/*   $Source: bitbucket.org:berkeleylab/upc-runtime.git/upc-examples/upc_collectivev/bupc_collectivev_test.upc $ */
/*  Description: UPC collectives value interface tester */
/*  Copyright 2005, Dan Bonachea <bonachea@cs.berkeley.edu> */

#include <upc.h>
#include <bupc_collectivev.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define BARRIER() do { fflush(NULL); sleep(1); upc_barrier; fflush(NULL); } while (0)
#define PRINT_LINE()  do { upc_barrier; if (verbose && MYTHREAD == 0) printf("-\n"); BARRIER(); } while (0)

#define FOO_VAL(thread) (((thread)+1)*1001)
#define BAR_VAL(thread) (((thread)+1)*1001.001)

#define VERIFY_FOO_VAL(thread, result) do {                          \
  if ((result) != FOO_VAL(thread)) {                                 \
    fprintf(stderr,"ERROR: thread %i got foo(%i)=%i, expected=%i\n", \
            MYTHREAD, (thread), (result), FOO_VAL(thread));          \
    fflush(NULL);                                                    \
  }                                                                  \
} while(0)

#define VERIFY_FOO_SUM(thread, result) do {                              \
  int expected = 0;                                                      \
  for (int i=0; i<thread; i++) expected += FOO_VAL(i);                   \
  if ((result) != expected) {                                            \
    fprintf(stderr,"ERROR: thread %i got foo_sum(%i)=%i, expected=%i\n", \
            MYTHREAD, (thread), (result), expected);                     \
    fflush(NULL);                                                        \
  }                                                                      \
} while(0)

#define VERIFY_BAR_SUM(thread, result) do {                              \
  double expected = 0;                                                   \
  for (int i=0; i<thread; i++) expected += BAR_VAL(i);                   \
  if (fabs((result) - expected) > 0.1) {                                 \
    fprintf(stderr,"ERROR: thread %i got bar_sum(%i)=%f, expected=%f\n", \
            MYTHREAD, (thread), (result), expected);                     \
    fflush(NULL);                                                        \
  }                                                                      \
} while(0)

#if BUPC_COLLECTIVEV_VERSION_MAJOR < 1
#error bad BUPC_COLLECTIVEV_VERSION_MAJOR definition
#endif

#if !defined(BUPC_COLLECTIVEV_VERSION_MINOR)
#error bad BUPC_COLLECTIVEV_VERSION_MINOR definition
#endif

static void *my_malloc(size_t size) {
  void *ptr = malloc(size);
  if (!ptr) {
    fprintf(stderr, "Out of memory allocating %lu bytes.\n",
                    (unsigned long)size);
    upc_global_exit(41);
  }
  return ptr;
}

static void *my_calloc(size_t nmemb, size_t size) {
  void *ptr = calloc(nmemb, size);
  if (!ptr) {
    fprintf(stderr, "Out of memory allocating %lu elements of size %lu bytes.\n",
                    (unsigned long)nmemb, (unsigned long)size);
    upc_global_exit(42);
  }
  return ptr;
}

int verbose = 0;

