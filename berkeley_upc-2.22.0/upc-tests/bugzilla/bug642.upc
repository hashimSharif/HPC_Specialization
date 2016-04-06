#include <stdio.h>
#include <upc.h>                                                           
void f() {
 const char *tstrings[] =
  {"          total ",
   "          setup ",
   "            fft ",
   "         evolve ",
   "       checksum ",
   "         fftlow ",
   "        fftcopy ",
   "      transpose ",
   "     all_to_all "};                  
}
int main() { printf("done.\n"); return 0; }
