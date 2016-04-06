/*                                                         */
/*  UPC-BASED "ALL-TO-ALL" COMMUNICATION PERFORMANCE TEST  */
/*                                                         */
/*  ANDREW A. JOHNSON   AHPCRC/NCSI   AUGUST 2004          */
/*                                                         */
/*  Minor changes by Dan Bonachea, to work in test suite   */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <upc.h>
#ifdef _CRAY
#define USE_PRAGMAS 1
#include <intrinsics.h>
#ifdef __crayx1
  #define IRTC_RATE() 100
#else
  #define IRTC_RATE() 75
#endif
#else
#define USE_PRAGMAS 0
#include <sys/time.h>
#include <inttypes.h>
static int64_t mygetMicrosecondTimeStamp(void) {
    int64_t retval;
    struct timeval tv;
    if (gettimeofday(&tv, NULL)) {
        perror("gettimeofday");
        abort();
    }
    retval = ((int64_t)tv.tv_sec) * 1000000 + tv.tv_usec;
    return retval;
}
#define _rtc() mygetMicrosecondTimeStamp()
#define IRTC_RATE() 1000000.0
#endif

#define MIN_ARRAY_MB 	0.0001
#define MAX_ARRAY_MB 	100
#define NUM_TESTS 	50

typedef shared [] double *ptr_shared_dbl;

shared ptr_shared_dbl d1S[THREADS];
shared ptr_shared_dbl d2S[THREADS];

shared double r1SH[THREADS];
shared double r2SH[THREADS];
shared double r3SH[THREADS];
shared int    i1SH[THREADS];
shared int    i2SH[THREADS];
shared int    i3SH[THREADS];

#define EEPS 1.e-9

