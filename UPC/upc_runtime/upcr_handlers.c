/*
 * Grisly, preprocessor-addled implementation of Active Message handler wrapper
 * functions.
 *
 * You are not expected to understand this--read the notes in
 * upcr_handler_decls.h, and you shouldn't need to.
 *
 * A wrapper for each handler declared in <upcr_handler_decls.h> is
 * implemented.  The wrapper handles converting 64 bit pointers into two 32
 * bit arguments, and calls the 'real' handler function that the user writes.
 * 
 * This framework assumes that the user implements each handler they declare
 * somewhere--this file doesn't need to see prototypes of them, but the linker
 * will fail if any of them don't exist.
 *
 * An array of all the handlers is constructed, and used to implement the
 * upcri_get_handlertable() function.
 */


#include <upcr_internal.h>

/* 
 * These argument-list macros foreshadow the madness to come...
 */
#define UPCRI_HANDLER_ARGS0
#define UPCRI_HANDLER_ARGS1  , gasnet_handlerarg_t a0
#define UPCRI_HANDLER_ARGS2  , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1
#define UPCRI_HANDLER_ARGS3  , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2
#define UPCRI_HANDLER_ARGS4  , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3
#define UPCRI_HANDLER_ARGS5  , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4
#define UPCRI_HANDLER_ARGS6  , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5
#define UPCRI_HANDLER_ARGS7  , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5, \
			       gasnet_handlerarg_t a6
#define UPCRI_HANDLER_ARGS8  , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5, \
			       gasnet_handlerarg_t a6, gasnet_handlerarg_t a7
#define UPCRI_HANDLER_ARGS9  , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5, \
			       gasnet_handlerarg_t a6, gasnet_handlerarg_t a7, \
			       gasnet_handlerarg_t a8
#define UPCRI_HANDLER_ARGS10 , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5, \
			       gasnet_handlerarg_t a6, gasnet_handlerarg_t a7, \
			       gasnet_handlerarg_t a8, gasnet_handlerarg_t a9
#define UPCRI_HANDLER_ARGS11 , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5, \
			       gasnet_handlerarg_t a6, gasnet_handlerarg_t a7, \
			       gasnet_handlerarg_t a8, gasnet_handlerarg_t a9, \
			       gasnet_handlerarg_t a10
#define UPCRI_HANDLER_ARGS12 , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5, \
			       gasnet_handlerarg_t a6, gasnet_handlerarg_t a7, \
			       gasnet_handlerarg_t a8, gasnet_handlerarg_t a9, \
			       gasnet_handlerarg_t a10, gasnet_handlerarg_t a11
#define UPCRI_HANDLER_ARGS13 , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5, \
			       gasnet_handlerarg_t a6, gasnet_handlerarg_t a7, \
			       gasnet_handlerarg_t a8, gasnet_handlerarg_t a9, \
			       gasnet_handlerarg_t a10, gasnet_handlerarg_t a11\
			       gasnet_handlerarg_t a12
#define UPCRI_HANDLER_ARGS14 , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5, \
			       gasnet_handlerarg_t a6, gasnet_handlerarg_t a7, \
			       gasnet_handlerarg_t a8, gasnet_handlerarg_t a9, \
			       gasnet_handlerarg_t a10, gasnet_handlerarg_t a11, \
			       gasnet_handlerarg_t a12, gasnet_handlerarg_t a13
#define UPCRI_HANDLER_ARGS15 , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5, \
			       gasnet_handlerarg_t a6, gasnet_handlerarg_t a7, \
			       gasnet_handlerarg_t a8, gasnet_handlerarg_t a9, \
			       gasnet_handlerarg_t a10, gasnet_handlerarg_t a11, \
			       gasnet_handlerarg_t a12, gasnet_handlerarg_t a13, \
			       gasnet_handlerarg_t a14
#define UPCRI_HANDLER_ARGS16 , gasnet_handlerarg_t a0, gasnet_handlerarg_t a1, \
			       gasnet_handlerarg_t a2, gasnet_handlerarg_t a3, \
			       gasnet_handlerarg_t a4, gasnet_handlerarg_t a5, \
			       gasnet_handlerarg_t a6, gasnet_handlerarg_t a7, \
			       gasnet_handlerarg_t a8, gasnet_handlerarg_t a9, \
			       gasnet_handlerarg_t a10, gasnet_handlerarg_t a11, \
			       gasnet_handlerarg_t a12, gasnet_handlerarg_t a13, \
			       gasnet_handlerarg_t a14, gasnet_handlerarg_t a15

/*
 * Declare prototypes for handler functions declared in
 * <upcr_handler_decls.h>.
 *
 * This relies on the fact that the result of '##' will be expanded if it
 * resolves to a macro name.  A fine preprocessor feature to know about.
 *
 * Notes:  
 *   1) The user's handler function always has the 32 bit # of args (pointers
 *	are 1 arg): providing that constant # of args across ptr sizes is the
 *	whole point of all this rigmarole.
 *   2) In this file we declare all of the user's args as
 *      gasnet_handlerarg_t's, including pointers (we can't do otherwise,
 *      since we don't know which args are pointers).  This is OK, since these
 *      prototypes won't be seen outside this file, and the number of arguments
 *      (and their size) is the same.
 */
