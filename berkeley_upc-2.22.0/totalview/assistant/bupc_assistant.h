/* $Source: bitbucket.org:berkeleylab/upc-runtime.git/totalview/assistant/bupc_assistant.h $ */
/* $Locker:  $ */

/**********************************************************************
 * Copyright (C) 2001-2002 Etnus, LLC
 *
 * Permission is hereby granted to use, reproduce, prepare derivative
 * works, and to redistribute to others.
 *
 *				  DISCLAIMER
 *
 * Neither Etnus, nor any of their employees, makes any warranty
 * express or implied, or assumes any legal liability or
 * responsibility for the accuracy, completeness, or usefulness of any
 * information, apparatus, product, or process disclosed, or
 * represents that its use would not infringe privately owned rights.
 *
 * This code was written by
 * James Cownie: Etnus, LLC. <jcownie@etnus.com>
 **********************************************************************/

/* Update log
 *
 * Apr 1  2005 JCDuell@lbl.gov: Add Berkeley UPC support.
 * Dec 17 2002 JHC: Add two new lookup functions to allow lookups of variables
 *              and types on the thread (and therefore in shared libraries
 *              linked into the process). Version up to 5, but a totalview built
 *              for the V5 interface will accept a V4 assistant since we 
 *              added the new callbacks to the end of the table its fine.
 * Dec 10 2002 JHC: Up the version number; I should have done it on Dec 2.
 * Dec  2 2002 JHC: Pass the address as well as the name into symbol_to_pts
 *              Some implementations can do all they need directly from the 
 *              address so this can avoid a symbol lookup.
 * Oct 18 2002 JHC: Added uda_image and associated calls, changed
 *              uda_length_of_pts to use an image as its context rather than
 *              a thread. Add uda_type and associated calls.  We want to be
 *              able to find out the length of a PTS without needing a
 *              process, it must be deducible from an executable image on its
 *              own. Where sensible, various other callbacks now have image
 *              context rather job context.  Upped the interface compatibility.
 * Oct 15 2002 JHC: Added uda_get_threadno.
 * Oct 10 2002 JHC: Fixed some argument mis-namings, added error code ranges.
 *              (Thanks, Brian).
 * Oct  7 2002 JHC: Add the show_opaque call.
 * Apr 15 2002 JHC: Add uda_initialise_job, <stddef.h> and more explanation
 *              of the version calls.
 * Apr 11 2002 JHC: Add uda_no_information, clarify its use in the get_info
 *              callback.
 * Jan 30 2002 FNW: Fix update log format. The blank line is necessary.
 * Jan 21 2002 JHC: Significantly upgraded to allow more complicated
 *              assistant and support implementations where the upc_addressof
 *              a PTS is not its absolute address.
 * Oct 17 2001 JHC: Created.
 */

#ifndef _UPC_ASSISTANT_INCLUDED_
#define _UPC_ASSISTANT_INCLUDED_

#include <portable_inttypes.h>
#include <stddef.h>				/* We use size_t */

