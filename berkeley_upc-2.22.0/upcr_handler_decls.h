/* $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_handler_decls.h $
 * Jason Duell <jduell@lbl.gov>
 *
 * Central location for Active Message handler declarations.  These
 * declarations take a rather odd form in order to 'transparently' support 32
 * vs. 64 bit architectures over AM (which only supports 32 bit arguments).
 *
 * Each Active Message handler function in the runtime must have a
 * corresponding entry here.  NOTHING besides entries, comments, and
 * preprocessor commands can exist in this file (it gets expanded into enum
 * definitions, and other funny contexts).  This file gets included by other
 * files multiple times, which is why it lacks the conventional "#ifndef
 * FOO_H..." wrappers around the body.
 *
 * Do NOT put a semicolon at the end of each macro, or Bad Things are
 * guaranteed to happen.
 *
 * A declaration must consist of an encompassing
 * UPCRI_{SHORT|MEDIUM|LONG}_HANDLER() macro, the arguments of which are
 *
 * 1) The name of the handler function.  This function must be implemented
 *    somewhere,  but you do not need to declare a prototype for it in a
 *    header file.  The function can be declared inline, so long as you
 *    guarantee that the definition is visible to upcr_handlers.c. If the
 *    function is not inline, it cannot be static.
 * 2) The number of *extra* arguments on a 32 bit platform. 
 * 3) The number of *extra* arguments on a 64 bit platform.  Extra arguments
 *    that are (or may be) 64 bits in size must be counted as 2 arguments.
 * 4) A parenthesized list of the prototype arguments of the function.  
 *    AM handlers must all return an int, and all must take a
 *    gasnet_token_t as their first argument.  Medium and Long handlers
 *    must also take a void * pointer and a size_t length as the next
 *    arguments.  Extra arguments may be passed, but must all be either 32 bit
 *    gasnet_handlerarg_t's, or void * pointers (which are 32/64 bits
 *    depending on the platform).  Any integer arguments that
 *    could require 64 bits of info on a 64 bit platform (example: an integer
 *    offset into an address space area) should be passed as pointers (i.e
 *    cast the integer to a pointer--don't pass the address of the int).
 *    Structs (like shared pointers) should be passed in a Medium or Long
 *    calls in the opaque payload.
 * 5) A parenthesized list, as it would appear in a function call on a 32 bit
 *    platform to your handler, with all arguments named a0, a1, ... aN.
 *    Pointers must be wrapper in the UPCRI_RECV_PTR() macro (to cast from a
 *    gasnet_handlerarg_t to a void *).
 * 6) Same thing, but for 64 bit platforms.  Since gasnet_handlerarg_t's are
 *    32 bits, the ptr macro must consume 2 arguments.
 *
 * Convention for UPC Runtime AM handler names:  use 'S/M/L' 
 * letter for short/medium/long, and then either 'Request' or 'Reply',
 * e.g. "upcri_foo_MRequest"
 *
 * To call an AM handler, use one of the
 * UPCRI_{SHORT|MEDIUM|LONG}_{REQUEST|REPLY} macros.  These take the number of
 * extra arguments for 32/64 architectures (again, pointers count as 2 args
 * for 64 bit platforms), then a parenthesized list of arguments:
 * 1) The number of the node that the request is going to (if a Request), or
 *    the magic word 'token' (if a Reply).
 * 2) The ID of the handler being called, gotten via
 *    UPCRI_HANDLER_ID(function_name)
 * 3) If the handler is Medium or long, the pointer to the data you are
 *    sending, then the length of the data to be sent.
 * 4) The remaining (extra) arguments to the function.  Any pointers (or ints
 *    that are being passed as pointers) must be wrapped in a UPCRI_SEND_PTR
 *    macro call.
 */

/* 
 * These macros are just to make the lines shorter... 
 */
#define tok gasnet_token_t
#define arg gasnet_handlerarg_t
#ifdef PLATFORM_ARCH_32
#  define ptr(p) UPCRI_RECV_PTR(p)
#else 
#  define ptr2(p1, p2) UPCRI_RECV_PTR(p1, p2)
#endif
 
/*
 * Atomic ops
 */
UPCRI_SHORT_HANDLER(upcri_atomic_SReply, 4, 5,
    (tok token, int bytes, uint32_t hi32, uint32_t lo32, void *trigger),
    (token, a0, a1, a2, ptr(a3)),
    (token, a0, a1, a2, ptr2(a3,a4)))
UPCRI_SHORT_HANDLER(upcri_atomic_set_SRequest, 5, 7,
    (tok token, int bytes, uint32_t hi32, uint32_t lo32, void *addr, void *trigger),
    (token, a0, a1, a2, ptr(a3), ptr(a4)),
    (token, a0, a1, a2, ptr2(a3,a4), ptr2(a5,a6)))
