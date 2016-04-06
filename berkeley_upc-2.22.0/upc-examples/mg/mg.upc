/* UPC version of the NAS MG benchmark based on the OpenMP C version
   from RWCP, Japan */

/*--------------------------------------------------------------------
  
  NAS Parallel Benchmarks 2.3 OpenMP C versions - MG
 
  This benchmark is an OpenMP C version of the NPB MG code.
  
  The OpenMP C versions are developed by RWCP and derived from the serial
  Fortran versions in "NPB 2.3-serial" developed by NAS.
 
  Permission to use, copy, distribute and modify this software for any
  purpose with or without fee is hereby granted.
  This software is provided "as is" without express or implied warranty.
  
  Send comments on the OpenMP C versions to pdp-openmp@rwcp.or.jp
 
  Information on OpenMP activities at RWCP is available at:
 
           http://pdplab.trc.rwcp.or.jp/pdperf/Omni/
  
  Information on NAS Parallel Benchmarks 2.3 is available at:
  
           http://www.nas.nasa.gov/NAS/NPB/
 
--------------------------------------------------------------------*/
/*--------------------------------------------------------------------
 
  Authors: E. Barszcz
           P. Frederickson
           A. Woo
           M. Yarrow
 
  OpenMP C version: S. Satoh
  UPC version: P. Husbands  
--------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <upc_relaxed.h>
#include <assert.h>
#include <stdlib.h>
#include "npb-C.uph"
#include "globals.uph"

#ifdef DEBUG
void *calloc_check(size_t a, size_t b, int line) {
  void *retval = calloc(a,b);
  if (retval == NULL) {
    fprintf(stderr,"ERROR: failed to calloc(%i,%i) at %s:%i\n", 
            (int)a, (int)b, __FILE__, line);
    fflush(stderr);
    upc_global_exit(-1);
  }
  return retval;
}
#undef calloc
#define calloc(a,b) calloc_check((a),(b),__LINE__)

shared void *upc_alloc_check(size_t s, int line) {
  shared void *retval = upc_alloc(s);
  if ((void *)retval == NULL) {
    fprintf(stderr,"ERROR: failed to upc_alloc(%i) at %s:%i\n", 
            (int)s, __FILE__, line);
    fflush(stderr);
    upc_global_exit(-1);
  }
  return retval;
}
#undef upc_alloc
#define upc_alloc(s) upc_alloc_check((s),__LINE__)
#endif

/* ONLYBUFFER only puts communication buffers in shared space
   for those implementations where the amount of shared memory
   is limited */

#define ONLYBUFFER

/* Structure holding the local portion of the grid and
   associated information */

typedef shared [] double *sdblptr;
typedef shared [] int *sintptr;
#define DIRTYPE sdblptr

typedef struct {
  sdblptr localData;       /* Local data */     
  sintptr sdims;           /* Dimensions of local data */    
  sintptr faceSync;        /* Synchronization points for transfers */   
  sdblptr xzbuffer;        /* Buffers for transfers */
  sdblptr yzbuffer;
  sdblptr xybuffer;        
  sdblptr *directory;      /* Pointers to remote data */
  sintptr *dimsdir;        /* Remote sizes */
  sintptr *facedir;        /* Remote sync points */
  sdblptr *yzdirectory;    /* Remote buffers */
  sdblptr *xzdirectory;
  sdblptr *xydirectory;
  double *G;               /* Local pointer to local data */
  double *yzcommbuffer;    /* Local pointers to buffers */
  double *xzcommbuffer;
  int *dims;               /* Local pointer to size */
  int totalSize;           /* Total number of elements (including ghosts) */
  int globallb[3];         /* What part of the grid do I have */
  int globalub[3];
  int live;                /* Am I alive at this level? */
} upc3d;

/* Function pointers for putting and getting data */

typedef void (*putfntype)(upc3d *,int,int,int,int);
typedef void (*getfntype)(upc3d *,int);
putfntype putfn[3];
getfntype getfn[3];

/* Array access macro */
#define AREF(A,k,j,i) A->G[(k)*A->dims[1]*A->dims[0] + (j)*A->dims[0] + (i)]

/* Spin when not equal and equal to a value */
#ifndef __BERKELEY_UPC_RUNTIME__
  #undef upc_poll 
  #define upc_poll() do { upc_fence; } while(0)
#endif

#define SPINNE(loc,val) while(loc != val) upc_poll();
#define SPINEQ(loc,val) while(loc == val) upc_poll();

/* Linear index of processor (k,j,i).  Used to index into
   the directories declared above */

#define LINEARIZEPROC(k,j,i,level) (k*pd[level][1]*pd[level][0] + j*pd[level][0]+i)

/* Some globals defining your id in a 3-d processor grid 
   and the processor grid dimensions */

int **id;
int **pd;

static int is1, is2, is3, ie1, ie2, ie3;

/* parameters */
#define T_BENCH 1
#define T_INIT  2
#define T_COMM 3

/* Maximum number of levels */
int GMAXLEVEL;

/* Set an individual element with global indices*/

void gset(upc3d *v,int x,int y,int z,double val)
{
  /* Do I have it? */
  if ((v->globallb[0] <= x) && (v->globalub[0] > x) &&
      (v->globallb[1] <= y) && (v->globalub[1] > y) &&
      (v->globallb[2] <= z) && (v->globalub[2] > z)) {
    /* Get local x y and z */
   int localx = x - v->globallb[0];
   int localy = y - v->globallb[1];
   int localz = z - v->globallb[2];
   localx = v->globallb[0] == 0 ? localx : localx + 1;
   localy = v->globallb[1] == 0 ? localy : localy + 1;
   localz = v->globallb[2] == 0 ? localz : localz + 1;
   AREF(v,localz,localy,localx) = val;
  }
}

/* Zero out everything including ghost cells */
void zero(upc3d *z)
{
  memset((void *) z->G, 0, z->totalSize*sizeof(double));
}

/* Figure out what the global bounds will be for a particular
   dimension and extent given my pid in the grid */

void getbounds(int extent, int mypid, int dim_size,int *lb_p, int *ub_p)
{
  int blocksize;
  if(extent-2 < dim_size) {
    if(mypid == 0) {
      *lb_p = 0;
      *ub_p = extent;
    } else {
      *lb_p = *ub_p = extent;
    }
  } else {
    blocksize = ((extent-2)+dim_size-1)/dim_size;
    if(blocksize < 1) {
      printf("%d %d %d\n",extent,blocksize,dim_size);
      upc_global_exit(1);
    }
    if(mypid == 0) {
      *lb_p = 0;
      if(mypid == dim_size-1) {
        *ub_p = extent;
      } else {
        *ub_p = blocksize+1;
      }
    } else {
      *lb_p = (blocksize+1)+(mypid-1)*blocksize;
      if(mypid == dim_size-1) {
        *ub_p = extent;
      } else {
        *ub_p = *lb_p + blocksize;
      }
    }
  }
}

/* Create a level of the grid hierarchy */