#ifdef	__cplusplus
extern "C" {
#endif

/***********************************************************************
 * This header defines the interface between a UPC enabled debugger
 * and an "assistant", which is a dynamic library which can be linked
 * into the debugger at run time (using dlopen() or an equivalent
 * function).  The assistant exists to separate the details of the UPC
 * run time implementation from the debugger, so that the debugger
 * does not need to be rebuilt when UPC implementations change, and
 * the debugger can portably support many different UPC
 * implementations.
 * 
 * Throughout this document "PTS" should be read as "Pointer To
 * Shared", i.e. the object misleadingly called a "shared pointer" in
 * the UPC specification. (Though note that the 1.1 specification has
 * adopted the term pointer to shared throughout, showing that there is
 * some good in the world).
 *
 * This interface is based on a number of fundamental design decisions
 * which are listed here :-
 *
 * 1) The assistant handles PTS arithmetic.
 *    (This is necessary if a PTS contains hidden implementation
 *    specific data).
 * 
 * 2) The assistant provides a way of unpacking the PTS into {thread,
 *    address, phase} so that the debugger can display these to the
 *    user. These are exactly upc_threadof, upc_addrfield and
 *    upc_phaseof.
 *	- NOTE: wrong! upc_addrfield() is not guaranteed to return a valid
 *	  address, just a *representation* of it.  For instance, Berkeley UPC
 *	  often stores an offset in a PTS instead of a full address (to save
 *	  bits), and our upc_addrfield returns that offset. JCD 3/11/05
 *    
 * 3) The assistant provides a way of packing a {thread, address,
 *    phase} back into a PTS. 
 *    (We need this if we're to allow the user to modify a PTS. 
 *    Since modifying a PTS implies that they already had a PTS
 *    any hidden data should be carried along too. If the assistant
 *    cannot do this, it can return failure).
 *
 * 4) The assistant provides a way of converting a PTS into a {thread,
 *    local_address} tuple so that the debugger can access the
 *    data. The local_address here is that which would have been the
 *    result of doing a cast to a local pointer inside UPC thread
 *    "thread".
 *
 *    (We need this because the UPC spec does not require that the
 *    upc_addrfield be the same as the result of casting to a local
 *    pointer, and the debugger needs to be able to access the target
 *    of a PTS).
 *
 * 5) The assistant provides a way of converting the address of a shared
 *    object read from the debug information into a PTS.
 *
 *    (We need this to allow the debugger to index an object like this
 *    extern shared int ia[50];
 *    )
 *
 * 6) The assistant needs to be able to copy data from store in the
 *    target processes (i.e. UPC threads) and convert it to host
 *    format.
 *    (This is provided by callbacks into the debugger).
 *
 * 7) The assistant must not hold state in static or global internal
 *    variables. It is entirely reasonable for the debugger to use the
 *    same assistant to debug two UPC jobs at the same time, and these
 *    need not have the same compilation model.  A corollary of this is
 *    that the assistant may need to hold its own state information
 *    associated with a UPC job or UPC thread.
 *
 * 8) All of the UPC threads in a UPC application are compiled with the
 *    same compilation model.
 *
 ***********************************************************************/

/***********************************************************************
 * Version of the interface this header represents 
 */
enum
{
  UPCDA_INTERFACE_COMPATIBILITY = 5
};

/***********************************************************************
 * Type definitions.
 */

/* Opaque types are used here to provide a degree of type checking
 * through the prototypes of the interface functions.
 *
 * Only pointers to these types are ever passed across the interface.
 * Internally to the debugger, or the assistant you should immediately
 * cast these pointers to pointers to the concrete types that you
 * actually want to use.
 *
 * (An alternative would be to use void * for all of these arguments,
 * but that would remove a useful degree of type checking; assuming
 * that you are thinking while typing the casts :-)
 *
 */

typedef struct uda_target_pts_ uda_target_pts;

typedef struct uda_job_         uda_job;
typedef struct uda_thread_      uda_thread;

typedef struct uda_job_info_    uda_job_info;
typedef struct uda_thread_info_ uda_thread_info; 

typedef struct uda_image_       uda_image;
typedef struct uda_image_info_  uda_image_info;

typedef struct uda_type_        uda_type;

/***********************************************************************
 * Defined types which form a part of the interface.
 */

/***********************************************************************
 * Raw address information.
 *
 * Note: these will likely need to be "long long" (or some suitable 64
 * bit type) on machines where the debugger and assistant are compiled
 * in 32 bit mode but the target process may have been compiled in 64
 * bit mode. 
 */
#if (defined (__sgi) || defined (__hpux) || defined (_AIX) || defined (__sun))
typedef unsigned long long uda_taddr;		/* Something long enough for a target address */
typedef long long          uda_tword;		/* Something long enough for a word    */
#else
/* Simple machines where there's only one compilation model */
typedef unsigned long uda_taddr;		/* Something long enough for a target address */
typedef long          uda_tword;		/* Something long enough for a word    */
#endif

/***********************************************************************
 * Defined structures which form part of the interface.
 */

/***********************************************************************
 * Note that even "simple" addresses may be more complicated than 
 * one might expect. The complexity arises when dealing with addresses
 * for symbols which have been looked up by the debugger in debug or
 * other symbol tables. The problem is that in a parallel environment such
 * as UPC the address at which a symbol appears in the address space
 * may be different in each process (UPC thread). (Consider a symbol in a 
 * dynamic library which is loaded at a different address in each process).
 *
 * We therefore use a different type for such an address (which may need
 * process specific relocation) from that which we use for an absolute address.
 *
 * We provide a callback into the debugger to allow the assistant
 * to convert a relocatable address into an absolute address within
 * a specific UPC thread.
 *
 * We assume that when creating a PTS from such an address the assistant is 
 * capable of doing whatever is necessary.
 *
 * This is a struct to ensure that it is hard to confuse it with a fully
 * resolved absolute address.
 */
typedef struct 
{
  uda_taddr value;
  uda_tword opaque;				/* Extra information which may be needed */
} uda_relocatable_addr;

/* A structure for (target) architectural information */
typedef struct
{
  int short_size;				/* sizeof (short) */
  int int_size;					/* sizeof (int)   */
  int long_size;				/* sizeof (long)  */
  int long_long_size;				/* sizeof (long long) */
  int pointer_size;				/* sizeof (void *) */
} uda_target_type_sizes;

/* A structure to represent the decoded values in a pointer to shared
 * when passed between the debugger and the assistant.
 */
typedef struct
{
  uda_taddr  addrfield;				/* local address */
  uda_tword  phase;				/* upc_phaseof()   */
  uda_tword  thread;				/* upc_threadof()  */
  uda_tword  opaque;				/* For implementations which need it. 
						 * This will be displayed by the debugger to the 
						 * user if so requested (see uda_show_opaque),
						 * in which case the user may also modify it.
						 */
} uda_debugger_pts;

/* Result codes. 
 * uda_ok is returned for success. 
 * Anything else implies a failure of some sort. 
 *
 * Most of the functions actually return one of these, however to avoid
 * any potential issues with different compilers implementing enums as
 * different sized objects, we actually use int as the result type.
 * 
 * Additional errors can be returned by the assistant or the debugger
 * in the appropriate ranges.
 *
 * See below for functions to convert codes to strings.
 */
enum {
  uda_ok = 0,
  uda_bad_assistant,
  uda_bad_job,
  uda_bad_thread_index,
  uda_no_information,
  uda_no_symbol,
  uda_read_failed,
  uda_relocation_failed,
  uda_first_assistant_code = 1000,			/* Allow for more pre-defines */
      uda_assistant_malloc_failed,
  uda_first_debugger_code  = 2000   
};

#define uda_error_belongs_to_assistant(code) (((code) >= uda_first_assistant_code) &&\
	                                      ((code) <  uda_first_debugger_code))


