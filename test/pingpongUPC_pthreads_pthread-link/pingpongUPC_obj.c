/* --- UPCR system headers --- */ 
#include "upcr.h" 
#include "whirl2c.h"
#include "upcr_proxy.h"
/*******************************************************
 * C file translated from WHIRL Sun Apr 10 01:06:38 2016
 *******************************************************/

/* UPC Runtime specification expected: 3.6 */
#define UPCR_WANT_MAJOR 3
#define UPCR_WANT_MINOR 6
/* UPC translator version: release 2.22.0, built on Oct 27 2015 at 17:48:24, host aphid linux-x86_64/64, gcc v4.2.4 (Ubuntu 4.2.4-1ubuntu4) */
/* Included code from the initialization script */
#include</usr/local/berkeley_upc/opt/include/upcr_config.h>
#include</usr/local/berkeley_upc/opt/include/portable_platform.h>
#include "upcr_geninclude/stdlib.h"
#include "upcr_geninclude/stdio.h"
#include "upcr_geninclude/math.h"
#include</usr/local/berkeley_upc/opt/include/upcr_preinclude/upc_types.h>
#include "upcr_geninclude/stddef.h"
#include</usr/local/berkeley_upc/opt/include/upcr_preinclude/upc_bits.h>
#include "upcr_geninclude/stdlib.h"
#include "upcr_geninclude/inttypes.h"
#include</usr/include/x86_64-linux-gnu/sys/time.h>
#include "upcr_geninclude/inttypes.h"
#include</usr/include/unistd.h>
#line 1 "pingpongUPC.w2c.h"
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
static long mygetMicrosecondTimeStamp(void);

extern int user_main(int, char **);


#define UPCR_SHARED_SIZE_ 8
#define UPCR_PSHARED_SIZE_ 8
upcr_pshared_ptr_t d1S;
upcr_pshared_ptr_t d2S;
upcr_pshared_ptr_t r1SH;
upcr_pshared_ptr_t r2SH;
upcr_pshared_ptr_t r3SH;
upcr_pshared_ptr_t i1SH;
upcr_pshared_ptr_t i2SH;
upcr_pshared_ptr_t i3SH;

void UPCRI_ALLOC_pingpongUPC_17485257927008478918(void) { 
UPCR_BEGIN_FUNCTION();
upcr_startup_pshalloc_t _bupc_pinfo[] = { 
UPCRT_STARTUP_PSHALLOC(d1S, 8, 1, 1, 8, "A1H_R1_PR0_d"), 
UPCRT_STARTUP_PSHALLOC(d2S, 8, 1, 1, 8, "A1H_R1_PR0_d"), 
UPCRT_STARTUP_PSHALLOC(r1SH, 8, 1, 1, 8, "A1H_R1_d"), 
UPCRT_STARTUP_PSHALLOC(r2SH, 8, 1, 1, 8, "A1H_R1_d"), 
UPCRT_STARTUP_PSHALLOC(r3SH, 8, 1, 1, 8, "A1H_R1_d"), 
UPCRT_STARTUP_PSHALLOC(i1SH, 4, 1, 1, 4, "A1H_R1_i"), 
UPCRT_STARTUP_PSHALLOC(i2SH, 4, 1, 1, 4, "A1H_R1_i"), 
UPCRT_STARTUP_PSHALLOC(i3SH, 4, 1, 1, 4, "A1H_R1_i"), 
 };

UPCR_SET_SRCPOS("_pingpongUPC_17485257927008478918_ALLOC",0);
upcr_startup_pshalloc(_bupc_pinfo, sizeof(_bupc_pinfo) / sizeof(upcr_startup_pshalloc_t));
}

void UPCRI_INIT_pingpongUPC_17485257927008478918(void) { 
UPCR_BEGIN_FUNCTION();
UPCR_SET_SRCPOS("_pingpongUPC_17485257927008478918_INIT",0);
}

#line 25 "pingpongUPC.c"
static long mygetMicrosecondTimeStamp()
#line 25 "pingpongUPC.c"
{
#line 25 "pingpongUPC.c"
  UPCR_BEGIN_FUNCTION();
  register _INT32 _bupc_comma;
  struct timeval tv;
  int _bupc__spilleq0;
  long retval;
  
#line 28 "pingpongUPC.c"
  _bupc_comma = gettimeofday(&tv, (struct timezone *) 0ULL);
#line 28 "pingpongUPC.c"
  _bupc__spilleq0 = _bupc_comma;
#line 28 "pingpongUPC.c"
  if(_bupc__spilleq0 != 0)
#line 28 "pingpongUPC.c"
  {
#line 29 "pingpongUPC.c"
    perror("gettimeofday");
#line 30 "pingpongUPC.c"
    abort();
  }
#line 32 "pingpongUPC.c"
  retval = (tv).tv_usec + ((tv).tv_sec * 1000000LL);
#line 33 "pingpongUPC.c"
  UPCR_EXIT_FUNCTION();
#line 33 "pingpongUPC.c"
  return retval;
} /* mygetMicrosecondTimeStamp */


#line 57 "pingpongUPC.c"
extern int user_main(
  int argc,
  char ** argv)
