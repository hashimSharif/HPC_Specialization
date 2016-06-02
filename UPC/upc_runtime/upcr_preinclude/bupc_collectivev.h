/*   $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_preinclude/bupc_collectivev.h $ */
/*  Description: UPC collectives value interface */
/*  Copyright 2005, Dan Bonachea <bonachea@cs.berkeley.edu> */

#ifndef _BUPC_COLLECTIVEV_H
#define _BUPC_COLLECTIVEV_H

#include <upc.h>
#include <upc_collective.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#ifndef MIN
#define MIN(x,y)  ((x)<(y)?(x):(y))
#endif
#ifndef MAX
#define MAX(x,y)  ((x)>(y)?(x):(y))
#endif

/* interface version adhered to */
#define BUPC_COLLECTIVEV_VERSION_MAJOR 1
#define BUPC_COLLECTIVEV_VERSION_MINOR 2

#ifndef BUPC_COLLECTIVEV_DEBUG
  #if defined(__BERKELEY_UPC_RUNTIME_DEBUG__) || defined(GASNET_DEBUG)
    #define BUPC_COLLECTIVEV_DEBUG 1
  #else
    #define BUPC_COLLECTIVEV_DEBUG 0
  #endif
#endif

#ifndef BUPC_COLLECTIVEV_INLINE
  #if 1
    #define BUPC_COLLECTIVEV_INLINE
  #else
    #define BUPC_COLLECTIVEV_INLINE inline
  #endif
#endif

#ifndef BUPC_COLLECTIVEV_SYNC
  #if 0
    #define BUPC_COLLECTIVEV_SYNC (UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC)
  #else
    #define BUPC_COLLECTIVEV_SYNC (UPC_IN_MYSYNC|UPC_OUT_MYSYNC)
  #endif
#endif

