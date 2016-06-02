/* --- UPCR system headers --- */ 
#include "upcr.h" 
#include "whirl2c.h"
#include "upcr_proxy.h"
/*******************************************************
 * C file translated from WHIRL Mon May 30 21:35:21 2016
 *******************************************************/

/* UPC Runtime specification expected: 3.6 */
#define UPCR_WANT_MAJOR 3
#define UPCR_WANT_MINOR 6
/* UPC translator version: release 2.22.2, built on May 12 2016 at 23:37:50, host cori04 linux-x86_64/64, gcc v4.3.4 [gcc-4_3-branch revision 152973] */
/* Included code from the initialization script */
#include</global/common/cori/ftg/upc/2.22.3/hsw/intel/PrgEnv-intel-5.2.82-16.0.0.109/runtime/inst/opt/include/upcr_config.h>
#include</global/common/cori/ftg/upc/2.22.3/hsw/intel/PrgEnv-intel-5.2.82-16.0.0.109/runtime/inst/opt/include/portable_platform.h>
#include "upcr_geninclude/string.h"
#include</global/u2/h/hashim/ALLVM/MG/UPC/./timer.h>
#include</global/u2/h/hashim/ALLVM/MG/UPC/./defines.h>
#include</global/common/cori/ftg/upc/2.22.3/hsw/intel/PrgEnv-intel-5.2.82-16.0.0.109/runtime/inst/opt/include/upcr_preinclude/upc_types.h>
#include "upcr_geninclude/stddef.h"
#include</global/common/cori/ftg/upc/2.22.3/hsw/intel/PrgEnv-intel-5.2.82-16.0.0.109/runtime/inst/opt/include/upcr_preinclude/upc_bits.h>
#include "upcr_geninclude/stdlib.h"
#include "upcr_geninclude/inttypes.h"
#line 1 "bench_upc.w2c.h"
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
struct _bupc_anonymous3_2843631922l {
        int i;
        int j;
        int k;
      };
      struct _bupc_anonymous2_2008870031l {
        int i;
        int j;
        int k;
      };
      struct _bupc_anonymous1_2966228528l {
        int i;
        int j;
        int k;
      };
      struct small_box {
      struct _bupc_anonymous1_2966228528l low;
      struct _bupc_anonymous2_2008870031l dim;
      struct _bupc_anonymous3_2843631922l dim_with_ghosts;
      int ghosts;
      int pencil;
      int plane;
      int volume;
      int numGrids;
      int bufsizes[27LL];
      _IEEE64 * surface_bufs[27LL];
      _IEEE64 * ghost_bufs[27LL];
      upcr_pshared_ptr_t surface_bufs_sh[27LL];
      upcr_pshared_ptr_t ghost_bufs_sh[27LL];
      _IEEE64 ** UPCR_RESTRICT grids;
      unsigned long * UPCR_RESTRICT RedBlackMask;
      unsigned char * UPCR_RESTRICT RedBlack_4BitMask;
    };
    struct _bupc_anonymous11_2187141507l {
          int faces;
          int edges;
          int corners;
        };
        struct _bupc_anonymous12_2512429172l {
        int buf;
        struct _bupc_anonymous11_2187141507l offset;
      };
      struct _bupc_anonymous9_1758455794l {
          int faces;
          int edges;
          int corners;
        };
        struct _bupc_anonymous10_2351580566l {
        int buf;
        struct _bupc_anonymous9_1758455794l offset;
      };
      struct _bupc_anonymous13_1945307835l {
      int rank;
      int local_index;
      struct _bupc_anonymous10_2351580566l send;
      struct _bupc_anonymous12_2512429172l recv;
    };
    struct _bupc_anonymous15_3206836908l {
      int i;
      int j;
      int k;
    };
    struct _bupc_anonymous14_2264459204l {
      int i;
      int j;
      int k;
    };
    typedef  struct {
    struct _bupc_anonymous14_2264459204l low;
    struct _bupc_anonymous15_3206836908l dim;
    int numLevels;
    int ghosts;
    struct _bupc_anonymous13_1945307835l neighbors[27LL];
    struct small_box * levels;
    upcr_pshared_ptr_t levels_sh;
  }   subdomain_type;
  struct _bupc_anonymous23_1456641712l {
      int i;
      int j;
      int k;
    };
    struct _bupc_anonymous22_1683534513l {
      int i;
      int j;
      int k;
    };
    struct _bupc_anonymous21_1196944356l {
      int i;
      int j;
      int k;
    };
    struct _bupc_anonymous20_2465394881l {
      int faces;
      int edges;
      int corners;
    };
    struct _bupc_anonymous18_2702322571l {
      unsigned long smooth[10LL];
      unsigned long residual[10LL];
      unsigned long restriction[10LL];
      unsigned long interpolation[10LL];
      unsigned long communication[10LL];
      unsigned long s2buf[10LL];
      unsigned long bufcopy[10LL];
      unsigned long buf2g[10LL];
      unsigned long recv[10LL];
      unsigned long send[10LL];
      unsigned long wait[10LL];
      unsigned long norm[10LL];
      unsigned long blas1[10LL];
      unsigned long collectives[10LL];
      unsigned long bottom_solve;
      unsigned long build;
      unsigned long vcycles;
      unsigned long MGSolve;
    };
    struct _bupc_anonymous24_2888895574l {
    struct _bupc_anonymous18_2702322571l cycles;
    int rank_of_neighbor[27LL];
    _IEEE64 * send_buffer[27LL];
    _IEEE64 * recv_buffer[27LL];
    upcr_pshared_ptr_t send_buffer_sh[27LL];
    upcr_pshared_ptr_t recv_buffer_sh[27LL];
    upcr_pshared_ptr_t remote_recv_buffer[27LL];
    upcr_pshared_ptr_t full_bit[27LL];
    upcr_pshared_ptr_t empty_bit[27LL];
    upcr_pshared_ptr_t signal_empty[27LL];
    upcr_pshared_ptr_t signal_full[27LL];
    upcr_pshared_ptr_t subdomains_sh;
    struct _bupc_anonymous20_2465394881l buffer_size[27LL];
    struct _bupc_anonymous21_1196944356l dim;
    struct _bupc_anonymous22_1683534513l subdomains_in;
    struct _bupc_anonymous23_1456641712l subdomains_per_rank_in;
    int rank;
    int numsubdomains;
    int numLevels;
    int numGrids;
    int ghosts;
    subdomain_type * subdomains;
  };
  /* File-level vars and routines */
struct _IO_FILE;
extern upcr_shared_ptr_t upc_alloc_aligned(unsigned long, unsigned long);

extern upcr_pshared_ptr_t add_disp(upcr_pshared_ptr_t, int);

extern void print_domain_layout(upcr_pshared_ptr_t);

extern upcr_shared_ptr_t upcr_pshared_to_shared(upcr_pshared_ptr_t);

extern void init_box_levels(subdomain_type *, int);

extern void init_subdomains(struct _bupc_anonymous24_2888895574l *, int);

extern void set_ghost_bufs(struct small_box *);

extern struct _bupc_anonymous24_2888895574l * init_domain(int);

extern void print_all_box_ptrs(struct small_box *);

extern void print_all_domain_ptrs(struct _bupc_anonymous24_2888895574l *);

extern upcr_pshared_ptr_t the_saddest_hack(upcr_pshared_ptr_t, int);

extern void exchange_global_buffer_info(int);

extern void init_domain_srcv(struct _bupc_anonymous24_2888895574l *, int, int);


#define UPCR_SHARED_SIZE_ 16
#define UPCR_PSHARED_SIZE_ 16
upcr_pshared_ptr_t domain_1_sh;
upcr_pshared_ptr_t domain_CA_sh;
extern struct _IO_FILE*  stderr;
extern int do_print;
typedef upcr_pshared_ptr_t _type_tmp_full[27];
_type_tmp_full UPCR_TLD_DEFINE_TENTATIVE(tmp_full, 432, 8);
typedef upcr_pshared_ptr_t _type_tmp_empty[27];
_type_tmp_empty UPCR_TLD_DEFINE_TENTATIVE(tmp_empty, 432, 8);
typedef upcr_pshared_ptr_t _type_tmp_recv[27];
_type_tmp_recv UPCR_TLD_DEFINE_TENTATIVE(tmp_recv, 432, 8);
typedef char _type_lbuf[1024];
_type_lbuf UPCR_TLD_DEFINE_TENTATIVE(lbuf, 1024, 1);

