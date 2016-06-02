#include <upc.h>

#if __UPC_STATIC_THREADS__
typedef int *T1;
shared [10] T1 arr1[100]; /* blocksize=10 shared array of pointers-to-private-ints */
                        /* only legal in static env */

int * shared [10] arr2[100]; /* should be same as arr1 */
#endif

typedef shared [10] int *T2;
T2 arr3[100];  /* 100 element private array of pointers-to-shared-ints(blocksize=10) */
             /* legal in static or dynamic env */

shared [10] int *arr4[100]; /* should be same as arr3 */

#if __UPC_STATIC_THREADS__
typedef shared [10] int *T3;
shared [10] T3 arr5[100]; /* blocksize=10 shared array of pointers-to-shared-ints(blocksize=10) */
                        /* only legal in static env */

shared [10] int * shared [10] arr6[100]; /* should be same as arr5 */

typedef shared [10] int *T4;
shared [2] T4 arr7[100]; /* blocksize=2 shared array of pointers-to-shared-ints(blocksize=10) */
                        /* only legal in static env */

shared [10] int * shared [2] arr8[100]; /* should be same as arr7 */
#endif

typedef shared [10] int *T5;
shared [] T5 arr9[100]; /* blocksize=I shared array of pointers-to-shared-ints(blocksize=10) */
                        /* legal in static or dynamic env */

shared [10] int * shared [] arr10[100]; /* should be same as arr9 */

#if __UPC_STATIC_THREADS__
typedef shared [1] int *T6;
shared [10] T6 arr11[100]; /* blocksize=10 shared array of pointers-to-shared-ints(blocksize=1) */
                        /* only legal in static env */

shared [1] int * shared [10] arr12[100]; /* should be same as arr11 */
#endif

typedef shared [10] int *T7;
T7 arr13[2][3][6]; /* 3-d private array of pointer-to-shared-ints(blocksize=10) */
                        /* legal in static or dynamic env */

shared [10] int *arr14[2][3][6]; /* should be same as arr13 */

typedef shared double *T8;
T8 arr15[100]; /* 100 element private array of pointers-to-shared-double(blocksize=1) */
                        /* legal in static or dynamic env */

shared double *arr16[100]; /* should be same as arr15 */

typedef shared [] double *T9;
T9 arr17[100]; /* 100 element private array of pointers-to-shared-double(blocksize=I) */
                        /* legal in static or dynamic env */

shared [] double *arr18[100]; /* should be same as arr17 */

typedef int * shared [] *T10;
T10 arr19[100]; /* 100 element private array of 
                   pointers-to-shared-pointers(blocksize=I)-to-private-int */
                        /* legal in static or dynamic env */
int * shared [] *arr20[100]; /* should be same as arr19 */


shared [4] int arr21[100*THREADS]; /* blocksize=4 shared array of ints */
                                    /* legal in static or dynamic env */
typedef shared [4] int T11;
T11 arr22[100*THREADS]; /* should be same as arr21 */

typedef int T12;
typedef shared [4] T12 T13;
typedef T13 T14;
T14 arr23[100*THREADS]; /* also same as arr21 */

int main() { return 0; }
