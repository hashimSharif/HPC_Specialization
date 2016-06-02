/*   $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_atomic.h $
 * Description:
 *  Berkeley UPC atomic extensions - types and prototypes 
 *
 * Copyright 2006, Dan Bonachea <bonachea@cs.berkeley.edu>
 */


#ifndef UPCR_ATOMIC_H
#define UPCR_ATOMIC_H

/*---------------------------------------------------------------------------------*/
/* Misc. settings */

/* Bug 2391 - Need strong atomics w/ SHMEM (and w/ PSHM for same reasons) */
#if GASNET_CONDUIT_SHMEM
  /* Take the safe approach of assuming *all* shmem-conduit platforms
   * need this work-around.  If we encounter one that does not then
   * we can add PLATFORM_* exceptions as needed.
   */
  #define UPCRI_ATOMIC_FORCE_STRONG 1
#elif UPCRI_USING_PSHM
  #define UPCRI_ATOMIC_FORCE_STRONG 1
#endif

/* Cannot use mutex-based atomics in another processes's segment */
#if UPCRI_USING_PSHM
  #if GASNETT_STRONGATOMIC32_NOT_SIGNALSAFE
    #define UPCRI_ATOMIC_FORCE_LOCAL_32 1
  #endif
  #if GASNETT_STRONGATOMIC64_NOT_SIGNALSAFE
    #define UPCRI_ATOMIC_FORCE_LOCAL_64 1
  #endif
#endif

/*---------------------------------------------------------------------------------*/

/* Scalar results are written to this structure.
 * Vector results (if/when implemented) will probably be written to
 * the client's buffer (by the AM handler or the Get).
 */
struct upcri_atomic_result {
  union {
    uint64_t      _bupc_atomic_val_U64;
    uint32_t      _bupc_atomic_val_U32;
#ifndef INTTYPES_16BIT_MISSING
    uint16_t      _bupc_atomic_val_U16;
#endif
    uint8_t       _bupc_atomic_val_U8;
    int           _bupc_atomic_val_I;
    unsigned int  _bupc_atomic_val_UI;
    long          _bupc_atomic_val_L;
    unsigned long _bupc_atomic_val_UL;
    short	  _bupc_atomic_val_S;
    unsigned short _bupc_atomic_val_US;
    char          _bupc_atomic_val_C;
    unsigned char _bupc_atomic_val_UC;
    float         _bupc_atomic_val_F;
    double        _bupc_atomic_val_D;
  } value;
  int flag;
};

/*---------------------------------------------------------------------------------*/
/* Atomic ops */

/* Flags to apply to local atomics based on strictness */
#define _bupc_atomic_read_flags(isstrict) \
  (isstrict ? (GASNETT_ATOMIC_MB_PRE|GASNETT_ATOMIC_RMB_POST) : 0)
#define _bupc_atomic_set_flags(isstrict) \
  (isstrict ? (GASNETT_ATOMIC_WMB_PRE|GASNETT_ATOMIC_MB_POST) : 0)
#define _bupc_atomic_cas_flags(isstrict) \
  (isstrict ? (GASNETT_ATOMIC_MB_PRE|GASNETT_ATOMIC_MB_POST) : 0)

#if UPCRI_ATOMIC_FORCE_STRONG
  #define _upcri_atomic_cons(_id)  gasnett_strongatomic##_id
#else
  #define _upcri_atomic_cons(_id)  gasnett_atomic##_id
#endif
#define upcri_atomic32_t      _upcri_atomic_cons(32_t)
#define upcri_atomic32_read   _upcri_atomic_cons(32_read)
#define upcri_atomic32_set    _upcri_atomic_cons(32_set)
#define upcri_atomic32_cas    _upcri_atomic_cons(32_compare_and_swap)
#define upcri_atomic32_swap   _upcri_atomic_cons(32_swap)
#define upcri_atomic32_add    _upcri_atomic_cons(32_add)
#define upcri_atomic64_t      _upcri_atomic_cons(64_t)
#define upcri_atomic64_read   _upcri_atomic_cons(64_read)
#define upcri_atomic64_set    _upcri_atomic_cons(64_set)
#define upcri_atomic64_cas    _upcri_atomic_cons(64_compare_and_swap)
#define upcri_atomic64_swap   _upcri_atomic_cons(64_swap)
#define upcri_atomic64_add    _upcri_atomic_cons(64_add)

/* Affinity/access tests */
GASNETT_INLINE(upcri_atomic32_local)
upcri_local_t upcri_atomic32_local(upcr_shared_ptr_t ptr) {
  #if UPCRI_ATOMIC_FORCE_LOCAL_32
    return (upcri_s_nodeof(ptr) == gasnet_mynode()) ? upcri_s_islocal(ptr) : 0;
  #else
    return upcri_s_islocal(ptr);
  #endif
}
GASNETT_INLINE(upcri_atomic64_local)
upcri_local_t upcri_atomic64_local(upcr_shared_ptr_t ptr) {
  #if UPCRI_ATOMIC_FORCE_LOCAL_64
    return (upcri_s_nodeof(ptr) == gasnet_mynode()) ? upcri_s_islocal(ptr) : 0;
  #else
    return upcri_s_islocal(ptr);
  #endif
}

/*---------------------------------------------------------------------------------*/
/* Enum for naming types (not all implemented yet) */

enum {
	/* 64-bit integer types: */
	_BUPC_ATOMIC_TYPE_U64,
	_BUPC_ATOMIC_TYPE_I64 = _BUPC_ATOMIC_TYPE_U64,
#if SIZEOF_SHORT == 8
	_BUPC_ATOMIC_TYPE_S = _BUPC_ATOMIC_TYPE_U64,
	_BUPC_ATOMIC_TYPE_US = _BUPC_ATOMIC_TYPE_U64,
#endif
#if SIZEOF_INT == 8
	_BUPC_ATOMIC_TYPE_I = _BUPC_ATOMIC_TYPE_U64,
	_BUPC_ATOMIC_TYPE_UI = _BUPC_ATOMIC_TYPE_U64,
#endif
#if SIZEOF_LONG == 8
	_BUPC_ATOMIC_TYPE_L = _BUPC_ATOMIC_TYPE_U64,
	_BUPC_ATOMIC_TYPE_UL = _BUPC_ATOMIC_TYPE_U64,
#endif

