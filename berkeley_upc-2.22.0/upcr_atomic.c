/*   $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_atomic.c $
 * Description: 
 *  Berkeley UPC atomic extensions
 *
 * Copyright 2006, Dan Bonachea <bonachea@cs.berkeley.edu>
 */

#include <upcr.h>
#include <upcr_internal.h>

/*---------------------------------------------------------------------------------*/

/* For now the following three handlers are just for typeless 32- and 64-bit scalars.
 * Vector results could be handled by either replacing or augmenting these
 * handlers with Mediums.
 */

void
upcri_atomic_SReply(gasnet_token_t token, int bytes, uint32_t hi32, uint32_t lo32, void *result) {
  switch (bytes) {
    case 4:
      ((struct upcri_atomic_result *)result)->value._bupc_atomic_val_U32 = lo32;
      break;
    case 8:
      ((struct upcri_atomic_result *)result)->value._bupc_atomic_val_U64 = UPCRI_MAKEWORD(hi32, lo32);
      break;
    default:
      upcri_err("Invalid width in upcri_atomic_SReply");
  }
  gasnett_weak_wmb();
  ((struct upcri_atomic_result *)result)->flag = 1;
}

void
upcri_atomic_set_SRequest(gasnet_token_t token, int bytes, uint32_t hi32, uint32_t lo32,
			  void *addr, void *result) {
  switch (bytes) {
    case 4:
      upcri_atomic32_set((upcri_atomic32_t *)addr, lo32, 0);
      break;
    case 8:
    {
      const uint64_t value = UPCRI_MAKEWORD(hi32, lo32);
      upcri_atomic64_set((upcri_atomic64_t *)addr, value, 0);
      break;
    }
    default:
      upcri_err("Invalid width in upcri_atomic_set_SRequest");
  }
  UPCRI_AM_CALL(UPCRI_SHORT_REPLY(4, 5, 
		(token, UPCRI_HANDLER_ID(upcri_atomic_SReply),
		 bytes, hi32, lo32, UPCRI_SEND_PTR(result))));
}

void
upcri_atomic_read_SRequest(gasnet_token_t token, int bytes, void *addr, void *result) {
  uint32_t hi32;
  uint32_t lo32;
  switch (bytes) {
    case 4:
#if UPCR_DEBUG
      hi32 = 0xdeadbeef;	/* avoid uninitialized variable warning */
#endif
      lo32 = upcri_atomic32_read((upcri_atomic32_t *)addr, 0);
      break;
    case 8:
    {
      const uint64_t value = upcri_atomic64_read((upcri_atomic64_t *)addr, 0);
      hi32 = UPCRI_HIWORD(value);
      lo32 = UPCRI_LOWORD(value);
      break;
    }
    default:
      hi32 = lo32 = 0; /* warning suppression */
      upcri_err("Invalid width in upcri_atomic_set_SRequest");
  }
  UPCRI_AM_CALL(UPCRI_SHORT_REPLY(4, 5, 
		(token, UPCRI_HANDLER_ID(upcri_atomic_SReply),
		 bytes, hi32, lo32, UPCRI_SEND_PTR(result))));
}

/* As the interface grows, the handlers below may grow
 * a "count" argument to add generality without
 * the need to add additional handlers.
 */

/* handler for 2-operand Read-Modify-Write operations */
void
upcri_atomic_rmw2_SRequest(gasnet_token_t token,
                           int type, int operation,
                           uint32_t hi32_0, uint32_t lo32_0,
                           uint32_t hi32_1, uint32_t lo32_1,
                           void *addr, void *result) {
  #define bupc_common_rmw2(_op0,_op1,_operation,_width)                  \
    const uint##_width##_t op0 = (_op0);                                 \
    const uint##_width##_t op1 = (_op1);                                 \
    uint##_width##_t oldval;                                             \
    switch(_operation) {                                                 \
      case _BUPC_ATOMIC_OP_cswap:                                        \
        oldval = _bupc_atomicU##_width##_cswap##_local(addr, op0, op1, 0);\
        break;                                                           \
      case _BUPC_ATOMIC_OP_mswap:                                        \
        oldval = _bupc_atomicU##_width##_mswap##_local(addr, op0, op1, 0);\
        break;                                                           \
      default:                                                           \
        oldval = 0; /* warning suppression */                            \
        upcri_err("Invalid operation in upcri_atomic_rmw2_SRequest");    \
    }                                                                    \
    bytes = _width/8;

  uint32_t hi32, lo32;
  int bytes;
#if UPCR_DEBUG
  bytes = 0;	/* avoid uninitialized variable warning */
#endif
  switch (type) {
    case _BUPC_ATOMIC_TYPE_U64:
    {
      bupc_common_rmw2(UPCRI_MAKEWORD(hi32_0, lo32_0),
                       UPCRI_MAKEWORD(hi32_1, lo32_1),operation,64);
      hi32 = UPCRI_HIWORD(oldval);
      lo32 = UPCRI_LOWORD(oldval);
      break;
    }
    case _BUPC_ATOMIC_TYPE_U32:
    {
      bupc_common_rmw2(lo32_0,lo32_1,operation,32);
      hi32 = 0; /* warning suppression */
      lo32 = oldval;
      break;
    }
    default:
      hi32 = lo32 = 0; /* warning suppression */
      upcri_err("Invalid type in upcri_atomic_rmw2_SRequest");
  }

  UPCRI_AM_CALL(UPCRI_SHORT_REPLY(4, 5, 
		(token, UPCRI_HANDLER_ID(upcri_atomic_SReply),
		 bytes, hi32, lo32, UPCRI_SEND_PTR(result))));
  #undef bupc_common_rmw2
}