#undef UPCRI_SHORT_HANDLER
#undef UPCRI_MEDIUM_HANDLER
#undef UPCRI_LONG_HANDLER

#define UPCRI_SHORT_HANDLER(name, cnt32, cnt64, protoargs, call32, call64) \
	  void name protoargs ;
#define UPCRI_MEDIUM_HANDLER(name, cnt32, cnt64, protoargs, call32, call64) \
	  void name protoargs ;
#define UPCRI_LONG_HANDLER(name, cnt32, cnt64, protoargs, call32, call64) \
	  void name protoargs ;
#include <upcr_handler_decls.h>


/*
 * Now define wrapper functions that expand out pointers into 2 parameters as
 * necessary, and then call the user's handler function.
 */
#undef UPCRI_SHORT_HANDLER
#undef UPCRI_MEDIUM_HANDLER
#undef UPCRI_LONG_HANDLER

#if PLATFORM_ARCH_32
#  define UPCRI_SHORT_HANDLER(name, cnt32, cnt64, protorgs, call32, call64)  \
          void name##_wrap (gasnet_token_t token  UPCRI_HANDLER_ARGS##cnt32) \
          {   UPCRI_BEGIN_AMHANDLER();                                       \
              name call32 ;                                                  \
              UPCRI_END_AMHANDLER();                                         \
	  }
#  define UPCRI_MEDIUM_HANDLER(name, cnt32, cnt64, protorgs, call32, call64) \
	  void name##_wrap (gasnet_token_t token, void *addr,		     \
			    size_t nbytes  UPCRI_HANDLER_ARGS##cnt32)	     \
          {   UPCRI_BEGIN_AMHANDLER();                                       \
              name call32 ;                                                  \
              UPCRI_END_AMHANDLER();                                         \
	  }
#  define UPCRI_LONG_HANDLER(name, cnt32, cnt64, protorgs, call32, call64)   \
	  void name##_wrap (gasnet_token_t token, void *addr,		     \
			   size_t nbytes  UPCRI_HANDLER_ARGS##cnt32)	     \
          {   UPCRI_BEGIN_AMHANDLER();                                       \
              name call32 ;                                                  \
              UPCRI_END_AMHANDLER();                                         \
	  }
#elif defined(PLATFORM_ARCH_64)
#  define UPCRI_SHORT_HANDLER(name, cnt32, cnt64, protorgs, call32, call64)  \
	  void name##_wrap (gasnet_token_t token  UPCRI_HANDLER_ARGS##cnt64) \
          {   UPCRI_BEGIN_AMHANDLER();                                       \
              name call64 ;                                                  \
              UPCRI_END_AMHANDLER();                                         \
	  }
#  define UPCRI_MEDIUM_HANDLER(name, cnt32, cnt64, protorgs, call32, call64) \
	  void name##_wrap (gasnet_token_t token, void *addr,		     \
			    size_t nbytes  UPCRI_HANDLER_ARGS##cnt64)	     \
          {   UPCRI_BEGIN_AMHANDLER();                                       \
              name call64 ;                                                  \
              UPCRI_END_AMHANDLER();                                         \
	  }
#  define UPCRI_LONG_HANDLER(name, cnt32, cnt64, protorgs, call32, call64)   \
	  void name##_wrap (gasnet_token_t token, void *addr,		     \
			   size_t nbytes  UPCRI_HANDLER_ARGS##cnt64)	     \
          {   UPCRI_BEGIN_AMHANDLER();                                       \
              name call64 ;                                                  \
              UPCRI_END_AMHANDLER();                                         \
	  }
#endif

#include <upcr_handler_decls.h>


/*
 * Now make a table of the wrapper functions and their IDs.
 */
#undef UPCRI_SHORT_HANDLER
#undef UPCRI_MEDIUM_HANDLER
#undef UPCRI_LONG_HANDLER

#if GASNET_USE_STRICT_PROTOTYPES
typedef void *handler_fn;
#else
typedef void (*handler_fn)();  /* prototype for generic handler function */
#endif

#define UPCRI_SHORT_HANDLER(name, cnt32, cnt64, protorgs, call32, call64) \
	{ UPCRI_HANDLER_ID(name), (handler_fn) name##_wrap },
#define UPCRI_MEDIUM_HANDLER(name, cnt32, cnt64, protorgs, call32, call64) \
	{ UPCRI_HANDLER_ID(name), (handler_fn) name##_wrap },
#define UPCRI_LONG_HANDLER(name, cnt32, cnt64, protorgs, call32, call64) \
	{ UPCRI_HANDLER_ID(name), (handler_fn) name##_wrap },

static gasnet_handlerentry_t handler_table[] = {
#   include <upcr_handler_decls.h>
    /* one last bogus entry, since last must not have a comma */
    { 0, NULL }
};

/*
 * Provide the table and the number of entries in it to the initialization
 * functions.
 */
gasnet_handlerentry_t * upcri_get_handlertable(void)
{
    return handler_table;
}

size_t upcri_get_handlertable_count(void)
{
    return (sizeof(handler_table) / sizeof(gasnet_handlerentry_t)) - 1;
}