	/* 32-bit integer types: */
	_BUPC_ATOMIC_TYPE_U32,
	_BUPC_ATOMIC_TYPE_I32 = _BUPC_ATOMIC_TYPE_U32,
#if SIZEOF_SHORT == 4
	_BUPC_ATOMIC_TYPE_S = _BUPC_ATOMIC_TYPE_U32,
	_BUPC_ATOMIC_TYPE_US = _BUPC_ATOMIC_TYPE_U32,
#endif
#if SIZEOF_INT == 4
	_BUPC_ATOMIC_TYPE_I = _BUPC_ATOMIC_TYPE_U32,
	_BUPC_ATOMIC_TYPE_UI = _BUPC_ATOMIC_TYPE_U32,
#endif
#if SIZEOF_LONG == 4
	_BUPC_ATOMIC_TYPE_L = _BUPC_ATOMIC_TYPE_U32,
	_BUPC_ATOMIC_TYPE_UL = _BUPC_ATOMIC_TYPE_U32,
#endif

#ifndef INTTYPES_16BIT_MISSING
	/* 16-bit integer types: */
	_BUPC_ATOMIC_TYPE_U16,
	_BUPC_ATOMIC_TYPE_I16 = _BUPC_ATOMIC_TYPE_U16,
#if SIZEOF_SHORT == 2
	_BUPC_ATOMIC_TYPE_S = _BUPC_ATOMIC_TYPE_U16,
	_BUPC_ATOMIC_TYPE_US = _BUPC_ATOMIC_TYPE_U16,
#endif
#endif /* INTTYPES_16BIT_MISSING */

	/* 8-bit integer types: */
	_BUPC_ATOMIC_TYPE_U8,
	_BUPC_ATOMIC_TYPE_I8 = _BUPC_ATOMIC_TYPE_U8,
#if SIZEOF_CHAR == 1
	_BUPC_ATOMIC_TYPE_C = _BUPC_ATOMIC_TYPE_U8,
	_BUPC_ATOMIC_TYPE_UC = _BUPC_ATOMIC_TYPE_U8,
#endif
#if SIZEOF_SHORT == 1
	_BUPC_ATOMIC_TYPE_S = _BUPC_ATOMIC_TYPE_U8,
	_BUPC_ATOMIC_TYPE_US = _BUPC_ATOMIC_TYPE_U8,
#endif

	/* Floating point type: */
	_BUPC_ATOMIC_TYPE_F,
	_BUPC_ATOMIC_TYPE_D
};

/*---------------------------------------------------------------------------------*/
/* Enum for naming fetch-and-OP (not all implemented yet) */

enum {  /* The mixed case eases some templates */
	_BUPC_ATOMIC_OP_fetchadd,
	_BUPC_ATOMIC_OP_fetchand,
	_BUPC_ATOMIC_OP_fetchor,
	_BUPC_ATOMIC_OP_fetchxor,
	_BUPC_ATOMIC_OP_fetchnot,
	_BUPC_ATOMIC_OP_swap,
	_BUPC_ATOMIC_OP_cswap,
	_BUPC_ATOMIC_OP_mswap
};

/*---------------------------------------------------------------------------------*/
/* Tracing macros */
#if GASNET_TRACE
  #if UPCR_DEBUG
    /* Evaluation of "data" must be free of side effects */
    #define _BUPC_ATOMIC_TRACE_FMT_DATA(var,data)                              \
	do {                                                                   \
	    const unsigned char *_data = (const unsigned char *)(data);        \
	    char *_p_out = var;                                                \
	    int _i;                                                            \
	    for (_i = 0; _i < _nbytes; _i++) {                                 \
	        snprintf(_p_out,4,"%02x ", _data[_i]); _p_out += 3;            \
	    }                                                                  \
	    if (_nbytes) *(--_p_out) = '\0'; /* drop training space */         \
	} while (0)
    #define _BUPC_ATOMIC_TRACE_FMT_BYTES(nbytes) \
	int _nbytes = (int)(nbytes)
  #else
    #define _BUPC_ATOMIC_TRACE_FMT_DATA(var,data) \
	do { var[0] = '?'; var[1] = '\0'; } while (0)
    #define _BUPC_ATOMIC_TRACE_FMT_BYTES(nbytes) \
	((void)0)
  #endif

  #define _BUPC_ATOMIC_TRACE_GETPUT(name,node,data,isstrict) do {    \
	int _islocal = ((node) == gasnet_mynode());                  \
	if (!_islocal || !upcri_trace_suppresslocal) {               \
	    char _datastr[80];                                       \
	    _BUPC_ATOMIC_TRACE_FMT_BYTES(sizeof(*(data)));           \
	    _BUPC_ATOMIC_TRACE_FMT_DATA(_datastr, data);             \
            UPCRI_TRACE_STRICT(isstrict);                            \
            UPCRI_TRACE_PRINTF_NOPOS((#name "_ATOMIC%s: data: %s",   \
				     (_islocal ? "_LOCAL" : ""),     \
				     _datastr));                     \
	}                                                            \
    } while(0)
  #define _BUPC_ATOMIC_TRACE_PUT(node,data,isstrict) \
	_BUPC_ATOMIC_TRACE_GETPUT(PUT,node,data,isstrict)
  #define _BUPC_ATOMIC_TRACE_GET(node,data,isstrict) \
	_BUPC_ATOMIC_TRACE_GETPUT(GET,node,data,isstrict)
  #define _BUPC_ATOMIC_TRACE_RMW2(name,op0,op1,result,isstrict,islocal) do {\
	int _islocal = (islocal);                                    \
	if (!_islocal || !upcri_trace_suppresslocal) {               \
	    char _op0str[80], _op1str[80], _resultstr[80];           \
	    _BUPC_ATOMIC_TRACE_FMT_BYTES(sizeof(*(result)));         \
	    _BUPC_ATOMIC_TRACE_FMT_DATA(_op0str,op0);                \
	    _BUPC_ATOMIC_TRACE_FMT_DATA(_op1str,op1);                \
	    _BUPC_ATOMIC_TRACE_FMT_DATA(_resultstr,result);          \
            UPCRI_TRACE_STRICT(isstrict);                            \
	    UPCRI_TRACE_PRINTF_NOPOS(("ATOMIC" name "%s(%s, %s) = %s",\
				     (_islocal ? "_LOCAL" : ""),     \
				     _op0str, _op1str, _resultstr)); \
	}                                                            \
  } while(0)
  #define _BUPC_ATOMIC_TRACE_RMW1(name,op0,result,isstrict,islocal) do {\
	int _islocal = (islocal);                                    \
	if (!_islocal || !upcri_trace_suppresslocal) {               \
	    char _op0str[80], _resultstr[80];                        \
	    _BUPC_ATOMIC_TRACE_FMT_BYTES(sizeof(*(result)));         \
	    _BUPC_ATOMIC_TRACE_FMT_DATA(_op0str,op0);                \
	    _BUPC_ATOMIC_TRACE_FMT_DATA(_resultstr,result);          \
            UPCRI_TRACE_STRICT(isstrict);                            \
	    UPCRI_TRACE_PRINTF_NOPOS(("ATOMIC" name "%s(%s) = %s",   \
				     (_islocal ? "_LOCAL" : ""),     \
				     _op0str, _resultstr));          \
	}                                                            \
  } while(0)
  #define _BUPC_ATOMIC_TRACE_RMW0(name,result,isstrict,islocal) do { \
	int _islocal = (islocal);                                    \
	if (!_islocal || !upcri_trace_suppresslocal) {               \
	    char _resultstr[80];                                     \
	    _BUPC_ATOMIC_TRACE_FMT_BYTES(sizeof(*(result)));         \
	    _BUPC_ATOMIC_TRACE_FMT_DATA(_resultstr,result);          \
            UPCRI_TRACE_STRICT(isstrict);                            \
	    UPCRI_TRACE_PRINTF_NOPOS(("ATOMIC" name "%s() = %s",     \
				     (_islocal ? "_LOCAL" : ""),     \
				      _resultstr));                  \
	}                                                            \
  } while(0)
