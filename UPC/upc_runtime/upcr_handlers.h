/*
 * Exports enum id's for Active Message handlers,
 * and macros for calling handlers.
 *
 * You are not expected to understand this--read the notes in
 * upcr_handler_decls.h, and you shouldn't need to.
 *
 * Jason Duell <jcduell@lbl.gov>
 *
 * $id$
 */

#ifndef UPCR_HANDLERS_H
#define UPCR_HANDLERS_H

/* 
 * Macros for splitting and reassembling 64-bit quantities 
 */
#define UPCRI_HIWORD(arg)     ((uint32_t) (((uint64_t)(arg)) >> 32))
#if PLATFORM_COMPILER_CRAY || PLATFORM_COMPILER_INTEL || defined(__cplusplus)
  /* workaround irritating warning #69: Integer conversion resulted in truncation. 
     which happens whenever Cray C or Intel C sees address-of passed to SEND_PTR
   */
#define UPCRI_LOWORD(arg)     ((uint32_t) (((uint64_t)(arg)) & 0xFFFFFFFF))
#else
#define UPCRI_LOWORD(arg)     ((uint32_t) ((uint64_t)(arg)))
#endif
#define UPCRI_MAKEWORD(hi,lo) (   (((uint64_t)(hi)) << 32) \
			        | (((uint64_t)(lo)) & 0xffffffff) )

/* Name of handler ID for a given handler function */
#define UPCRI_HANDLER_ID(name) name##_handler_id

/* 
 * These are used to set up an enum value for each handler ID.
 */
#define UPCRI_SHORT_HANDLER(name, cnt32, cnt64, protoargs, call32, call64) \
	UPCRI_HANDLER_ID(name),

#define UPCRI_MEDIUM_HANDLER(name, cnt32, cnt64, protoargs, call32, call64) \
	UPCRI_HANDLER_ID(name),

#define UPCRI_LONG_HANDLER(name, cnt32, cnt64, protoargs, call32, call64) \
	UPCRI_HANDLER_ID(name),

/* Every handler function needs a uniqe number between 200-255.
 * The GASNet implementation reserves ID's 1-127 for itself: client libs must
 * use IDs between 128-255.
 */
#define UPCRI_HANDLER_BASE  127

/* Crank out the enum values */
enum {
    _DUMMY_STARTVAL = UPCRI_HANDLER_BASE,
#   include <upcr_handler_decls.h>
    _WE_DONT_NEED_NO_STINKING_COMMA_ENDVAL
};

/* AM safety assertions */
#if UPCR_DEBUG 
  GASNETT_THREADKEY_DECLARE(upcri_AMhandlercontext_key);

  #define UPCRI_BEGIN_AMHANDLER() UPCRI_PEVT_BEGINAMHANDLER do {                                              \
      intptr_t count = (intptr_t)gasnett_threadkey_get(upcri_AMhandlercontext_key); \
      upcri_assert(count >= 0);                                                     \
      gasnett_threadkey_set(upcri_AMhandlercontext_key, (void *)(count+1));         \
    } while (0)
  #define UPCRI_END_AMHANDLER() do {                                                \
      intptr_t count = (intptr_t)gasnett_threadkey_get(upcri_AMhandlercontext_key); \
      upcri_assert(count >= 1);                                                     \
      gasnett_threadkey_set(upcri_AMhandlercontext_key, (void *)(count-1));         \
    } while (0) UPCRI_PEVT_ENDAMHANDLER
  #define UPCRI_ASSERT_NOTINAMHANDLER()                                               \
      ((void)                                                                         \
      (((intptr_t)gasnett_threadkey_get(upcri_AMhandlercontext_key)) ?                \
       (upcri_err("Illegal non-AM-safe operation in an AM Handler context, at %s:%i", \
                  __FILE__,__LINE__),0) :                                             \
      0))
  #define UPCRI_ASSERT_INAMHANDLER()                                              \
      ((void)                                                                     \
      (((intptr_t)gasnett_threadkey_get(upcri_AMhandlercontext_key)) < 1 ?        \
       (upcri_err("Illegal AM operation outside an AM Handler context, at %s:%i", \
                  __FILE__,__LINE__),0) :                                         \
      0))
  #define UPCRI_ASSERT_NOTINAMHANDLER_DECL() \
      char _bupc_AMHandlerCheck = sizeof(_bupc_AMHandlerCheck) + (UPCRI_ASSERT_NOTINAMHANDLER(), 0);
#else
  #define UPCRI_BEGIN_AMHANDLER()       UPCRI_PEVT_BEGINAMHANDLER
  #define UPCRI_END_AMHANDLER()         UPCRI_PEVT_ENDAMHANDLER
  #define UPCRI_ASSERT_NOTINAMHANDLER() ((void)0)
  #define UPCRI_ASSERT_NOTINAMHANDLER_DECL() /* must be nothing */
  #define UPCRI_ASSERT_INAMHANDLER()    ((void)0)
