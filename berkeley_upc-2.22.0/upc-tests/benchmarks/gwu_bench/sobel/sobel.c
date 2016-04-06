/*
 * Sobel Edge Detection demonstration
 * Copyright (C) 2000-2001
 *     Ludovic Courtès, Chen Cjianxun, Tarek El-Ghazawi
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upc-tests/benchmarks/gwu_bench/sobel/sobel.c $
 */

#include <stdio.h>
#include <upc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#ifdef DEBUG_H
# include DEBUG_H
#else
//# error "CONFIGDIR undefined."
#define debug_init()
#define debug_step ((void)0)
#define debug(x) x
#endif

/* The UPC compiler for the SGI Origin based upon GCC 2.95.2 does not support
 * blocking factors. Therefore, arrays have to be declared with a blocking
 * factor equal to one (hence the need for index computation macros). The
 * BLOCK_BUG flag has to be set when using this compiler.
 * 
 * The DYNAMIC flag should be defined at compilation time to use the dynamic
 * array allocation. In this case, the image size (IMGSIZE) doesn't need to be
 * defined at compilation time. Otherwise, IMGSIZE should always be a power
 * of 2.
 */
#if (!defined DYNAMIC) && (!defined IMGSIZE)
# error "You must define IMGSIZE to set the number of bytes per row (must be a power of 2)."
#endif

/* ITERATION_NUM: number of iterations of the Sobel Edge Detections. Running
 * the algorithm several times allows to get a more accurate execution time.
 */
#define ITERATION_NUM 15.0


#define BYTET unsigned char

/* struct RowOfBytes is a way to avoid compilation errors with compilers
 * not supporting too high blocking factors.
 */
#define BLOCK (IMGSIZE/THREADS)	/* Block size */

typedef struct {
#ifndef DYNAMIC
  BYTET r[IMGSIZE];
#else
  shared[] BYTET *r;
#endif 
} RowOfBytes;

#if (!defined BLOCK_BUG) && (!defined DYNAMIC)

shared[IMGSIZE/THREADS] RowOfBytes orig[IMGSIZE], edge[IMGSIZE];

/* Next and previous rows index */
#define NEXT_ROW(i) ((i)+1)
#define PREV_ROW(i) ((i)-1)

#define FIRST_ROW(i) (!((i)%BLOCK))
#define LAST_ROW(i)  (FIRST_ROW((i)+1))

#else  /* BLOCK_BUG or DYNAMIC */


#ifndef DYNAMIC
shared RowOfBytes orig[IMGSIZE], edge[IMGSIZE];
#else
shared RowOfBytes *orig, *edge;
//shared 
int        IMGSIZE;
#endif

/* Next and previous rows index */
// IMGSIZE==BLOCK*THREADS
/* NOTE: NEXT_ROW(IMGSIZE**2) doesn't work (need one more % but it's unused anyway)
 *       PREV_ROW(0) doesn't work either (but unused as well)
 */
#define NEXT_ROW(i)   ((((i)+THREADS)%IMGSIZE)+(((i)+THREADS)/IMGSIZE))
#define PREV_ROW_(i)  ((((i)-THREADS)%IMGSIZE)+(((i)-THREADS)/IMGSIZE))
#define PREV_ROW(i)   ((i<THREADS)?(PREV_ROW_(i+IMGSIZE)-1):(PREV_ROW_(i)))

#define FIRST_ROW(i) ((i)<THREADS)
#define LAST_ROW(i)  ((i+THREADS)>=IMGSIZE)

#endif


/* The following function will ensure that the layout of the dynamically
 * allocated data is conforming to the UPC specs.
 */
void CheckDataLayout(shared RowOfBytes* ptr)
{
	int i, j;
	size_t err=0;
	volatile struct RowOfBytes* lp;
	volatile BYTET* lp_b;
	
	for(i=0; i<IMGSIZE; i++)
	{
		if(!MYTHREAD)
		{	if(upc_threadof(&ptr[i]) != ((size_t)i%THREADS))
			{	fprintf(stderr, "Warning: &ptr[%3i] has affinity to thread %2i\n",
								i, (int)upc_threadof(&ptr[i]));
				err++;
			}
		}
		
		if(MYTHREAD == (i%THREADS))
		{
			for(j=0; j<IMGSIZE; j++)
			{	assert(upc_threadof(&ptr[i]) == upc_threadof(&ptr[i].r[j]));
				lp_b = (BYTET*)&ptr[i].r[j];
			}

			lp=(struct RowOfBytes*)&ptr[i];
			if((i-MYTHREAD)%THREADS)
			{	lp=(struct RowOfBytes*)&ptr[NEXT_ROW(i)];
				lp=(struct RowOfBytes*)&ptr[PREV_ROW(i)];
			}
		}
	}
	upc_barrier 777;

	if(!MYTHREAD)
	{	if(err) fprintf(stderr, "*** Data layout test failed (%i errors)\n", (int)err);
		else    fprintf(stderr, "*** Data layout test successful\n");
	}
}