#line 57 "pingpongUPC.c"
{
#line 57 "pingpongUPC.c"
  UPCR_BEGIN_FUNCTION();
  register _IEEE64 _bupc_comma;
  register _IEEE64 _bupc_comma0;
  register _INT32 _bupc_comma1;
  register _IEEE64 _bupc_comma2;
  register _IEEE64 _bupc_comma3;
  register _INT64 _bupc_comma4;
  register _IEEE64 _bupc_comma5;
  register _IEEE64 _bupc_comma6;
  register _IEEE64 _bupc_comma7;
  register _INT64 _bupc_comma8;
  register _INT64 _bupc_comma9;
  register _IEEE64 _bupc_comma10;
  register _INT64 _bupc_comma11;
  register _INT64 _bupc_comma12;
  register _IEEE64 _bupc_comma13;
  register _INT64 _bupc_comma14;
  register _INT64 _bupc_comma15;
  register _IEEE64 _bupc_comma16;
  register _INT64 _bupc_comma17;
  register _INT64 _bupc_comma18;
  int npes;
  int mypn;
  _IEEE64 rnpes;
  _IEEE64 minMB;
  _IEEE64 maxMB;
  int incMB;
  _IEEE64 rl1;
  _IEEE64 rl2;
  _IEEE64 drl;
  _IEEE64 rnum;
  int num;
  _IEEE64 * d1;
  _IEEE64 * d2;
  long long t2;
  int j;
  int i;
  int ifromLR[200LL];
  int itooLR[200LL];
  int m;
  _IEEE64 rrr;
  _IEEE64 val;
  int k;
  char fname[20LL];
  struct _IO_FILE * fp;
  int itest;
  _IEEE64 rl;
  _IEEE64 ri;
  long long t1;
  long long tt;
  _IEEE64 totalT;
  _IEEE64 tmin;
  _IEEE64 tmax;
  _IEEE64 tavg;
  int ip;
  _IEEE64 tavg2;
  _IEEE64 tmin2;
  _IEEE64 tmax2;
  upcr_shared_ptr_t _bupc_call0;
  upcr_shared_ptr_t _bupc_call1;
  struct _IO_FILE * _bupc_call2;
  struct _IO_FILE * _bupc_call3;
  struct _IO_FILE * _bupc_call4;
  struct _IO_FILE * _bupc_call5;
  upcr_pshared_ptr_t _bupc_Mptra6;
  upcr_pshared_ptr_t _bupc_Mptra7;
  upcr_pshared_ptr_t _bupc_Mptra8;
  _IEEE64 _bupc_spillld9;
  _IEEE64 _bupc_spillld10;
  int _bupc_spillld11;
  upcr_pshared_ptr_t _bupc_Mstopcvt12;
  upcr_pshared_ptr_t _bupc_Mptra13;
  upcr_pshared_ptr_t _bupc_Mstopcvt14;
  upcr_pshared_ptr_t _bupc_Mptra15;
  upcr_pshared_ptr_t _bupc_Mptra16;
  upcr_pshared_ptr_t _bupc_spillld17;
  _IEEE64 * _bupc_Mcvtptr18;
  upcr_pshared_ptr_t _bupc_Mptra19;
  upcr_pshared_ptr_t _bupc_spillld20;
  _IEEE64 * _bupc_Mcvtptr21;
  upcr_pshared_ptr_t _bupc_Mptra22;
  upcr_pshared_ptr_t _bupc_spillld23;
  upcr_pshared_ptr_t _bupc_Mptra24;
  _IEEE64 _bupc_spillld25;
  upcr_pshared_ptr_t _bupc_Mptra26;
  upcr_pshared_ptr_t _bupc_spillld27;
  upcr_pshared_ptr_t _bupc_Mptra28;
  _IEEE64 _bupc_spillld29;
  upcr_pshared_ptr_t _bupc_Mptra30;
  upcr_pshared_ptr_t _bupc_spillld31;
  upcr_pshared_ptr_t _bupc_Mptra32;
  _IEEE64 _bupc_spillld33;
  upcr_pshared_ptr_t _bupc_Mptra34;
  upcr_pshared_ptr_t _bupc_Mptra35;
  _IEEE64 _bupc_spillld36;
  upcr_pshared_ptr_t _bupc_Mptra37;
  _IEEE64 _bupc_spillld38;
  upcr_pshared_ptr_t _bupc_Mptra39;
  _IEEE64 _bupc_spillld40;
  upcr_pshared_ptr_t _bupc_Mptra41;
  _IEEE64 _bupc_spillld42;
  upcr_pshared_ptr_t _bupc_Mptra43;
  _IEEE64 _bupc_spillld44;
  upcr_pshared_ptr_t _bupc_Mptra45;
  upcr_pshared_ptr_t _bupc_spillld46;
  upcr_pshared_ptr_t _bupc_Mptra47;
  _IEEE64 _bupc_spillstoreparm48;
  upcr_pshared_ptr_t _bupc_Mptra49;
  upcr_pshared_ptr_t _bupc_spillld50;
  upcr_pshared_ptr_t _bupc_Mptra51;
  _IEEE64 _bupc_spillstoreparm52;
  upcr_pshared_ptr_t _bupc_Mptra53;
  upcr_pshared_ptr_t _bupc_Mptra54;
  _IEEE64 _bupc_spillld55;
  upcr_pshared_ptr_t _bupc_Mptra56;
  _IEEE64 _bupc_spillld57;
  upcr_pshared_ptr_t _bupc_Mptra58;
  _IEEE64 _bupc_spillld59;
  upcr_pshared_ptr_t _bupc_Mptra60;
  _IEEE64 _bupc_spillld61;
  upcr_pshared_ptr_t _bupc_Mptra62;
  _IEEE64 _bupc_spillld63;
  upcr_pshared_ptr_t _bupc_Mptra64;
  upcr_pshared_ptr_t _bupc_spillld65;
  upcr_pshared_ptr_t _bupc_Mptra66;
  _IEEE64 _bupc_spillld67;
  upcr_pshared_ptr_t _bupc_Mptra68;
  upcr_pshared_ptr_t _bupc_spillld69;
  upcr_pshared_ptr_t _bupc_Mptra70;
  _IEEE64 _bupc_spillld71;
  upcr_pshared_ptr_t _bupc_Mptra72;
  upcr_pshared_ptr_t _bupc_Mptra73;
  _IEEE64 _bupc_spillld74;
  upcr_pshared_ptr_t _bupc_Mptra75;
  _IEEE64 _bupc_spillld76;
  upcr_pshared_ptr_t _bupc_Mptra77;
  _IEEE64 _bupc_spillld78;
  upcr_pshared_ptr_t _bupc_Mptra79;
  _IEEE64 _bupc_spillld80;
  upcr_pshared_ptr_t _bupc_Mptra81;
  _IEEE64 _bupc_spillld82;
  upcr_pshared_ptr_t _bupc_Mptra83;
  upcr_pshared_ptr_t _bupc_spillld84;
  upcr_pshared_ptr_t _bupc_Mptra85;
  _IEEE64 _bupc_spillstoreparm86;
  upcr_pshared_ptr_t _bupc_Mptra87;
  upcr_pshared_ptr_t _bupc_spillld88;
  upcr_pshared_ptr_t _bupc_Mptra89;
  _IEEE64 _bupc_spillstoreparm90;
  upcr_pshared_ptr_t _bupc_Mptra91;
  upcr_pshared_ptr_t _bupc_Mptra92;
  _IEEE64 _bupc_spillld93;
  upcr_pshared_ptr_t _bupc_Mptra94;
  _IEEE64 _bupc_spillld95;
  upcr_pshared_ptr_t _bupc_Mptra96;
  _IEEE64 _bupc_spillld97;
  upcr_pshared_ptr_t _bupc_Mptra98;
  _IEEE64 _bupc_spillld99;
  upcr_pshared_ptr_t _bupc_Mptra100;
  _IEEE64 _bupc_spillld101;
  
#line 59 "pingpongUPC.c"
  sleep((unsigned int) 40U);
#line 69 "pingpongUPC.c"
  npes = ((int) upcr_threads () );
#line 70 "pingpongUPC.c"
  mypn = ((int) upcr_mythread () );
#line 72 "pingpongUPC.c"
  rnpes = (_IEEE64)(npes);
#line 74 "pingpongUPC.c"
  upcr_barrier(-1720949050, 1);
#line 76 "pingpongUPC.c"
  if(mypn == 0)
#line 76 "pingpongUPC.c"
  {
#line 82 "pingpongUPC.c"
    if(argc > 1)
#line 82 "pingpongUPC.c"
    {
#line 82 "pingpongUPC.c"
      _bupc_comma = atof((const char *) * (argv + 1LL));
#line 82 "pingpongUPC.c"
      minMB = _bupc_comma;
    }
    else
#line 82 "pingpongUPC.c"
    {
#line 83 "pingpongUPC.c"
      minMB = 0.0001;
    }
#line 84 "pingpongUPC.c"
    if(argc > 2)
#line 84 "pingpongUPC.c"
    {
#line 84 "pingpongUPC.c"
      _bupc_comma0 = atof((const char *) * (argv + 2LL));
#line 84 "pingpongUPC.c"
      maxMB = _bupc_comma0;
    }
    else
#line 84 "pingpongUPC.c"
    {
#line 85 "pingpongUPC.c"
      maxMB = 100.0;
    }
#line 86 "pingpongUPC.c"
    if(argc > 3)
#line 86 "pingpongUPC.c"
    {
#line 86 "pingpongUPC.c"
      _bupc_comma1 = atoi((const char *) * (argv + 3LL));
#line 86 "pingpongUPC.c"
      incMB = _bupc_comma1;
    }
    else
#line 86 "pingpongUPC.c"
    {
#line 87 "pingpongUPC.c"
      incMB = 50;
    }
#line 89 "pingpongUPC.c"
    printf("MINIMUM MB ARRAY SIZE: %f\n", minMB);
#line 90 "pingpongUPC.c"
    printf("MAXIMUM MB ARRAY SIZE: %f\n", maxMB);
#line 91 "pingpongUPC.c"
    printf("NUMBER OF TESTS: %i\n", incMB);
#line 93 "pingpongUPC.c"
    _bupc_Mptra6 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ((int) upcr_mythread () ));
#line 93 "pingpongUPC.c"
    UPCR_PUT_PSHARED(_bupc_Mptra6, 0, &minMB, 8);
#line 94 "pingpongUPC.c"
    _bupc_Mptra7 = UPCR_ADD_PSHARED1(r2SH, 8ULL, ((int) upcr_mythread () ));
#line 94 "pingpongUPC.c"
    UPCR_PUT_PSHARED(_bupc_Mptra7, 0, &maxMB, 8);
#line 95 "pingpongUPC.c"
    _bupc_Mptra8 = UPCR_ADD_PSHARED1(i1SH, 4ULL, ((int) upcr_mythread () ));
#line 95 "pingpongUPC.c"
    UPCR_PUT_PSHARED_VAL(_bupc_Mptra8, 0, incMB, 4);
  }
#line 97 "pingpongUPC.c"
  upcr_barrier(-1720949049, 1);
#line 99 "pingpongUPC.c"
  if(mypn != 0)
