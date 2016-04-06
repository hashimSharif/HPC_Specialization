/* test that reports on shared memory alignment */
#include <upc.h>

int main() {
 shared char *p;

 if (MYTHREAD == 0) {
 for (int i=1; i <= 1048576; i*=2) {
   char *lp;
   uintptr_t lpi;
   int align = 1;

   p = upc_alloc(i);
   lp = (char *)p;
   lpi = (uintptr_t)lp;
   while (!(lpi & 0x1) ) { align <<= 1; lpi >>= 1; }
   printf("upc_alloc(%i):       \t \t%8i-byte aligned\n", i, align);

   align = 1;
   p = upc_global_alloc(THREADS,i);
   lp = (char *)p;
   lpi = (uintptr_t)lp;
   while (!(lpi & 0x1) ) { align <<= 1; lpi >>= 1; }
   printf("upc_global_alloc(%i):\t \t%8i-byte aligned\n", i, align);
 }
 } 
 return 0;
} 
