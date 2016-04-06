/*
 * UPC Semaphores, a Berkeley UPC extension 
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_sem.c $
 * Dan Bonachea <bonachea@cs.berkeley.edu>
 */

#include <upcr.h>
#include <upcr_internal.h>

#ifdef UPCR_DEBUG
  #define UPCR_SEM_DEBUG 1
#endif
#ifndef UPCRI_ALLOW_SINGLE_PUT
#define UPCRI_ALLOW_SINGLE_PUT 1
#endif

#define UNIMPLEMENTED() upcri_err("Function not implemented")

#define UPCRI_SEM_INTEGER     0x1
#define UPCRI_SEM_MPRODUCER   0x2
#define UPCRI_SEM_MCONSUMER   0x4
#define UPCRI_SEM_FLAGMASK    0x7
#define UPCRI_SEM_ALIGN       (UPCRI_SEM_FLAGMASK+1)

#define UPCRI_SEM_IS_INTEGER(flags)     ((flags) & UPCRI_SEM_INTEGER)
#define UPCRI_SEM_IS_BOOLEAN(flags)   (!((flags) & UPCRI_SEM_INTEGER))
#define UPCRI_SEM_IS_MPRODUCER(flags)   ((flags) & UPCRI_SEM_MPRODUCER)
#define UPCRI_SEM_IS_SPRODUCER(flags) (!((flags) & UPCRI_SEM_MPRODUCER))
#define UPCRI_SEM_IS_MCONSUMER(flags)   ((flags) & UPCRI_SEM_MCONSUMER)
#define UPCRI_SEM_IS_SCONSUMER(flags) (!((flags) & UPCRI_SEM_MCONSUMER))

#define UPCRI_SEM_MAGIC       ((uint64_t)0xf08b3f60c35e11d9ULL)

#ifndef UPCRI_SEMTABLE_SZ
  #define UPCRI_SEMTABLE_SZ 16
#endif
#if !(UPCRI_SEMTABLE_SZ == 65536 || UPCRI_SEMTABLE_SZ == 256 || \
      UPCRI_SEMTABLE_SZ == 16 || UPCRI_SEMTABLE_SZ == 4 || \
      UPCRI_SEMTABLE_SZ == 2 || UPCRI_SEMTABLE_SZ == 1)
#error unsupported UPCRI_SEMTABLE_SZ
#endif

typedef uint32_t upcri_sem_ctr_t; 

/* fragmentation tables for signalling puts */
typedef struct _upcri_semtable_entry {
  gasnet_node_t srcthread;
  upcri_sem_seqnum_t seqnum;
  upcri_sem_ctr_t counterval;
  struct _upcri_semtable_entry *next;
} upcri_semtable_entry_t;

typedef struct _upcri_semtable {
  gasnet_hsl_t hsl; /* protects this entire linked list */
  upcri_semtable_entry_t *list;
} upcri_semtable_t;

typedef struct _upcri_sem {
  union {
    volatile upcri_sem_ctr_t int_ctr; /* used for integer semaphores when CAS not available */
    gasnett_atomic_t atomic_ctr;  /* used in all other cases */
  } userval;
  gasnet_hsl_t hsl; /* protects read-to-decrement linkage and frag_table ptr  */
  upcr_shared_ptr_t allocptr;
  upcri_semtable_t *frag_table; /* table of fragmented ops in-flight */
  #if UPCRI_ALLOW_SINGLE_PUT
    unsigned int inittable_idx;
    void *tiny_data; /* points to upcri_semproducer_t or list of upcri_semtarget_t */
    void *queued_pst; /* connection requests */
  #endif
  #if UPCR_SEM_DEBUG
    uint64_t magic;
    int flags;
    upcr_thread_t srcthread; /* for SPRODUCER */
    int srcthread_set;
  #endif
} upcri_sem_t;

#define UPCRI_GET_SEM_P_LOCAL(ps) \
  ((upcri_sem_t *)((uintptr_t)(ps) & ~(uintptr_t)UPCRI_SEM_FLAGMASK))
#define UPCRI_GET_SEM_P(s) \
  UPCRI_GET_SEM_P_LOCAL(upcri_pshared_to_remote(s))
#define UPCRI_GET_SEM_P_THSLICE(s,th) \
  UPCRI_GET_SEM_P_LOCAL(upcri_pshared_to_remote_withthread(s,th))
#define UPCRI_GET_SEM_FLAGS_LOCAL(ps) \
  ((int)((uintptr_t)(ps) & (uintptr_t)UPCRI_SEM_FLAGMASK))
#define UPCRI_GET_SEM_FLAGS(s) \
  UPCRI_GET_SEM_FLAGS_LOCAL(upcri_pshared_to_remote(s))

#if UPCR_SEM_DEBUG
  #define UPCRI_CHECK_SEM_LOCAL(ps) do {                                       \
      upcri_assert(ps == (upcri_sem_t *)UPCRI_ALIGNDOWN(ps, UPCRI_SEM_ALIGN)); \
      upcri_assert((ps->flags & ~(int)UPCRI_SEM_FLAGMASK) == 0);               \
      upcri_assert(ps->magic == UPCRI_SEM_MAGIC);                              \
    } while (0)
  #define UPCRI_CHECK_SEM(s) do {                                                     \
      upcri_sem_t *_tmp_ps = UPCRI_GET_SEM_P(s);                                      \
      int _tmp_flags = UPCRI_GET_SEM_FLAGS(s);                                        \
      upcri_assert(upcri_pshared_nodeof(s) == gasnet_mynode());                       \
      upcri_assert(_tmp_flags == _tmp_ps->flags);                                     \
      if (UPCRI_SEM_CAN_TINYPUT(_tmp_flags)) {                                        \
        void *ps = UPCRI_GET_SEM_P_THSLICE(s,upcr_mythread());                        \
        upcri_assert(upcr_threadof_shared(_tmp_ps->allocptr) == 0);                   \
        upcri_assert((void *)UPCRI_ALIGNDOWN(                                         \
                     upcri_pshared_to_remote_withthread(s,upcr_mythread()),           \
                     UPCRI_SEM_ALIGN) == ps);                                         \
        upcri_assert((void *)UPCRI_ALIGNUP(                                           \
                      upcri_shared_remote_to_mylocal(_tmp_ps->allocptr),              \
                      UPCRI_SEM_ALIGN) == ps);                                        \
      } else {                                                                        \
        upcri_assert(UPCRI_ALIGNDOWN(upcri_pshared_to_remote(s), UPCRI_SEM_ALIGN) ==  \
          UPCRI_ALIGNUP(upcri_shared_to_remote(_tmp_ps->allocptr), UPCRI_SEM_ALIGN)); \
      }                                                                               \
      UPCRI_CHECK_SEM_LOCAL(_tmp_ps);                                                 \
    } while (0)
#else
  #define UPCRI_CHECK_SEM_LOCAL(ps) ((void)0)
  #define UPCRI_CHECK_SEM(s)        ((void)0)
#endif

#if UPCR_SEM_DEBUG
  #define UPCRI_CHECK_OVERFLOW(ps, flags, n) do {                      \
    /* cannot portably rely on huge atomic_t values */                 \
    upcri_assert(BUPC_SEM_MAXVALUE < (1<<30));                         \
    /* there a race here, but it's relatively benign */                \
    if ((n) > BUPC_SEM_MAXVALUE ||                                     \
      (UPCRI_SEM_USERVAL(ps,flags)+(n)) > BUPC_SEM_MAXVALUE)           \
       upcri_err("bupc_sem_post incremented a semaphore value beyond " \
             "BUPC_SEM_MAXVALUE limit of %i", (int)BUPC_SEM_MAXVALUE); \
  } while (0)
#else
  #define UPCRI_CHECK_OVERFLOW(ps, flags, n) ((void)0)
#endif

#if GASNETT_HAVE_ATOMIC_CAS
  #define UPCRI_SEM_USERVAL(ps, flags) gasnett_atomic_read(&((ps)->userval.atomic_ctr), 0)
#else
  #define UPCRI_SEM_USERVAL(ps, flags) \
    (UPCRI_SEM_IS_INTEGER(flags) ? ((ps)->userval.int_ctr) : gasnett_atomic_read(&((ps)->userval.atomic_ctr),0))
#endif

