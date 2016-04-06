#include <time.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <upc.h>
#include <upc_tick.h>

double x = 1.0001;

int main() {
clock_t init = clock();
upc_tick_t inittick = upc_ticks_now();
printf("initial=%llu\n",(unsigned long long)init);
 for (int i=0; i < 5; i++) {
   { /* delay loop of CPU busy time */
     upc_tick_t start = upc_ticks_now();
     while (upc_ticks_to_ns(upc_ticks_now()-start) < 1000000000) {
       for (int i=0; i < 1000; i++) {
         x *= 1.0001;
       }
     }
   }
   {
   double tickt = upc_ticks_to_ns(upc_ticks_now()-inittick)*1.e-9;
   double clockt = (clock()-init)/(double)CLOCKS_PER_SEC;
   printf("tick_t: %.3f  clock: %.3f\n", tickt, clockt);
   if ((tickt - clockt) > 2) 
      printf("WARNING: clock() and upc_ticks_now() do not agree - (heavily loaded system?)\n");
   if ((clockt - tickt) > 2) 
      printf("ERROR: clock() > upc_ticks_now()\n");
   fflush(NULL);
   }
 }
 printf("done.\n");
}
