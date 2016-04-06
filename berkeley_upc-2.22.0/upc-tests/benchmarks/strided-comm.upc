#ifndef BUPC_USE_UPC_NAMESPACE
#define BUPC_USE_UPC_NAMESPACE 1
#endif


#include <upc.h>
#include <stdio.h>
#include <inttypes.h>
#include <upc_relaxed.h>
#include <upc_nb.h>

#include "bupc_timers.h"

#define ONE_DIMENSION       1
#define TWO_DIMENSIONS      2
#define THREE_DIMENSIONS    3
#define ONE_DIMENSION_BLOCKING 4
#define ONE_DIMENSION_SLOW  5

#define ARRAY_SIZE  1024*1024 

double shared dataArray[4*ARRAY_SIZE][THREADS];

int main(int argc, char *argv[]) {
  
  double tStart, tStop, totalTime;

  int i, j;
  upc_barrier;
  int communicationMode;
  int numberOfIterations;
  long chunkSize, memoryStride, chunkCount;
  long transferRange; 
  int left, right;
  upc_handle_t leftHandle, rightHandle;
  double *leftShadowRegion, *rightShadowRegion;
  long currentLocation;

  printf("argc=%d \n argv: ", argc);
  
  if (argc != 6) {
    printf("upc-sc <communication mode> <number of iterations> <chunk size> <memory stride> <count> \n");
    exit(0);
  }

  for (i=0; i<argc; i++) {
    printf("%s ", argv[i]);
  }
  printf("\n");

  upc_barrier;
 
 
  sscanf(argv[1], "%d", & communicationMode); 
  sscanf(argv[2], "%d", & numberOfIterations); 
  sscanf(argv[3], "%ld", & chunkSize); 
  sscanf(argv[4], "%ld", & memoryStride); 
  sscanf(argv[5], "%ld", & chunkCount); 
  printf("performing %d iterations with communication mode %d;"
	 " exchanging %ld chunks of size %ld, memory stride %ld\n",
	 numberOfIterations, communicationMode,
	 chunkCount, chunkSize, memoryStride);
  if (MYTHREAD == 0) {
    transferRange = (chunkCount-1)*memoryStride+chunkSize;
    if (transferRange > ARRAY_SIZE) {
      printf("Transfer range %ld exceeds array size %ld\n", 
	     transferRange, (long) ARRAY_SIZE);
      upc_global_exit(-1);
    }
    if (chunkSize == 0 || chunkCount == 0 || chunkSize > memoryStride) {
      printf("Incorrect parameters\n");
      upc_global_exit(-1);
    }

  }
  
  if (MYTHREAD == 0) {
    timer_clear(1);
    timer_start(1);
    tStart = timer_read(1);
  }

  upc_memset( & dataArray[0][MYTHREAD], 0, 4*ARRAY_SIZE*sizeof(double));

  switch (communicationMode) {
  case ONE_DIMENSION:
    left  = (MYTHREAD+THREADS-1)%THREADS;
    right = (MYTHREAD+1)%THREADS;
    leftShadowRegion = (double*) &dataArray[0*ARRAY_SIZE][MYTHREAD];
    rightShadowRegion = (double *)& dataArray[3*ARRAY_SIZE][MYTHREAD];

    for (i=0; i<numberOfIterations; i++) {
      upc_barrier;
      rightHandle = upc_memget_fstrided_async( rightShadowRegion,
					       chunkSize*sizeof(double),
					       memoryStride*sizeof(double),
					       chunkCount,
					       & dataArray[1*ARRAY_SIZE][right],
					       chunkSize*sizeof(double),
					       memoryStride*sizeof(double),
					       chunkCount);

      leftHandle = upc_memget_fstrided_async( leftShadowRegion,
					      chunkSize*sizeof(double),
					      memoryStride*sizeof(double),
					      chunkCount,
					      & dataArray[2*ARRAY_SIZE][left],
					      chunkSize*sizeof(double),
					      memoryStride*sizeof(double), 
					      chunkCount);
      upc_sync(leftHandle);
      upc_sync(rightHandle);
      upc_barrier;
    }

    break;
  case TWO_DIMENSIONS:
    break;
  case THREE_DIMENSIONS:
    break;

  case ONE_DIMENSION_BLOCKING:
    left  = (MYTHREAD+THREADS-1)%THREADS;
    right = (MYTHREAD+1)%THREADS;
    leftShadowRegion = (double*) &dataArray[0*ARRAY_SIZE][MYTHREAD];
    rightShadowRegion = (double *)& dataArray[3*ARRAY_SIZE][MYTHREAD];

    for (i=0; i<numberOfIterations; i++) {
      upc_barrier;

    rightHandle = upc_memget_fstrided_async( rightShadowRegion,
					     chunkSize*sizeof(double),
					     memoryStride*sizeof(double),
					     chunkCount,
					     & dataArray[1*ARRAY_SIZE][right],
					     chunkSize*sizeof(double),
					     memoryStride*sizeof(double),
					     chunkCount);
    
    upc_sync(rightHandle);
    leftHandle = upc_memget_fstrided_async( leftShadowRegion,
					    chunkSize*sizeof(double),
					    memoryStride*sizeof(double),
					    chunkCount,
					    & dataArray[2*ARRAY_SIZE][left],
					    chunkSize*sizeof(double),
					    memoryStride*sizeof(double), 
					    chunkCount);
    upc_sync(leftHandle);

      upc_barrier;
    }

    break;

  case ONE_DIMENSION_SLOW:
    left  = (MYTHREAD+THREADS-1)%THREADS;
    right = (MYTHREAD+1)%THREADS;
    leftShadowRegion = (double*) &dataArray[0*ARRAY_SIZE][MYTHREAD];
    rightShadowRegion = (double *)& dataArray[3*ARRAY_SIZE][MYTHREAD];

    for (i=0; i<numberOfIterations; i++ ) {
      upc_barrier;
      for (j=0, currentLocation = 0; 
	   j<chunkCount; 
	   j++,currentLocation += memoryStride) {  
	upc_memget(leftShadowRegion + currentLocation*sizeof(double),
		   & dataArray[2*ARRAY_SIZE+currentLocation][left],
		   chunkSize*sizeof(double));
	upc_memget(rightShadowRegion + currentLocation*sizeof(double),
		   & dataArray[1*ARRAY_SIZE+currentLocation][right],
		   chunkSize*sizeof(double));
      }
      upc_barrier;
    }

    break;
  default:
    printf("incorrect communication mode\n");
    exit(-1);
  }

 
  upc_barrier; 
  if (MYTHREAD == 0) {
    timer_stop(1);
    tStop = timer_read(1);
    printf("performed %d iterations with comm mode %d;"
	   " %ld chunks of size %ld, memory stride %ld in %g seconds\n",
	   numberOfIterations, communicationMode,
	   chunkCount, chunkSize, memoryStride, tStop -tStart);
    printf("done.\n");
  }
}
