/* Program: UPCBench - synthetic benchmark (upc_synthetic)
 * Programmer: Sebastien Chauvin
 * Revision: 1.0-BETA, January 23, 2000
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

 * It is based on :

 * Program: Stream
 * Programmer: Joe R. Zagar
 * Revision: 4.0-BETA, October 24, 1995
 * Original code developed by John D. McCalpin
 *
 * This program measures memory transfer rates in MB/s for simple 
 * computational kernels coded in C.  These numbers reveal the quality
 * of code generation for simple uncacheable kernels as well as showing
 * the cost of floating-point operations relative to memory accesses.
 *
 * INSTRUCTIONS:
 *
 *	    This benchmark requires a good bit of memory to run.  Adjust the
 *      value of 'ARRAY_SIZE' (below) to get a 'min time' of 
 *      at least 20 clock-ticks for every test. 
 *      This will provide rate estimates that should be good to about
 *      5% precision.
 *
 *      The USE_SHARED flag can be defined to use UPC shared arrays. If not
 *      defined, the program can also be compiled with a regular C compiler.
 */

#ifdef USE_SHARED
# ifdef USE_STRICT
#  include <upc_strict.h>
# elif USE_RELAXED
#  include <upc_relaxed.h>
# else
#  error "Need to define either USE_STRICT or USE_RELAXED."
# endif
#endif

#define __tostr(e) #e
#define tostr(e) __tostr(e)

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <assert.h>


#ifndef ARRAY_SIZE
#ifndef USE_SHARED
/* if not shared, need bigger arrays for better accuracy */
# define ARRAY_SIZE	10000000
#else
# define ARRAY_SIZE	 1000000
#endif
#endif

#define STRUCT_SIZE 6
#define NTESTS 10
#define NTIMES	7
#define OFFSET	0

#ifndef MIN
# define MIN(x,y) ((x)<(y)?(x):(y))
#endif
#ifndef MAX
# define MAX(x,y) ((x)>(y)?(x):(y))
#endif

#ifdef USE_SHARED
# define QUALIFIER shared
# define MemCpy(dst, src, size) upc_memcpy(dst, src, size);
# define MemSet(dst, i, size)   upc_memset(dst, i, size);
#else
# define QUALIFIER
# define MemCpy(dst, src, size) memcpy(dst, src, size);
# define MemSet(dst, i, size)   memset(dst, i, size);
#endif

#ifdef ELEM_T
typedef ELEM_T elem_t;
#else
# error "Define a type for operations performed (ELEM_T)."
#endif


#ifdef USE_SHARED
shared[] elem_t	*shared sa[THREADS], *shared sc[THREADS];

//shared [] static double	*a, *c;
shared[] elem_t	*a, *c;


#else
static elem_t	a[ARRAY_SIZE+OFFSET], c[ARRAY_SIZE+OFFSET];
#endif

typedef struct { elem_t a[STRUCT_SIZE]; } tstruct;

#ifdef USE_SHARED
typedef shared [] tstruct *pstruct;
#else
typedef tstruct *pstruct;
#endif

static double	rmstime[NTESTS] = {0}, maxtime[NTESTS] = {0},
		mintime[NTESTS];

#ifdef USE_SHARED
static int disable_test[NTESTS] = {0,0,0,0,0,0,0,0,0,0};
#else
static int disable_test[NTESTS] = {0,0,0,1,1,1,0,0,1,0};
#endif

static const char	*label[NTESTS] = {
#ifndef USE_SHARED
							  "memcpy:    ", 
							  "memset:    ",
#else
							  "upc_memcpy:", 
							  "upc_memset:",
#endif
							  "Struct_cp: ",
							  "Copy(arr): ",
							  "Copy(ptr): ",
							  "Set:       ",
							  "Get(strct):",
							  "Put(strct):",
							  "Sum:       ",
							  "Scale:     " };

static double	bytes[NTESTS] = {
    sizeof(elem_t) * ARRAY_SIZE,
    sizeof(elem_t) * ARRAY_SIZE,
    sizeof(elem_t) * ARRAY_SIZE,
    sizeof(elem_t) * ARRAY_SIZE,
    sizeof(elem_t) * ARRAY_SIZE,
    sizeof(elem_t) * ARRAY_SIZE,
    sizeof(elem_t) * ARRAY_SIZE,
    sizeof(elem_t) * ARRAY_SIZE,
    sizeof(elem_t) * ARRAY_SIZE,
    sizeof(elem_t) * ARRAY_SIZE
    };


/* second()
 *
 * Returns time in seconds.
 */
