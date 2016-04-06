/*                                                         */
/*  MPI-BASED "ALL-TO-ALL" COMMUNICATION PERFORMANCE TEST  */
/*                                                         */
/*  ANDREW A. JOHNSON   AHPCRC/NCSI   AUGUST 2004          */
/*                                                         */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mpi.h>
#ifdef _CRAY
#include <intrinsics.h>
#else
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
#define EEPS 1.e-9

int main(int argc, char *argv[]){

   int i, j, k, m, ip, num, npes, mypn, itoo, ifrom;
   int incMB, nreq, itooL[200], ifromL[200], itooLR[200], ifromLR[200];
   double *d1, *d2;
   MPI_Status stat, statL[400];
   MPI_Request reqL[400];
   long long t1, t2, tt;
   double totalT, tmin, tmax, tavg, tmin2, tmax2, tavg2;
   double rl1, rl2, rl, drl, ri, rnpes, minMB, maxMB, rnum, rrr, val;
   FILE *fp;
   char fname[20];

   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &npes);
   MPI_Comm_rank(MPI_COMM_WORLD, &mypn);
   rnpes = (double) npes;

   MPI_Barrier(MPI_COMM_WORLD);

   t1 = _rtc();
   if (mypn == 0){
   /* printf("MINIMUM MB ARRAY SIZE?\n"); */
      scanf("%lf", &minMB);
   /* printf("MAXIMUM MB ARRAY SIZE?\n"); */
      scanf("%lf", &maxMB);
   /* printf("NUMBER OF TESTS?\n"); */
      scanf("%d", &incMB);
   }
   MPI_Bcast(&minMB, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
   MPI_Bcast(&maxMB, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
   MPI_Bcast(&incMB, 1, MPI_INT   , 0, MPI_COMM_WORLD);

   rl1 = log10(minMB);
   rl2 = log10(maxMB);
   drl = (rl2 - rl1) / (double) (incMB-1);

   rnum = 1000000. * maxMB / sizeof(double) + 0.5;
   num = (int) rnum;
   d1 = (double *) malloc(sizeof(double) * (num+1000));
   d2 = (double *) malloc(sizeof(double) * (num+1000));
   t2 = _rtc();

   /* CREATE RANDOM itoo AND ifrom LISTS            */
   /* (SO THAT THE TEST DOESN'T USE ANY "PREFERRED" */
   /*  PROCESSOR-TO-PROCESSOR DIRECTIONS)           */

   srand48(1234 + 10*mypn);
   for (i = j = 0; i < npes; i++){
      if (i != mypn){
         itooLR[j] = ifromLR[j] = i;  /* WARNING: LOOKS LIKE THE MAXIMUM    */
         j++;                         /* NUMBER OF PROCESSORS IS HARD-WIRED */
      }                               /* IN THE SIZE OF THESE ARRAYS        */
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
   MPI_Barrier(MPI_COMM_WORLD);

   /* SOME "SANITY" CHECKS */

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

   /* --- LETS TEST THE 'MPI_Sendrecv' VERSION FIRST --- */

   /* FOR SOME UNKNOWN REASON, FIRST SENDRECV IS SLOWER THAN THE REST */
   /* SO WE'LL SEND A FEW TEST MESSAGES FIRST TO CLEAR THAT UP        */

   num = 10000;
   for (i = 0; i < num; i++) d1[i] = (double) i;  /* SOME DUMMY DATA TO SEND */

   MPI_Barrier(MPI_COMM_WORLD);
   for (k = 1; k <= 4; k++){
      t1 = _rtc();
      for (ip = 1; ip < npes; ip++){
         itoo  = mypn + ip;  if (itoo >= npes) itoo = itoo - npes;
         ifrom = mypn - ip;  if (ifrom < 0) ifrom = ifrom + npes;
          itooL[ip-1] = itoo;
         ifromL[ip-1] = ifrom;
         MPI_Sendrecv(d1, num, MPI_DOUBLE, itoo , 111,
                      d2, num, MPI_DOUBLE, ifrom, 111, MPI_COMM_WORLD, &stat);
      }
      t2 = _rtc();
   }
   MPI_Barrier(MPI_COMM_WORLD);

   /* ROUND-ROBBIN TEST USING MPI_SENDRECV */

   if (mypn == 0){
      sprintf(fname, "outMPI-SR-%03d.txt", npes);
      fp = fopen(fname, "w");
   }
   for (rl = rl1; rl <= rl2; rl += drl){
      ri = 1000000.0 * pow(10., rl) / 8. + 0.5;
      num = (int) ri;
      ri = 8. * num / 1000000.;

      for (j = 0; j < num; j++) d1[j] = (double) j;  /* SOME DUMMY DATA */
      MPI_Barrier(MPI_COMM_WORLD);
      t1 = _rtc();

      for (i = 0; i < (npes-1); i++){                       /* ACTUAL TEST */
         MPI_Sendrecv(d1, num, MPI_DOUBLE,  itooL[i], 111,  /* ACTUAL TEST */
                      d2, num, MPI_DOUBLE, ifromL[i], 111,  /* ACTUAL TEST */
                      MPI_COMM_WORLD, &stat);               /* ACTUAL TEST */
      }                                                     /* ACTUAL TEST */

      t2 = _rtc();
      tt = t2 - t1;
      totalT = tt / (double) IRTC_RATE();
      MPI_Barrier(MPI_COMM_WORLD);

      MPI_Reduce(&totalT, &tmin, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
      MPI_Reduce(&totalT, &tmax, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
      MPI_Reduce(&totalT, &tavg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
      if (mypn == 0){
         tavg = tavg / rnpes;

         tavg2 = tavg / (rnpes-1.);
         tmin2 = tmin / (rnpes-1.);
         tmax2 = tmax / (rnpes-1.);
         fprintf(fp, "%20.13lf  %20.13lf  %20.13lf\n",ri,tavg,tavg2);
      }
   }
   if (mypn == 0) fclose(fp);

   /* ---- TEST USING NON-BLOCKING SEND & RECV ---- */

   if (mypn == 0){
      sprintf(fname, "outMPI-NB-%03d.txt", npes);
      fp = fopen(fname, "w");
   }
   for (rl = rl1; rl <= rl2; rl += drl){
      ri = 1000000.0 * pow(10., rl) / 8. + 0.5;
      num = (int) ri;
      ri = 8. * num / 1000000.;

      for (j = 0; j < num; j++) d1[j] = (double) j;  /* SOME DUMMY DATA */
      nreq = 0;
      MPI_Barrier(MPI_COMM_WORLD);
      t1 = _rtc();
 
      /* POST ALL RECEIVES FIRST */

      for (i = 0; i < (npes-1); i++){                     /* ACTUAL TEST */
         MPI_Irecv(d2, num, MPI_DOUBLE, ifromLR[i], 222,  /* ACTUAL TEST */
                   MPI_COMM_WORLD, &reqL[nreq++]);        /* ACTUAL TEST */
      }                                                   /* ACTUAL TEST */

      /* POST ALL SENDS NEXT */

      for (i = 0; i < (npes-1); i++){                     /* ACTUAL TEST */
         MPI_Isend(d1, num, MPI_DOUBLE, itooLR[i], 222,   /* ACTUAL TEST */
                   MPI_COMM_WORLD, &reqL[nreq++]);        /* ACTUAL TEST */
      }                                                   /* ACTUAL TEST */

      /* WAIT FOR COMPLETION */

      MPI_Waitall(nreq, reqL, statL);

      t2 = _rtc();
      tt = t2 - t1;
      totalT = tt / (double) IRTC_RATE();
      MPI_Barrier(MPI_COMM_WORLD);

      MPI_Reduce(&totalT, &tmin, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
      MPI_Reduce(&totalT, &tmax, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
      MPI_Reduce(&totalT, &tavg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
      if (mypn == 0){
         tavg = tavg / rnpes;

         tavg2 = tavg / (rnpes-1.);
         tmin2 = tmin / (rnpes-1.);
         tmax2 = tmax / (rnpes-1.);
         fprintf(fp, "%20.13lf  %20.13lf  %20.13lf\n",ri,tavg,tavg2);
      }
   }
   if (mypn == 0) fclose(fp);

   MPI_Finalize();
}
