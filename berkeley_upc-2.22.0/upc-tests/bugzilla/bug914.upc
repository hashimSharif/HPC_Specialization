#include <assert.h>
#include <stdio.h>

#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
int main() {
 static unsigned long long MAG00[2]={0x0UL, MATRIX_A};
 static unsigned long MAG01[2]={0x0UL, MATRIX_A};
 static unsigned int MAG02[2]={0x0UL, MATRIX_A};
 unsigned long m = MATRIX_A;
 unsigned int m2 = MATRIX_A;
 assert(MAG00[1] > 0 && MAG00[1] < 0xF0000000UL && MAG00[1] == MATRIX_A);
 assert(MAG01[1] > 0 && MAG01[1] < 0xF0000000UL && MAG01[1] == MATRIX_A);
 assert(MAG02[1] > 0 && MAG02[1] < 0xF0000000UL && MAG02[1] == MATRIX_A);
 assert(m > 0 && m < 0xF0000000UL && m == MATRIX_A);
 assert(m2 > 0 && m2 < 0xF0000000UL && m2 == MATRIX_A);
 printf("done.\n");
 return 0;
}