#if 0
#include <sys/time.h>
#include <sys/times.h>
double second()
{
    double secx;
    struct tms realbuf;

    times(&realbuf);
    secx = ( realbuf.tms_stime + realbuf.tms_utime ) / (float) CLK_TCK;
    return ((double) secx);
}
#else
#include <sys/time.h>
double second() {
    struct timeval tv;
    if (gettimeofday(&tv, NULL)) {
        perror("gettimeofday");
        abort();
    }
    return tv.tv_sec + (tv.tv_usec * 0.000001);
}
#endif

/* checktick()
 *
 * Computes the system clock accuracy.
 */
int checktick()
{
# define M 20
    int		i, minDelta, Delta;
    double	t1, t2, timesfound[M];

/*  Collect a sequence of M unique time values from the system. */

    for (i = 0; i < M; i++) {
	t1 = second();
	while( ((t2=second()) - t1) < 1.0E-6 );
	timesfound[i] = t1 = t2;
	}

/*
 * Determine the minimum difference between these M values.
 * This result will be our estimate (in microseconds) for the
 * clock granularity.
 */

    minDelta = 1000000;
    for (i = 1; i < M; i++) {
	Delta = (int)( 1.0E6 * (timesfound[i]-timesfound[i-1]));
	minDelta = MIN(minDelta, MAX(Delta,0));
	}

    return(minDelta);
#undef M
}

/* main()
 *
 * `volatile' global variables are used to make sure that no optimizations
 * will be done by the compiler to remove caculations.
 */

volatile elem_t tmp_elem;
volatile tstruct st_r;

