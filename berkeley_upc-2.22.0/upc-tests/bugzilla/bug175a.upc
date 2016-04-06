#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


#define SIZEOF(obj,val) do { \
  int testval = sizeof(obj); \
  if (testval != (val)) {      \
   printf("%i: ERROR: sizeof(" #obj ")=%i, should be %i\n", MYTHREAD, testval, (val)); \
  }} while (0)

#define BLOCK_SIZEOF(obj,val) do { \
  int testval = upc_blocksizeof(obj); \
  if (testval != (val)) {      \
   printf("%i: ERROR: upc_blocksizeof(" #obj ")=%i, should be %i\n", MYTHREAD, testval, (val)); \
  }} while (0)

#if defined(__BERKELEY_UPC__) && defined(__UPC_STATIC_THREADS__)
// We can expect tight bounds
#define LOCAL_SIZEOF(obj,val) do { \
  int testval = upc_localsizeof(obj); \
  if (testval != (val)) {      \
   printf("%i: ERROR: upc_localsizeof(" #obj ")=%i, should be %i\n", MYTHREAD, testval, (val)); \
  }} while (0)
#else
#define LOCAL_SIZEOF(obj,val) do { \
  int testval = upc_localsizeof(obj); \
  if (testval < (val)) {      \
   printf("%i: ERROR: upc_localsizeof(" #obj ")=%i, should be >= %i\n", MYTHREAD, testval, (val)); \
  }} while (0)
#endif

#define ELEM_SIZEOF(obj,val) do { \
  int testval = upc_elemsizeof(obj); \
  if (testval != (val)) {      \
   printf("%i: ERROR: upc_elemsizeof(" #obj ")=%i, should be %i\n", MYTHREAD, testval, (val)); \
  }} while (0)

#define TEST(obj, sz, blocksz, localsz, elemsz) do { \
  SIZEOF(obj,sz);                   \
  BLOCK_SIZEOF(obj,blocksz);        \
  LOCAL_SIZEOF(obj,localsz);        \
  ELEM_SIZEOF(obj,elemsz);          \
} while (0)

#if __UPC_STATIC_THREADS__
#if THREADS != 2
 #error test must be compiled with 2 threads
#endif
 shared [7] char arr1[30];
 shared [7] int32_t arr3[30];
 shared double arr6[100];
#endif

 shared [7] char arr2[30*THREADS];
 shared [7] int32_t arr4[30*THREADS];
 shared [] float arr5[100];
 shared double arr7[100*THREADS];

 shared float x1;
 shared [] float x2;
 shared [13] float x3;

int main() {
 if (THREADS != 2) {
   printf("error: test must be run with 2 threads\n");
   exit(1);
 }


 #if __UPC_STATIC_THREADS__
  TEST(arr1, 30, 7, 16, 1);
  TEST(arr3, 120, 7, 64, 4);
  TEST(arr6, 800, 1, 400, 8);
 #endif

  TEST(arr2, 30*THREADS, 7, 32, 1);
  TEST(arr4, 120*THREADS, 7, 128, 4);

  TEST(arr5, 400, 0, 400, 4);

  TEST(arr7, 800*THREADS, 1, 800, 8);

  TEST(x1, 4, 1, 4, 4);
  TEST(x2, 4, 0, 4, 4);
  TEST(x3, 4, 13, 4, 4);

  /* type-name inputs */
 #if __UPC_STATIC_THREADS__
  TEST(shared float [10], 40, 1, 20, 4);
  TEST(shared [7] float [30], 120, 7, 64, 4);
 #endif

  TEST(shared float [10*THREADS], 80, 1, 40, 4);
  TEST(shared [] float [10], 40, 0, 40, 4);
  TEST(shared [7] float [30*THREADS], 120*THREADS, 7, 128, 4);

  TEST(shared float, 4, 1, 4, 4);
  TEST(shared [] float, 4, 0, 4, 4);
  TEST(shared [13] float, 4, 13, 4, 4);

  printf("done.\n");
  return 0;
}