#else
  #define _BUPC_ATOMIC_TRACE_GET(node,data,isstrict)      ((void)0)
  #define _BUPC_ATOMIC_TRACE_PUT(node,data,isstrict)      ((void)0)
  #define _BUPC_ATOMIC_TRACE_RMW2(name,op0,op1,result,isstrict,islocal) ((void)0)
  #define _BUPC_ATOMIC_TRACE_RMW1(name,op0,result,isstrict,islocal)     ((void)0)
  #define _BUPC_ATOMIC_TRACE_RMW0(name,reesult,isstrict,islocal)        ((void)0)
#endif

/*---------------------------------------------------------------------------------*/
/* Typeless data-movement operations */

#if 1 /* XXX: Must assume network Gets are subject to word-tearing (unless proven otherwise). */

  /* These are Get/Put for *typeless* 32- and 64-bit scalars.
   * Replacing or augmenting the AM handlers with Mediums will allow for vectors.
   */

  GASNETT_INLINE(_bupc_atomic32_read)
  uint32_t
  _bupc_atomic32_read(upcr_shared_ptr_t src, int isstrict UPCRI_PT_ARG) {
    uint32_t retval;
    upcri_local_t local = upcri_atomic32_local(src);
    (void) upcri_checkvalid_shared(src);
  
    /* See comments in upcr_shaccess.h for description of fencing a "strict_GET()" */
    UPCRI_STRICT_HOOK_IF(isstrict);
    if_pt (local) {
      upcri_atomic32_t * const p = (upcri_atomic32_t *)upcri_s2local(local,src);
      retval = upcri_atomic32_read(p, _bupc_atomic_read_flags(isstrict));
    } else {
      struct upcri_atomic_result result;
      void* srcaddr = upcri_shared_to_remote(src);
      result.flag = 0;
      gasnett_local_wmb(); /* Needed for both 'flag' and for STRICT */
      UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(3, 5,
	            (upcri_shared_nodeof(src),
		     UPCRI_HANDLER_ID(upcri_atomic_read_SRequest), 
	             4, UPCRI_SEND_PTR(srcaddr),
		     UPCRI_SEND_PTR(&result))));
      GASNET_BLOCKUNTIL(result.flag != 0); /* Includes the RMB for STRICT */
      retval = result.value._bupc_atomic_val_U32;
    }
    _BUPC_ATOMIC_TRACE_GET(upcri_shared_nodeof(src), &retval, isstrict);
    return retval;
  }
  
  GASNETT_INLINE(_bupc_atomic32_set)
  void
  _bupc_atomic32_set(upcr_shared_ptr_t dest, uint32_t val, int isstrict UPCRI_PT_ARG) {
    upcri_local_t local = upcri_atomic32_local(dest);
    (void) upcri_checkvalid_shared(dest);
  
    /* See comments in upcr_shaccess.h for description of fencing a "strict_PUT()" */
    UPCRI_STRICT_HOOK_IF(isstrict);
    if_pt (local) {
      upcri_atomic32_t * const p = (upcri_atomic32_t *)upcri_s2local(local,dest);
      upcri_atomic32_set(p, val, _bupc_atomic_set_flags(isstrict));
    } else {
      struct upcri_atomic_result result;
      void* destaddr = upcri_shared_to_remote(dest);
      result.flag = 0;
      gasnett_local_wmb(); /* Needed for both 'flag' and for STRICT */
      UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(5, 7,
	            (upcri_shared_nodeof(dest),
		     UPCRI_HANDLER_ID(upcri_atomic_set_SRequest), 
		     4, 0, val, UPCRI_SEND_PTR(destaddr),
		     UPCRI_SEND_PTR(&result))));
      GASNET_BLOCKUNTIL(result.flag != 0); /* Includes the RMB for STRICT */
    }
    _BUPC_ATOMIC_TRACE_PUT(upcri_shared_nodeof(dest), &val, isstrict);
  }

  GASNETT_INLINE(_bupc_atomic64_read)
  uint64_t
  _bupc_atomic64_read(upcr_shared_ptr_t src, int isstrict UPCRI_PT_ARG) {
    uint64_t retval;
    upcri_local_t local = upcri_atomic64_local(src);
    (void) upcri_checkvalid_shared(src);
  
    /* See comments in upcr_shaccess.h for description of fencing a "strict_GET()" */
    UPCRI_STRICT_HOOK_IF(isstrict);
    if_pt (local) {
      upcri_atomic64_t * const p = (upcri_atomic64_t *)upcri_s2local(local,src);
      retval = upcri_atomic64_read(p, _bupc_atomic_read_flags(isstrict));
    } else {
      struct upcri_atomic_result result;
      void* srcaddr = upcri_shared_to_remote(src);
      result.flag = 0;
      gasnett_local_wmb(); /* Needed for both 'flag' and for STRICT */
      UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(3, 5,
	            (upcri_shared_nodeof(src),
		     UPCRI_HANDLER_ID(upcri_atomic_read_SRequest), 
	             8, UPCRI_SEND_PTR(srcaddr),
		     UPCRI_SEND_PTR(&result))));
      GASNET_BLOCKUNTIL(result.flag != 0); /* Includes the RMB for STRICT */
      retval = result.value._bupc_atomic_val_U64;
    }
    _BUPC_ATOMIC_TRACE_GET(upcri_shared_nodeof(src), &retval, isstrict);
    return retval;
  }
  
  GASNETT_INLINE(_bupc_atomic64_set)
  void
  _bupc_atomic64_set(upcr_shared_ptr_t dest, uint64_t val, int isstrict UPCRI_PT_ARG) {
    upcri_local_t local = upcri_atomic64_local(dest);
    (void) upcri_checkvalid_shared(dest);
  
    /* See comments in upcr_shaccess.h for description of fencing a "strict_PUT()" */
    UPCRI_STRICT_HOOK_IF(isstrict);
    if_pt (local) {
      upcri_atomic64_t * const p = (upcri_atomic64_t *)upcri_s2local(local,dest);
      upcri_atomic64_set(p, val, _bupc_atomic_set_flags(isstrict));
    } else {
      struct upcri_atomic_result result;
      void* destaddr = upcri_shared_to_remote(dest);
      result.flag = 0;
      gasnett_local_wmb(); /* Needed for both 'flag' and for STRICT */
      UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(5, 7,
	            (upcri_shared_nodeof(dest),
		     UPCRI_HANDLER_ID(upcri_atomic_set_SRequest), 
		     8, UPCRI_HIWORD(val), UPCRI_LOWORD(val),
	             UPCRI_SEND_PTR(destaddr),
		     UPCRI_SEND_PTR(&result))));
      GASNET_BLOCKUNTIL(result.flag != 0); /* Includes the RMB for STRICT */
    }
    _BUPC_ATOMIC_TRACE_PUT(upcri_shared_nodeof(dest), &val, isstrict);
  }