#define _UPCRI_SEM_USERUP_ATOMIC(ps, flags, n) do {                     \
    gasnett_atomic_t *_ptr = &((ps)->userval.atomic_ctr);               \
    upcri_sem_ctr_t _inc = (n);                                         \
    UPCRI_CHECK_OVERFLOW(ps, flags, _inc);                              \
    if (UPCRI_SEM_IS_BOOLEAN(flags)) /* boolean up => just set */       \
      gasnett_atomic_set(_ptr,1,0);                                     \
    else if (_inc == 1) /* simple increment */                          \
      gasnett_atomic_increment(_ptr,0);                                 \
    else /* general increment */                                        \
      upcri_atomicadd(_ptr,_inc);                                       \
  } while (0)
#if GASNETT_HAVE_ATOMIC_ADD_SUB
  #define upcri_atomicadd(ptr,inc) gasnett_atomic_add(ptr,inc,0)
#elif GASNETT_HAVE_ATOMIC_CAS
  /* Should never happen - GASNet will implement this if needed */
  #define upcri_atomicadd(ptr,inc) do {                  \
    upcri_sem_ctr_t _readval;                            \
    do {                                                 \
      _readval = gasnett_atomic_read(ptr,0);             \
    } while (!upcri_cas(ptr,_readval,_readval+inc,0));   \
  } while (0)
#else
  #define upcri_atomicadd(ptr,inc) (upcri_err("internal error in upcri_atomicadd"),0)
#endif
#if GASNETT_HAVE_ATOMIC_CAS
  #define UPCRI_SEM_USERUP(ps, flags, n) _UPCRI_SEM_USERUP_ATOMIC(ps, flags, n)
  #define upcri_cas(ptr,oldval,newval,f) gasnett_atomic_compare_and_swap(ptr,oldval,newval,f)
#else
  #define UPCRI_SEM_USERUP(ps, flags, n) do {            \
      upcri_sem_ctr_t _inc2 = (n);                       \
      if (UPCRI_SEM_IS_INTEGER(flags)) {                 \
        gasnet_hsl_lock(&(ps->hsl));                     \
          UPCRI_CHECK_OVERFLOW(ps, flags, _inc2);        \
          (ps)->userval.int_ctr += _inc2;                \
        gasnet_hsl_unlock(&(ps->hsl));                   \
      } else _UPCRI_SEM_USERUP_ATOMIC(ps, flags, _inc2); \
    } while (0)
  #define upcri_cas(ptr,oldval,newval,f) (upcri_err("internal error in upcri_cas"),0)
#endif

#if UPCR_SEM_DEBUG
  #define UPCRI_SEM_REGISTER_SPRODUCER(ps, th) do {                               \
    upcr_thread_t _th = (th);                                                     \
    upcri_assert(UPCRI_SEM_IS_SPRODUCER(ps->flags));                              \
    if (ps->srcthread_set) {                                                      \
      if (ps->srcthread != _th) {                                                 \
        upcri_err("a bupc_sem_t object created with BUPC_SEM_SPRODUCER"           \
                  " was signaled by two threads: %i and %i, which is prohibited", \
          (int)ps->srcthread, (int)_th);                                          \
      }                                                                           \
    } else {                                                                      \
      ps->srcthread = _th;                                                        \
      ps->srcthread_set = 1;                                                      \
    }                                                                             \
  } while (0)
#else
  #define UPCRI_SEM_REGISTER_SPRODUCER(ps, th) ((void)0)
#endif

#if GASNET_STATS
  #define UPCRI_SEM_STATS(expr) do { upcri_myseminfo()->expr; } while (0)
#else
  #define UPCRI_SEM_STATS(expr) ((void)0)
#endif
#ifdef GASNET_TRACE
  #define UPCRI_TRACE_SEMFLAGS(encodedflags)                                          \
    (UPCRI_SEM_IS_INTEGER(encodedflags)  ?"BUPC_SEM_INTEGER":  "BUPC_SEM_BOOLEAN"),   \
    (UPCRI_SEM_IS_MPRODUCER(encodedflags)?"BUPC_SEM_MPRODUCER":"BUPC_SEM_SPRODUCER"), \
    (UPCRI_SEM_IS_MCONSUMER(encodedflags)?"BUPC_SEM_MCONSUMER":"BUPC_SEM_SCONSUMER")  
  #define UPCRI_TRACE_SEMOP(name, semptr, val) do {                                     \
      char _ptrstr[UPCRI_DUMP_MIN_LENGTH];                                              \
      upcri_dump_shared(upcr_pshared_to_shared(semptr), _ptrstr, UPCRI_DUMP_MIN_LENGTH); \
      UPCRI_TRACE_PRINTF(("SEM " #name "(%s, %i) [%s|%s|%s]", _ptrstr, (int)(val),      \
        UPCRI_TRACE_SEMFLAGS(UPCRI_GET_SEM_FLAGS(semptr))));                            \
    } while (0)
#else
  #define UPCRI_TRACE_SEMFLAGS(encodedflags)    ((void)0)
  #define UPCRI_TRACE_SEMOP(name, semptr, val)  ((void)0)
#endif
/* ------------------------------------------------------------------------------------ */
/* subsystem global state vars */
static size_t upcri_sem_maxmed_threshold = 0;
#if UPCRI_ALLOW_SINGLE_PUT
  /* maxpayload - largest data payload eligble for tinypacket */
  #if defined(GASNET_CONDUIT_IBV)
    static size_t upcri_sem_tinypacket_maxpayload = 255; /* empirically determined cross-over on jacquard */
  #else
    static size_t upcri_sem_tinypacket_maxpayload = 32;
  #endif
  /* depth - depth of the tinypacket queue (0 == disable) */
  #if defined(GASNET_CONDUIT_MPI) || \
      defined(GASNET_CONDUIT_UDP)
    /* the tinypacket algorithm is designed for conduits where RDMA is significantly
       faster that AM. It's expected to be slower on core-only conduits, and any
       that don't match the performance profile, so disable by default on those */
    static size_t upcri_sem_tinypacket_depth = 0;
  #else
    static size_t upcri_sem_tinypacket_depth = 32;
  #endif
  /* number of tokens for controlling the queue */
  static int upcri_sem_tinypacket_payloadwidth = 1;
  static size_t upcri_sem_tinypacket_numtokens = 2;
  static size_t upcri_sem_tinypacket_tokensz = (size_t)-1;
  static size_t upcri_sem_tinypacket_bufsz = 0;
#endif
/* subsystem initialization */
static int _upcri_sem_isinit = 0;
#define upcri_sem_init() if_pf (!_upcri_sem_isinit) _upcri_sem_init()
static gasnet_hsl_t upcri_init_hsl = GASNET_HSL_INITIALIZER;
void _upcri_sem_init(void) {
  gasnet_hsl_lock(&upcri_init_hsl);
  if (!_upcri_sem_isinit) {

    /* choose an intelligent default */
    #if defined(GASNET_CONDUIT_IBV) || \
        defined(GASNET_CONDUIT_PORTALS4) || \
        defined(GASNET_CONDUIT_GEMINI) || \
        defined(GASNET_CONDUIT_ARIES)
      /* "packed longs" are just as efficient as mediums, so save the copy costs */
      upcri_sem_maxmed_threshold = 0;
    #else
      upcri_sem_maxmed_threshold = MIN(gasnet_AMMaxMedium(), UPCR_PAGESIZE); /* reasonably sane default */
    #endif
    upcri_sem_maxmed_threshold = gasnett_getenv_int_withdefault("UPC_SEM_MAXMEDIUM", upcri_sem_maxmed_threshold, 1);

  #if UPCRI_ALLOW_SINGLE_PUT
    upcri_sem_tinypacket_maxpayload = gasnett_getenv_int_withdefault("UPC_SEM_MAXTINY", upcri_sem_tinypacket_maxpayload, 1);
    if (upcri_sem_tinypacket_maxpayload <= 255) {
      upcri_sem_tinypacket_payloadwidth = 1;
    } else if (upcri_sem_tinypacket_maxpayload <= 65535) {
      upcri_sem_tinypacket_payloadwidth = 2;
    } else {
      upcri_err("UPC_SEM_MAXTINY must be <= 65535");
    }
    upcri_sem_tinypacket_depth = gasnett_getenv_int_withdefault("UPC_SEM_TINYDEPTH", upcri_sem_tinypacket_depth, 0);
    if (upcri_sem_tinypacket_depth > 4096) {
      upcri_err("UPC_SEM_TINYDEPTH must be <= 4096 (0 disables tiny sem packets)"); /* sanity check */
    } else if (upcri_sem_tinypacket_depth == 0) { /* disable tinypackets */
      upcri_sem_tinypacket_maxpayload = 0;
    } else {
        if (upcri_sem_tinypacket_numtokens > upcri_sem_tinypacket_depth) {
          upcri_sem_tinypacket_numtokens = upcri_sem_tinypacket_depth;
        }
        upcri_sem_tinypacket_tokensz = upcri_sem_tinypacket_depth/upcri_sem_tinypacket_numtokens;
    }
    upcri_sem_tinypacket_bufsz = UPCRI_ALIGNUP(2*(1 + upcri_sem_tinypacket_payloadwidth) +
                                               sizeof(void*) + 
                                               upcri_sem_tinypacket_maxpayload,
                                               GASNETT_CACHE_LINE_BYTES);
  #endif

    gasnett_local_wmb();
    _upcri_sem_isinit = 1;
  }
  gasnet_hsl_unlock(&upcri_init_hsl);
}
/* ------------------------------------------------------------------------------------ */
/* tinypacket support */
#if UPCRI_ALLOW_SINGLE_PUT
  #define UPCRI_SEM_CAN_TINYPUT(flags) (upcri_sem_tinypacket_depth)