void UPCRI_ALLOC_bench_upc_13867599481258072387(void) { 
UPCR_BEGIN_FUNCTION();
upcr_startup_pshalloc_t _bupc_pinfo[] = { 
UPCRT_STARTUP_PSHALLOC(domain_1_sh, 16, 1, 1, 16, "A1H_R1_PR1_N29_bupc_anonymous24_2888895574l"), 
UPCRT_STARTUP_PSHALLOC(domain_CA_sh, 16, 1, 1, 16, "A1H_R1_PR1_N29_bupc_anonymous24_2888895574l"), 
 };

UPCR_SET_SRCPOS("_bench_upc_13867599481258072387_ALLOC",0);
upcr_startup_pshalloc(_bupc_pinfo, sizeof(_bupc_pinfo) / sizeof(upcr_startup_pshalloc_t));
}

void UPCRI_INIT_bench_upc_13867599481258072387(void) { 
UPCR_BEGIN_FUNCTION();
UPCR_SET_SRCPOS("_bench_upc_13867599481258072387_INIT",0);
}

#line 35 "operators.upc/bench_upc.c"
extern upcr_shared_ptr_t upc_alloc_aligned(
  unsigned long size,
  unsigned long align)
#line 35 "operators.upc/bench_upc.c"
{
#line 35 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  upcr_pshared_ptr_t res;
  char * lres;
  unsigned long disp;
  upcr_shared_ptr_t _bupc_call0;
  upcr_pshared_ptr_t _bupc_Mstopcvt1;
  char * _bupc_Mcvtptr2;
  upcr_pshared_ptr_t _bupc_Mptra3;
  upcr_shared_ptr_t _bupc_Mstopcvt4;
  
#line 39 "operators.upc/bench_upc.c"
  _bupc_call0 = upc_alloc((unsigned long)(size + align));
#line 39 "operators.upc/bench_upc.c"
  _bupc_Mstopcvt1 = UPCR_SHARED_TO_PSHARED(_bupc_call0);
#line 39 "operators.upc/bench_upc.c"
  res = _bupc_Mstopcvt1;
#line 40 "operators.upc/bench_upc.c"
  _bupc_Mcvtptr2 = (char *) UPCR_PSHARED_TO_LOCAL(res);
#line 40 "operators.upc/bench_upc.c"
  lres = _bupc_Mcvtptr2;
#line 41 "operators.upc/bench_upc.c"
  disp = (unsigned long)(lres);
#line 42 "operators.upc/bench_upc.c"
  disp = (disp - (disp % align)) + 64ULL;
#line 43 "operators.upc/bench_upc.c"
  if((disp & 63ULL) != 0ULL)
#line 43 "operators.upc/bench_upc.c"
  {
#line 44 "operators.upc/bench_upc.c"
    printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
  }
#line 46 "operators.upc/bench_upc.c"
  _bupc_Mptra3 = UPCR_ADD_PSHAREDI(res, 1ULL, (_INT64) disp);
#line 46 "operators.upc/bench_upc.c"
  res = _bupc_Mptra3;
#line 47 "operators.upc/bench_upc.c"
  _bupc_Mstopcvt4 = UPCR_PSHARED_TO_SHARED(res);
#line 47 "operators.upc/bench_upc.c"
  return (_bupc_Mstopcvt4);
} /* upc_alloc_aligned */


#line 60 "operators.upc/bench_upc.c"
extern upcr_pshared_ptr_t add_disp(
  upcr_pshared_ptr_t base,
  int elems)
#line 60 "operators.upc/bench_upc.c"
{
#line 60 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  upcr_pshared_ptr_t _bupc_Mptra5;
  
#line 62 "operators.upc/bench_upc.c"
  _bupc_Mptra5 = UPCR_ADD_PSHAREDI(base, 1ULL, elems);
#line 62 "operators.upc/bench_upc.c"
  return (_bupc_Mptra5);
} /* add_disp */


#line 66 "operators.upc/bench_upc.c"
extern void print_domain_layout(
  upcr_pshared_ptr_t Ds)