#define uda_error_belongs_to_debugger(code)  ((code) >= uda_first_debugger_code)

/***********************************************************************
 * Callbacks from the assistant to the debugger.
 *
 * All calls from the assistant back into the debugger are made via
 * a callback table, this means that the assistant DLL does not need
 * to be linked against the debugger to satisfy external symbols, and
 * makes it easier to extend the interface while being able to continue
 * to use old assistant libraries.
 *
 * Here we describe the type signatures of the callbacks so that we
 * can then define a callback table.
 *
 * All non memory allocation callbacks which can fail return a status
 * value as the function result. The interesting result is returned
 * via a pointer argument.
 */

/* Allocate store */
typedef void * (*uda_malloc_fp) (size_t);
/* Free it again */
typedef void   (*uda_free_fp)   (void *);

/* Print a message (intended for debugging use *ONLY*). */
typedef void (*uda_prints_fp) (const char *);

/* Convert an error code from the debugger into an error message 
 * (this cannot fail since it returns a string including the error
 * number if it is unknown */
typedef const char * (*uda_error_string_fp) (int);

/* Given a job return the number of UPC threads in it. */
typedef int (*uda_job_thread_count_fp) (uda_job *, int *);

/* Given a job return the requested UPC thread within it. */
typedef int (*uda_job_get_thread_fp) (uda_job *, uda_tword, uda_thread **);