#else
  /* This code is *NOT* currently being maintained */

  GASNETT_INLINE(_bupc_atomic32_read)
  uint32_t
  _bupc_atomic32_read(upcr_shared_ptr_t src, int isstrict UPCRI_PT_ARG) {
    return (uint32_t)_upcr_get_shared_val(src, 0, 4, isstrict UPCRI_PT_PASS);
  }

  GASNETT_INLINE(_bupc_atomic32_set)
  void
  _bupc_atomic32_set(upcr_shared_ptr_t dest, uint32_t val, int isstrict UPCRI_PT_ARG) {
    _upcr_put_shared_val(dest, 0, val, 4, isstrict UPCRI_PT_PASS);
  }

  GASNETT_INLINE(_bupc_atomic64_read)
  uint64_t
  _bupc_atomic64_read(upcr_shared_ptr_t src, int isstrict UPCRI_PT_ARG) {
    uint64_t retval;
    #if SIZEOF_UPCR_REGISTER_VALUE_T >= 8
      retval = (uint64_t)_upcr_get_shared_val(src, 0, 8, isstrict UPCRI_PT_PASS);
    #else
      _upcr_get_shared(&retval, src, 0, 8, isstrict UPCRI_PT_PASS);
    #endif
    return retval;
  }

  GASNETT_INLINE(_bupc_atomic64_set)
  void
  _bupc_atomic64_set(upcr_shared_ptr_t dest, uint64_t val, int isstrict UPCRI_PT_ARG) {
    #if SIZEOF_UPCR_REGISTER_VALUE_T >= 8
      _upcr_put_shared_val(dest, 0, val, 8, isstrict UPCRI_PT_PASS);
    #else
      _upcr_put_shared(dest, 0, &val, 8, isstrict UPCRI_PT_PASS);
    #endif
  }
#endif

/* LOCAL Read */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomic32_read_local)
  uint32_t
  _bupc_atomic32_read_local(void *addr) {
    return upcri_atomic32_read((upcri_atomic32_t *)addr, 0);
  }

  GASNETT_INLINE(_bupc_atomic64_read_local)
  uint64_t
  _bupc_atomic64_read_local(void *addr) {
    return upcri_atomic64_read((upcri_atomic64_t *)addr, 0);
  }
#endif

/* LOCAL Set */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomic32_set_local)
  void
  _bupc_atomic32_set_local(void *addr, uint32_t val) {
    upcri_atomic32_set((upcri_atomic32_t *)addr, val, 0);
  }

  GASNETT_INLINE(_bupc_atomic64_set_local)
  void
  _bupc_atomic64_set_local(void *addr, uint64_t val) {
    upcri_atomic64_set((upcri_atomic64_t *)addr, val, 0);
  }
#endif

/*---------------------------------------------------------------------------------*/
/* Template */

#define _BUPC_ATOMIC_RMW2_DEFN_U(width, operation)                                                 \
  GASNETT_INLINE(_bupc_atomicU##width##_##operation)                                               \
  uint##width##_t _bupc_atomicU##width##_##operation(                                              \
        upcr_shared_ptr_t dest,                                                                    \
        uint##width##_t op0, uint##width##_t op1,                                                  \
        int isstrict UPCRI_PT_ARG) {                                                               \
    uint##width##_t retval;                                                                        \
    upcri_local_t local = upcri_atomic##width##_local(dest);                                       \
    (void) upcri_checkvalid_shared(dest);                                                          \
    /* Strict fencing is the union of strict get/put operations */                                 \
    UPCRI_STRICT_HOOK_IF(isstrict);                                                                \
    if_pt (local) {                                                                                \
      retval = _bupc_atomicU##width##_##operation##_local(upcri_s2local(local,dest),               \
                                                          op0, op1,                                \
                                                          _bupc_atomic_cas_flags(isstrict));       \
    } else {                                                                                       \
      struct upcri_atomic_result result;                                                           \
      void* destaddr = upcri_shared_to_remote(dest);                                               \
      result.flag = 0;                                                                             \
      gasnett_local_wmb(); /* For both 'flag' and for STRICT */                                    \
      UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(8, 10,                                                     \
                    (upcri_shared_nodeof(dest),                                                    \
                     UPCRI_HANDLER_ID(upcri_atomic_rmw2_SRequest),                                 \
                     _BUPC_ATOMIC_TYPE_U##width, _BUPC_ATOMIC_OP_##operation,                      \
                     UPCRI_HIWORD(op0), UPCRI_LOWORD(op0),                                         \
                     UPCRI_HIWORD(op1), UPCRI_LOWORD(op1),                                         \
                     UPCRI_SEND_PTR(destaddr),                                                     \
                     UPCRI_SEND_PTR(&result))));                                                   \
      GASNET_BLOCKUNTIL(result.flag != 0); /* Includes the RMB for STRICT */                       \
      retval = result.value._bupc_atomic_val_U##width;                                             \
    }                                                                                              \
    _BUPC_ATOMIC_TRACE_RMW2(#width "_" #operation, &op0, &op1, &retval, isstrict, local);          \
    return retval;                                                                                 \
  }

