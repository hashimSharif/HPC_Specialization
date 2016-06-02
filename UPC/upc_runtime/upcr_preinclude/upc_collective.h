#ifndef _UPC_COLLECTIVE_H_
#define _UPC_COLLECTIVE_H_

#if !defined(__BERKELEY_UPC_FIRST_PREPROCESS__) && !defined(__BERKELEY_UPC_ONLY_PREPROCESS__)
#error This file should only be included during initial preprocess
#endif

#if __UPC_COLLECTIVE__ != 1
#error Bad feature macro predefinition
#endif

#include <stdlib.h>

/* Enable use of our builtin collectives implementation */
#define upc_all_broadcast	bupc_all_broadcast
#define upc_all_scatter		bupc_all_scatter
#define upc_all_gather		bupc_all_gather
#define upc_all_gather_all	bupc_all_gather_all
#define upc_all_exchange	bupc_all_exchange
#define upc_all_permute		bupc_all_permute
#define upc_all_reduceC		bupc_all_reduceC
#define upc_all_reduceUC	bupc_all_reduceUC
#define upc_all_reduceS		bupc_all_reduceS
#define upc_all_reduceUS	bupc_all_reduceUS
#define upc_all_reduceI		bupc_all_reduceI
#define upc_all_reduceUI	bupc_all_reduceUI
#define upc_all_reduceL		bupc_all_reduceL
#define upc_all_reduceUL	bupc_all_reduceUL
#define upc_all_reduceF		bupc_all_reduceF
#define upc_all_reduceD		bupc_all_reduceD
#define upc_all_reduceLD	bupc_all_reduceLD
#define upc_all_prefix_reduceC	bupc_all_prefix_reduceC
#define upc_all_prefix_reduceUC	bupc_all_prefix_reduceUC
#define upc_all_prefix_reduceS	bupc_all_prefix_reduceS
#define upc_all_prefix_reduceUS	bupc_all_prefix_reduceUS
#define upc_all_prefix_reduceI	bupc_all_prefix_reduceI
#define upc_all_prefix_reduceUI	bupc_all_prefix_reduceUI
#define upc_all_prefix_reduceL	bupc_all_prefix_reduceL
#define upc_all_prefix_reduceUL	bupc_all_prefix_reduceUL
#define upc_all_prefix_reduceF	bupc_all_prefix_reduceF
#define upc_all_prefix_reduceD	bupc_all_prefix_reduceD
#define upc_all_prefix_reduceLD	bupc_all_prefix_reduceLD

#ifdef BUPC_USE_UPC_NAMESPACE
  #define upc_team_broadcast	bupc_team_broadcast
  #define upc_team_exchange	bupc_team_exchange
  #define UPC_TEAM_ALL		BUPC_TEAM_ALL
#endif

/* upc_flag_t and constants are in a pure-C file: */
#include <upc_collective_bits.h>




/* Prototypes for relocalization functions */

#if !UPCRI_LIBWRAP

void upc_all_broadcast(shared void *_dst, shared const void *_src, size_t _nbytes, upc_flag_t _sync_mode);
bupc_coll_handle_t bupc_team_broadcast(bupc_team_t team, shared void *_dst, shared const void *_src, size_t _nbytes, upc_flag_t _sync_mode);
void upc_all_scatter(shared void *_dst, shared const void *_src, size_t _nbytes, upc_flag_t _sync_mode);
  void upc_all_gather(shared void * _dst, shared const void * _src, size_t _nbytes, upc_flag_t _sync_mode);
  void upc_all_gather_all(shared void *_dst, shared const void *_src, size_t _nbytes, upc_flag_t _sync_mode);
  void upc_all_exchange(shared void *_dst, shared const void *_src, size_t _nbytes, upc_flag_t _sync_mode);
bupc_coll_handle_t bupc_team_exchange(bupc_team_t team, shared void *_dst, shared const void *_src, size_t _nbytes, upc_flag_t _sync_mode);

  void upc_all_permute(shared void *_dst, shared const void *_src, shared const int *_perm, 
                       size_t _nbytes, upc_flag_t _sync_mode);

#else /* !UPCRI_LIBWRAP */

  #define UPCRI_LIBWRAP_COLLECTIVE(name)                                           \
    UPCRI_LIBWRAP_FN                                                               \
    void upc_all_##name(shared void *_dst, shared const void *_src,                \
                        size_t _nbytes, upc_flag_t _sync_mode) {                   \
      _upcr_all_##name(upcri_bless_SVP2shared(_dst), upcri_bless_SVP2shared(_src), \
                       _nbytes, _sync_mode);                                       \
    }
  #define UPCRI_LIBWRAP_TEAM_COLLECTIVE(name)                                           \
    UPCRI_LIBWRAP_FN                                                               \
    bupc_coll_handle_t bupc_team_##name(bupc_team_t team, shared void *_dst, shared const void *_src, \
                        size_t _nbytes, upc_flag_t _sync_mode) {                   \
      return _upcr_team_##name(team, upcri_bless_SVP2shared(_dst), upcri_bless_SVP2shared(_src), \
                               _nbytes, _sync_mode);                    \
    }
  UPCRI_LIBWRAP_COLLECTIVE(broadcast)
  UPCRI_LIBWRAP_TEAM_COLLECTIVE(broadcast)
  UPCRI_LIBWRAP_COLLECTIVE(scatter)
  UPCRI_LIBWRAP_COLLECTIVE(gather)
  UPCRI_LIBWRAP_COLLECTIVE(gather_all)
  UPCRI_LIBWRAP_COLLECTIVE(exchange)
  /*  UPCRI_LIBWRAP_TEAM_COLLECTIVE(exchange) */
  UPCRI_LIBWRAP_FN
  bupc_coll_handle_t bupc_team_exchange(bupc_team_t team, shared void *_dst, shared const void *_src, \
                                     size_t _nbytes, upc_flag_t _sync_mode) { \
    return _upcr_team_exchange(team, upcri_bless_SVP2pshared(_dst), upcri_bless_SVP2pshared(_src), \
                             _nbytes, _sync_mode);                      \
  }
  UPCRI_LIBWRAP_FN
  void upc_all_permute(shared void *_dst, shared const void *_src, 
                       shared const int *_perm, size_t _nbytes, upc_flag_t _sync_mode) {
    _upcr_all_permute(upcri_bless_SVP2shared(_dst),upcri_bless_SVP2shared(_src),
                      upcri_bless_SVP2shared(_perm), _nbytes, _sync_mode);
  }