int main(int argc, char **argv){

   int i, j, k, m, ip, num, npes, mypn, itoo, ifrom, itest;
   int incMB, nreq, itooL[200], ifromL[200], itooLR[200], ifromLR[200];
   double *d1, *d2;
   long long t1, t2, tt;
   double totalT, tmin, tmax, tavg, tmin2, tmax2, tavg2;
   double rl1, rl2, rl, drl, ri, rnpes, minMB, maxMB, rnum, val, rrr;
   FILE *fp;
   char fname[20];

   npes = THREADS;
   mypn = MYTHREAD;

   rnpes = (double) npes;

   upc_barrier;

   if (mypn == 0){
   #if STDIN_INPUT
      scanf("%lf", &minMB);
      scanf("%lf", &maxMB);
      scanf("%d", &incMB);
   #else
      if (argc > 1) minMB = atof(argv[1]);
      else          minMB = MIN_ARRAY_MB;
      if (argc > 2) maxMB = atof(argv[2]);
      else          maxMB = MAX_ARRAY_MB;
      if (argc > 3) incMB = atoi(argv[3]);
      else          incMB = NUM_TESTS;
   #endif
      printf("MINIMUM MB ARRAY SIZE: %f\n", minMB);
      printf("MAXIMUM MB ARRAY SIZE: %f\n", maxMB);
      printf("NUMBER OF TESTS: %i\n", incMB);

      r1SH[MYTHREAD] = minMB;
      r2SH[MYTHREAD] = maxMB;
      i1SH[MYTHREAD] = incMB;
   }
   upc_barrier;

   if (mypn != 0){
      minMB = r1SH[0];
      maxMB = r2SH[0];
      incMB = i1SH[0];
   }
   upc_barrier;

   rl1 = log10(minMB);
   rl2 = log10(maxMB);
   drl = (rl2 - rl1) / (double) (incMB-1);

   rnum = 1000000. * maxMB / sizeof(double) + 0.5;
   num = (int) rnum;

   /* ALLOCATE THE SHARRED DATA TRANSFER ARRAYS */

   upc_barrier;
   d1S[MYTHREAD] = upc_alloc((num+1000) * sizeof(double));
   d2S[MYTHREAD] = upc_alloc((num+1000) * sizeof(double));
   upc_barrier;

   d1 = (double *) d1S[MYTHREAD];  /* CAST INTO A LOCAL POINTER */
   d2 = (double *) d2S[MYTHREAD];  /* CAST INTO A LOCAL POINTER */

   t2 = _rtc();

   /* CREATE RANDOM itoo AND ifrom LISTS            */
   /* (SO THAT THE TEST DOESN'T USE ANY "PREFERRED" */
   /*  PROCESSOR-TO-PROCESSOR DIRECTIONS)           */

   srand48(1234 + 10*mypn);
   for (i = j = 0; i < npes; i++){
      if (i != mypn){
         itooLR[j] = ifromLR[j] = i; /* THESE SIZES ARE HARD-WIRED (200)     */
         j++;                        /* SO SHOULD BE CHANGED (ABOVE) IF MORE */
      }                              /* THAN 200 PROCESSORS ARE USED */
   }
   for (m = 0; m < 100; m++){
      for (i = 0; i < (npes-1); i++){
         rrr = drand48();
         val = (npes-1.-2.*EEPS)*rrr + EEPS;
         j = (int) val;
         if (j < 0 || j >= (npes-1)) j = 1;
         k = itooLR[i];
         itooLR[i] = itooLR[j];
         itooLR[j] = k;

         rrr = drand48();
         val = (npes-1.-2.*EEPS)*rrr + EEPS;
         j = (int) val;
         if (j < 0 || j >= (npes-1)) j = 1;
         k = ifromLR[i];
         ifromLR[i] = ifromLR[j];
         ifromLR[j] = k;
      }
   }
   upc_barrier;

   /* SOME SANITY CHECKS */

   for (i = 0; i < (npes-1); i++){
      if (itooLR[i] == mypn){
         printf("ERROR 1\n");
         exit(1);
      }
      if (ifromLR[i] == mypn){
         printf("ERROR 2\n");
         exit(1);
      }
   }
   for (i = 0; i < (npes-2); i++){
      for (j = (i+1); j < (npes-1); j++){
         if (itooLR[i] == itooLR[j]){
            printf("ERROR 3\n");
            exit(1);
         }
         if (ifromLR[i] == ifromLR[j]){
            printf("ERROR 4\n");
            exit(1);
         }
      }
   }

   /* ---- ROUND-ROBBIN MEMORY GRAB ---- */

   if (mypn == 0){
      sprintf(fname, "outUPC-G-%03d.txt", npes);
    #ifdef STDOUT_OUTPUT
      fp = stdout; fprintf(fp, "%s\n", fname);
    #else
      fp = fopen(fname, "w");
    #endif
   }
   itest = 0;
   for (rl = rl1; rl <= rl2; rl += drl){
      ri = 1000000.0 * pow(10., rl) / 8. + 0.5;
      num = (int) ri;
      ri = 8. * num / 1000000.;

      for (j = 0; j < num; j++){
         d1[j] = (double) j;
      }
      upc_barrier;
      /* INITIALIZATION */
      for (i = 0; i < (npes-1); i++){
         for (j = 0; j < num; j++){
            d2[j] = d1S[ ifromLR[i] ][j];
         }
      }
      upc_barrier;
      /* PRE-RUN OF THE TEST */
      /* (FOR SOME UNKNOWN REASON, FIRST TRANSFER IS SLOWER THAN THE REST  */
      /*  SO WE'LL SEND A FEW TEST MESSAGES FIRST TO CLEAR THAT UP)        */
      if (itest == 0){
         for (k = 1; k <= 3; k++){
            for (i = 0; i < (npes-1); i++){
#if USE_PRAGMAS
#pragma concurrent
#endif
               for (j = 0; j < num; j++){
                  d2[j] = d1S[ ifromLR[i] ][j];
               }
            }
         }
         itest = 1;
      }
      upc_barrier;
      t1 = _rtc();

      for (i = 0; i < (npes-1); i++){        /* MAIN TEST HERE */
#if USE_PRAGMAS
#pragma concurrent                           /* MAIN TEST HERE */
#endif
         for (j = 0; j < num; j++){          /* MAIN TEST HERE */
            d2[j] = d1S[ ifromLR[i] ][j];    /* MAIN TEST HERE */
         }                                   /* MAIN TEST HERE */
      }                                      /* MAIN TEST HERE */

      t2 = _rtc();
      tt = t2 - t1;
      totalT = tt / (double) IRTC_RATE();
      upc_barrier;

      r1SH[MYTHREAD] = totalT;

      upc_barrier;

      if (mypn == 0){
         tmin = totalT;
         tmax = totalT;
         tavg = totalT;
         for (ip = 1; ip < npes; ip++){
            if (r1SH[ip] < tmin) tmin = r1SH[ip];
            if (r1SH[ip] > tmax) tmax = r1SH[ip];
            tavg += r1SH[ip];
         }
         tavg = tavg / rnpes;

         tavg2 = tavg / (rnpes-1.);
         tmin2 = tmin / (rnpes-1.);
         tmax2 = tmax / (rnpes-1.);
         fprintf(fp, "%20.13lf  %20.13lf  %20.13lf\n",ri,tavg,tavg2);
      }
   }
   if (mypn == 0 && fp != stdout) fclose(fp);

   /* ---- ROUND-ROBBIN MEMORY PUT ---- */

   if (mypn == 0){
      sprintf(fname, "outUPC-P-%03d.txt", npes);
    #ifdef STDOUT_OUTPUT
      fp = stdout; fprintf(fp, "%s\n", fname);
    #else
      fp = fopen(fname, "w");
    #endif
   }
   itest = 0;
   for (rl = rl1; rl <= rl2; rl += drl){
      ri = 1000000.0 * pow(10., rl) / 8. + 0.5;
      num = (int) ri;
      ri = 8. * num / 1000000.;

      for (j = 0; j < num; j++){
         d1[j] = (double) j;
      }
      upc_barrier;
      /* PRE-RUN OF THE TEST */
      if (itest == 0){
         for (k = 1; k <= 3; k++){
            for (i = 0; i < (npes-1); i++){
#if USE_PRAGMAS
#pragma concurrent
#endif
               for (j = 0; j < num; j++){
                  d2S[ itooLR[i] ][j] = d1[j];
               }
            }
         }
         itest = 1;
      }
      upc_barrier;
      t1 = _rtc();

      for (i = 0; i < (npes-1); i++){       /* MAIN TEST HERE */
#if USE_PRAGMAS
#pragma concurrent                          /* MAIN TEST HERE */
#endif
         for (j = 0; j < num; j++){         /* MAIN TEST HERE */
            d2S[ itooLR[i] ][j] = d1[j];    /* MAIN TEST HERE */
         }                                  /* MAIN TEST HERE */
      }                                     /* MAIN TEST HERE */

      t2 = _rtc();
      tt = t2 - t1;
      totalT = tt / (double) IRTC_RATE();
      upc_barrier;

      r1SH[MYTHREAD] = totalT;

      upc_barrier;

      if (mypn == 0){
         tmin = totalT;
         tmax = totalT;
         tavg = totalT;
         for (ip = 1; ip < npes; ip++){
            if (r1SH[ip] < tmin) tmin = r1SH[ip];
            if (r1SH[ip] > tmax) tmax = r1SH[ip];
            tavg += r1SH[ip];
         }
         tavg = tavg / rnpes;

         tavg2 = tavg / (rnpes-1.);
         tmin2 = tmin / (rnpes-1.);
         tmax2 = tmax / (rnpes-1.);
         fprintf(fp, "%20.13lf  %20.13lf  %20.13lf\n",ri,tavg,tavg2);
      }
   }
   if (mypn == 0 && fp != stdout) fclose(fp);

   /* ---- ROUND-ROBBIN MEMORY GRAB WITH MULTI-STREAMING ---- */

   if (mypn == 0){
      sprintf(fname, "outUPC-GM-%03d.txt", npes);
    #ifdef STDOUT_OUTPUT
      fp = stdout; fprintf(fp, "%s\n", fname);
    #else
      fp = fopen(fname, "w");
    #endif
   }
   itest = 0;
   for (rl = rl1; rl <= rl2; rl += drl){
      ri = 1000000.0 * pow(10., rl) / 8. + 0.5;
      num = (int) ri;
      ri = 8. * num / 1000000.;

      for (j = 0; j < num; j++){
         d1[j] = (double) j;
      }
      upc_barrier;
      /* PRE-RUN OF THE TEST */
      if (itest == 0){
         for (k = 1; k <= 3; k++){
#if USE_PRAGMAS
#pragma csd parallel for private(i, j)
#endif
            for (i = 0; i < (npes-1); i++){
#if USE_PRAGMAS
#pragma concurrent
#endif
               for (j = 0; j < num; j++){
                  d2[j] = d1S[ ifromLR[i] ][j];
               }
            }
         }
         itest = 1;
      }
      upc_barrier;
      t1 = _rtc();
#if USE_PRAGMAS
#pragma csd parallel for private(i, j)      /* MAIN TEST HERE */
#endif
      for (i = 0; i < (npes-1); i++){       /* MAIN TEST HERE */
#if USE_PRAGMAS
#pragma concurrent                          /* MAIN TEST HERE */
#endif
         for (j = 0; j < num; j++){         /* MAIN TEST HERE */
            d2[j] = d1S[ ifromLR[i] ][j];   /* MAIN TEST HERE */
         }                                  /* MAIN TEST HERE */
      }                                     /* MAIN TEST HERE */

      t2 = _rtc();
      tt = t2 - t1;
      totalT = tt / (double) IRTC_RATE();
      upc_barrier;

      r1SH[MYTHREAD] = totalT;

      upc_barrier;

      if (mypn == 0){
         tmin = totalT;
         tmax = totalT;
         tavg = totalT;
         for (ip = 1; ip < npes; ip++){
            if (r1SH[ip] < tmin) tmin = r1SH[ip];
            if (r1SH[ip] > tmax) tmax = r1SH[ip];
            tavg += r1SH[ip];
         }
         tavg = tavg / rnpes;

         tavg2 = tavg / (rnpes-1.);
         tmin2 = tmin / (rnpes-1.);
         tmax2 = tmax / (rnpes-1.);
         fprintf(fp, "%20.13lf  %20.13lf  %20.13lf\n",ri,tavg,tavg2);
      }
   }
   if (mypn == 0 && fp != stdout) fclose(fp);

   /* ----- ROUND-ROBBIN MEMORY PUT WITH MULTI-STREAMING ---- */

   if (mypn == 0){
      sprintf(fname, "outUPC-PM-%03d.txt", npes);
    #ifdef STDOUT_OUTPUT
      fp = stdout; fprintf(fp, "%s\n", fname);
    #else
      fp = fopen(fname, "w");
    #endif
   }
   itest = 0;
   for (rl = rl1; rl <= rl2; rl += drl){
      ri = 1000000.0 * pow(10., rl) / 8. + 0.5;
      num = (int) ri;
      ri = 8. * num / 1000000.;

      for (j = 0; j < num; j++){
         d1[j] = (double) j;
      }
      upc_barrier;
      /* PRE-RUN OF THE TEST */
      if (itest == 0){
         for (k = 1; k <= 3; k++){
#if USE_PRAGMAS
#pragma csd parallel for private(i, j)
#endif
            for (i = 0; i < (npes-1); i++){
#if USE_PRAGMAS
#pragma concurrent
#endif
               for (j = 0; j < num; j++){
                  d2S[ itooLR[i] ][j] = d1[j];
               }
            }
         }
         itest = 1;
      }
      upc_barrier;
      t1 = _rtc();
#if USE_PRAGMAS
#pragma csd parallel for private(i, j)     /* MAIN TEST HERE */
#endif
      for (i = 0; i < (npes-1); i++){      /* MAIN TEST HERE */
#if USE_PRAGMAS
#pragma concurrent                         /* MAIN TEST HERE */
#endif
         for (j = 0; j < num; j++){        /* MAIN TEST HERE */
            d2S[ itooLR[i] ][j] = d1[j];   /* MAIN TEST HERE */
         }                                 /* MAIN TEST HERE */
      }                                    /* MAIN TEST HERE */

      t2 = _rtc();
      tt = t2 - t1;
      totalT = tt / (double) IRTC_RATE();
      upc_barrier;

      r1SH[MYTHREAD] = totalT;

      upc_barrier;

      if (mypn == 0){
         tmin = totalT;
         tmax = totalT;
         tavg = totalT;
         for (ip = 1; ip < npes; ip++){
            if (r1SH[ip] < tmin) tmin = r1SH[ip];
            if (r1SH[ip] > tmax) tmax = r1SH[ip];
            tavg += r1SH[ip];
         }
         tavg = tavg / rnpes;

         tavg2 = tavg / (rnpes-1.);
         tmin2 = tmin / (rnpes-1.);
         tmax2 = tmax / (rnpes-1.);
         fprintf(fp, "%20.13lf  %20.13lf  %20.13lf\n",ri,tavg,tavg2);
      }
   }
   if (mypn == 0 && fp != stdout) fclose(fp);
   if (mypn == 0) printf("done.\n");
}