/* Given a job return the image associated with it. */
typedef int (*uda_job_get_image_fp) (uda_job *, uda_image **);

/* Given a thread return the job it belongs to. */
typedef int (*uda_thread_get_job_fp) (uda_thread *, uda_job **);

/* These functions let the assistant library associate information
 * with specific jobs and threads and images. The definition of
 * uda_*_info is up to the assistant; the debugger only ever has a
 * pointer to it and doesn't look inside, so the assistant can store
 * whatever it wants.
 *
 * If a uda_get_*_info function is called before the corresponding
 * uda_set_*_info function has been called (or after the info has been
 * reset to (void *)0), then the get function will return
 * uda_no_information and nullify the result pointer.
 */
/* Associate information with a UPC job object */
typedef int (*uda_job_set_info_fp) (uda_job *, uda_job_info *);
typedef int (*uda_job_get_info_fp) (uda_job *, uda_job_info **);

/* Associate information with a UPC thread object */
typedef int (*uda_thread_set_info_fp) (uda_thread *, uda_thread_info *);
typedef int (*uda_thread_get_info_fp) (uda_thread *, uda_thread_info **);

/* Associate information with an image object */
typedef int (*uda_image_set_info_fp) (uda_image *, uda_image_info *);
typedef int (*uda_image_get_info_fp) (uda_image *, uda_image_info **);

/* Calls on an image */
/* Fill in the sizes of target types for this image */
typedef int (*uda_get_type_sizes_fp)  (uda_image *, uda_target_type_sizes *);
/* Lookup a global variable and return its relocatable address */
typedef int (*uda_variable_lookup_fp)    (uda_image *, const char *, uda_relocatable_addr *);
/* Lookup a type and return it */
typedef int (*uda_type_lookup_fp)    (uda_image *, const char *, uda_type **);

/* Calls on a type */
/* Get the length of the type in bytes */
typedef int (*uda_type_length_fp) (uda_type *, uda_tword *);
/* Lookup a field within an aggregate type by name, and return
 * its _bit_ offset within the aggregate, its bit length and its type.
 */
typedef int (*uda_type_get_member_info_fp) (uda_type *, const char *, 
					    uda_tword *bit_offset_, 
					    uda_tword *bit_length_,
					    uda_type **);

/* Calls on a uda_thread */
/* Relocate a relocatable address for use in a specific UPC thread */
typedef int (*uda_relocate_address_fp) (uda_thread *, const uda_relocatable_addr *, uda_taddr *);

/* Look up a variable in a thread.
 * This is more general than looking it up in an image, since it also
 * looks in any shared libraries which are linked into the thread.
 * Since this is thread specific the result is an absolute (rather than
 * relocatable) address. The address is therefore _only_ valid within
 * the specific thread.
 */
typedef int (*uda_thread_variable_lookup_fp) (uda_thread *, const char *, uda_taddr *);

/* Look up a type in a thread.
 * This is more general than looking it up in an image, since it also
 * looks in any shared libraries which are linked into the thread.
 */
typedef int (*uda_thread_type_lookup_fp) (uda_thread *, const char *, uda_type **);

/* Read store from a specific UPC thread */
typedef int (*uda_read_store_fp) (uda_thread *, uda_taddr, uda_tword, void *);
/* Convert data from target byte order to host byte order */
typedef int (*uda_target_to_host_fp)(uda_thread *, uda_tword, const void *, void *);
/* Convert data from host byte order to target byte order */
typedef int (*uda_host_to_target_fp)(uda_thread *, uda_tword, const void *, void *);