#line 99 "pingpongUPC.c"
  {
#line 100 "pingpongUPC.c"
    _bupc_spillld9 = UPCR_GET_PSHARED_DOUBLEVAL(r1SH, 0);
#line 100 "pingpongUPC.c"
    minMB = _bupc_spillld9;
#line 101 "pingpongUPC.c"
    _bupc_spillld10 = UPCR_GET_PSHARED_DOUBLEVAL(r2SH, 0);
#line 101 "pingpongUPC.c"
    maxMB = _bupc_spillld10;
#line 102 "pingpongUPC.c"
    UPCR_GET_PSHARED(&_bupc_spillld11, i1SH, 0, 4);
#line 102 "pingpongUPC.c"
    incMB = _bupc_spillld11;
  }
#line 104 "pingpongUPC.c"
  upcr_barrier(-1720949048, 1);
#line 106 "pingpongUPC.c"
  _bupc_comma2 = log10(minMB);
#line 106 "pingpongUPC.c"
  rl1 = _bupc_comma2;
#line 107 "pingpongUPC.c"
  _bupc_comma3 = log10(maxMB);
#line 107 "pingpongUPC.c"
  rl2 = _bupc_comma3;
#line 108 "pingpongUPC.c"
  drl = (rl2 - rl1) / (_IEEE64)((incMB + -1));
#line 110 "pingpongUPC.c"
  rnum = ((maxMB * 1e+06) * 0.125) + 0.5;
#line 111 "pingpongUPC.c"
  num = _I4F8TRUNC(rnum);
#line 115 "pingpongUPC.c"
  upcr_barrier(-1720949047, 1);
#line 116 "pingpongUPC.c"
  _bupc_call0 = upc_alloc((unsigned long)(((_UINT64)(num) * 8ULL) + 8000ULL));
#line 116 "pingpongUPC.c"
  _bupc_Mptra13 = UPCR_ADD_PSHARED1(d1S, 8ULL, ((int) upcr_mythread () ));
#line 116 "pingpongUPC.c"
  _bupc_Mstopcvt12 = UPCR_SHARED_TO_PSHARED(_bupc_call0);
#line 116 "pingpongUPC.c"
  UPCR_PUT_PSHARED_VAL(_bupc_Mptra13, 0, _bupc_Mstopcvt12, 8);
#line 117 "pingpongUPC.c"
  _bupc_call1 = upc_alloc((unsigned long)(((_UINT64)(num) * 8ULL) + 8000ULL));
#line 117 "pingpongUPC.c"
  _bupc_Mptra15 = UPCR_ADD_PSHARED1(d2S, 8ULL, ((int) upcr_mythread () ));
#line 117 "pingpongUPC.c"
  _bupc_Mstopcvt14 = UPCR_SHARED_TO_PSHARED(_bupc_call1);
#line 117 "pingpongUPC.c"
  UPCR_PUT_PSHARED_VAL(_bupc_Mptra15, 0, _bupc_Mstopcvt14, 8);
#line 118 "pingpongUPC.c"
  upcr_barrier(-1720949046, 1);
#line 120 "pingpongUPC.c"
  _bupc_Mptra16 = UPCR_ADD_PSHARED1(d1S, 8ULL, ((int) upcr_mythread () ));
#line 120 "pingpongUPC.c"
  UPCR_GET_PSHARED(&_bupc_spillld17, _bupc_Mptra16, 0, 8);
#line 120 "pingpongUPC.c"
  _bupc_Mcvtptr18 = (_IEEE64 *) UPCR_PSHARED_TO_LOCAL(_bupc_spillld17);
#line 120 "pingpongUPC.c"
  d1 = _bupc_Mcvtptr18;
#line 121 "pingpongUPC.c"
  _bupc_Mptra19 = UPCR_ADD_PSHARED1(d2S, 8ULL, ((int) upcr_mythread () ));
#line 121 "pingpongUPC.c"
  UPCR_GET_PSHARED(&_bupc_spillld20, _bupc_Mptra19, 0, 8);
#line 121 "pingpongUPC.c"
  _bupc_Mcvtptr21 = (_IEEE64 *) UPCR_PSHARED_TO_LOCAL(_bupc_spillld20);
#line 121 "pingpongUPC.c"
  d2 = _bupc_Mcvtptr21;
#line 123 "pingpongUPC.c"
  _bupc_comma4 = mygetMicrosecondTimeStamp();
#line 123 "pingpongUPC.c"
  t2 = _bupc_comma4;
#line 129 "pingpongUPC.c"
  srand48((long)((mypn * 10) + 1234));
#line 130 "pingpongUPC.c"
  j = 0;
#line 130 "pingpongUPC.c"
  i = j;
#line 130 "pingpongUPC.c"
  while(i < npes)
#line 130 "pingpongUPC.c"
  {
#line 131 "pingpongUPC.c"
    if(i != mypn)
#line 131 "pingpongUPC.c"
    {
#line 132 "pingpongUPC.c"
      (ifromLR)[j] = i;
#line 132 "pingpongUPC.c"
      (itooLR)[j] = (ifromLR)[j];
#line 133 "pingpongUPC.c"
      j = j + 1;
    }
#line 135 "pingpongUPC.c"
    _1 :;
#line 135 "pingpongUPC.c"
    i = i + 1;
  }
#line 136 "pingpongUPC.c"
  m = 0;
#line 136 "pingpongUPC.c"
  while(m <= 99)
#line 136 "pingpongUPC.c"
  {
#line 137 "pingpongUPC.c"
    i = 0;
#line 137 "pingpongUPC.c"
    while(i < (npes + -1))
#line 137 "pingpongUPC.c"
    {
#line 138 "pingpongUPC.c"
      _bupc_comma5 = drand48();
#line 138 "pingpongUPC.c"
      rrr = _bupc_comma5;
#line 139 "pingpongUPC.c"
      val = ((((_IEEE64)(npes) + -1.0e+0) + -2e-09) * rrr) + 1e-09;
#line 140 "pingpongUPC.c"
      j = _I4F8TRUNC(val);
#line 141 "pingpongUPC.c"
      if((_INT32)((j < 0)) || (_INT32)((j >= (npes + -1))))
#line 141 "pingpongUPC.c"
      {
#line 141 "pingpongUPC.c"
        j = 1;
      }
#line 142 "pingpongUPC.c"
      k = (itooLR)[i];
#line 143 "pingpongUPC.c"
      (itooLR)[i] = (itooLR)[j];
#line 144 "pingpongUPC.c"
      (itooLR)[j] = k;
#line 146 "pingpongUPC.c"
      _bupc_comma6 = drand48();
#line 146 "pingpongUPC.c"
      rrr = _bupc_comma6;
#line 147 "pingpongUPC.c"
      val = ((((_IEEE64)(npes) + -1.0e+0) + -2e-09) * rrr) + 1e-09;
#line 148 "pingpongUPC.c"
      j = _I4F8TRUNC(val);
#line 149 "pingpongUPC.c"
      if((_INT32)((j < 0)) || (_INT32)((j >= (npes + -1))))
#line 149 "pingpongUPC.c"
      {
#line 149 "pingpongUPC.c"
        j = 1;
      }
#line 150 "pingpongUPC.c"
      k = (ifromLR)[i];
#line 151 "pingpongUPC.c"
      (ifromLR)[i] = (ifromLR)[j];
#line 152 "pingpongUPC.c"
      (ifromLR)[j] = k;
#line 153 "pingpongUPC.c"
      _3 :;
#line 153 "pingpongUPC.c"
      i = i + 1;
    }
#line 154 "pingpongUPC.c"
    _2 :;
#line 154 "pingpongUPC.c"
    m = m + 1;
  }
#line 155 "pingpongUPC.c"
  upcr_barrier(-1720949045, 1);
#line 159 "pingpongUPC.c"
  i = 0;
#line 159 "pingpongUPC.c"
  while(i < (npes + -1))
#line 159 "pingpongUPC.c"
  {
#line 160 "pingpongUPC.c"
    if((itooLR)[i] == mypn)
#line 160 "pingpongUPC.c"
    {
#line 161 "pingpongUPC.c"
      printf("ERROR 1\n");
#line 162 "pingpongUPC.c"
      upcri_do_exit((int) 1);
    }
#line 164 "pingpongUPC.c"
    if((ifromLR)[i] == mypn)
#line 164 "pingpongUPC.c"
    {
#line 165 "pingpongUPC.c"
      printf("ERROR 2\n");
#line 166 "pingpongUPC.c"
      upcri_do_exit((int) 1);
    }
#line 168 "pingpongUPC.c"
    _4 :;
#line 168 "pingpongUPC.c"
    i = i + 1;
  }
