#define USING_CRAY 0
#include <stdio.h>
#include <stdlib.h>

#if USING_CRAY
#include <upc_relaxed.h>
#else
#include <upc_strict.h>
#endif

#include <time.h>
#include <sys/times.h>
#include <sys/time.h>
#define	MaxN 5000
#define LOOPS 1000
#define OVERHEAD_ITERATIONS 1000  /* number of iterations in overhead timing */
#define NumofHashValues 13
int hashsize[NumofHashValues];
#define MaxHashValue 128
shared int array[MaxN];
#if USING_CRAY
upc_lock_t arrayflag[MaxN];
#else
upc_lock_t *arrayflag[MaxN];
#endif
#if USING_CRAY
upc_lock_t threadflag[THREADS];
#else
upc_lock_t *threadflag[THREADS];
#endif
#if USING_CRAY
upc_lock_t hashflag[MaxHashValue];
#else
upc_lock_t *hashflag[MaxHashValue];
#endif
int main ()
{
  
struct timeval tpstart, tpstop;
unsigned int overhead, measured;

  
  hashsize[0]  = 1;
  hashsize[1]  = 3;
  hashsize[2]  = 4;
  hashsize[3]  = 7;
  hashsize[4]  = 8;
  hashsize[5]  = 16;
  hashsize[6]  = 17;
  hashsize[7]  = 31;
  hashsize[8]  = 32;
  hashsize[9] = 61;
  hashsize[10] = 64;
  hashsize[11] = 127;
  hashsize[12] = 128;
  
{ int i;
 overhead = 0;
 for(i=0; i < OVERHEAD_ITERATIONS; i++) {
    gettimeofday(&tpstart, NULL);
    gettimeofday(&tpstop, NULL);
    overhead += (tpstop.tv_sec-tpstart.tv_sec) * 1000000.0
      + (tpstop.tv_usec-tpstart.tv_usec);
 }
 overhead/=OVERHEAD_ITERATIONS;
}
  
  srand48((long) MYTHREAD);  // Initialize Random Number Generator

#define WHICHCASE 15
#if( WHICHCASE & 8 )
  
{ int N, l, i;
  for(N=250; N<=MaxN; N+=250){
    
{int i;
  upc_forall(i=0; i<N;	i++; &array[i])
      array[i] = 0;
}

    
  upc_barrier;
  gettimeofday(&tpstart,NULL); 

    for(l=0; l<LOOPS; l++){
      i =(int)( N * drand48() );
      array[i]+= 1;
    }

    
  gettimeofday(&tpstop, NULL);  
  /* Elapased time in microseconds = 1E+06 seconds. */
  measured = (tpstop.tv_sec-tpstart.tv_sec) * 1000000.0 +
               (tpstop.tv_usec-tpstart.tv_usec) - overhead;
  upc_barrier;

    
if(MYTHREAD==0) {
 int i, sum;
 sum = 0;
 for(i=0;i<N;i++)
    sum += array[i];
 if( sum != (THREADS * LOOPS) )
   printf("Update Ratio: THREADS=%2d, N = %4d   %d/%d =  %f\n", 
            THREADS, N,  sum, (THREADS * LOOPS), 
            (double)sum/(double)(THREADS*LOOPS));
}
    printf("Nolocks: N = %4d %2d.%2d  in %d(usec)\n", 
                   N, THREADS, MYTHREAD, measured );
    upc_barrier;
  } 
}
  upc_barrier;
#endif
#if( WHICHCASE & 4 )
  
// Lock each array entry
#if USING_CRAY
// don't need to initialize locks
#else
{int l;
  for(l=0; l<MaxN; l++){
   arrayflag[l] = upc_all_lock_alloc();
   //upc_lock_init(arrayflag[l]);
  }
}
#endif
{ int N, l, i;
  for(N=500; N<=MaxN; N+=1500){
    
{int i;
  upc_forall(i=0; i<N;	i++; &array[i])
      array[i] = 0;
}

    
  upc_barrier;
  gettimeofday(&tpstart,NULL); 

    for(l=0; l<LOOPS; l++){
       i = (int) (N * drand48());
#if USING_CRAY
       upc_lock( &arrayflag[i] );
       array[i]+= 1;
       upc_unlock( &arrayflag[i] );
#else
       upc_lock( arrayflag[i] );
       array[i]+= 1;
       upc_unlock( arrayflag[i] );
#endif
    }

    
  gettimeofday(&tpstop, NULL);  
  /* Elapased time in microseconds = 1E+06 seconds. */
  measured = (tpstop.tv_sec-tpstart.tv_sec) * 1000000.0 +
               (tpstop.tv_usec-tpstart.tv_usec) - overhead;
  upc_barrier;

    
if(MYTHREAD==0) {
 int i, sum;
 sum = 0;
 for(i=0;i<N;i++)
    sum += array[i];
 if( sum != (THREADS * LOOPS) )
   printf("Update Ratio: THREADS=%2d, N = %4d   %d/%d =  %f\n", 
            THREADS, N,  sum, (THREADS * LOOPS), 
            (double)sum/(double)(THREADS*LOOPS));
}
    printf("ArrayLock: N = %4d %2d.%2d  in %d(usec)\n", 
                   N, THREADS, MYTHREAD, measured );
    upc_barrier;
  } 
}
  upc_barrier;
#endif
#if( WHICHCASE & 2 )
  
// One lock per thread
#if USING_CRAY
// don't need to initialize locks
#else
{ int l;
 for(l=0; l<THREADS; l++){
   threadflag[l] = upc_all_lock_alloc();
   //upc_lock_init(threadflag[l]);
 }
}
#endif

{ int N, l, i;
  for(N=500; N<=MaxN; N+=1500){
    
{int i;
  upc_forall(i=0; i<N;	i++; &array[i])
      array[i] = 0;
}

    
  upc_barrier;
  gettimeofday(&tpstart,NULL); 

    for(l=0; l<LOOPS; l++){
      i = (int) (N * drand48());
#if USING_CRAY
      upc_lock( &threadflag[upc_threadof(&array[i])] );
      array[i]+= 1;
      upc_unlock( &threadflag[upc_threadof(&array[i])] );
#else
      upc_lock( threadflag[upc_threadof(&array[i])] );
      array[i]+= 1;
      upc_unlock( threadflag[upc_threadof(&array[i])] );
#endif
    }

    
  gettimeofday(&tpstop, NULL);  
  /* Elapased time in microseconds = 1E+06 seconds. */
  measured = (tpstop.tv_sec-tpstart.tv_sec) * 1000000.0 +
               (tpstop.tv_usec-tpstart.tv_usec) - overhead;
  upc_barrier;

    
if(MYTHREAD==0) {
 int i, sum;
 sum = 0;
 for(i=0;i<N;i++)
    sum += array[i];
 if( sum != (THREADS * LOOPS) )
   printf("Update Ratio: THREADS=%2d, N = %4d   %d/%d =  %f\n", 
            THREADS, N,  sum, (THREADS * LOOPS), 
            (double)sum/(double)(THREADS*LOOPS));
}
    printf("ThreadLock: N = %4d %2d.%2d  in %d(usec)\n", 
                   N, THREADS, MYTHREAD, measured );
    upc_barrier;
  } 
}
  upc_barrier;
#endif
#if( WHICHCASE & 1 )
  
#if USING_CRAY
// don't need to initialize locks
#else
{int l;
 for(l=0; l<MaxHashValue; l++){
  hashflag[l] = upc_all_lock_alloc();
  //upc_lock_init(hashflag[l]);
 }
}
#endif

{ int i, l, N, h;
  for(N=500; N<=MaxN; N+=1500){
   for(h=0; h < NumofHashValues; h++){
     
{int i;
  upc_forall(i=0; i<N;	i++; &array[i])
      array[i] = 0;
}

     
  upc_barrier;
  gettimeofday(&tpstart,NULL); 

     for(l=0; l<LOOPS; l++){
       i = (int) (N * drand48());
#if USING_CRAY
       upc_lock( &hashflag[i%hashsize[h]] );
       array[i]+= 1;
       upc_unlock( &hashflag[i%hashsize[h]] );
#else
       upc_lock( hashflag[i%hashsize[h]] );
       array[i]+= 1;
       upc_unlock( hashflag[i%hashsize[h]] );
#endif
     }

     
  gettimeofday(&tpstop, NULL);  
  /* Elapased time in microseconds = 1E+06 seconds. */
  measured = (tpstop.tv_sec-tpstart.tv_sec) * 1000000.0 +
               (tpstop.tv_usec-tpstart.tv_usec) - overhead;
  upc_barrier;

     
if(MYTHREAD==0) {
 int i, sum;
 sum = 0;
 for(i=0;i<N;i++)
    sum += array[i];
 if( sum != (THREADS * LOOPS) )
   printf("Update Ratio: THREADS=%2d, N = %4d   %d/%d =  %f\n", 
            THREADS, N,  sum, (THREADS * LOOPS), 
            (double)sum/(double)(THREADS*LOOPS));
}
     printf("HashLock: N = %4d %2d.%2d with %3d in %d(usec)\n", 
                   N, THREADS, MYTHREAD, hashsize[h],  measured );
     upc_barrier;
   }
  } 
}
  upc_barrier;
#endif
printf("done.\n");
return 0;
}