upc3d *create_upc3d(int nx,int ny,int nz,int level)
{
  int i,prod=1,nn;
  int size[3];
  upc3d *result = calloc(1,sizeof(upc3d));
  static shared [] sdblptr *shared globaldir;
  static shared [] sdblptr *shared globalyzdir;
  static shared [] sdblptr *shared globalxzdir;
  static shared [] sdblptr *shared globalxydir;
  static shared [] sintptr *shared globalfacedir;
  static shared [] sintptr *shared globaldimsdir;

  size[0]=nx;
  size[1]=ny;
  size[2]=nz;
  result->live = 1;

  if(level < GMAXLEVEL) {
    if(id[level][0] == -1) {
      pd[level][0]=pd[level+1][0];
      pd[level][1]=pd[level+1][1];
      pd[level][2]=pd[level+1][2];

      id[level][0]=id[level+1][0];
      id[level][1]=id[level+1][1];
      id[level][2]=id[level+1][2];
    }
  }
  for(i=0;i < 3;i++) {
    if(size[i]-2 < pd[level][i]) {
      pd[level][i] /= 2;
      if(id[level][i] % 2) {
        id[level][i]/=2;
      } else {
        id[level][i]=-1;
        result->live=0;
        result->globalub[i]=result->globallb[i] = 0;
        continue;
      }
    }
    getbounds(size[i], id[level][i], pd[level][i],&(result->globallb[i]), 
                                    &(result->globalub[i]));
    prod*=(result->globalub[i]-result->globallb[i]);
  }
  if(level < GMAXLEVEL) {
    for(i=0;i < 3;i++) {
      if(id[level+1][i] < 0) {
        id[level][i]=-1;
        result->live = 0;
      }
    }
  }
  result->totalSize = 1;
  result->sdims = (shared [] int *) upc_alloc(3*sizeof(int));
  for(i=0;i < 3;i++) {
    int span = result->globalub[i]-result->globallb[i];
    if(span == 0) {
      result->totalSize = 1;
      result->sdims[0]=result->sdims[1]=result->sdims[2]=0;
      break;
    }
    if(result->globallb[i] > 0) {
      span++;
    }
    if(result->globalub[i] < size[i]) {
      span++;
    }
    result->totalSize*=span;
    result->sdims[i] = span;
  }
  upc_barrier;
  result->dims = (int *) (result->sdims);
#ifdef ONLYBUFFER
  result->localData = (shared [] double *) NULL;
#else
  result->localData = (shared [] double *) 
                      upc_alloc(result->totalSize*sizeof(double));
#endif
  result->xzbuffer = (shared [] double *) 
                      upc_alloc((2*result->sdims[0]*result->sdims[2]+1)*
                      sizeof(double));
  result->yzbuffer = (shared [] double *)
                      upc_alloc((2*result->sdims[1]*result->sdims[2]+1)*
                      sizeof(double));
  result->xybuffer = (shared [] double *)
                      upc_alloc((2*result->sdims[0]*result->sdims[1]+1)*
                      sizeof(double));
#ifdef ONLYBUFFER
  result->G = (double *) calloc(result->totalSize,sizeof(double));
#else
  result->G = (double *) (result->localData);
#endif
  result->faceSync = (shared [] int *) upc_alloc(6*sizeof(int));
  for(i=0;i < 6;i++) {
    result->faceSync[i] = 0;
  }
  upc_barrier;
  nn=pd[level][0]*pd[level][1]*pd[level][2];
  if(MYTHREAD == 0) { 
    globaldir = upc_alloc(nn*sizeof(DIRTYPE));
    globalyzdir = upc_alloc(nn*sizeof(DIRTYPE));
    globalxzdir = upc_alloc(nn*sizeof(DIRTYPE));
    globalxydir = upc_alloc(nn*sizeof(DIRTYPE));
    globalfacedir = upc_alloc(nn*sizeof(DIRTYPE));
    globaldimsdir = upc_alloc(nn*sizeof(DIRTYPE));
  }
  upc_barrier;
  i = LINEARIZEPROC(id[level][2],id[level][1],id[level][0],level);
  if((result->live) && (i < pd[level][0]*pd[level][1]*pd[level][2])) {
    globaldir[i]=result->localData;
    globalyzdir[i]=result->yzbuffer;
    globalxzdir[i]=result->xzbuffer;
    globalxydir[i]=result->xybuffer;
    globalfacedir[i]=result->faceSync;
    globaldimsdir[i]=result->sdims;
  }
  /* Create some local space for the largest planes that have to be
     transferred */
  result->xzcommbuffer = calloc(2*result->dims[0]*result->dims[2]+1,
                                sizeof(double));
  result->yzcommbuffer = calloc(2*result->dims[1]*result->dims[2]+1,
                                sizeof(double));
  upc_barrier;
  zero(result);
  /* Now cache all of these directories */
  result->directory = calloc(nn,sizeof(DIRTYPE));
  upc_memget(result->directory,globaldir,nn*sizeof(DIRTYPE));
  result->yzdirectory = calloc(nn,sizeof(DIRTYPE));
  upc_memget(result->yzdirectory,globalyzdir,nn*sizeof(DIRTYPE));
  result->xzdirectory = calloc(nn,sizeof(DIRTYPE));
  upc_memget(result->xzdirectory,globalxzdir,nn*sizeof(DIRTYPE));
  result->xydirectory = calloc(nn,sizeof(DIRTYPE));
  upc_memget(result->xydirectory,globalxydir,nn*sizeof(DIRTYPE));


  result->facedir = calloc(nn,sizeof(sintptr));
  upc_memget(result->facedir,globalfacedir,nn*sizeof(sintptr));
  result->dimsdir = calloc(nn,sizeof(sintptr));
  upc_memget(result->dimsdir,globaldimsdir,nn*sizeof(sintptr));

  return result;
}

/* Create a hierarchy */
upc3d **create_grid_hierarchy(int nlevels,int *m1,int *m2, int *m3)
{
  upc3d ptr3d;
  int l,i;
  upc3d **resulthier = (upc3d **) calloc(nlevels+1,sizeof(upc3d *));
  
  for(l=nlevels;l >= 1;l--) {
    if(l < nlevels && pd[l][0] != -1) {
      for(i=0;i < 3;i++) {
        pd[l][i]=pd[l+1][i];
        id[l][i]=id[l+1][i];
      }
    }
    resulthier[l] = create_upc3d(m1[l],m2[l],m3[l],l);
  }
  if(MYTHREAD == 0) {
    for(i=1;i <=nlevels;i++) {
    printf("Level %d is a %d x %d x %d processor grid\n",i,pd[i][0], pd[i][1],
           pd[i][2]);
    }
  }
  return resulthier;
  
}



void norm2u3(upc3d *z,int n1,int n2,int n3,
             double *rnm2, double *rnmu,int nx, int ny, int nz,int level)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

/*--------------------------------------------------------------------
c     norm2u3 evaluates approximations to the L2 norm and the
c     uniform (or L-infinity or Chebyshev) norm, under the
c     assumption that the boundaries are periodic or zero.  Add the
c     boundaries in with half weight (quarter weight on the edges
c     and eighth weight at the corners) for inhomogeneous boundaries.
c-------------------------------------------------------------------*/

    double s = 0.0;
    double tmp;
    int i,j,k;
    double p_s = 0.0, p_a = 0.0;
    static shared double rnmu_shared;
    static shared double rnm2_shared;
    static shared double ps_private[THREADS];
    static shared double pa_private[THREADS];
    int ldx,ldy,ldz;
    int n = nx*ny*nz;
    ldx = z->dims[0];
    ldy = z->dims[1];
    ldz = z->dims[2];
    for(k=1;k < ldz-1;k++) {
      for(j=1;j < ldy-1;j++) {
        for(i=1;i < ldx-1;i++) {
          double val = AREF(z,k,j,i);
          p_s = p_s + val*val;
          tmp=fabs(val);
          if(tmp > p_a) p_a = tmp;
        }
      }
     }
     ps_private[MYTHREAD]=p_s;
     pa_private[MYTHREAD]=p_a;
     upc_barrier;
     if(MYTHREAD == 0) {
       p_a=0.0;
       s=0.0;
       for(i=0;i < THREADS;i++) {
         s+=ps_private[i];
         if (pa_private[i] > p_a) p_a = pa_private[i];
       }
       rnm2_shared = sqrt(s/(double)n);
       rnmu_shared = p_a;
     }
     upc_barrier;
     *rnm2=rnm2_shared;
     *rnmu=rnmu_shared;
}

void rep_nrm(upc3d *u, int n1, int n2, int n3,
                    const char *title, int kk) {

/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

/*--------------------------------------------------------------------
c     report on norm
c-------------------------------------------------------------------*/

    double rnm2, rnmu;


    norm2u3(u,n1,n2,n3,&rnm2,&rnmu,nx[kk],ny[kk],nz[kk],kk);
    if(MYTHREAD == 0) {
      printf(" Level%2d in %8s: norms =%21.14e%21.14e\n",
             kk, title, rnm2, rnmu);
    }
}

/* Send and receive section.  xy planes are contiguous so
   we can use a single {upc_}memcpy.  Others need packing
   and unpacking.  The protocol is:
   Send
   Write +/- 1 in appropriate sync point
   When receiving processor sees a 1 unpacks.  -1 means the
     sending and receiving processors are the same.
   When unpacked receiving processor resets sync point to 0
*/