#line 169 "pingpongUPC.c"
  i = 0;
#line 169 "pingpongUPC.c"
  while(i < (npes + -2))
#line 169 "pingpongUPC.c"
  {
#line 170 "pingpongUPC.c"
    j = i + 1;
#line 170 "pingpongUPC.c"
    while(j < (npes + -1))
#line 170 "pingpongUPC.c"
    {
#line 171 "pingpongUPC.c"
      if((itooLR)[i] == (itooLR)[j])
#line 171 "pingpongUPC.c"
      {
#line 172 "pingpongUPC.c"
        printf("ERROR 3\n");
#line 173 "pingpongUPC.c"
        upcri_do_exit((int) 1);
      }
#line 175 "pingpongUPC.c"
      if((ifromLR)[i] == (ifromLR)[j])
#line 175 "pingpongUPC.c"
      {
#line 176 "pingpongUPC.c"
        printf("ERROR 4\n");
#line 177 "pingpongUPC.c"
        upcri_do_exit((int) 1);
      }
#line 179 "pingpongUPC.c"
      _6 :;
#line 179 "pingpongUPC.c"
      j = j + 1;
    }
#line 180 "pingpongUPC.c"
    _5 :;
#line 180 "pingpongUPC.c"
    i = i + 1;
  }
#line 184 "pingpongUPC.c"
  if(mypn == 0)
#line 184 "pingpongUPC.c"
  {
#line 185 "pingpongUPC.c"
    sprintf(fname, "outUPC-G-%03d.txt", npes);
#line 189 "pingpongUPC.c"
    _bupc_call2 = fopen(fname, "w");
#line 189 "pingpongUPC.c"
    fp = _bupc_call2;
  }
#line 192 "pingpongUPC.c"
  itest = 0;
#line 193 "pingpongUPC.c"
  rl = rl1;
#line 193 "pingpongUPC.c"
  while(rl <= rl2)
#line 193 "pingpongUPC.c"
  {
#line 194 "pingpongUPC.c"
    _bupc_comma7 = pow(10.0, rl);
#line 194 "pingpongUPC.c"
    ri = ((_bupc_comma7 * 1e+06) * 0.125) + 0.5;
#line 195 "pingpongUPC.c"
    num = _I4F8TRUNC(ri);
#line 196 "pingpongUPC.c"
    ri = ((_IEEE64)(num) * 8.0) / 1e+06;
#line 198 "pingpongUPC.c"
    j = 0;
#line 198 "pingpongUPC.c"
    while(j < num)
#line 198 "pingpongUPC.c"
    {
#line 199 "pingpongUPC.c"
      * (d1 + j) = (_IEEE64)(j);
#line 200 "pingpongUPC.c"
      _8 :;
#line 200 "pingpongUPC.c"
      j = j + 1;
    }
#line 201 "pingpongUPC.c"
    upcr_barrier(-1720949044, 1);
#line 203 "pingpongUPC.c"
    i = 0;
#line 203 "pingpongUPC.c"
    while(i < (npes + -1))
#line 203 "pingpongUPC.c"
    {
#line 204 "pingpongUPC.c"
      j = 0;
#line 204 "pingpongUPC.c"
      while(j < num)
#line 204 "pingpongUPC.c"
      {
#line 205 "pingpongUPC.c"
        _bupc_Mptra22 = UPCR_ADD_PSHARED1(d1S, 8ULL, (ifromLR)[i]);
#line 205 "pingpongUPC.c"
        UPCR_GET_PSHARED(&_bupc_spillld23, _bupc_Mptra22, 0, 8);
#line 205 "pingpongUPC.c"
        _bupc_Mptra24 = UPCR_ADD_PSHAREDI(_bupc_spillld23, 8ULL, j);
#line 205 "pingpongUPC.c"
        _bupc_spillld25 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra24, 0);
#line 205 "pingpongUPC.c"
        * (d2 + j) = _bupc_spillld25;
#line 206 "pingpongUPC.c"
        _10 :;
#line 206 "pingpongUPC.c"
        j = j + 1;
      }
#line 207 "pingpongUPC.c"
      _9 :;
#line 207 "pingpongUPC.c"
      i = i + 1;
    }
#line 208 "pingpongUPC.c"
    upcr_barrier(-1720949043, 1);
#line 212 "pingpongUPC.c"
    if(itest == 0)
#line 212 "pingpongUPC.c"
    {
#line 213 "pingpongUPC.c"
      k = 1;
#line 213 "pingpongUPC.c"
      while(k <= 3)
#line 213 "pingpongUPC.c"
      {
#line 214 "pingpongUPC.c"
        i = 0;
#line 214 "pingpongUPC.c"
        while(i < (npes + -1))
#line 214 "pingpongUPC.c"
        {
#line 218 "pingpongUPC.c"
          j = 0;
#line 218 "pingpongUPC.c"
          while(j < num)
#line 218 "pingpongUPC.c"
          {
#line 219 "pingpongUPC.c"
            _bupc_Mptra26 = UPCR_ADD_PSHARED1(d1S, 8ULL, (ifromLR)[i]);
#line 219 "pingpongUPC.c"
            UPCR_GET_PSHARED(&_bupc_spillld27, _bupc_Mptra26, 0, 8);
#line 219 "pingpongUPC.c"
            _bupc_Mptra28 = UPCR_ADD_PSHAREDI(_bupc_spillld27, 8ULL, j);
#line 219 "pingpongUPC.c"
            _bupc_spillld29 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra28, 0);
#line 219 "pingpongUPC.c"
            * (d2 + j) = _bupc_spillld29;
#line 220 "pingpongUPC.c"
            _13 :;
#line 220 "pingpongUPC.c"
            j = j + 1;
          }
#line 221 "pingpongUPC.c"
          _12 :;
#line 221 "pingpongUPC.c"
          i = i + 1;
        }
#line 222 "pingpongUPC.c"
        _11 :;
#line 222 "pingpongUPC.c"
        k = k + 1;
      }
#line 223 "pingpongUPC.c"
      itest = 1;
    }
#line 225 "pingpongUPC.c"
    upcr_barrier(-1720949042, 1);
#line 226 "pingpongUPC.c"
    _bupc_comma8 = mygetMicrosecondTimeStamp();
#line 226 "pingpongUPC.c"
    t1 = _bupc_comma8;
#line 228 "pingpongUPC.c"
    i = 0;
#line 228 "pingpongUPC.c"
    while(i < (npes + -1))
#line 228 "pingpongUPC.c"
    {
#line 232 "pingpongUPC.c"
      j = 0;
#line 232 "pingpongUPC.c"
      while(j < num)
#line 232 "pingpongUPC.c"
      {
#line 233 "pingpongUPC.c"
        _bupc_Mptra30 = UPCR_ADD_PSHARED1(d1S, 8ULL, (ifromLR)[i]);
#line 233 "pingpongUPC.c"
        UPCR_GET_PSHARED(&_bupc_spillld31, _bupc_Mptra30, 0, 8);
#line 233 "pingpongUPC.c"
        _bupc_Mptra32 = UPCR_ADD_PSHAREDI(_bupc_spillld31, 8ULL, j);
#line 233 "pingpongUPC.c"
        _bupc_spillld33 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra32, 0);
#line 233 "pingpongUPC.c"
        * (d2 + j) = _bupc_spillld33;
#line 234 "pingpongUPC.c"
        _15 :;
#line 234 "pingpongUPC.c"
        j = j + 1;
      }
#line 235 "pingpongUPC.c"
      _14 :;
#line 235 "pingpongUPC.c"
      i = i + 1;
    }
#line 237 "pingpongUPC.c"
    _bupc_comma9 = mygetMicrosecondTimeStamp();
#line 237 "pingpongUPC.c"
    t2 = _bupc_comma9;
#line 238 "pingpongUPC.c"
    tt = t2 - t1;
#line 239 "pingpongUPC.c"
    totalT = (_IEEE64)(tt) / 1e+06;
#line 240 "pingpongUPC.c"
    upcr_barrier(-1720949041, 1);
#line 242 "pingpongUPC.c"
    _bupc_Mptra34 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ((int) upcr_mythread () ));
#line 242 "pingpongUPC.c"
    UPCR_PUT_PSHARED(_bupc_Mptra34, 0, &totalT, 8);
#line 244 "pingpongUPC.c"
    upcr_barrier(-1720949040, 1);
