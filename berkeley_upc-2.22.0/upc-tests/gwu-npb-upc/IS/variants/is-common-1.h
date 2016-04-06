#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <upc.h>
#include <upc_relaxed.h>

#include "npb-C.h"
#include "npbparams.h"
#define MAX_TIMERS         5
#include "upc_timers.h"

#define TIMER_TOTALTIME    0
#define TIMER_COMPTIME     1
#define TIMER_COMMTIME     2
#define TIMER_ALLREDUCE    3
#define TIMER_ALLTOALL     4

/* default values */
#ifndef CLASS
#define CLASS 'S'
#endif

/*  CLASS S  */
#if CLASS == 'S'
#define  TOTAL_KEYS_LOG_2    16
#define  MAX_KEY_LOG_2       11
#define  NUM_BUCKETS_LOG_2   9
#endif

/*  CLASS W  */
#if CLASS == 'W'
#define  TOTAL_KEYS_LOG_2    20
#define  MAX_KEY_LOG_2       16
#define  NUM_BUCKETS_LOG_2   10
#endif

/*  CLASS A  */
#if CLASS == 'A'
#define  TOTAL_KEYS_LOG_2    23
#define  MAX_KEY_LOG_2       19
#define  NUM_BUCKETS_LOG_2   10
#endif

/*  CLASS B  */
#if CLASS == 'B'
#define  TOTAL_KEYS_LOG_2    25
#define  MAX_KEY_LOG_2       21
#define  NUM_BUCKETS_LOG_2   10
#endif

/*  CLASS C  */
#if CLASS == 'C'
#define  TOTAL_KEYS_LOG_2    27
#define  MAX_KEY_LOG_2       23
#define  NUM_BUCKETS_LOG_2   10
#endif

#define  TOTAL_KEYS          (1 << TOTAL_KEYS_LOG_2)
#define  MAX_KEY             (1 << MAX_KEY_LOG_2)
#define  NUM_BUCKETS         (1 << NUM_BUCKETS_LOG_2)
#define  NUM_KEYS            (TOTAL_KEYS/THREADS)

/* On larger number of processors, since the keys are (roughly)  */
/* gaussian distributed, the first and last processor sort keys  */
/* in a large interval, requiring array sizes to be larger. Note */
/* that for large THREADS, NUM_KEYS is, however, a small number*/
#if THREADS < 256
#define  SIZE_OF_BUFFERS     3*NUM_KEYS/2
#else
#define  SIZE_OF_BUFFERS     3*NUM_KEYS
#endif

#define  MAX_PROCS           256
#define  MAX_ITERATIONS      10
#define  TEST_ARRAY_SIZE     5

/* Typedef: if necessary, change the */
/* size of int here by changing the  */
/* int type to, say, long            */
typedef int INT_TYPE;

typedef struct{
    int count;
    int displ;
} send_info;

shared INT_TYPE lastkeys[THREADS];
shared int passed_verification_shd[THREADS];

/* These are the three main arrays. */
/* See SIZE_OF_BUFFERS def above    */
INT_TYPE key_array[SIZE_OF_BUFFERS],
         key_buff2[SIZE_OF_BUFFERS],
         bucket_ptrs[NUM_BUCKETS],
         process_bucket_distrib_ptr1[NUM_BUCKETS+TEST_ARRAY_SIZE],
         process_bucket_distrib_ptr2[NUM_BUCKETS+TEST_ARRAY_SIZE],
         send_displ[THREADS], send_count[THREADS] ;

INT_TYPE total_local_keys;
INT_TYPE total_lesser_keys;
