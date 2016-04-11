/* --- UPCR system headers --- */ 
#include "upcr.h" 
#include "whirl2c.h"
#include "upcr_proxy.h"
/*******************************************************
 * C file translated from WHIRL Sun Apr 10 01:06:50 2016
 *******************************************************/

/* UPC Runtime specification expected: 3.6 */
#define UPCR_WANT_MAJOR 3
#define UPCR_WANT_MINOR 6
/* UPC translator version: release 2.22.0, built on Oct 27 2015 at 17:48:24, host aphid linux-x86_64/64, gcc v4.2.4 (Ubuntu 4.2.4-1ubuntu4) */
/* Included code from the initialization script */
#include</usr/local/berkeley_upc/opt/include/upcr_config.h>
#include</usr/local/berkeley_upc/opt/include/portable_platform.h>
#include "upcr_geninclude/stdio.h"
#include "upcr_geninclude/stdlib.h"
#include</usr/include/unistd.h>
#include</usr/local/berkeley_upc/opt/include/upcr_preinclude/upc_types.h>
#include "upcr_geninclude/stddef.h"
#include</usr/local/berkeley_upc/opt/include/upcr_preinclude/upc_bits.h>
#include "upcr_geninclude/stdlib.h"
#include "upcr_geninclude/inttypes.h"
#include</usr/include/assert.h>
#line 1 "doublereduce.w2c.h"
/* Include builtin types and operators */

#ifndef UPCR_TRANS_EXTRA_INCL
#define UPCR_TRANS_EXTRA_INCL
extern int upcrt_gcd (int _a, int _b);
extern int _upcrt_forall_start(int _start_thread, int _step, int _lo, int _scale);
#define upcrt_forall_start(start_thread, step, lo, scale)  \
       _upcrt_forall_start(start_thread, step, lo, scale)