#define _BUPC_ATOMIC_RMW2_DEFN_I(width, operation)                                                 \
  /* Assumes 2s complement arithmetic for ADD: */                                                  \
  GASNETT_INLINE(_bupc_atomicI##width##_##operation)                                               \
  int##width##_t _bupc_atomicI##width##_##operation(                                               \
        upcr_shared_ptr_t dest,                                                                    \
        int##width##_t op0, int##width##_t op1,                                                    \
        int isstrict UPCRI_PT_ARG) {                                                               \
    return (int##width##_t)_bupc_atomicU##width##_##operation(dest,                                \
                                                              (uint##width##_t)op0,                \
                                                              (uint##width##_t)op1,                \
                                                              isstrict                             \
                                                              UPCRI_PT_PASS);                      \
  }                                                                                                \
  GASNETT_INLINE(_bupc_atomicI##width##_##operation##_local)                                       \
  int##width##_t _bupc_atomicI##width##_##operation##_local(                                       \
        void *dest, int##width##_t op0, int##width##_t op1, int flags) {                           \
    return (int##width##_t)_bupc_atomicU##width##_##operation##_local(dest,                        \
                                                                      (uint##width##_t)op0,        \
                                                                      (uint##width##_t)op1,        \
                                                                      flags);                      \
  }

#define _BUPC_ATOMIC_RMW2_DEFN(width, operation)   \
        _BUPC_ATOMIC_RMW2_DEFN_U(width, operation) \
        _BUPC_ATOMIC_RMW2_DEFN_I(width, operation)

#define _BUPC_ATOMIC_RMW1_DEFN_U(width, operation)                                                 \
  GASNETT_INLINE(_bupc_atomicU##width##_##operation)                                               \
  uint##width##_t _bupc_atomicU##width##_##operation(                                              \
        upcr_shared_ptr_t dest,                                                                    \
        uint##width##_t operand,                                                                   \
        int isstrict UPCRI_PT_ARG) {                                                               \
    uint##width##_t retval;                                                                        \
    upcri_local_t local = upcri_atomic##width##_local(dest);                                       \
    (void) upcri_checkvalid_shared(dest);                                                          \
    /* Strict fencing is the union of strict get/put operations */                                 \
    UPCRI_STRICT_HOOK_IF(isstrict);                                                                \
    if_pt (local) {                                                                                \
      retval = _bupc_atomicU##width##_##operation##_local(upcri_s2local(local,dest),               \
                                                          operand,                                 \
                                                          _bupc_atomic_cas_flags(isstrict));       \
    } else {                                                                                       \
      struct upcri_atomic_result result;                                                           \
      void* destaddr = upcri_shared_to_remote(dest);                                               \
      result.flag = 0;                                                                             \
      gasnett_local_wmb(); /* For both 'flag' and for STRICT */                                    \
      UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(6, 8,                                                      \
                    (upcri_shared_nodeof(dest),                                                    \
                     UPCRI_HANDLER_ID(upcri_atomic_rmw1_SRequest),                                 \
                     _BUPC_ATOMIC_TYPE_U##width, _BUPC_ATOMIC_OP_##operation,                      \
                     UPCRI_HIWORD(operand), UPCRI_LOWORD(operand),                                 \
                     UPCRI_SEND_PTR(destaddr),                                                     \
                     UPCRI_SEND_PTR(&result))));                                                   \
      GASNET_BLOCKUNTIL(result.flag != 0); /* Includes the RMB for STRICT */                       \
      retval = result.value._bupc_atomic_val_U##width;                                             \
    }                                                                                              \
    _BUPC_ATOMIC_TRACE_RMW1(#width "_" #operation, &operand, &retval, isstrict, local);            \
    return retval;                                                                                 \
  }

#define _BUPC_ATOMIC_RMW1_DEFN_I(width, operation)                                                 \
  /* Assumes 2s complement arithmetic for ADD: */                                                  \
  GASNETT_INLINE(_bupc_atomicI##width##_##operation)                                               \
  int##width##_t _bupc_atomicI##width##_##operation(                                               \
        upcr_shared_ptr_t dest,                                                                    \
        int##width##_t operand,                                                                    \
        int isstrict UPCRI_PT_ARG) {                                                               \
    return (int##width##_t)_bupc_atomicU##width##_##operation(dest,                                \
                                                              (uint##width##_t)operand,            \
                                                              isstrict                             \
                                                              UPCRI_PT_PASS);                      \
  }                                                                                                \
  GASNETT_INLINE(_bupc_atomicI##width##_##operation##_local)                                       \
  int##width##_t _bupc_atomicI##width##_##operation##_local(                                       \
        void *dest, int##width##_t operand, int flags) {                                           \
    return (int##width##_t)_bupc_atomicU##width##_##operation##_local(dest,                        \
                                                                      (uint##width##_t)operand,    \
                                                                      flags);                      \
  }

#define _BUPC_ATOMIC_RMW1_DEFN(width, operation)   \
        _BUPC_ATOMIC_RMW1_DEFN_U(width, operation) \
        _BUPC_ATOMIC_RMW1_DEFN_I(width, operation)

#define _BUPC_ATOMIC_RMW0_DEFN_U(width, operation)                                                 \
  GASNETT_INLINE(_bupc_atomicU##width##_##operation)                                               \
  uint##width##_t _bupc_atomicU##width##_##operation(                                              \
        upcr_shared_ptr_t dest,                                                                    \
        int isstrict UPCRI_PT_ARG) {                                                               \
    uint##width##_t retval;                                                                        \
    upcri_local_t local = upcri_atomic##width##_local(dest);                                       \
    (void) upcri_checkvalid_shared(dest);                                                          \
    /* Strict fencing is the union of strict get/put operations */                                 \
    UPCRI_STRICT_HOOK_IF(isstrict);                                                                \
    if_pt (local) {                                                                                \
      retval = _bupc_atomicU##width##_##operation##_local(upcri_s2local(local,dest),               \
                                                     _bupc_atomic_cas_flags(isstrict));            \
    } else {                                                                                       \
      struct upcri_atomic_result result;                                                           \
      void* destaddr = upcri_shared_to_remote(dest);                                               \
      result.flag = 0;                                                                             \
      gasnett_local_wmb(); /* For both 'flag' and for STRICT */                                    \
      UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(4, 6,                                                      \
                    (upcri_shared_nodeof(dest),                                                    \
                     UPCRI_HANDLER_ID(upcri_atomic_rmw0_SRequest),                                 \
                     _BUPC_ATOMIC_TYPE_U##width, _BUPC_ATOMIC_OP_##operation,                      \
                     UPCRI_SEND_PTR(destaddr),                                                     \
                     UPCRI_SEND_PTR(&result))));                                                   \
      GASNET_BLOCKUNTIL(result.flag != 0); /* Includes the RMB for STRICT */                       \
      retval = result.value._bupc_atomic_val_U##width;                                             \
    }                                                                                              \
    _BUPC_ATOMIC_TRACE_RMW0(#width "_" #operation, &retval, isstrict, local);                      \
    return retval;                                                                                 \
  }                                                                                                \

#define _BUPC_ATOMIC_RMW0_DEFN_I(width, operation)                                                 \
  /* Assumes 2s complement arithmetic for ADD: */                                                  \
  GASNETT_INLINE(_bupc_atomicI##width##_##operation)                                               \
  int##width##_t _bupc_atomicI##width##_##operation(                                               \
        upcr_shared_ptr_t dest,                                                                    \
        int isstrict UPCRI_PT_ARG) {                                                               \
    return (int##width##_t)_bupc_atomicU##width##_##operation(dest, isstrict UPCRI_PT_PASS);       \
  }                                                                                                \
  GASNETT_INLINE(_bupc_atomicI##width##_##operation##_local)                                       \
  int##width##_t _bupc_atomicI##width##_##operation##_local(                                       \
        void *dest, int flags) {                                                                   \
    return (int##width##_t)_bupc_atomicU##width##_##operation##_local(dest, flags);                \
  }

#define _BUPC_ATOMIC_RMW0_DEFN(width, operation)   \
        _BUPC_ATOMIC_RMW0_DEFN_U(width, operation) \
        _BUPC_ATOMIC_RMW0_DEFN_I(width, operation)

/*---------------------------------------------------------------------------------*/
/* Local operations on [u]int32_t: */

/* LOCAL Fetch-and-ADD */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU32_fetchadd_local)
  uint32_t
  _bupc_atomicU32_fetchadd_local(void *addr, uint32_t operand, int flags) {
    upcri_atomic32_t * const p = (upcri_atomic32_t *)addr;
    return upcri_atomic32_add(p, operand, flags) - operand;
  }
#endif

/* LOCAL Fetch-and-AND */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU32_fetchand_local)
  uint32_t
  _bupc_atomicU32_fetchand_local(void *addr, uint32_t operand, int flags) {
    upcri_atomic32_t * const p = (upcri_atomic32_t *)addr;
    uint32_t oldval, newval;
    do {
      newval = (oldval = upcri_atomic32_read(p, 0)) & operand;
    } while(!upcri_atomic32_cas(p, oldval, newval, flags));
    return oldval;
  }
#endif

/* LOCAL Fetch-and-OR */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU32_fetchor_local)
  uint32_t
  _bupc_atomicU32_fetchor_local(void *addr, uint32_t operand, int flags) {
    upcri_atomic32_t * const p = (upcri_atomic32_t *)addr;
    uint32_t oldval, newval;
    do {
      newval = (oldval = upcri_atomic32_read(p, 0)) | operand;
    } while(!upcri_atomic32_cas(p, oldval, newval, flags));
    return oldval;
  }
#endif

/* LOCAL Fetch-and-XOR */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU32_fetchxor_local)
  uint32_t
  _bupc_atomicU32_fetchxor_local(void *addr, uint32_t operand, int flags) {
    upcri_atomic32_t * const p = (upcri_atomic32_t *)addr;
    uint32_t oldval, newval;
    do {
      newval = (oldval = upcri_atomic32_read(p, 0)) ^ operand;
    } while(!upcri_atomic32_cas(p, oldval, newval, flags));
    return oldval;
  }
#endif

/* LOCAL Fetch-and-SWAP */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU32_swap_local)
  uint32_t
  _bupc_atomicU32_swap_local(void *addr, uint32_t operand, int flags) {
    upcri_atomic32_t * const p = (upcri_atomic32_t *)addr;
    return upcri_atomic32_swap(p, operand, flags);
  }
#endif

/* LOCAL Fetch-and-NOT */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU32_fetchnot_local)
  uint32_t
  _bupc_atomicU32_fetchnot_local(void *addr, int flags) {
    upcri_atomic32_t * const p = (upcri_atomic32_t *)addr;
    uint32_t oldval, newval;
    do {
      newval = ~(oldval = upcri_atomic32_read(p, 0));
    } while(!upcri_atomic32_cas(p, oldval, newval, flags));
    return oldval;
  }
