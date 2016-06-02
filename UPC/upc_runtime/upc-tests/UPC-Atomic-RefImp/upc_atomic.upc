/* Reference implementation of UPC atomics from UPC 1.3 
 * Written by Dan Bonachea 
 * Copyright 2013, The Regents of the University of California 
 * See LICENSE.TXT for licensing information.
 * See README for more information
 */

#include "upc.h"
#include "upc_atomic.h"
#ifndef _RUPC_ATOMIC_H
#error Reference upc_atomic.h not found. Check your -I include path.
#endif

/* -DNDEBUG disables checking for client usage errors (enabled by default) */
#if (defined(__BERKELEY_UPC_RUNTIME_DEBUG__) || defined(GASNET_DEBUG) || defined(DEBUG)) && !defined(FORCE_NDEBUG)
  #define DEBUG 1
  #undef NDEBUG
#elif defined(NDEBUG) || defined(FORCE_NDEBUG)
  #undef DEBUG
#else
  #define DEBUG 1
  #undef NDEBUG
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef MIN
#define MIN(x,y)  ((x)<(y)?(x):(y))
#endif
#ifndef MAX
#define MAX(x,y)  ((x)>(y)?(x):(y))
#endif

#ifndef _STRINGIFY
#define _STRINGIFY_HELPER(x) #x
#define _STRINGIFY(x) _STRINGIFY_HELPER(x)
#endif

#define IDENT(identName, identText)                                      \
  extern const char *identName;                                          \
  const char *identName = identText;                                     \
  extern char *_##identName##_identfn(void) { return (char*)identName; } \
  static int _dummy_##identName = sizeof(_dummy_##identName)

IDENT(rupc_verident,"$UPCAtomics: Version 1.0 $");

static const char *context;
#ifdef __GNUC__
__attribute__((__format__ (__printf__, 1, 2)))
#endif
static void fatal(const char *s, ...) {
  char msg[255];
  va_list ap;
  va_start(ap, s);
    vsprintf(msg, s, ap);
  va_end(ap);
  fprintf(stderr,"*** Error in %s: %s\n", (context?context:"upc_atomic"), msg);
  abort();
}

#if DEBUG && defined(__UPC_COLLECTIVE__)
  #include <upc_collective.h>
  typedef unsigned long long bigint_t;
  #define BCAST_SZ MAX(sizeof(bigint_t), sizeof(shared void *))
  static shared [] char bcast_src[BCAST_SZ];
  static shared [BCAST_SZ] char bcast_dst[THREADS][BCAST_SZ];
  #define CHECK_SINGLE(val) do {                                                        \
    bigint_t lv = (bigint_t)(val);                                                      \
    if (!MYTHREAD) *(shared bigint_t *)&bcast_src = lv;                                 \
    upc_all_broadcast(bcast_dst, bcast_src, BCAST_SZ, UPC_IN_MYSYNC|UPC_OUT_MYSYNC);    \
    bigint_t rv = *(shared bigint_t *)&bcast_dst[MYTHREAD];                             \
    if (lv != rv) fatal("%s must be single-valued (%llu != %llu)", #val, lv, rv);       \
  } while (0)
  #define CHECK_SINGLE_PTR(val) do {                                                    \
    shared void *lv = (shared void *)(val);                                             \
    if (!MYTHREAD) *(shared void **)&bcast_src = lv;                                    \
    upc_all_broadcast(bcast_dst, bcast_src, BCAST_SZ, UPC_IN_MYSYNC|UPC_OUT_MYSYNC);    \
    shared void *rv = *(shared void **)&bcast_dst[MYTHREAD];                            \
    if (lv != rv) fatal("%s must be single-valued", #val);                              \
  } while (0)
#else
  #define CHECK_SINGLE(val)     ((void)0)
  #define CHECK_SINGLE_PTR(val) ((void)0)
#endif