#if BUPC_COLLECTIVEV_DEBUG
  #include <ctype.h>
  #define _BUPC_ALLV_FARGS , const char *__typename, const char *__file, int __line
  #define _BUPC_ALLV_AARGS(TYPE) , #TYPE, __FILE__, __LINE__
  #define _BUPC_ALLV_NAME(root,all_suffix)           \
    char __function_name[] = (root "\0\0\0\0");      \
    if (all_suffix) strcat(__function_name, "_all"); 
  typedef unsigned long long _bupc_allv_typehash_t;
  typedef struct  {
    _bupc_allv_typehash_t __typehash;
    size_t __datasz;
    int __rootthreadid;
  } _bupc_allv_debuginfo_t;
  shared [1] _bupc_allv_debuginfo_t *__bupcr_allv_salldebuginfo;
  shared [1] _bupc_allv_debuginfo_t *__bupcr_allv_ralldebuginfo;
  _bupc_allv_debuginfo_t *__bupcr_allv_lsalldebuginfo;
  _bupc_allv_debuginfo_t *__bupcr_allv_lralldebuginfo;
  shared [] char * shared __bupcr_allv_zero_typename;
  shared int __bupcr_allv_zero_typename_sz;
  #define _BUPC_ALLV_DEBUG_SINGLEVAL(datasz, rootthreadid) do {                              \
    _bupc_allv_debuginfo_t __bupcr_allv_mydebuginfo;                                         \
    if (!__bupcr_allv_salldebuginfo) {                                                       \
      __bupcr_allv_salldebuginfo = upc_all_alloc(2*THREADS, sizeof(_bupc_allv_debuginfo_t)); \
      __bupcr_allv_lsalldebuginfo =                                                          \
          (_bupc_allv_debuginfo_t *)(__bupcr_allv_salldebuginfo + MYTHREAD);                 \
      __bupcr_allv_ralldebuginfo = __bupcr_allv_salldebuginfo+THREADS;                       \
      __bupcr_allv_lralldebuginfo =                                                          \
           (_bupc_allv_debuginfo_t *)(__bupcr_allv_ralldebuginfo + MYTHREAD);                \
      memset(__bupcr_allv_lsalldebuginfo, 0, sizeof(_bupc_allv_debuginfo_t)); /* clr pad */  \
    }                                                                                        \
    memset(&__bupcr_allv_mydebuginfo, 0, sizeof(_bupc_allv_debuginfo_t)); /* clr pad */      \
    if (MYTHREAD == 0) {                                                                     \
      int __typename_sz = strlen(__typename)+1;                                              \
      if (__bupcr_allv_zero_typename_sz < __typename_sz) {                                   \
        __bupcr_allv_zero_typename = upc_alloc(__typename_sz);                               \
        __bupcr_allv_zero_typename_sz = __typename_sz;                                       \
      }                                                                                      \
      strcpy((void*)__bupcr_allv_zero_typename, __typename);                                 \
    }                                                                                        \
    __bupcr_allv_mydebuginfo.__typehash = _bupc_allv_typehash(__typename);                   \
    __bupcr_allv_mydebuginfo.__datasz = datasz;                                              \
    __bupcr_allv_mydebuginfo.__rootthreadid = rootthreadid;                                  \
    memcpy(__bupcr_allv_lsalldebuginfo, &__bupcr_allv_mydebuginfo,                           \
           sizeof(_bupc_allv_debuginfo_t));                                                  \
    upc_all_broadcast(__bupcr_allv_ralldebuginfo, __bupcr_allv_salldebuginfo,                \
                      sizeof(_bupc_allv_debuginfo_t), BUPC_COLLECTIVEV_SYNC);                \
    if (memcmp(__bupcr_allv_lralldebuginfo, &__bupcr_allv_mydebuginfo,                       \
               sizeof(_bupc_allv_debuginfo_t))) {                                            \
      int __typename_sz = __bupcr_allv_zero_typename_sz;                                     \
      char *__mytypename = malloc(__typename_sz);                                            \
      upc_memget(__mytypename, __bupcr_allv_zero_typename, __typename_sz);                   \
      fprintf(stderr, "*** Usage error detected in %s at %s:%i:\n"                           \
         "  Thread 0: rootid=%i TYPE='%s' (size=%i bytes, hash=0x%llx)\n"                    \
         "  Thread %i: rootid=%i TYPE='%s' (size=%i bytes, hash=0x%llx)\n"                   \
         , __function_name, __file, __line, __bupcr_allv_mydebuginfo.__rootthreadid,         \
           __mytypename, (int)__bupcr_allv_mydebuginfo.__datasz,                             \
           (unsigned long long)__bupcr_allv_mydebuginfo.__typehash,                          \
           MYTHREAD, __bupcr_allv_lralldebuginfo->__rootthreadid,                            \
           __typename, (int)__bupcr_allv_lralldebuginfo->__datasz,                           \
           (unsigned long long)__bupcr_allv_lralldebuginfo->__typehash);                     \
      abort();                                                                               \
    }                                                                                        \
    upc_barrier; /* ensure nobody races forward after an error is detected */                \
  } while (0)
  /* compute an integral hash of a character string representing a C type (ignoring irrelevant spacing) */
  static _bupc_allv_typehash_t _bupc_allv_typehash(const char *__typename) {
    _bupc_allv_typehash_t __result = 0;
    unsigned char __prevspace = 0;
    int __lastalpha = 0;
    for (unsigned char *__buf = (unsigned char *)__typename; *__buf; __buf++) {
      unsigned char __thischar = *__buf;
      if (isspace(__thischar)) { 
        if (__lastalpha) __prevspace = 0x80; 
        continue; 
      } else if (isalpha(__thischar) || __thischar == '_') { 
        __thischar = __thischar | __prevspace; __prevspace = 0; __lastalpha = 1;
      } else {
        __prevspace = 0; __lastalpha = 0;
      }
      __result = ((__result << 8) | 
                 ((__result >> (sizeof(_bupc_allv_typehash_t)-8)) & 0xFF) ) ^ __thischar;
    }
    return __result;
  }
#else
  #define _BUPC_ALLV_FARGS
  #define _BUPC_ALLV_AARGS(TYPE) 
  #define _BUPC_ALLV_NAME(root,all_suffix) int __dummy_var = sizeof(__dummy_var)
  #define _BUPC_ALLV_DEBUG_SINGLEVAL(datasz, rootthreadid)
#endif

#define __sbuf __bupcr_allv_sbuf
#define __lsbuf __bupcr_allv_lsbuf
#define __rbuf __bupcr_allv_rbuf
#define __lrbuf __bupcr_allv_lrbuf

shared [1] char *__sbuf;
shared [1] char *__rbuf;
char *__lsbuf;
char *__lrbuf;
int __bupcr_allv_sbufsz;
int __bupcr_allv_rbufsz;