#endif

/* LOCAL Compare-and-swap */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU32_cswap_local)
  uint32_t
  _bupc_atomicU32_cswap_local(void *addr, uint32_t op_old, uint32_t op_new, int flags) {
    upcri_atomic32_t * const p = (upcri_atomic32_t *)addr;
    uint32_t oldval;
    do {
      if ((oldval = upcri_atomic32_read(p, 0)) != op_old) break;
    } while(!upcri_atomic32_cas(p, op_old, op_new, flags));
    return oldval;
  }
#endif

/* LOCAL Masked-swap */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU32_mswap_local)
  uint32_t
  _bupc_atomicU32_mswap_local(void *addr, uint32_t op_mask, uint32_t op_val, int flags) {
    upcri_atomic32_t * const p = (upcri_atomic32_t *)addr;
    uint32_t oldval, newval;
    op_val &= op_mask;
    op_mask = ~op_mask;
    do {
      oldval = upcri_atomic32_read(p, 0);
      newval = op_val | (oldval & op_mask);
    } while(!upcri_atomic32_cas(p, oldval, newval, flags));
    return oldval;
  }
#endif

/*---------------------------------------------------------------------------------*/
/* Local operations on [u]int64_t: */

/* LOCAL Fetch-and-ADD */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU64_fetchadd_local)
  uint64_t
  _bupc_atomicU64_fetchadd_local(void *addr, uint64_t operand, int flags) {
    upcri_atomic64_t * const p = (upcri_atomic64_t *)addr;
    return upcri_atomic64_add(p, operand, flags) - operand;
  }
#endif

/* LOCAL Fetch-and-AND */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU64_fetchand_local)
  uint64_t
  _bupc_atomicU64_fetchand_local(void *addr, uint64_t operand, int flags) {
    upcri_atomic64_t * const p = (upcri_atomic64_t *)addr;
    uint64_t oldval, newval;
    do {
      newval = (oldval = upcri_atomic64_read(p, 0)) & operand;
    } while(!upcri_atomic64_cas(p, oldval, newval, flags));
    return oldval;
  }
#endif

/* LOCAL Fetch-and-OR */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU64_fetchor_local)
  uint64_t
  _bupc_atomicU64_fetchor_local(void *addr, uint64_t operand, int flags) {
    upcri_atomic64_t * const p = (upcri_atomic64_t *)addr;
    uint64_t oldval, newval;
    do {
      newval = (oldval = upcri_atomic64_read(p, 0)) | operand;
    } while(!upcri_atomic64_cas(p, oldval, newval, flags));
    return oldval;
  }
#endif

/* LOCAL Fetch-and-XOR */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU64_fetchxor_local)
  uint64_t
  _bupc_atomicU64_fetchxor_local(void *addr, uint64_t operand, int flags) {
    upcri_atomic64_t * const p = (upcri_atomic64_t *)addr;
    uint64_t oldval, newval;
    do {
      newval = (oldval = upcri_atomic64_read(p, 0)) ^ operand;
    } while(!upcri_atomic64_cas(p, oldval, newval, flags));
    return oldval;
  }
#endif

/* LOCAL Fetch-and-SWAP */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU64_swap_local)
  uint64_t
  _bupc_atomicU64_swap_local(void *addr, uint64_t operand, int flags) {
    upcri_atomic64_t * const p = (upcri_atomic64_t *)addr;
    return upcri_atomic64_swap(p, operand, flags);
  }
