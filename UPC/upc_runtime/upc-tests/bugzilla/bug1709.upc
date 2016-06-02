/* A simple test of bupc_atomic extensions */

#include <upc.h>
#include <stdint.h>
#include <stdio.h>

shared int failures = 0;

#define DECL_TEST(_type,_code)                              \
  void test_##_code(void) {                                 \
    static shared _type var;                                \
    _type local_var, want;                                  \
    int prev_failures = failures;                           \
    int i;                                                  \
                                                            \
    if (!MYTHREAD) {                                        \
     _type *var_ptr = (_type *)&var;                        \
                                                            \
     /* SERIAL/Private tests */                             \
     printf("Testing BUPC atomics on type code " #_code " (serial tests)...\n");\
     fflush(stdout);                                        \
                                                            \
     /* SET  */                                             \
     bupc_atomic##_code##_set_private(var_ptr, 1);          \
                                                            \
     /* READ */                                             \
     local_var = bupc_atomic##_code##_read_private(var_ptr);\
     if (local_var != 1) {                                  \
      printf("ERROR: test_" #_code "_READ_private() returned 0x%llx when expecting 1\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     /* ADD */                                              \
     local_var = bupc_atomic##_code##_fetchadd_private(var_ptr, 2); \
     if (local_var != 1) {                                  \
      printf("ERROR: test_" #_code "_ADD_private() returned 0x%llx when expecting 1\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_read_private(var_ptr);\
     if (local_var != 3) {                                  \
      printf("ERROR: test_" #_code "_ADD_private() wrote 0x%llx when expecting 3\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
      bupc_atomic##_code##_set_private(var_ptr, 3);         \
     }                                                      \
                                                            \
     /* XOR */                                              \
     local_var = bupc_atomic##_code##_fetchxor_private(var_ptr, 6); \
     if (local_var != 3) {                                  \
      printf("ERROR: test_" #_code "_XOR_private() returned 0x%llx when expecting 3\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_read_private(var_ptr);\
     if (local_var != 5) {                                  \
      printf("ERROR: test_" #_code "_XOR_private() wrote 0x%llx when expecting 5\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
      bupc_atomic##_code##_set_private(var_ptr, 5);         \
     }                                                      \
                                                            \
     /* OR */                                               \
     local_var = bupc_atomic##_code##_fetchor_private(var_ptr,10);\
     if (local_var != 5) {                                  \
      printf("ERROR: test_" #_code "_OR_private() returned 0x%llx when expecting 5\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_read_private(var_ptr);\
     if (local_var != 15) {                                 \
      printf("ERROR: test_" #_code "_OR_private() wrote 0x%llx when expecting 15\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
      bupc_atomic##_code##_set_private(var_ptr, 15);        \
     }                                                      \
                                                            \
     /* AND */                                              \
     local_var = bupc_atomic##_code##_fetchand_private(var_ptr,24);\
     if (local_var != 15) {                                  \
      printf("ERROR: test_" #_code "_AND_private() returned 0x%llx when expecting 15\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_read_private(var_ptr);\
     if (local_var != 8) {                                  \
      printf("ERROR: test_" #_code "_AND_private() wrote 0x%llx when expecting 8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
      bupc_atomic##_code##_set_private(var_ptr, 8);         \
     }                                                      \
                                                            \
     /* NOT */                                              \
     local_var = bupc_atomic##_code##_fetchnot_private(var_ptr);\
     if (local_var != 8) {                                  \
      printf("ERROR: test_" #_code "_NOT_private() returned 0x%llx when expecting 8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_read_private(var_ptr);\
     if (local_var != ~(_type)8) {                          \
      printf("ERROR: test_" #_code "_NOT_private() wrote 0x%llx when expecting ~8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
      bupc_atomic##_code##_set_private(var_ptr, ~(_type)8); \
     }                                                      \
                                                            \
     /* SWAP */                                             \
     local_var = bupc_atomic##_code##_swap_private(var_ptr,10); \
     if (~local_var != 8) {                                 \
      printf("ERROR: test_" #_code "_SWAP_private() returned 0x%llx when expecting ~8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_read_private(var_ptr);\
     if (local_var != 10) {                                 \
      printf("ERROR: test_" #_code "_SWAP_private() wrote 0x%llx when expecting 10\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
      bupc_atomic##_code##_set_private(var_ptr, 10);        \
     }                                                      \
                                                            \
     /* ADD negative */                                     \
     local_var = bupc_atomic##_code##_fetchadd_private(var_ptr, (_type)(-2)); \
     if (local_var != 10) {                                  \
      printf("ERROR: test_" #_code "_ADD_private(-2) returned 0x%llx when expecting 10\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_read_private(var_ptr);\
     if (local_var != 8) {                                  \
      printf("ERROR: test_" #_code "_ADD_private() wrote 0x%llx when expecting 8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
      bupc_atomic##_code##_set_private(var_ptr, 8);         \
     }                                                      \
                                                            \
     /* CSWAP */                                            \
     local_var = bupc_atomic##_code##_cswap_private(var_ptr, 8, 9);\
     if (local_var != 8) {                                 \
      printf("ERROR: test_" #_code "_CSWAP_private() returned 0x%llx when expecting 8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_read_private(var_ptr);\
     if (local_var != 9) {                                  \
      printf("ERROR: test_" #_code "_CSWAP_private() wrote 0x%llx when expecting 9\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
      bupc_atomic##_code##_set_private(var_ptr, 9);         \
     }                                                      \
                                                            \
     /* MSWAP */                                            \
     local_var = bupc_atomic##_code##_mswap_private(var_ptr, 7, 255);\
     if (local_var != 9) {                                 \
      printf("ERROR: test_" #_code "_MSWAP_private() returned 0x%llx when expecting 9\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_read_private(var_ptr);\
     if (local_var != 15) {                                 \
      printf("ERROR: test_" #_code "_MSWAP_private() wrote 0x%llx when expecting 15\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
      bupc_atomic##_code##_set_private(var_ptr, 15);         \
     }                                                      \
    }                                                       \
    upc_barrier;                                            \
                                                            \
    for (i=0; i<THREADS; ++i) {                             \
     if (i != MYTHREAD) {                                   \
       upc_barrier i;                                       \
       continue;                                            \
     }                                                      \
                                                            \
     /* SERIAL tests */                                     \
     var = 1;                                               \
                                                            \
     /* ADD */                                              \
     local_var = bupc_atomic##_code##_fetchadd_relaxed(&var, 1); \
     if (local_var != 1) {                                  \
      printf("ERROR: test_" #_code "_ADD_relaxed() returned 0x%llx when expecting 1\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_fetchadd_strict(&var, 1); \
     if (local_var != 2) {                                  \
      printf("ERROR: test_" #_code "_ADD_strict() returned 0x%llx when expecting 2\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     /* XOR */                                              \
     local_var = bupc_atomic##_code##_fetchxor_relaxed(&var, 7); \
     if (local_var != 3) {                                  \
      printf("ERROR: test_" #_code "_XOR_relaxed() returned 0x%llx when expecting 3\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_fetchxor_strict(&var, 1); \
     if (local_var != 4) {                                  \
      printf("ERROR: test_" #_code "_XOR_strict() returned 0x%llx when expecting 4\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     /* OR */                                               \
     local_var = bupc_atomic##_code##_fetchor_relaxed(&var,2);\
     if (local_var != 5) {                                  \
      printf("ERROR: test_" #_code "_OR_relaxed() returned 0x%llx when expecting 5\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_fetchor_strict(&var,8);\
     if (local_var != 7) {                                  \
      printf("ERROR: test_" #_code "_OR_strict() returned 0x%llx when expecting 7\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     /* AND */                                              \
     local_var = bupc_atomic##_code##_fetchand_relaxed(&var,30);\
     if (local_var != 15) {                                  \
      printf("ERROR: test_" #_code "_AND_relaxed() returned 0x%llx when expecting 15\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_fetchand_strict(&var,9);\
     if (local_var != 14) {                                  \
      printf("ERROR: test_" #_code "_AND_strict() returned 0x%llx when expecting 14\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     /* NOT */                                              \
     local_var = bupc_atomic##_code##_fetchnot_relaxed(&var);\
     if (local_var != 8) {                                  \
      printf("ERROR: test_" #_code "_NOT_relaxed() returned 0x%llx when expecting 8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_fetchnot_strict(&var);\
     if (~local_var != 8) {                                 \
      printf("ERROR: test_" #_code "_NOT_strict() returned 0x%llx when expecting ~8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     /* SWAP */                                             \
     local_var = bupc_atomic##_code##_swap_relaxed(&var,9); \
     if (local_var != 8) {                                  \
      printf("ERROR: test_" #_code "_SWAP_relaxed() returned 0x%llx when expecting 8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_swap_strict(&var,10); \
     if (local_var != 9) {                                 \
      printf("ERROR: test_" #_code "_SWAP_strict() returned 0x%llx when expecting 9\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     /* ADD negative */                                     \
     local_var = bupc_atomic##_code##_fetchadd_relaxed(&var, (_type)(-1)); \
     if (local_var != 10) {                                  \
      printf("ERROR: test_" #_code "_ADD_relaxed(-1) returned 0x%llx when expecting 10\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_fetchadd_strict(&var, (_type)(-1)); \
     if (local_var != 9) {                                  \
      printf("ERROR: test_" #_code "_ADD_strict(-1) returned 0x%llx when expecting 9\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     /* CSWAP */                                            \
     local_var = bupc_atomic##_code##_cswap_relaxed(&var, 8, 9);\
     if (local_var != 8) {                                 \
      printf("ERROR: test_" #_code "_CSWAP_relaxed() returned 0x%llx when expecting 8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_cswap_strict(&var, 9, 8);\
     if (local_var != 9) {                                 \
      printf("ERROR: test_" #_code "_CSWAP_strict() returned 0x%llx when expecting 9\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     /* MSWAP */                                            \
     local_var = bupc_atomic##_code##_mswap_relaxed(&var, 7, 255);\
     if (local_var != 8) {                                 \
      printf("ERROR: test_" #_code "_MSWAP_relaxed() returned 0x%llx when expecting 8\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
     local_var = bupc_atomic##_code##_mswap_strict(&var, 24, 247);\
     if (local_var != 15) {                                 \
      printf("ERROR: test_" #_code "_MSWAP_strict() returned 0x%llx when expecting 15\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     /* READ */                                             \
     local_var = bupc_atomic##_code##_read_strict(&var);    \
     if (local_var != 23) {                                 \
      printf("ERROR: test_" #_code "_READ_strict() returned 0x%llx when expecting 23\n", \
             (long long unsigned int)local_var);            \
      ++failures;                                           \
     }                                                      \
                                                            \
     upc_barrier i;                                         \
    }                                                       \
                                                            \
    /* PARALLEL (pounding) tests */                         \
    if (!MYTHREAD) {                                        \
      printf("Testing BUPC atomics on type code " #_code " (parallel tests)...\n");\
      fflush(stdout);                                       \
    }                                                       \
    upc_barrier;                                            \
                                                            \
    bupc_atomic##_code##_set_relaxed(&var, 0);              \
    bupc_atomic##_code##_set_strict(&var, 0);               \
                                                            \
    upc_barrier;                                            \
                                                            \
    bupc_atomic##_code##_fetchadd_relaxed(&var, MYTHREAD);  \
    bupc_atomic##_code##_fetchadd_strict(&var, MYTHREAD);   \
                                                            \
    upc_barrier;                                            \
                                                            \
    local_var = bupc_atomic##_code##_read_relaxed(&var) +   \
                bupc_atomic##_code##_read_strict(&var);     \
    want = (THREADS * (THREADS - 1)) * 2;                   \
    if (local_var != want) {                                \
      printf("ERROR: test_" #_code "_ADD() thread %d read 0x%llx when expecting %d\n", \
             MYTHREAD, (long long unsigned int)local_var, (int)want);\
      ++failures;                                           \
    }                                                       \
                                                            \
    upc_barrier;                                            \
                                                            \
    bupc_atomic##_code##_fetchxor_relaxed(&var, MYTHREAD);  \
    bupc_atomic##_code##_fetchxor_strict(&var, MYTHREAD);   \
                                                            \
    upc_barrier;                                            \
                                                            \
    local_var = bupc_atomic##_code##_read_relaxed(&var) +   \
                bupc_atomic##_code##_read_strict(&var);     \
    if (local_var != want) {                                \
      printf("ERROR: test_" #_code "_XOR() thread %d read 0x%llx when expecting %d\n", \
             MYTHREAD, (long long unsigned int)local_var, (int)want);\
      ++failures;                                           \
    }                                                       \
                                                            \
    upc_barrier;                                            \
                                                            \
    bupc_atomic##_code##_fetchor_relaxed(&var, MYTHREAD);   \
    bupc_atomic##_code##_fetchor_strict(&var, MYTHREAD);    \
                                                            \
    upc_barrier;                                            \
                                                            \
    local_var = bupc_atomic##_code##_read_relaxed(&var) +   \
                bupc_atomic##_code##_read_strict(&var);     \
    want /= 2;                                              \
    for (i=0; i < THREADS; ++i) want = want | i;            \
    want *= 2;                                              \
    if (local_var != want) {                                \
      printf("ERROR: test_" #_code "_OR() thread %d read 0x%llx when expecting %d\n", \
             MYTHREAD, (long long unsigned int)local_var, (int)want);\
      ++failures;                                           \
    }                                                       \
                                                            \
    upc_barrier;                                            \
                                                            \
    bupc_atomic##_code##_fetchnot_relaxed(&var);            \
    bupc_atomic##_code##_fetchnot_strict(&var);             \
                                                            \
    upc_barrier;                                            \
                                                            \
    local_var = bupc_atomic##_code##_read_relaxed(&var) +   \
                bupc_atomic##_code##_read_strict(&var);     \
    /* want unchanged by even number of NOT operations */   \
    if (local_var != want) {                                \
      printf("ERROR: test_" #_code "_NOT() thread %d read 0x%llx when expecting %d\n", \
             MYTHREAD, (long long unsigned int)local_var, (int)want);\
      ++failures;                                           \
    }                                                       \
                                                            \
    upc_barrier;                                            \
                                                            \
    bupc_atomic##_code##_fetchand_relaxed(&var, MYTHREAD+1);\
    bupc_atomic##_code##_fetchand_strict(&var, MYTHREAD+1); \
                                                            \
    upc_barrier;                                            \
                                                            \
    local_var = bupc_atomic##_code##_read_relaxed(&var) +   \
                bupc_atomic##_code##_read_strict(&var);     \
    want = 0;                                               \
    if (local_var != want) {                                \
      printf("ERROR: test_" #_code "_AND() thread %d read 0x%llx when expecting %d\n", \
             MYTHREAD, (long long unsigned int)local_var, (int)want);\
      ++failures;                                           \
    }                                                       \
                                                            \
    upc_barrier;                                            \
                                                            \
    local_var = bupc_atomic##_code##_swap_relaxed(&var, MYTHREAD+1);\
    want = bupc_atomic##_code##_swap_strict(&var, THREADS+MYTHREAD+1);\
    upc_barrier;                                            \
    bupc_atomic##_code##_fetchadd_relaxed(&var, local_var); \
    bupc_atomic##_code##_fetchadd_strict(&var, want);       \
    upc_barrier;                                            \
                                                            \
    local_var = bupc_atomic##_code##_read_relaxed(&var) +   \
                bupc_atomic##_code##_read_strict(&var);     \
    want = (2*THREADS) * (2*THREADS + 1);                   \
    if (local_var != want) {                                \
      printf("ERROR: test_" #_code "_SWAP() thread %d read 0x%llx when expecting %d\n", \
             MYTHREAD, (long long unsigned int)local_var, (int)want);\
      ++failures;                                           \
    }                                                       \
                                                            \
    local_var /= 2;                                         \
    upc_barrier;                                            \
    bupc_atomic##_code##_cswap_relaxed(&var,local_var,  local_var+1);\
    bupc_atomic##_code##_cswap_strict(&var, local_var+1,local_var+2);\
    bupc_atomic##_code##_cswap_relaxed(&var,local_var+2,local_var+3);\
    bupc_atomic##_code##_cswap_strict(&var, local_var+3,local_var+4);\
    upc_barrier;                                            \
                                                            \
    local_var = bupc_atomic##_code##_read_relaxed(&var) +   \
                bupc_atomic##_code##_read_strict(&var);     \
    want = want + 8;                                        \
    if (local_var != want) {                                \
      printf("ERROR: test_" #_code "_CSWAP() thread %d read 0x%llx when expecting %d\n", \
             MYTHREAD, (long long unsigned int)local_var, (int)want);\
      ++failures;                                           \
    }                                                       \
                                                            \
    /* XXX: want a multi-threaded MSWAP test */             \
                                                            \
    upc_barrier;                                            \
    if (!MYTHREAD && (prev_failures == failures)) {         \
      puts("PASS");                                         \
    }                                                       \
  }

DECL_TEST(uint64_t, U64)
DECL_TEST(int64_t,  I64)
DECL_TEST(uint32_t, U32)
DECL_TEST(int32_t,  I32)

DECL_TEST(int, I)
DECL_TEST(unsigned int,  UI)
DECL_TEST(long, L)
DECL_TEST(unsigned long,  UL)

int main(void) {
   
  test_U64();
  test_I64();
  test_U32();
  test_I32();

  test_I();
  test_UI();
  test_L();
  test_UL();

  upc_barrier;

  if (!MYTHREAD) {
    puts(failures ? "FAILURE" : "SUCCESS");
  }

  upc_barrier;

  return !!failures;
}