typedef struct 
{
  uda_malloc_fp                 malloc_cb;
  uda_free_fp                   free_cb;
  uda_prints_fp                 prints_cb;
  uda_error_string_fp           error_string_cb;

  uda_get_type_sizes_fp         get_type_sizes_cb;
  uda_variable_lookup_fp        variable_lookup_cb;
  uda_type_lookup_fp            type_lookup_cb;

  uda_relocate_address_fp       relocate_address_cb;

  uda_job_thread_count_fp       job_thread_count_cb;
  uda_job_get_thread_fp         job_get_thread_cb;
  uda_job_get_image_fp          job_get_image_cb;

  uda_thread_get_job_fp         thread_get_job_cb;

  uda_job_set_info_fp           job_set_info_cb;
  uda_job_get_info_fp	        job_get_info_cb;

  uda_thread_set_info_fp        thread_set_info_cb;
  uda_thread_get_info_fp        thread_get_info_cb;
			  
  uda_image_set_info_fp         image_set_info_cb;
  uda_image_get_info_fp         image_get_info_cb;

  uda_type_length_fp            type_length_cb;
  uda_type_get_member_info_fp   type_get_member_info_cb;

  uda_read_store_fp             read_store_cb;
  uda_target_to_host_fp         target_to_host_cb;
  uda_host_to_target_fp         host_to_target_cb;   
  uda_thread_type_lookup_fp     thread_type_lookup_cb;
  uda_thread_variable_lookup_fp thread_variable_lookup_cb;
} uda_basic_callbacks;

/***********************************************************************
 * Calls from the debugger into the DLL.
 ***********************************************************************/

/* Provide the library with the pointers to the the debugger functions
 * it needs The DLL need only save the pointer, the debugger promises
 * to maintain the table of functions valid for as long as
 * needed. (The table remains the property of the debugger, and should
 * not be messed with, or deallocated by the DLL). This applies to
 * all of the callback tables.
 */
extern void uda_setup_basic_callbacks (const uda_basic_callbacks *);

/* Version handling */
/* Return a printable string which identifies the assistant library,
 * suitable for logging by the debugger, or reporting by a customer in
 * a fault report.
 */
extern const char *uda_version_string (void);

/* Return the version compatinility UPCDA_INTERFACE_COMPATIBILITY
 * so that the debugger can check that it can use this assistant.
 */
extern int         uda_version_compatibility(void);

/* Provide a text string for an error value */
extern const char * uda_error_string (int);

/* Destroy any information associated with a uda_job */
extern void uda_destroy_job_info (uda_job *);
/* Destroy any information associated with a uda_thread */
extern void uda_destroy_thread_info (uda_thread *);
/* Destroy any information associated with a uda_image */
extern void uda_destroy_image_info (uda_image *);


/***********************************************************************
 * Useful calls which do real work, rather than just housekeeping.
 */

/* Let the assistant check that the target job really is suitable for
 *  the assistant.
 *
 * This call is made by the debugger into the assistant once per job
 * to allow the assistant to do whatever checking of the target and
 * information cacheing it wants to.
 *
 * The debugger will make the call _after_ the job has started and
 * created all its UPC threads, but before the debugger makes any
 * other call specific to this job (or its threads).  
 *
 * If this call fails (does not return uda_ok), then the debugger will
 * not use the assistant to help it when debugging this job.
 */
extern int uda_initialise_job (uda_job *);

/* Return the value of MYTHREAD for a specific uda_thread object.
 * This allows the debugger to determine the mapping between an 
 * unordered bag of threads/processes and the UPC world.
 *
 * As ever the result of the function is the status, the value
 * of MYTHREAD is returned through the second argument.
 *
 * We need this function because MYTHREAD is a somewhat odd object in UPC
 * and may not be present in the debug information, therefore we require
 * help from the assistant library to extract its value.
 */
extern int uda_get_threadno (uda_thread *, int *);
 
/* Convert the target process representation of a shared pointer to
 * the unpacked representation used by the debugger.
 *
 * Note :-
 *
 * 1) That the debugger is fetching those bits from the target and 
 *    placing them in a potentially unaligned buffer.
 * 2) It is the address of this buffer which is passed to the pack/unpack
 *    routines. 
 * 3) The data in the buffer is in target byte order, it has not been
 *    manipulated by the debugger in any way. (It's as if it had done
 *    a memcpy from the target).
 *
 * The debugger is responsible for fetching these objects because they may
 * reasonably be stored in registers, and constructing an interface to the
 * DLL which allows it to specify general addresses (which include registers)
 * is rather complicated (and unnecessary if the debugger can already
 * fetch the appropriate bits).
 * 
 * 4) The debugger passes in the UPC thread in case the assistant needs that 
 *    context.
 * 5) The debugger passes in the blocksize of the PTS' target, in case
 *    the UPC implementation uses different PTS objects depending on the
 *    block size.
 *
 */