#endif

/* LOCAL Fetch-and-NOT */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU64_fetchnot_local)
  uint64_t
  _bupc_atomicU64_fetchnot_local(void *addr, int flags) {
    upcri_atomic64_t * const p = (upcri_atomic64_t *)addr;
    uint64_t oldval, newval;
    do {
      newval = ~(oldval = upcri_atomic64_read(p, 0));
    } while(!upcri_atomic64_cas(p, oldval, newval, flags));
    return oldval;
  }
#endif

/* LOCAL Compare-and-swap */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU64_cswap_local)
  uint64_t
  _bupc_atomicU64_cswap_local(void *addr, uint64_t op_old, uint64_t op_new, int flags) {
    upcri_atomic64_t * const p = (upcri_atomic64_t *)addr;
    uint64_t oldval;
    do {
      if ((oldval = upcri_atomic64_read(p, 0)) != op_old) break;
    } while(!upcri_atomic64_cas(p, op_old, op_new, flags));
    return oldval;
  }
#endif

/* LOCAL Masked-swap */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  GASNETT_INLINE(_bupc_atomicU64_mswap_local)
  uint64_t
  _bupc_atomicU64_mswap_local(void *addr, uint64_t op_mask, uint64_t op_val, int flags) {
    upcri_atomic64_t * const p = (upcri_atomic64_t *)addr;
    uint64_t oldval, newval;
    op_val &= op_mask;
    op_mask = ~op_mask;
    do {
      oldval = upcri_atomic64_read(p, 0);
      newval = op_val | (oldval & op_mask);
    } while(!upcri_atomic64_cas(p, oldval, newval, flags));
    return oldval;
  }
#endif

/*---------------------------------------------------------------------------------*/
/* Operations on [u]int32_t: */

/* Fetch-and-ADD */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW1_DEFN(32, fetchadd)
#endif

/* Fetch-and-AND */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW1_DEFN(32, fetchand)
#endif

/* Fetch-and-OR */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW1_DEFN(32, fetchor)
#endif

/* Fetch-and-XOR */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW1_DEFN(32, fetchxor)
#endif

/* Fetch-and-SWAP */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW1_DEFN(32, swap)
#endif

/* Fetch-and-NOT */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW0_DEFN(32, fetchnot)
#endif

/* Compare-and-swap */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW2_DEFN(32, cswap)
#endif

/* Masked-swap */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW2_DEFN(32, mswap)
#endif

/*---------------------------------------------------------------------------------*/
/* Operations on [u]int64_t: */

/* Fetch-and-ADD */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW1_DEFN(64, fetchadd)
#endif

/* Fetch-and-AND */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW1_DEFN(64, fetchand)
#endif

/* Fetch-and-OR */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW1_DEFN(64, fetchor)
#endif

/* Fetch-and-XOR */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW1_DEFN(64, fetchxor)
#endif

/* Fetch-and-SWAP */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW1_DEFN(64, swap)
#endif

/* Fetch-and-NOT */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW0_DEFN(64, fetchnot)
#endif

/* Compare-and-swap */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW2_DEFN(64, cswap)
#endif

/* Masked-swap */
#if 0
  /* Space to add platform-specific overrides */
#else /* Default */
  _BUPC_ATOMIC_RMW2_DEFN(64, mswap)
#endif

/*---------------------------------------------------------------------------------*/
/* Private ops (which differ when using PSHM w/ non signal-safe atomics): */

#define _BUPC_ATOMIC_PRIV_SET_DEFN(width) \
    GASNETT_INLINE(_bupc_atomic##width##_set_priv)                                                   \
    void _bupc_atomic##width##_set_priv(void *addr, uint##width##_t val UPCRI_PT_ARG) {              \
      upcr_shared_ptr_t sptr;                                                                        \
      if_pf (_BUPC_ATOMIC_PRIV_IS_REMOTE##width(sptr, addr)) {                                       \
        _bupc_atomic##width##_set(sptr, val, 0 UPCRI_PT_PASS);                                       \
      } else {                                                                                       \
        _bupc_atomic##width##_set_local(addr, val);                                                  \
        _BUPC_ATOMIC_TRACE_PUT(gasnet_mynode(), &val, 0);                                            \
      }                                                                                              \
    }
#define _BUPC_ATOMIC_PRIV_READ_DEFN(width) \
    GASNETT_INLINE(_bupc_atomic##width##_read_priv)                                                  \
    uint##width##_t _bupc_atomic##width##_read_priv(void *addr UPCRI_PT_ARG) {                       \
      upcr_shared_ptr_t sptr;                                                                        \
      if_pf (_BUPC_ATOMIC_PRIV_IS_REMOTE##width(sptr, addr)) {                                       \
        return _bupc_atomic##width##_read(sptr, 0 UPCRI_PT_PASS);                                    \
      } else {                                                                                       \
        uint##width##_t retval = _bupc_atomic##width##_read_local(addr);                             \
        _BUPC_ATOMIC_TRACE_GET(gasnet_mynode(), &retval, 0);                                         \
        return retval;                                                                               \
      }                                                                                              \
    }
