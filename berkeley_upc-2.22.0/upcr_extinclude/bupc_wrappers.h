#ifndef BUPC_WRAPPERS_H
#define BUPC_WRAPPERS_H

/* This header file exists to allow single-preprocess UPC compilers (like GCCUPC)
   to access the UPC-Collectives library, UPC-IO library and bupc_* library extensions,
   many of which are implemented using macro trickery in the Berkeley UPC compiler that
   relies upon dual-preprocess compilation.
*/

#if !defined(__BERKELEY_UPC_ONLY_PREPROCESS__) || !defined(UPCRI_LIBWRAP) || !defined(UPCRI_LIBWRAP_FN)
#error this header should only be used during UPC app compile, by non-BUPC compilers
#endif

#define UPCRI_LIBWRAP_FN __attribute__((__always_inline__)) static __inline__

/* "bless" functions perform safe type conversion between UPC's (shared void *) type (aka SVP) 
   and UPCR's upcr_(p)shared_ptr_t which is used in the upcr.h declarations and libupcr implementation */
UPCRI_LIBWRAP_FN 
upcr_shared_ptr_t upcri_bless_SVP2shared(shared void const *p) {
  return *(upcr_shared_ptr_t*)&p;
}
UPCRI_LIBWRAP_FN 
upcr_pshared_ptr_t upcri_bless_SVP2pshared(shared void const *p) {
  return *(upcr_pshared_ptr_t*)&p;  /* NOTE: relies on GCCUPC equivalence: shared==pshared */
}
UPCRI_LIBWRAP_FN 
shared void * upcri_bless_shared2SVP(upcr_shared_ptr_t p) {
  return *(shared void **)&p;
}
UPCRI_LIBWRAP_FN
shared void * upcri_bless_pshared2SVP(upcr_pshared_ptr_t p) {
  return *(shared void **)&p; /* NOTE: relies on GCCUPC equivalence: shared==pshared */
}

UPCRI_LIBWRAP_FN 
upcr_shared_ptr_t *upcri_bless_SVPA2sharedA(shared void const **p) {
  return *(upcr_shared_ptr_t**)&p;
}

#endif /* BUPC_WRAPPERS_H */
