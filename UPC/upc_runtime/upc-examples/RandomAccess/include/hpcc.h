/* -*- mode: C; tab-width: 2; indent-tabs-mode: nil; fill-column: 79; coding: iso-latin-1-unix -*- */

#ifndef HPCC_H
#define HPCC_H 1

/* HPL includes:
stdio.h
stdlib.h
string.h
stdarg.h
vararg.h (if necessary)
mpi.h
*/
//#include <hpl.h>

#include <hpccver.h>

#include <math.h>
#include <time.h>

/* definitions */
#define HPL_T_test int
#define HPL_T_FACT int
#define HPL_T_TOP int
#define HPL_T_SWAP int
#define HPL_MAX_PARAM 16

#include <stdio.h>
#include <stdlib.h>

/* parameters of execution */
typedef struct {
  /* HPL section */
   HPL_T_test                 test;
   int                        nval  [HPL_MAX_PARAM],
                              nbval [HPL_MAX_PARAM],
                              pval  [HPL_MAX_PARAM],
                              qval  [HPL_MAX_PARAM],
                              nbmval[HPL_MAX_PARAM],
                              ndvval[HPL_MAX_PARAM],
                              ndhval[HPL_MAX_PARAM];
   HPL_T_FACT                 pfaval[HPL_MAX_PARAM],
                              rfaval[HPL_MAX_PARAM];
   HPL_T_TOP                  topval[HPL_MAX_PARAM];
   HPL_T_FACT                 rpfa;
   HPL_T_SWAP                 fswap;
   int ns, nbs, npqs, npfs, nbms, ndvs, nrfs, ntps, ndhs, tswap, L1notran, Unotran, equil, align;

  /* HPCC section */
  char inFname[256 + 1], outFname[256 + 1];
  int PTRANSns, PTRANSnval[2 * HPL_MAX_PARAM];
  int PTRANSnbs, PTRANSnbval[2 * HPL_MAX_PARAM];
  int PTRANSnpqs, PTRANSpval[2 * HPL_MAX_PARAM], PTRANSqval[2 * HPL_MAX_PARAM];
  double Tflops, ptransGBs, MPIGUPs, StarGUPs, SingleGUPs, StarStreamCopyGBs, StarStreamScaleGBs,
    StarStreamAddGBs, StarStreamTriadGBs, SingleStreamCopyGBs, SingleStreamScaleGBs,
    SingleStreamAddGBs, SingleStreamTriadGBs;
  double MaxPingPongLatency, RandomlyOrderedRingLatency, MinPingPongBandwidth,
    NaturallyOrderedRingBandwidth, RandomlyOrderedRingBandwidth;

  int Failure; /* over all failure failure of the benchmark */

  unsigned long HPLMaxProcMem;
  int HPLMaxProc;
  int RunHPL, RunPTRANS, RunStarStream, RunSingleStream, RunMPIRandomAccess, RunStarRandomAccess,
    RunSingleRandomAccess, RunLatencyBandwidth;
} HPCC_Params;
/*
This is what needs to be done to add a new benchmark:
-  Add the benchmark code to the directory structure (headers, makefiles)
-  Add benchmark output data to the HPCC_Params structure.
-  Initialize the HPCC_Params structure data in HPCC_Init().
-  Add a call to the benchmark function in main().
-  Make sure that all the processes fill out the structure with the same data.
-  Print the output of the benchmark in HPCC_Finalize().
*/

extern int HPCC_Init(HPCC_Params *params);
extern int HPCC_Finalize(HPCC_Params *params);
extern int MinStoreBits(unsigned long x);

extern int HPL_main(int ARGC, char **ARGV, double *GflopsPtr, int *failure);
extern int PTRANS(HPCC_Params *params);
extern int MPIRandomAccess(HPCC_Params *params);
extern int SingleRandomAccess(HPCC_Params *params);
extern int StarRandomAccess(HPCC_Params *params);
extern int SingleStream(HPCC_Params *params);
extern int StarStream(HPCC_Params *params);

extern int MaxMem(int nprocs, int imrow, int imcol, int nmat, int *mval, int *nval, int nbmat,
  int *mbval, int *nbval, int ngrids, int *npval, int *nqval, long *maxMem);
extern int RandomAccess(HPCC_Params *params, int doIO, double *GUPs, int *failure);
extern int Stream(HPCC_Params *params, int doIO, double *copyGBs, double *scaleGBs,
  double *addGBs, double *triadGBs, int *failure);
extern void main_bench_lat_bw(HPCC_Params *params);

extern int pdtrans(char *trans, int *m, int *n, int * mb, int *nb, double *a, int *lda,
  double *beta, double *c__, int *ldc, int *imrow, int *imcol, double *work, int *iwork);
extern FILE* pdtransinfo(int *nmat, int *mval, int *nval, int *ldval,
  int *nbmat, int *mbval, int *nbval, int *ldnbval, int *ngrids, int *npval, int *nqval,
  int *ldpqval, int *iaseed, int *imrow, int *imcol, float *thresh, int *iam, int *nprocs,
  double *eps, char *infname, int *fcl, char *outfname);