#line 246 "pingpongUPC.c"
    if(mypn == 0)
#line 246 "pingpongUPC.c"
    {
#line 247 "pingpongUPC.c"
      tmin = totalT;
#line 248 "pingpongUPC.c"
      tmax = totalT;
#line 249 "pingpongUPC.c"
      tavg = totalT;
#line 250 "pingpongUPC.c"
      ip = 1;
#line 250 "pingpongUPC.c"
      while(ip < npes)
#line 250 "pingpongUPC.c"
      {
#line 251 "pingpongUPC.c"
        _bupc_Mptra35 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 251 "pingpongUPC.c"
        _bupc_spillld36 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra35, 0);
#line 251 "pingpongUPC.c"
        if(_bupc_spillld36 < tmin)
#line 251 "pingpongUPC.c"
        {
#line 251 "pingpongUPC.c"
          _bupc_Mptra37 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 251 "pingpongUPC.c"
          _bupc_spillld38 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra37, 0);
#line 251 "pingpongUPC.c"
          tmin = _bupc_spillld38;
        }
#line 252 "pingpongUPC.c"
        _bupc_Mptra39 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 252 "pingpongUPC.c"
        _bupc_spillld40 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra39, 0);
#line 252 "pingpongUPC.c"
        if(_bupc_spillld40 > tmax)
#line 252 "pingpongUPC.c"
        {
#line 252 "pingpongUPC.c"
          _bupc_Mptra41 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 252 "pingpongUPC.c"
          _bupc_spillld42 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra41, 0);
#line 252 "pingpongUPC.c"
          tmax = _bupc_spillld42;
        }
#line 253 "pingpongUPC.c"
        _bupc_Mptra43 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 253 "pingpongUPC.c"
        _bupc_spillld44 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra43, 0);
#line 253 "pingpongUPC.c"
        tavg = tavg + _bupc_spillld44;
#line 254 "pingpongUPC.c"
        _16 :;
#line 254 "pingpongUPC.c"
        ip = ip + 1;
      }
#line 255 "pingpongUPC.c"
      tavg = tavg / rnpes;
#line 257 "pingpongUPC.c"
      tavg2 = tavg / (rnpes + -1.0e+0);
#line 258 "pingpongUPC.c"
      tmin2 = tmin / (rnpes + -1.0e+0);
#line 259 "pingpongUPC.c"
      tmax2 = tmax / (rnpes + -1.0e+0);
#line 260 "pingpongUPC.c"
      fprintf(fp, "%20.13lf  %20.13lf  %20.13lf\n", ri, tavg, tavg2);
    }
#line 262 "pingpongUPC.c"
    _7 :;
#line 262 "pingpongUPC.c"
    rl = rl + drl;
  }
#line 263 "pingpongUPC.c"
  if((_INT32)((mypn == 0)) && (_INT32)(((_UINT64)(fp) != (_UINT64)(stdout))))
#line 263 "pingpongUPC.c"
  {
#line 263 "pingpongUPC.c"
    fclose(fp);
  }
#line 267 "pingpongUPC.c"
  if(mypn == 0)
#line 267 "pingpongUPC.c"
  {
#line 268 "pingpongUPC.c"
    sprintf(fname, "outUPC-P-%03d.txt", npes);
#line 272 "pingpongUPC.c"
    _bupc_call3 = fopen(fname, "w");
#line 272 "pingpongUPC.c"
    fp = _bupc_call3;
  }
#line 275 "pingpongUPC.c"
  itest = 0;
#line 276 "pingpongUPC.c"
  rl = rl1;
#line 276 "pingpongUPC.c"
  while(rl <= rl2)
#line 276 "pingpongUPC.c"
  {
#line 277 "pingpongUPC.c"
    _bupc_comma10 = pow(10.0, rl);
#line 277 "pingpongUPC.c"
    ri = ((_bupc_comma10 * 1e+06) * 0.125) + 0.5;
#line 278 "pingpongUPC.c"
    num = _I4F8TRUNC(ri);
#line 279 "pingpongUPC.c"
    ri = ((_IEEE64)(num) * 8.0) / 1e+06;
#line 281 "pingpongUPC.c"
    j = 0;
#line 281 "pingpongUPC.c"
    while(j < num)
#line 281 "pingpongUPC.c"
    {
#line 282 "pingpongUPC.c"
      * (d1 + j) = (_IEEE64)(j);
#line 283 "pingpongUPC.c"
      _18 :;
#line 283 "pingpongUPC.c"
      j = j + 1;
    }
#line 284 "pingpongUPC.c"
    upcr_barrier(-1720949039, 1);
#line 286 "pingpongUPC.c"
    if(itest == 0)
#line 286 "pingpongUPC.c"
    {
#line 287 "pingpongUPC.c"
      k = 1;
#line 287 "pingpongUPC.c"
      while(k <= 3)
#line 287 "pingpongUPC.c"
      {
#line 288 "pingpongUPC.c"
        i = 0;
#line 288 "pingpongUPC.c"
        while(i < (npes + -1))
#line 288 "pingpongUPC.c"
        {
#line 292 "pingpongUPC.c"
          j = 0;
#line 292 "pingpongUPC.c"
          while(j < num)
#line 292 "pingpongUPC.c"
          {
#line 293 "pingpongUPC.c"
            _bupc_Mptra45 = UPCR_ADD_PSHARED1(d2S, 8ULL, (itooLR)[i]);
#line 293 "pingpongUPC.c"
            UPCR_GET_PSHARED(&_bupc_spillld46, _bupc_Mptra45, 0, 8);
#line 293 "pingpongUPC.c"
            _bupc_Mptra47 = UPCR_ADD_PSHAREDI(_bupc_spillld46, 8ULL, j);
            _bupc_spillstoreparm48 = *(d1 + j);
#line 293 "pingpongUPC.c"
            UPCR_PUT_PSHARED(_bupc_Mptra47, 0, &_bupc_spillstoreparm48, 8);
#line 294 "pingpongUPC.c"
            _21 :;
#line 294 "pingpongUPC.c"
            j = j + 1;
          }
#line 295 "pingpongUPC.c"
          _20 :;
#line 295 "pingpongUPC.c"
          i = i + 1;
        }
#line 296 "pingpongUPC.c"
        _19 :;
#line 296 "pingpongUPC.c"
        k = k + 1;
      }
#line 297 "pingpongUPC.c"
      itest = 1;
    }
#line 299 "pingpongUPC.c"
    upcr_barrier(-1720949038, 1);
#line 300 "pingpongUPC.c"
    _bupc_comma11 = mygetMicrosecondTimeStamp();
#line 300 "pingpongUPC.c"
    t1 = _bupc_comma11;
#line 302 "pingpongUPC.c"
    i = 0;
#line 302 "pingpongUPC.c"
    while(i < (npes + -1))
#line 302 "pingpongUPC.c"
    {
#line 306 "pingpongUPC.c"
      j = 0;
#line 306 "pingpongUPC.c"
      while(j < num)
#line 306 "pingpongUPC.c"
      {
#line 307 "pingpongUPC.c"
        _bupc_Mptra49 = UPCR_ADD_PSHARED1(d2S, 8ULL, (itooLR)[i]);
#line 307 "pingpongUPC.c"
        UPCR_GET_PSHARED(&_bupc_spillld50, _bupc_Mptra49, 0, 8);
#line 307 "pingpongUPC.c"
        _bupc_Mptra51 = UPCR_ADD_PSHAREDI(_bupc_spillld50, 8ULL, j);
        _bupc_spillstoreparm52 = *(d1 + j);
#line 307 "pingpongUPC.c"
        UPCR_PUT_PSHARED(_bupc_Mptra51, 0, &_bupc_spillstoreparm52, 8);
#line 308 "pingpongUPC.c"
        _23 :;
#line 308 "pingpongUPC.c"
        j = j + 1;
      }
#line 309 "pingpongUPC.c"
      _22 :;
#line 309 "pingpongUPC.c"
      i = i + 1;
    }
#line 311 "pingpongUPC.c"
    _bupc_comma12 = mygetMicrosecondTimeStamp();
#line 311 "pingpongUPC.c"
    t2 = _bupc_comma12;
#line 312 "pingpongUPC.c"
    tt = t2 - t1;
#line 313 "pingpongUPC.c"
    totalT = (_IEEE64)(tt) / 1e+06;
#line 314 "pingpongUPC.c"
    upcr_barrier(-1720949037, 1);
#line 316 "pingpongUPC.c"
    _bupc_Mptra53 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ((int) upcr_mythread () ));
