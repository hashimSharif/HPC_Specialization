#include <upc.h>
#include <stdint.h>

/* compile with -T 256 or -T 1024 to see problem */
shared double buff[THREADS*1065024ull];
shared double buff2[THREADS*4260096ull];

int main() { 
  uint64_t x;
  buff[0] = 0.0;
  buff[(THREADS-1)*1065024ull] = 1.4;
  buff2[(THREADS-1)*4260096ull] = 1.4;
  x = &(buff2[THREADS*4260096ull])-buff2;
  return 0;
}