void unpackyz(upc3d *v,int destplane)
{
  double *src = (double *) v->yzbuffer;
  int n = 0;
  int k,j;
  if(destplane != 0) {
    src += v->dims[1]*v->dims[2];
  }
  for(k=0;k < v->dims[2]-0;k++) {
    for(j=0;j < v->dims[1]-0; j++) {
      AREF(v,k,j,destplane) = src[n++];
    }
  }
}

void putyz(upc3d *v,int destxproc,int srcplane,int destplane,int level)
{
  int increment, faceincrement,n,lineardest;
  int k,j,i;
  lineardest = LINEARIZEPROC(id[level][2],id[level][1],destxproc,level);
  if(destplane == 0) {
    increment = 0;
    faceincrement = 0;
  } else {
    increment = v->dims[2]*v->dims[1];
    faceincrement = 1;
  }
  if(destxproc != id[level][0]) {
    n=0;
    for(k=0;k < v->dims[2]-0;k++) {
      for(j=0;j < v->dims[1]-0;j++) {
        v->yzcommbuffer[n++] = AREF(v,k,j,srcplane);
      }
    }
    upc_memput(v->yzdirectory[lineardest]+increment,
               v->yzcommbuffer, n*sizeof(double));
    {
#pragma upc strict
      v->facedir[lineardest][faceincrement] = 1;
    }
  } else {
    /* Do local copy */
    for(k=0;k < v->dims[2]-0;k++) {
      for(j=0;j < v->dims[1]-0; j++) {
        AREF(v,k,j,destplane) = AREF(v,k,j,srcplane);
      }
    }
    {
#pragma upc strict
      v->facedir[lineardest][faceincrement] = -1;
    }
  }
}

void unpackxz(upc3d *v,int destplane)
{
  double *src = (double *) v->xzbuffer;
  int n = 0;
  int k,i;
  if(destplane != 0) {
    src += v->dims[0]*v->dims[2];
  }
  for(k=0;k < v->dims[2]-0;k++) {
    for(i=0;i < v->dims[0]; i++) {
      AREF(v,k,destplane,i) = src[n++];
    }
  }
}

void unpackxy(upc3d *v,int destplane)
{
  double *src = (double *) v->xybuffer;
  if(destplane != 0) {
    src += v->dims[0]*v->dims[1];
  }

  memcpy(v->G + destplane*v->dims[0]*v->dims[1],
         src,v->dims[0]*v->dims[1]*sizeof(double));
}

void putxz(upc3d *v,int destyproc,int srcplane,int destplane,int level)
{
  int increment, faceincrement,n,lineardest;
  int k,j,i;
  if(destplane == 0) {
    increment = 0;
    faceincrement = 2;
  } else {
    increment = v->dims[2]*v->dims[0];
    faceincrement = 3;
  }
  lineardest = LINEARIZEPROC(id[level][2],destyproc,id[level][0],level);
  if(destyproc != id[level][1]) {
    n=0;
    for(k=0;k < v->dims[2]-0;k++) {
      for(i=0;i < v->dims[0]; i++) {
        v->xzcommbuffer[n++] = AREF(v,k,srcplane,i);
      }
    }
    upc_memput(v->xzdirectory[lineardest] + increment,
               v->xzcommbuffer,
               n*sizeof(double));
    {
#pragma upc strict
      v->facedir[lineardest][faceincrement] = 1;
    }
  } else {
    /* Do local copy */
    for(k=0;k < v->dims[2]-0;k++) {
      for(i=0;i < v->dims[0]; i++) {
        AREF(v,k,destplane,i) = AREF(v,k,srcplane,i);
      }
    }
    {
#pragma upc strict
      v->facedir[lineardest][faceincrement] = -1;
    }
  }
}

void putxy(upc3d *v,int destzproc,int srcplane,int destplane,int level)
{
  int increment, faceincrement,lineardest;
  int k,j,i;
  lineardest = LINEARIZEPROC(destzproc,id[level][1],id[level][0],level);
  if(destplane == 0) {
    increment = 0;
    faceincrement = 4;
  } else {
    increment = v->dims[0]*v->dims[1];
    faceincrement = 5;
  }
  if(destzproc != id[level][2]) {
    /*
    upc_memput(v->directory[lineardest]
               +destplane*v->dims[1]*v->dims[0],
               v->G+srcplane*v->dims[1]*v->dims[0],
               v->dims[0]*v->dims[1]*sizeof(double));
    */
    upc_memput(v->xydirectory[lineardest]+increment,
               v->G+srcplane*v->dims[1]*v->dims[0],
               v->dims[0]*v->dims[1]*sizeof(double));
    {
#pragma upc strict
      v->facedir[lineardest][faceincrement] = 1;
    }
  } else {
    memcpy(v->G+destplane*v->dims[1]*v->dims[0],
           v->G+srcplane*v->dims[1]*v->dims[0],
           v->dims[0]*v->dims[1]*sizeof(double));
    {
#pragma upc strict
      v->facedir[lineardest][faceincrement] = -1;
    }
  }
}


void getyz(upc3d *v,int destplane)
{
  int faceincrement;
  if(destplane == 0) {
    faceincrement = 0;
  } else {
    faceincrement = 1;
  }
  {
#pragma upc strict
    SPINEQ(v->faceSync[faceincrement],0);
    if(v->faceSync[faceincrement] != -1) unpackyz(v,destplane);
    v->faceSync[faceincrement] = 0;
  }
}

void getxz(upc3d *v,int destplane)
{
  int faceincrement;
  if(destplane == 0) {
    faceincrement = 2;
  } else {
    faceincrement = 3;
  }
  {
#pragma upc strict
    SPINEQ(v->faceSync[faceincrement],0);
    if(v->faceSync[faceincrement] != -1) unpackxz(v,destplane);
    v->faceSync[faceincrement] = 0;
  }
}


void getxy(upc3d *v,int destplane)
{
  int faceincrement;
  if(destplane == 0) {
    faceincrement = 4;
  } else {
    faceincrement = 5;
  }
  {
#pragma upc strict
    SPINEQ(v->faceSync[faceincrement],0);
    if(v->faceSync[faceincrement] != -1) unpackxy(v,destplane);
    v->faceSync[faceincrement] = 0;
  }
}

int getlinear(int *myid,int dest,int k,int axis) 
{ 
  int lineardest;
  switch(axis) {
  case 0:
    lineardest = LINEARIZEPROC(myid[2],myid[1],dest,k);
    break;
  case 1:
    lineardest = LINEARIZEPROC(myid[2],dest,myid[0],k);
    break;
  case 2:
    lineardest = LINEARIZEPROC(dest,myid[1],myid[0],k);
    break;
  default:
    lineardest = 0; /* Added to suppress compiler warnings -PHH 2013.07.26 */
    upc_global_exit(1);
  }
  return(lineardest);
}

/* comm3 - do boundary as well as ghost region exchange */

void comm3(upc3d *v,int k)
{
  int linearprev,dest,axis;
  timer_start(T_COMM+k);
  if(!v->live) {
    goto END;
  }
  for(axis=0;axis < 3;axis++) {
    /* Send my penultimate to the first of the next processor */
    dest = id[k][axis] == pd[k][axis]-1 ? 0 : id[k][axis]+1;
    (*(putfn[axis]))(v,dest,v->dims[axis]-2,0,k);
    /* Send my first non-ghost to the last of the previous processor */
    dest = id[k][axis] == 0 ? pd[k][axis]-1 : id[k][axis]-1;
    switch(axis) {
    case 0:
      linearprev = LINEARIZEPROC(id[k][2],id[k][1],dest,k);
      break;
    case 1:
      linearprev = LINEARIZEPROC(id[k][2],dest,id[k][0],k);
      break;
    case 2:
      linearprev = LINEARIZEPROC(dest,id[k][1],id[k][0],k);
      break;
    }
    (*(putfn[axis]))(v,dest,1,v->dimsdir[linearprev][axis]-1,k);
    (*(getfn[axis]))(v,0);
    (*(getfn[axis]))(v,v->dims[axis]-1);
  }
 END:
  upc_barrier;
  timer_stop(T_COMM+k);
}

/* Boundary exchange after interpolation */