#if DEBUG
  #undef assert
  #define assert(expr) \
    ((expr) ? (void)0 : fatal("Assertion failure at line %d: %s", __LINE__, #expr))
  #define CONTEXT(str) context = (str)
  #define CHECK_NONNULL(val) do { if ((val) == NULL) fatal("%s must not be null", #val); } while(0)
  #define MAGIC 0x6e34a79cULL
  #define CHECK_DOMAIN(p) do {                                   \
     shared dom_t *_d = (shared dom_t *)(p);                     \
     if (upc_threadof(_d) != 0 || upc_phaseof(_d) != 0)          \
        fatal("Invalid upc_atomicdomain_t *");                   \
     shared dom_t *_md = _d+MYTHREAD;                            \
     if (_md->magic != MAGIC)                                    \
        fatal("Invalid or corrupted upc_atomicdomain_t");        \
  } while(0)
  /* check an ops flag block */
  #define CHECK_VALIDOPS(ops) do {                                                      \
    upc_op_t _ops = (ops);                                                              \
    if ((_ops == 0) || (_ops & ~OPS_ALL))                                               \
      fatal("invalid upc_op_t value (%llu)", (unsigned long long)_ops);                 \
  } while (0)
  /* check a single op value */
  #define CHECK_VALIDOP(op) do {                                                        \
    upc_op_t _op = (op);                                                                \
    unsigned long long _tmp = (unsigned long long)_op;                                  \
    CHECK_VALIDOPS(_op);                                                                \
    while ((_tmp & 0x1) == 0) _tmp >>= 1;                                               \
    if (_tmp > 1)                                                                       \
      fatal("invalid unique upc_op_t value (%llu)", (unsigned long long)_op);           \
  } while (0)
#else
  #undef assert
  #define assert(expr)          ((void)0)
  #define CONTEXT(str)          ((void)0)
  #define CHECK_NONNULL(val)    ((void)0)
  #define CHECK_DOMAIN(d)       ((void)0)
  #define CHECK_VALIDOPS(ops)   ((void)0)
  #define CHECK_VALIDOP(op)     ((void)0)
#endif

/* ------------------------------------------------------------------------------- */
/* domlock_t: the abstract domain lock object, striped across threads inside dom_t 
 * Several implementations are provided with varying levels of distribution and concurrency
 */
#if !defined(LOCK_CENTRAL) && !defined(LOCK_NODIR) && !defined(LOCK_FULLDIR) && !defined(LOCK_DIR)
  #if __BERKELEY_UPC_SMP_CONDUIT__ /* shared memory */
    #define LOCK_NODIR 1
  #else
    #define LOCK_FULLDIR 1
  #endif
#endif

#if defined(LOCK_CENTRAL)
  /* one centralized lock protects the domain */
  typedef upc_lock_t *domlock_t; /* replicated handle */
  static void lock_alloc(shared domlock_t *dl) {
    shared domlock_t *mdl = dl + MYTHREAD;
    upc_lock_t *lock = upc_all_lock_alloc(); /* one lock to rule them all */
    assert(lock);
    *mdl = lock; 
  }
  static void lock_free(shared domlock_t *dl) {
    shared domlock_t *mdl = dl + MYTHREAD;
    upc_lock_t *lock = *mdl;
    assert(lock);
    #if _RUPC_HAVE_UPC13
      upc_all_lock_free(lock);
    #else
      if (!MYTHREAD) upc_lock_free(lock);
    #endif
    *mdl = NULL;
  }
  static upc_lock_t *lock_fetch(shared domlock_t *dl, shared void *addr) {
    shared domlock_t *mdl = dl + MYTHREAD;
    upc_lock_t *lock = *mdl;
    assert(lock);
    return lock;
  }
  IDENT(rupc_lockident,"$UPCAtomics: LOCK_CENTRAL $");
