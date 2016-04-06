/* a simple, embarrassingly parallel scaling tester for UPC, POSIX threads, Solaris threads */
#ifndef __UPC__
#define _REENTRANT    /* basic 3-lines for threads */
#include <pthread.h>
#ifdef __sun
     #include <thread.h>
#endif
#endif
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#if __UPC_TICK__
#include <upc_tick.h>
#endif

#define HAVE_SETCONCURRENCY 1

  static int64_t mygetMicrosecondTimeStamp(void) {
#if __UPC_TICK__
      return upc_ticks_to_ns(upc_ticks_now()) / 1000;
#else
      int64_t retval;
      struct timeval tv;
      if (gettimeofday(&tv, NULL)) {
          perror("gettimeofday");
          abort();
      }
      retval = ((int64_t)tv.tv_sec) * 1000000 + tv.tv_usec;
      return retval;
#endif
  }
  #define TIME() mygetMicrosecondTimeStamp()

     void *compute(void *);   /* thread routine */
     int i;
     int iters = 0;

     int
     main(int argc, char *argv[])
     {
       int threads = 0;
       int64_t start,end;
       int print = 1;
#ifdef __UPC__
             print = (!MYTHREAD);
             if (argc < 2)  {
                     printf("%s [iters]\n",argv[0]);
                     return (1);
             }
             threads = THREADS;
#else
             if (argc < 4)  {
                     printf("%s [iters] [thrlib] [threadcnt]\n",argv[0]);
                     printf("thrlib=0 to use pthread_create()\n");
#ifdef __sun
                     printf("thrlib=1 to use thr_create()\n");
#endif
                     return (1);
             }
             threads = atoi(argv[3]);
             if (threads < 1) threads = 1;
#endif
             iters = atoi(argv[1]);
             if (iters < 1) iters = 10000000;
             start = TIME();
#ifdef __UPC__
             if (print) printf("Testing %i iterations with %i UPC threads...\n",iters,threads);
             upc_barrier;
             compute((void *)(uintptr_t)MYTHREAD);
             upc_barrier;
#else
             {
             pthread_t *tid = malloc(threads*sizeof(pthread_t));
#if HAVE_SETCONCURRENCY
             pthread_setconcurrency(threads);
#endif
             switch (*argv[2])  {
             case '0':  /* POSIX */
               printf("Testing %i iterations with %i POSIX threads...\n",iters,threads);
               for ( i = 0; i < threads; i++) {
                 pthread_attr_t attr;
                 if (pthread_attr_init(&attr)) perror("pthread_attr_init");
                 if (pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM)) perror("pthread_attr_setscope");
                 if (pthread_create(&tid[i], NULL, compute, (void *)(uintptr_t)i)) perror("pthread_create");
               }
               for ( i = 0; i < threads; i++) {
                 if (pthread_join(tid[i], NULL)) perror("pthread_join");
               }
               break;
#ifdef __sun
             case '1':  /* Solaris */
               printf("Testing %i iterations with %i Solaris threads...\n",iters,threads);
                     for ( i = 0; i < threads; i++)
                             thr_create(NULL, 0, compute, (void *)(uintptr_t)i, 0, &tid[i]);
                     while (thr_join(0, NULL, NULL) == 0)
                             ;
                     break;
#endif
             default: printf("ERROR: unknown thread lib\n"); exit(1);
             }  /* switch */
             }
#endif
             end = TIME();
             if (print) printf("total time: %i us\n", (int)(end-start));
             if (print) printf("done.\n");
             return (0);
     }  /* main */

     double foo = 0;
     void *
     compute(void *arg)
     {
             double x = 1.0001;
             int64_t start,end;
             int i;
             uintptr_t tmp = (uintptr_t)arg;
             int mythread = (int)tmp;
             printf("thread %d computing %i iterations...\n", mythread, iters);
             start=TIME();
             for (i=0; i < iters; i++) {
               x /= x;
             }
             end=TIME();
             foo += x;
             printf("thread %d time: %i us\n", mythread, (int)(end-start));
             return (NULL);
     }
