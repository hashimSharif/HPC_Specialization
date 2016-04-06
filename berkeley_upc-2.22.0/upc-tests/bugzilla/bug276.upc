#include <stdio.h>
#include <upc.h>


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

  p1 = upc_resetphase(p1); /* nop */
  p2 = upc_resetphase(p2); /* should reset phase */

  printf("phaseof(p1)=%i\n",(int)upc_phaseof(p1));
  printf("phaseof(p2)=%i\n",(int)upc_phaseof(p2));
  if (upc_phaseof(p1) != 0 || upc_phaseof(p2) != 0)
   printf("ERROR: wrong value 2!\n");

  printf("done.\n");
}