void comm3_interp(upc3d *z,upc3d *v,int k)
{
  int dest,axis,linearprev;
  timer_start(T_COMM+k);
  if(!v->live) {
    goto END;
  }

  if ((pd[k][0] == pd[k-1][0]) && (pd[k][1] == pd[k-1][1]) &&
      (pd[k][2] == pd[k-1][2])) {
    /* Easy. Send 2 up in each direction.  Same as original comm3, but 
       last ghost region on each processor is actually active. */
    /* Send my penultimate to the first of the next processor */
    /* Exchange yz boundary */
    /* 0 yz, 1 xz, 2 xy */
    for(axis = 0; axis < 3;axis++) {
      dest = id[k][axis] == pd[k][axis]-1 ? 0 : id[k][axis]+1;
      (*(putfn[axis]))(v,dest,v->dims[axis]-2,0,k);
      (*(putfn[axis]))(v,dest,v->dims[axis]-1,1,k);
      (*(getfn[axis]))(v,0);
      (*(getfn[axis]))(v,1);
    }
  } else {
    /* Hard. */
    /* For the axes that aren't chopped, do normal 2 up */
    /* For axes that are chopped, do 2 up then 1 up */
    for(axis = 0;axis < 3;axis++) {
      if(pd[k][axis] == pd[k-1][axis]) {
          dest = id[k][axis] == pd[k][axis]-1 ? 0 : id[k][axis]+1;
          (*(putfn[axis]))(v,dest,v->dims[axis]-2,0,k);
          (*(putfn[axis]))(v,dest,v->dims[axis]-1,1,k);
          (*(getfn[axis]))(v,0);
          (*(getfn[axis]))(v,1);
      } else {
        /* Live or became live */
        if(id[k][axis] % 2) {
          dest = id[k][axis] == pd[k][axis]-1 ? 0 : id[k][axis]+1;
          (*(putfn[axis]))(v,dest,v->dims[axis]-2,0,k);
          (*(putfn[axis]))(v,dest,v->dims[axis]-1,1,k);
          (*(getfn[axis]))(v,0);
          dest = id[k][axis] == 0 ? pd[k][axis]-1 : id[k][axis]-1;
          linearprev = getlinear(&(id[k][0]),dest,k,axis);
          (*(putfn[axis]))(v,dest,1,v->dimsdir[linearprev][axis]-1,k);
        } else {
          /* If previous neighbour is live */
          dest = id[k][axis] == pd[k][axis]-1 ? 0 : id[k][axis]+1;
          (*(getfn[axis]))(v,0);
          (*(getfn[axis]))(v,1);
          (*(putfn[axis]))(v,dest,v->dims[axis]-2,0,k);
          (*(getfn[axis]))(v,v->dims[axis]-1);
        }
      }
      /*printf("%d (%d,%d,%d) completed axis %d ? %d\n",MYTHREAD,
                 id[k][0],id[k][1],id[k][2],axis,z->live);*/
    }
  }
 END:
  upc_barrier;
  timer_stop(T_COMM+k);
  return;
}

void psinv(upc3d *r, upc3d *u, int n1, int n2, int n3,
           double c[4], int k)
{

/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

/*--------------------------------------------------------------------
c     psinv applies an approximate inverse as smoother:  u = u + Cr
c
c     This  implementation costs  15A + 4M per result, where
c     A and M denote the costs of Addition and Multiplication.  
c     Presuming coefficient c(3) is zero (the NPB assumes this,
c     but it is thus not a general case), 2A + 1M may be eliminated,
c     resulting in 13A + 3M.
c     Note that this vectorizes, and is also fine for cache 
c     based machines.  
c-------------------------------------------------------------------*/

    int i3, i2, i1;
    int ldx = u->dims[0];
    int ldy = u->dims[1];
    int ldz = u->dims[2];
    double r1[M], r2[M];
    timer_start(T_COMM+lt+1);
    for (i3 = 1; i3 < ldz-1; i3++) {
      for (i2 = 1; i2 < ldy-1; i2++) {
        for (i1 = 0; i1 < ldx; i1++) {
#if 0
          /* The following form appears to trigger a bug in icc-10 (BUPC bug 2160).  -PHH 2009.10.11 */
          r1[i1] = AREF(r,i3,i2-1,i1) + AREF(r,i3,i2+1,i1)
            + AREF(r,i3-1,i2,i1) + AREF(r,i3+1,i2,i1);
          r2[i1] = AREF(r,i3-1,i2-1,i1) + AREF(r,i3-1,i2+1,i1)
                    + AREF(r,i3+1,i2-1,i1) + AREF(r,i3+1,i2+1,i1);
#else
          r1[i1]  = AREF(r,i3,i2-1,i1);
          r1[i1] += AREF(r,i3,i2+1,i1);
          r1[i1] += AREF(r,i3-1,i2,i1);
          r1[i1] += AREF(r,i3+1,i2,i1);;
          r2[i1]  = AREF(r,i3-1,i2-1,i1);
          r2[i1] += AREF(r,i3-1,i2+1,i1);
          r2[i1] += AREF(r,i3+1,i2-1,i1);
          r2[i1] += AREF(r,i3+1,i2+1,i1);
#endif
        }
        for (i1 = 1; i1 < ldx-1; i1++) {
          AREF(u,i3,i2,i1) = AREF(u,i3,i2,i1)
            + c[0] * AREF(r,i3,i2,i1)
            + c[1] * ( AREF(r,i3,i2,i1-1) + AREF(r,i3,i2,i1+1)
                       + r1[i1] )
            + c[2] * ( r2[i1] + r1[i1-1] + r1[i1+1] );
         /*--------------------------------------------------------------------
         c  Assume c(3) = 0    (Enable line below if c(3) not= 0)
         c---------------------------------------------------------------------
         c    >                     + c(3) * ( r2(i1-1) + r2(i1+1) )
         c-------------------------------------------------------------------*/
        }
      }
    }

    timer_stop(T_COMM+lt+1);
/*--------------------------------------------------------------------
c     exchange boundary points
c-------------------------------------------------------------------*/
    comm3(u,k);

    if (debug_vec[0] >= 1 ) {
        rep_nrm(u,n1,n2,n3,"   psinv",k);
    }

    /*
    if ( debug_vec[3] >= k ) {
        showall(u,n1,n2,n3);
    }
    */
}

void resid( upc3d *u, upc3d *v, upc3d *r, double a[4],
            int n1,int n2,int n3,int k ) 
{

/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

/*--------------------------------------------------------------------
c     resid computes the residual:  r = v - Au
c
c     This  implementation costs  15A + 4M per result, where
c     A and M denote the costs of Addition (or Subtraction) and 
c     Multiplication, respectively. 
c     Presuming coefficient a(1) is zero (the NPB assumes this,
c     but it is thus not a general case), 3A + 1M may be eliminated,
c     resulting in 12A + 3M.
c     Note that this vectorizes, and is also fine for cache 
c     based machines.  
c-------------------------------------------------------------------*/

    int i3, i2, i1;
    int ldx = u->dims[0];
    int ldy = u->dims[1];
    int ldz = u->dims[2];
    double u1[M], u2[M];
    /* Everything excluding (artificial) ghost cells */
    for (i3 = 1; i3 < ldz-1; i3++) {
      for (i2 = 1; i2 < ldy-1; i2++) {
        for (i1 = 0; i1 < ldx; i1++) {
          u1[i1] = AREF(u,i3,(i2-1),i1) +
            AREF(u,i3,(i2+1),i1) +
            AREF(u,(i3-1),i2,i1) +
            AREF(u,(i3+1),i2,i1);
          u2[i1] = AREF(u,(i3-1),(i2-1),i1) +
            AREF(u,(i3-1),(i2+1),i1) +
            AREF(u,(i3+1),(i2-1),i1) +
            AREF(u,(i3+1),(i2+1),i1);
        }
        for (i1 = 1; i1 < ldx-1; i1++) {
                AREF(r,i3,i2,i1) = AREF(v,i3,i2,i1)
                    - a[0] * AREF(u,i3,i2,i1)
/*--------------------------------------------------------------------
c  Assume a(1) = 0      (Enable 2 lines below if a(1) not= 0)
c---------------------------------------------------------------------
c    >                     - a(1) * ( u(i1-1,i2,i3) + u(i1+1,i2,i3)
c    >                              + u1(i1) )
c-------------------------------------------------------------------*/
                - a[2] * ( u2[i1] + u1[i1-1] + u1[i1+1] )
                      - a[3] * ( u2[i1-1] + u2[i1+1] );
            }
        }
    }

/*--------------------------------------------------------------------
c     exchange boundary data
c--------------------------------------------------------------------*/
    comm3(r,k);
    if (debug_vec[0] >= 1 ) {
        rep_nrm(r,n1,n2,n3,"   resid",k);
    }

    /*
    if ( debug_vec[2] >= k ) {
        showall(r,n1,n2,n3);
    }
    */
}