extern int pdmatgen(int *ictxt, char *aform, char *diag, int *m, int *n, int *mb, int *nb, double*a,
  int *lda, int *iarow, int *iacol, int *iseed, int *iroff, int *irnum, int *icoff, int *icnum,
  int * myrow, int *mycol, int *nprow, int *npcol, double alpha);
extern int pdmatcmp(int *ictxt, int *m_, int *n_, double *a, int *lda_, double *aCopy, int *ldc_,
  double *error);
extern int pxerbla(int *ictxt, char *srname, int *info);
extern int slcombine_(int *ictxt, char *scope, char *op, char * timetype, int *n, int *ibeg,
  double *times);
extern int icopy_(int *n, int *sx, int *incx, int * sy, int *incy);
extern int numroc_(int *, int *, int *, int *, int *);
extern int slboot_(void);
extern int sltimer_(int *i__);
extern int ilcm_(int *, int *);
extern int iceil_(int *, int *);
extern double pdrand();
extern int setran_(int *, int *, int *);
extern int jumpit_(int *, int *, int *, int *);
extern int xjumpm_(int *, int *, int *, int *, int *, int *, int *);
/* ---------------------------------------------------------------------- */
extern double dcputime00(void);
extern double dwalltime00(void);
extern void Cblacs_abort(int ConTxt, int ErrNo);
extern void Cblacs_barrier(int ConTxt, char *scope);
extern void Cblacs_exit(int NotDone);
extern void Cblacs_get(int ConTxt, int what, int *val);
extern void Cblacs_gridexit(int ConTxt);
extern void Cblacs_gridinfo(int ConTxt, int *nprow, int *npcol, int *myrow, int *mycol);
extern void Cblacs_gridinit(int *ConTxt, char *order, int nprow, int npcol);
extern void Cblacs_pinfo(int *mypnum, int *nprocs);
extern void Cdgamn2d(int ConTxt, char *scope, char *top, int m, int n, double *A, int lda, int *rA,
  int *cA, int ldia, int rdest, int cdest);
extern void Cdgamx2d(int ConTxt, char *scope, char *top, int m, int n, double *A, int lda,
  int *rA, int *cA, int ldia, int rdest, int cdest);
extern void Cdgebr2d(int ConTxt, char *scope, char *top, int m, int n, double *A,
  int lda, int rsrc, int csrc);
extern void Cdgebs2d(int ConTxt, char *scope, char *top, int m, int n, double *A, int lda);
extern void Cdgerv2d(int ConTxt, int m, int n, double *A, int lda, int rsrc, int csrc);
extern void Cdgesd2d(int ConTxt, int m, int n, double *A, int lda, int rdest, int cdest);
extern void Cdgsum2d(int ConTxt, char *scope, char *top, int m, int n, double *A, int lda,
  int rdest, int cdest);
extern void Cigebr2d(int ConTxt, char *scope, char *top, int m, int n, int *A, int lda, int rsrc,
  int csrc);
extern void Cigebs2d(int ConTxt, char *scope, char *top, int m, int n, int *A, int lda);
extern void Cigsum2d(int ConTxt, char *scope, char *top, int m, int n, int *A, int lda,
  int rdest, int cdest);
extern void Cblacs_dSendrecv(int ctxt, int mSrc, int nSrc, double *Asrc, int ldaSrc, int rdest,
  int cdest, int mDest, int nDest, double *Adest, int ldaDest, int rsrc, int csrc);
/* ---------------------------------------------------------------------- */
#ifndef MAX
#define MAX(x,y) ((x)>(y)?(x):(y))
#endif
#ifndef MIN
#define MIN(x,y) ((x)<(y)?(x):(y))
#endif
#define DPRN(i,v) do{printf(__FILE__ "(%d)@%d:" #v "=%g\n",__LINE__,i,(double)(v));fflush(stdout);}while(0)

#define FPRINTF(r,f,s,v) do{if(0==r){fprintf(f,s "\n",v);fflush(f);}}while(0)
#define FPRINTF2(r,f,s,v1,v2) do{if(0==r){fprintf(f,s "\n",v1,v2);fflush(f);}}while(0)
#define FPRINTF3(r,f,s,v1,v2,v3) do{if(0==r){fprintf(f,s "\n",v1,v2,v3);fflush(f);}}while(0)
#define BEGIN_IO(r,fn,f) do{if(0==r){f=fopen(fn,"a" );if(!f){f=stderr;FPRINTF(r,f,"Problem with appending to file %s",fn);}}}while(0)
#define END_IO(r,f) do{if(0==r){if(f!=stdout&&f!=stderr)fclose(f);}}while(0)

#define XMALLOC(t,s) ((t*)malloc(sizeof(t)*(s)))
#define XCALLOC(t,s) ((t*)calloc((s),sizeof(t)))

#endif
