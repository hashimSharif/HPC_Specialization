#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <upc.h>

#define MAX_THREADS 100

typedef struct ufoo { 
  int a[MAX_THREADS]; 
  float b[MAX_THREADS];
  shared int *spint;
} UFOO;

shared UFOO udata, adata[2*THREADS];
UFOO lfoo, alfoo;


shared int global;

int main()
{
    int i;
    int errflag=0;

    if (THREADS>MAX_THREADS) {
	printf("Too many threads.\n");
	exit(1);
    }
    
    //
    // thread 0 set the union field some predefined value
    //
    if (MYTHREAD==0) {
      for(i=0; i<THREADS; i++) {
	    udata.a[i]=i;
	    adata[1].a[i] = i;
      }
      udata.spint = &global;
      adata[1].spint = &global;
	global = 123456;
    }
    upc_barrier 1;
    //
    // to check the variable can be accessed by all threads
    //
    for (i=0; i<THREADS; i++) {
	if (udata.a[i]!=i){
	    errflag=1;
	    printf("test_struct - udata : Error in thread %d with the union element %d\n",MYTHREAD,i);

	}
	if (adata[1].a[i]!=i){
	  errflag |= 2;
	  printf("test_struct - adata : Error in thread %d with the union element %d\n",MYTHREAD,i);
	}
    }

    if(*udata.spint != 123456)
      printf("test_struct  : udata.spint: Error in %d\n", MYTHREAD);
/*      if(*adata[1].spint != 123456)  */
/*       Printf("test_struct  : adata.spint: Error in %d\n", MYTHREAD); */
    
    
    
    //
    // check union variable's affinity
    //
    if (upc_threadof(&udata)!=0){
	errflag |= 4;
#ifdef VERBOSE0
	printf("Error: The union variable udata is not in thread 0\n");
#endif
    }

    if (errflag) {
	printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
    } else if (MYTHREAD == 0) {
	printf("Success: on Thread %d \n",MYTHREAD);
    }

    return(errflag);
 
} 