#else
  #define UPCRI_SEM_CAN_TINYPUT(flags) 0
#endif

#if UPCRI_ALLOW_SINGLE_PUT
  struct upcri_semtarget_S;

  typedef struct upcri_semproducer_S { /* producer-side metadata */
    unsigned int head;
    gasnett_atomic_t connection_established; /* 0=request sent, 1=request acknowledged, 2=connected */
    struct upcri_semtarget_S *target; /* remote recvbuf addr */
    upcr_shared_ptr_t allocptr; /* allocated addr of this data stucture */
    gasnet_handle_t *handles;
    struct upcri_semproducer_S *next; /* freequeue linkage (protected by inithsl) */
  } upcri_semproducer_t;

  #define UPCRI_SEMPRODUCER_SLOTS(psp) \
    ((uint8_t*)UPCRI_ALIGNUP((((upcri_semproducer_t*)(psp))+1),GASNETT_CACHE_LINE_BYTES))

  typedef struct upcri_semtarget_S {  /* target-side metadata */
    unsigned int head;
    upcr_thread_t srcthread;
    gasnet_node_t srcnode;
    void *srctoken;
    upcri_semproducer_t *producer; /* remote sendbuf addr */
    upcr_shared_ptr_t allocptr; /* allocated addr of this data stucture */
    struct upcri_semtarget_S *next; /* linkage protected by mysem->hsl */
  } upcri_semtarget_t;

  #define UPCRI_SEMTARGET_SLOTS(pst) \
    ((uint8_t*)UPCRI_ALIGNUP((((upcri_semtarget_t*)(pst))+1),GASNETT_CACHE_LINE_BYTES))

/* unpacked wire protocol struct */
typedef struct {
  uint8_t seminc;
  uint16_t databytes;
  uint16_t zerocnt;
  void *dataptr;
  uint8_t datapayload[1/*upcri_sem_tinypacket_maxpayload*/];
} upcri_tinypacket_fields_t;
#define UPCRI_TINY_HDRSZ (2*(1+2*upcri_sem_tinypacket_payloadwidth))

void *upcri_tinypacket_prepare_recvbuf(void *tpacket, size_t len) {
  uint8_t *p = tpacket;
  uint8_t val = 0;
  upcri_assert(len % 2 == 0);
  while (len--) {
    *p = val;
    val = ~val;
    p++;
  }
  return p;
}

/* consume bytes from an incoming tinypacket, copy them into dst and return offset tinypacket ptr */
GASNETT_INLINE(upcri_tinypacket_recv_bytes)
void *upcri_tinypacket_recv_bytes(void *tpacket_src, void *databuf_dst, size_t len) {
  uint8_t *src = tpacket_src;
  uint8_t *dst = databuf_dst;

  while (len--) {
    uint8_t tmpval;
    while ((tmpval = src[0]) != src[1]) gasnet_AMPoll();
    src[0] = 0; src[1] = (uint8_t)-1;
    *dst = tmpval;
    src += 2; dst++;
  }
  return src;
}

GASNETT_INLINE(upcri_tinypacket_recv_zerochk_bytes)
void upcri_tinypacket_recv_zerochk_bytes(void *tpacket_src, void *databuf_dst, size_t len, size_t zerocnt) {
 retry:
 {
#if 1 
  size_t const curzerocnt = gasnett_count0s_copy(databuf_dst, tpacket_src, len);
#else /* naive, byte-oriented copy and count */
  uint8_t * const src = tpacket_src;
  uint8_t * const dst = databuf_dst;
  size_t curzerocnt, i;
    curzerocnt = 0;
    for (i = 0; i < len; i++) {
      uint8_t const tmpval = src[i];
      dst[i] = tmpval;
      if (!tmpval) curzerocnt++;
    }
#endif
  if (curzerocnt != zerocnt) {
    upcri_assert(curzerocnt > zerocnt);
    gasnet_AMPoll();
    goto retry;
  }
 }
  memset(tpacket_src, 0, len);
}

/* copy bytes from source memory into an outgoing tinypacket, and return offset tinypacket ptr */
GASNETT_INLINE(upcri_tinypacket_pack_send_bytes)
void *upcri_tinypacket_pack_send_bytes(void *tpacket_dst, const void *databuf_src, size_t len) {
  uint8_t const *src = databuf_src;
  uint8_t *dst = tpacket_dst;

  while (len--) {
    uint8_t tmpval = *src;
    dst[0] = tmpval; dst[1] = tmpval;
    src++; dst += 2;
  }
  return dst;
}

/* copy zerochk bytes from source memory into an outgoing tinypacket, and return zerocnt */
#if 1
  #define upcri_tinypacket_pack_send_zerochk_bytes gasnett_count0s_copy
#else  /* naive, byte-oriented copy and count */
GASNETT_INLINE(upcri_tinypacket_pack_send_zerochk_bytes)
size_t upcri_tinypacket_pack_send_zerochk_bytes(void *tpacket_dst, const void *databuf_src, size_t len) {
  uint8_t const * const src = databuf_src;
  uint8_t * const dst = tpacket_dst;
  size_t i, zerocnt = 0;

  for (i = 0; i < len; i++) {
    uint8_t const tmpval = src[i];
    dst[i] = tmpval;
    if (!tmpval) zerocnt++;
  }
  return zerocnt;
}
#endif

/* accept any incoming connection requests */
void _upcri_sem_tinyaccept(upcri_sem_t *ps, int flags UPCRI_PT_ARG) {
  while (ps->queued_pst) { /* accept new connections */
    upcri_semtarget_t *queued_pst = NULL;
    gasnet_hsl_lock(&(ps->hsl));
      if (ps->queued_pst) {
        queued_pst = ps->queued_pst;
        ps->queued_pst = queued_pst->next;
      }
    gasnet_hsl_unlock(&(ps->hsl));
    if (queued_pst) {
      upcr_shared_ptr_t allocptr = upcr_alloc(sizeof(upcri_semtarget_t) + 
                 upcri_sem_tinypacket_depth*upcri_sem_tinypacket_bufsz + 
                 2*GASNETT_CACHE_LINE_BYTES);
      upcr_thread_t const srcthread = queued_pst->srcthread;
      gasnet_node_t const srcnode = upcri_thread_to_node(srcthread);
      upcri_semtarget_t * pst = upcr_shared_to_local(allocptr);
      pst = (void *)UPCRI_ALIGNUP(pst, GASNETT_CACHE_LINE_BYTES);
      if (UPCRI_SEM_IS_SPRODUCER(flags)) /* extra safety check */
        UPCRI_SEM_REGISTER_SPRODUCER(ps, srcthread);
      pst->allocptr = allocptr;
      pst->srcthread = srcthread;
      pst->srcnode = srcnode;
      pst->producer = queued_pst->producer;
      pst->head = 0;
      pst->srctoken = 0;
      upcri_free(queued_pst);

      { /* init tiny packet landing zones */
        uint8_t *p = UPCRI_SEMTARGET_SLOTS(pst);
        size_t const zerozonesz = upcri_sem_tinypacket_bufsz - UPCRI_TINY_HDRSZ;
        int i;
        for (i = 0; i < upcri_sem_tinypacket_depth; i++) {
            p = upcri_tinypacket_prepare_recvbuf(p, UPCRI_TINY_HDRSZ);
            memset(p, 0, zerozonesz);
            p += zerozonesz;
        }
      }
      gasnett_local_wmb();
      /* send connection acknowledgement */
      UPCRI_SEM_STATS(tinypacket_incoming_connections++);
      UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(4, 7, 
		    (srcnode, UPCRI_HANDLER_ID(upcri_SR_tinypacket_connect),
		     srcthread, UPCRI_SEND_PTR(NULL), UPCRI_SEND_PTR(pst->producer), UPCRI_SEND_PTR(pst))));
      pst->next = ps->tiny_data;
      ps->tiny_data = pst;
    }
  } /* while */
}