#line 66 "operators.upc/bench_upc.c"
{
#line 66 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  int th;
  int n;
  upcr_shared_ptr_t _bupc_call6;
  upcr_shared_ptr_t _bupc_call7;
  upcr_shared_ptr_t _bupc_call8;
  upcr_shared_ptr_t _bupc_call9;
  upcr_shared_ptr_t _bupc_call10;
  upcr_shared_ptr_t _bupc_call11;
  upcr_pshared_ptr_t _bupc_Mptra12;
  upcr_pshared_ptr_t _bupc_spillld13;
  upcr_pshared_ptr_t _bupc_Mptra14;
  upcr_pshared_ptr_t _bupc_Mptra15;
  upcr_pshared_ptr_t _bupc_spillld16;
  upcr_pshared_ptr_t _bupc_Mptra17;
  upcr_pshared_ptr_t _bupc_spillld18;
  upcr_pshared_ptr_t _bupc_Mptra19;
  upcr_pshared_ptr_t _bupc_Mptra20;
  upcr_pshared_ptr_t _bupc_spillld21;
  upcr_pshared_ptr_t _bupc_Mptra22;
  upcr_pshared_ptr_t _bupc_spillld23;
  upcr_pshared_ptr_t _bupc_Mptra24;
  upcr_pshared_ptr_t _bupc_Mptra25;
  upcr_pshared_ptr_t _bupc_spillld26;
  upcr_pshared_ptr_t _bupc_Mptra27;
  upcr_pshared_ptr_t _bupc_spillld28;
  upcr_pshared_ptr_t _bupc_Mptra29;
  upcr_pshared_ptr_t _bupc_Mptra30;
  upcr_pshared_ptr_t _bupc_spillld31;
  upcr_pshared_ptr_t _bupc_Mptra32;
  upcr_pshared_ptr_t _bupc_spillld33;
  upcr_pshared_ptr_t _bupc_Mptra34;
  upcr_pshared_ptr_t _bupc_Mptra35;
  upcr_pshared_ptr_t _bupc_spillld36;
  upcr_pshared_ptr_t _bupc_Mptra37;
  upcr_pshared_ptr_t _bupc_spillld38;
  upcr_pshared_ptr_t _bupc_Mptra39;
  upcr_pshared_ptr_t _bupc_Mptra40;
  upcr_pshared_ptr_t _bupc_spillld41;
  
#line 69 "operators.upc/bench_upc.c"
  if(((int) upcr_mythread () ) == 0)
#line 69 "operators.upc/bench_upc.c"
  {
#line 70 "operators.upc/bench_upc.c"
    th = 0;
#line 70 "operators.upc/bench_upc.c"
    while(th < ((int) upcr_threads () ))
#line 70 "operators.upc/bench_upc.c"
    {
#line 71 "operators.upc/bench_upc.c"
      n = 0;
#line 71 "operators.upc/bench_upc.c"
      while(n <= 26)
#line 71 "operators.upc/bench_upc.c"
      {
#line 72 "operators.upc/bench_upc.c"
        _bupc_Mptra12 = UPCR_ADD_PSHARED1(Ds, 16ULL, th);
#line 72 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld13, _bupc_Mptra12, 0, 16);
#line 72 "operators.upc/bench_upc.c"
        _bupc_Mptra14 = UPCR_ADD_PSHAREDI(_bupc_spillld13, 1ULL, (_INT64) 2128ULL);
#line 72 "operators.upc/bench_upc.c"
        _bupc_Mptra15 = UPCR_ADD_PSHAREDI(_bupc_Mptra14, 16ULL, (_INT64)(_UINT64)(n));
#line 72 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld16, _bupc_Mptra15, 0, 16);
#line 72 "operators.upc/bench_upc.c"
        _bupc_call6 = upcr_pshared_to_shared(_bupc_spillld16);
#line 72 "operators.upc/bench_upc.c"
        upcri_dump_shared(_bupc_call6, lbuf, (int) 1024);
#line 73 "operators.upc/bench_upc.c"
        fprintf(stderr, "%d : RECEIVE BUFFER AT %d   %s\n", th, n, lbuf);
#line 75 "operators.upc/bench_upc.c"
        _bupc_Mptra17 = UPCR_ADD_PSHARED1(Ds, 16ULL, th);
#line 75 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld18, _bupc_Mptra17, 0, 16);
#line 75 "operators.upc/bench_upc.c"
        _bupc_Mptra19 = UPCR_ADD_PSHAREDI(_bupc_spillld18, 1ULL, (_INT64) 2560ULL);
#line 75 "operators.upc/bench_upc.c"
        _bupc_Mptra20 = UPCR_ADD_PSHAREDI(_bupc_Mptra19, 16ULL, (_INT64)(_UINT64)(n));
#line 75 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld21, _bupc_Mptra20, 0, 16);
#line 75 "operators.upc/bench_upc.c"
        _bupc_call7 = upcr_pshared_to_shared(_bupc_spillld21);
#line 75 "operators.upc/bench_upc.c"
        upcri_dump_shared(_bupc_call7, lbuf, (int) 1024);
#line 76 "operators.upc/bench_upc.c"
        fprintf(stderr, "%d : REMOTE RECEIVE BUFFER AT %d  %s\n", th, n, lbuf);
#line 78 "operators.upc/bench_upc.c"
        _bupc_Mptra22 = UPCR_ADD_PSHARED1(Ds, 16ULL, th);
#line 78 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld23, _bupc_Mptra22, 0, 16);
#line 78 "operators.upc/bench_upc.c"
        _bupc_Mptra24 = UPCR_ADD_PSHAREDI(_bupc_spillld23, 1ULL, (_INT64) 3424ULL);
#line 78 "operators.upc/bench_upc.c"
        _bupc_Mptra25 = UPCR_ADD_PSHAREDI(_bupc_Mptra24, 16ULL, (_INT64)(_UINT64)(n));
#line 78 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld26, _bupc_Mptra25, 0, 16);
#line 78 "operators.upc/bench_upc.c"
        _bupc_call8 = upcr_pshared_to_shared(_bupc_spillld26);
#line 78 "operators.upc/bench_upc.c"
        upcri_dump_shared(_bupc_call8, lbuf, (int) 1024);
#line 79 "operators.upc/bench_upc.c"
        fprintf(stderr, "%d : EMPTY BIT  AT %d  %s\n", th, n, lbuf);
#line 81 "operators.upc/bench_upc.c"
        _bupc_Mptra27 = UPCR_ADD_PSHARED1(Ds, 16ULL, th);
#line 81 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld28, _bupc_Mptra27, 0, 16);
#line 81 "operators.upc/bench_upc.c"
        _bupc_Mptra29 = UPCR_ADD_PSHAREDI(_bupc_spillld28, 1ULL, (_INT64) 3856ULL);
#line 81 "operators.upc/bench_upc.c"
        _bupc_Mptra30 = UPCR_ADD_PSHAREDI(_bupc_Mptra29, 16ULL, (_INT64)(_UINT64)(n));
#line 81 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld31, _bupc_Mptra30, 0, 16);
#line 81 "operators.upc/bench_upc.c"
        _bupc_call9 = upcr_pshared_to_shared(_bupc_spillld31);
#line 81 "operators.upc/bench_upc.c"
        upcri_dump_shared(_bupc_call9, lbuf, (int) 1024);
#line 82 "operators.upc/bench_upc.c"
        fprintf(stderr, "%d : SIGNAL EMPTY  BIT  AT %d   %s\n", th, n, lbuf);
#line 84 "operators.upc/bench_upc.c"
        _bupc_Mptra32 = UPCR_ADD_PSHARED1(Ds, 16ULL, th);
#line 84 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld33, _bupc_Mptra32, 0, 16);
#line 84 "operators.upc/bench_upc.c"
        _bupc_Mptra34 = UPCR_ADD_PSHAREDI(_bupc_spillld33, 1ULL, (_INT64) 2992ULL);
#line 84 "operators.upc/bench_upc.c"
        _bupc_Mptra35 = UPCR_ADD_PSHAREDI(_bupc_Mptra34, 16ULL, (_INT64)(_UINT64)(n));
#line 84 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld36, _bupc_Mptra35, 0, 16);
#line 84 "operators.upc/bench_upc.c"
        _bupc_call10 = upcr_pshared_to_shared(_bupc_spillld36);
#line 84 "operators.upc/bench_upc.c"
        upcri_dump_shared(_bupc_call10, lbuf, (int) 1024);
#line 85 "operators.upc/bench_upc.c"
        fprintf(stderr, "%d : FULL  BIT  AT %d  %s\n", th, n, lbuf);
#line 87 "operators.upc/bench_upc.c"
        _bupc_Mptra37 = UPCR_ADD_PSHARED1(Ds, 16ULL, th);
#line 87 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld38, _bupc_Mptra37, 0, 16);
#line 87 "operators.upc/bench_upc.c"
        _bupc_Mptra39 = UPCR_ADD_PSHAREDI(_bupc_spillld38, 1ULL, (_INT64) 4288ULL);
#line 87 "operators.upc/bench_upc.c"
        _bupc_Mptra40 = UPCR_ADD_PSHAREDI(_bupc_Mptra39, 16ULL, (_INT64)(_UINT64)(n));
#line 87 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld41, _bupc_Mptra40, 0, 16);
#line 87 "operators.upc/bench_upc.c"
        _bupc_call11 = upcr_pshared_to_shared(_bupc_spillld41);
#line 87 "operators.upc/bench_upc.c"
        upcri_dump_shared(_bupc_call11, lbuf, (int) 1024);
#line 88 "operators.upc/bench_upc.c"
        fprintf(stderr, "%d : SIGNAL FULL  BIT  AT %d   %s\n", th, n, lbuf);
#line 90 "operators.upc/bench_upc.c"
        _2 :;
#line 90 "operators.upc/bench_upc.c"
        n = n + 1;
      }
#line 91 "operators.upc/bench_upc.c"
      _1 :;
#line 91 "operators.upc/bench_upc.c"
      th = th + 1;
    }
  }
  UPCR_EXIT_FUNCTION();
  return;
} /* print_domain_layout */


#line 100 "operators.upc/bench_upc.c"
extern void init_box_levels(
  subdomain_type * box,
  int NL)
#line 100 "operators.upc/bench_upc.c"
{
#line 100 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  char dump[256LL];
  upcr_shared_ptr_t _bupc_call42;
  upcr_pshared_ptr_t _bupc_Mstopcvt43;
  struct small_box * _bupc_Mcvtptr44;
  upcr_shared_ptr_t _bupc_Mstopcvt45;
  
#line 102 "operators.upc/bench_upc.c"
  _bupc_call42 = upc_alloc((unsigned long)((_UINT64)(NL) * 1488ULL));
#line 102 "operators.upc/bench_upc.c"
  _bupc_Mstopcvt43 = UPCR_SHARED_TO_PSHARED(_bupc_call42);
#line 102 "operators.upc/bench_upc.c"
  (box) -> levels_sh = _bupc_Mstopcvt43;
#line 103 "operators.upc/bench_upc.c"
  _bupc_Mcvtptr44 = (struct small_box *) UPCR_PSHARED_TO_LOCAL((box) -> levels_sh);
#line 103 "operators.upc/bench_upc.c"
  (box) -> levels = _bupc_Mcvtptr44;
#line 106 "operators.upc/bench_upc.c"
  _bupc_Mstopcvt45 = UPCR_PSHARED_TO_SHARED((box) -> levels_sh);
#line 106 "operators.upc/bench_upc.c"
  _bupc_dump_shared(_bupc_Mstopcvt45, dump, (int) 255);
  UPCR_EXIT_FUNCTION();
  return;
} /* init_box_levels */