#line 316 "pingpongUPC.c"
    UPCR_PUT_PSHARED(_bupc_Mptra53, 0, &totalT, 8);
#line 318 "pingpongUPC.c"
    upcr_barrier(-1720949036, 1);
#line 320 "pingpongUPC.c"
    if(mypn == 0)
#line 320 "pingpongUPC.c"
    {
#line 321 "pingpongUPC.c"
      tmin = totalT;
#line 322 "pingpongUPC.c"
      tmax = totalT;
#line 323 "pingpongUPC.c"
      tavg = totalT;
#line 324 "pingpongUPC.c"
      ip = 1;
#line 324 "pingpongUPC.c"
      while(ip < npes)
#line 324 "pingpongUPC.c"
      {
#line 325 "pingpongUPC.c"
        _bupc_Mptra54 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 325 "pingpongUPC.c"
        _bupc_spillld55 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra54, 0);
#line 325 "pingpongUPC.c"
        if(_bupc_spillld55 < tmin)
#line 325 "pingpongUPC.c"
        {
#line 325 "pingpongUPC.c"
          _bupc_Mptra56 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 325 "pingpongUPC.c"
          _bupc_spillld57 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra56, 0);
#line 325 "pingpongUPC.c"
          tmin = _bupc_spillld57;
        }
#line 326 "pingpongUPC.c"
        _bupc_Mptra58 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 326 "pingpongUPC.c"
        _bupc_spillld59 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra58, 0);
#line 326 "pingpongUPC.c"
        if(_bupc_spillld59 > tmax)
#line 326 "pingpongUPC.c"
        {
#line 326 "pingpongUPC.c"
          _bupc_Mptra60 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 326 "pingpongUPC.c"
          _bupc_spillld61 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra60, 0);
#line 326 "pingpongUPC.c"
          tmax = _bupc_spillld61;
        }
#line 327 "pingpongUPC.c"
        _bupc_Mptra62 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 327 "pingpongUPC.c"
        _bupc_spillld63 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra62, 0);
#line 327 "pingpongUPC.c"
        tavg = tavg + _bupc_spillld63;
#line 328 "pingpongUPC.c"
        _24 :;
#line 328 "pingpongUPC.c"
        ip = ip + 1;
      }
#line 329 "pingpongUPC.c"
      tavg = tavg / rnpes;
#line 331 "pingpongUPC.c"
      tavg2 = tavg / (rnpes + -1.0e+0);
#line 332 "pingpongUPC.c"
      tmin2 = tmin / (rnpes + -1.0e+0);
#line 333 "pingpongUPC.c"
      tmax2 = tmax / (rnpes + -1.0e+0);
#line 334 "pingpongUPC.c"
      fprintf(fp, "%20.13lf  %20.13lf  %20.13lf\n", ri, tavg, tavg2);
    }
#line 336 "pingpongUPC.c"
    _17 :;
#line 336 "pingpongUPC.c"
    rl = rl + drl;
  }
#line 337 "pingpongUPC.c"
  if((_INT32)((mypn == 0)) && (_INT32)(((_UINT64)(fp) != (_UINT64)(stdout))))
#line 337 "pingpongUPC.c"
  {
#line 337 "pingpongUPC.c"
    fclose(fp);
  }
#line 341 "pingpongUPC.c"
  if(mypn == 0)
#line 341 "pingpongUPC.c"
  {
#line 342 "pingpongUPC.c"
    sprintf(fname, "outUPC-GM-%03d.txt", npes);
#line 346 "pingpongUPC.c"
    _bupc_call4 = fopen(fname, "w");
#line 346 "pingpongUPC.c"
    fp = _bupc_call4;
  }
#line 349 "pingpongUPC.c"
  itest = 0;
#line 350 "pingpongUPC.c"
  rl = rl1;
#line 350 "pingpongUPC.c"
  while(rl <= rl2)
#line 350 "pingpongUPC.c"
  {
#line 351 "pingpongUPC.c"
    _bupc_comma13 = pow(10.0, rl);
#line 351 "pingpongUPC.c"
    ri = ((_bupc_comma13 * 1e+06) * 0.125) + 0.5;
#line 352 "pingpongUPC.c"
    num = _I4F8TRUNC(ri);
#line 353 "pingpongUPC.c"
    ri = ((_IEEE64)(num) * 8.0) / 1e+06;
#line 355 "pingpongUPC.c"
    j = 0;
#line 355 "pingpongUPC.c"
    while(j < num)
#line 355 "pingpongUPC.c"
    {
#line 356 "pingpongUPC.c"
      * (d1 + j) = (_IEEE64)(j);
#line 357 "pingpongUPC.c"
      _26 :;
#line 357 "pingpongUPC.c"
      j = j + 1;
    }
#line 358 "pingpongUPC.c"
    upcr_barrier(-1720949035, 1);
#line 360 "pingpongUPC.c"
    if(itest == 0)
#line 360 "pingpongUPC.c"
    {
#line 361 "pingpongUPC.c"
      k = 1;
#line 361 "pingpongUPC.c"
      while(k <= 3)
#line 361 "pingpongUPC.c"
      {
#line 365 "pingpongUPC.c"
        i = 0;
#line 365 "pingpongUPC.c"
        while(i < (npes + -1))
#line 365 "pingpongUPC.c"
        {
#line 369 "pingpongUPC.c"
          j = 0;
#line 369 "pingpongUPC.c"
          while(j < num)
#line 369 "pingpongUPC.c"
          {
#line 370 "pingpongUPC.c"
            _bupc_Mptra64 = UPCR_ADD_PSHARED1(d1S, 8ULL, (ifromLR)[i]);
#line 370 "pingpongUPC.c"
            UPCR_GET_PSHARED(&_bupc_spillld65, _bupc_Mptra64, 0, 8);
#line 370 "pingpongUPC.c"
            _bupc_Mptra66 = UPCR_ADD_PSHAREDI(_bupc_spillld65, 8ULL, j);
#line 370 "pingpongUPC.c"
            _bupc_spillld67 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra66, 0);
#line 370 "pingpongUPC.c"
            * (d2 + j) = _bupc_spillld67;
#line 371 "pingpongUPC.c"
            _29 :;
#line 371 "pingpongUPC.c"
            j = j + 1;
          }
#line 372 "pingpongUPC.c"
          _28 :;
#line 372 "pingpongUPC.c"
          i = i + 1;
        }
#line 373 "pingpongUPC.c"
        _27 :;
#line 373 "pingpongUPC.c"
        k = k + 1;
      }
#line 374 "pingpongUPC.c"
      itest = 1;
    }
#line 376 "pingpongUPC.c"
    upcr_barrier(-1720949034, 1);
#line 377 "pingpongUPC.c"
    _bupc_comma14 = mygetMicrosecondTimeStamp();
#line 377 "pingpongUPC.c"
    t1 = _bupc_comma14;
#line 381 "pingpongUPC.c"
    i = 0;
#line 381 "pingpongUPC.c"
    while(i < (npes + -1))
#line 381 "pingpongUPC.c"
    {
#line 385 "pingpongUPC.c"
      j = 0;
#line 385 "pingpongUPC.c"
      while(j < num)
#line 385 "pingpongUPC.c"
      {
#line 386 "pingpongUPC.c"
        _bupc_Mptra68 = UPCR_ADD_PSHARED1(d1S, 8ULL, (ifromLR)[i]);
#line 386 "pingpongUPC.c"
        UPCR_GET_PSHARED(&_bupc_spillld69, _bupc_Mptra68, 0, 8);
#line 386 "pingpongUPC.c"
        _bupc_Mptra70 = UPCR_ADD_PSHAREDI(_bupc_spillld69, 8ULL, j);
#line 386 "pingpongUPC.c"
        _bupc_spillld71 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra70, 0);
#line 386 "pingpongUPC.c"
        * (d2 + j) = _bupc_spillld71;
#line 387 "pingpongUPC.c"
        _31 :;
#line 387 "pingpongUPC.c"
        j = j + 1;
      }
#line 388 "pingpongUPC.c"
      _30 :;