extern int uda_unpack_pts (uda_thread *, const uda_target_pts *, uda_tword, uda_debugger_pts *);

/* Convert the unpacked representation of a shared pointer used by the
 * debugger back to the packed representation used by the target.
 */
extern int uda_pack_pts   (uda_thread *, const uda_debugger_pts *, uda_tword, uda_target_pts *);

/* Return the size of a shared pointer for a target with the requested
 * block size.  The debugger may be able to work this out from the
 * debug information, but it is also convenient to have it here.
 * Note that this call is on an image, so the assistant must be able to 
 * work out the result without reading target store, since the debugger
 * may call this before the job has started. Since this is likely dependent
 * on a compilation mode (or is simply constant), that should be fine.
 */
extern int uda_length_of_pts (uda_image *, uda_tword target_blocksize, uda_tword element_size, uda_tword *);

/* Tell the debugger whether to allow the user to see the "opaque" field
 * of a PTS with the given properties.
 * A result of uda_ok means show the opaque value, anything else means don't.
 */
extern int uda_show_opaque (uda_image *, uda_tword target_blocksize, uda_tword element_size);

/* Convert a PTS into a an absolute address. We assume that the thread in the
 * PTS does not change ! We pass in the block size and element size of the
 * pointer target in case that affects the calculation.
 */
extern int uda_pts_to_addr (uda_thread *, const uda_debugger_pts *, 
			    uda_tword target_blocksize, uda_tword element_size,
			    uda_taddr *);

/* Functions for PTS address arithmetic. 
 *
 * Index a PTS
 * Given a PTS, the target element size, the target blocking, the number of threads,
 * and the index required updates the PTS to point to that element.
 */
extern int uda_index_pts (uda_thread *, uda_debugger_pts *, uda_tword block_size, uda_tword element_size, uda_tword thread_count, uda_tword delta);

/* Compute the value of p1 - p2 where p1 and p2 are compatible
 * pointers to shared with properties detailed in the other arguments,
 * the result is returned in delta
 */
extern int uda_pts_difference (uda_thread *, const uda_debugger_pts *p1, const uda_debugger_pts *p2,uda_tword block_size, uda_tword element_size, uda_tword thread_count, uda_tword *delta);

/* Given the name of a symbol of a shared type (therefore a static or
 * global symbol), and its address (as given by the debug information)
 * in a thread compute the pointer-to-shared which represents the
 * address of the symbol.
 */
extern int uda_symbol_to_pts (uda_thread *, const char *, uda_taddr sym_addr, uda_tword block_size, uda_tword element_size, uda_debugger_pts *);

/* JCD: accessor functions for Berkeley UPC shared ptr representation. 
 * - These are not directly used by bupc_assistant.c, but rather are invoked
 *   from within upcr_sptr.h functions when that file's functions call into
 *   upcr_sptr.h */
int	   bupc_assistant_mythread (uda_thread *thread);
int	   bupc_assistant_threads (uda_thread *thread);
uintptr_t  bupc_assistant_myregion (uda_thread *thread);
uintptr_t *bupc_assistant_thread2region (uda_thread *thread);

static void d_printf (const char *fmt, ...);


#define TV_ASST_DEBUG 0
#if TV_ASST_DEBUG 
  #if __GNUC__
    #define TV_ASST_TRACE(call) TV_DO_TRACE call ;
    #define TV_DO_TRACE(format, args...) d_printf("()()()()()()() %s: " format "\n", __FUNCTION__, ## args)
  #elif HAVE_FUNC
    #define TV_ASST_TRACE(call) d_printf("()()()()()()() %s: ", __func__) ;
  #else
    #define TV_ASST_TRACE(call) 
  #endif
#else
  #define TV_ASST_TRACE(call) 
#endif

#ifdef	__cplusplus
}  /* extern "C" */
#endif

#endif /* Idempotence */