#elif defined(LOCK_NODIR)
  /* each thread has a lock protecting data with affinity to that thread */
  typedef upc_lock_t *domlock_t; /* per-thread lock */
  static void lock_alloc(shared domlock_t *dl) {
    shared domlock_t *mdl = dl + MYTHREAD;
    upc_lock_t *lock = upc_global_lock_alloc();
    assert(lock);
    *mdl = lock;
    upc_barrier; /* ensure all locks are established */
  }
  static void lock_free(shared domlock_t *dl) {
    shared domlock_t *mdl = dl + MYTHREAD;
    assert(*mdl);
    upc_lock_free(*mdl);
    *mdl = NULL;
  }
  static upc_lock_t *lock_fetch(shared domlock_t *dl, shared void *addr) {
    size_t th = upc_threadof(addr);
    assert(th < THREADS);
    shared domlock_t *hdl = dl + th;
    upc_lock_t *lock = *hdl;
    assert(lock);
    return lock;
  }
  IDENT(rupc_lockident,"$UPCAtomics: LOCK_NODIR $");
#elif defined(LOCK_FULLDIR)
  /* each thread has a lock protecting data with affinity to that thread
   * and a full (non-scalable) cache of the other thread locks, to save a roundtrip latency
   */
  typedef struct { 
    upc_lock_t *lock;  /* per-thread lock */
    upc_lock_t **dir;
  } domlock_t; 
  static void lock_alloc(shared domlock_t *dl) {
    shared domlock_t *msdl = dl + MYTHREAD;
    domlock_t *mdl = (domlock_t *)msdl;
    upc_lock_t *lock = upc_global_lock_alloc();
    assert(lock);
    mdl->lock = lock;
    mdl->dir = calloc(THREADS,sizeof(upc_lock_t *));
    upc_barrier; /* ensure all locks are established */
  }
  static void lock_free(shared domlock_t *dl) {
    shared domlock_t *msdl = dl + MYTHREAD;
    domlock_t *mdl = (domlock_t *)msdl;
    assert(mdl->lock);
    upc_lock_free(mdl->lock);
    assert(mdl->dir);
    free(mdl->dir);
    mdl->lock = NULL;
    mdl->dir = NULL;
  }
  static upc_lock_t *lock_fetch(shared domlock_t *dl, shared void *addr) {
    shared domlock_t *msdl = dl + MYTHREAD;
    domlock_t *mdl = (domlock_t *)msdl;
    size_t th = upc_threadof(addr);
    assert(th < THREADS);
    upc_lock_t *lock = mdl->dir[th];
    if (lock) return lock; /* cache hit */
    shared domlock_t *hdl = dl + th;
    lock = hdl->lock; /* cache miss */
    assert(lock);
    mdl->dir[th] = lock;
    return lock;
  }
  IDENT(rupc_lockident,"$UPCAtomics: LOCK_FULLDIR $");