/* check for the arrival of tiny packets, and process them */
void _upcri_sem_tinypoll(upcr_pshared_ptr_t sem, upcri_sem_t *ps, int flags UPCRI_PT_ARG) {
  upcri_assert(UPCRI_SEM_CAN_TINYPUT(flags));
  if_pf (ps->queued_pst) _upcri_sem_tinyaccept(ps, flags UPCRI_PT_PASS);
  { /* poll for activity */
    upcri_semtarget_t *pst = ps->tiny_data;
    while (pst) {
      int const entry = pst->head;
      int const entryoffset = entry * upcri_sem_tinypacket_bufsz;
      uint8_t * const tpacket_slots = UPCRI_SEMTARGET_SLOTS(pst);
      uint8_t * tpacket = tpacket_slots + entryoffset;

      if (pst->srctoken) { /* send reply to clear remote flag, returning this token */
        if (!entry) { /* make progress on reaping puts we create here  */
          int nowarn = gasnet_try_syncnbi_puts(); 
          (void) nowarn;
        }
        gasnet_put_nbi_val(pst->srcnode, pst->srctoken, 0, 1);
        pst->srctoken = 0;
      }

      if (*tpacket) { /* recv the incoming tinypacket */
        upcri_tinypacket_fields_t fields;
        tpacket = upcri_tinypacket_recv_bytes(tpacket, &fields.seminc, 1);
        if (upcri_sem_tinypacket_payloadwidth == 1) {
          uint8_t tmp;
          tpacket = upcri_tinypacket_recv_bytes(tpacket, &tmp, 1);
          fields.databytes = tmp;
        } else {
          tpacket = upcri_tinypacket_recv_bytes(tpacket, &fields.databytes, 2);
        }
        if (fields.databytes) {
          int ptrchk = (fields.seminc >> 5);
          fields.seminc &= 0x1F;
          upcri_assert(fields.databytes <= upcri_sem_tinypacket_maxpayload);
          if (upcri_sem_tinypacket_payloadwidth == 1) {
            uint8_t tmp;
            tpacket = upcri_tinypacket_recv_bytes(tpacket, &tmp, 1);
            fields.zerocnt = tmp;
          } else {
            tpacket = upcri_tinypacket_recv_bytes(tpacket, &fields.zerocnt, 2);
          }
          upcri_tinypacket_recv_zerochk_bytes(tpacket, &fields.dataptr, sizeof(void*), ptrchk);
          tpacket = ((uint8_t*)tpacket) + (sizeof(void*));
          upcri_assert(fields.dataptr);
          upcri_tinypacket_recv_zerochk_bytes(tpacket, fields.dataptr, fields.databytes, fields.zerocnt);
          gasnett_local_wmb();
        }
        UPCRI_SEM_USERUP(ps, flags, fields.seminc);
        /* advance to next recv buffer */
        pst->head = (entry + 1) % upcri_sem_tinypacket_depth;
        if (pst->head % upcri_sem_tinypacket_tokensz == 0) { 
          /* enqueue a token return - send is delayed until next wait */
          upcri_semproducer_t * const rproducer = pst->producer;
          int const token_base = (entry / upcri_sem_tinypacket_tokensz) * upcri_sem_tinypacket_tokensz;
          pst->srctoken = UPCRI_SEMPRODUCER_SLOTS(rproducer) + (token_base * upcri_sem_tinypacket_bufsz);
        }
      }
      pst = pst->next;
    }
  }
}

/* establish a tinysem connection between tinysem producer and tinysem target */
void upcri_SR_tinypacket_connect(gasnet_token_t token, gasnet_handlerarg_t srcthread, void *_ps, void *_psp, void *_pst) {
  if (_pst) { /* connection established - (usually) final step */
    upcri_semproducer_t *psp = _psp;
    psp->target = _pst;
    gasnett_atomic_increment(&(psp->connection_established),GASNETT_ATOMIC_WMB_PRE);
  } else if (_ps == NULL) { /* connection request acknowledgement */
    upcri_semproducer_t *psp = _psp;
    gasnett_atomic_increment(&(psp->connection_established),0);
  } else { /* connection request - enqueue on the semaphore */
    upcri_sem_t * const ps = _ps;
    upcri_semtarget_t * const queued_pst = upcri_calloc(1,sizeof(upcri_semtarget_t));
    queued_pst->srcthread = srcthread;
    queued_pst->producer = _psp;
    gasnet_hsl_lock(&(ps->hsl));
      queued_pst->next = ps->queued_pst;
      ps->queued_pst = queued_pst;
    gasnet_hsl_unlock(&(ps->hsl));
    /* acknowledge that we've enqueued the connection request */
    UPCRI_AM_CALL(UPCRI_SHORT_REPLY(4, 7, 
		  (token, UPCRI_HANDLER_ID(upcri_SR_tinypacket_connect),
		   srcthread, UPCRI_SEND_PTR(NULL), UPCRI_SEND_PTR(_psp), UPCRI_SEND_PTR(NULL))));
  }
}

/* perform a tinypacket sem_up or signalling store 
   return nonzero on success, or zero if send resources exhausted
 */
