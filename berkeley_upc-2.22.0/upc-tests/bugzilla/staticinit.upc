#include <stdio.h>
#include <stdint.h>
#include <upc.h>

shared uint8_t x8_0 = 0;
shared uint8_t x8_1 = 1;
shared uint8_t x8_2F = 0x2F;

shared uint16_t x16_0 = 0;
shared uint16_t x16_1 = 1;
shared uint16_t x16_4E2E = 0x4E2E;

shared uint32_t x32_0 = 0;
shared uint32_t x32_1 = 1;
shared uint32_t x32_7ABCDEF5 = 0x7ABCDEF5;

shared uint64_t x64_0 = 0;
shared uint64_t x64_1 = 1;
shared uint64_t x64_61A2A3A476543210 = 0x61A2A3A476543210ULL;

shared float f_0 = 0.0f;
shared float f_1 = 1.0f;
shared float f_4 = 4.0f;

shared float d_0 = 0.0;
shared float d_1 = 1.0;
shared float d_9 = 9.0;

int8_t X8_0 = 0;
int8_t X8_1 = 1;
int8_t X8_6F = 0x6F;

int16_t X16_0 = 0;
int16_t X16_1 = 1;
int16_t X16_64E2 = 0x64E2;

int32_t X32_0 = 0;
int32_t X32_1 = 1;
int32_t X32_75DBACE2 = 0x75DBACE2;

int64_t X64_0 = 0;
int64_t X64_1 = 1;
int64_t X64_29E3A420E3FF2DC5 = 0x29E3A420E3FF2DC5ULL;

float F_0 = 0.0f;
float F_1 = 1.0f;
float F_3 = 3.0f;

float D_0 = 0.0;
float D_1 = 1.0;
float D_8 = 8.0;

int main() {
#define PR(var,val) do { \
  unsigned long long thisval = (unsigned long long)(var##_##val); \
  printf("%s = %llx\n",#var"_"#val,thisval); \
  if ((thisval - (unsigned long long)(0x##val)) != 0) printf("ERROR: mismatch at line %i\n",__LINE__); \
} while (0)

PR(x8,0);
PR(x8,1);
PR(x8,2F);

PR(x16,0);
PR(x16,1);
PR(x16,4E2E);

PR(x32,0);
PR(x32,1);
PR(x32,7ABCDEF5);
PR(x64,0);
PR(x64,1);
PR(x64,61A2A3A476543210);

PR(f,0);
PR(f,1);
PR(f,4);

PR(d,0);
PR(d,1);
PR(d,9);

PR(X8,0);
PR(X8,1);
PR(X8,6F);

PR(X16,0);
PR(X16,1);
PR(X16,64E2);

PR(X32,0);
PR(X32,1);
PR(X32,75DBACE2);
PR(X64,0);
PR(X64,1);
PR(X64,29E3A420E3FF2DC5);

PR(F,0);
PR(F,1);
PR(F,3);

PR(D,0);
PR(D,1);
PR(D,8);

upc_barrier;

printf("done.\n");

return 0;
}