#line 114 "operators.upc/bench_upc.c"
extern void init_subdomains(
  struct _bupc_anonymous24_2888895574l * d,
  int SD)
#line 114 "operators.upc/bench_upc.c"
{
#line 114 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  char dump[255LL];
  upcr_shared_ptr_t _bupc_call46;
  upcr_pshared_ptr_t _bupc_Mstopcvt47;
  subdomain_type * _bupc_Mcvtptr48;
  upcr_shared_ptr_t _bupc_Mstopcvt49;
  
#line 115 "operators.upc/bench_upc.c"
  _bupc_call46 = upc_alloc((unsigned long)((_UINT64)(SD) * 1136ULL));
#line 115 "operators.upc/bench_upc.c"
  _bupc_Mstopcvt47 = UPCR_SHARED_TO_PSHARED(_bupc_call46);
#line 115 "operators.upc/bench_upc.c"
  (d) -> subdomains_sh = _bupc_Mstopcvt47;
#line 116 "operators.upc/bench_upc.c"
  _bupc_Mcvtptr48 = (subdomain_type *) UPCR_PSHARED_TO_LOCAL((d) -> subdomains_sh);
#line 116 "operators.upc/bench_upc.c"
  (d) -> subdomains = _bupc_Mcvtptr48;
#line 119 "operators.upc/bench_upc.c"
  _bupc_Mstopcvt49 = UPCR_PSHARED_TO_SHARED((d) -> subdomains_sh);
#line 119 "operators.upc/bench_upc.c"
  _bupc_dump_shared(_bupc_Mstopcvt49, dump, (int) 255);
  UPCR_EXIT_FUNCTION();
  return;
} /* init_subdomains */


#line 125 "operators.upc/bench_upc.c"
extern void set_ghost_bufs(
  struct small_box * box)
#line 125 "operators.upc/bench_upc.c"
{
#line 125 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  _IEEE64 * (*_bupc_arr_base0)[27LL];
  _IEEE64 * base;
  int n;
  _IEEE64 * (*_bupc_arr_base1)[27LL];
  int(*_bupc_arr_base2)[27LL];
  _IEEE64 * (*_bupc_arr_base3)[27LL];
  unsigned long disp;
  _IEEE64 * (*_bupc_arr_base4)[27LL];
  upcr_pshared_ptr_t(*_bupc_arr_base5)[27LL];
  upcr_pshared_ptr_t(*_bupc_arr_base6)[27LL];
  int(*_bupc_arr_base7)[27LL];
  int(*_bupc_arr_base8)[27LL];
  upcr_pshared_ptr_t(*_bupc_arr_base9)[27LL];
  char dump[256LL];
  upcr_pshared_ptr_t _bupc_Mptra50;
  upcr_shared_ptr_t _bupc_Mstopcvt51;
  
#line 129 "operators.upc/bench_upc.c"
  _bupc_arr_base0 = (_IEEE64 * (*)[27LL])((_UINT8 *)(box) + 168ULL);
#line 129 "operators.upc/bench_upc.c"
  base = (*_bupc_arr_base0)[0];
#line 130 "operators.upc/bench_upc.c"
  n = 0;
#line 130 "operators.upc/bench_upc.c"
  while(n <= 26)
#line 130 "operators.upc/bench_upc.c"
  {
#line 131 "operators.upc/bench_upc.c"
    _bupc_arr_base1 = (_IEEE64 * (*)[27LL])((_UINT8 *)(box) + 168ULL);
#line 131 "operators.upc/bench_upc.c"
    (*_bupc_arr_base1)[n] = base;
#line 132 "operators.upc/bench_upc.c"
    _bupc_arr_base2 = (int(*)[27LL])((_UINT8 *)(box) + 56ULL);
#line 132 "operators.upc/bench_upc.c"
    base = base + (*_bupc_arr_base2)[n];
#line 133 "operators.upc/bench_upc.c"
    _1 :;
#line 133 "operators.upc/bench_upc.c"
    n = n + 1;
  }
#line 135 "operators.upc/bench_upc.c"
  _bupc_arr_base3 = (_IEEE64 * (*)[27LL])((_UINT8 *)(box) + 384ULL);
#line 135 "operators.upc/bench_upc.c"
  base = (*_bupc_arr_base3)[0];
#line 136 "operators.upc/bench_upc.c"
  disp = 0ULL;
#line 137 "operators.upc/bench_upc.c"
  n = 0;
#line 137 "operators.upc/bench_upc.c"
  while(n <= 26)
#line 137 "operators.upc/bench_upc.c"
  {
#line 138 "operators.upc/bench_upc.c"
    _bupc_arr_base4 = (_IEEE64 * (*)[27LL])((_UINT8 *)(box) + 384ULL);
#line 138 "operators.upc/bench_upc.c"
    (*_bupc_arr_base4)[n] = base;
#line 139 "operators.upc/bench_upc.c"
    _bupc_arr_base5 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(box) + 1032ULL);
#line 139 "operators.upc/bench_upc.c"
    _bupc_arr_base6 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(box) + 1032ULL);
#line 139 "operators.upc/bench_upc.c"
    _bupc_Mptra50 = UPCR_ADD_PSHAREDI((*_bupc_arr_base5)[0], 8ULL, (_INT64) disp);
#line 139 "operators.upc/bench_upc.c"
    (*_bupc_arr_base6)[n] = _bupc_Mptra50;
#line 140 "operators.upc/bench_upc.c"
    _bupc_arr_base7 = (int(*)[27LL])((_UINT8 *)(box) + 56ULL);
#line 140 "operators.upc/bench_upc.c"
    base = base + (*_bupc_arr_base7)[n];
#line 141 "operators.upc/bench_upc.c"
    _bupc_arr_base8 = (int(*)[27LL])((_UINT8 *)(box) + 56ULL);
#line 141 "operators.upc/bench_upc.c"
    disp = disp + (_UINT64)((*_bupc_arr_base8)[n]);
#line 144 "operators.upc/bench_upc.c"
    _bupc_arr_base9 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(box) + 1032ULL);
#line 144 "operators.upc/bench_upc.c"
    _bupc_Mstopcvt51 = UPCR_PSHARED_TO_SHARED((*_bupc_arr_base9)[n]);
#line 144 "operators.upc/bench_upc.c"
    _bupc_dump_shared(_bupc_Mstopcvt51, dump, (int) 255);
#line 148 "operators.upc/bench_upc.c"
    _2 :;
#line 148 "operators.upc/bench_upc.c"
    n = n + 1;
  }
  UPCR_EXIT_FUNCTION();
  return;
} /* set_ghost_bufs */


#line 153 "operators.upc/bench_upc.c"
extern struct _bupc_anonymous24_2888895574l * init_domain(
  int which)
