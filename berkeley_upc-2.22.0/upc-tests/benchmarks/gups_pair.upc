#include "stdlib.h"
#include "stdio.h"
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
	proc = (proc + 1) % ROWS;
      }
      index_array[i] = proc * COLUMNS + (rand() % COLUMNS);
    }
  }
}

int main(int argc, char** argv) {
  
  int iter;
  double tmp;
  int i,j,k; 
  double percent;
  
  if (argc < 3) {
    printf("wrong number of arguments\n");
    upc_global_exit(1);
  }
  iter = atoi(argv[1]);
  ind_ar_size = atoi(argv[2]);
  percent =  (argc == 3) ? 0 : atoi(argv[3]) / 100.0;
  
  index_array = (int*) malloc(ind_ar_size * sizeof(int));
  
  /* init array */
  upc_forall(i = 0; i < ROWS; i++; &array[i*COLUMNS]) {
    for (j = 0; j < COLUMNS; j++) {
      array[i*COLUMNS + j].x = 3.14;
      array[i*COLUMNS + j].y = 4.13;
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
	/* read only */
	tmp = array[index_array[i]].x + array[index_array[i]].y + 1;
      }
      timer_stop(0);
    }

    printf("Performance of GUPS with %d %% of local accesses out of %d iterations: %f\n", percent_ar[j], iter, timer_read(0));
    upc_barrier;
  }

  printf ("output: %f\n", tmp);
  printf ("done.\n");
  return 0;
}
 