/* handler for 1-operand Read-Modify-Write operations */
void
upcri_atomic_rmw1_SRequest(gasnet_token_t token,
				int type, int operation,
				uint32_t hi32, uint32_t lo32,
			        void *addr, void *result) {
  #define bupc_fetchop_case(_width,_op)                                  \
  case _BUPC_ATOMIC_OP_##_op:                                            \
    oldval = _bupc_atomicU##_width##_##_op##_local(addr, op0, 0);        \
    break;

  #define bupc_common_rmw1(_op0,_operation,_width)                       \
    const uint##_width##_t op0 = (_op0);                                 \
    uint##_width##_t oldval;                                             \
    switch(_operation) {                                                 \
      bupc_fetchop_case(_width,fetchadd);                                \
      bupc_fetchop_case(_width,fetchand);                                \
      bupc_fetchop_case(_width,fetchor);                                 \
      bupc_fetchop_case(_width,fetchxor);                                \
      bupc_fetchop_case(_width,swap);                                    \
      default:                                                           \
        oldval = 0; /* warning suppression */                            \
        upcri_err("Invalid operation in upcri_atomic_rmw1_SRequest");    \
    }                                                                    \
    bytes = _width/8;

  int bytes;
#if UPCR_DEBUG
  bytes = 0;	/* avoid uninitialized variable warning */
#endif
  switch (type) {
    case _BUPC_ATOMIC_TYPE_U64:
    {
      bupc_common_rmw1(UPCRI_MAKEWORD(hi32, lo32),operation,64);
      hi32 = UPCRI_HIWORD(oldval);
      lo32 = UPCRI_LOWORD(oldval);
      break;
    }
    case _BUPC_ATOMIC_TYPE_U32:
    {
      bupc_common_rmw1(lo32,operation,32);
      lo32 = oldval;
      break;
    }
    default:
      upcri_err("Invalid type in upcri_atomic_rmw1_SRequest");
  }

  UPCRI_AM_CALL(UPCRI_SHORT_REPLY(4, 5, 
		(token, UPCRI_HANDLER_ID(upcri_atomic_SReply),
		 bytes, hi32, lo32, UPCRI_SEND_PTR(result))));
  #undef bupc_fetchop_case
  #undef bupc_common_rmw1
}

/* handler for 0-oparand Read-Modify-Write operations */
void
upcri_atomic_rmw0_SRequest(gasnet_token_t token,
                           int type, int operation,
                           void *addr, void *result) {
  #define bupc_common_rmw0(_operation,_width)                            \
    uint##_width##_t oldval;                                             \
    switch(_operation) {                                                 \
      case _BUPC_ATOMIC_OP_fetchnot:                                     \
        oldval = _bupc_atomicU##_width##_fetchnot##_local(addr, 0);      \
        break;                                                           \
      default:                                                           \
        oldval = 0; /* warning suppression */                            \
        upcri_err("Invalid operation in upcri_atomic_rmw0_SRequest");    \
    }                                                                    \
    bytes = _width/8;

  uint32_t hi32, lo32;
  int bytes;
#if UPCR_DEBUG
  hi32 = lo32 = bytes = 0;	/* avoid uninitialized variable warnings */
#endif
  switch (type) {
    case _BUPC_ATOMIC_TYPE_U64:
    {
      bupc_common_rmw0(operation,64);
      hi32 = UPCRI_HIWORD(oldval);
      lo32 = UPCRI_LOWORD(oldval);
      break;
    }
    case _BUPC_ATOMIC_TYPE_U32:
    {
      bupc_common_rmw0(operation,32);
      lo32 = oldval;
      break;
    }
    default:
      upcri_err("Invalid type in upcri_atomic_rmw1_SRequest");
  }

  UPCRI_AM_CALL(UPCRI_SHORT_REPLY(4, 5, 
		(token, UPCRI_HANDLER_ID(upcri_atomic_SReply),
		 bytes, hi32, lo32, UPCRI_SEND_PTR(result))));
  #undef bupc_common_rmw0
}

/*---------------------------------------------------------------------------------*/
