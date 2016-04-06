#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define T int64_t

int main() {
  T maxval, minval;
    if (((T)-1) > 0) { // unsigned
      maxval = (T)-1;
      minval = 0;
    } else { // signed
      maxval = ((T)1) << (sizeof(T)*8-2);
      maxval = (maxval - 1) + maxval;
      minval = -maxval;
    }
  if (maxval <= minval) { 
    printf("ERROR\n");
    fflush(stdout);
    return 1;
  } 

  // code below this line just triggers the sunC optimizations

  T maxlocal = (T)(int64_t)(maxval / THREADS / 2);
  T minlocal = (T)(int64_t)(minval / THREADS / 2);
  T tmp = 0;
  for (int i=0; i < 1000/THREADS; i++) {
          T val = maxval - i - 1;
          tmp += maxval - val;
  }
  printf("%llx\n", (unsigned long long)(maxlocal/4 + minlocal/4 + tmp));
  printf("SUCCESS\n");

  return 0;
}