UPCRI_SHORT_HANDLER(upcri_atomic_read_SRequest, 3, 5,
    (tok token, int bytes, void *addr, void *trigger),
    (token, a0, ptr(a1), ptr(a2)),
    (token, a0, ptr2(a1,a2), ptr2(a3,a4)))
UPCRI_SHORT_HANDLER(upcri_atomic_rmw0_SRequest, 4, 6,
    (tok token, int type, int operation, void *addr, void *trigger),
    (token, a0, a1, ptr(a2), ptr(a3)),
    (token, a0, a1, ptr2(a2,a3), ptr2(a4,a5)))
UPCRI_SHORT_HANDLER(upcri_atomic_rmw1_SRequest, 6, 8,
    (tok token, int type, int operation, uint32_t hi32, uint32_t lo32, void *addr, void *trigger),
    (token, a0, a1, a2, a3, ptr(a4), ptr(a5)),
    (token, a0, a1, a2, a3, ptr2(a4,a5), ptr2(a6,a7)))
UPCRI_SHORT_HANDLER(upcri_atomic_rmw2_SRequest, 8, 10,
    (tok token, int type, int operation, uint32_t hi32_0, uint32_t lo32_0,
     uint32_t hi32_1, uint32_t lo32_1, void *addr, void *trigger),
    (token, a0, a1, a2, a3, a4, a5, ptr(a6), ptr(a7)),
    (token, a0, a1, a2, a3, a4, a5, ptr2(a6,a7), ptr2(a8,a9)))

/*
 * Memory allocation handler functions
 */
UPCRI_SHORT_HANDLER(upcri_global_alloc_SRequest, 5, 9, 
    (tok token, void *nblocks, void *blocksz, void *result_sptr, void *trigger,
    gasnet_handlerarg_t caller),
    (token, ptr(a0), ptr(a1), ptr(a2), ptr(a3), a4),
    (token, ptr2(a0,a1), ptr2(a2,a3), ptr2(a4,a5), ptr2(a6,a7), a8))

UPCRI_MEDIUM_HANDLER(upcri_global_alloc_MReply, 3, 6,
    (tok token, void *msg, size_t len, void *res, void *trigger, void *lheapsz),
    (token, addr, nbytes, ptr(a0), ptr(a1), ptr(a2)),
    (token, addr, nbytes, ptr2(a0,a1), ptr2(a2,a3), ptr2(a4,a5)))

UPCRI_SHORT_HANDLER(upcri_expand_local_SRequest, 4, 7,
    (tok token, void *neededlheapsz, void *requestsz, void *trigger_addr,
    gasnet_handlerarg_t caller),
    (token, ptr(a0), ptr(a1), ptr(a2), a3),
    (token, ptr2(a0,a1), ptr2(a2,a3), ptr2(a4,a5), a6))

UPCRI_SHORT_HANDLER(upcri_expand_local_SReply, 2, 4,
    (tok token, void *newlargestlh, void *trigger_addr),
    (token, ptr(a0), ptr(a1)),
    (token, ptr2(a0,a1), ptr2(a2,a3)))
    
UPCRI_MEDIUM_HANDLER(upcri_free_MRequest, 0, 0,
    (tok token, void *addr, size_t nbytes),
    (token, addr, nbytes),
    (token, addr, nbytes))

/* 
 * Remote memcpy functions
 */
UPCRI_SHORT_HANDLER(upcri_remote_memcpy_SRequest, 4, 8,
    (tok token, void *dst, void *src, void *sz, void *trigger),
    (token, ptr(a0), ptr(a1), ptr(a2), ptr(a3)),
    (token, ptr2(a0,a1), ptr2(a2,a3), ptr2(a4,a5), ptr2(a6,a7)))

UPCRI_SHORT_HANDLER(upcri_remote_memcpy_SReply, 1, 2,
    (tok token, void *trigger),
    (token, ptr(a0)),
    (token, ptr2(a0,a1)))

/* 
 * Lock handler functions
 * Target tids are needed only in pthread builds where node numbers are not enough.
 * So, arg counts for several messages depend on UPCRI_UPC_PTHREADS
 */
#if UPCRI_UPC_PTHREADS
UPCRI_SHORT_HANDLER(upcri_SRP_lockreply, 4, 5,
    (tok token, arg threadid, arg generation, arg thread, void *addr),
    (token, a0, a1, a2, ptr(a3)),
    (token, a0, a1, a2, ptr2(a3,a4)))

UPCRI_SHORT_HANDLER(upcri_SRP_unlockreply, 2, 2,
    (tok token, arg threadid, arg reply),
    (token, a0, a1),
    (token, a0, a1))

UPCRI_SHORT_HANDLER(upcri_SRP_lockgrant, 1, 1,
    (tok token, arg threadid),
    (token, a0),
    (token, a0))