int GI(upc3d *v,int index,int axis) 
{
  int sub;
  sub = v->globallb[axis] == 0 ? 0 : 1;
  return v->globallb[axis]+index-sub;
}

void rprj3( upc3d *r,  int m1k, int m2k, int m3k,
                    upc3d *s, int m1j, int m2j, int m3j, int k )
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/ 
/*--------------------------------------------------------------------
c     rprj3 projects onto the next coarser grid, 
c     using a trilinear Finite Element projection:  s = r' = P r
c     
c     This  implementation costs  20A + 4M per result, where
c     A and M denote the costs of Addition and Multiplication.  
c     Note that this vectorizes, and is also fine for cache 
c     based machines.  
c-------------------------------------------------------------------*/

    int j3, j2, j1, i3, i2, i1, d1, d2, d3;

    FILE *fp;
    double x1[M], y1[M], x2, y2;

    int ldx = s->dims[0];
    int ldy = s->dims[1];
    int ldz = s->dims[2];
    if(!r->live) goto END;
    if ((r->globallb[0] > 0) && (r->globallb[0] % 2 == 0)) {
      d1 = 2;
    } else {
      d1 = 1;
    }

    if ((r->globallb[1] > 0) && (r->globallb[1] % 2 == 0)) {
      d2 = 2;
    } else {
      d2 = 1;
    }

    if ((r->globallb[2] > 0) && (r->globallb[2] % 2 == 0)) {
      d3 = 2;
    } else {
      d3 = 1;
    }
    for (j3 = 1; j3 < ldz-1; j3++) {
      i3 = 2*j3-d3;
      for (j2 = 1; j2 < ldy-1; j2++) {
        i2 = 2*j2-d2;
        for (j1 = 1; j1 < ldx; j1++) {
          i1 = 2*j1-d1;
          x1[i1] = AREF(r,i3+1,i2,i1) + AREF(r,i3+1,i2+2,i1)
            + AREF(r,i3,i2+1,i1) + AREF(r,i3+2,i2+1,i1);
          y1[i1] = AREF(r,i3,i2,i1) + AREF(r,i3+2,i2,i1)
            + AREF(r,i3,i2+2,i1) + AREF(r,i3+2,i2+2,i1);
        }
        
        for (j1 = 1; j1 < ldx-1; j1++) {
          i1 = 2*j1-d1;
          y2 = AREF(r,i3,i2,i1+1) + AREF(r,i3+2,i2,i1+1)
            + AREF(r,i3,i2+2,i1+1) + AREF(r,i3+2,i2+2,i1+1);
          x2 = AREF(r,i3+1,i2,i1+1) + AREF(r,i3+1,i2+2,i1+1)
            + AREF(r,i3,i2+1,i1+1) + AREF(r,i3+2,i2+1,i1+1);
          AREF(s,j3,j2,j1) =
            0.5 * AREF(r,i3+1,i2+1,i1+1)
            + 0.25 * ( AREF(r,i3+1,i2+1,i1) 
                       + AREF(r,i3+1,i2+1,i1+2) + x2)
            + 0.125 * ( x1[i1] + x1[i1+2] + y2)
            + 0.0625 * ( y1[i1] + y1[i1+2] );
        }
      }
    }
END:
    comm3(s,k-1);
    if (debug_vec[0] >= 1 ) {
        rep_nrm(s,m1j,m2j,m3j,"   rprj3",k-1);
    }
    /*
    if (debug_vec[4] >= k ) {
        showall(s,m1j,m2j,m3j);
    }
    */
}

void interp( upc3d *z, int mm1, int mm2, int mm3,
                    upc3d *u, int n1, int n2, int n3, int k )
{
  /*--------------------------------------------------------------------
    c-------------------------------------------------------------------*/
  
  /*--------------------------------------------------------------------
    c     interp adds the trilinear interpolation of the correction
c     from the coarser grid to the current approximation:  u = u + Qu'
c     
c     Observe that this  implementation costs  16A + 4M, where
c     A and M denote the costs of Addition and Multiplication.  
c     Note that this vectorizes, and is also fine for cache 
c     based machines.  Vector machines may get slightly better 
c     performance however, with 8 separate "do i1" loops, rather than 4.
c-------------------------------------------------------------------*/

    int i3, i2, i1, d1, d2, d3, t1, t2, t3;

/*
c note that m = 1037 in globals.h but for this only need to be
c 535 to handle up to 1024^3
c      integer m
c      parameter( m=535 )
*/
    double z1[M], z2[M], z3[M];
    int lbx = z->globallb[0] == 0 ? 0 : 1; 
    int ubx = z->globalub[0] == n1 ? z->dims[0] : z->dims[0]-1;
    int ldx = z->dims[0];
    int ldy = z->dims[1];
    int ldz = z->dims[2];

    /* Gasp.  A goto! */
    if(u->live && !z->live) goto COMM;
    if(!u->live) goto COMM;

    if ((u->globallb[0] > 0) && (u->globallb[0] % 2 == 0)) {
      d1 = 1;
    } else {
      d1 = 0;
    }

    if ((u->globallb[1] > 0) && (u->globallb[1] % 2 == 0)) {
      d2 = 1;
    } else {
      d2 = 0;
    }

    if ((u->globallb[2] > 0) && (u->globallb[2] % 2 == 0)) {
      d3 = 1;
    } else {
      d3 = 0;
    }

    if ( n1 != 3 && n2 != 3 && n3 != 3 ) {
        for (i3 = 1; i3 < ldz-1; i3++) {
          for (i2 = 1; i2 < ldy-1; i2++) {
            for (i1 = 0; i1 < ldx; i1++) {
              z1[i1] = AREF(z,i3,i2+1,i1) + AREF(z,i3,i2,i1);
              z2[i1] = AREF(z,i3+1,i2,i1) + AREF(z,i3,i2,i1);
              z3[i1] = AREF(z,i3+1,i2+1,i1) + AREF(z,i3+1,i2,i1) + z1[i1];
            }
            for (i1 = 1; i1 < ldx-1; i1++) {
              AREF(u,2*i3-d3,2*i2-d2,2*i1-d1) = AREF(u,2*i3-d3,2*i2-d2,2*i1-d1)
                +AREF(z,i3,i2,i1);
              AREF(u,2*i3-d3,2*i2-d2,2*i1+1-d1) = AREF(u,2*i3-d3,2*i2-d2,
                                                       2*i1+1-d1)
                +0.5*(AREF(z,i3,i2,i1+1)+AREF(z,i3,i2,i1));
            }
            for (i1 = 1; i1 < ldx-1; i1++) {
              AREF(u,2*i3-d3,2*i2+1-d2,2*i1-d1) = AREF(u,2*i3-d3,2*i2+1-d2,
                                                       2*i1-d1)
                +0.5 * z1[i1];
              AREF(u,2*i3-d3,2*i2+1-d2,2*i1+1-d1) = AREF(u,2*i3-d3,2*i2+1-d2,
                                                         2*i1+1-d1)
                +0.25*( z1[i1] + z1[i1+1] );
            }
            for (i1 = 1; i1 < ldx-1; i1++) {
              AREF(u,2*i3+1-d3,2*i2-d2,2*i1-d1) = AREF(u,2*i3+1-d3,2*i2-d2,
                                                       2*i1-d1)
                +0.5 * z2[i1];
              AREF(u,2*i3+1-d3,2*i2-d2,2*i1+1-d1) = AREF(u,2*i3+1-d3,2*i2-d2,
                                                         2*i1+1-d1)
                +0.25*( z2[i1] + z2[i1+1] );
            }
            for (i1 = 1; i1 < ldx-1; i1++) {
              AREF(u,2*i3+1-d3,2*i2+1-d2,2*i1-d1) = AREF(u,2*i3+1-d3,2*i2+1-d2
                                                         ,2*i1-d1)
                +0.25* z3[i1];
              AREF(u,2*i3+1-d3,2*i2+1-d2,2*i1+1-d1) = 
                AREF(u,2*i3+1-d3,2*i2+1-d2,2*i1+1-d1)
                +0.125*( z3[i1] + z3[i1+1] );
            }
          }
        }
    } else {
      upc_global_exit(1);
    }
 COMM:
    comm3_interp(z,u,k);
    if (debug_vec[0] >= 1 ) {
      rep_nrm(z,mm1,mm2,mm3,"z: inter",k-1);
      rep_nrm(u,n1,n2,n3,"u: inter",k);
    }
    /*
    if ( debug_vec[5] >= k ) {
      showall(z,mm1,mm2,mm3);
      showall(u,n1,n2,n3);
    }
    */
}