#define _BUPC_ALLV_BUFSETUP(sdatasz, rdatasz) do {                          \
    int __sdatasz = (sdatasz);                                              \
    int __rdatasz = (rdatasz);                                              \
    if (__bupcr_allv_sbufsz < __sdatasz) {                                  \
      __bupcr_allv_sbufsz = MAX(16, MAX(__bupcr_allv_sbufsz*2, __sdatasz)); \
      __sbuf = upc_all_alloc(THREADS, __bupcr_allv_sbufsz);                 \
      __lsbuf = (void *)(__sbuf + MYTHREAD);                                \
    }                                                                       \
    if (__bupcr_allv_rbufsz < __rdatasz) {                                  \
      __bupcr_allv_rbufsz = MAX(16, MAX(__bupcr_allv_rbufsz*2, __rdatasz)); \
      __rbuf = upc_all_alloc(THREADS, __bupcr_allv_rbufsz);                 \
      __lrbuf = (void *)(__rbuf + MYTHREAD);                                \
    }                                                                       \
  } while (0)

/* ------------------------------------------------------------------------------------ */
static BUPC_COLLECTIVEV_INLINE
void *_bupc_allv_broadcast(void *__srcdata, size_t __datasz, int __rootthreadid
                           _BUPC_ALLV_FARGS) {
  _BUPC_ALLV_NAME("bupc_allv_broadcast",0);
  _BUPC_ALLV_BUFSETUP(__datasz,__datasz);
  _BUPC_ALLV_DEBUG_SINGLEVAL(__datasz, __rootthreadid);
  if (__rootthreadid == MYTHREAD) memcpy(__lsbuf, __srcdata, __datasz); 
  upc_all_broadcast(__rbuf, __sbuf+__rootthreadid, __datasz, 
                    BUPC_COLLECTIVEV_SYNC);
  return __lrbuf;
}

#define bupc_allv_broadcast(TYPE, inputval, senderthreadid)                \
  (*(TYPE*)(_bupc_allv_broadcast(&(inputval), sizeof(TYPE), senderthreadid \
            _BUPC_ALLV_AARGS(TYPE))))
/* ------------------------------------------------------------------------------------ */
static BUPC_COLLECTIVEV_INLINE
void *_bupc_allv_gather(void *__srcdata, size_t __datasz, int __rootthreadid, void *__destarray
                           _BUPC_ALLV_FARGS) {
  _BUPC_ALLV_NAME("bupc_allv_gather",__rootthreadid == -1);
  _BUPC_ALLV_BUFSETUP(__datasz,__datasz*THREADS); 
  _BUPC_ALLV_DEBUG_SINGLEVAL(__datasz, __rootthreadid);
  #if BUPC_COLLECTIVEV_DEBUG
    if (__rootthreadid == MYTHREAD && !__destarray) {
      fprintf(stderr, "*** Usage error detected in %s at %s:%i:\n"
         "  Thread %i is a root, but passed invalid destination array\n",
         __function_name, __file, __line, MYTHREAD);
      abort();
    }
  #endif
  memcpy(__lsbuf, __srcdata, __datasz); 
  if (__rootthreadid == -1) {
    upc_all_gather_all(__rbuf, __sbuf, __datasz, 
                      BUPC_COLLECTIVEV_SYNC);
  } else {
    upc_all_gather(__rbuf+__rootthreadid, __sbuf, __datasz, 
                      BUPC_COLLECTIVEV_SYNC);
  }
  if ((__rootthreadid == MYTHREAD || __rootthreadid == -1) && __destarray) {
    memcpy(__destarray, __lrbuf, __datasz*THREADS); 
  }
  return __destarray;
}

#define bupc_allv_gather(TYPE, inputval, rootthreadid, rootdestarray)               \
  ((TYPE*)(_bupc_allv_gather(&(inputval), sizeof(TYPE), rootthreadid, rootdestarray \
            _BUPC_ALLV_AARGS(TYPE))))

#define bupc_allv_gather_all(TYPE, inputval, destarray)               \
  ((TYPE*)(_bupc_allv_gather(&(inputval), sizeof(TYPE), -1, destarray \
            _BUPC_ALLV_AARGS(TYPE))))