#line 153 "operators.upc/bench_upc.c"
{
#line 153 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  upcr_pshared_ptr_t dom;
  struct _bupc_anonymous24_2888895574l * result;
  upcr_pshared_ptr_t _bupc_mcselect52;
  upcr_shared_ptr_t _bupc_call53;
  _INT32 _bupc_Mptreq54;
  upcr_pshared_ptr_t _bupc_Mstopcvt55;
  upcr_pshared_ptr_t _bupc_Mptra56;
  upcr_pshared_ptr_t _bupc_Mptra57;
  upcr_pshared_ptr_t _bupc_spillld58;
  struct _bupc_anonymous24_2888895574l * _bupc_Mcvtptr59;
  
#line 154 "operators.upc/bench_upc.c"
  if(which != 0)
#line 154 "operators.upc/bench_upc.c"
  {
#line 154 "operators.upc/bench_upc.c"
    _bupc_mcselect52 = domain_1_sh;
  }
  else
#line 154 "operators.upc/bench_upc.c"
  {
#line 154 "operators.upc/bench_upc.c"
    _bupc_mcselect52 = domain_CA_sh;
  }
#line 154 "operators.upc/bench_upc.c"
  dom = _bupc_mcselect52;
#line 157 "operators.upc/bench_upc.c"
  _bupc_Mptreq54 = UPCR_ISNULL_PSHARED(dom);
#line 157 "operators.upc/bench_upc.c"
  if(_bupc_Mptreq54)
#line 157 "operators.upc/bench_upc.c"
  {
#line 158 "operators.upc/bench_upc.c"
    printf("Ooops!\n");
#line 159 "operators.upc/bench_upc.c"
    upc_global_exit((int) 1);
  }
#line 162 "operators.upc/bench_upc.c"
  _bupc_call53 = upc_alloc((unsigned long) 5128ULL);
#line 162 "operators.upc/bench_upc.c"
  _bupc_Mptra56 = UPCR_ADD_PSHARED1(dom, 16ULL, ((int) upcr_mythread () ));
#line 162 "operators.upc/bench_upc.c"
  _bupc_Mstopcvt55 = UPCR_SHARED_TO_PSHARED(_bupc_call53);
#line 162 "operators.upc/bench_upc.c"
  UPCR_PUT_PSHARED(_bupc_Mptra56, 0, &_bupc_Mstopcvt55, 16);
#line 163 "operators.upc/bench_upc.c"
  _bupc_Mptra57 = UPCR_ADD_PSHARED1(dom, 16ULL, ((int) upcr_mythread () ));
#line 163 "operators.upc/bench_upc.c"
  UPCR_GET_PSHARED(&_bupc_spillld58, _bupc_Mptra57, 0, 16);
#line 163 "operators.upc/bench_upc.c"
  _bupc_Mcvtptr59 = (struct _bupc_anonymous24_2888895574l *) UPCR_PSHARED_TO_LOCAL(_bupc_spillld58);
#line 163 "operators.upc/bench_upc.c"
  result = _bupc_Mcvtptr59;
#line 164 "operators.upc/bench_upc.c"
  if((_UINT64)(result) == 0ULL)
#line 164 "operators.upc/bench_upc.c"
  {
#line 165 "operators.upc/bench_upc.c"
    printf("Null domain ...\n");
#line 166 "operators.upc/bench_upc.c"
    upc_global_exit((int) 1);
  }
#line 168 "operators.upc/bench_upc.c"
  UPCR_EXIT_FUNCTION();
#line 168 "operators.upc/bench_upc.c"
  return result;
} /* init_domain */


#line 173 "operators.upc/bench_upc.c"
extern void print_all_box_ptrs(
  struct small_box * bp)
#line 173 "operators.upc/bench_upc.c"
{
#line 173 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  int n;
  upcr_pshared_ptr_t(*_bupc_arr_base10)[27LL];
  char dump[256LL];
  upcr_shared_ptr_t _bupc_Mstopcvt60;
  
#line 177 "operators.upc/bench_upc.c"
  printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
#line 178 "operators.upc/bench_upc.c"
  n = 0;
#line 178 "operators.upc/bench_upc.c"
  while(n <= 26)
#line 178 "operators.upc/bench_upc.c"
  {
#line 179 "operators.upc/bench_upc.c"
    _bupc_arr_base10 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(bp) + 1032ULL);
#line 179 "operators.upc/bench_upc.c"
    _bupc_Mstopcvt60 = UPCR_PSHARED_TO_SHARED((*_bupc_arr_base10)[n]);
#line 179 "operators.upc/bench_upc.c"
    _bupc_dump_shared(_bupc_Mstopcvt60, dump, (int) 255);
#line 180 "operators.upc/bench_upc.c"
    printf("%d: BOXLEV %p Assigning  at %d: %s\n", ((int) upcr_mythread () ), bp, n, dump);
#line 181 "operators.upc/bench_upc.c"
    _1 :;
#line 181 "operators.upc/bench_upc.c"
    n = n + 1;
  }
#line 182 "operators.upc/bench_upc.c"
  printf("==================================================================\n");
  UPCR_EXIT_FUNCTION();
  return;
} /* print_all_box_ptrs */


#line 187 "operators.upc/bench_upc.c"
extern void print_all_domain_ptrs(
  struct _bupc_anonymous24_2888895574l * local_d)
#line 187 "operators.upc/bench_upc.c"
{
#line 187 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  int box;
  int NL;
  upcr_pshared_ptr_t sdp;
  char dump[256LL];
  int level;
  upcr_pshared_ptr_t bp;
  int n;
  upcr_pshared_ptr_t _bupc_call61;
  upcr_pshared_ptr_t _bupc_Mptra62;
  upcr_shared_ptr_t _bupc_Mstopcvt63;
  upcr_pshared_ptr_t _bupc_spillld64;
  upcr_pshared_ptr_t _bupc_Mptra65;
  upcr_shared_ptr_t _bupc_Mstopcvt66;
  upcr_shared_ptr_t _bupc_Mstopcvt67;
  
#line 193 "operators.upc/bench_upc.c"
  box = 0;
#line 193 "operators.upc/bench_upc.c"
  while(box < (local_d) -> numsubdomains)
#line 193 "operators.upc/bench_upc.c"
  {
#line 194 "operators.upc/bench_upc.c"
    NL = (((local_d) -> subdomains + box)) -> numLevels;
#line 196 "operators.upc/bench_upc.c"
    _bupc_Mptra62 = UPCR_ADD_PSHAREDI((local_d) -> subdomains_sh, 1136ULL, box);
#line 196 "operators.upc/bench_upc.c"
    sdp = _bupc_Mptra62;
#line 197 "operators.upc/bench_upc.c"
    _bupc_Mstopcvt63 = UPCR_PSHARED_TO_SHARED(sdp);
#line 197 "operators.upc/bench_upc.c"
    _bupc_dump_shared(_bupc_Mstopcvt63, dump, (int) 255);
#line 198 "operators.upc/bench_upc.c"
    printf("%d: INITIAL Subdomain in %d at %d %s\n", ((int) upcr_mythread () ), (int) 100, box, dump);
#line 200 "operators.upc/bench_upc.c"
    level = 0;
#line 200 "operators.upc/bench_upc.c"
    while(level < NL)
#line 200 "operators.upc/bench_upc.c"
    {
#line 201 "operators.upc/bench_upc.c"
      UPCR_GET_PSHARED(&_bupc_spillld64, sdp, 1120, 16);
#line 201 "operators.upc/bench_upc.c"
      _bupc_Mptra65 = UPCR_ADD_PSHAREDI(_bupc_spillld64, 1488ULL, level);
#line 201 "operators.upc/bench_upc.c"
      bp = _bupc_Mptra65;
#line 202 "operators.upc/bench_upc.c"
      _bupc_Mstopcvt66 = UPCR_PSHARED_TO_SHARED(bp);
#line 202 "operators.upc/bench_upc.c"
      _bupc_dump_shared(_bupc_Mstopcvt66, dump, (int) 255);
#line 203 "operators.upc/bench_upc.c"
      printf("%d: INITIAL Box in %d at %d  level %d %s\n", ((int) upcr_mythread () ), (int) 100, box, level, dump);
#line 204 "operators.upc/bench_upc.c"
      n = 0;
#line 204 "operators.upc/bench_upc.c"
      while(n <= 26)
#line 204 "operators.upc/bench_upc.c"
      {
#line 205 "operators.upc/bench_upc.c"
        _bupc_call61 = the_saddest_hack(bp, n);
#line 205 "operators.upc/bench_upc.c"
        _bupc_Mstopcvt67 = UPCR_PSHARED_TO_SHARED(_bupc_call61);
#line 205 "operators.upc/bench_upc.c"
        _bupc_dump_shared(_bupc_Mstopcvt67, dump, (int) 255);
#line 206 "operators.upc/bench_upc.c"
        printf("%d: INITIAL Assigning  dom  %d, level %d at %d: %s\n", ((int) upcr_mythread () ), box, level, n, dump);
#line 207 "operators.upc/bench_upc.c"
        _3 :;
#line 207 "operators.upc/bench_upc.c"
        n = n + 1;
      }
#line 208 "operators.upc/bench_upc.c"
      _2 :;
#line 208 "operators.upc/bench_upc.c"
      level = level + 1;
    }
#line 210 "operators.upc/bench_upc.c"
    _1 :;
#line 210 "operators.upc/bench_upc.c"
    box = box + 1;
  }
#line 212 "operators.upc/bench_upc.c"
  printf("==================================================================\n");
  UPCR_EXIT_FUNCTION();
  return;
} /* print_all_domain_ptrs */