int32_t UPCR_TLD_DEFINE_TENTATIVE(upcrt_forall_control, 4, 4);
#define upcr_forall_control upcrt_forall_control
#ifndef UPCR_EXIT_FUNCTION
#define UPCR_EXIT_FUNCTION() ((void)0)
#endif
#if UPCR_RUNTIME_SPEC_MAJOR > 3 || (UPCR_RUNTIME_SPEC_MAJOR == 3 && UPCR_RUNTIME_SPEC_MINOR >= 8)
  #define UPCRT_STARTUP_SHALLOC(sptr, blockbytes, numblocks, mult_by_threads, elemsz, typestr) \
      { &(sptr), (blockbytes), (numblocks), (mult_by_threads), (elemsz), #sptr, (typestr) }
#else
  #define UPCRT_STARTUP_SHALLOC(sptr, blockbytes, numblocks, mult_by_threads, elemsz, typestr) \
      { &(sptr), (blockbytes), (numblocks), (mult_by_threads) }
#endif
#define UPCRT_STARTUP_PSHALLOC UPCRT_STARTUP_SHALLOC

/**** Autonb optimization ********/

extern void _upcrt_memput_nb(upcr_shared_ptr_t _dst, const void *_src, size_t _n);
#define upcrt_memput_nb(dst, src, n) \
       (upcri_srcpos(), _upcrt_memput_nb(dst, src, n))

#endif


/* Types */
/* File-level vars and routines */
extern void initdoublereduce();

extern _IEEE64 doublereduce(_IEEE64 *, int);

extern int user_main();


#define UPCR_SHARED_SIZE_ 8
#define UPCR_PSHARED_SIZE_ 8
upcr_pshared_ptr_t reduce_incoming_directory;
upcr_pshared_ptr_t reduce_incoming_flags_directory;
upcr_pshared_ptr_t UPCR_TLD_DEFINE_TENTATIVE(reduce_incoming, 8, 8);
volatile double*  UPCR_TLD_DEFINE_TENTATIVE(reduce_incoming_local, 8, 8);
upcr_pshared_ptr_t*  UPCR_TLD_DEFINE_TENTATIVE(reduce_incoming_directory_cached, 8, 8);
upcr_pshared_ptr_t UPCR_TLD_DEFINE_TENTATIVE(reduce_incoming_flags, 8, 8);
volatile int*  UPCR_TLD_DEFINE_TENTATIVE(reduce_incoming_flags_local, 8, 8);
upcr_pshared_ptr_t*  UPCR_TLD_DEFINE_TENTATIVE(reduce_incoming_flags_directory_cached, 8, 8);
upcr_shared_ptr_t input;

void UPCRI_ALLOC_doublereduce_669514363622805199(void) { 
UPCR_BEGIN_FUNCTION();
upcr_startup_shalloc_t _bupc_info[] = { 
UPCRT_STARTUP_SHALLOC(input, 800, 1, 1, 8, "A100H_R100_d"), 
 };
upcr_startup_pshalloc_t _bupc_pinfo[] = { 
UPCRT_STARTUP_PSHALLOC(reduce_incoming_directory, 8, 1, 1, 8, "A1H_R1_PR0_d"), 
UPCRT_STARTUP_PSHALLOC(reduce_incoming_flags_directory, 8, 1, 1, 8, "A1H_R1_PR0_i"), 
 };

UPCR_SET_SRCPOS("_doublereduce_669514363622805199_ALLOC",0);
upcr_startup_shalloc(_bupc_info, sizeof(_bupc_info) / sizeof(upcr_startup_shalloc_t));
upcr_startup_pshalloc(_bupc_pinfo, sizeof(_bupc_pinfo) / sizeof(upcr_startup_pshalloc_t));
}

void UPCRI_INIT_doublereduce_669514363622805199(void) { 
UPCR_BEGIN_FUNCTION();
UPCR_SET_SRCPOS("_doublereduce_669514363622805199_INIT",0);
}

#line 28 "doublereduce.upc"
extern void initdoublereduce()
#line 28 "doublereduce.upc"
{
#line 28 "doublereduce.upc"
  UPCR_BEGIN_FUNCTION();
  int i;
  upcr_pshared_ptr_t * _bupc__casttmp0;
  upcr_pshared_ptr_t * _bupc__casttmp1;
  upcr_shared_ptr_t _bupc_call0;
  upcr_shared_ptr_t _bupc_call1;
  void * _bupc_call2;
  void * _bupc_call3;
  upcr_pshared_ptr_t _bupc_Mstopcvt4;
  _IEEE64 * _bupc_Mcvtptr5;
  upcr_pshared_ptr_t _bupc_Mptra6;
  upcr_pshared_ptr_t _bupc_Mstopcvt7;
  int * _bupc_Mcvtptr8;
  upcr_pshared_ptr_t _bupc_Mptra9;
  upcr_pshared_ptr_t _bupc_Mptra10;
  upcr_pshared_ptr_t _bupc_Mptra11;
  upcr_pshared_ptr_t _bupc_spillld12;
  upcr_pshared_ptr_t _bupc_Mptra13;
  upcr_pshared_ptr_t _bupc_spillld14;
  
#line 30 "doublereduce.upc"
  _bupc_call0 = upc_alloc((unsigned long)((_UINT64)(((int) upcr_threads () )) * 8ULL));
#line 30 "doublereduce.upc"
  _bupc_Mstopcvt4 = UPCR_SHARED_TO_PSHARED(_bupc_call0);
#line 30 "doublereduce.upc"
  (*((upcr_pshared_ptr_t *) UPCR_TLD_ADDR( reduce_incoming ))) = _bupc_Mstopcvt4;
#line 31 "doublereduce.upc"
  _bupc_Mcvtptr5 = (_IEEE64 *) UPCR_PSHARED_TO_LOCAL((*((upcr_pshared_ptr_t *) UPCR_TLD_ADDR( reduce_incoming ))));
#line 31 "doublereduce.upc"
  (*((volatile _IEEE64 **) UPCR_TLD_ADDR( reduce_incoming_local ))) = (volatile _IEEE64 *)(_bupc_Mcvtptr5);
#line 32 "doublereduce.upc"
  _bupc_Mptra6 = UPCR_ADD_PSHARED1(reduce_incoming_directory, 8ULL, ((int) upcr_mythread () ));
#line 32 "doublereduce.upc"
  UPCR_PUT_PSHARED_VAL_STRICT(_bupc_Mptra6, 0, (*((upcr_pshared_ptr_t *) UPCR_TLD_ADDR( reduce_incoming ))), 8);
#line 34 "doublereduce.upc"
  _bupc_call1 = upc_alloc((unsigned long)((_UINT64)(((int) upcr_threads () )) * 4ULL));
#line 34 "doublereduce.upc"
  _bupc_Mstopcvt7 = UPCR_SHARED_TO_PSHARED(_bupc_call1);
#line 34 "doublereduce.upc"
  (*((upcr_pshared_ptr_t *) UPCR_TLD_ADDR( reduce_incoming_flags ))) = _bupc_Mstopcvt7;
#line 35 "doublereduce.upc"
  _bupc_Mcvtptr8 = (int *) UPCR_PSHARED_TO_LOCAL((*((upcr_pshared_ptr_t *) UPCR_TLD_ADDR( reduce_incoming_flags ))));
#line 35 "doublereduce.upc"
  (*((volatile int **) UPCR_TLD_ADDR( reduce_incoming_flags_local ))) = (volatile int *)(_bupc_Mcvtptr8);
#line 36 "doublereduce.upc"
  _bupc_Mptra9 = UPCR_ADD_PSHARED1(reduce_incoming_flags_directory, 8ULL, ((int) upcr_mythread () ));
#line 36 "doublereduce.upc"
  UPCR_PUT_PSHARED_VAL_STRICT(_bupc_Mptra9, 0, (*((upcr_pshared_ptr_t *) UPCR_TLD_ADDR( reduce_incoming_flags ))), 8);
#line 38 "doublereduce.upc"
  i = 0;
#line 38 "doublereduce.upc"
  while(i < ((int) upcr_threads () ))
#line 38 "doublereduce.upc"
  {
#line 39 "doublereduce.upc"
    _bupc_Mptra10 = UPCR_ADD_PSHAREDI((*((upcr_pshared_ptr_t *) UPCR_TLD_ADDR( reduce_incoming_flags ))), 4ULL, i);
#line 39 "doublereduce.upc"
    UPCR_PUT_PSHARED_VAL_STRICT(_bupc_Mptra10, 0, 0, 4);
#line 40 "doublereduce.upc"
    _1 :;
#line 40 "doublereduce.upc"
    i = i + 1;
  }
#line 41 "doublereduce.upc"
  upcr_barrier(935481039, 1);
#line 42 "doublereduce.upc"
  _bupc_call2 = calloc((unsigned long)(_UINT64)(((int) upcr_threads () )), (unsigned long) 8ULL);
#line 42 "doublereduce.upc"
  _bupc__casttmp0 = _bupc_call2;
#line 42 "doublereduce.upc"
  (*((upcr_pshared_ptr_t **) UPCR_TLD_ADDR( reduce_incoming_directory_cached ))) = _bupc__casttmp0;
#line 43 "doublereduce.upc"
  _bupc_call3 = calloc((unsigned long)(_UINT64)(((int) upcr_threads () )), (unsigned long) 8ULL);
#line 43 "doublereduce.upc"
  _bupc__casttmp1 = _bupc_call3;
#line 43 "doublereduce.upc"
  (*((upcr_pshared_ptr_t **) UPCR_TLD_ADDR( reduce_incoming_flags_directory_cached ))) = _bupc__casttmp1;
#line 44 "doublereduce.upc"
  i = 0;
#line 44 "doublereduce.upc"
  while(i < ((int) upcr_threads () ))
#line 44 "doublereduce.upc"
  {
#line 45 "doublereduce.upc"
    _bupc_Mptra11 = UPCR_ADD_PSHARED1(reduce_incoming_directory, 8ULL, i);
#line 45 "doublereduce.upc"
    UPCR_GET_PSHARED_STRICT(&_bupc_spillld12, _bupc_Mptra11, 0, 8);
#line 45 "doublereduce.upc"
    * ((*((upcr_pshared_ptr_t **) UPCR_TLD_ADDR( reduce_incoming_directory_cached ))) + i) = _bupc_spillld12;
#line 46 "doublereduce.upc"
    _bupc_Mptra13 = UPCR_ADD_PSHARED1(reduce_incoming_flags_directory, 8ULL, i);
#line 46 "doublereduce.upc"
    UPCR_GET_PSHARED_STRICT(&_bupc_spillld14, _bupc_Mptra13, 0, 8);
#line 46 "doublereduce.upc"
    * ((*((upcr_pshared_ptr_t **) UPCR_TLD_ADDR( reduce_incoming_flags_directory_cached ))) + i) = _bupc_spillld14;
#line 47 "doublereduce.upc"
    _2 :;
#line 47 "doublereduce.upc"
    i = i + 1;
  }
  UPCR_EXIT_FUNCTION();
  return;
} /* initdoublereduce */


#line 51 "doublereduce.upc"
extern _IEEE64 doublereduce(
  _IEEE64 * vec,
  int lenvec)
#line 51 "doublereduce.upc"
{
#line 51 "doublereduce.upc"
  UPCR_BEGIN_FUNCTION();
  _IEEE64 mycontribution;
  int myid;
  int level;
  int exp2level;
  int i;
  int target;
  int oddneighbour;
  _IEEE64 result;
  int _bupc_w2c_oddneighbour0;
  int evenneighbour;
  upcr_pshared_ptr_t _bupc_Mptra15;
  upcr_pshared_ptr_t _bupc_Mptra16;
  upcr_pshared_ptr_t _bupc_Mptra17;
  upcr_pshared_ptr_t _bupc_Mptra18;
  
#line 52 "doublereduce.upc"
  mycontribution = 0.0;
#line 54 "doublereduce.upc"
  myid = ((int) upcr_mythread () );
#line 55 "doublereduce.upc"
  level = 0;
#line 57 "doublereduce.upc"
  exp2level = 1;
#line 60 "doublereduce.upc"
  i = 0;
#line 60 "doublereduce.upc"
  while(i < lenvec)
#line 60 "doublereduce.upc"
  {
#line 61 "doublereduce.upc"
    mycontribution = mycontribution + *(vec + i);
#line 62 "doublereduce.upc"
    _1 :;
#line 62 "doublereduce.upc"
    i = i + 1;
  }
#line 64 "doublereduce.upc"
  while(1)
#line 64 "doublereduce.upc"
  {
#line 65 "doublereduce.upc"
    if((myid % 2) == 1)
#line 65 "doublereduce.upc"
    {
#line 67 "doublereduce.upc"
      target = ((int) upcr_mythread () ) - exp2level;
#line 76 "doublereduce.upc"
      _bupc_Mptra15 = UPCR_ADD_PSHAREDI(*((*((upcr_pshared_ptr_t **) UPCR_TLD_ADDR( reduce_incoming_directory_cached ))) + target), 8ULL, ((int) upcr_mythread () ));
#line 76 "doublereduce.upc"
      UPCR_PUT_PSHARED_DOUBLEVAL_STRICT(_bupc_Mptra15, 0, mycontribution);
#line 77 "doublereduce.upc"
      _bupc_Mptra16 = UPCR_ADD_PSHAREDI(*((*((upcr_pshared_ptr_t **) UPCR_TLD_ADDR( reduce_incoming_flags_directory_cached ))) + target), 4ULL, ((int) upcr_mythread () ));
#line 77 "doublereduce.upc"
      UPCR_PUT_PSHARED_VAL_STRICT(_bupc_Mptra16, 0, ((int) upcr_mythread () ) + 1, 4);
#line 80 "doublereduce.upc"
      goto _2;
    }
    else
#line 65 "doublereduce.upc"
    {
#line 84 "doublereduce.upc"
      oddneighbour = ((int) upcr_mythread () ) + exp2level;
#line 85 "doublereduce.upc"
      if(oddneighbour >= ((int) upcr_threads () ))
#line 85 "doublereduce.upc"
      {
#line 87 "doublereduce.upc"
        myid = myid * 2;
#line 87 "doublereduce.upc"
        exp2level = exp2level / 2;
#line 88 "doublereduce.upc"
        goto _2;
      }
#line 91 "doublereduce.upc"
      while(*((*((volatile int **) UPCR_TLD_ADDR( reduce_incoming_flags_local ))) + oddneighbour) == 0)
#line 91 "doublereduce.upc"
      {
#line 92 "doublereduce.upc"
        upcr_poll();
      }
#line 95 "doublereduce.upc"
      if(*((*((volatile int **) UPCR_TLD_ADDR( reduce_incoming_flags_local ))) + oddneighbour) == (oddneighbour + 1))
#line 95 "doublereduce.upc"
      {
        0;
      }
      else
#line 95 "doublereduce.upc"
      {
#line 95 "doublereduce.upc"
        __assert_fail("reduce_incoming_flags_local[oddneighbour] == oddneighbour+1", "doublereduce.upc", (unsigned int) 95U, "doublereduce");
      }
#line 97 "doublereduce.upc"
      mycontribution = mycontribution + *((*((volatile _IEEE64 **) UPCR_TLD_ADDR( reduce_incoming_local ))) + oddneighbour);
#line 99 "doublereduce.upc"
      * ((*((volatile int **) UPCR_TLD_ADDR( reduce_incoming_flags_local ))) + oddneighbour) = 0;
    }
#line 101 "doublereduce.upc"
    exp2level = exp2level * 2;
#line 102 "doublereduce.upc"
    myid = myid / 2;
  }
#line 103 "doublereduce.upc"
  _2 :;
#line 105 "doublereduce.upc"
  result = mycontribution;
#line 132 "doublereduce.upc"
  do
#line 132 "doublereduce.upc"
  {
#line 108 "doublereduce.upc"
    if(((_UINT32)(myid) & 1U) == 0U)
#line 108 "doublereduce.upc"
    {
#line 110 "doublereduce.upc"
      _bupc_w2c_oddneighbour0 = ((int) upcr_mythread () ) + exp2level;
#line 113 "doublereduce.upc"
      _bupc_Mptra17 = UPCR_ADD_PSHAREDI(*((*((upcr_pshared_ptr_t **) UPCR_TLD_ADDR( reduce_incoming_directory_cached ))) + _bupc_w2c_oddneighbour0), 8ULL, ((int) upcr_mythread () ));
#line 113 "doublereduce.upc"
      UPCR_PUT_PSHARED_DOUBLEVAL_STRICT(_bupc_Mptra17, 0, result);
#line 114 "doublereduce.upc"
      _bupc_Mptra18 = UPCR_ADD_PSHAREDI(*((*((upcr_pshared_ptr_t **) UPCR_TLD_ADDR( reduce_incoming_flags_directory_cached ))) + _bupc_w2c_oddneighbour0), 4ULL, ((int) upcr_mythread () ));
#line 114 "doublereduce.upc"
      UPCR_PUT_PSHARED_VAL_STRICT(_bupc_Mptra18, 0, ((int) upcr_mythread () ) + 1, 4);
    }
    else
#line 108 "doublereduce.upc"
    {
#line 119 "doublereduce.upc"
      evenneighbour = ((int) upcr_mythread () ) - exp2level;
#line 120 "doublereduce.upc"
      while(*((*((volatile int **) UPCR_TLD_ADDR( reduce_incoming_flags_local ))) + evenneighbour) == 0)
#line 120 "doublereduce.upc"
      {
#line 121 "doublereduce.upc"
        upcr_poll();
      }
#line 123 "doublereduce.upc"
      if(*((*((volatile int **) UPCR_TLD_ADDR( reduce_incoming_flags_local ))) + evenneighbour) == (evenneighbour + 1))
#line 123 "doublereduce.upc"
      {
        0;
      }
      else
#line 123 "doublereduce.upc"
      {
#line 123 "doublereduce.upc"
        __assert_fail("reduce_incoming_flags_local[evenneighbour] == evenneighbour+1", "doublereduce.upc", (unsigned int) 123U, "doublereduce");
      }
#line 124 "doublereduce.upc"
      result = *((*((volatile _IEEE64 **) UPCR_TLD_ADDR( reduce_incoming_local ))) + evenneighbour);
#line 126 "doublereduce.upc"
      * ((*((volatile int **) UPCR_TLD_ADDR( reduce_incoming_flags_local ))) + evenneighbour) = 0;
    }
#line 130 "doublereduce.upc"
    myid = myid * 2;
#line 131 "doublereduce.upc"
    exp2level = exp2level / 2;
#line 132 "doublereduce.upc"
    _3 :;
  }
#line 132 "doublereduce.upc"
  while(exp2level > 0);
#line 133 "doublereduce.upc"
  printf("MYTHREAD=%4d result=%10.3f\n", ((int) upcr_mythread () ), result);
#line 134 "doublereduce.upc"
  UPCR_EXIT_FUNCTION();
#line 134 "doublereduce.upc"
  return result;
} /* doublereduce */


#line 141 "doublereduce.upc"
extern int user_main()
#line 141 "doublereduce.upc"
{
#line 141 "doublereduce.upc"
  UPCR_BEGIN_FUNCTION();
  register _IEEE64 _bupc_comma;
  int passed;
  _IEEE64 answer;
  int numth;
  int i;
  _IEEE64 result;
  upcr_shared_ptr_t _bupc_Mptra19;
  upcr_shared_ptr_t _bupc_Mptra20;
  _IEEE64 * _bupc_Mcvtptr21;
  
#line 143 "doublereduce.upc"
  sleep((unsigned int) 40U);
#line 146 "doublereduce.upc"
  passed = 1;
#line 147 "doublereduce.upc"
  printf("Starting..\n");
#line 148 "doublereduce.upc"
  answer = (_IEEE64)(((((int) upcr_threads () ) * ((((int) upcr_threads () ) * 100) + -1)) * 100) / 2);
#line 149 "doublereduce.upc"
  if(((int) upcr_mythread () ) == 0)
#line 149 "doublereduce.upc"
  {
#line 150 "doublereduce.upc"
    numth = ((int) upcr_threads () );
#line 151 "doublereduce.upc"
    printf("Expected answer = %10.3f\n", answer);
#line 153 "doublereduce.upc"
    while(((_UINT32)(numth) & 1U) == 0U)
#line 153 "doublereduce.upc"
    {
#line 154 "doublereduce.upc"
      numth = numth / 2;
    }
#line 156 "doublereduce.upc"
    if(numth != 1)
#line 156 "doublereduce.upc"
    {
#line 157 "doublereduce.upc"
      printf("Failed: number of threads [%d] MUST be a power of 2\n", ((int) upcr_threads () ));
#line 158 "doublereduce.upc"
      upc_global_exit((int) 1);
    }
  }
#line 161 "doublereduce.upc"
  if(((int) upcr_mythread () ) == 0)
#line 161 "doublereduce.upc"
  {
#line 162 "doublereduce.upc"
    i = 0;
#line 162 "doublereduce.upc"
    while(i < (((int) upcr_threads () ) * 100))
#line 162 "doublereduce.upc"
    {
#line 163 "doublereduce.upc"
      _bupc_Mptra19 = UPCR_ADD_SHARED(input, 8ULL, i, 100ULL);
#line 163 "doublereduce.upc"
      UPCR_PUT_SHARED_DOUBLEVAL_STRICT(_bupc_Mptra19, 0, (_IEEE64)(i));
#line 164 "doublereduce.upc"
      _1 :;
#line 164 "doublereduce.upc"
      i = i + 1;
    }
  }
#line 166 "doublereduce.upc"
  upcr_barrier(935481040, 1);
#line 167 "doublereduce.upc"
  initdoublereduce();
#line 168 "doublereduce.upc"
  i = 0;
#line 168 "doublereduce.upc"
  while(i <= 0)
#line 168 "doublereduce.upc"
  {
#line 170 "doublereduce.upc"
    _bupc_Mptra20 = UPCR_ADD_SHARED(input, 8ULL, ((int) upcr_mythread () ) * 100, 100ULL);
#line 170 "doublereduce.upc"
    _bupc_Mcvtptr21 = (_IEEE64 *) UPCR_SHARED_TO_LOCAL(_bupc_Mptra20);
#line 170 "doublereduce.upc"
    _bupc_comma = doublereduce(_bupc_Mcvtptr21, (int) 100);
#line 170 "doublereduce.upc"
    result = _bupc_comma;
#line 171 "doublereduce.upc"
    if(result != answer)
#line 171 "doublereduce.upc"
    {
#line 172 "doublereduce.upc"
      passed = 0;
    }
#line 174 "doublereduce.upc"
    _2 :;
#line 174 "doublereduce.upc"
    i = i + 1;
  }
#line 175 "doublereduce.upc"
  if(passed != 0)
#line 175 "doublereduce.upc"
  {
#line 176 "doublereduce.upc"
    printf("Passed\n");
  }
  else
#line 176 "doublereduce.upc"
  {
#line 178 "doublereduce.upc"
    printf("Failed\n");
  }
#line 180 "doublereduce.upc"
  UPCR_EXIT_FUNCTION();
#line 180 "doublereduce.upc"
  return 0;
} /* user_main */

#line 1 "_SYSTEM"
/**************************************************************************/
/* upcc-generated strings for configuration consistency checks            */

GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_GASNetConfig_gen, 
 "$GASNetConfig: (/tmp/upcc--17991-1460275610/doublereduce.trans.c) RELEASE=1.26.0,SPEC=1.8,CONDUIT=IBV(IBV-1.16/IBV-1.13),THREADMODEL=PAR,SEGMENT=FAST,PTR=64bit,noalign,nopshm,debug,trace,stats,debugmalloc,srclines,timers_native,membars_native,atomics_native,atomic32_native,atomic64_native $");
GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_UPCRConfig_gen,
 "$UPCRConfig: (/tmp/upcc--17991-1460275610/doublereduce.trans.c) VERSION=2.22.0,PLATFORMENV=shared-distributed,SHMEM=pthreads,SHAREDPTRREP=packed/p20:t10:a34,TRANS=berkeleyupc,debug,nogasp,notv,dynamicthreads $");
GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_translatetime, 
 "$UPCTranslateTime: (doublereduce.o) Sun Apr 10 01:06:50 2016 $");
GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_GASNetConfig_obj, 
 "$GASNetConfig: (doublereduce.o) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_UPCRConfig_obj,
 "$UPCRConfig: (doublereduce.o) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_translator, 
 "$UPCTranslator: (doublereduce.o) /usr/local/upc/2.22.0/translator/install/targ (aphid) $");
GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_upcver, 
 "$UPCVersion: (doublereduce.o) 2.22.0 $");
GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_compileline, 
 "$UPCCompileLine: (doublereduce.o) /usr/local/upc/2.22.0/runtime/inst/bin/upcc.pl --at-remote-http -translator=/usr/local/upc/2.22.0/translator/install/targ --arch-size=64 --network=ibv --pthreads 2 --lines --trans --sizes-file=upcc-sizes doublereduce.i $");
GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_compiletime, 
 "$UPCCompileTime: (doublereduce.o) " __DATE__ " " __TIME__ " $");
#ifndef UPCRI_CC /* ensure backward compatilibity for http netcompile */
#define UPCRI_CC <unknown>
#endif
GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_backendcompiler, 
 "$UPCRBackendCompiler: (doublereduce.o) " _STRINGIFY(UPCRI_CC) " $");

#ifdef GASNETT_CONFIGURE_MISMATCH
  GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_configuremismatch, 
   "$UPCRConfigureMismatch: (doublereduce.o) 1 $");
  GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_configuredcompiler, 
   "$UPCRConfigureCompiler: (doublereduce.o) " GASNETT_PLATFORM_COMPILER_IDSTR " $");
  GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_buildcompiler, 
   "$UPCRBuildCompiler: (doublereduce.o) " PLATFORM_COMPILER_IDSTR " $");
#endif

/**************************************************************************/
GASNETT_IDENT(UPCRI_IdentString_doublereduce_o_1460275610_transver_2,
 "$UPCTranslatorVersion: (doublereduce.o) 2.22.0, built on Oct 27 2015 at 17:48:24, host aphid linux-x86_64/64, gcc v4.2.4 (Ubuntu 4.2.4-1ubuntu4) $");
GASNETT_IDENT(UPCRI_IdentString_INIT_doublereduce_669514363622805199,"$UPCRInitFn: (doublereduce.trans.c) UPCRI_INIT_doublereduce_669514363622805199 $");
GASNETT_IDENT(UPCRI_IdentString_ALLOC_doublereduce_669514363622805199,"$UPCRAllocFn: (doublereduce.trans.c) UPCRI_ALLOC_doublereduce_669514363622805199 $");
