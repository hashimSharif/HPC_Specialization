#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TEST_VAR
#define TEST_VAR "UPC_DUMMY"
#endif

#ifndef TEST_VAL
#define TEST_VAL "UPC dummy value"
#endif


int main(int argc, char **argv) {
  int ret = 0;
  const char *val = getenv(TEST_VAR);
  if (!val) {
    fprintf(stderr, "ERROR: getenv('%s') returned NULL on P%i/%i\n", TEST_VAR, MYTHREAD, THREADS);
    ret = 1;
  } else if (strcmp(val,TEST_VAL)) {
    fprintf(stderr, "ERROR: getenv('%s') returned '%s', expected '%s' on P%i/%i\n", 
            TEST_VAR, val, TEST_VAL, MYTHREAD, THREADS);
    ret = 2;
  }

  if (argc != 4) {
    fprintf(stderr, "ERROR: argc == %i (expected 4) on P%i/%i\n", 
            argc, MYTHREAD, THREADS);
    ret = 3;
  } else {
    if (strcmp(argv[1], "UPC")) {
      fprintf(stderr, "ERROR: argv[1] == %s (expected 'UPC') on P%i/%i\n", 
            argv[1], MYTHREAD, THREADS);
      ret = 4;
    }
    if (strcmp(argv[2], "is")) {
      fprintf(stderr, "ERROR: argv[2] == %s (expected 'is') on P%i/%i\n", 
            argv[2], MYTHREAD, THREADS);
      ret = 5;
    }
    if (strcmp(argv[3], "Unified Parallel C")) {
      fprintf(stderr, "ERROR: argv[3] == %s (expected 'Unified Parallel C') on P%i/%i\n", 
            argv[3], MYTHREAD, THREADS);
      ret = 6;
    }
  }

  printf("done.\n");
  return ret;
}