int main(int argc, char **argv) {
   int foo = FOO_VAL(MYTHREAD);
   double bar = BAR_VAL(MYTHREAD);

   /* Pass -v to see O(THREADS^2) output of results */
   if ((argc > 1) && (0 == strcmp(argv[1], "-v"))) {
     verbose = 1;
     --argc;
     ++argv;
   }

   if (argc > 1) { /* test error cases */
     switch (atoi(argv[1])) {
       case 1: bupc_allv_broadcast(int, foo, MYTHREAD); break;
       case 2: bupc_allv_gather(int, foo, MYTHREAD, NULL); break;
       case 3: bupc_allv_gather(int, foo, 0, NULL); break;
       case 4: bupc_allv_scatter(int, -1, NULL); break;
       case 5: bupc_allv_scatter(int, MYTHREAD, NULL); break;
       case 6: bupc_allv_scatter(int, 0, NULL); break;
       case 7: bupc_allv_reduce(int, foo, MYTHREAD, UPC_ADD); break;
       case 8: bupc_allv_reduce(int, foo, 0, 666); break;
       case 9: bupc_allv_reduce_all(int, foo, 666); break;
       case 10: bupc_allv_prefix_reduce(int, foo, 666); break;
       case 11: if (MYTHREAD%2 == 0) bupc_allv_broadcast(int, foo, 0); 
                else                 bupc_allv_broadcast(float, foo, 0); 
                break;
       case 12: if (MYTHREAD%2 == 0) bupc_allv_reduce_all(int, foo, UPC_ADD); 
                else                 bupc_allv_reduce_all(float, foo, UPC_ADD); 
                break;
       case 13: if (MYTHREAD%2 == 0) bupc_allv_reduce_all(int, foo, UPC_ADD); 
                else                 bupc_allv_reduce_all(size_t, foo, UPC_ADD); 
                break;
       default: printf("There are 13 error tests.\n"); 
     }
     exit(-1);
   }

   if (MYTHREAD == 0) printf("bupc_allv_broadcast\n");
   BARRIER();
   for (int i=0; i < THREADS; i++) {
               // bupc_allv_broadcast(TYPE, value, rootthread)
     int result = bupc_allv_broadcast(int, foo, i);
     if (verbose) printf("%i: sender=%i result=%i\n", MYTHREAD, i, result);
     VERIFY_FOO_VAL(i, result);
     if (i != THREADS-1) PRINT_LINE();
   }
   BARRIER();
   if (MYTHREAD == 0) printf("misc matching tests\n");
   BARRIER();
   { int zero = 0;
     unsigned int ui = 0; 
     char **cpp;
     shared char **scpp;
     shared char * shared const *scscp;
     if (MYTHREAD%2==0) bupc_allv_broadcast(unsigned int, ui, 0);
     else               bupc_allv_broadcast(   unsigned    int, ui, 0);
     if (MYTHREAD%2==0) bupc_allv_broadcast(unsigned int, ui, zero);
     else               bupc_allv_broadcast(   unsigned    int, ui, 0);
     if (MYTHREAD%2==0) bupc_allv_broadcast(char**, cpp, 0);
     else               bupc_allv_broadcast( char * * , cpp, 0);
     if (MYTHREAD%2==0) bupc_allv_broadcast(shared char**, scpp, 0);
     else               bupc_allv_broadcast( shared char * * , scpp, 0);
     if (MYTHREAD%2==0) bupc_allv_broadcast( shared   char * shared  const * , scscp, 0);
     else               bupc_allv_broadcast(shared char*shared const*, scscp, 0);
     BARRIER();
     if (MYTHREAD==0) printf("test complete.\n");
   }
   BARRIER();
   if (MYTHREAD == 0) printf("bupc_allv_permute\n");
   BARRIER();
   for (int i=0; i < THREADS; i++) {
               // bupc_allv_permute(TYPE, value, tothreadid)
     int result = bupc_allv_permute(int, foo, (MYTHREAD+i)%THREADS);
     if (verbose) printf("%i: result=%i\n", MYTHREAD, result);
     VERIFY_FOO_VAL((MYTHREAD+THREADS-i)%THREADS, result);
     if (i != THREADS-1) PRINT_LINE();
   }
   BARRIER();
   if (MYTHREAD == 0) printf("bupc_allv_gather\n");
   BARRIER();
   for (int i=0; i < THREADS; i++) {
     if (MYTHREAD != i) {
       bupc_allv_gather(int, foo, i, NULL);
     } else { /* MYTHREAD == i */
       int *result = my_calloc(THREADS,sizeof(int));
       // bupc_allv_gather(TYPE, value, tothreadid, rootdestarray)
       bupc_allv_gather(int, foo, i, result);
       for (int j=0; j < THREADS; j++) {
         if (verbose) printf("%i: result[%i]=%i\n", MYTHREAD, j, result[j]);
         VERIFY_FOO_VAL(j, result[j]);
       }
       free(result);
     }
     if (i != THREADS-1) PRINT_LINE();
   }
   BARRIER();
   if (MYTHREAD == 0) printf("bupc_allv_gather_all\n");
   BARRIER();
   for (int i=0; i < THREADS; i++) {
     int *result = my_calloc(THREADS,sizeof(int));
     // bupc_allv_gather_all(TYPE, value, destarray)
     bupc_allv_gather_all(int, foo, result);
     for (int j=0; j < THREADS; j++) {
       if (verbose) printf("%i: result[%i]=%i\n", MYTHREAD, j, result[j]);
       VERIFY_FOO_VAL(j, result[j]);
     }
     PRINT_LINE();
     // ignore the result on even threads
     memset(result,0xFF,THREADS*sizeof(int));
     bupc_allv_gather_all(int, foo, (MYTHREAD%2?result:NULL));
     for (int j=0; j < THREADS; j++) {
       if (MYTHREAD%2) {
         if (verbose) printf("%i: result[%i]=%i\n", MYTHREAD, j, result[j]);
         VERIFY_FOO_VAL(j, result[j]);
       } else {
         if (verbose) printf("%i: result[%i]=%i (ignored)\n", MYTHREAD, j, result[j]);
         if (result[j] != -1) {                                            \
           fprintf(stderr,"ERROR: thread %i passed NULL dest array, but it was clobbered!", MYTHREAD);
           fflush(NULL); 
         }
       }
     }
     free(result);
     if (i != THREADS-1) PRINT_LINE();
   }
   BARRIER();
   if (MYTHREAD == 0) printf("bupc_allv_scatter\n");
   BARRIER();
   for (int i=0; i < THREADS; i++) {
     int result;
     if (MYTHREAD != i) {
       result = bupc_allv_scatter(int, i, NULL);
     } else { /* MYTHREAD == i */
       int *src = my_malloc(THREADS*sizeof(int));
       for (int j=0; j < THREADS; j++) {
         src[j] = FOO_VAL(j*10);
       }
             // bupc_allv_scatter(TYPE, fromthreadid, rootsrcarray)
       result = bupc_allv_scatter(int, i, src);
       free(src);
     }
     if (verbose) printf("%i: result=%i\n", MYTHREAD, result);
     VERIFY_FOO_VAL(MYTHREAD*10, result);
     if (i != THREADS-1) PRINT_LINE();
   }
   BARRIER();
   if (MYTHREAD == 0) printf("bupc_allv_reduce\n");
   BARRIER();
   for (int i=0; i < THREADS; i++) {
               // bupc_allv_reduce(TYPE, value, rootthread, reductionop)
     int result = bupc_allv_reduce(int, foo, i, UPC_ADD);
     double fresult = bupc_allv_reduce(double, bar, i, UPC_ADD);
     if (MYTHREAD == i) {
       if (verbose) printf("%i: result=%i\n", MYTHREAD, result);
       if (verbose) printf("%i: fresult=%f\n", MYTHREAD, fresult);
       VERIFY_FOO_SUM(THREADS, result);
       VERIFY_BAR_SUM(THREADS, fresult);
     }
   }
   BARRIER();
   if (MYTHREAD == 0) printf("bupc_allv_reduce_all\n");
   BARRIER();
   {
               // bupc_allv_reduce_all(TYPE, value, reductionop)
     int result = bupc_allv_reduce_all(int, foo, UPC_ADD);
     double fresult = bupc_allv_reduce_all(double, bar, UPC_ADD);
     if (verbose) printf("%i: result=%i\n", MYTHREAD, result);
     if (verbose) printf("%i: fresult=%f\n", MYTHREAD, fresult);
     VERIFY_FOO_SUM(THREADS, result);
     VERIFY_BAR_SUM(THREADS, fresult);
   }
   BARRIER();
   if (MYTHREAD == 0) printf("bupc_allv_prefix_reduce\n");
   BARRIER();
   {
               // bupc_allv_prefix_reduce(TYPE, value, reductionop)
     int result = bupc_allv_prefix_reduce(int, foo, UPC_ADD);
     double fresult = bupc_allv_prefix_reduce(double, bar, UPC_ADD);
     if (verbose) printf("%i: result=%i\n", MYTHREAD, result);
     if (verbose) printf("%i: fresult=%f\n", MYTHREAD, fresult);
     VERIFY_FOO_SUM(MYTHREAD+1, result); /* +1 because prefix_reduce is inclusive */
     VERIFY_BAR_SUM(MYTHREAD+1, fresult);
   }
   BARRIER();
   if (MYTHREAD == 0) printf("bupc_allv_broadcast(shared void *)\n");
   BARRIER();
   { /* test we can broadcast pointers (in this case from all_alloc so we can 
        verify correctness - obviously you'd probably never use it exactly this way) */
     shared void *p = upc_all_alloc(THREADS,1);
     shared void *myp = NULL;
     if (MYTHREAD==0) myp = p;

     shared void *result = bupc_allv_broadcast(shared void *, myp, 0);

     if (result != p) { fprintf(stderr, "ERROR: got incorrect pointer val from bupc_allv_broadcast\n"); }
     BARRIER();
     if (MYTHREAD==0) { upc_free(p); printf("test complete.\n"); }
   }
   BARRIER();
   if (MYTHREAD == 0) printf("bupc_allv_gather_all(shared [1] char *)\n");
   BARRIER();
   { /* test we can exchange pointers (in this case from all_alloc so we can 
        verify correctness - obviously you'd probably never use it exactly this way) */
     shared [1] char *p = upc_all_alloc(THREADS,1);
     shared [1] char *myp = p+MYTHREAD;
     shared [1] char **result = my_calloc(THREADS,sizeof(shared [1] char *));

     bupc_allv_gather_all(shared [1] char *, myp, result);
     for (int i=0; i < THREADS; i++) {
       if (result[i] != p + i) { 
         fprintf(stderr, "%i: ERROR: got incorrect pointer val from bupc_allv_gather_all at %i\n",
           MYTHREAD, i); 
       }
     }
     free(result);
     BARRIER();
     if (MYTHREAD==0) { upc_free(p); printf("test complete.\n"); }
   }
   BARRIER();
   if (MYTHREAD == 0) printf("done.\n");
   return 0;
}