#endif

/* Prototypes for computational functions */

#if !UPCRI_LIBWRAP
  #define UPCRI_REDUCE_PROTOTYPES(typecode,fulltype)                                 \
    void upc_all_reduce##typecode(shared void *_dst, shared const void *_src,        \
                                   upc_op_t _op, size_t _nelems, size_t _blk_size,   \
                                   fulltype (*_func)(fulltype,fulltype),             \
                                   upc_flag_t _sync_mode);                           \
    void upc_all_prefix_reduce##typecode(shared void *_dst, shared const void *_src, \
                                   upc_op_t _op, size_t _nelems, size_t _blk_size,   \
                                   fulltype (*_func)(fulltype,fulltype),             \
                                   upc_flag_t _sync_mode);                           \
    /* Berkeley UPC extension: bupc_all_reduce_all */                                \
    void bupc_all_reduce_all##typecode(shared void *_dst, shared const void *_src,   \
                                   upc_op_t _op, size_t _nelems, size_t _blk_size,   \
                                   fulltype (*_func)(fulltype,fulltype),             \
                                   upc_flag_t _sync_mode);
#else /* UPCRI_LIBWRAP */

  #define UPCRI_REDUCE_PROTOTYPES(typecode,fulltype)                                 \
    UPCRI_LIBWRAP_FN                                                                 \
    void upc_all_reduce##typecode(shared void *_dst, shared const void *_src,        \
                                   upc_op_t _op, size_t _nelems, size_t _blk_size,   \
                                   fulltype (*_func)(fulltype,fulltype),             \
                                   upc_flag_t _sync_mode) {                          \
      _upcr_all_reduce##typecode(upcri_bless_SVP2shared(_dst),                       \
                                 upcri_bless_SVP2shared(_src),                       \
                                 _op, _nelems, _blk_size, _func, _sync_mode, 0);     \
    }                                                                                \
    UPCRI_LIBWRAP_FN                                                                 \
    void upc_all_prefix_reduce##typecode(shared void *_dst, shared const void *_src, \
                                   upc_op_t _op, size_t _nelems, size_t _blk_size,   \
                                   fulltype (*_func)(fulltype,fulltype),             \
                                   upc_flag_t _sync_mode) {                          \
      _upcr_all_prefix_reduce##typecode(upcri_bless_SVP2shared(_dst),                \
                                 upcri_bless_SVP2shared(_src),                       \
                                 _op, _nelems, _blk_size, _func, _sync_mode);        \
    }                                                                                \
    UPCRI_LIBWRAP_FN                                                                 \
    /* Berkeley UPC extension: bupc_all_reduce_all */                                \
    void bupc_all_reduce_all##typecode(shared void *_dst, shared const void *_src,   \
                                   upc_op_t _op, size_t _nelems, size_t _blk_size,   \
                                   fulltype (*_func)(fulltype,fulltype),             \
                                   upc_flag_t _sync_mode) {                          \
      _upcr_all_reduce##typecode(upcri_bless_SVP2shared(_dst),                       \
                                 upcri_bless_SVP2shared(_src),                       \
                                 _op, _nelems, _blk_size, _func, _sync_mode, 1);     \
    }

#endif

UPCRI_REDUCE_PROTOTYPES(C,  signed char)
UPCRI_REDUCE_PROTOTYPES(UC, unsigned char)
UPCRI_REDUCE_PROTOTYPES(S,  signed short)
UPCRI_REDUCE_PROTOTYPES(US, unsigned short)
UPCRI_REDUCE_PROTOTYPES(I,  signed int)
UPCRI_REDUCE_PROTOTYPES(UI, unsigned int)
UPCRI_REDUCE_PROTOTYPES(L,  signed long)
UPCRI_REDUCE_PROTOTYPES(UL, unsigned long)
UPCRI_REDUCE_PROTOTYPES(F,  float)
UPCRI_REDUCE_PROTOTYPES(D,  double)
UPCRI_REDUCE_PROTOTYPES(LD, UPCRI_COLL_LONG_DOUBLE)

#ifdef BUPC_USE_UPC_NAMESPACE
  #define upc_all_reduce_allC	bupc_all_reduce_allC
  #define upc_all_reduce_allUC	bupc_all_reduce_allUC
  #define upc_all_reduce_allS	bupc_all_reduce_allS
  #define upc_all_reduce_allUS	bupc_all_reduce_allUS
  #define upc_all_reduce_allI	bupc_all_reduce_allI
  #define upc_all_reduce_allUI	bupc_all_reduce_allUI
  #define upc_all_reduce_allL	bupc_all_reduce_allL
  #define upc_all_reduce_allUL	bupc_all_reduce_allUL
  #define upc_all_reduce_allF	bupc_all_reduce_allF
  #define upc_all_reduce_allD	bupc_all_reduce_allD
  #define upc_all_reduce_allLD	bupc_all_reduce_allLD
#endif

#endif