int upcri_sem_tinyput(upcr_pshared_ptr_t sem, size_t seminc, gasnet_node_t node,
                       void *pdst, const void *psrc, size_t nbytes UPCRI_PT_ARG) {
  upcri_sem_t *ps = UPCRI_GET_SEM_P_THSLICE(sem, upcr_mythread());
  upcri_seminfo_t *myinfo = upcri_myseminfo();
  int idx = ps->inittable_idx;
  upcri_assert(node != gasnet_mynode());
  upcri_assert(UPCRI_SEM_CAN_TINYPUT(UPCRI_GET_SEM_FLAGS(sem)));
  upcri_assert(nbytes <= upcri_sem_tinypacket_maxpayload);

  if (idx >= myinfo->inittable_cnt || myinfo->inittable[idx] != ps) { /* first touch on this thread - init my local copy */
    int i;
    idx = -1;
    if (myinfo->inittable_cnt == myinfo->inittable_sz) { /* table full */
      for (i = 0; i < myinfo->inittable_cnt; i++) {
        if (myinfo->inittable[i] == NULL) { idx = i; break; }
      }
      if (idx < 0) { /* grow table */
        myinfo->inittable_sz = myinfo->inittable_sz*2 + 1;
        gasnet_hsl_lock(&upcri_init_hsl);
          myinfo->inittable = upcri_realloc(myinfo->inittable, 
                                            sizeof(void *) * myinfo->inittable_sz);
        gasnet_hsl_unlock(&upcri_init_hsl);
        idx = myinfo->inittable_cnt++;
      }
    } else {
      idx = myinfo->inittable_cnt++;
    }
    myinfo->inittable[idx] = ps;
    ps->inittable_idx = idx;
    { /* request a tinysem connection */
      upcr_thread_t srcthread = upcr_mythread();
      upcri_sem_t * const rps = UPCRI_GET_SEM_P(sem);
      upcr_shared_ptr_t allocptr = upcr_alloc(sizeof(upcri_semproducer_t) + 
             upcri_sem_tinypacket_depth*upcri_sem_tinypacket_bufsz + 
             2*GASNETT_CACHE_LINE_BYTES);
      uint8_t * tpacket_slots; 
      upcri_semproducer_t *psp = upcr_shared_to_local(allocptr);
      psp = (void *)UPCRI_ALIGNUP(psp, GASNETT_CACHE_LINE_BYTES);
      ps->tiny_data = psp;
      psp->head = 0;
      psp->handles = upcri_calloc(upcri_sem_tinypacket_depth, sizeof(gasnet_handle_t));
      psp->allocptr = allocptr;
      tpacket_slots = UPCRI_SEMPRODUCER_SLOTS(psp);
      for (i = 0; i < upcri_sem_tinypacket_depth; i++) {
        tpacket_slots[i*upcri_sem_tinypacket_bufsz] = 0;
      }
      psp->target = NULL; /* will be filled in once connection established */
      gasnett_atomic_set(&(psp->connection_established),0,GASNETT_ATOMIC_WMB_POST);
      /* Request to be enqueued for connection establishment */
      UPCRI_SEM_STATS(tinypacket_outgoing_connections++);
      UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(4, 7, 
		    (node, UPCRI_HANDLER_ID(upcri_SR_tinypacket_connect),
		     srcthread, UPCRI_SEND_PTR(rps), UPCRI_SEND_PTR(psp), UPCRI_SEND_PTR(NULL))));
      /* housekeeping */
      if (myinfo->freequeue) {
        upcri_semproducer_t * psp;
        gasnet_hsl_lock(&upcri_init_hsl);
          psp = myinfo->freequeue;
          myinfo->freequeue = NULL;
        gasnet_hsl_unlock(&upcri_init_hsl);
        while (psp) { /* bug 1739 - cannot syncnb while holding HSL */
          upcri_semproducer_t * const next = psp->next;
          gasnet_wait_syncnb_all(psp->handles, upcri_sem_tinypacket_depth);
          upcri_free(psp->handles);
          upcri_do_local_free(psp->allocptr);
          psp = next;
        }
      }
      /* must block here to ensure connection request is acknowledged before falling back to AM
         otherwise the target might subsequently free the sem before our connection request arrives
       */
      GASNET_BLOCKUNTIL(gasnett_atomic_read(&(psp->connection_established),0) > 0);
    }
  }

  { /* prepare the outgoing tinypacket */
    upcri_semproducer_t *psp = ps->tiny_data;
    uint8_t * const tpacket_slots = UPCRI_SEMPRODUCER_SLOTS(psp);
    upcri_tinypacket_fields_t fields;
    int const entry = psp->head;
    int const entryoffset = entry*upcri_sem_tinypacket_bufsz;
    uint8_t * const tpacket_base = tpacket_slots + entryoffset;
    uint8_t * tpacket = tpacket_base;

    /* still waiting for a connection */
    if (gasnett_atomic_read(&(psp->connection_established),GASNETT_ATOMIC_RMB_POST) < 2) {
      UPCRI_SEM_STATS(tinypacket_noconnection_cnt++);
      return 0;
    }

    if (entry % upcri_sem_tinypacket_tokensz == 0 && 
        *tpacket) { /* token containing this slot still in use remotely */
      UPCRI_SEM_STATS(tinypacket_backpressure_cnt++);
      return 0; /* failed */
    } else {
      UPCRI_SEM_STATS(tinypacket_send_cnt++);
      UPCRI_SEM_STATS(tinypacket_databytes += nbytes);
      psp->head = (entry + 1) % upcri_sem_tinypacket_depth;
    }

    upcri_assert(seminc > 0 && seminc < 32);
    if (nbytes) { 
      const int ptrchk = gasnett_count0s_uintptr_t((uintptr_t)pdst);
      upcri_assert(ptrchk < 8 && ptrchk >= 0);
      fields.seminc = (uint8_t)((ptrchk << 5) | seminc);
    } else fields.seminc = seminc;
    upcri_assert(nbytes <= upcri_sem_tinypacket_maxpayload);
    fields.databytes = nbytes;

    tpacket = upcri_tinypacket_pack_send_bytes(tpacket, &fields.seminc, 1);
    if (upcri_sem_tinypacket_payloadwidth == 1) {
      uint8_t tmp = fields.databytes;
      tpacket = upcri_tinypacket_pack_send_bytes(tpacket, &tmp, 1);
    } else {
      tpacket = upcri_tinypacket_pack_send_bytes(tpacket, &fields.databytes, 2);
    }
    if (nbytes) {
      void *pzerocnt = tpacket;
      tpacket = ((uint8_t*)tpacket) + (upcri_sem_tinypacket_payloadwidth<<1);
      memcpy(tpacket, &pdst, sizeof(void*));
      tpacket = ((uint8_t*)tpacket) + (sizeof(void*));
      if (upcri_sem_tinypacket_payloadwidth == 1) {
        uint8_t const zerocnt = upcri_tinypacket_pack_send_zerochk_bytes(tpacket, psrc, nbytes);
        upcri_tinypacket_pack_send_bytes(pzerocnt, &zerocnt, 1);
      } else {
        uint16_t const zerocnt = upcri_tinypacket_pack_send_zerochk_bytes(tpacket, psrc, nbytes);
        upcri_tinypacket_pack_send_bytes(pzerocnt, &zerocnt, 2);
      }
      tpacket += nbytes;
    }
    { uint8_t * rtpacket = UPCRI_SEMTARGET_SLOTS(psp->target) + entryoffset;
      /* send it - send buffers are explicitly recycled via token-based sync,
         but need to use NB sync here to prevent the very rare 'slow-zeros' race, where the target might
         mistakenly acknowledge the previous put from this send buffer while a packet full of zeros 
         from that previous put is still in-flight - syncing here ensures that's drained
       */
      psp->handles[entry] = gasnet_put_nb_bulk(node, rtpacket, tpacket_base, (tpacket-tpacket_base));
      if ((entry+1) % upcri_sem_tinypacket_tokensz == 0) { /* sync handles for next token */
        gasnet_wait_syncnb_all(&(psp->handles[(entry+1)%upcri_sem_tinypacket_depth]),
                               upcri_sem_tinypacket_tokensz);
      }
    }

    return 1; /* success */
  }
}
#define UPCRI_SEM_TINYPOLL(sem,ps,flags) \
   if (UPCRI_SEM_CAN_TINYPUT(flags)) _upcri_sem_tinypoll(sem,ps,flags UPCRI_PT_PASS)

#else /* !UPCRI_ALLOW_SINGLE_PUT */
  #define UPCRI_SEM_TINYPOLL(sem,ps,flags) ((void)0)
  void upcri_SR_tinypacket_connect(gasnet_token_t token, gasnet_handlerarg_t srcthread, void *_ps, void *_psp, void *_pst) { upcri_err("impossible call to upcri_SR_tinypacket_connect()"); }
#endif
/* ------------------------------------------------------------------------------------ */
upcr_pshared_ptr_t _bupc_sem_alloc(int _flags UPCRI_PT_ARG) {
  upcr_shared_ptr_t allocptr;
  upcr_pshared_ptr_t retval;
  upcri_sem_t *ps;
  int encoded_flags = 0;
  
  upcri_sem_init(); /* init semaphore subsystem, if necessary */

  if (_flags & ~(int)BUPC_SEM_MASK || 
      ((_flags & BUPC_SEM_BOOLEAN) && (_flags & BUPC_SEM_INTEGER)) ||
      ((_flags & BUPC_SEM_SPRODUCER) && (_flags & BUPC_SEM_MPRODUCER)) ||
      ((_flags & BUPC_SEM_SCONSUMER) && (_flags & BUPC_SEM_MCONSUMER))) 
      upcri_err("bad flags to bupc_sem_alloc(): %i", _flags);
  if (!(_flags & BUPC_SEM_BOOLEAN))   encoded_flags |= UPCRI_SEM_INTEGER;
  if (!(_flags & BUPC_SEM_SPRODUCER)) encoded_flags |= UPCRI_SEM_MPRODUCER;
  if (!(_flags & BUPC_SEM_SCONSUMER)) encoded_flags |= UPCRI_SEM_MCONSUMER;

  UPCRI_TRACE_PRINTF(("HEAPOP bupc_sem_alloc(%s|%s|%s)", UPCRI_TRACE_SEMFLAGS(encoded_flags) ));
  UPCRI_SEM_STATS(alloc_cnt++);
  #if UPCRI_ALLOW_SINGLE_PUT
  if (UPCRI_SEM_CAN_TINYPUT(encoded_flags)) {
    allocptr = upcr_global_alloc(upcr_threads(), sizeof(upcri_sem_t) + UPCRI_SEM_ALIGN);
    ps = upcri_shared_remote_to_mylocal(allocptr);
    ps = (upcri_sem_t *)UPCRI_ALIGNUP(ps, UPCRI_SEM_ALIGN);
    ps->tiny_data = NULL;
    ps->queued_pst = NULL;
  } else
  #endif
  {
    allocptr = upcr_alloc(sizeof(upcri_sem_t)+UPCRI_SEM_ALIGN);
    ps = upcr_shared_to_local(allocptr);
    ps = (upcri_sem_t *)UPCRI_ALIGNUP(ps, UPCRI_SEM_ALIGN);
  }
  retval = upcr_local_to_pshared((void *)(((uintptr_t)ps)+encoded_flags));
  upcri_assert(ps == UPCRI_GET_SEM_P(retval));

  ps->allocptr = allocptr;
  ps->frag_table = NULL;
  #if !GASNETT_HAVE_ATOMIC_CAS
    if (UPCRI_SEM_IS_INTEGER(encoded_flags)) (ps)->userval.int_ctr = 0;
    else
  #endif
      gasnett_atomic_set(&(ps->userval.atomic_ctr),0,0);
  gasnet_hsl_init(&(ps->hsl));
  #if UPCR_SEM_DEBUG
    ps->srcthread = (upcr_thread_t)-1;
    ps->srcthread_set = 0;
    ps->flags = encoded_flags;
    ps->magic = UPCRI_SEM_MAGIC;
  #endif
  UPCRI_CHECK_SEM(retval);
  /* Work around an ICE bug in gcc-4.8.x on x86-64: */
#if UPCRI_STRUCT_SPTR && !GASNET_DEBUG && \
        PLATFORM_ARCH_X86_64 && PLATFORM_COMPILER_GNU && PLATFORM_COMPILER_VERSION_GE(4,8,0) /* TODO: end? */
  gasnett_compiler_fence();
  __builtin_ia32_sfence();
#else
  gasnett_local_wmb();
#endif
  return retval;
}

