/* sobel-opt-all.c
 *
 * Sobel function with remote data prefetching into local memory.
 * (should be included in sobel.c)
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upc-tests/benchmarks/gwu_bench/sobel/sobel-opt-all.c $
 */

#ifdef STATIC_ALLOC
BYTET localrow[IMGSIZE];
#else
BYTET* localrow=NULL;
#endif

#define STRUCTSIZE 6
typedef struct { BYTET a[STRUCTSIZE]; } cpstruct;

/* Bytes left after last STUCTSIZE chunk has been copied */
#define REMAINDER (IMGSIZE%STRUCTSIZE)

int Sobel(void)
{
  int i,j,d1,d2;
  double magnitude;
 
  BYTET* p_orig0;
  BYTET* p_orig1;
  BYTET* p_orig2;
  BYTET* p_edge;

#ifndef STATIC_ALLOC
	if(!localrow)
		localrow = (BYTET*)malloc(sizeof(BYTET)*IMGSIZE);
#endif


  upc_forall(i=1; i<(IMGSIZE-1); i++; &edge[i])
	{
    debug(p_edge=(BYTET*)edge[i].r);
    p_orig1=(BYTET*)orig[i].r;

    if (FIRST_ROW(i))
    { shared void *tmp = orig[PREV_ROW(i)].r;
      shared cpstruct *pss = tmp;
      cpstruct *psp = (void*)localrow;

      for(j=0; j<=(IMGSIZE-STRUCTSIZE); j+=STRUCTSIZE) *(psp++) = *(pss++);
      if (REMAINDER) upc_memget(psp, pss, REMAINDER);

      p_orig0=localrow;
    }
    else
      p_orig0=(BYTET*)orig[PREV_ROW(i)].r;

    if (LAST_ROW(i))
    { shared void *tmp = orig[NEXT_ROW(i)].r;
      shared cpstruct *pss = tmp;
      cpstruct *psp = (void*)localrow;

      for(j=0; j<=(IMGSIZE-STRUCTSIZE); j+=STRUCTSIZE) *(psp++) = *(pss++);
      if (REMAINDER) upc_memget(psp, pss, REMAINDER);

      p_orig2=localrow;
    }
    else
      p_orig2=(BYTET*)orig[NEXT_ROW(i)].r;

    for (j=1; j<IMGSIZE-1; j++) {   
      d1=(int)   p_orig0[NEXT_ROW(j)]-p_orig0[PREV_ROW(j)];
      d1+=((int) p_orig1[NEXT_ROW(j)]-p_orig1[PREV_ROW(j)])<<1;
      d1+=(int)  p_orig2[NEXT_ROW(j)]-p_orig2[PREV_ROW(j)];

      d2=(int)   p_orig0[PREV_ROW(j)]-p_orig2[PREV_ROW(j)];
      d2+=((int) p_orig0[j]  -p_orig2[j]  )<<1;
      d2+=(int)  p_orig0[NEXT_ROW(j)]-p_orig2[NEXT_ROW(j)];

      magnitude=sqrt((double)(d1*d1+d2*d2));
      p_edge[j]=magnitude>255? 255:(unsigned char)magnitude;
    }
  }
  return 0;
}

/* vi:ts=2:ai
 */