#elif defined(LOCK_DIR)
  #if LOCK_DIR < 2 /* default cache size is 4, user can override with -DLOCK_DIR=N */
    #undef LOCK_DIR
    #define LOCK_DIR 4
  #endif
  /* each thread has a lock protecting data with affinity to that thread
   * and a partial cache of the other thread locks, to save a roundtrip latency
   * more scalable than LOCK_FULLDIR, at the cost of a limited working set
   */
  typedef struct {
    upc_lock_t *lock;
    int threadid;
    int active;
  } cacheentry_t;
  typedef struct { 
    upc_lock_t *lock;  /* per-thread lock */
    cacheentry_t *dir;
  } domlock_t; 
  static int cachesz;
  static void lock_alloc(shared domlock_t *dl) {
    shared domlock_t *msdl = dl + MYTHREAD;
    domlock_t *mdl = (domlock_t *)msdl;
    upc_lock_t *lock = upc_global_lock_alloc();
    assert(lock);
    mdl->lock = lock;
    if (!cachesz) cachesz = MIN(THREADS, LOCK_DIR);
    mdl->dir = calloc(cachesz,sizeof(cacheentry_t));
    upc_barrier; /* ensure all locks are established */
  }
  static void lock_free(shared domlock_t *dl) {
    shared domlock_t *msdl = dl + MYTHREAD;
    domlock_t *mdl = (domlock_t *)msdl;
    assert(mdl->lock);
    upc_lock_free(mdl->lock);
    assert(mdl->dir);
    free(mdl->dir);
    mdl->lock = NULL;
    mdl->dir = NULL;
  }
  static upc_lock_t *lock_fetch(shared domlock_t *dl, shared void *addr) {
    shared domlock_t *msdl = dl + MYTHREAD;
    domlock_t *mdl = (domlock_t *)msdl;
    int th = (int)upc_threadof(addr);
    assert(th < THREADS);
    if (th == MYTHREAD) {
      assert(mdl->lock);
      return mdl->lock;
    }
    cacheentry_t *dir = mdl->dir;
    upc_lock_t *lock;
    for (int i=0; i < cachesz; i++) {
      if (dir[i].threadid == th && dir[i].lock) { /* cache hit */
        lock = dir[i].lock;
        dir[i].active++;
        return lock;
      }
    }
    /* cache miss */
    shared domlock_t *hdl = dl + th;
    lock = hdl->lock; 
    /* approximate LRU cache replacement */
    int victim = -1;
    unsigned int minactive;
    for (int i=0; i < cachesz; i++) {
      if (victim < 0 || dir[i].active < minactive) {
        victim = i;
        minactive = dir[i].active;
      }
    }
    assert(lock);
    assert(victim >= 0 && victim < cachesz);
    dir[victim].lock = lock;
    dir[victim].threadid = th;
    dir[victim].active = 1;
    return lock;
  }
  IDENT(rupc_lockident,"$UPCAtomics: LOCK_DIR="_STRINGIFY(LOCK_DIR)" $");
#else
  #error Unsupported LOCK_* define
#endif

#ifdef __BERKELEY_UPC__
/* workaround bug 3204 */
#define DOMLOCK(d) ((shared domlock_t *)(((shared [] char *)(d))+offsetof(dom_t, domlock)))
#else
#define DOMLOCK(d) ((shared domlock_t *)&((d)->domlock))
#endif
/* ------------------------------------------------------------------------------- */
/* dom_t: the internal domain datastructure, striped across threads */
typedef struct {
  #if DEBUG
  unsigned long long magic; /* for sanity checking */
  #endif

  /* Placement here works around BUPC bug 3231, and may avoid internal padding */
  domlock_t        domlock;

  /* the alloc arguments, replicated across threads */
  upc_type_t       type;
  upc_op_t         ops;
  upc_atomichint_t hints;
} dom_t;

/* ------------------------------------------------------------------------------- */
/* helper macros */

#define OPS_ACCESS  ((upc_op_t)(UPC_GET | UPC_SET | UPC_CSWAP))
#define OPS_BITWISE ((upc_op_t)(UPC_AND | UPC_OR | UPC_XOR))
#define OPS_NUMERIC ((upc_op_t)(UPC_ADD | UPC_SUB | UPC_MULT | \
                                UPC_INC | UPC_DEC | \
                                UPC_MAX | UPC_MIN))

#define OPS_ALL   (OPS_ACCESS | OPS_BITWISE | OPS_NUMERIC)
#define OPS_INT   OPS_ALL
#define OPS_PTS   OPS_ACCESS
#define OPS_FLOAT (OPS_ACCESS | OPS_NUMERIC)

