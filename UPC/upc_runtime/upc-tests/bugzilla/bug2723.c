#include <stdio.h>
#include <inttypes.h>
int main(void) {
    uint16_t seed;
    union {
      uint64_t u64;
      uint16_t u16[4];
    } tm;
    tm.u64 = 0x010408104080;
    seed = tm.u16[1];
    if (seed == 0x0104 || seed == 0x0810) printf("done.\n");
    else printf("ERROR (0x%x)\n", (unsigned int)seed);
}