#endif

/*
 * Pointer packing/unpacking macros
 */
#if PLATFORM_ARCH_32
#  define UPCRI_SEND_PTR(ptr)   ((gasnet_handlerarg_t) ptr)
#  define UPCRI_RECV_PTR(a0)    ((void *) a0)
#elif PLATFORM_ARCH_64
#  define UPCRI_SEND_PTR(ptr)   ((gasnet_handlerarg_t) UPCRI_HIWORD(ptr)), \
				((gasnet_handlerarg_t) UPCRI_LOWORD(ptr))
#  define UPCRI_RECV_PTR(a0,a1) ((void *) UPCRI_MAKEWORD(a0,a1))
#endif

/*
 * Use these to call Active Message handlers.
 *
 * We rely on the fact that the C preprocessor treats anything within
 * parenthesis (including comma-separated tokens) as a single argument in
 * order to write a single macro that can take variable numbers of arguments.
 * But this makes the invocation look a little funny.
 *
 * Usage: 
 *
 * cnt32	       = Number of args needed for AM call on PTR32 platform.
 * cnt64	       = Number of args needed for AM call on PTR64 platform.
 * parenthesized_args = Parenthesized argument list for AM request/reply
 *			 call, with any pointer args wrapped in a
 *			 UPCRI_SEND_PTR() macro.
 */

#if PLATFORM_ARCH_32
#  define UPCRI_SHORT_REQUEST(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_NOTINAMHANDLER(), gasnet_AMRequestShort##cnt32 parenthesized_args
#  define UPCRI_SHORT_REPLY(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_INAMHANDLER(),    gasnet_AMReplyShort##cnt32 parenthesized_args
#  define UPCRI_MEDIUM_REQUEST(cnt32, cnt64, parenthesized_args)\
	  UPCRI_ASSERT_NOTINAMHANDLER(), gasnet_AMRequestMedium##cnt32 parenthesized_args
#  define UPCRI_MEDIUM_REPLY(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_INAMHANDLER(),    gasnet_AMReplyMedium##cnt32 parenthesized_args
#  define UPCRI_LONG_REQUEST(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_NOTINAMHANDLER(), gasnet_AMRequestLong##cnt32 parenthesized_args
#  define UPCRI_LONG_REPLY(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_INAMHANDLER(),    gasnet_AMReplyLong##cnt32 parenthesized_args
#  define UPCRI_LONGASYNC_REQUEST(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_NOTINAMHANDLER(), gasnet_AMRequestLongAsync##cnt32 parenthesized_args
#elif PLATFORM_ARCH_64
#  define UPCRI_SHORT_REQUEST(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_NOTINAMHANDLER(), gasnet_AMRequestShort##cnt64 parenthesized_args
#  define UPCRI_SHORT_REPLY(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_INAMHANDLER(),    gasnet_AMReplyShort##cnt64 parenthesized_args
#  define UPCRI_MEDIUM_REQUEST(cnt32, cnt64, parenthesized_args)\
	  UPCRI_ASSERT_NOTINAMHANDLER(), gasnet_AMRequestMedium##cnt64 parenthesized_args
#  define UPCRI_MEDIUM_REPLY(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_INAMHANDLER(),    gasnet_AMReplyMedium##cnt64 parenthesized_args
#  define UPCRI_LONG_REQUEST(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_NOTINAMHANDLER(), gasnet_AMRequestLong##cnt64 parenthesized_args
#  define UPCRI_LONG_REPLY(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_INAMHANDLER(),    gasnet_AMReplyLong##cnt64 parenthesized_args
#  define UPCRI_LONGASYNC_REQUEST(cnt32, cnt64, parenthesized_args)	\
	  UPCRI_ASSERT_NOTINAMHANDLER(), gasnet_AMRequestLongAsync##cnt64 parenthesized_args
#endif

/* States for triggers in client-server-ish operations */
enum {
    UPCRI_REQUEST_BLOCKED,
    UPCRI_REQUEST_DONE
};

/* Convenience wrapper for AM calls: if call fails, print error message and
 * abort */
#define UPCRI_AM_CALL(fncall)				      \
    do {						      \
	int retcode = (fncall);				      \
	if_pf(retcode != GASNET_OK) {			      \
	    upcri_gaserr(retcode, "while calling: " #fncall); \
	}						      \
    } while (0)

/*
 * Returns table of handlers and their IDs
 */
gasnet_handlerentry_t * upcri_get_handlertable(void);
size_t upcri_get_handlertable_count(void);


#endif /* UPCR_HANDLERS_H */