#define _BUPC_ATOMIC_PRIV_RMW0_DEFN(width, operation) \
    GASNETT_INLINE(_bupc_atomicU##width##_##operation##_priv)                                        \
    uint##width##_t _bupc_atomicU##width##_##operation##_priv(                                       \
          void *dest UPCRI_PT_ARG) {                                                                 \
      upcr_shared_ptr_t sptr;                                                                        \
      if_pf (_BUPC_ATOMIC_PRIV_IS_REMOTE##width(sptr, dest)) {                                       \
        return _bupc_atomicU##width##_##operation(sptr, 0 UPCRI_PT_PASS);                            \
      } else {                                                                                       \
        uint##width##_t retval = _bupc_atomicU##width##_##operation##_local(dest, 0);                \
        _BUPC_ATOMIC_TRACE_RMW0(#width "_" #operation, &retval, 0, 1);                               \
        return retval;                                                                               \
      }                                                                                              \
    }                                                                                                \
    GASNETT_INLINE(_bupc_atomicI##width##_##operation##_priv)                                        \
    int##width##_t _bupc_atomicI##width##_##operation##_priv(                                        \
          void *dest UPCRI_PT_ARG) {                                                                 \
      upcr_shared_ptr_t sptr;                                                                        \
      if_pf (_BUPC_ATOMIC_PRIV_IS_REMOTE##width(sptr, dest)) {                                       \
        return _bupc_atomicI##width##_##operation(sptr, 0 UPCRI_PT_PASS);                            \
      } else {                                                                                       \
        int##width##_t retval = _bupc_atomicI##width##_##operation##_local(dest, 0);                 \
        _BUPC_ATOMIC_TRACE_RMW0(#width "_" #operation, &retval, 0, 1);                               \
        return retval;                                                                               \
      }                                                                                              \
    }
#define _BUPC_ATOMIC_PRIV_RMW1_DEFN(width, operation) \
    GASNETT_INLINE(_bupc_atomicU##width##_##operation##_priv)                                        \
    uint##width##_t _bupc_atomicU##width##_##operation##_priv(                                       \
          void *dest, uint##width##_t op0 UPCRI_PT_ARG) {                                            \
      upcr_shared_ptr_t sptr;                                                                        \
      if_pf (_BUPC_ATOMIC_PRIV_IS_REMOTE##width(sptr, dest)) {                                       \
        return _bupc_atomicU##width##_##operation(sptr, op0, 0 UPCRI_PT_PASS);                       \
      } else {                                                                                       \
        uint##width##_t retval = _bupc_atomicU##width##_##operation##_local(dest, op0, 0);           \
        _BUPC_ATOMIC_TRACE_RMW1(#width "_" #operation, &op0, &retval, 0, 1);                         \
        return retval;                                                                               \
      }                                                                                              \
    }                                                                                                \
    GASNETT_INLINE(_bupc_atomicI##width##_##operation##_priv)                                        \
    int##width##_t _bupc_atomicI##width##_##operation##_priv(                                        \
          void *dest, int##width##_t op0 UPCRI_PT_ARG) {                                             \
      upcr_shared_ptr_t sptr;                                                                        \
      if_pf (_BUPC_ATOMIC_PRIV_IS_REMOTE##width(sptr, dest)) {                                       \
        return _bupc_atomicI##width##_##operation(sptr, op0, 0 UPCRI_PT_PASS);                       \
      } else {                                                                                       \
        int##width##_t retval = _bupc_atomicI##width##_##operation##_local(dest, op0, 0);            \
        _BUPC_ATOMIC_TRACE_RMW1(#width "_" #operation, &op0, &retval, 0, 1);                         \
        return retval;                                                                               \
      }                                                                                              \
    }
#define _BUPC_ATOMIC_PRIV_RMW2_DEFN(width, operation) \
    GASNETT_INLINE(_bupc_atomicU##width##_##operation##_priv)                                        \
    uint##width##_t _bupc_atomicU##width##_##operation##_priv(                                       \
          void *dest, uint##width##_t op0, uint##width##_t op1 UPCRI_PT_ARG) {                       \
      upcr_shared_ptr_t sptr;                                                                        \
      if_pf (_BUPC_ATOMIC_PRIV_IS_REMOTE##width(sptr, dest)) {                                       \
        return _bupc_atomicU##width##_##operation(sptr, op0, op1, 0 UPCRI_PT_PASS);                  \
      } else {                                                                                       \
        uint##width##_t retval = _bupc_atomicU##width##_##operation##_local(dest, op0, op1, 0);      \
        _BUPC_ATOMIC_TRACE_RMW2(#width "_" #operation, &op0, &op1, &retval, 0, 1);                   \
        return retval;                                                                               \
      }                                                                                              \
    }                                                                                                \
    GASNETT_INLINE(_bupc_atomicI##width##_##operation##_priv)                                        \
    int##width##_t _bupc_atomicI##width##_##operation##_priv(                                        \
          void *dest, int##width##_t op0, int##width##_t op1 UPCRI_PT_ARG) {                         \
      upcr_shared_ptr_t sptr;                                                                        \
      if_pf (_BUPC_ATOMIC_PRIV_IS_REMOTE##width(sptr, dest)) {                                       \
        return _bupc_atomicI##width##_##operation(sptr, op0, op1, 0 UPCRI_PT_PASS);                  \
      } else {                                                                                       \
        int##width##_t retval = _bupc_atomicI##width##_##operation##_local(dest, op0, op1, 0);       \
        _BUPC_ATOMIC_TRACE_RMW2(#width "_" #operation, &op0, &op1, &retval, 0, 1);                   \
        return retval;                                                                               \
      }                                                                                              \
    }


#if UPCRI_ATOMIC_FORCE_LOCAL_32
  #define _BUPC_ATOMIC_PRIV_IS_REMOTE32(_sptr, _addr) \
      (!upcr_isnull_shared((_sptr = _bupc_inverse_cast(_addr))))
#else
  #define _BUPC_ATOMIC_PRIV_IS_REMOTE32(_sptr, _addr) \
      (_sptr = upcr_null_shared, 0)
#endif

_BUPC_ATOMIC_PRIV_SET_DEFN(32)
_BUPC_ATOMIC_PRIV_READ_DEFN(32)
_BUPC_ATOMIC_PRIV_RMW1_DEFN(32, fetchadd)
_BUPC_ATOMIC_PRIV_RMW1_DEFN(32, fetchand)
_BUPC_ATOMIC_PRIV_RMW1_DEFN(32, fetchor)
_BUPC_ATOMIC_PRIV_RMW1_DEFN(32, fetchxor)
_BUPC_ATOMIC_PRIV_RMW1_DEFN(32, swap)
_BUPC_ATOMIC_PRIV_RMW0_DEFN(32, fetchnot)
_BUPC_ATOMIC_PRIV_RMW2_DEFN(32, cswap)
_BUPC_ATOMIC_PRIV_RMW2_DEFN(32, mswap)
  
#if UPCRI_ATOMIC_FORCE_LOCAL_64
  #define _BUPC_ATOMIC_PRIV_IS_REMOTE64(_sptr, _addr) \
      (!upcr_isnull_shared((_sptr = _bupc_inverse_cast(_addr))))
#else
  #define _BUPC_ATOMIC_PRIV_IS_REMOTE64(_sptr, _addr) \
      (_sptr = upcr_null_shared, 0)
#endif

_BUPC_ATOMIC_PRIV_SET_DEFN(64)
_BUPC_ATOMIC_PRIV_READ_DEFN(64)
_BUPC_ATOMIC_PRIV_RMW1_DEFN(64, fetchadd)
_BUPC_ATOMIC_PRIV_RMW1_DEFN(64, fetchand)
_BUPC_ATOMIC_PRIV_RMW1_DEFN(64, fetchor)
_BUPC_ATOMIC_PRIV_RMW1_DEFN(64, fetchxor)
_BUPC_ATOMIC_PRIV_RMW1_DEFN(64, swap)
_BUPC_ATOMIC_PRIV_RMW0_DEFN(64, fetchnot)
_BUPC_ATOMIC_PRIV_RMW2_DEFN(64, cswap)
_BUPC_ATOMIC_PRIV_RMW2_DEFN(64, mswap)
  
/*---------------------------------------------------------------------------------*/
/* External interface: */
#if !UPCRI_BUILDING_LIBUPCR
#include <upcr_atomic_defs.h>
#endif

/*---------------------------------------------------------------------------------*/

#endif /* UPCR_ATOMIC_H */