#line 220 "operators.upc/bench_upc.c"
extern void exchange_global_buffer_info(
  int which)
#line 220 "operators.upc/bench_upc.c"
{
#line 220 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  upcr_pshared_ptr_t Ds;
  struct _bupc_anonymous24_2888895574l * local_d;
  int box;
  int NL;
  int level;
  int n;
  struct _bupc_anonymous13_1945307835l(*_bupc_arr_base11)[27LL];
  int tmp;
  upcr_pshared_ptr_t target_d;
  upcr_pshared_ptr_t sdp;
  upcr_pshared_ptr_t bp;
  upcr_pshared_ptr_t(*_bupc_arr_base12)[27LL];
  int _bupc_w2c_tmp0;
  upcr_pshared_ptr_t _bupc_mcselect68;
  upcr_pshared_ptr_t _bupc_call69;
  upcr_pshared_ptr_t _bupc_Mptra70;
  upcr_pshared_ptr_t _bupc_spillld71;
  struct _bupc_anonymous24_2888895574l * _bupc_Mcvtptr72;
  upcr_pshared_ptr_t _bupc_Mptra73;
  upcr_pshared_ptr_t _bupc_spillld74;
  upcr_pshared_ptr_t _bupc_spillld75;
  upcr_pshared_ptr_t _bupc_Mptra76;
  upcr_pshared_ptr_t _bupc_spillld77;
  upcr_pshared_ptr_t _bupc_Mptra78;
  upcr_pshared_ptr_t _bupc_Mptra79;
  upcr_pshared_ptr_t _bupc_spillld80;
  upcr_pshared_ptr_t _bupc_Mptra81;
  upcr_pshared_ptr_t _bupc_Mptra82;
  int _bupc_spillld83;
  upcr_pshared_ptr_t _bupc_Mptra84;
  upcr_pshared_ptr_t _bupc_spillld85;
  upcr_pshared_ptr_t _bupc_Mptra86;
  upcr_pshared_ptr_t _bupc_Mptra87;
  upcr_pshared_ptr_t _bupc_spillld88;
  upcr_pshared_ptr_t _bupc_Mptra89;
  upcr_pshared_ptr_t _bupc_spillld90;
  upcr_pshared_ptr_t _bupc_Mptra91;
  upcr_pshared_ptr_t _bupc_Mptra92;
  upcr_pshared_ptr_t _bupc_Mptra93;
  upcr_pshared_ptr_t _bupc_spillld94;
  upcr_pshared_ptr_t _bupc_Mptra95;
  upcr_pshared_ptr_t _bupc_Mptra96;
  int _bupc_spillld97;
  upcr_pshared_ptr_t _bupc_Mptra98;
  upcr_pshared_ptr_t _bupc_spillld99;
  upcr_pshared_ptr_t _bupc_Mptra100;
  upcr_pshared_ptr_t _bupc_Mptra101;
  upcr_pshared_ptr_t _bupc_spillld102;
  upcr_pshared_ptr_t _bupc_Mptra103;
  upcr_pshared_ptr_t _bupc_spillld104;
  upcr_pshared_ptr_t _bupc_Mptra105;
  upcr_pshared_ptr_t _bupc_Mptra106;
  
#line 221 "operators.upc/bench_upc.c"
  if(which != 0)
#line 221 "operators.upc/bench_upc.c"
  {
#line 221 "operators.upc/bench_upc.c"
    _bupc_mcselect68 = domain_1_sh;
  }
  else
#line 221 "operators.upc/bench_upc.c"
  {
#line 221 "operators.upc/bench_upc.c"
    _bupc_mcselect68 = domain_CA_sh;
  }
#line 221 "operators.upc/bench_upc.c"
  Ds = _bupc_mcselect68;
#line 230 "operators.upc/bench_upc.c"
  upcr_barrier(667375939, 1);
#line 238 "operators.upc/bench_upc.c"
  _bupc_Mptra70 = UPCR_ADD_PSHARED1(Ds, 16ULL, ((int) upcr_mythread () ));
#line 238 "operators.upc/bench_upc.c"
  UPCR_GET_PSHARED(&_bupc_spillld71, _bupc_Mptra70, 0, 16);
#line 238 "operators.upc/bench_upc.c"
  _bupc_Mcvtptr72 = (struct _bupc_anonymous24_2888895574l *) UPCR_PSHARED_TO_LOCAL(_bupc_spillld71);
#line 238 "operators.upc/bench_upc.c"
  local_d = _bupc_Mcvtptr72;
#line 239 "operators.upc/bench_upc.c"
  box = 0;
#line 239 "operators.upc/bench_upc.c"
  while(box < (local_d) -> numsubdomains)
#line 239 "operators.upc/bench_upc.c"
  {
#line 240 "operators.upc/bench_upc.c"
    NL = (((local_d) -> subdomains + box)) -> numLevels;
#line 241 "operators.upc/bench_upc.c"
    level = 0;
#line 241 "operators.upc/bench_upc.c"
    while(level < NL)
#line 241 "operators.upc/bench_upc.c"
    {
#line 242 "operators.upc/bench_upc.c"
      n = 0;
#line 242 "operators.upc/bench_upc.c"
      while(n <= 26)
#line 242 "operators.upc/bench_upc.c"
      {
#line 244 "operators.upc/bench_upc.c"
        _bupc_arr_base11 = (struct _bupc_anonymous13_1945307835l(*)[27LL])((_UINT8 *)(((local_d) -> subdomains + box)) + 32ULL);
#line 244 "operators.upc/bench_upc.c"
        tmp = ((*_bupc_arr_base11)[n]).rank;
#line 246 "operators.upc/bench_upc.c"
        _bupc_Mptra73 = UPCR_ADD_PSHARED1(Ds, 16ULL, tmp);
#line 246 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld74, _bupc_Mptra73, 0, 16);
#line 246 "operators.upc/bench_upc.c"
        target_d = _bupc_spillld74;
#line 247 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld75, target_d, 4720, 16);
#line 247 "operators.upc/bench_upc.c"
        _bupc_Mptra76 = UPCR_ADD_PSHAREDI(_bupc_spillld75, 1136ULL, box);
#line 247 "operators.upc/bench_upc.c"
        sdp = _bupc_Mptra76;
#line 248 "operators.upc/bench_upc.c"
        UPCR_GET_PSHARED(&_bupc_spillld77, sdp, 1120, 16);
#line 248 "operators.upc/bench_upc.c"
        _bupc_Mptra78 = UPCR_ADD_PSHAREDI(_bupc_spillld77, 1488ULL, level);
#line 248 "operators.upc/bench_upc.c"
        bp = _bupc_Mptra78;
#line 249 "operators.upc/bench_upc.c"
        _bupc_arr_base12 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(((((local_d) -> subdomains + box)) -> levels + level)) + 600ULL);
#line 249 "operators.upc/bench_upc.c"
        _bupc_call69 = the_saddest_hack(bp, (int)(26 - n));
#line 249 "operators.upc/bench_upc.c"
        (*_bupc_arr_base12)[n] = _bupc_call69;
#line 251 "operators.upc/bench_upc.c"
        _3 :;
#line 251 "operators.upc/bench_upc.c"
        n = n + 1;
      }
#line 252 "operators.upc/bench_upc.c"
      _2 :;
#line 252 "operators.upc/bench_upc.c"
      level = level + 1;
    }
#line 253 "operators.upc/bench_upc.c"
    _1 :;
#line 253 "operators.upc/bench_upc.c"
    box = box + 1;
  }