#line 388 "pingpongUPC.c"
      i = i + 1;
    }
#line 390 "pingpongUPC.c"
    _bupc_comma15 = mygetMicrosecondTimeStamp();
#line 390 "pingpongUPC.c"
    t2 = _bupc_comma15;
#line 391 "pingpongUPC.c"
    tt = t2 - t1;
#line 392 "pingpongUPC.c"
    totalT = (_IEEE64)(tt) / 1e+06;
#line 393 "pingpongUPC.c"
    upcr_barrier(-1720949033, 1);
#line 395 "pingpongUPC.c"
    _bupc_Mptra72 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ((int) upcr_mythread () ));
#line 395 "pingpongUPC.c"
    UPCR_PUT_PSHARED(_bupc_Mptra72, 0, &totalT, 8);
#line 397 "pingpongUPC.c"
    upcr_barrier(-1720949032, 1);
#line 399 "pingpongUPC.c"
    if(mypn == 0)
#line 399 "pingpongUPC.c"
    {
#line 400 "pingpongUPC.c"
      tmin = totalT;
#line 401 "pingpongUPC.c"
      tmax = totalT;
#line 402 "pingpongUPC.c"
      tavg = totalT;
#line 403 "pingpongUPC.c"
      ip = 1;
#line 403 "pingpongUPC.c"
      while(ip < npes)
#line 403 "pingpongUPC.c"
      {
#line 404 "pingpongUPC.c"
        _bupc_Mptra73 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 404 "pingpongUPC.c"
        _bupc_spillld74 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra73, 0);
#line 404 "pingpongUPC.c"
        if(_bupc_spillld74 < tmin)
#line 404 "pingpongUPC.c"
        {
#line 404 "pingpongUPC.c"
          _bupc_Mptra75 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 404 "pingpongUPC.c"
          _bupc_spillld76 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra75, 0);
#line 404 "pingpongUPC.c"
          tmin = _bupc_spillld76;
        }
#line 405 "pingpongUPC.c"
        _bupc_Mptra77 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 405 "pingpongUPC.c"
        _bupc_spillld78 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra77, 0);
#line 405 "pingpongUPC.c"
        if(_bupc_spillld78 > tmax)
#line 405 "pingpongUPC.c"
        {
#line 405 "pingpongUPC.c"
          _bupc_Mptra79 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 405 "pingpongUPC.c"
          _bupc_spillld80 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra79, 0);
#line 405 "pingpongUPC.c"
          tmax = _bupc_spillld80;
        }
#line 406 "pingpongUPC.c"
        _bupc_Mptra81 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 406 "pingpongUPC.c"
        _bupc_spillld82 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra81, 0);
#line 406 "pingpongUPC.c"
        tavg = tavg + _bupc_spillld82;
#line 407 "pingpongUPC.c"
        _32 :;
#line 407 "pingpongUPC.c"
        ip = ip + 1;
      }
#line 408 "pingpongUPC.c"
      tavg = tavg / rnpes;
#line 410 "pingpongUPC.c"
      tavg2 = tavg / (rnpes + -1.0e+0);
#line 411 "pingpongUPC.c"
      tmin2 = tmin / (rnpes + -1.0e+0);
#line 412 "pingpongUPC.c"
      tmax2 = tmax / (rnpes + -1.0e+0);
#line 413 "pingpongUPC.c"
      fprintf(fp, "%20.13lf  %20.13lf  %20.13lf\n", ri, tavg, tavg2);
    }
#line 415 "pingpongUPC.c"
    _25 :;
#line 415 "pingpongUPC.c"
    rl = rl + drl;
  }
#line 416 "pingpongUPC.c"
  if((_INT32)((mypn == 0)) && (_INT32)(((_UINT64)(fp) != (_UINT64)(stdout))))
#line 416 "pingpongUPC.c"
  {
#line 416 "pingpongUPC.c"
    fclose(fp);
  }
#line 420 "pingpongUPC.c"
  if(mypn == 0)
#line 420 "pingpongUPC.c"
  {
#line 421 "pingpongUPC.c"
    sprintf(fname, "outUPC-PM-%03d.txt", npes);
#line 425 "pingpongUPC.c"
    _bupc_call5 = fopen(fname, "w");
#line 425 "pingpongUPC.c"
    fp = _bupc_call5;
  }
#line 428 "pingpongUPC.c"
  itest = 0;
#line 429 "pingpongUPC.c"
  rl = rl1;
#line 429 "pingpongUPC.c"
  while(rl <= rl2)
#line 429 "pingpongUPC.c"
  {
#line 430 "pingpongUPC.c"
    _bupc_comma16 = pow(10.0, rl);
#line 430 "pingpongUPC.c"
    ri = ((_bupc_comma16 * 1e+06) * 0.125) + 0.5;
#line 431 "pingpongUPC.c"
    num = _I4F8TRUNC(ri);
#line 432 "pingpongUPC.c"
    ri = ((_IEEE64)(num) * 8.0) / 1e+06;
#line 434 "pingpongUPC.c"
    j = 0;
#line 434 "pingpongUPC.c"
    while(j < num)
#line 434 "pingpongUPC.c"
    {
#line 435 "pingpongUPC.c"
      * (d1 + j) = (_IEEE64)(j);
#line 436 "pingpongUPC.c"
      _34 :;
#line 436 "pingpongUPC.c"
      j = j + 1;
    }
#line 437 "pingpongUPC.c"
    upcr_barrier(-1720949031, 1);
#line 439 "pingpongUPC.c"
    if(itest == 0)
#line 439 "pingpongUPC.c"
    {
#line 440 "pingpongUPC.c"
      k = 1;
#line 440 "pingpongUPC.c"
      while(k <= 3)
#line 440 "pingpongUPC.c"
      {
#line 444 "pingpongUPC.c"
        i = 0;
#line 444 "pingpongUPC.c"
        while(i < (npes + -1))
#line 444 "pingpongUPC.c"
        {
#line 448 "pingpongUPC.c"
          j = 0;
#line 448 "pingpongUPC.c"
          while(j < num)
#line 448 "pingpongUPC.c"
          {
#line 449 "pingpongUPC.c"
            _bupc_Mptra83 = UPCR_ADD_PSHARED1(d2S, 8ULL, (itooLR)[i]);
#line 449 "pingpongUPC.c"
            UPCR_GET_PSHARED(&_bupc_spillld84, _bupc_Mptra83, 0, 8);
#line 449 "pingpongUPC.c"
            _bupc_Mptra85 = UPCR_ADD_PSHAREDI(_bupc_spillld84, 8ULL, j);
            _bupc_spillstoreparm86 = *(d1 + j);
#line 449 "pingpongUPC.c"
            UPCR_PUT_PSHARED(_bupc_Mptra85, 0, &_bupc_spillstoreparm86, 8);
#line 450 "pingpongUPC.c"
            _37 :;
#line 450 "pingpongUPC.c"
            j = j + 1;
          }
#line 451 "pingpongUPC.c"
          _36 :;
#line 451 "pingpongUPC.c"
          i = i + 1;
        }
#line 452 "pingpongUPC.c"
        _35 :;
#line 452 "pingpongUPC.c"
        k = k + 1;
      }
#line 453 "pingpongUPC.c"
      itest = 1;
    }
#line 455 "pingpongUPC.c"
    upcr_barrier(-1720949030, 1);
#line 456 "pingpongUPC.c"
    _bupc_comma17 = mygetMicrosecondTimeStamp();
#line 456 "pingpongUPC.c"
    t1 = _bupc_comma17;
#line 460 "pingpongUPC.c"
    i = 0;
#line 460 "pingpongUPC.c"
    while(i < (npes + -1))
#line 460 "pingpongUPC.c"
    {
#line 464 "pingpongUPC.c"
      j = 0;
#line 464 "pingpongUPC.c"
      while(j < num)
#line 464 "pingpongUPC.c"
      {
#line 465 "pingpongUPC.c"
        _bupc_Mptra87 = UPCR_ADD_PSHARED1(d2S, 8ULL, (itooLR)[i]);
#line 465 "pingpongUPC.c"
        UPCR_GET_PSHARED(&_bupc_spillld88, _bupc_Mptra87, 0, 8);
#line 465 "pingpongUPC.c"
        _bupc_Mptra89 = UPCR_ADD_PSHAREDI(_bupc_spillld88, 8ULL, j);
        _bupc_spillstoreparm90 = *(d1 + j);
#line 465 "pingpongUPC.c"
        UPCR_PUT_PSHARED(_bupc_Mptra89, 0, &_bupc_spillstoreparm90, 8);
#line 466 "pingpongUPC.c"
        _39 :;
#line 466 "pingpongUPC.c"
        j = j + 1;
      }
#line 467 "pingpongUPC.c"
      _38 :;
#line 467 "pingpongUPC.c"
      i = i + 1;
    }
#line 469 "pingpongUPC.c"
    _bupc_comma18 = mygetMicrosecondTimeStamp();
#line 469 "pingpongUPC.c"
    t2 = _bupc_comma18;
#line 470 "pingpongUPC.c"
    tt = t2 - t1;
#line 471 "pingpongUPC.c"
    totalT = (_IEEE64)(tt) / 1e+06;
#line 472 "pingpongUPC.c"
    upcr_barrier(-1720949029, 1);
#line 474 "pingpongUPC.c"
    _bupc_Mptra91 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ((int) upcr_mythread () ));