void mg3P(upc3d **u, upc3d *v, upc3d**r, 
                 double a[4],
                 double c[4], int n1, int n2, int n3, int k) {

/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

/*--------------------------------------------------------------------
c     multigrid V-cycle routine
c-------------------------------------------------------------------*/

    int j;

/*--------------------------------------------------------------------
c     down cycle.
c     restrict the residual from the fine grid to the coarse
c-------------------------------------------------------------------*/

    for (k = lt; k >= lb+1; k--) {
        j = k-1;
        rprj3(r[k], m1[k], m2[k], m3[k],
          r[j], m1[j], m2[j], m3[j], k);
    }
    k = lb;
/*--------------------------------------------------------------------
c     compute an approximate solution on the coarsest grid
c-------------------------------------------------------------------*/
    zero(u[k]);
    psinv(r[k], u[k], m1[k], m2[k], m3[k], c, k);

    for (k = lb+1; k <= lt-1; k++) {
        j = k-1;
/*--------------------------------------------------------------------
c        prolongate from level k-1  to k
c-------------------------------------------------------------------*/
        zero(u[k]);
        interp(u[j], m1[j], m2[j], m3[j], 
                u[k], m1[k], m2[k], m3[k], k);
/*--------------------------------------------------------------------
c        compute residual for level k
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c        apply smoother
c-------------------------------------------------------------------*/
        resid(u[k], r[k], r[k], a, m1[k], m2[k], m3[k],k);
        psinv(r[k], u[k], 
               m1[k], m2[k], m3[k], c, k);
    }
    j = lt - 1;
    k = lt;
    interp(u[j], m1[j], m2[j], m3[j], u[lt], 
            n1, n2, n3, k);
    resid(u[lt], v, r[lt], a,
           n1, n2, n3, k);

    psinv(r[lt], u[lt], 
           n1, n2, n3, c, k);
}

static void setup(int *n1, int *n2, int *n3, int lt) {

/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

    int k;

    for ( k = lt-1; k >= 1; k--) {
        nx[k] = nx[k+1]/2;
        ny[k] = ny[k+1]/2;
        nz[k] = nz[k+1]/2;
    }

    for (k = 1; k <= lt; k++) {
        m1[k] = nx[k]+2;
        m2[k] = nz[k]+2;
        m3[k] = ny[k]+2;
    }

    is1 = 1;
    ie1 = nx[lt];
    *n1 = nx[lt]+2;
    is2 = 1;
    ie2 = ny[lt];
    *n2 = ny[lt]+2;
    is3 = 1;
    ie3 = nz[lt];
    *n3 = nz[lt]+2;

    if (debug_vec[1] >=  1 ) {
        printf(" in setup, \n");
        printf("  lt  nx  ny  nz  n1  n2  n3 is1 is2 is3 ie1 ie2 ie3\n");
        printf("%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n",
               lt,nx[lt],ny[lt],nz[lt],*n1,*n2,*n3,is1,is2,is3,ie1,ie2,ie3);
    }
}

void setup_processor_grid(int levels)
{
  int idx,idy,idz;

  double done = 1.0; 
  double dtwo = 2.0;
  double logp;
  double logpx,logpy;
  int i,j;

  pd = calloc(levels+1,sizeof(int *));
  id = calloc(levels+1,sizeof(int *));
  for(i=1;i <= levels;i++) {
    pd[i]=calloc(3,sizeof(int));
    id[i]=calloc(3,sizeof(int));
    for(j=0;j < 3;j++) {
      pd[i][j] = -1;
      id[i][j] = -1;
    }
  }
  /* Setup the processor grid */
  logp=(log(THREADS*1.0)+0.0001)/log(dtwo);
  logpx = logp/3;
  pd[levels][0] = pow(dtwo,logpx);
  logpy = (logp - logpx)/2;
  pd[levels][1] = pow(dtwo,logpy);
  printf("logp: %f logpx: %f d[levels][0]=%d pd[levels][1]=%d\n",
            logp,logpx, 
            pd[levels][0],
                                               pd[levels][1]);
  pd[levels][2] = THREADS/(pd[levels][0]*pd[levels][1]);
  if(THREADS == 32) {
    pd[levels][0] = 2;
    pd[levels][1] = 4;
    pd[levels][2] = 4;
  }
  if(THREADS == 128) {
    pd[levels][0] = 4;
    pd[levels][1] = 4;
    pd[levels][2] = 8;
  }
  id[levels][0]= (MYTHREAD % (pd[levels][0]*pd[levels][1])) % pd[levels][0];
  id[levels][1] = (MYTHREAD % (pd[levels][0]*pd[levels][1])) / pd[levels][0];
  id[levels][2] = MYTHREAD/(pd[levels][0]*pd[levels][1]);
}


