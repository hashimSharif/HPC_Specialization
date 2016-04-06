#include <stdio.h>
#include <upc.h>


void check(int totalsize, int nbytes, int threadid, int answer) {
  int val;
  val = upc_affinitysize(totalsize, nbytes, threadid);
  if (val != answer) 
    printf("ERROR: upc_affinitysize(%i, %i, %i) returned %i, should be %i\n",
           totalsize, nbytes, threadid, val, answer);
}

int main() {
  shared int *p1;
  shared [5] int *p2;
  shared [] int *p3;
  shared [10] int *p4;
  shared void *p5;

  p3 = upc_alloc(1024);
  if (!p3) 
   printf("ERROR: upc_alloc failed.\n");

  p4 = upc_all_alloc(1024,10*sizeof(int));
  if (!p4) 
   printf("ERROR: upc_all_alloc failed.\n");

  p1 = (shared int *)&p4[1];
  p5 = &p4[1];
  p2 = p5;
  printf("phaseof(p1)=%i\n",(int)upc_phaseof(p1)); 
  printf("phaseof(p2)=%i\n",(int)upc_phaseof(p2));  
  if (upc_phaseof(p1) != 0 || upc_phaseof(p2) != 1)
   printf("ERROR: wrong value 1!\n");

  p1 = upc_resetphase(p1); /* should be no-op */
  p2 = upc_resetphase(p2); /* should reset phase */

  printf("phaseof(p1)=%i\n",(int)upc_phaseof(p1));
  printf("phaseof(p2)=%i\n",(int)upc_phaseof(p2));
  if (upc_phaseof(p1) != 0 || upc_phaseof(p2) != 0)
   printf("ERROR: wrong value 2!\n");

  if (THREADS != 2) {
    printf("ERROR: This test should be run with two threads.\n");
    upc_global_exit(1);
  }

  check(10,10,0,10);
  check(10,10,1,0);
  check(20,10,0,10);
  check(20,10,1,10);
  check(30,10,0,20);
  check(30,10,1,10);
  check(29,10,0,19);
  check(29,10,1,10);
  check(31,10,0,20);
  check(31,10,1,11);
  check(11,1,0,6);
  check(11,1,1,5);
  check(10,100,0,10);
  check(10,100,1,0);
  check(10,0,0,10);
  check(10,0,1,0);
  check(0,0,0,0);
  check(0,0,1,0);
  check(0,1,0,0);
  check(0,1,1,0);
  check(200,2,0,100);
  check(200,2,1,100);
  check(202,2,0,102);
  check(202,2,1,100);

  printf("done.\n");
}




