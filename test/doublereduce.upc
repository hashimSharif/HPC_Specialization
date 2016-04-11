/* Reduce double precision vectors in UPC.
   THREADS should be a power of two 
   Parry Husbands*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <upc_strict.h>
#include <assert.h>

/* #include <upc_relaxed.h> */

typedef shared [] double * sdblptr;
typedef shared [] int * sintptr;

sdblptr reduce_incoming;
volatile double *reduce_incoming_local;
shared sdblptr reduce_incoming_directory[THREADS];
sdblptr *reduce_incoming_directory_cached;
sintptr reduce_incoming_flags;
volatile int *reduce_incoming_flags_local;
shared sintptr reduce_incoming_flags_directory[THREADS];
sintptr *reduce_incoming_flags_directory_cached;

#define REDUCE_EMPTY 0
#define REDUCE_FILLED 1

void initdoublereduce()
{
  int i;
  reduce_incoming = (sdblptr) upc_alloc(THREADS*sizeof(double));
  reduce_incoming_local = (double *) reduce_incoming;
  reduce_incoming_directory[MYTHREAD] = reduce_incoming;

  reduce_incoming_flags = (sintptr) upc_alloc(THREADS*sizeof(int));
  reduce_incoming_flags_local = (int *) reduce_incoming_flags;
  reduce_incoming_flags_directory[MYTHREAD] = reduce_incoming_flags;

  for(i=0;i < THREADS;i++) {
    reduce_incoming_flags[i] = REDUCE_EMPTY;
  }
  upc_barrier;
  reduce_incoming_directory_cached = (sdblptr *) calloc(THREADS,sizeof(sdblptr));
  reduce_incoming_flags_directory_cached = (sintptr *) calloc(THREADS,sizeof(sintptr));
  for(i=0;i < THREADS;i++) {
    reduce_incoming_directory_cached[i]=reduce_incoming_directory[i];
    reduce_incoming_flags_directory_cached[i]=reduce_incoming_flags_directory[i];
  }
}

double doublereduce(double *vec,int lenvec)
{
  double mycontribution = 0;
  double result;
  int myid = MYTHREAD;
  int level = 0;
  /* 2^level or (exp 2 level)*/
  int exp2level = 1;
  int i, oddneighbour, evenneighbour;
  /* Do local sum */
  for(i=0;i < lenvec;i++) {
    mycontribution+=vec[i];
  }
  /* Go up the tree */
  while(1) {
    if(myid % 2 == 1) {
      /* Send to my even neighbour */
      int target = MYTHREAD-exp2level;
      /* Do the send */
      {
#pragma upc strict
	/* I want the order preserved. Don't want the flag to
	   overtake the data*/

	/* But this should be nonblocking. Progress should be nade,
	   but you don't have to wait for completion */
        reduce_incoming_directory_cached[target][MYTHREAD]=mycontribution;
        reduce_incoming_flags_directory_cached[target][MYTHREAD]=MYTHREAD+1;
      }
      /* Go to distribution phase */
      break;
    } else {
     /* Wait for data from my odd neighbour */
     /* After a while you run out of people to talk to */
     int oddneighbour = MYTHREAD + exp2level;
     if(oddneighbour >= THREADS) {
       /* Whoops.  Went too far. Undo and go to distribute phase */
       myid*=2;exp2level/=2;
       break;
     }
     /* Wait for data from my odd neighbour */
     while(reduce_incoming_flags_local[oddneighbour] == REDUCE_EMPTY) {
       upc_fence;
     }
     /* Make sure the right proc did the write */
     assert(reduce_incoming_flags_local[oddneighbour] == oddneighbour+1);
     /* Add to what I've been collecting */
     mycontribution += reduce_incoming_local[oddneighbour];
      /* Reset for next time */
     reduce_incoming_flags_local[oddneighbour]=REDUCE_EMPTY;
    }
    exp2level*=2;
    myid/=2;
  }

  result = mycontribution;
  /* Go down the tree, reversing the process */
  do {
    if((myid % 2) == 0) {
      /* Send to neighbour */
      int oddneighbour = MYTHREAD+exp2level;
      {
#pragma upc strict
	reduce_incoming_directory_cached[oddneighbour][MYTHREAD]=result;
	reduce_incoming_flags_directory_cached[oddneighbour][MYTHREAD]=MYTHREAD+1;
      }
    } else {
      /* Wait for something from my even neighbour.  
	 Note that this is the same neighbour you sent your contribution to */
      int evenneighbour = MYTHREAD-exp2level;
      while(reduce_incoming_flags_local[evenneighbour] == REDUCE_EMPTY) {
        upc_fence;
      }
      assert(reduce_incoming_flags_local[evenneighbour] == evenneighbour+1);
      result = reduce_incoming_local[evenneighbour];
      /* Reset for next broadcast */
      reduce_incoming_flags_local[evenneighbour]=REDUCE_EMPTY;
    }
    /* exp2level gives how many processes to jump over. It also tells
       you how many sends you need to make */
    myid*=2;
    exp2level/=2;
  } while (exp2level > 0);
  printf("MYTHREAD=%4d result=%10.3f\n", MYTHREAD,result);
  return(result);
}

#define SIZEPERPROC 100
#define ROUNDS 1
shared [SIZEPERPROC] double input[SIZEPERPROC*THREADS];
int main()
{

  sleep(40);
  int i;
  double answer;
  int passed = 1;
  printf("Starting..\n"); 
  answer = SIZEPERPROC*THREADS*(SIZEPERPROC*THREADS-1)/2;
  if(MYTHREAD == 0) {
    int numth = THREADS;
    printf("Expected answer = %10.3f\n",answer);
    /* check that number of threads is a power of 2 */
    while (numth % 2 == 0) {
	numth /= 2;
    }
    if (numth != 1) {
	printf("Failed: number of threads [%d] MUST be a power of 2\n",THREADS);
	upc_global_exit(1);
    }
  }
  if(MYTHREAD == 0) {
    for(i=0;i < SIZEPERPROC*THREADS;i++) {
      input[i]=i;
    }
  }
  upc_barrier;
  initdoublereduce();
  for(i=0;i < ROUNDS;i++) {
    double result = doublereduce((double *) &input[MYTHREAD*SIZEPERPROC],
				 SIZEPERPROC);
    if(result != answer) {
      passed = 0;
    } 
  }
  if(passed) {
    printf("Passed\n");
  } else {
    printf("Failed\n");
  }
  return(0);
}
