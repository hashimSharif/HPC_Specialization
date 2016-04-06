/* sobel-opt-prefetch.c
 *
 * Sobel function with remote data prefetching in local-shared memory (that's
 * why `localrow' is declared as a pointer to shared data).
 * (should be included in sobel.c)
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upc-tests/benchmarks/gwu_bench/sobel/sobel-opt-prefetch.c $
 */

#define STRUCTSIZE 6
typedef struct { BYTET a[STRUCTSIZE]; } cpstruct;

/* Bytes left after last STUCTSIZE chunk has been copied */
#define REMAINDER (IMGSIZE%STRUCTSIZE)

#ifdef STATIC_ALLOC
shared[IMGSIZE] BYTET localrow[THREADS][IMGSIZE];
#else
shared[] BYTET* shared localrow[THREADS];	/* zero init (ANSI C) */
#endif
 
int Sobel(void)
{
  int i,j,d1,d2;
  double magnitude;
 
  shared BYTET* p_orig0;
  shared BYTET* p_orig1;
  shared BYTET* p_orig2;
  shared BYTET* p_edge;

#ifndef STATIC_ALLOC
	if(localrow[MYTHREAD]==NULL)
# ifdef __UPC_VERSION__ // UPC version 1.1 or higher
		localrow[MYTHREAD] = (shared[] BYTET*)upc_alloc(IMGSIZE * sizeof(BYTET));
# else
		localrow[MYTHREAD] = (shared[] BYTET*)upc_local_alloc(IMGSIZE, sizeof(BYTET));
# endif
#endif

  upc_forall(i=1; i<IMGSIZE-1; i++; &edge[i])
  {
    p_edge=(shared BYTET*)edge[i].r;
    p_orig1=(shared BYTET*)orig[i].r;

		/* At the beginning of a block, prefetch the previous line (which has
		 * affinity with MYTHREAD-1) into local-shared memory by copying structures.
		 */
    if (FIRST_ROW(i))
    { shared [] cpstruct *pss = (shared void*) orig[PREV_ROW(i)].r;
      shared [] cpstruct *psp = (shared void*)localrow[MYTHREAD];

      for(j=0; j<=(IMGSIZE-STRUCTSIZE); j+=STRUCTSIZE) *(psp++) = *(pss++);
      if (REMAINDER) upc_memcpy(psp, pss, REMAINDER);

      p_orig0=(shared BYTET*)localrow[MYTHREAD];
    }
    else
      p_orig0=(shared BYTET*)orig[PREV_ROW(i)].r;

		/* At the end of a block, prefetch the next line (which has
		 * affinity with MYTHREAD+1) into local-shared memory.
		 */
    if (LAST_ROW(i))
    { shared [] cpstruct *pss = (shared void*) orig[NEXT_ROW(i)].r;
      shared [] cpstruct *psp = (shared void*)localrow[MYTHREAD];

      for(j=0; j<=(IMGSIZE-STRUCTSIZE); j+=STRUCTSIZE) *(psp++) = *(pss++);
      if (REMAINDER) upc_memcpy(psp, pss, REMAINDER);

      p_orig2=(shared BYTET*)localrow[MYTHREAD];
    }
    else
      p_orig2=(shared BYTET*)orig[NEXT_ROW(i)].r;

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
