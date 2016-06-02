/* --- UPCR system headers --- */ 
#include "upcr.h" 
#include "whirl2c.h"
#include "upcr_proxy.h"
/*******************************************************
 * C file translated from WHIRL Mon May 30 21:35:20 2016
 *******************************************************/

/* UPC Runtime specification expected: 3.6 */
#define UPCR_WANT_MAJOR 3
#define UPCR_WANT_MINOR 6
/* UPC translator version: release 2.22.2, built on May 12 2016 at 23:37:50, host cori04 linux-x86_64/64, gcc v4.3.4 [gcc-4_3-branch revision 152973] */
/* Included code from the initialization script */
#include</global/common/cori/ftg/upc/2.22.3/hsw/intel/PrgEnv-intel-5.2.82-16.0.0.109/runtime/inst/opt/include/upcr_config.h>
#include</global/common/cori/ftg/upc/2.22.3/hsw/intel/PrgEnv-intel-5.2.82-16.0.0.109/runtime/inst/opt/include/portable_platform.h>
#include "upcr_geninclude/stdlib.h"
#include</global/common/cori/ftg/upc/2.22.3/hsw/intel/PrgEnv-intel-5.2.82-16.0.0.109/runtime/inst/opt/include/upcr_preinclude/upc_collective_bits.h>
#line 1 "max_norm_upc.w2c.h"
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
extern _IEEE64 do_reduce(_IEEE64);


#define UPCR_SHARED_SIZE_ 16
#define UPCR_PSHARED_SIZE_ 16
upcr_pshared_ptr_t MAX_NORM;
upcr_pshared_ptr_t max_norm_sh;

void UPCRI_ALLOC_max_norm_upc_11660783732355663972(void) { 
UPCR_BEGIN_FUNCTION();
upcr_startup_pshalloc_t _bupc_pinfo[] = { 
UPCRT_STARTUP_PSHALLOC(MAX_NORM, 8, 1, 0, 8, "R1_d"), 
UPCRT_STARTUP_PSHALLOC(max_norm_sh, 8, 1, 1, 8, "A1H_R1_d"), 
 };

UPCR_SET_SRCPOS("_max_norm_upc_11660783732355663972_ALLOC",0);
upcr_startup_pshalloc(_bupc_pinfo, sizeof(_bupc_pinfo) / sizeof(upcr_startup_pshalloc_t));
}

void UPCRI_INIT_max_norm_upc_11660783732355663972(void) { 
UPCR_BEGIN_FUNCTION();
UPCR_SET_SRCPOS("_max_norm_upc_11660783732355663972_INIT",0);
}

#line 16 "operators.upc/max_norm_upc.c"
extern _IEEE64 do_reduce(
  _IEEE64 max_norm)
#line 16 "operators.upc/max_norm_upc.c"
{
#line 16 "operators.upc/max_norm_upc.c"
  UPCR_BEGIN_FUNCTION();
  _IEEE64 _bupc_retspill0;
  upcr_pshared_ptr_t _bupc_Mptra0;
  upcr_shared_ptr_t _bupc_Mstopcvt1;
  upcr_pshared_ptr_t _bupc_Mptra2;
  upcr_shared_ptr_t _bupc_Mstopcvt3;
  upcr_shared_ptr_t _bupc_Mstopcvt4;
  upcr_shared_ptr_t _bupc_Mstopcvt5;
  _IEEE64 _bupc_spillstoreparm6;
  upcr_pshared_ptr_t _bupc_Mptra7;
  _IEEE64 _bupc_spillld8;
  
#line 18 "operators.upc/max_norm_upc.c"
  _bupc_Mptra0 = UPCR_ADD_PSHARED1(max_norm_sh, 8ULL, ((int) upcr_mythread () ));
#line 18 "operators.upc/max_norm_upc.c"
  UPCR_PUT_PSHARED(_bupc_Mptra0, 0, &max_norm, 8);
#line 19 "operators.upc/max_norm_upc.c"
  upcr_barrier(-373913500, 1);
#line 20 "operators.upc/max_norm_upc.c"
  _bupc_Mstopcvt1 = UPCR_PSHARED_TO_SHARED(MAX_NORM);
#line 20 "operators.upc/max_norm_upc.c"
  _bupc_Mptra2 = UPCR_ADD_PSHARED1(max_norm_sh, 8ULL, ((int) upcr_mythread () ));
#line 20 "operators.upc/max_norm_upc.c"
  _bupc_Mstopcvt3 = UPCR_PSHARED_TO_SHARED(_bupc_Mptra2);
#line 20 "operators.upc/max_norm_upc.c"
  bupc_all_reduceD(_bupc_Mstopcvt1, _bupc_Mstopcvt3, (unsigned long) 256ULL, (unsigned long)(_UINT64)(((int) upcr_threads () )), (unsigned long) 1ULL, (_IEEE64(*)(_IEEE64, _IEEE64)) 0ULL, (int) 10);
#line 21 "operators.upc/max_norm_upc.c"
  _bupc_Mstopcvt4 = UPCR_PSHARED_TO_SHARED(max_norm_sh);
#line 21 "operators.upc/max_norm_upc.c"
  _bupc_Mstopcvt5 = UPCR_PSHARED_TO_SHARED(MAX_NORM);
#line 21 "operators.upc/max_norm_upc.c"
  bupc_all_broadcast(_bupc_Mstopcvt4, _bupc_Mstopcvt5, (unsigned long) 8ULL, (int) 36);
#line 32 "operators.upc/max_norm_upc.c"
  if(((int) upcr_mythread () ) == 0)
#line 32 "operators.upc/max_norm_upc.c"
  {
    _bupc_spillstoreparm6 = 0.0;
#line 32 "operators.upc/max_norm_upc.c"
    UPCR_PUT_PSHARED(MAX_NORM, 0, &_bupc_spillstoreparm6, 8);
  }
#line 34 "operators.upc/max_norm_upc.c"
  _bupc_Mptra7 = UPCR_ADD_PSHARED1(max_norm_sh, 8ULL, ((int) upcr_mythread () ));
#line 34 "operators.upc/max_norm_upc.c"
  _bupc_spillld8 = UPCR_GET_PSHARED_DOUBLEVAL(_bupc_Mptra7, 0);
#line 34 "operators.upc/max_norm_upc.c"
  _bupc_retspill0 = _bupc_spillld8;
#line 34 "operators.upc/max_norm_upc.c"
  UPCR_EXIT_FUNCTION();
#line 34 "operators.upc/max_norm_upc.c"
  return _bupc_retspill0;
} /* do_reduce */

