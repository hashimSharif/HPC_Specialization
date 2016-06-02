/*
 * bupc_totalview_sptr.h
 *
 * Interface for Totalview to 'see' Berkeley UPC shared pointers.
 *
 */

#ifndef _UPCR_SPTR_BASE_H 
#define _UPCR_SPTR_BASE_H

/* Get basic types and standard headers, as portably obtained from
 * upcr/gasnet's configure magic.  
 * Note: these two headers should come first, in this order, for
 * portable_inttypes to work well */
#include <upcr_config.h>
#include <portable_inttypes.h>
#include <upcr_syshdrs.h>

#include <assert.h>

#include "bupc_assistant.h"

/* Tell upcr_sptr.h not to declare any static variables for us, since
 * Totalview isn't linked with the upcr runtime.  We'll get a compiler error
 * if upcr_sptr.h refers to any runtime variables which we haven't
 * special-cased in this header.  
 */
#define UPCRI_NOT_LINKED_WITH_RUNTIME 1

/* Linker-provided addressing only used by GCCUPC, which is not supported */
#if UPCRI_USING_GCCUPC || UPCR_USING_LINKADDRS 
 #error --enable-gccupc and --enable-totalview are incompatible: reconfigure
#endif 

#if UPCRI_SYMMETRIC_PSHARED
  #error --enable-sptr-symmetric does not yet work with --enable-totalview
#endif

/* Hack:  leverage pthreads "extra argument" macros to pass Totalview's UPC
 * thread info into upcr_sptr.h functions 
 */ 
#ifdef UPCRI_UPC_PTHREADS
  #error Totalview assistant library does not support pthreads!! 
#endif
#define UPCRI_PT_ARG_ALONE  uda_thread *thread
#define UPCRI_PT_ARG	    , UPCRI_PT_ARG_ALONE
#define UPCRI_PT_PASS_ALONE thread
#define UPCRI_PT_PASS	    , UPCRI_PT_PASS_ALONE
/* Some functions only need the extra arg for Totalview */
#define UPCRI_TV_ARG_ALONE  UPCRI_PT_ARG_ALONE
#define UPCRI_TV_ARG	    , UPCRI_TV_ARG_ALONE
#define UPCRI_TV_PASS_ALONE thread
#define UPCRI_TV_PASS	    , UPCRI_TV_PASS_ALONE

/*************************************************************************
 * Hacks to avoid upcr code constructs in upcr_sptr.h that aren't needed for
 * Totalview support, and would otherwise require that we #include other
 * upcr/gasnet headers.
 *************************************************************************/

#ifdef __cplusplus
  #define GASNETT_BEGIN_EXTERNC extern "C" {
  #define GASNETT_END_EXTERNC   }
#else
  #define GASNETT_BEGIN_EXTERNC 
  #define GASNETT_END_EXTERNC 
#endif

/* Don't bother inlining functions.
 * - Note: this works since we've got only one compilation unit
 *   (bupc_assistant.c). */
#define GASNETT_INLINE(function) 

/* Turn off upcr's assertions: they'll still be caught in executable */
#define upcri_assert(expr) ((void)0)

/* Datatypes defined elsewhere in upcr/gasnet headers */
typedef unsigned int upcr_thread_t;
typedef uint32_t gasnet_node_t;	

/************************************************************************* 
 * Things needed by upcr_sptr.h which we must custom handle for the assistant
 * library.
 *************************************************************************/

#define upcr_mythread()	    ((upcr_thread_t) bupc_assistant_mythread(thread))
#define upcr_threads()	    ((upcr_thread_t) bupc_assistant_threads(thread))
#define upcri_myregion()    (bupc_assistant_myregion(thread))
#if ! UPCRI_SINGLE_ALIGNED_REGIONS
#  define upcri_thread2region (bupc_assistant_thread2region(thread)) 
#endif

#include <upcr_sptr.h>



#endif  /* _UPCR_SPTR_BASE_H */