UPCRI_SHORT_HANDLER(upcri_SRQ_lockdestroy, 3, 4,
    (tok token, arg freer_threadid, arg lock_threadid, void *lock),
    (token, a0, a1, ptr(a2)), 
    (token, a0, a1, ptr2(a2,a3)))
#else /* UPCRI_UPC_PTHREADS */
UPCRI_SHORT_HANDLER(upcri_SRP_lockreply, 3, 4,
    (tok token, arg generation, arg thread, void *addr),
    (token, a0, a1, ptr(a2)),
    (token, a0, a1, ptr2(a2,a3)))

UPCRI_SHORT_HANDLER(upcri_SRP_unlockreply, 1, 1,
    (tok token, arg reply),
    (token, a0),
    (token, a0))

UPCRI_SHORT_HANDLER(upcri_SRP_lockgrant, 0, 0,
    (tok token),
    (token),
    (token))

UPCRI_SHORT_HANDLER(upcri_SRQ_lockdestroy, 2, 3,
    (tok token, arg freer_threadid, void *lock),
    (token, a0, ptr(a1)), 
    (token, a0, ptr2(a1,a2)))
#endif /* UPCRI_UPC_PTHREADS */

UPCRI_SHORT_HANDLER(upcri_SRQ_lock, 4, 6,
    (tok token, arg isblocking, void *lock, arg threadid, void *address),
    (token, a0, ptr(a1), a2, ptr(a3)), 
    (token, a0, ptr2(a1,a2), a3, ptr2(a4,a5)))

UPCRI_SHORT_HANDLER(upcri_SRQ_unlock, 3, 4,
    (tok token, arg threadid, arg generation, void *lock),
    (token, a0, a1, ptr(a2)), 
    (token, a0, a1, ptr2(a2,a3)))

UPCRI_SHORT_HANDLER(upcri_SRQ_lockenqueue, 2, 3,
    (tok token, arg thread, void *tail_addr),
    (token, a0, ptr(a1)),
    (token, a0, ptr2(a1,a2)))

UPCRI_SHORT_HANDLER(upcri_SRQ_freeheldlock, 1, 2,
    (tok token, void *tail_addr),
    (token, ptr(a0)), 
    (token, ptr2(a0,a1)))

/* 
 * Semaphore handler functions
 */
UPCRI_SHORT_HANDLER(upcri_SR_sem_free, 3, 5,
    (tok token, arg threadid, void *ps, void *done),
    (token, a0, ptr(a1), ptr(a2)), 
    (token, a0, ptr2(a1,a2), ptr2(a3,a4)))

UPCRI_SHORT_HANDLER(upcri_SR_tinypacket_connect, 4, 7,
    (tok token, arg threadid, void *ps, void *psp, void *pst),
    (token, a0, ptr(a1), ptr(a2), ptr(a3)), 
    (token, a0, ptr2(a1,a2), ptr2(a3,a4), ptr2(a5,a6)))

UPCRI_SHORT_HANDLER(upcri_SRQ_sem_upN, 2, 3,
    (tok token, arg seminc, void *semaddr),
    (token, a0, ptr(a1)), 
    (token, a0, ptr2(a1,a2)))

UPCRI_MEDIUM_HANDLER(upcri_MRQ_memput_signal, 6, 8,
    (tok token, void *addr, size_t nbytes, arg seqnum, arg threadid, arg numfragments, arg seminc, void *semaddr, void *dstaddr),
    (token, addr, nbytes, a0, a1, a2, a3, ptr(a4), ptr(a5)), 
    (token, addr, nbytes, a0, a1, a2, a3, ptr2(a4,a5), ptr2(a6,a7)))

UPCRI_LONG_HANDLER(upcri_LRQ_memput_signal, 5, 6,
    (tok token, void *addr, size_t nbytes, arg seqnum, arg threadid, arg numfragments, arg seminc, void *semaddr),
    (token, addr, nbytes, a0, a1, a2, a3, ptr(a4)), 
    (token, addr, nbytes, a0, a1, a2, a3, ptr2(a4,a5)))

#if defined(GASNET_SEGMENT_EVERYTHING) && UPCRI_UPC_PTHREADS
  /* Gather gasnet_seginfo_t's for segment exchange */
  UPCRI_SHORT_HANDLER(upcri_SRQ_seginfo, 3, 6,
    (tok token, void *info_addr, void *seg_addr, void *seg_size),
    (token, ptr(a0), ptr(a1), ptr(a2)),
    (token, ptr2(a0,a1), ptr2(a2,a3), ptr2(a4,a5)))
#endif

#undef tok
#undef arg
#ifdef PLATFORM_ARCH_32
#undef ptr
#else
#undef ptr2
#endif

