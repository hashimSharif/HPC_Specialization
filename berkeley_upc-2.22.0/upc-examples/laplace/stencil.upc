/* stencil.upc
   Perform a simple 1-d stencil computation in UPC.
   Shows forall overheads, and local accesses to shared arrays 
   Parry Husbands */

#include <upc_relaxed.h>
#include <stdio.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <sys/time.h>

/* Number of iterations of timing loop */
#define TIMES 10

/* How many elements are local to each thread */
#define LOCALSIZE 500

/* Timing routines */

#define OVERHEAD_ITERATIONS 1000
struct timeval tp_1st, tp_2nd;
unsigned int overhead, measured;

void init_timer()
{
  int i;
  overhead = 0;
  /* Measure overhead */
  for(i=0;i < OVERHEAD_ITERATIONS;i++) {
    gettimeofday(&tp_1st, NULL);
    gettimeofday(&tp_2nd, NULL);
    overhead += (tp_2nd.tv_sec-tp_1st.tv_sec) * 1000000.0
      + (tp_2nd.tv_usec-tp_1st.tv_usec);
  }
  overhead/=OVERHEAD_ITERATIONS;
  
}

void start_timer()
{
    gettimeofday(&tp_1st, NULL);
}

float report_time(const char *message)
{
    gettimeofday(&tp_2nd, NULL);
    measured = (tp_2nd.tv_sec-tp_1st.tv_sec) * 1000000.0 + 
      (tp_2nd.tv_usec-tp_1st.tv_usec) - overhead;
    /* Print time in milliseconds. */
    if(MYTHREAD == 0) {
      printf("%s %f (sec)\n", message,measured/1000000.0);
    }
    return(measured/1000000.0);
}

/* Input and output arrays */
shared [LOCALSIZE] double input[LOCALSIZE*THREADS];
shared [LOCALSIZE] double output[LOCALSIZE*THREADS];

int main()
{
  int i,j;
  double *inputlocal=(double *) &input[LOCALSIZE*MYTHREAD];
  double *outputlocal = (double *) &output[LOCALSIZE*MYTHREAD];

  /* Perform a simple 1-d stencil using various UPC language
     features */
  upc_barrier;
  start_timer();
  for(i=0;i < TIMES;i++) {
    /* Use upc_forall.  Implementations will eventually try
       to optimize this */
    upc_forall(j=1;j < LOCALSIZE*THREADS-1;j++; &(input[j])) {
      output[j]=0.25*(2*input[j]+input[j-1]+input[j+1]);
    }
  }
  upc_barrier;
  report_time("upc_forall shared");

  upc_barrier;
  start_timer();
  for(i=0;i < TIMES;i++) {
    /* Use a for loop, but still go through the shared arrays */
    if(MYTHREAD > 0) {
      j=MYTHREAD*LOCALSIZE;
      output[j]=0.25*(2*input[j]+input[j-1]+input[j+1]);
    }
    for(j=MYTHREAD*LOCALSIZE+1;j < (MYTHREAD+1)*LOCALSIZE-1;j++) {
      output[j]=0.25*(2*input[j]+input[j-1]+input[j+1]);
    }
    if(MYTHREAD < THREADS-1) {
      j=(MYTHREAD+1)*LOCALSIZE-1;
      output[j]=0.25*(2*input[j]+input[j-1]+input[j+1]);
    }
  }
  upc_barrier;
  report_time("for shared");
  upc_barrier;
  start_timer();
  for(i=0;i < TIMES;i++) {
    /* Use a for loop, and use local pointers to the shared arrays
       whenever possible */
    if(MYTHREAD > 0) {
      j=MYTHREAD*LOCALSIZE;
      outputlocal[0]=0.25*(2*inputlocal[0]+input[j-1]+inputlocal[1]);
    }
    for(j=1;j < LOCALSIZE-1;j++) {
      outputlocal[j]=0.25*(2*inputlocal[j]+inputlocal[j-1]+inputlocal[j+1]);
    }
    if(MYTHREAD < THREADS-1) {
      j=(MYTHREAD+1)*LOCALSIZE-1;
      outputlocal[LOCALSIZE-1]=0.25*(2*inputlocal[LOCALSIZE-1]+
				     inputlocal[LOCALSIZE-2]+
				     input[j+1]);
    }
  }
  upc_barrier;
  report_time("for local");
  return(0); 
}