#define UNSUPPORTED_TYPES(func)                                            \
      case UPC_CHAR:    func(signed char,        UPC_CHAR,    INT); break; \
      case UPC_UCHAR:   func(unsigned char,      UPC_UCHAR,   INT); break; \
      case UPC_SHORT:   func(short,              UPC_SHORT,   INT); break; \
      case UPC_USHORT:  func(unsigned short,     UPC_USHORT,  INT); break; \
      case UPC_LLONG:   func(long long,          UPC_LLONG,   INT); break; \
      case UPC_ULLONG:  func(unsigned long long, UPC_ULLONG,  INT); break; \
      case UPC_INT8:    func(int8_t,             UPC_INT8,    INT); break; \
      case UPC_UINT8:   func(uint8_t,            UPC_UINT8,   INT); break; \
      case UPC_INT16:   func(int16_t,            UPC_INT16,   INT); break; \
      case UPC_UINT16:  func(uint16_t,           UPC_UINT16,  INT); break; \
      case UPC_LDOUBLE: func(long double,        UPC_LDOUBLE, FLOAT); break;   

typedef shared void *svp_t; // typedef to prevent warnings about duplicate shared quals

#define SWITCH_TYPE(t, func, unsup_func, nomatch) do {                 \
    upc_type_t _t = (t);                                               \
    switch (_t) {                                                      \
      case UPC_INT32:   func(int32_t,       UPC_INT32,  INT);   break; \
      case UPC_UINT32:  func(uint32_t,      UPC_UINT32, INT);   break; \
      case UPC_INT64:   func(int64_t,       UPC_INT64,  INT);   break; \
      case UPC_UINT64:  func(uint64_t,      UPC_UINT64, INT);   break; \
      case UPC_INT:     func(int,           UPC_INT,    INT);   break; \
      case UPC_UINT:    func(unsigned int,  UPC_UINT,   INT);   break; \
      case UPC_LONG:    func(long,          UPC_LONG,   INT);   break; \
      case UPC_ULONG:   func(unsigned long, UPC_ULONG,  INT);   break; \
      case UPC_FLOAT:   func(float,         UPC_FLOAT,  FLOAT); break; \
      case UPC_DOUBLE:  func(double,        UPC_DOUBLE, FLOAT); break; \
      case UPC_PTS:     func(svp_t,         UPC_PTS,    PTS);   break; \
      UNSUPPORTED_TYPES(unsup_func)                                    \
      default: nomatch;                                                \
    }                                                                  \
} while(0)

#define NOOP3(a,b,c)
#define FATAL3(a,b,c) fatal("Invalid or corrupted upc_atomicdomain_t")

