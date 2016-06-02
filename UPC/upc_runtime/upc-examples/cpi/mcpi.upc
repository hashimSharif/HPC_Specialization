/* Compute pi by approximating the area of a circle of
   radius 1. 
   Compute random points in [0,1]x[0,1] and
   see what fraction of them are in the circle.  That gives
   pi/4 */ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <upc.h> 

/* Am I in the circle? */
int hit()
{
	
  double drand_max = RAND_MAX;
  double x = rand()/drand_max;
  double y = rand()/drand_max;
  if ((x*x + y*y) <= 1.0) return(1);
  else return(0);
}

shared int all_hits[THREADS];

int main(int argc, char **argv)
{
    int i, total_hits, my_hits = 0;
    double pi;
    int trials, my_trials;
    if (argc != 2)
	trials = 1000000;
    else
	trials = atoi(argv[1]);

    my_trials = (trials + THREADS - 1 - MYTHREAD)/THREADS;

    srand(MYTHREAD*17);

    for (i=0; i < my_trials; i++) my_hits += hit();
    all_hits[MYTHREAD] = my_hits;
    upc_barrier;
    if (MYTHREAD == 0) {
      total_hits = 0;
      for (i=0; i < THREADS; i++) {
	total_hits += all_hits[i];
      }
      pi = 4.0*((double) total_hits)/((double) trials);
      printf("PI estimated to %10.7f from %d trials on %d threads.\n",
	     pi, trials, THREADS);
    }
    return(0);
}
