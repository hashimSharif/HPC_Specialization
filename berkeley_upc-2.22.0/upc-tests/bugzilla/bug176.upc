#include <upc.h>
#include <stdio.h>

/* PGI TPR 19327: libpgc in 13.0 to 13.5 contains a conflicting "a1" symbol! -PHH */
#if defined(__PGI) && (__PGIC__ == 13) && (__PGIC_MINOR__ < 6)
#define a1 mya1
#endif

#define EQUAL(t1,t2) do { \
  if (!bupc_assert_type(t1,t2)) \
   fprintf(stderr,"ERROR line %i: types mismatched: (%s) != (%s)\n", \
	__LINE__,#t1, #t2); \
  } while (0)


typedef shared [2] int *(*fnptr)(const int *, shared float *);
fnptr f;

shared int y;
shared [10] int x[100*THREADS];
shared const int * shared volatile w;
int * shared p;
typedef shared [20] int T1x;
T1x a1[THREADS];

typedef int *T1;
shared [10] T1 arr1[100*THREADS]; /* blocksize=10 shared array of pointers-to-private-ints */

int * shared [10] arr2[100*THREADS]; /* should be same as arr1 */

typedef shared [10] int *T2;
T2 arr3[100];  /* 100 element private array of pointers-to-shared-ints(blocksize=10) */

shared [10] int *arr4[100]; /* should be same as arr3 */

typedef shared [10] int *T3;
shared [10] T3 arr5[100*THREADS]; /* blocksize=10 shared array of pointers-to-shared-ints(blocksize=10) */

shared [10] int * shared [10] arr6[100*THREADS]; /* should be same as arr5 */

typedef shared [10] int *T4;
shared [2] T4 arr7[100*THREADS]; /* blocksize=2 shared array of pointers-to-shared-ints(blocksize=10) */

shared [10] int * shared [2] arr8[100*THREADS]; /* should be same as arr7 */

typedef shared [10] int *T5;
shared [] T5 arr9[100]; /* blocksize=I shared array of pointers-to-shared-ints(blocksize=10) */

shared [10] int * shared [] arr10[100]; /* should be same as arr9 */

typedef shared [1] int *T6;
shared [10] T6 arr11[100*THREADS]; /* blocksize=10 shared array of pointers-to-shared-ints(blocksize=1) */

shared [1] int * shared [10] arr12[100*THREADS]; /* should be same as arr11 */

typedef shared [10] int *T7;
T7 arr13[2][3][6]; /* 3-d private array of pointer-to-shared-ints(blocksize=10) */

shared [10] int *arr14[2][3][6]; /* should be same as arr13 */

typedef shared double *T8;
T8 arr15[100]; /* 100 element private array of pointers-to-shared-double(blocksize=1) */

shared double *arr16[100]; /* should be same as arr15 */

typedef shared [] double *T9;
T9 arr17[100]; /* 100 element private array of pointers-to-shared-double(blocksize=I) */

shared [] double *arr18[100]; /* should be same as arr17 */

typedef struct S1 {
        int x;
        shared [3] const double *p;
        volatile float f;
        } S1_t;
S1_t s1;

int main() {
  EQUAL(y,shared int); 
  EQUAL(&(x[10]), shared [10] int *);
  EQUAL(*p, int);
  EQUAL(a1[0], T1x);
  EQUAL(a1[0], shared [20] int);
  EQUAL(w, shared const int * shared volatile);
  EQUAL(&w, shared const int * shared volatile *);
  EQUAL(*w, shared const int);

  EQUAL(arr1, arr2);
  EQUAL(arr1[0], int * shared[10]);
  EQUAL(arr2[0], int * shared[10]);
  EQUAL(*(arr1[0]), int );
  EQUAL(*(arr2[0]), int );

  EQUAL(arr3, arr4);
  EQUAL(arr3[0], shared [10] int *);
  EQUAL(arr4[0], shared [10] int *);
  EQUAL(*(arr3[0]), shared [10] int );
  EQUAL(*(arr4[0]), shared [10] int );

  EQUAL(arr5, arr6);
  EQUAL(arr5[0], shared [10] int * shared [10] );
  EQUAL(arr6[0], shared [10] int * shared [10] );
  EQUAL(*(arr5[0]), shared [10] int );
  EQUAL(*(arr6[0]), shared [10] int );

  EQUAL(arr7, arr8);
  EQUAL(arr7[0], shared [10] int * shared [2] );
  EQUAL(arr8[0], shared [10] int * shared [2] );
  EQUAL(*(arr7[0]), shared [10] int );
  EQUAL(*(arr8[0]), shared [10] int );

  EQUAL(arr9, arr10);
  EQUAL(arr9[0],  shared [10] int * shared []  );
  EQUAL(arr10[0], shared [10] int * shared []  );
  EQUAL(*(arr9[0]),  shared [10] int   );
  EQUAL(*(arr10[0]), shared [10] int   );

  EQUAL(arr11, arr12);
  EQUAL(arr11[0], shared [1] int * shared [10]  );
  EQUAL(arr12[0], shared [1] int * shared [10]  );
  EQUAL(*(arr11[0]), shared [1] int );
  EQUAL(*(arr12[0]), shared [1] int );

  EQUAL(arr13, arr14);
  EQUAL(arr13[0][0][0], shared [10] int * );
  EQUAL(arr14[0][0][0], shared [10] int * );
  EQUAL(*(arr13[0][0][0]), shared [10] int  );
  EQUAL(*(arr14[0][0][0]), shared [10] int  );

  EQUAL(arr15, arr16);
  EQUAL(arr15[0], shared double * );
  EQUAL(arr16[0], shared double * );
  EQUAL(*(arr15[0]), shared double );
  EQUAL(*(arr16[0]), shared double );

  EQUAL(arr17, arr18);
  EQUAL(arr17[0], shared [] double * );
  EQUAL(arr18[0], shared [] double * );
  EQUAL(*(arr17[0]), shared [] double );
  EQUAL(*(arr18[0]), shared [] double );

#if 0
  EQUAL(const volatile int, int);
  EQUAL(const volatile int *, int *);
  EQUAL(int * const, int *);
  EQUAL(int * * const * * , int ****);
  EQUAL(int * * volatile * * , int ****);
  EQUAL(shared [10] int, shared [2] int);
  EQUAL(fnptr, int);
#endif
  EQUAL(fnptr, fnptr);
  EQUAL(S1_t, s1);


  printf("done.\n");
  return 0;
}