/* I just copied the places where the top level grid is +/- 1 */
void zran3(upc3d *v,int k)
{
  int n1[10][3];
  int p1[10][3];
  int m,i;

  if(Class=='S') {
    n1[0][0]= 9; n1[0][1]=16; n1[0][2]=28;
    n1[1][0]=10; n1[1][1]=27; n1[1][2]=24;
    n1[2][0]=28; n1[2][1]=17; n1[2][2]=33;
    n1[3][0]=22; n1[3][1]=21; n1[3][2]=13;
    n1[4][0]= 7; n1[4][1]=19; n1[4][2]=10;
    n1[5][0]=14; n1[5][1]= 4; n1[5][2]= 3;
    n1[6][0]= 6; n1[6][1]=30; n1[6][2]=17;
    n1[7][0]= 7; n1[7][1]=16; n1[7][2]= 2;
    n1[8][0]=15; n1[8][1]=10; n1[8][2]=19;
    n1[9][0]= 2; n1[9][1]=13; n1[9][2]= 4;
    
    p1[0][0]=19; p1[0][1]=28; p1[0][2]=19;
    p1[1][0]=30; p1[1][1]= 2; p1[1][2]=30;
    p1[2][0]=32; p1[2][1]= 6; p1[2][2]=27;
    p1[3][0]=14; p1[3][1]=17; p1[3][2]=14;
    p1[4][0]=23; p1[4][1]=33; p1[4][2]= 8;
    p1[5][0]= 3; p1[5][1]=18; p1[5][2]=23;
    p1[6][0]= 6; p1[6][1]=24; p1[6][2]= 5;
    p1[7][0]= 4; p1[7][1]= 2; p1[7][2]= 5;
    p1[8][0]=21; p1[8][1]=31; p1[8][2]=33;
    p1[9][0]= 9; p1[9][1]= 3; p1[9][2]=22;
  } else if (Class == 'A') {
    n1[0][0]=211; n1[0][1]=154; n1[0][2]= 98;
    n1[1][0]=102; n1[1][1]=138; n1[1][2]=112;
    n1[2][0]=101; n1[2][1]=156; n1[2][2]= 59;
    n1[3][0]= 17; n1[3][1]=205; n1[3][2]= 32;
    n1[4][0]= 92; n1[4][1]= 63; n1[4][2]=205;
    n1[5][0]=199; n1[5][1]=  7; n1[5][2]=203;
    n1[6][0]=250; n1[6][1]=170; n1[6][2]=157;
    n1[7][0]= 82; n1[7][1]=184; n1[7][2]=255;
    n1[8][0]=154; n1[8][1]=162; n1[8][2]= 36;
    n1[9][0]=223; n1[9][1]= 42; n1[9][2]=240;
 
    p1[0][0]= 57; p1[0][1]=120; p1[0][2]=167;
    p1[1][0]=  5; p1[1][1]=118; p1[1][2]=175;
    p1[2][0]=176; p1[2][1]=246; p1[2][2]=164;
    p1[3][0]= 45; p1[3][1]=194; p1[3][2]=234;
    p1[4][0]=212; p1[4][1]=  7; p1[4][2]=248;
    p1[5][0]=115; p1[5][1]=123; p1[5][2]=207;
    p1[6][0]=202; p1[6][1]= 83; p1[6][2]=209;
    p1[7][0]=203; p1[7][1]= 18; p1[7][2]=198;
    p1[8][0]=243; p1[8][1]=172; p1[8][2]= 14;
    p1[9][0]= 54; p1[9][1]=209; p1[9][2]= 40;
  } else if (Class == 'B') {
    n1[0][0]=211; n1[0][1]=154; n1[0][2]= 98;
    n1[1][0]=102; n1[1][1]=138; n1[1][2]=112;
    n1[2][0]=101; n1[2][1]=156; n1[2][2]= 59;
    n1[3][0]= 17; n1[3][1]=205; n1[3][2]= 32;
    n1[4][0]= 92; n1[4][1]= 63; n1[4][2]=205;
    n1[5][0]=199; n1[5][1]=  7; n1[5][2]=203;
    n1[6][0]=250; n1[6][1]=170; n1[6][2]=157;
    n1[7][0]= 82; n1[7][1]=184; n1[7][2]=255;
    n1[8][0]=154; n1[8][1]=162; n1[8][2]= 36;
    n1[9][0]=223; n1[9][1]= 42; n1[9][2]=240;
 
    p1[0][0]= 57; p1[0][1]=120; p1[0][2]=167;
    p1[1][0]=  5; p1[1][1]=118; p1[1][2]=175;
    p1[2][0]=176; p1[2][1]=246; p1[2][2]=164;
    p1[3][0]= 45; p1[3][1]=194; p1[3][2]=234;
    p1[4][0]=212; p1[4][1]=  7; p1[4][2]=248;
    p1[5][0]=115; p1[5][1]=123; p1[5][2]=207;
    p1[6][0]=202; p1[6][1]= 83; p1[6][2]=209;
    p1[7][0]=203; p1[7][1]= 18; p1[7][2]=198;
    p1[8][0]=243; p1[8][1]=172; p1[8][2]= 14;
    p1[9][0]= 54; p1[9][1]=209; p1[9][2]= 40;
  } else if (Class == 'C') {
    n1[0][0]=74;  n1[0][1]=  2; n1[0][2]=107;
    n1[1][0]=402; n1[1][1]=504; n1[1][2]=447;
    n1[2][0]=154; n1[2][1]=338; n1[2][2]= 10;
    n1[3][0]= 18; n1[3][1]= 21; n1[3][2]=457;
    n1[4][0]=352; n1[4][1]=194; n1[4][2]=418;
    n1[5][0]=383; n1[5][1]= 74; n1[5][2]=283;
    n1[6][0]=344; n1[6][1]=139; n1[6][2]=168;
    n1[7][0]=233; n1[7][1]=278; n1[7][2]= 61;
    n1[8][0]= 96; n1[8][1]=401; n1[8][2]=238;
    n1[9][0]=399; n1[9][1]=312; n1[9][2]=200;
 
    p1[0][0]=151; p1[0][1]=401; p1[0][2]=331;
    p1[1][0]=203; p1[1][1]= 10; p1[1][2]= 51;
    p1[2][0]=146; p1[2][1]= 93; p1[2][2]=312;
    p1[3][0]=163; p1[3][1]=280; p1[3][2]= 75;
    p1[4][0]=509; p1[4][1]= 43; p1[4][2]=127;
    p1[5][0]=243; p1[5][1]= 87; p1[5][2]=  5;
    p1[6][0]=149; p1[6][1]=117; p1[6][2]=199;
    p1[7][0]=451; p1[7][1]=270; p1[7][2]=443;
    p1[8][0]= 11; p1[8][1]=493; p1[8][2]=118;
    p1[9][0]=310; p1[9][1]=361; p1[9][2]= 11;
  } else if (Class == 'D') {
    n1[0][0]= 87; n1[0][1]=329; n1[0][2]=234;
    n1[1][0]=223; n1[1][1]=908; n1[1][2]= 16;
    n1[2][0]=846; n1[2][1]=263; n1[2][2]=254;
    n1[3][0]=894; n1[3][1]= 72; n1[3][2]=363;
    n1[4][0]=608; n1[4][1]=201; n1[4][2]= 61;
    n1[5][0]=399; n1[5][1]=669; n1[5][2]= 51;
    n1[6][0]=308; n1[6][1]= 77; n1[6][2]=626;
    n1[7][0]=480; n1[7][1]=876; n1[7][2]=806;
    n1[8][0]=775; n1[8][1]=347; n1[8][2]=476;
    n1[9][0]=188; n1[9][1]=376; n1[9][2]=696;
 
    p1[0][0]= 80; p1[0][1]=278; p1[0][2]=252;
    p1[1][0]=273; p1[1][1]= 77; p1[1][2]=817;
    p1[2][0]=260; p1[2][1]=732; p1[2][2]=484;
    p1[3][0]=779; p1[3][1]=455; p1[3][2]=708;
    p1[4][0]=958; p1[4][1]=219; p1[4][2]=954;
    p1[5][0]=624; p1[5][1]=883; p1[5][2]=182;
    p1[6][0]=984; p1[6][1]=946; p1[6][2]=698;
    p1[7][0]=337; p1[7][1]=297; p1[7][2]=602;
    p1[8][0]=744; p1[8][1]=643; p1[8][2]=149;
    p1[9][0]=741; p1[9][1]=881; p1[9][2]=783;
  } else {
    printf("Only Classes S,A,B,C,D supported for now!\n");
  }

  /* Convert to 0 based indices */
  for(m=0;m < 10;m++) {
    for(i=0;i < 3;i++) {
      n1[m][i]--;
      p1[m][i]--;
    }
  }

  /* Do the setting */
  for(m=0;m < 10;m++) {
    gset(v,n1[m][0],n1[m][1],n1[m][2],-1.0);
    gset(v,p1[m][0],p1[m][1],p1[m][2],1.0);
  } 
  upc_barrier;
  comm3(v,k);
}

void setup_fns()
{
    putfn[0]=putyz;getfn[0]=getyz;
    putfn[1]=putxz;getfn[1]=getxz;
    putfn[2]=putxy;getfn[2]=getxy;
}

