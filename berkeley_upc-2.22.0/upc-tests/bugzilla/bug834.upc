#include <stdio.h>
//#include <stdint.h>
#include <inttypes.h>
/* NOTE: revised 2001-01-22 to access 'tm' via (char*) rather than (uint16_t*).
  Vars 'seed' changed from 32-bit to 16-bit in the process.
  The purpose of the change is to fix the ANSI-aliasing violation in the original
  test while preserving its ability to reproduce the original translator bugs
  (which use of a union type would not have done). */
int main(void) {
    uint64_t tm = 0x010408104070;
    uint16_t seed = 0xFF00;
    int i;
    for (i=0; i < 8; i++) {
      seed = (char)seed ^ ((char *)&tm)[i];
    }
    if (seed == 0x002d) printf("done.\n");
    else printf("ERROR (0x%x)\n", (unsigned int)seed);
}

