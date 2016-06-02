#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include <upc.h>

#define ROWS THREADS
#define COLUMNS 1024

#include "bupc_timers.h"

int percent_ar[] = {5, 10, 20, 50, 70, 90, 95};

struct entry {
  double x;
  double y;
};

shared [COLUMNS] struct entry array[ROWS*COLUMNS];

int *index_array;
int ind_ar_size;
int poly_deg;

void build_index(double percent) {
  int i;
  if (percent == 0) {
    /* uniform random access: N-1/N of remote reads */ 
    for (i = 0; i < ind_ar_size; i++) {
      index_array[i] = rand() % (ROWS * COLUMNS);
    }
  } else {
    for (i = 0; i < percent * ind_ar_size; i++) {
      index_array[i] = MYTHREAD * COLUMNS + (rand() % COLUMNS);
    }
    for (; i < ind_ar_size; i++) {
      int proc = rand() % ROWS;
      if (proc == MYTHREAD) {
	/* not truly random, but oh well ...*/
	proc = (proc + 1) % THREADS;
      }
      index_array[i] = proc * COLUMNS + (rand() % COLUMNS);
    }
  }
}

int main(int argc, char** argv) {
  
  int iter;
  double res;
  int i,j,k; 
  double percent;
  
  if (argc < 4) {
    printf("wrong number of arguments: ./prog iter index_array_size poly_degree \n");
    upc_global_exit(1);
  }
  iter = atoi(argv[1]);
  ind_ar_size = atoi(argv[2]);
  poly_deg = atoi(argv[3]);
  
  percent =  (argc == 3) ? 0 : atoi(argv[3]) / 100.0;
  
  index_array = (int*) malloc(ind_ar_size * sizeof(int));
  
  /* init array */
  upc_forall(i = 0; i < ROWS; i++; &array[i*COLUMNS]) {
    for (j = 0; j < COLUMNS; j++) {
      array[i*COLUMNS + j].x = 1.14;
      array[i*COLUMNS + j].y = 1.53;
    }
  }
  
  upc_barrier;
  
  for (j = 0; j < sizeof(percent_ar) / sizeof (int); j++) {
    timer_clear(0);
    for (k = 0; k < iter; k++) {
      /* set up the index array */
      build_index(percent_ar[j] / 100.0);

      timer_start(0);
      
      for (i = 0; i < ind_ar_size; i++) {
	/* one read + one update*/
	int l;
	double tmp = array[index_array[i]].x;
	res = 0.0;
	for (l = 0; l < poly_deg; l++) {
	  res += (poly_deg - l) * pow(tmp, l);
	}
	array[index_array[i]].y = res;
      }
      timer_stop(0);
    }

    printf("%i: Performance of scale with %d %% of local accesses out of %d iterations: %f us/iter\n", 
           MYTHREAD, percent_ar[j], iter, (1.0E6*timer_read(0))/(((double)iter)*ind_ar_size));
    upc_barrier;
  }

  printf ("output: %f\n", res);
  return 0;
}
 