void _bupc_sem_free(upcr_pshared_ptr_t _s UPCRI_PT_ARG) {
  upcr_thread_t thread = upcr_threadof_pshared(_s);
  #ifdef GASNET_TRACE
    char ptrstr[UPCRI_DUMP_MIN_LENGTH];
    upcri_dump_shared(upcr_pshared_to_shared(_s), ptrstr, UPCRI_DUMP_MIN_LENGTH);
    UPCRI_TRACE_PRINTF(("HEAPOP bupc_sem_free(%s)", ptrstr));
  #endif
  UPCRI_SEM_STATS(free_cnt++);
  if (thread != upcr_mythread()) {
    upcri_err("bupc_sem_free currently requires the semaphore to have local affinity"
              " affinity=%i != MYTHREAD=%i",(int)thread, (int)upcr_mythread());
  } else {
    upcri_sem_t *ps = UPCRI_GET_SEM_P(_s);
    int flags = UPCRI_GET_SEM_FLAGS(_s);
    UPCRI_CHECK_SEM(_s);
    #if UPCR_SEM_DEBUG
      memset(&(ps->magic), 0xDD, sizeof(ps->magic));
    #endif
    if (ps->frag_table) upcri_free(ps->frag_table);
    #if UPCRI_ALLOW_SINGLE_PUT
    if (UPCRI_SEM_CAN_TINYPUT(flags)) {
      int producercnt = 0;
      gasnett_atomic_t ackcnt = gasnett_atomic_init(0);
      upcri_semtarget_t *pst,*pstp;
      _upcri_sem_tinyaccept(ps, flags UPCRI_PT_PASS); /* clear any pending connection requests */
      gasnet_hsl_lock(&(ps->hsl));
        pst = ps->tiny_data;
        ps->tiny_data = NULL;
      gasnet_hsl_unlock(&(ps->hsl));
      pstp = pst;
      while (pstp) { /* inform producer node to remove from inittable */
        upcr_thread_t srcthread = pstp->srcthread;
        gasnet_node_t const node = upcri_thread_to_node(srcthread);
        upcri_sem_t *rps = UPCRI_GET_SEM_P_THSLICE(_s,srcthread);
        UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(3, 5, 
		      (node, UPCRI_HANDLER_ID(upcri_SR_sem_free),
                       srcthread, UPCRI_SEND_PTR(rps), UPCRI_SEND_PTR(&ackcnt))));

        producercnt++;
        pstp = pstp->next;
      }
      GASNET_BLOCKUNTIL(gasnett_atomic_read(&ackcnt,0) == producercnt);
      pstp = pst;
      while (pstp) { /* free target zones */
        upcri_semtarget_t *pstnext = pstp->next;
        upcr_free(pstp->allocptr); /* local shared heap */
        pstp = pstnext;
      }
      if (ps->queued_pst) upcri_err("bupc_sem_free called on a semaphore while still in use remotely");
      upcr_free(ps->allocptr); /* global shared heap */
    } else
    #endif
    {
      upcri_do_local_free(ps->allocptr);
    }
  }
}
void upcri_SR_sem_free(gasnet_token_t token, gasnet_handlerarg_t threadid, 
                       void *_ps, void *_ackcnt) {
#if UPCRI_ALLOW_SINGLE_PUT
  if (_ps) { /* request to tinysem producer */
    upcri_sem_t * const ps = _ps;
    upcri_semproducer_t * const psp = ps->tiny_data;
    int const idx = ps->inittable_idx;
    upcri_seminfo_t * const tinfo = upcri_hisseminfo(threadid);
    upcri_assert(tinfo);
    gasnet_hsl_lock(&upcri_init_hsl); /* prevent a race on table grow */
      upcri_assert(idx < tinfo->inittable_cnt);
      upcri_assert(tinfo->inittable[idx] == ps);
      tinfo->inittable[idx] = NULL; /* mark entry as free */
      psp->next = tinfo->freequeue; /* schedule datastructure for cleanup */
      tinfo->freequeue = psp;
    gasnet_hsl_unlock(&upcri_init_hsl);
    _ps = NULL;
    UPCRI_AM_CALL(UPCRI_SHORT_REPLY(3, 5, 
		  (token, UPCRI_HANDLER_ID(upcri_SR_sem_free), 0,
                   UPCRI_SEND_PTR(_ps), UPCRI_SEND_PTR(_ackcnt))));
  } else { /* reply to freer (tinysem target) */
    gasnett_atomic_t *ackcnt = _ackcnt;
    gasnett_atomic_increment(ackcnt, 0);
  }
#else
  upcri_err("impossible call to upcri_SR_sem_free()");
#endif
}
/* ------------------------------------------------------------------------------------ */
void upcri_SRQ_sem_upN(gasnet_token_t token, 
                       gasnet_handlerarg_t seminc, void *semaddr) {
  upcri_sem_t * const ps = UPCRI_GET_SEM_P_LOCAL(semaddr);
  int flags = UPCRI_GET_SEM_FLAGS_LOCAL(semaddr);
  UPCRI_CHECK_SEM_LOCAL(ps);
  upcri_assert(ps->flags == flags);
  #if UPCR_SEM_DEBUG & !defined(UPCRI_UPC_PTHREADS)
    if (UPCRI_SEM_IS_SPRODUCER(flags)) { /* extra safety check */
      gasnet_node_t srcnode;
      gasnet_AMGetMsgSource(token, &srcnode);
      UPCRI_SEM_REGISTER_SPRODUCER(ps, srcnode);
    }
  #endif
  UPCRI_SEM_USERUP(ps, flags, seminc);
}