/* ------------------------------------------------------------------------------- */
static const char *type_str(upc_type_t type) {
  static char tmp[80];
  #define RETURN_TYPE_STR(ctype, typemacro, typecat) return #typemacro;
  SWITCH_TYPE(type, RETURN_TYPE_STR, RETURN_TYPE_STR, );
  sprintf(tmp, "Unknown upc_type_t (%d)", (int)type);
  return tmp;
}
/* ------------------------------------------------------------------------------- */
static const char *op_str(upc_op_t op) {
  static char tmp[80];
  #define RETURN_OP_STR(o) if (op == o) return #o
  RETURN_OP_STR(UPC_AND);
  RETURN_OP_STR(UPC_OR);
  RETURN_OP_STR(UPC_XOR);
  RETURN_OP_STR(UPC_ADD);
  RETURN_OP_STR(UPC_SUB);
  RETURN_OP_STR(UPC_MULT);
  RETURN_OP_STR(UPC_MIN);
  RETURN_OP_STR(UPC_MAX);
  RETURN_OP_STR(UPC_INC);
  RETURN_OP_STR(UPC_DEC);
  RETURN_OP_STR(UPC_CSWAP);
  RETURN_OP_STR(UPC_SET);
  RETURN_OP_STR(UPC_GET);
  sprintf(tmp, "Unknown upc_op_t (%d)", (int)op);
  return tmp;
}
/* ------------------------------------------------------------------------------- */
static void check_valid_typeop(upc_type_t type, upc_op_t ops) {
  #define CHECKOP_TYPE(ctype, typemacro, typecat) \
    if (ops & ~OPS_##typecat) fatal("Unsupported upc_op_t value for type " #typemacro); 
  #define UNSUP_TYPE(ctype, typemacro, typecat) \
    fatal(#typemacro " is not a supported upc_type_t type for upc_atomic"); 
  SWITCH_TYPE(type, CHECKOP_TYPE, UNSUP_TYPE, fatal("Unrecognized upc_type_t type argument"));
}
/* ------------------------------------------------------------------------------- */
int rupc_atomic_isfast(upc_type_t type, upc_op_t ops, shared void *addr) {
  CONTEXT("upc_atomic_isfast");
  CHECK_NONNULL(addr);
  CHECK_VALIDOPS(ops);
  #if DEBUG
    check_valid_typeop(type, ops);
  #endif
  return upc_threadof(addr) == MYTHREAD;
}
/* ------------------------------------------------------------------------------- */
upc_atomicdomain_t *rupc_all_atomicdomain_alloc(upc_type_t type, upc_op_t ops, upc_atomichint_t hints) {
  CONTEXT("upc_all_atomicdomain_alloc");
  CHECK_SINGLE(type);
  CHECK_SINGLE(ops);
  CHECK_SINGLE(hints);
  CHECK_VALIDOPS(ops);
  check_valid_typeop(type, ops);
  shared dom_t *d = upc_all_alloc(THREADS, sizeof(dom_t));
  assert(d);
  shared dom_t *md = d+MYTHREAD;
  md->type = type;
  md->ops = ops;
  md->hints = hints;
  #if DEBUG
    md->magic = MAGIC;
  #endif
  lock_alloc(DOMLOCK(d)); /* comes last and may include barrier */
  CHECK_DOMAIN(d);
  return (upc_atomicdomain_t *)d;
}

/* ------------------------------------------------------------------------------- */
void rupc_all_atomicdomain_free(upc_atomicdomain_t *ptr) {
  CONTEXT("upc_all_atomicdomain_free");
  CHECK_SINGLE_PTR(ptr);
  if (!ptr) return;
  upc_barrier;
  CHECK_DOMAIN(ptr);
  shared dom_t *d = (shared dom_t *)ptr;
  shared dom_t *md = d+MYTHREAD;
  upc_barrier;
  #if DEBUG
    md->magic = (unsigned long long)-1;
  #endif
  lock_free(DOMLOCK(d));
  #if _RUPC_HAVE_UPC13
    upc_all_free(d);
  #else
    if (!MYTHREAD) upc_free(d);
  #endif
}
/* ------------------------------------------------------------------------------- */
static void rupc_atomic_op(upc_atomicdomain_t *domain,
    void * restrict fetch_ptr, upc_op_t op,
    shared void * restrict target,
    const void * restrict operand1,
    const void * restrict operand2) {
  CHECK_NONNULL(domain);
  CHECK_NONNULL(target);
  CHECK_VALIDOP(op);
  CHECK_DOMAIN(domain);
  shared dom_t *d = (shared dom_t *)domain;
  shared dom_t *md = d+MYTHREAD;
  #if DEBUG
    if (!(op & md->ops)) fatal("%s invalid for this domain", op_str(op));
    if (op == UPC_GET && !fetch_ptr) fatal("fetch_ptr must be non-null for UPC_GET");
    if (op == UPC_GET || op == UPC_INC || op == UPC_DEC) {
      if (operand1) fatal("operand1 must be null for %s", op_str(op));
    } else {
      if (!operand1) fatal("operand1 must not be null for %s", op_str(op));
    }
    if (op == UPC_CSWAP) {
      if (!operand2) fatal("operand2 must not be null for %s", op_str(op));
    } else {
      if (operand2) fatal("operand2 must be null for %s", op_str(op));
    }
    if ((fetch_ptr && fetch_ptr == operand1) || 
        (fetch_ptr && fetch_ptr == operand2) || 
        (operand1 && operand1 == operand2))
      fatal("pointer arguments must not alias (restrict)");
    if (upc_threadof(target) == MYTHREAD) {
       void *ltarget = (void *)target;
       if (ltarget == fetch_ptr || ltarget == operand1 || ltarget == operand2)
         fatal("pointer arguments must not alias (restrict)");
    }
  #endif
  upc_lock_t *lock = lock_fetch(DOMLOCK(d), target);
  upc_lock(lock); /* acquire */
  { 
    upc_type_t type = md->type;
    int write = 1;

    #define OP_CASES_ACCESS(T)                                                 \
        case UPC_SET:   newval = *operand1_t;                           break; \
        case UPC_GET:   write = 0; /* omit write */                     break; \
        case UPC_CSWAP: if (oldval == *operand1_t) newval = *operand2_t;       \
                        else write = 0; /* omit write */                       \
                        break;                                                    
    #define OP_CASES_BITWISE(T)                                                \
        case UPC_AND:   newval = oldval & *operand1_t;                  break; \
        case UPC_OR:    newval = oldval | *operand1_t;                  break; \
        case UPC_XOR:   newval = oldval ^ *operand1_t;                  break; 
    #define OP_CASES_NUMERIC(T)                                                \
        case UPC_INC:   newval = oldval + 1;                            break; \
        case UPC_DEC:   newval = oldval - 1;                            break; \
        case UPC_ADD:   newval = oldval + *operand1_t;                  break; \
        case UPC_SUB:   newval = oldval - *operand1_t;                  break; \
        case UPC_MULT:  newval = oldval * *operand1_t;                  break; \
        case UPC_MIN: { T op1 = *operand1_t; newval = MIN(oldval,op1);  break; } \
        case UPC_MAX: { T op1 = *operand1_t; newval = MAX(oldval,op1);  break; } 

    #define OP_CASES_INT(T)    OP_CASES_ACCESS(T) OP_CASES_BITWISE(T) OP_CASES_NUMERIC(T)
    #define OP_CASES_FLOAT(T)  OP_CASES_ACCESS(T) OP_CASES_NUMERIC(T)
    #define OP_CASES_PTS(T)    OP_CASES_ACCESS(T)

    #define PERFORMOP_TYPE(T, typemacro, typecat) do {                   \
      T oldval; T newval;                                                \
      T *fetch_t = (void *)fetch_ptr; /* avoid optimizer bug 3211 */     \
      T const *operand1_t = (void *)operand1;                            \
      T const *operand2_t = (void *)operand2;                            \
      if (op == UPC_SET && !fetch_ptr) ; /* omit read */                 \
      else oldval = *(shared T *)target;                                 \
      if (fetch_t) *fetch_t = oldval;                                    \
      switch (op) {                                                      \
        OP_CASES_##typecat(T)                                            \
        default: fatal("Invalid or corrupted upc_atomicdomain_t");       \
      }                                                                  \
      if (write) *(shared T *)target = (T)newval; /* cast for bug 3271 */\
    } while (0)

    SWITCH_TYPE(type, PERFORMOP_TYPE, 
                FATAL3, fatal("Invalid or corrupted upc_atomicdomain_t"));
  }

  upc_unlock(lock); /* release */
}
/* ------------------------------------------------------------------------------- */
void rupc_atomic_strict(upc_atomicdomain_t *domain,
    void * restrict fetch_ptr, upc_op_t op,
    shared void * restrict target,
    const void * restrict operand1,
    const void * restrict operand2) {
  CONTEXT("upc_atomic_strict");
  /* all ops are done with full-blown locking, which satisfies the requirements of strict */
  rupc_atomic_op(domain, fetch_ptr, op, target, operand1, operand2);
}

void rupc_atomic_relaxed(upc_atomicdomain_t *domain,
    void * restrict fetch_ptr, upc_op_t op,
    shared void * restrict target,
    const void * restrict operand1,
    const void * restrict operand2) {
  CONTEXT("upc_atomic_relaxed");
  rupc_atomic_op(domain, fetch_ptr, op, target, operand1, operand2);
}
/* ------------------------------------------------------------------------------- */