int main()
{
    int			BytesPerWord;
    register int	i;
    int			k,j;
    double		scalar, times[NTESTS][NTIMES];
#ifndef USE_SHARED
    elem_t      *pa, *pc;
#else
    int thr;
    shared[] elem_t *pa, *pc;
#endif

    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

	BytesPerWord = sizeof(elem_t);
	printf("Array elements type is %li bits (" tostr(ELEM_T) ")\n", ((long)BytesPerWord<<3));
    printf("Total memory required : %.1f MB.\n", (2 * ARRAY_SIZE * BytesPerWord) / 1048576.0);
    printf("Clock Ticks: %d us\n", checktick());

#ifndef USE_SHARED
    printf("*** upc_synthetic benchmark without shared data\n\n");
    for (j=0; j<ARRAY_SIZE; j++) {
	a[j] = j/ARRAY_SIZE;
	c[j] = j/ARRAY_SIZE;
	}
#else
	if(!MYTHREAD)
	#ifdef RELAXED
	    printf("*** upc_synthetic benchmark with relaxed shared data\n\n");
	#else
	    printf("*** upc_synthetic benchmark with strict shared data\n\n");
	#endif

#ifdef DEBUG
	fprintf(stderr, "Starting memory allocation\n");
#endif

    sa[MYTHREAD] = pa =
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
       (shared[] elem_t*)upc_alloc((ARRAY_SIZE+OFFSET) * sizeof(elem_t));
#else
       (shared[] elem_t*)upc_local_alloc(ARRAY_SIZE+OFFSET, sizeof(elem_t));
#endif
    assert(pa != NULL);

    sc[MYTHREAD] = pc =
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
       (shared[] elem_t*)upc_alloc((ARRAY_SIZE+OFFSET) * sizeof(elem_t));
#else
       (shared[] elem_t*)upc_local_alloc(ARRAY_SIZE+OFFSET, sizeof(elem_t));
#endif
    assert(pc != NULL);

    for (j=0; j<ARRAY_SIZE; j++) {
		pa[j] = j/(double)ARRAY_SIZE;
		pc[j] = j/(double)ARRAY_SIZE;
	}
    upc_barrier 1;

#ifdef DEBUG
    fprintf(stderr, "Memory allocated\n");
#endif

    if (MYTHREAD) return 0;

#endif 

    /*	--- MAIN LOOP --- repeat test cases NTIMES times --- */

#ifdef USE_SHARED
    for (thr=0; thr<THREADS; thr++)
    { a=sa[thr];
      c=sc[thr];
      printf("Thread %d\n", thr);
#endif 
    scalar = 3.0;
    for (k=0; k<NTIMES; k++)
      { 
        fprintf(stderr, "|%d>",k);
		/* MemCopy */
        if (!disable_test[0])
        { times[0][k] = second();
          MemCpy(a, c, ARRAY_SIZE*sizeof(elem_t));
		  times[0][k] = second() - times[0][k];
		}

		/* MemSet */
        if (!disable_test[1])
        { fprintf(stderr, "1");
          times[1][k] = second();
          MemSet(a, 1, ARRAY_SIZE*sizeof(elem_t));
		  times[1][k] = second() - times[1][k];
		}

		/* Structure Copy (shared to shared) */
        if (!disable_test[2])
        { fprintf(stderr, "2");
		  times[2][k] = second();
		  { pstruct st_a = (QUALIFIER void*) a, 
                    st_c = (QUALIFIER void*) c;
#if 0 // May overrun the array bounds!
            for(i=0; i<ARRAY_SIZE; i+=STRUCT_SIZE)
#else
            for(i=0; i<ARRAY_SIZE-STRUCT_SIZE+1; i+=STRUCT_SIZE)
#endif
              *(st_a++) = *(st_c++);
          }
		  times[2][k] = second() - times[2][k];
		}

		/* Array Copy */
        if (!disable_test[3])
        { fprintf(stderr, "3");
		  times[3][k] = second();
		  for (j=0; j<ARRAY_SIZE; j++)
	    	c[j] = a[j];
		  times[3][k] = second() - times[3][k];
        }

		/* Array Copy Using Pointers */
        if (!disable_test[4])
        { fprintf(stderr, "4");
		  times[4][k] = second();
          { pc=c; pa=a;
	  	    for (j=0; j<ARRAY_SIZE; j++)
		      *(pc++) = *(pa++);
          }
		  times[4][k] = second() - times[4][k];
        }
	
		/* Set (to shared) */
        if (!disable_test[5])
		{ elem_t set=2;
          fprintf(stderr, "5");
          times[5][k] = second();
		  for (i=0; i<ARRAY_SIZE; i++)
		    a[i] = (set++);
		  times[5][k] = second() - times[5][k];
        }

		/* Get Struct (from shared to local) */
        if (!disable_test[6])
		{ fprintf(stderr, "6");
		  times[6][k] = second();
		  { pstruct st_a = (QUALIFIER void*)a;
#if 0 // May overrun the array bounds!
            for(i=0; i<ARRAY_SIZE; i+=STRUCT_SIZE)
#else
            for(i=0; i<ARRAY_SIZE-STRUCT_SIZE+1; i+=STRUCT_SIZE)
#endif
              st_r = *(st_a++);
          }
		  times[6][k] = second() - times[6][k];
		}

		/* Put Struct (from local to shared) */
        if (!disable_test[7])
		{ tstruct st_w = { { 0 } };
          fprintf(stderr, "7");
		  times[7][k] = second();
		  { pstruct st_a = (QUALIFIER void*) a;
#if 0 // May overrun the array bounds!
            for(i=0; i<ARRAY_SIZE; i+=STRUCT_SIZE)
#else
            for(i=0; i<ARRAY_SIZE-STRUCT_SIZE+1; i+=STRUCT_SIZE)
#endif
              *(st_a++) = st_w;
          }
		  times[7][k] = second() - times[7][k];
		}

		/* Sum */
        if (!disable_test[8])
		{ elem_t sum=0;
          fprintf(stderr, "8");
          times[8][k] = second();
		  for (i=0; i<ARRAY_SIZE; i++)
	    	sum += a[i];
          times[8][k] = second() - times[8][k];
		  tmp_elem = sum;	/* avoid compiler optimizations */
        }

		/* Scale */
        if (!disable_test[9])
        { fprintf(stderr, "9");
		  times[9][k] = second();
		  for (j=0; j<ARRAY_SIZE; j++)
		    c[j] = scalar * a[j];
		  times[9][k] = second() - times[9][k];
        }

        fprintf(stderr, "\n");
      }
 
    /*	--- SUMMARY --- */

    for(j=0; j<NTESTS;j++) 
    { mintime[j]=FLT_MAX;
      maxtime[j]=0;
    }

    for (k=0; k<NTIMES; k++)
	{
		for (j=0; j<NTESTS; j++)
        	if (!disable_test[j]) 
		    { 
			    rmstime[j] = rmstime[j] + (times[j][k] * times[j][k]);
			    mintime[j] = MIN(mintime[j], times[j][k]);
			    maxtime[j] = MAX(maxtime[j], times[j][k]);
		    }
	}
    
    printf("Function      Rate (MB/s)   RMS time     Min time     Max time\n");
    for (j=0; j<NTESTS; j++) 
      if (!disable_test[j])
	  {
		rmstime[j] = sqrt(rmstime[j]/(double)NTIMES);
   
        if (mintime[j]==0)
          printf("%sTime under system precision (RMS=%f)!\n",
                 label[j], rmstime[j]);
        else
			printf("%s%11.4f  %11.4f  %11.4f  %11.4f\n", label[j],
		       1.0E-06 * (bytes[j])/mintime[j],
		       rmstime[j],
		       mintime[j],
		       maxtime[j]);
	    }
#ifdef USE_SHARED
    }
#endif
    printf("done.\n");
    return 0;
}

/* vi:ts=4:ai
 */