GASNETT_INLINE(upcri_sem_upN)
void upcri_sem_upN(upcr_pshared_ptr_t s, size_t n UPCRI_PT_ARG) {
  gasnet_node_t node = upcri_pshared_nodeof(s);
  #if UPCR_SEM_DEBUG
    if (n > 1 && UPCRI_SEM_IS_BOOLEAN(UPCRI_GET_SEM_FLAGS(s)))
      upcri_err("bupc_sem_postN called on a boolean semaphore");
  #endif
  gasnett_local_wmb(); /* force global completion of prior relaxed ops */
  if (node == gasnet_mynode()) {
    upcri_sem_t *ps = UPCRI_GET_SEM_P(s);
    UPCRI_SEM_STATS(postlocal_cnt++);
    UPCRI_CHECK_SEM(s);
    UPCRI_SEM_USERUP(ps, UPCRI_GET_SEM_FLAGS(s), n);
  } else {
    UPCRI_SEM_STATS(postremote_cnt++);
    #if UPCRI_ALLOW_SINGLE_PUT
      if (UPCRI_SEM_CAN_TINYPUT(UPCRI_GET_SEM_FLAGS(s)) &&
               n < 32 &&
               upcri_sem_tinyput(s, n, node, 0, 0, 0 UPCRI_PT_PASS)) {
        return;
      }
    #endif

    UPCRI_SEM_STATS(post_short_cnt++);
    UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(2, 3, 
		  (node, UPCRI_HANDLER_ID(upcri_SRQ_sem_upN),
                   n, UPCRI_SEND_PTR(upcri_pshared_to_remote(s)))));
  }
}
void _bupc_sem_post(upcr_pshared_ptr_t s UPCRI_PT_ARG) {
  upcri_sem_init(); /* init semaphore subsystem, if necessary */
  UPCRI_TRACE_SEMOP(bupc_sem_post, s, 1);
  upcri_sem_upN(s, 1 UPCRI_PT_PASS);
}
void _bupc_sem_postN(upcr_pshared_ptr_t s, size_t n UPCRI_PT_ARG) {
  upcri_sem_init(); /* init semaphore subsystem, if necessary */
  UPCRI_TRACE_SEMOP(bupc_sem_postN, s, n);
  upcri_sem_upN(s, n UPCRI_PT_PASS);
}
/* ------------------------------------------------------------------------------------ */
GASNETT_INLINE(upcri_sem_downN)
int upcri_sem_downN(upcr_pshared_ptr_t s, size_t n, int blocking UPCRI_PT_ARG) {
  upcr_thread_t thread = upcr_threadof_pshared(s);
  int success = 0;
  #if UPCR_SEM_DEBUG
    if (n > 1 && UPCRI_SEM_IS_BOOLEAN(UPCRI_GET_SEM_FLAGS(s)))
      upcri_err("bupc_sem_waitN/tryN called on a boolean semaphore");
  #endif

  if_pf (thread != upcr_mythread()) {
    UPCRI_SEM_STATS(waitremote_cnt++);
    upcri_err("bupc_sem_try/wait currently requires the semaphore to have local affinity:"
              " affinity=%i != MYTHREAD=%i",(int)thread, (int)upcr_mythread());
  } else {
    upcri_sem_t *ps = UPCRI_GET_SEM_P(s);
    int const flags = UPCRI_GET_SEM_FLAGS(s);
    #if GASNET_STATS
      gasnett_tick_t starttime = gasnett_ticks_now();
    #endif
    UPCRI_CHECK_SEM(s);
    upcri_assert(ps->flags == flags);
    do {
      upcri_sem_ctr_t oldval;
      /* wait for necessary values to become available */
      if (blocking) {
        #if UPCRI_ALLOW_SINGLE_PUT
          UPCRI_SEM_TINYPOLL(s,ps,flags);
          while ((oldval=UPCRI_SEM_USERVAL(ps,flags)) < n) { 
            gasnet_AMPoll();
            if_pf (upcri_polite_wait) gasnett_sched_yield();
            UPCRI_SEM_TINYPOLL(s,ps,flags);
          }
        #else
          GASNET_BLOCKUNTIL((oldval=UPCRI_SEM_USERVAL(ps,flags)) >= n);
        #endif
      } else {
        UPCRI_SEM_TINYPOLL(s,ps,flags);
        if ((oldval=UPCRI_SEM_USERVAL(ps,flags)) < n) return 0;
      }
      #if GASNETT_HAVE_ATOMIC_CAS
        { upcri_sem_ctr_t newval = oldval - n;
          success = upcri_cas(&((ps)->userval.atomic_ctr), oldval, newval, GASNETT_ATOMIC_ACQ_IF_TRUE);
	  /* ACQ ensures subsequent relaxed ops can't move upward */
        }
      #else /* no CAS - protect read-to-decrement linkage using an HSL */
        gasnet_hsl_lock(&(ps->hsl));
          if ((oldval=UPCRI_SEM_USERVAL(ps,flags)) >= n) {
            if (UPCRI_SEM_IS_INTEGER(flags)) (ps)->userval.int_ctr = (oldval - n);
            else gasnett_atomic_set(&((ps)->userval.atomic_ctr), 0, 0); 
            success = 1;
            gasnett_local_rmb(); /* prevent subsequent relaxed ops from moving upwards */
          }
        gasnet_hsl_unlock(&(ps->hsl));
      #endif
    } while (!success && blocking);
    UPCRI_SEM_STATS(waittime += (gasnett_ticks_now() - starttime));
  }
  return success;
}

void _bupc_sem_waitN(upcr_pshared_ptr_t s, size_t n UPCRI_PT_ARG) {
  UPCRI_TRACE_SEMOP(bupc_sem_waitN, s, n);
  UPCRI_SEM_STATS(waitlocal_cnt++);
  upcri_sem_downN(s, n, 1 UPCRI_PT_PASS);
}
void _bupc_sem_wait(upcr_pshared_ptr_t s UPCRI_PT_ARG) {
  UPCRI_TRACE_SEMOP(bupc_sem_wait, s, 1);
  UPCRI_SEM_STATS(waitlocal_cnt++);
  upcri_sem_downN(s, 1, 1 UPCRI_PT_PASS);
}

int _bupc_sem_tryN(upcr_pshared_ptr_t s, size_t n UPCRI_PT_ARG) {
  UPCRI_TRACE_SEMOP(bupc_sem_tryN, s, n);
  UPCRI_SEM_STATS(trylocal_cnt++);
  if (upcri_sem_downN(s, n, 0 UPCRI_PT_PASS)) {
    return 1;
  } else {
    UPCRI_SEM_STATS(trylocal_failure_cnt++);
    return 0;
  }
}
int _bupc_sem_try(upcr_pshared_ptr_t s UPCRI_PT_ARG) {
  UPCRI_TRACE_SEMOP(bupc_sem_try, s, 1);
  UPCRI_SEM_STATS(trylocal_cnt++);
  if (upcri_sem_downN(s, 1, 0 UPCRI_PT_PASS)) {
    return 1;
  } else {
    UPCRI_SEM_STATS(trylocal_failure_cnt++);
    return 0;
  }
}

/* ------------------------------------------------------------------------------------ */
/* compute a hash key for the sem table
   empirically determined to outperform simple mod for non-power-of-2 table size
   by over 2x (measured on x86)
 */
GASNETT_INLINE(upcri_fold_key)
uint32_t upcri_fold_key(uint32_t key) {
  #if UPCRI_SEMTABLE_SZ == 1
    return 0;
  #else
    key ^= (key >> 16);
    #define UPCRI_SEMTABLE_KEYMASK 0x0FFFF
    #if UPCRI_SEMTABLE_SZ <= 256
      key ^= (key >> 8);
      #undef  UPCRI_SEMTABLE_KEYMASK
      #define UPCRI_SEMTABLE_KEYMASK 0x0FF
    #endif
    #if UPCRI_SEMTABLE_SZ <= 16
      key ^= (key >> 4);
      #undef  UPCRI_SEMTABLE_KEYMASK
      #define UPCRI_SEMTABLE_KEYMASK 0x0F
    #endif
    #if UPCRI_SEMTABLE_SZ <= 4
      key ^= (key >> 2);
      #undef  UPCRI_SEMTABLE_KEYMASK
      #define UPCRI_SEMTABLE_KEYMASK 0x03
    #endif
    #if UPCRI_SEMTABLE_SZ == 2
      key ^= (key >> 1);
      #undef  UPCRI_SEMTABLE_KEYMASK
      #define UPCRI_SEMTABLE_KEYMASK 0x01
    #endif
    return key & UPCRI_SEMTABLE_KEYMASK;
  #endif
}

