/* UPC atomic error tester, v0.1
 * Written by Dan Bonachea 
 * Copyright 2013, The Regents of the University of California 
 * This code is under BSD license: http://upc.lbl.gov/download/dist/LICENSE.TXT
 */

/*****************************************************************************
Usage: atomic_err <test_num>

Runs the selected erroneous usage case for the atomics API. Every case
represents a client usage error, where the result is undefined behavior.
High-quality implementations may provide some kind of diagnostic output, but
others may silently fail or crash (all of which are permitted behaviors).

 *****************************************************************************/

#include <upc.h>
#include <upc_atomic.h>
#include <stdio.h>
#include <stdlib.h>

int testnum = 0;
void report(const char *s) {
  if (!MYTHREAD) { printf("Test %i: %s\n", testnum, s); fflush(stdout); }
  upc_barrier;
}

shared int64_t val_int32;
shared int64_t val_int64;

int main(int argc, char **argv) {
  if (argc > 1) {
    testnum = atoi(argv[1]);
  }

  upc_atomicdomain_t *dom_int32 = upc_all_atomicdomain_alloc(UPC_INT32, UPC_GET|UPC_SET|UPC_ADD, 0);
  int64_t tmp_int32 = 1, tmp2_int32 = 1;

  upc_atomicdomain_t *dom_int64 = upc_all_atomicdomain_alloc(UPC_INT64, UPC_GET|UPC_SET|UPC_ADD|UPC_CSWAP, 0);
  int64_t tmp_int64 = 1, tmp2_int64 = 1;

  switch (testnum) {

    case 1: report("Alloc bad type");   upc_all_atomicdomain_alloc(-1, UPC_ADD, 0); break;
    case 2: report("Alloc unsup type"); upc_all_atomicdomain_alloc(UPC_SHORT, UPC_ADD, 0); break;
    case 3: report("Alloc bad op");     upc_all_atomicdomain_alloc(UPC_INT, -1, 0); break;
    case 4: report("Alloc unsup op");   upc_all_atomicdomain_alloc(UPC_INT, UPC_LOGAND, 0); break;
    case 5: report("Alloc unsup op for type"); upc_all_atomicdomain_alloc(UPC_FLOAT, UPC_OR, 0); break;
    case 6: report("Alloc nonsingle type"); upc_all_atomicdomain_alloc((MYTHREAD?UPC_INT32:UPC_INT64), UPC_GET, 0); break;
    case 7: report("Alloc nonsingle op");   upc_all_atomicdomain_alloc(UPC_LONG, (MYTHREAD?UPC_MULT:UPC_ADD), 0); break;
    case 8: report("Alloc nonsingle hint"); upc_all_atomicdomain_alloc(UPC_DOUBLE, UPC_ADD, MYTHREAD); break;

    case 9: report("Free nonsingle dom"); upc_all_atomicdomain_free(MYTHREAD?dom_int64:NULL); break;
    case 10: report("Free nonsingle dom"); upc_all_atomicdomain_free(MYTHREAD?dom_int64:dom_int32); break;

    case 11: report("Isfast bad type");   upc_atomic_isfast(-1, UPC_ADD, &val_int32); break;
    case 12: report("Isfast unsup type"); upc_atomic_isfast(UPC_SHORT, UPC_ADD, &val_int32); break;
    case 13: report("Isfast bad op");     upc_atomic_isfast(UPC_INT32, -1, &val_int32); break;
    case 14: report("Isfast unsup op");   upc_atomic_isfast(UPC_INT32, UPC_LOGOR, &val_int32); break;
    case 15: report("Isfast unsup op for type");   upc_atomic_isfast(UPC_PTS, UPC_AND, &val_int32); break;
    case 16: report("Isfast null");       upc_atomic_isfast(UPC_DOUBLE, UPC_ADD|UPC_GET|UPC_SET, NULL); break;

    case 17: report("atomic null");       upc_atomic_relaxed(NULL, &tmp_int32, UPC_ADD, &val_int32, &tmp2_int32, 0); break;
    case 18: report("atomic null");       upc_atomic_relaxed(dom_int32, &tmp_int32, UPC_ADD, NULL, &tmp2_int32, 0); break;
    case 19: report("atomic bad dom");    upc_atomic_relaxed((upc_atomicdomain_t *)&val_int32, &tmp_int32, UPC_ADD, &val_int32, &tmp_int32, 0); break;
    case 20: report("atomic bad get");    upc_atomic_relaxed(dom_int32, NULL, UPC_GET, &val_int32, 0, 0); break;
    case 21: report("atomic bad arg");    upc_atomic_relaxed(dom_int32, &tmp_int32, UPC_GET, &val_int32, &tmp2_int32, 0); break;
    case 22: report("atomic bad op");     upc_atomic_relaxed(dom_int32, &tmp_int32, UPC_MULT, &val_int32, &tmp2_int32, 0); break;
    case 23: report("atomic bad arg");    upc_atomic_relaxed(dom_int32, NULL, UPC_ADD, &val_int32, &tmp2_int32, &tmp_int32); break;
    case 24: report("atomic bad arg");    upc_atomic_relaxed(dom_int32, NULL, UPC_ADD, &val_int32, NULL, NULL); break;
    case 25: report("atomic bad arg");    upc_atomic_relaxed(dom_int64, NULL, UPC_CSWAP, &val_int64, NULL, NULL); break;
    case 26: report("atomic bad arg");    upc_atomic_relaxed(dom_int64, NULL, UPC_CSWAP, &val_int64, &tmp_int64, NULL); break;
    case 27: report("atomic alias");      upc_atomic_relaxed(dom_int32, &tmp_int32, UPC_ADD, &val_int32, &tmp_int32, 0); break;
    case 28: report("atomic alias");      upc_atomic_relaxed(dom_int32, 0, UPC_ADD, &val_int32, (MYTHREAD==0?(void *)&val_int32:&tmp_int32), 0); break;
    case 29: report("atomic alias");      upc_atomic_relaxed(dom_int32, (MYTHREAD==0?(void *)&val_int32:&tmp_int32), UPC_ADD, &val_int32, &tmp2_int32, 0); break;

    default:
      if (!MYTHREAD) fprintf(stderr,"Usage: %s <test_num>\n", argv[0]);
      upc_barrier;
      return 1;
  }

  upc_barrier 8;
  fprintf(stderr,"%d: FAILED\n", MYTHREAD); // should never reach here
  return 1;
}