#line 255 "operators.upc/bench_upc.c"
  n = 0;
#line 255 "operators.upc/bench_upc.c"
  while(n <= 26)
#line 255 "operators.upc/bench_upc.c"
  {
#line 256 "operators.upc/bench_upc.c"
    _bupc_w2c_tmp0 = 26 - n;
#line 257 "operators.upc/bench_upc.c"
    _bupc_Mptra89 = UPCR_ADD_PSHARED1(Ds, 16ULL, ((int) upcr_mythread () ));
#line 257 "operators.upc/bench_upc.c"
    UPCR_GET_PSHARED(&_bupc_spillld90, _bupc_Mptra89, 0, 16);
#line 257 "operators.upc/bench_upc.c"
    _bupc_Mptra91 = UPCR_ADD_PSHAREDI(_bupc_spillld90, 1ULL, (_INT64) 3856ULL);
#line 257 "operators.upc/bench_upc.c"
    _bupc_Mptra92 = UPCR_ADD_PSHAREDI(_bupc_Mptra91, 16ULL, (_INT64)(_UINT64)(n));
#line 257 "operators.upc/bench_upc.c"
    _bupc_Mptra79 = UPCR_ADD_PSHARED1(Ds, 16ULL, ((int) upcr_mythread () ));
#line 257 "operators.upc/bench_upc.c"
    UPCR_GET_PSHARED(&_bupc_spillld80, _bupc_Mptra79, 0, 16);
#line 257 "operators.upc/bench_upc.c"
    _bupc_Mptra81 = UPCR_ADD_PSHAREDI(_bupc_spillld80, 1ULL, (_INT64) 1152ULL);
#line 257 "operators.upc/bench_upc.c"
    _bupc_Mptra82 = UPCR_ADD_PSHAREDI(_bupc_Mptra81, 4ULL, (_INT64)(_UINT64)(n));
#line 257 "operators.upc/bench_upc.c"
    UPCR_GET_PSHARED(&_bupc_spillld83, _bupc_Mptra82, 0, 4);
#line 257 "operators.upc/bench_upc.c"
    _bupc_Mptra84 = UPCR_ADD_PSHARED1(Ds, 16ULL, _bupc_spillld83);
#line 257 "operators.upc/bench_upc.c"
    UPCR_GET_PSHARED(&_bupc_spillld85, _bupc_Mptra84, 0, 16);
#line 257 "operators.upc/bench_upc.c"
    _bupc_Mptra86 = UPCR_ADD_PSHAREDI(_bupc_spillld85, 1ULL, (_INT64) 3424ULL);
#line 257 "operators.upc/bench_upc.c"
    _bupc_Mptra87 = UPCR_ADD_PSHAREDI(_bupc_Mptra86, 16ULL, (_INT64)(_UINT64)(_bupc_w2c_tmp0));
#line 257 "operators.upc/bench_upc.c"
    UPCR_GET_PSHARED(&_bupc_spillld88, _bupc_Mptra87, 0, 16);
#line 257 "operators.upc/bench_upc.c"
    UPCR_PUT_PSHARED(_bupc_Mptra92, 0, &_bupc_spillld88, 16);
#line 258 "operators.upc/bench_upc.c"
    _bupc_Mptra103 = UPCR_ADD_PSHARED1(Ds, 16ULL, ((int) upcr_mythread () ));
#line 258 "operators.upc/bench_upc.c"
    UPCR_GET_PSHARED(&_bupc_spillld104, _bupc_Mptra103, 0, 16);
#line 258 "operators.upc/bench_upc.c"
    _bupc_Mptra105 = UPCR_ADD_PSHAREDI(_bupc_spillld104, 1ULL, (_INT64) 4288ULL);
#line 258 "operators.upc/bench_upc.c"
    _bupc_Mptra106 = UPCR_ADD_PSHAREDI(_bupc_Mptra105, 16ULL, (_INT64)(_UINT64)(n));
#line 258 "operators.upc/bench_upc.c"
    _bupc_Mptra93 = UPCR_ADD_PSHARED1(Ds, 16ULL, ((int) upcr_mythread () ));
#line 258 "operators.upc/bench_upc.c"
    UPCR_GET_PSHARED(&_bupc_spillld94, _bupc_Mptra93, 0, 16);
#line 258 "operators.upc/bench_upc.c"
    _bupc_Mptra95 = UPCR_ADD_PSHAREDI(_bupc_spillld94, 1ULL, (_INT64) 1152ULL);
#line 258 "operators.upc/bench_upc.c"
    _bupc_Mptra96 = UPCR_ADD_PSHAREDI(_bupc_Mptra95, 4ULL, (_INT64)(_UINT64)(n));
#line 258 "operators.upc/bench_upc.c"
    UPCR_GET_PSHARED(&_bupc_spillld97, _bupc_Mptra96, 0, 4);
#line 258 "operators.upc/bench_upc.c"
    _bupc_Mptra98 = UPCR_ADD_PSHARED1(Ds, 16ULL, _bupc_spillld97);
#line 258 "operators.upc/bench_upc.c"
    UPCR_GET_PSHARED(&_bupc_spillld99, _bupc_Mptra98, 0, 16);
#line 258 "operators.upc/bench_upc.c"
    _bupc_Mptra100 = UPCR_ADD_PSHAREDI(_bupc_spillld99, 1ULL, (_INT64) 2992ULL);
#line 258 "operators.upc/bench_upc.c"
    _bupc_Mptra101 = UPCR_ADD_PSHAREDI(_bupc_Mptra100, 16ULL, (_INT64)(_UINT64)(_bupc_w2c_tmp0));
#line 258 "operators.upc/bench_upc.c"
    UPCR_GET_PSHARED(&_bupc_spillld102, _bupc_Mptra101, 0, 16);
#line 258 "operators.upc/bench_upc.c"
    UPCR_PUT_PSHARED(_bupc_Mptra106, 0, &_bupc_spillld102, 16);
#line 259 "operators.upc/bench_upc.c"
    _4 :;
#line 259 "operators.upc/bench_upc.c"
    n = n + 1;
  }
#line 289 "operators.upc/bench_upc.c"
  if(do_print != 0)
#line 289 "operators.upc/bench_upc.c"
  {
#line 290 "operators.upc/bench_upc.c"
    print_domain_layout(Ds);
  }
#line 291 "operators.upc/bench_upc.c"
  upcr_barrier(667375940, 1);
  UPCR_EXIT_FUNCTION();
  return;
} /* exchange_global_buffer_info */


#line 306 "operators.upc/bench_upc.c"
extern void init_domain_srcv(
  struct _bupc_anonymous24_2888895574l * domain,
  int n,
  int size)
#line 306 "operators.upc/bench_upc.c"
{
#line 306 "operators.upc/bench_upc.c"
  UPCR_BEGIN_FUNCTION();
  upcr_pshared_ptr_t(*_bupc_arr_base13)[27LL];
  upcr_pshared_ptr_t(*_bupc_arr_base14)[27LL];
  upcr_pshared_ptr_t(*_bupc_arr_base15)[27LL];
  _IEEE64 * (*_bupc_arr_base16)[27LL];
  upcr_pshared_ptr_t(*_bupc_arr_base17)[27LL];
  _IEEE64 * (*_bupc_arr_base18)[27LL];
  upcr_pshared_ptr_t(*_bupc_arr_base19)[27LL];
  upcr_pshared_ptr_t(*_bupc_arr_base20)[27LL];
  _IEEE64 * (*_bupc_arr_base21)[27LL];
  _IEEE64 * (*_bupc_arr_base22)[27LL];
  upcr_shared_ptr_t _bupc_call107;
  upcr_shared_ptr_t _bupc_call108;
  upcr_pshared_ptr_t _bupc_Mstopcvt109;
  upcr_pshared_ptr_t _bupc_Mstopcvt110;
  _IEEE64 * _bupc_Mcvtptr111;
  _IEEE64 * _bupc_Mcvtptr112;
  _INT32 _bupc_Mptreq113;
  _INT32 _bupc_Mptreq114;
  
#line 314 "operators.upc/bench_upc.c"
  _bupc_arr_base13 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(domain) + 1696ULL);