void CheckRows(shared RowOfBytes* ptr)
{
	int i;
	if(!MYTHREAD)
	{	for(i=0; i<BLOCK*THREADS; i++)
		{
			int j=(i*THREADS)%IMGSIZE+(i*THREADS)/IMGSIZE;
			fprintf(stderr, "i=%2i PREV_ROW=%2i NEXT_ROW=%2i\n", j, PREV_ROW(j), NEXT_ROW(j));
			if(j>THREADS)   assert(upc_threadof(&ptr[j])==upc_threadof(&ptr[PREV_ROW(j)]));
			if(!((j+THREADS)/IMGSIZE)) assert(upc_threadof(&ptr[j])==upc_threadof(&ptr[NEXT_ROW(j)]));
		}
	}
	upc_barrier 888;
}

void GenRandom(shared RowOfBytes* arr)
{
  int i,j;
#ifdef DEBUG
	fprintf(stderr, "GenRandom(): Entering\n");
#endif
  for (i=0; i<IMGSIZE; i++)
    for (j=0; j<IMGSIZE; j++)
		{
#ifdef DEBUG
			fprintf(stderr, "GenRandom(): i=% 5i | j=% 5i\r", i, j);
#endif
			arr[i].r[j]=((BYTET)rand());
		}
#ifdef DEBUG
	fprintf(stderr, "\nGenRandom(): orig successfully filled\n");
#endif
}

/* Include the definition for the Sobel function according to the hand-
 * optimization requested.
 */
#if   (defined OPT_PTRCAST)
#  include "sobel-opt-ptrcast.c"
#elif (defined OPT_PREFETCH)
#  include "sobel-opt-prefetch.c"
#elif (defined OPT_ALL)
#  include "sobel-opt-all.c"
#else	/* no hand-optimizations */
#  include "sobel-opt-none.c"
#endif

int main(int argc, char* argv[])
{
  int pe=MYTHREAD, time;
  double ftime;
  int i;

	setbuf(stdout,NULL);
	debug_init();
	
#ifdef DYNAMIC
	
  if (argc != 2)
  { if (!MYTHREAD)
    { fprintf(stderr, "Usage: %s imgsize\n", argv[0]);
      fprintf(stderr, "\timgsize       Size of the image to be processed (a power of 2)\n");
    }
    upc_barrier;
    exit(1);
	}

	//if(!MYTHREAD)  
    IMGSIZE = atoi(argv[1]);
	upc_barrier;
	if(!MYTHREAD)  assert(IMGSIZE>THREADS);
	
#ifdef DEBUG
	if (!MYTHREAD) fprintf(stderr, "sizeof(RowOfBytes)==%i\n", sizeof(RowOfBytes));
#endif 
	orig = upc_all_alloc(THREADS, BLOCK*sizeof(RowOfBytes));
	edge = upc_all_alloc(THREADS, BLOCK*sizeof(RowOfBytes));
	if(!MYTHREAD) debug_step;

	upc_forall(i=0; i<IMGSIZE; i++; &edge[i])
	{
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
		orig[i].r = (shared[] BYTET*)upc_alloc(IMGSIZE * sizeof(BYTET));
		edge[i].r = (shared[] BYTET*)upc_alloc(IMGSIZE * sizeof(BYTET));
#else
		orig[i].r = (shared[] BYTET*)upc_local_alloc(IMGSIZE, sizeof(BYTET));
		edge[i].r = (shared[] BYTET*)upc_local_alloc(IMGSIZE, sizeof(BYTET));
#endif
	}
	upc_barrier;
#ifdef DEBUG
	CheckDataLayout(orig);
	CheckRows(orig);
	upc_barrier;
#endif

	if(!MYTHREAD) debug_step;

#else
	if (argc!=1)
		fprintf(stderr, "Warning! Compiled for static array allocation (IMGSIZE=%i), "
										"args dimissed!\n", IMGSIZE);
#endif
  if (pe==0) GenRandom((shared void *)orig);
  
  upc_barrier 0;
  if (pe==0) clock();
  for (i=0; i<ITERATION_NUM; i++) Sobel();
  upc_barrier 1;

#ifdef DEBUG
  if(!pe) fprintf(stderr, "End of Sobel Edge Detection\n");
#endif
   
  if (pe==0) {
    time=clock();
    ftime=(time*1.0)/((double)ITERATION_NUM*CLOCKS_PER_SEC);
    printf("%12.6f\n", ftime);
    printf("done.\n");
  }

	upc_barrier;
  return 0;
}

/* vi:ts=2:ai
 */
