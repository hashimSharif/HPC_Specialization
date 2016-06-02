#include <upc_relaxed.h>
#include <inttypes.h>

#ifndef ROWS
#define ROWS 256
#endif
#ifndef COLS
#define COLS 256
#endif

/* a matrix distributed on each processor */

#include "bupc_timers.h"

shared [COLS/THREADS] double matrix[ROWS][COLS];

void compute(int iter);
void copyData();

int main(int argc, char** argv) {

  int iter;
  int sub_size;
  int i,j,k;

  if (argc != 2) {
    printf("wrong number of args\n");
    upc_global_exit(1);
  }

  iter = atoi(argv[1]);

  /* init */
  upc_forall(i = 0; i < COLS; i++; &matrix[0][i]) {
    for (j = 0; j < ROWS; j++) { 
      matrix[j][i] = 3.14;
    }
  }

  upc_barrier;

  /* do computation */
  compute(iter);

  upc_barrier;
  printf("done.\n");  
  return 0;
}  

double tmp [ROWS][COLS];
  
void compute(int iter) {

    int i, j, k;
    int64_t start, end;
    double up, down, left, right;

    start = TIME();
    for (k = 0; k < iter; k++) {
	for (i = 0; i < ROWS; i++) {
	    upc_forall(j = 0; j < COLS; j++; &matrix[i][j]) {
		up = (i == 0) ? 0 : matrix[i-1][j];
		down = (i == ROWS-1) ? 0 : matrix[i+1][j];
		left = (j == 0) ? 0 : matrix[i][j-1];
		right = (j == COLS - 1) ? 0 : matrix[i][j+1];

		tmp[i][j] = 4 * matrix[i][j] - up - down - left - right;
	    } /* j */
	}
	upc_barrier;
	copyData(); 
	upc_barrier;
    }
    end = TIME();

    printf("Number of iterations: %d\n", iter);
    printf("time: %f us/iter\n", ((int32_t)(end - start)) / (double)iter); 
}

void copyData() {

    int i, j;
    for (i = 0; i < ROWS; i++) {
	upc_forall(j = 0; j < COLS; j++; &matrix[i][j]) {
	    matrix[i][j] = tmp[i][j];
	}
    }
}