#line 474 "pingpongUPC.c"
    UPCR_PUT_PSHARED(_bupc_Mptra91, 0, &totalT, 8);
#line 476 "pingpongUPC.c"
    upcr_barrier(-1720949028, 1);
#line 478 "pingpongUPC.c"
    if(mypn == 0)
#line 478 "pingpongUPC.c"
    {
#line 479 "pingpongUPC.c"
      tmin = totalT;
#line 480 "pingpongUPC.c"
      tmax = totalT;
#line 481 "pingpongUPC.c"
      tavg = totalT;
#line 482 "pingpongUPC.c"
      ip = 1;
#line 482 "pingpongUPC.c"
      while(ip < npes)
#line 482 "pingpongUPC.c"
      {
#line 483 "pingpongUPC.c"
        _bupc_Mptra92 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 483 "pingpongUPC.c"
        _bupc_spillld93 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra92, 0);
#line 483 "pingpongUPC.c"
        if(_bupc_spillld93 < tmin)
#line 483 "pingpongUPC.c"
        {
#line 483 "pingpongUPC.c"
          _bupc_Mptra94 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 483 "pingpongUPC.c"
          _bupc_spillld95 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra94, 0);
#line 483 "pingpongUPC.c"
          tmin = _bupc_spillld95;
        }
#line 484 "pingpongUPC.c"
        _bupc_Mptra96 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 484 "pingpongUPC.c"
        _bupc_spillld97 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra96, 0);
#line 484 "pingpongUPC.c"
        if(_bupc_spillld97 > tmax)
#line 484 "pingpongUPC.c"
        {
#line 484 "pingpongUPC.c"
          _bupc_Mptra98 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 484 "pingpongUPC.c"
          _bupc_spillld99 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra98, 0);
#line 484 "pingpongUPC.c"
          tmax = _bupc_spillld99;
        }
#line 485 "pingpongUPC.c"
        _bupc_Mptra100 = UPCR_ADD_PSHARED1(r1SH, 8ULL, ip);
#line 485 "pingpongUPC.c"
        _bupc_spillld101 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra100, 0);
#line 485 "pingpongUPC.c"
        tavg = tavg + _bupc_spillld101;
#line 486 "pingpongUPC.c"
        _40 :;
#line 486 "pingpongUPC.c"
        ip = ip + 1;
      }
#line 487 "pingpongUPC.c"
      tavg = tavg / rnpes;
#line 489 "pingpongUPC.c"
      tavg2 = tavg / (rnpes + -1.0e+0);
#line 490 "pingpongUPC.c"
      tmin2 = tmin / (rnpes + -1.0e+0);
#line 491 "pingpongUPC.c"
      tmax2 = tmax / (rnpes + -1.0e+0);
#line 492 "pingpongUPC.c"
      fprintf(fp, "%20.13lf  %20.13lf  %20.13lf\n", ri, tavg, tavg2);
    }
#line 494 "pingpongUPC.c"
    _33 :;
#line 494 "pingpongUPC.c"
    rl = rl + drl;
  }
#line 495 "pingpongUPC.c"
  if((_INT32)((mypn == 0)) && (_INT32)(((_UINT64)(fp) != (_UINT64)(stdout))))
#line 495 "pingpongUPC.c"
  {
#line 495 "pingpongUPC.c"
    fclose(fp);
  }
#line 496 "pingpongUPC.c"
  if(mypn == 0)
#line 496 "pingpongUPC.c"
  {
#line 496 "pingpongUPC.c"
    printf("done.\n");
  }
  UPCR_EXIT_FUNCTION();
  return 0;
} /* user_main */

#line 1 "_SYSTEM"
/**************************************************************************/
/* upcc-generated strings for configuration consistency checks            */

GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_GASNetConfig_gen, 
 "$GASNetConfig: (/tmp/upcc--17950-1460275597/pingpongUPC.trans.c) RELEASE=1.26.0,SPEC=1.8,CONDUIT=IBV(IBV-1.16/IBV-1.13),THREADMODEL=PAR,SEGMENT=FAST,PTR=64bit,noalign,nopshm,debug,trace,stats,debugmalloc,srclines,timers_native,membars_native,atomics_native,atomic32_native,atomic64_native $");
GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_UPCRConfig_gen,
 "$UPCRConfig: (/tmp/upcc--17950-1460275597/pingpongUPC.trans.c) VERSION=2.22.0,PLATFORMENV=shared-distributed,SHMEM=pthreads,SHAREDPTRREP=packed/p20:t10:a34,TRANS=berkeleyupc,debug,nogasp,notv,dynamicthreads $");
GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_translatetime, 
 "$UPCTranslateTime: (pingpongUPC.o) Sun Apr 10 01:06:38 2016 $");
GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_GASNetConfig_obj, 
 "$GASNetConfig: (pingpongUPC.o) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_UPCRConfig_obj,
 "$UPCRConfig: (pingpongUPC.o) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_translator, 
 "$UPCTranslator: (pingpongUPC.o) /usr/local/upc/2.22.0/translator/install/targ (aphid) $");
GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_upcver, 
 "$UPCVersion: (pingpongUPC.o) 2.22.0 $");
GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_compileline, 
 "$UPCCompileLine: (pingpongUPC.o) /usr/local/upc/2.22.0/runtime/inst/bin/upcc.pl --at-remote-http -translator=/usr/local/upc/2.22.0/translator/install/targ --arch-size=64 --network=ibv --pthreads 2 --lines --trans --sizes-file=upcc-sizes pingpongUPC.i $");
GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_compiletime, 
 "$UPCCompileTime: (pingpongUPC.o) " __DATE__ " " __TIME__ " $");
#ifndef UPCRI_CC /* ensure backward compatilibity for http netcompile */
#define UPCRI_CC <unknown>
#endif
GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_backendcompiler, 
 "$UPCRBackendCompiler: (pingpongUPC.o) " _STRINGIFY(UPCRI_CC) " $");

#ifdef GASNETT_CONFIGURE_MISMATCH
  GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_configuremismatch, 
   "$UPCRConfigureMismatch: (pingpongUPC.o) 1 $");
  GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_configuredcompiler, 
   "$UPCRConfigureCompiler: (pingpongUPC.o) " GASNETT_PLATFORM_COMPILER_IDSTR " $");
  GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_buildcompiler, 
   "$UPCRBuildCompiler: (pingpongUPC.o) " PLATFORM_COMPILER_IDSTR " $");
#endif

/**************************************************************************/
GASNETT_IDENT(UPCRI_IdentString_pingpongUPC_o_1460275598_transver_2,
 "$UPCTranslatorVersion: (pingpongUPC.o) 2.22.0, built on Oct 27 2015 at 17:48:24, host aphid linux-x86_64/64, gcc v4.2.4 (Ubuntu 4.2.4-1ubuntu4) $");
GASNETT_IDENT(UPCRI_IdentString_INIT_pingpongUPC_17485257927008478918,"$UPCRInitFn: (pingpongUPC.trans.c) UPCRI_INIT_pingpongUPC_17485257927008478918 $");
GASNETT_IDENT(UPCRI_IdentString_ALLOC_pingpongUPC_17485257927008478918,"$UPCRAllocFn: (pingpongUPC.trans.c) UPCRI_ALLOC_pingpongUPC_17485257927008478918 $");