GASNETT_INLINE(upcri_RQ_memput_signal)
void upcri_RQ_memput_signal(gasnet_handlerarg_t srcthread, gasnet_handlerarg_t seqnum, gasnet_handlerarg_t numfragments, 
                       gasnet_handlerarg_t seminc, void *semaddr) {

  upcri_sem_t *ps = UPCRI_GET_SEM_P_LOCAL(semaddr);
  int flags = UPCRI_GET_SEM_FLAGS_LOCAL(semaddr);
  UPCRI_CHECK_SEM_LOCAL(ps);
  upcri_assert(ps->flags == flags);
  if (numfragments == 1) {
    upcri_assert(seqnum == 0);
    UPCRI_SEM_USERUP(ps, flags, seminc); /* nothing else to do */
  } else {
    uint32_t hashkey = upcri_fold_key(srcthread ^ seqnum);
    upcri_semtable_t *table = ps->frag_table;
    upcri_semtable_entry_t **pentry;
    upcri_semtable_entry_t *entry;
    if (table == NULL) {
      gasnet_hsl_lock(&(ps->hsl));
        if ((table = ps->frag_table) == NULL) { /* create the table */
          int i;
          table = upcri_calloc(UPCRI_SEMTABLE_SZ, sizeof(upcri_semtable_t));
          for (i=0; i < UPCRI_SEMTABLE_SZ; i++) gasnet_hsl_init(&(table[i].hsl));
          ps->frag_table = table;
        }
      gasnet_hsl_unlock(&(ps->hsl));
    }
    table += hashkey;
    gasnet_hsl_lock(&(table->hsl));
      pentry = &(table->list);
      while ((entry = *pentry) != NULL) {
        if (entry->srcthread == srcthread && entry->seqnum == seqnum) break;
        else pentry = &(entry->next);
      } 
      if (entry == NULL) { /* first fragment */
        entry = upcri_malloc(sizeof(upcri_semtable_entry_t));
        entry->srcthread = srcthread;
        entry->seqnum = seqnum;
        entry->counterval = 0;
        entry->next = NULL;
        *pentry = entry;
      }
      entry->counterval++;
      if (entry->counterval == numfragments) { /* last fragment */
        UPCRI_SEM_USERUP(ps, flags, seminc);
        *pentry = entry->next;
        upcri_free(entry);
      }
    gasnet_hsl_unlock(&(table->hsl));
  }
}
void upcri_LRQ_memput_signal(gasnet_token_t token, void *addr, size_t nbytes, 
                             gasnet_handlerarg_t srcthread, gasnet_handlerarg_t seqnum, gasnet_handlerarg_t numfragments, 
                             gasnet_handlerarg_t seminc, void *semaddr) {
  upcri_RQ_memput_signal(srcthread, seqnum, numfragments, seminc, semaddr);
}
void upcri_MRQ_memput_signal(gasnet_token_t token, void *addr, size_t nbytes, 
                             gasnet_handlerarg_t srcthread, gasnet_handlerarg_t seqnum, gasnet_handlerarg_t numfragments, 
                             gasnet_handlerarg_t seminc, void *semaddr, void *dstaddr) {
  memcpy(dstaddr, addr, nbytes);
  gasnett_local_wmb();
  upcri_RQ_memput_signal(srcthread, seqnum, numfragments, seminc, semaddr);
}
/* ------------------------------------------------------------------------------------ */
GASNETT_INLINE(bupc_memput_signal_internal)
void bupc_memput_signal_internal(upcr_shared_ptr_t dst, const void *src, size_t nbytes, 
                                 upcr_pshared_ptr_t sem, size_t seminc, int async UPCRI_PT_ARG) {
  #if UPCR_SEM_DEBUG
    if (seminc > 1 && UPCRI_SEM_IS_BOOLEAN(UPCRI_GET_SEM_FLAGS(sem)))
      upcri_err("bupc_memput_signal called on a boolean semaphore with n > 1");
    if (upcri_pshared_nodeof(sem) != upcri_shared_nodeof(dst))
      upcri_err("bupc_memput_signal called on a semaphore lacking affinity to the destination");
    if (seminc > BUPC_SEM_MAXVALUE) 
      upcri_err("bupc_memput_signal called with n too large");
    upcri_assert(nbytes/gasnet_AMMaxLongRequest() < (upcri_sem_ctr_t)-1);
  #endif
    
  { void *lsem = upcri_pshared_to_remote(sem);
    upcri_sem_t *psem = UPCRI_GET_SEM_P_LOCAL(lsem);
    const char *psrc = src;
    char *pdst = upcri_shared_to_remote(dst);
    gasnet_node_t node = upcri_shared_nodeof(dst);

    if (node == gasnet_mynode()) {
      UPCRI_SEM_STATS(putsignallocal_cnt++);
      UPCRI_SEM_STATS(putsignallocal_databytes += nbytes);
      memcpy(pdst, psrc, nbytes);
      gasnett_local_wmb(); /* force global completion of prior relaxed ops */
      UPCRI_SEM_USERUP(psem, UPCRI_GET_SEM_FLAGS_LOCAL(lsem), seminc);
      return;
    } 

    UPCRI_SEM_STATS(putsignalremote_cnt++);
    UPCRI_SEM_STATS(putsignalremote_databytes += nbytes);

    #if UPCRI_ALLOW_SINGLE_PUT
      if (nbytes <= upcri_sem_tinypacket_maxpayload && 
               UPCRI_SEM_CAN_TINYPUT(UPCRI_GET_SEM_FLAGS(sem)) &&
               seminc < 32 && 
               upcri_sem_tinyput(sem, seminc, node, pdst, psrc, nbytes UPCRI_PT_PASS)) {
        return; /* success */
      }
    #endif

    { /* TODO: should we UPCRI_ALIGNDOWN the frag size to improve copy overheads? */
      int const uselong = (nbytes > upcri_sem_maxmed_threshold);
      size_t const fragmax = (uselong ? gasnet_AMMaxLongRequest() : gasnet_AMMaxMedium());
      upcri_sem_ctr_t numfragments = (nbytes <= fragmax ? 1 : (nbytes + fragmax - 1)/fragmax );
      upcr_thread_t threadid = upcr_mythread();
      upcri_sem_seqnum_t seqnum;
      upcri_sem_ctr_t i = 0;

      gasnett_local_wmb(); /* force global completion of prior relaxed ops */

      if (numfragments > 1) {
        seqnum = upcri_myseminfo()->next_seqnum++;
      } else seqnum = 0; /* ignored */
      /* TODO: add handler versions for numfragments==1 that don't send fragmentation metadata */

      while (1) {
        size_t const fragsz = MIN(nbytes, fragmax);
        if (!uselong) {
          UPCRI_SEM_STATS(put_medium_cnt++);
          UPCRI_AM_CALL(UPCRI_MEDIUM_REQUEST(6, 8, 
		        (node, UPCRI_HANDLER_ID(upcri_MRQ_memput_signal),
                         (void*)psrc, fragsz, 
		         threadid, seqnum, numfragments, seminc, UPCRI_SEND_PTR(lsem),
                         UPCRI_SEND_PTR(pdst))));
        } else if (async) {
          UPCRI_SEM_STATS(put_longasync_cnt++);
          UPCRI_AM_CALL(UPCRI_LONGASYNC_REQUEST(5, 6, 
		        (node, UPCRI_HANDLER_ID(upcri_LRQ_memput_signal),
                         (void*)psrc, fragsz, pdst,
		         threadid, seqnum, numfragments, seminc, UPCRI_SEND_PTR(lsem))));
        } else {
          UPCRI_SEM_STATS(put_long_cnt++);
          UPCRI_AM_CALL(UPCRI_LONG_REQUEST(5, 6, 
		        (node, UPCRI_HANDLER_ID(upcri_LRQ_memput_signal),
                         (void*)psrc, fragsz, pdst,
		         threadid, seqnum, numfragments, seminc, UPCRI_SEND_PTR(lsem))));
        }
        i++;
        if (i == numfragments) break;
        else {
          pdst += fragsz;
          psrc += fragsz;
          nbytes -= fragsz;
        }
      }
    }
  }
}

void _bupc_memput_signal(upcr_shared_ptr_t dst, const void *src, size_t nbytes, 
                        upcr_pshared_ptr_t s, size_t n UPCRI_PT_ARG) {
  upcri_sem_init(); /* init semaphore subsystem, if necessary */
  UPCRI_TRACE_PRINTF(("PUT_SIGNAL: sz = %6llu", (unsigned long long)(nbytes)));
  UPCRI_TRACE_SEMOP(bupc_memput_signal, s, n);
  bupc_memput_signal_internal(dst, src, nbytes, s, n, 0 UPCRI_PT_PASS);
}

void _bupc_memput_signal_async(upcr_shared_ptr_t dst, const void *src, size_t nbytes, 
                        upcr_pshared_ptr_t s, size_t n UPCRI_PT_ARG) {
  upcri_sem_init(); /* init semaphore subsystem, if necessary */
  UPCRI_TRACE_PRINTF(("PUT_SIGNAL_ASYNC: sz = %6llu", (unsigned long long)(nbytes)));
  UPCRI_TRACE_SEMOP(bupc_memput_signal_async, s, n);
  bupc_memput_signal_internal(dst, src, nbytes, s, n, 1 UPCRI_PT_PASS);
}

/* ------------------------------------------------------------------------------------ */