#line 314 "operators.upc/bench_upc.c"
  _bupc_call107 = upc_alloc((unsigned long)(_UINT64)(size));
#line 314 "operators.upc/bench_upc.c"
  _bupc_Mstopcvt109 = UPCR_SHARED_TO_PSHARED(_bupc_call107);
#line 314 "operators.upc/bench_upc.c"
  (*_bupc_arr_base13)[n] = _bupc_Mstopcvt109;
#line 315 "operators.upc/bench_upc.c"
  _bupc_arr_base14 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(domain) + 2128ULL);
#line 315 "operators.upc/bench_upc.c"
  _bupc_call108 = upc_alloc((unsigned long)(_UINT64)(size));
#line 315 "operators.upc/bench_upc.c"
  _bupc_Mstopcvt110 = UPCR_SHARED_TO_PSHARED(_bupc_call108);
#line 315 "operators.upc/bench_upc.c"
  (*_bupc_arr_base14)[n] = _bupc_Mstopcvt110;
#line 319 "operators.upc/bench_upc.c"
  _bupc_arr_base15 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(domain) + 1696ULL);
#line 319 "operators.upc/bench_upc.c"
  _bupc_arr_base16 = (_IEEE64 * (*)[27LL])((_UINT8 *)(domain) + 1264ULL);
#line 319 "operators.upc/bench_upc.c"
  _bupc_Mcvtptr111 = (_IEEE64 *) UPCR_PSHARED_TO_LOCAL((*_bupc_arr_base15)[n]);
#line 319 "operators.upc/bench_upc.c"
  (*_bupc_arr_base16)[n] = _bupc_Mcvtptr111;
#line 321 "operators.upc/bench_upc.c"
  _bupc_arr_base17 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(domain) + 2128ULL);
#line 321 "operators.upc/bench_upc.c"
  _bupc_arr_base18 = (_IEEE64 * (*)[27LL])((_UINT8 *)(domain) + 1480ULL);
#line 321 "operators.upc/bench_upc.c"
  _bupc_Mcvtptr112 = (_IEEE64 *) UPCR_PSHARED_TO_LOCAL((*_bupc_arr_base17)[n]);
#line 321 "operators.upc/bench_upc.c"
  (*_bupc_arr_base18)[n] = _bupc_Mcvtptr112;
#line 322 "operators.upc/bench_upc.c"
  _bupc_arr_base19 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(domain) + 2128ULL);
#line 322 "operators.upc/bench_upc.c"
  _bupc_Mptreq113 = UPCR_ISNULL_PSHARED((*_bupc_arr_base19)[n]);
#line 322 "operators.upc/bench_upc.c"
  if(_bupc_Mptreq113)
    goto _1;
#line 322 "operators.upc/bench_upc.c"
  _bupc_arr_base20 = (upcr_pshared_ptr_t(*)[27LL])((_UINT8 *)(domain) + 1696ULL);
#line 322 "operators.upc/bench_upc.c"
  _bupc_Mptreq114 = UPCR_ISNULL_PSHARED((*_bupc_arr_base20)[n]);
#line 322 "operators.upc/bench_upc.c"
  if(!(_bupc_Mptreq114))
    goto _2;
#line 322 "operators.upc/bench_upc.c"
  _1 :;
#line 323 "operators.upc/bench_upc.c"
  printf("Error allocating UPC memory...\n");
#line 324 "operators.upc/bench_upc.c"
  upc_global_exit((int) 1);
#line 322 "operators.upc/bench_upc.c"
  _2 :;
#line 327 "operators.upc/bench_upc.c"
  _bupc_arr_base21 = (_IEEE64 * (*)[27LL])((_UINT8 *)(domain) + 1264ULL);
#line 327 "operators.upc/bench_upc.c"
  if((_UINT64)((*_bupc_arr_base21)[n]) == 0ULL)
    goto _4;
#line 327 "operators.upc/bench_upc.c"
  _bupc_arr_base22 = (_IEEE64 * (*)[27LL])((_UINT8 *)(domain) + 1480ULL);
#line 327 "operators.upc/bench_upc.c"
  if(!((_UINT64)((*_bupc_arr_base22)[n]) == 0ULL))
    goto _5;
#line 327 "operators.upc/bench_upc.c"
  _4 :;
#line 328 "operators.upc/bench_upc.c"
  printf("Error casting to local buffer ...\n");
#line 329 "operators.upc/bench_upc.c"
  upc_global_exit((int) 1);
#line 327 "operators.upc/bench_upc.c"
  _5 :;
  UPCR_EXIT_FUNCTION();
  return;
} /* init_domain_srcv */

#line 1 "_SYSTEM"
/**************************************************************************/
/* upcc-generated strings for configuration consistency checks            */

GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_GASNetConfig_gen, 
 "$GASNetConfig: (/global/cscratch1/sd/hashim/upcc-hashim-122559-1464669320/bench_upc.trans.c) RELEASE=1.26.3,SPEC=1.8,CONDUIT=ARIES(ARIES-0.4/ARIES-0.3),THREADMODEL=SEQ,SEGMENT=FAST,PTR=64bit,noalign,pshm,nodebug,notrace,nostats,nodebugmalloc,nosrclines,timers_native,membars_native,atomics_native,atomic32_native,atomic64_native $");
GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_UPCRConfig_gen,
 "$UPCRConfig: (/global/cscratch1/sd/hashim/upcc-hashim-122559-1464669320/bench_upc.trans.c) VERSION=2.22.3,PLATFORMENV=shared-distributed,SHMEM=pshm,SHAREDPTRREP=struct/p32:t32:a64,TRANS=berkeleyupc,nodebug,nogasp,notv,dynamicthreads $");
GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_translatetime, 
 "$UPCTranslateTime: (bench_upc.o) Mon May 30 21:35:21 2016 $");
GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_GASNetConfig_obj, 
 "$GASNetConfig: (bench_upc.o) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_UPCRConfig_obj,
 "$UPCRConfig: (bench_upc.o) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_translator, 
 "$UPCTranslator: (bench_upc.o) /usr/common/ftg/upc/2.22.3/hsw/translator/install/targ (cori04) $");
GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_upcver, 
 "$UPCVersion: (bench_upc.o) 2.22.3 $");
GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_compileline, 
 "$UPCCompileLine: (bench_upc.o) /global/common/cori/ftg/upc/2.22.3/hsw/intel/PrgEnv-intel-5.2.82-16.0.0.109/runtime/inst/opt/bin/upcc.pl -network aries -Wc,-fopenmp -Wc,-O3 -I. -DNO_PACK -D_UPC -trans operators.upc/max_norm_upc.c operators.upc/bench_upc.c -D_BARRIER_SYNC $");
GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_compiletime, 
 "$UPCCompileTime: (bench_upc.o) " __DATE__ " " __TIME__ " $");
#ifndef UPCRI_CC /* ensure backward compatilibity for http netcompile */
#define UPCRI_CC <unknown>
#endif
GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_backendcompiler, 
 "$UPCRBackendCompiler: (bench_upc.o) " _STRINGIFY(UPCRI_CC) " $");

#ifdef GASNETT_CONFIGURE_MISMATCH
  GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_configuremismatch, 
   "$UPCRConfigureMismatch: (bench_upc.o) 1 $");
  GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_configuredcompiler, 
   "$UPCRConfigureCompiler: (bench_upc.o) " GASNETT_PLATFORM_COMPILER_IDSTR " $");
  GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_buildcompiler, 
   "$UPCRBuildCompiler: (bench_upc.o) " PLATFORM_COMPILER_IDSTR " $");
#endif

/**************************************************************************/
GASNETT_IDENT(UPCRI_IdentString_bench_upc_o_1464669321_transver_2,
 "$UPCTranslatorVersion: (bench_upc.o) 2.22.2, built on May 12 2016 at 23:37:50, host cori04 linux-x86_64/64, gcc v4.3.4 [gcc-4_3-branch revision 152973] $");