/* ------------------------------------------------------------------------------------ */
static BUPC_COLLECTIVEV_INLINE
void *_bupc_allv_scatter(size_t __datasz, int __rootthreadid, void *__rootsrcarray
                           _BUPC_ALLV_FARGS) {
  _BUPC_ALLV_NAME("bupc_allv_scatter",0);
  _BUPC_ALLV_BUFSETUP(__datasz*THREADS, __datasz); 
  _BUPC_ALLV_DEBUG_SINGLEVAL(__datasz, __rootthreadid);
  #if BUPC_COLLECTIVEV_DEBUG
    if (__rootthreadid < 0) {
      fprintf(stderr, "*** Usage error detected in bupc_allv_scatter at %s:%i:\n"
         "  passed invalid root thread id: %i\n",
          __file, __line, __rootthreadid);
      abort();
    }
    if (__rootthreadid == MYTHREAD && !__rootsrcarray) {
      fprintf(stderr, "*** Usage error detected in bupc_allv_scatter at %s:%i:\n"
         "  Thread %i is the root, but passed invalid source array\n",
          __file, __line, MYTHREAD);
      abort();
    }
  #endif
  if (__rootthreadid == MYTHREAD) {
    memcpy(__lsbuf, __rootsrcarray, __datasz*THREADS); 
  }
  upc_all_scatter(__rbuf, __sbuf+__rootthreadid, __datasz, 
                    BUPC_COLLECTIVEV_SYNC);
  return __lrbuf;
}

#define bupc_allv_scatter(TYPE, rootthreadid, rootsrcarray)             \
  (*(TYPE*)(_bupc_allv_scatter(sizeof(TYPE), rootthreadid, rootsrcarray \
            _BUPC_ALLV_AARGS(TYPE))))
/* ------------------------------------------------------------------------------------ */
static BUPC_COLLECTIVEV_INLINE
void *_bupc_allv_permute(void *__srcdata, size_t __datasz, int __tothreadid
                           _BUPC_ALLV_FARGS) {
  size_t __ex = MAX(sizeof(int),__datasz);
  _BUPC_ALLV_NAME("bupc_allv_permute",0);
  _BUPC_ALLV_BUFSETUP(__ex + __datasz, __ex + __datasz);
  _BUPC_ALLV_DEBUG_SINGLEVAL(__datasz, 0);
  memcpy(__lsbuf, &__tothreadid, sizeof(int)); 
  memcpy(__lsbuf+__ex, __srcdata, __datasz); 
  upc_all_permute(__rbuf, ((shared [] char *)__sbuf)+__ex, (shared int *)__sbuf, __datasz, 
                    BUPC_COLLECTIVEV_SYNC);
  return __lrbuf;
}

#define bupc_allv_permute(TYPE, inputval, tothreadid)                    \
      (*(TYPE*)_bupc_allv_permute(&(inputval), sizeof(TYPE), tothreadid  \
         _BUPC_ALLV_AARGS(TYPE)))
/* ------------------------------------------------------------------------------------ */
typedef enum {
  _bupc_elemtype_FLOAT,
  _bupc_elemtype_INT,
  _bupc_elemtype_UNSIGNED
} _bupc_elemtype_t;

#define _BUPC_GET_ELEMTYPE(TYPE)                                              \
  (((TYPE)0.5F) == ((TYPE)0) ?                                                \
   (((TYPE)-1) < ((TYPE)0) ?  _bupc_elemtype_INT : _bupc_elemtype_UNSIGNED) : \
   _bupc_elemtype_FLOAT)                                                      

#if BUPC_COLLECTIVEV_DEBUG
  #define _BUPC_ALL_REDUCE_CHECKOP(__op) do {                           \
    switch (__op) {                                                     \
      case UPC_ADD: case UPC_MULT: case UPC_AND: case UPC_OR:           \
      case UPC_XOR: case UPC_LOGAND: case UPC_LOGOR:                    \
      case UPC_MIN: case UPC_MAX: break;                                \
      default:                                                          \
      fprintf(stderr, "*** Unsupported upc_op_t '%i' in %s at %s:%i\n", \
        (int)__op, __function_name, __file, __line);                    \
      abort();                                                          \
    }                                                                   \
  } while (0)
  #define _BUPC_BAD_REDUCE_TYPE() do {                        \
    fprintf(stderr, "*** Unknown type '%s' in %s at %s:%i\n", \
      __typename, __function_name, __file, __line);           \
    abort();                                                  \
  } while (0)
