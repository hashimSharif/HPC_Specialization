#include <upc.h>
#include <stdio.h>

#if !defined(__UPC_TICK__)
#  error "__UPC_TICK__ not predefined"
#elif (__UPC_TICK__ < 1)
#  error "Bad value for predefined __UPC_TICK__"
#else
#  include <upc_tick.h>
#endif

#ifndef UPC_TICK_MAX
#  error "UPC_TICK_MAX is undefined"
#endif
#ifndef UPC_TICK_MIN
#  error "UPC_TICK_MIN is undefined"
#endif

volatile double x = 1.0001;
void compute_foo() {
 for (int i=0; i < 1000; i++) {
   x *= x;
 }
}

int main() {
  upc_tick_t start = upc_ticks_now();
  compute_foo(); /* do something that needs to be timed */
  upc_tick_t end = upc_ticks_now();

  upc_tick_t the_min = UPC_TICK_MIN;
  upc_tick_t the_max = UPC_TICK_MAX;

  printf("Time was: %d nanoseconds\n",  (int)upc_ticks_to_ns(end-start));

  if (the_max <= the_min)  {
    printf("ERROR: UPC_TICK_MAX <= UPC_TICK_MIN\n");
  } else {
    printf("done.\n");
  }

  return 0;
}
