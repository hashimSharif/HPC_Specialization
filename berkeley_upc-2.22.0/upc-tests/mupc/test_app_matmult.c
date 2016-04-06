/* _test_app_matmult.c: matrix multiplication program.

	Date created : October 21, 2002
        Date modified: October 30, 2002

        Function tested: (Depending on the data type specified using the macro
			 data_t) If integer, then _UPCRTS_GetSyncInteger, 
			 _UPCRTS_GetBytes, and _UPCRTS_PutInteger.

        Description:
	- Matrix multiplication program. This program performs the following matrix
	  multiplication operation. User can change the data type by simply changing
	  the DATA_T macros. 
		a[ROW x colA] . b[colA x colB] = c[ROW x colB]
	- Matrix a is divided up among the threads so that row 0 has affinity to
	  thread 0, and row i has affinity to thread i.
	- Matrix b is divided up among the threads so that column 0 has affinity to
	  thread 0 and column i has affinity to thread i.
	- Matrix c is divided in the same fashion as matrix a.

        Platform Tested         No. Proc        Date Tested             Success
	UPC0 (all types)	2		October 30, 2002	Yes
	UPC0 (all types)	2		November 4, 2002	Yes
	CSE0 (all types)	2,4,8		November 12, 2002	Yes
	
        Bugs Found:
[FIXED] [10/21/2002] Can't compile this piece of code using the "mupcc" script. The
	following error message was obtained. This code compiles using UPC's compiler
	though...

	Alpha & UPC
	IL entry write-read difference: region number   2
     	entry kind = 20 (statement), written = 67, read = 66
        missing entry = 20
	"test_matmult.c", line 33 (col. 5): internal error: read_memory_region: not
          all expected entries were read

	Notes:
	[10/22/2002] It seems that brackets are needed for the "upc_forall" construct 
		     even if there's only 1 line of code in the construct. 
		     This is probably a bug with the edgcpfe_alpha source to source
		     converter. 
	[10/29/2002] User has to change the format secifier in the printfs depending on
		     the data type they used, or else erroneous results might be seen.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define DTYPE int 
#define ROW (THREADS*2) 
#define colA (THREADS*2)
#define colB (THREADS*2)

shared [colA] DTYPE a[ROW][colA];
shared [colB] DTYPE c[ROW][colB];
shared DTYPE b[colA][colB];

int main ()
{
   	int i, j, k;
	DTYPE sum;

	upc_forall (i = 0; i < ROW; i++; &a[i][0]) {
		for (j = 0; j < colA; j++) {
			a[i][j] = (DTYPE)(i) + (DTYPE)(j) + (DTYPE)(1);
		}
	}

	for (i = 0; i < colA; i++) {
		upc_forall(j = 0; j < colB; j++; &b[i][j]) {
			b[i][j] = (DTYPE)(i) * (DTYPE)(j) + (DTYPE)(1);
		}
	}

	upc_barrier;

#ifdef VERBOSE0
	if (MYTHREAD == 0) {
		for (i = 0; i < ROW; i++) {
			printf("\n\n");
			for (j = 0; j < colA; j++)
				printf("(%d)a[%d][%d] = %d   ", (int)upc_threadof(&a[i][j]), i, j, a[i][j]);	
		}
		printf("\n\n");
		
		for (i = 0; i < colA; i++) {
			printf("\n\n");
			for (j = 0; j < colB; j++)
				printf("(af=%d)b[%d][%d] = %d   ", (int)upc_threadof(&b[i][j]), i, j, b[i][j]);	
		}
		printf("\n\n");
	}
#endif
	upc_forall (i = 0; i < ROW; i++; &a[i][0]) {
		for (j = 0; j < colB; j++) {
			sum = (DTYPE)(0);
			for (k = 0; k < colA; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
	}

	upc_barrier;

	if (MYTHREAD == 0) {
		for (i = 0; i < ROW; i++) {
			printf("\n\n");
			for (j = 0; j < colB; j++)
				printf("(%d)c[%d][%d] = %d   ", (int)upc_threadof(&c[i][j]), i, j, c[i][j]);	
		}
                /* DOB: TODO, add a real result correctness check */
		printf("\nSuccess: application did not crash\n");
	}

	return 0;
}