#else
  #define _BUPC_ALL_REDUCE_CHECKOP(__op) ((void)0)
  #define _BUPC_BAD_REDUCE_TYPE() ((void)0)
#endif

#ifdef __BERKELEY_UPC__
  #define _BUPC_ALL_REDUCE(TYPESUFFIX) do {                              \
    if (__rootthreadid == -1) { /* reduce_all */                         \
        bupc_all_reduce_all##TYPESUFFIX(__rbuf, __sbuf, __op,            \
          THREADS, 1, NULL, BUPC_COLLECTIVEV_SYNC);                      \
        return __lrbuf;                                                  \
    } else {                                                             \
        upc_all_reduce##TYPESUFFIX(__rbuf+__rootthreadid, __sbuf, __op,  \
          THREADS, 1, NULL, BUPC_COLLECTIVEV_SYNC);                      \
        return (__rootthreadid == MYTHREAD ? (void*)__lrbuf : &__dummy); \
    }                                                                    \
  } while (0)
#else 
  #define _BUPC_ALL_REDUCE(TYPESUFFIX) do {                            \
    if (__rootthreadid == -1) { /* reduce_all */                       \
      upc_all_reduce##TYPESUFFIX(__rbuf, __sbuf, __op,                 \
          THREADS, 1, NULL, BUPC_COLLECTIVEV_SYNC);                    \
      upc_all_broadcast(__sbuf, __rbuf, __datasz,                      \
          BUPC_COLLECTIVEV_SYNC);                                      \
      return __lsbuf;                                                  \
    } else {                                                           \
      upc_all_reduce##TYPESUFFIX(__rbuf+__rootthreadid, __sbuf, __op,  \
          THREADS, 1, NULL, BUPC_COLLECTIVEV_SYNC);                    \
      return (__rootthreadid == MYTHREAD ? (void*)__lrbuf : &__dummy); \
    }                                                                  \
  } while (0)
#endif

static BUPC_COLLECTIVEV_INLINE 
void *_bupc_allv_reduce(void *__srcdata, size_t __datasz, int __rootthreadid, 
                        upc_op_t __op, _bupc_elemtype_t __elemtype 
                        _BUPC_ALLV_FARGS) {
  static union { 
      long double __dummyf1;
      unsigned long __dummyf2;
  } __dummy; /* dummy holds zeros which are returned to non-root threads */
  _BUPC_ALLV_NAME("bupc_allv_reduce",__rootthreadid == -1);
  _BUPC_ALLV_BUFSETUP(__datasz, __datasz);
  _BUPC_ALL_REDUCE_CHECKOP(__op);
  _BUPC_ALLV_DEBUG_SINGLEVAL(__datasz, __rootthreadid);
  memcpy(__lsbuf, __srcdata, __datasz); 
  switch (__elemtype) {
    case _bupc_elemtype_INT:
      if (__datasz == sizeof(char))       _BUPC_ALL_REDUCE(C);
      else if (__datasz == sizeof(short)) _BUPC_ALL_REDUCE(S);
      else if (__datasz == sizeof(int))   _BUPC_ALL_REDUCE(I);
      else if (__datasz == sizeof(long))  _BUPC_ALL_REDUCE(L);
      else _BUPC_BAD_REDUCE_TYPE();
    case _bupc_elemtype_UNSIGNED:
      if (__datasz == sizeof(char))       _BUPC_ALL_REDUCE(UC);
      else if (__datasz == sizeof(short)) _BUPC_ALL_REDUCE(US);
      else if (__datasz == sizeof(int))   _BUPC_ALL_REDUCE(UI);
      else if (__datasz == sizeof(long))  _BUPC_ALL_REDUCE(UL);
      else _BUPC_BAD_REDUCE_TYPE();
    case _bupc_elemtype_FLOAT:
      if (__datasz == sizeof(float))            _BUPC_ALL_REDUCE(F);
      else if (__datasz == sizeof(double))      _BUPC_ALL_REDUCE(D);
      /* else if (__datasz == sizeof(long double)) _BUPC_ALL_REDUCE(LD); */
      else _BUPC_BAD_REDUCE_TYPE();
  }
  return NULL; /* should never happen */
}


