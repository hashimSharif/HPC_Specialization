/* Reference implementation of upc_nb.h 
 * Copyright 2012, The Regents of the University of California 
 * This code is under BSD license: http://upc.lbl.gov/download/dist/LICENSE.TXT
 */

#ifndef _UPC_NB_H
#define _UPC_NB_H

#if !defined(__BERKELEY_UPC_FIRST_PREPROCESS__) && !defined(__BERKELEY_UPC_ONLY_PREPROCESS__)
#error This file should only be included during initial preprocess
#endif

#if __UPC_NB__ != 1
#error Bad feature macro predefinition
#endif

#undef  UPC_COMPLETE_HANDLE
#define UPC_COMPLETE_HANDLE  BUPC_COMPLETE_HANDLE
#undef  upc_handle_t
#define upc_handle_t         bupc_handle_t

#if !UPCRI_LIBWRAP
  struct _upcri_eop;
  typedef struct _upcri_eop *bupc_handle_t;
  #define BUPC_COMPLETE_HANDLE ((bupc_handle_t)NULL)

  /* explicit-handle variants */
  upc_handle_t upc_memcpy_nb(shared void *_dst, shared const void *_src, size_t _n);
  upc_handle_t upc_memget_nb(       void *_dst, shared const void *_src, size_t _n);
  upc_handle_t upc_memput_nb(shared void *_dst,        const void *_src, size_t _n);
  upc_handle_t upc_memset_nb(shared void *_dst, int _c, size_t _n);

  void upc_sync(upc_handle_t h);
  int upc_sync_attempt(upc_handle_t h);

  /* implicit-handle variants */
  void upc_memcpy_nbi(shared void *_dst, shared const void *_src, size_t _n);
  void upc_memget_nbi(       void *_dst, shared const void *_src, size_t _n);
  void upc_memput_nbi(shared void *_dst,        const void *_src, size_t _n);
  void upc_memset_nbi(shared void *_dst, int _c, size_t _n);

  void upc_synci(void);
  int upc_synci_attempt(void);
#else /* UPCRI_LIBWRAP */
  UPCRI_LIBWRAP_FN
  upc_handle_t upc_memcpy_nb(shared void *_dst, shared const void *_src, size_t _n) {
    return _upcr_memcpy_nb(upcri_bless_SVP2shared(_dst), upcri_bless_SVP2shared(_src), _n);
  }
  UPCRI_LIBWRAP_FN
  upc_handle_t upc_memget_nb(       void *_dst, shared const void *_src, size_t _n) {
    return _upcr_memget_nb(_dst, upcri_bless_SVP2shared(_src), _n);
  }
  UPCRI_LIBWRAP_FN
  upc_handle_t upc_memput_nb(shared void *_dst,        const void *_src, size_t _n) {
    return _upcr_memput_nb(upcri_bless_SVP2shared(_dst), _src, _n);
  }
  UPCRI_LIBWRAP_FN
  upc_handle_t upc_memset_nb(shared void *_dst, int _c, size_t _n) {
    return _upcr_memset_nb(upcri_bless_SVP2shared(_dst), _c, _n);
  }

  #define upc_sync          _upcr_waitsync
  #define upc_sync_attempt  _upcr_trysync

  UPCRI_LIBWRAP_FN
  void upc_memcpy_nbi(shared void *_dst, shared const void *_src, size_t _n) {
    _upcr_nbi_memcpy(upcri_bless_SVP2shared(_dst), upcri_bless_SVP2shared(_src), _n);
  }
  UPCRI_LIBWRAP_FN
  void upc_memget_nbi(       void *_dst, shared const void *_src, size_t _n) {
    _upcr_nbi_memget(_dst, upcri_bless_SVP2shared(_src), _n);
  }
  UPCRI_LIBWRAP_FN
  void upc_memput_nbi(shared void *_dst,        const void *_src, size_t _n) {
    _upcr_nbi_memput(upcri_bless_SVP2shared(_dst), _src, _n);
  }
  UPCRI_LIBWRAP_FN
  void upc_memset_nbi(shared void *_dst, int _c, size_t _n) {
    _upcr_nbi_memset(upcri_bless_SVP2shared(_dst), _c, _n);
  }

  #define upc_synci          _upcr_wait_syncnbi_all
  #define upc_synci_attempt  _upcr_try_syncnbi_all
#endif

#endif /* _UPC_NB_H */