int main(int argc, char *argv[]) 
{
/*-------------------------------------------------------------------------
c k is the current level. It is passed down through subroutine args
c and is NOT global. it is the current iteration
c------------------------------------------------------------------------*/

    int k, it;
    double t, tinit, mflops;
    int nthreads = THREADS;

/*-------------------------------------------------------------------------
c These arrays are in common because they are quite large
c and probably shouldn't be allocated on the stack. They
c are always passed as subroutine args. 
c------------------------------------------------------------------------*/
    
    upc3d **u;
    upc3d *v;
    upc3d **r;
    double a[4], c[4];

    double rnm2, rnmu;
    double epsilon = 1.0e-8;
    int n1, n2, n3, nit;
    double verify_value;
    boolean verified;

    int i, j, l;
    FILE *fp;
    setup_fns();
    timer_clear(T_BENCH);
    timer_clear(T_INIT);

    timer_start(T_INIT);

/*----------------------------------------------------------------------
c Read in and broadcast input data
c---------------------------------------------------------------------*/

    if(MYTHREAD == 0) {
    printf("\n\n NAS Parallel Benchmarks 2.3 UPC version"
           " - MG Benchmark\n\n");
    }

    fp = fopen("mg.input", "r");
    if (fp != NULL) {
      if(MYTHREAD == 0) {
        printf(" Reading from input file mg.input\n");
      }
        fscanf(fp, "%d", &lt);
        while(fgetc(fp) != '\n');
        fscanf(fp, "%d%d%d", &nx[lt], &ny[lt], &nz[lt]);
        while(fgetc(fp) != '\n');
        fscanf(fp, "%d", &nit);
        while(fgetc(fp) != '\n');
        for (i = 0; i <= 7; i++) {
            fscanf(fp, "%d", &debug_vec[i]);
        }
        fclose(fp);
    } else {
      if(MYTHREAD == 0) {
        printf(" No input file. Using compiled defaults\n");
      }
    
        lt = LT_DEFAULT;
        nit = NIT_DEFAULT;
        nx[lt] = NX_DEFAULT;
        ny[lt] = NY_DEFAULT;
        nz[lt] = NZ_DEFAULT;

        for (i = 0; i <= 7; i++) {
            debug_vec[i] = DEBUG_DEFAULT;
        }
    }

    if ( (nx[lt] != ny[lt]) || (nx[lt] != nz[lt]) ) {
        Class = 'U';
    } else if( nx[lt] == 32 && nit == 4 ) {
        Class = 'S';
    } else if( nx[lt] == 64 && nit == 40 ) {
        Class = 'W';
    } else if( nx[lt] == 256 && nit == 20 ) {
        Class = 'B';
    } else if( nx[lt] == 512 && nit == 20 ) {
        Class = 'C';
    } else if( nx[lt] == 1024 && nit == 50 ) {
        Class = 'D';
    } else if( nx[lt] == 256 && nit == 4 ) {
        Class = 'A';
    } else {
        Class = 'U';
    }

/*--------------------------------------------------------------------
c  Use these for debug info:
c---------------------------------------------------------------------
c     debug_vec(0) = 1 !=> report all norms
c     debug_vec(1) = 1 !=> some setup information
c     debug_vec(1) = 2 !=> more setup information
c     debug_vec(2) = k => at level k or below, show result of resid
c     debug_vec(3) = k => at level k or below, show result of psinv
c     debug_vec(4) = k => at level k or below, show result of rprj
c     debug_vec(5) = k => at level k or below, show result of interp
c     debug_vec(6) = 1 => (unused)
c     debug_vec(7) = 1 => (unused)
c-------------------------------------------------------------------*/
    /*debug_vec[0]=1;*/
    a[0] = -8.0/3.0;
    a[1] =  0.0;
    a[2] =  1.0/6.0;
    a[3] =  1.0/12.0;

    if (Class == 'A' || Class == 'S' || Class =='W') {
/*--------------------------------------------------------------------
c     Coefficients for the S(a) smoother
c-------------------------------------------------------------------*/
        c[0] =  -3.0/8.0;
        c[1] =  1.0/32.0;
        c[2] =  -1.0/64.0;
        c[3] =   0.0;
    } else {
/*--------------------------------------------------------------------
c     Coefficients for the S(b) smoother
c-------------------------------------------------------------------*/
        c[0] =  -3.0/17.0;
        c[1] =  1.0/33.0;
        c[2] =  -1.0/61.0;
        c[3] =   0.0;
    }
    
    lb = 1;

    GMAXLEVEL=lt;
    setup_processor_grid(lt);
    setup(&n1,&n2,&n3,lt);
    if(MYTHREAD == 0) {
      for(i=1;i <= lt;i++) {
        printf("Level %d is %3d x %3d x %3d\n",i,m1[i],m2[i],m3[i]);
      }
    }

    /* create_* automatically zeros out the grids */
   /*  printf("%d BEFORE grid h1\n", MYTHREAD); */
    u=create_grid_hierarchy(lt,m1,m2,m3);
   /*  printf("%d BEFORE upc3d h1\n", MYTHREAD); */
    v=create_upc3d(m1[lt],m2[lt],m3[lt],lt);
   /*  printf("%d BEFORE grid h2\n", MYTHREAD); */
    r=create_grid_hierarchy(lt,m1,m2,m3);
    zran3(v,lt);
    norm2u3(v,n1,n2,n3,&rnm2,&rnmu,nx[lt],ny[lt],nz[lt],lt);

    if (MYTHREAD == 0) {
      printf("\n norms of random v are\n");
      printf(" %4d%19.12e%19.12e\n", 0, rnm2, rnmu);
    }

    k=lt;
    resid(u[lt],v,r[lt],a,n1,n2,n3,k);
    norm2u3(r[lt],n1,n2,n3,&rnm2,&rnmu,nx[lt],ny[lt],nz[lt],lt);
    if(MYTHREAD == 0) {
      printf(" norms =%21.14e%21.14e\n", rnm2, rnmu);
    }
    /*c---------------------------------------------------------------------
      c     One iteration for startup
      c---------------------------------------------------------------------*/

    upc_barrier;
    if(MYTHREAD == 0) {
      printf("Calling mg3P for first time\n");
    }
    mg3P(u,v,r,a,c,n1,n2,n3,lt);
    upc_barrier;
    if(MYTHREAD == 0) {
      printf("Done with mg3P for first time\n");
    }
    resid(u[lt],v,r[lt],a,n1,n2,n3,lt);
    setup(&n1,&n2,&n3,lt);

    zero(u[lt]);
    zran3(v,lt);

    timer_stop(T_INIT);
    for(i=lt;i >= 1;i--) {
    timer_clear(T_COMM+i);
    }
    timer_clear(T_COMM+lt+1);
    timer_start(T_BENCH);
  {
    resid(u[lt],v,r[lt],a,n1,n2,n3,lt);
    norm2u3(r[lt],n1,n2,n3,&rnm2,&rnmu,nx[lt],ny[lt],nz[lt],lt);

    for ( it = 1; it <= nit; it++) {
        mg3P(u,v,r,a,c,n1,n2,n3,lt);
        resid(u[lt],v,r[lt],a,
               n1,n2,n3,lt);
    }
    norm2u3(r[lt],n1,n2,n3,&rnm2,&rnmu,nx[lt],ny[lt],nz[lt],lt);
  } 

    timer_stop(T_BENCH);
    t = timer_read(T_BENCH);
    tinit = timer_read(T_INIT);
    
    if(MYTHREAD == 0) {
      verified = FALSE;
      verify_value = 0.0;
      
      printf(" Initialization time: %15.3f seconds\n", tinit);
      for(i=lt;i >= 1;i--) {
        printf(" Comm time %d: %15.3f seconds\n", i,timer_read(T_COMM+i));
      }
      printf(" psinv: %15.3f seconds\n", timer_read(T_COMM+lt+1));
      printf(" Benchmark completed\n");
      
      if (Class != 'U') {
        if (Class == 'S') {
          verify_value = 0.530770700573e-04;
        } else if (Class == 'W') {
          verify_value = 0.250391406439e-17;  /* 40 iterations*/
          /*                            0.183103168997d-044 iterations*/
        } else if (Class == 'A') {
          verify_value = 0.243336530907e-5;
        } else if (Class == 'B') {
          verify_value = 0.180056440136e-5;
        } else if (Class == 'C') {
          verify_value =  0.570673228574e-06;
        } else if (Class == 'D') {
          verify_value = 0.158327506043e-09;
        }
        
        if ( fabs( rnm2 - verify_value ) <= epsilon ) {
          verified = TRUE;
          printf(" VERIFICATION SUCCESSFUL\n");
          printf(" L2 Norm is %20.12e\n", rnm2);
          printf(" Error is   %20.12e\n", rnm2 - verify_value);
        } else {
          verified = FALSE;
          printf(" VERIFICATION FAILED\n");
          printf(" L2 Norm is             %20.12e\n", rnm2);
          printf(" The correct L2 Norm is %20.12e\n", verify_value);
        }
      } else {
        verified = FALSE;
        printf(" Problem size unknown\n");
        printf(" NO VERIFICATION PERFORMED\n");
      }
      
      if ( t != 0.0 ) {
        int nn = nx[lt]*ny[lt]*nz[lt];
        mflops = 58.*nit*nn*1.0e-6 / t;
      } else {
        mflops = 0.0;
      }
      
      c_print_results("MG", Class, nx[lt], ny[lt], nz[lt], 
                      nit, nthreads, t, mflops, "          floating point", 
                      verified, NPBVERSION, COMPILETIME,
                      CS1, CS2, CS3, CS4, CS5, CS6, CS7);
    }
    return(0);
}