#define bupc_allv_reduce(TYPE, inputval, recvthreadid, op)                    \
      (*(TYPE*)_bupc_allv_reduce(&(inputval), sizeof(TYPE), recvthreadid, op, \
        _BUPC_GET_ELEMTYPE(TYPE) _BUPC_ALLV_AARGS(TYPE)))

#define bupc_allv_reduce_all(TYPE, inputval, op)                    \
      (*(TYPE*)_bupc_allv_reduce(&(inputval), sizeof(TYPE), -1, op, \
        _BUPC_GET_ELEMTYPE(TYPE) _BUPC_ALLV_AARGS(TYPE)))
/* ------------------------------------------------------------------------------------ */
#define _BUPC_ALL_PREFIX_REDUCE(TYPESUFFIX)  do {          \
   upc_all_prefix_reduce##TYPESUFFIX(__rbuf, __sbuf, __op, \
          THREADS, 1, NULL, BUPC_COLLECTIVEV_SYNC);        \
   return __lrbuf;                                         \
} while (0)

static BUPC_COLLECTIVEV_INLINE 
void *_bupc_allv_prefix_reduce(void *__srcdata, size_t __datasz, 
                        upc_op_t __op, _bupc_elemtype_t __elemtype 
                        _BUPC_ALLV_FARGS) {
  int __rootthreadid = 0; /* dummy */
  _BUPC_ALLV_NAME("bupc_allv_prefix_reduce",0);
  _BUPC_ALLV_BUFSETUP(__datasz, __datasz);
  _BUPC_ALL_REDUCE_CHECKOP(__op);
  _BUPC_ALLV_DEBUG_SINGLEVAL(__datasz, __rootthreadid);
  memcpy(__lsbuf, __srcdata, __datasz); 
  switch (__elemtype) {
    case _bupc_elemtype_INT:
      if (__datasz == sizeof(char))       _BUPC_ALL_PREFIX_REDUCE(C);
      else if (__datasz == sizeof(short)) _BUPC_ALL_PREFIX_REDUCE(S);
      else if (__datasz == sizeof(int))   _BUPC_ALL_PREFIX_REDUCE(I);
      else if (__datasz == sizeof(long))  _BUPC_ALL_PREFIX_REDUCE(L);
      else _BUPC_BAD_REDUCE_TYPE();
    case _bupc_elemtype_UNSIGNED:
      if (__datasz == sizeof(char))       _BUPC_ALL_PREFIX_REDUCE(UC);
      else if (__datasz == sizeof(short)) _BUPC_ALL_PREFIX_REDUCE(US);
      else if (__datasz == sizeof(int))   _BUPC_ALL_PREFIX_REDUCE(UI);
      else if (__datasz == sizeof(long))  _BUPC_ALL_PREFIX_REDUCE(UL);
      else _BUPC_BAD_REDUCE_TYPE();
    case _bupc_elemtype_FLOAT:
      if (__datasz == sizeof(float))            _BUPC_ALL_PREFIX_REDUCE(F);
      else if (__datasz == sizeof(double))      _BUPC_ALL_PREFIX_REDUCE(D);
      /* else if (__datasz == sizeof(long double)) _BUPC_ALL_PREFIX_REDUCE(LD); */
      else _BUPC_BAD_REDUCE_TYPE();
  }
  return NULL; /* should never happen */
}

#define bupc_allv_prefix_reduce(TYPE, inputval, op)                    \
      (*(TYPE*)_bupc_allv_prefix_reduce(&(inputval), sizeof(TYPE), op, \
        _BUPC_GET_ELEMTYPE(TYPE) _BUPC_ALLV_AARGS(TYPE)))
/* ------------------------------------------------------------------------------------ */

#undef __sbuf   
#undef __lsbuf 
#undef __rbuf 
#undef __lrbuf 

/* allow user to easily enable use of the "upc_" namespace for Berkeley extensions */
#ifdef BUPC_USE_UPC_NAMESPACE
  #define upc_allv_broadcast     bupc_allv_broadcast
  #define upc_allv_gather        bupc_allv_gather
  #define upc_allv_gather_all    bupc_allv_gather_all
  #define upc_allv_scatter       bupc_allv_scatter
  #define upc_allv_permute       bupc_allv_permute
  #define upc_allv_reduce        bupc_allv_reduce
  #define upc_allv_reduce_all    bupc_allv_reduce_all
  #define upc_allv_prefix_reduce bupc_allv_prefix_reduce
#endif

#endif