#line 1 "_SYSTEM"
/**************************************************************************/
/* upcc-generated strings for configuration consistency checks            */

GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_GASNetConfig_gen, 
 "$GASNetConfig: (/global/cscratch1/sd/hashim/upcc-hashim-122559-1464669320/max_norm_upc.trans.c) RELEASE=1.26.3,SPEC=1.8,CONDUIT=ARIES(ARIES-0.4/ARIES-0.3),THREADMODEL=SEQ,SEGMENT=FAST,PTR=64bit,noalign,pshm,nodebug,notrace,nostats,nodebugmalloc,nosrclines,timers_native,membars_native,atomics_native,atomic32_native,atomic64_native $");
GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_UPCRConfig_gen,
 "$UPCRConfig: (/global/cscratch1/sd/hashim/upcc-hashim-122559-1464669320/max_norm_upc.trans.c) VERSION=2.22.3,PLATFORMENV=shared-distributed,SHMEM=pshm,SHAREDPTRREP=struct/p32:t32:a64,TRANS=berkeleyupc,nodebug,nogasp,notv,dynamicthreads $");
GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_translatetime, 
 "$UPCTranslateTime: (max_norm_upc.o) Mon May 30 21:35:20 2016 $");
GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_GASNetConfig_obj, 
 "$GASNetConfig: (max_norm_upc.o) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_UPCRConfig_obj,
 "$UPCRConfig: (max_norm_upc.o) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_translator, 
 "$UPCTranslator: (max_norm_upc.o) /usr/common/ftg/upc/2.22.3/hsw/translator/install/targ (cori04) $");
GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_upcver, 
 "$UPCVersion: (max_norm_upc.o) 2.22.3 $");
GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_compileline, 
 "$UPCCompileLine: (max_norm_upc.o) /global/common/cori/ftg/upc/2.22.3/hsw/intel/PrgEnv-intel-5.2.82-16.0.0.109/runtime/inst/opt/bin/upcc.pl -network aries -Wc,-fopenmp -Wc,-O3 -I. -DNO_PACK -D_UPC -trans operators.upc/max_norm_upc.c operators.upc/bench_upc.c -D_BARRIER_SYNC $");
GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_compiletime, 
 "$UPCCompileTime: (max_norm_upc.o) " __DATE__ " " __TIME__ " $");
#ifndef UPCRI_CC /* ensure backward compatilibity for http netcompile */
#define UPCRI_CC <unknown>
#endif
GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_backendcompiler, 
 "$UPCRBackendCompiler: (max_norm_upc.o) " _STRINGIFY(UPCRI_CC) " $");

#ifdef GASNETT_CONFIGURE_MISMATCH
  GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_configuremismatch, 
   "$UPCRConfigureMismatch: (max_norm_upc.o) 1 $");
  GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_configuredcompiler, 
   "$UPCRConfigureCompiler: (max_norm_upc.o) " GASNETT_PLATFORM_COMPILER_IDSTR " $");
  GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_buildcompiler, 
   "$UPCRBuildCompiler: (max_norm_upc.o) " PLATFORM_COMPILER_IDSTR " $");
#endif

/**************************************************************************/
GASNETT_IDENT(UPCRI_IdentString_max_norm_upc_o_1464669320_transver_2,
 "$UPCTranslatorVersion: (max_norm_upc.o) 2.22.2, built on May 12 2016 at 23:37:50, host cori04 linux-x86_64/64, gcc v4.3.4 [gcc-4_3-branch revision 152973] $");
