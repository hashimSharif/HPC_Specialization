/*
 * UPC Runtime startup (and exit) functions
 *
 * Jason Duell <jcduell@lbl.gov>
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_init.h $
 */

#ifndef UPCR_INIT_H
#define UPCR_INIT_H

GASNETT_BEGIN_EXTERNC

/*****************************************************************************
 * Runtime initialization functions.
 *
 * There are two sets of initialization functions for the Berkeley UPC
 * runtime:  one low-level set targeted at compiler developers, who want the
 * largest amount of control over behavior, and one 'simpler' interface,
 * targeted at application/library developers who wish to use UPC within a
 * larger, non-UPC C/C++ program (though it can also be used by UPC
 * compilers).  The simpler interface (bupc_init() and bupc_init_reentrant())
 * uses the lower-level API, plus a set of 'magic' global variables provided
 * by the UPC linker, to provide the full set of information needed, while the
 * low-level API takes all needed information in the function parameters.  The
 * bupc_init functions are described in the 'upc_extern.h' header file.
 */


 /*****************************************************************************
 * Low-level API: 
 *
 * If used, the low-level initialization functions must be called in the
 * following order:
 *
 *	upcr_startup_init()
 *	upcr_startup_attach()
 *	upcr_startup_spawn()
 *	upcr_exit()		// not always needed: see description
 */

/*
 * Bootstraps a UPC job and performs any system-specific setup required.
 *
 * Called by all applications that use the UPC runtime at startup to bootstrap
 * the job before any other processing takes place.  Must be called before
 * any calls to any other functions in this specification, with the
 * command-line parameters passed to main (argc/argv), which may be modified
 * or augmented by this call (and are thus not safe to use before this call).
 * The semantics of any code executing before the call to
 * `upcr_startup_init()' is implementation-specific (for example, it is
 * undefined whether `stdin/stdout/stderr' are functional, or even how many
 * nodes will run that code).
 *
 * If the application using the runtime requires that it be run with a
 * fixed number of UPC threads, pass the thread count in the
 * 'static_threadcnt' parameter, and the program will abort with a error
 * message if the provided value does not match the execution environment that
 * will be provided.  Pass <= 0 for applications that can run with a dynamic
 * number of UPC threads.  If pthreads are used, a positive integer must be
 * supplied for 'default_pthreads_per_proc';  otherwise, pass 0.
 *
 * The 'main_name' parameter should be passed the name of the user's main()
 * UPC function: it is used to help users find that symbol name when debugging.
 * You may pass NULL if this is not needed.
 *
 * Upon return from `upcr_startup_init()', all the nodes of the job will be
 * running, stdout/stderr will be functional, and the basic job environment
 * will be established, however the primary network resources may not yet have
 * been initialized.  The following runtime functions are the only ones that
 * may be called between `upcr_startup_init()' and `upcr_startup_attach()':
 *
 *         `upcr_mynode()'
 *         `upcr_nodes()'
 *         `gasnet_getMaxLocalSegmentSize()'
 *         `gasnet_getMaxGlobalSegmentSize()'
 *         `upcr_getenv()'
 *         `upcr_global_exit()'
 *
 * All other runtime calls are prohibited until after a successful
 * `upcr_startup_attach()'.
 *
 * `upcr_startup_init()' may fail with a fatal error and
 * implementation-defined message if the nodes of the job cannot be
 * successfully bootstrapped.
 *
 * This function may be called repeatedly, but only the first invocation will
 * have any effect.
 */
void upcr_startup_init(int *pargc, char ***pargv, 
		       upcr_thread_t static_threadcnt, 
		       upcr_thread_t default_pthreads_per_proc, 
		       const char * main_name);


#define UPCR_ATTACH_ENV_OVERRIDE	1
#define UPCR_ATTACH_REQUIRE_SIZE	2
#define UPCR_ATTACH_SIZE_WARN		4

/*
 * Initializes the UPC runtime's network system, including shared memory
 * regions.  This function must be called after upcr_startup_init(), but
 * before any of the other upcr_startup_ functions.
 *
 * The 'default_shared_size' parameter gives the default size to request for
 * each UPC thread's shared memory region.  
 *
 * The 'default_shared_offset' parameter specifies the minimum distance (in
 * bytes) to provide between the current end of the regular C heap (commonly
 * provided by sbrk(0)) and the beginning of the shared memory region.  On
 * some platforms this offset becomes the growth limit for the regular C heap
 * (and thus determines how much more memory malloc(), calloc(), etc. can
 * return before failing).  On most systems, it is irrelevant, and 0 should be
 * passed, since using a large offset may limit the size of the shared memory
 * region.
 *
 * Values for 'default_shared_size' and 'default_shared_offset' must be
 * multiples of UPCR_PAGESIZE.  Both parameters may each be overridden at run
 * time if the 'flags' parameter allows it (see below).  
 * 
 * The size and address of the shared region that is created for each node in
 * the application can be determined after this call with the
 * gasnet_getSegmentInfo() function.  The size of the shared segment is
 * guaranteed to be be no larger than the requested size times the number of
 * pthreads on the node (with pthreads==1 if pthreads are not being used).
 * The region can be smaller than the requested amount, unless
 * UPCR_ATTACH_REQUIRE_SIZE is passed in the 'flags' parameter or the
 * UPC_REQUIRE_SHARED_SIZE environment variable is set to a nonempty value.  
 *
 * The 'flags' parameter can contain one or more of the following values (OR
 * them together if multiple flags are used):
 *   
 *   UPCR_ATTACH_ENV_OVERRIDE
 *      - if passed, the function checks the process' environment for 
 *        UPC_SHARED_HEAP_SIZE and/or UPC_SHARED_HEAP_OFFSET.  If these are
 *        set to valid values (a number immediately followed by a 'MB' or
 *        'GB', for example '32MB' for 32 megabytes, or '4GB' for 4
 *        gigabytes), they override the default_shared_size and
 *        default_shared_offset values, respectively.
 *
 *   UPCR_ATTACH_REQUIRE_SIZE
 *      - if this flag is passed, the function will die with an error message
 *        printed to stderr if the allocated shared region on any node is
 *        smaller than the amount that was asked for times the number of
 *        pthreads.  Can be overridden at startup by setting the
 *        UPC_REQUIRE_SHARED_SIZE environment variable to 'yes' or 'no'.
 *
 *   UPCR_ATTACH_SIZE_WARN
 *	- if this flag is passed, the runtime will issue a warning to stderr
 *	  if a smaller shared memory segment than requested will be used.
 *	  Can be overridden at startup by setting the UPC_SIZE_WARN
 *	  environment variable to 'yes' or 'no'.
 *
 * If any errors are encountered during upcr_startup_attach, an error message
 * is printed and the job is aborted.
 */

void upcr_startup_attach(uintptr_t default_shared_size, 
			 uintptr_t default_shared_offset, 
			 int flags);

/*
 * Struct argument to upcr_startup_spawn.
 */
struct upcr_startup_spawnfuncs {
    void (*pre_spawn_init)(void);
    void (*per_pthread_init)(void);
    void (*cache_init)(void *start, uintptr_t len);
    void (*heap_init)(void * start, uintptr_t len);
    void (*static_init)(void *start, uintptr_t len);
    int  (*main_function)(int argc, char **argv);
};

/*
 * Completes runtime initialization, including launching of any additional
 * pthreads (if a pthreaded runtime is used), and running of the user's main()
 * function (if any).
 *
 * '*pargc' and '*pargv' are passed to the 'main_function' in the 'spawnfuncs'
 * argument (if it is non-NULL).  The 'static_data_size' parameter should have
 * a nonzero value if and only if static shared data get their own section of
 * the shared memory segment, separate from the shared heaps (in Berkeley upc
 * static data are allocated off of the heap; GCCUPC uses a separate segment),
 * and this should be the size of the static data for each UPC thread.  The
 * 'default_cache_size' indicates how much shared memory to reserve for
 * caching, by default:  since caching is not yet implemented, pass 0.
 *
 * The 'spawnfuncs' parameter is a struct containing pointers to six
 * functions.
 *
 * The 'pre_spawn_init' function, if not NULL, is called first, before any
 * pthreads are launched.  It can contain any arbitrary initializations that
 * should happen only once per-process.
 *
 * Each of the remaining function pointers is called once on each UPC thread.  
 *
 * The 'per_pthread_init' function, if not NULL, is called by each pthread,
 * and can contain arbitrary initializations that need to happen on a
 * per-pthread basis.
 *
 * The 'cache_init' function is called next, but only if caching is being
 * used (i.e. if UPCR_USING_CACHING is defined).  It may be set to NULL
 * otherwise.  It must initialize the cache within the given region.  
 *
 * The 'heap_init' function is called next, and must initialize the runtime
 * shared heaps.  It takes parameters indicating the starting address and
 * length of the region to use for the heap.  
 *
 * The 'static_init' function is then called.  It must set up all static data
 * for the UPC thread, and takes the address and length of the segment to be
 * used (with the length guaranteed to be at least as large as provided in the
 * 'static_data_size' parameter).  
 *
 * Next, a barrier is performed.  Finally, if the 'main_function' parameter is
 * NULL, the function returns (and upcr_exit() should be used for any program
 * exit path, including the end of 'main').  Otherwise 'main_function' is
 * called with the command line arguments passed in 'argv' and 'argc' (with a
 * new copy made for each pthread if pthreads are used).  Again, upcr_exit()
 * should be used for any exit paths, except that returns from 'main_function'
 * are handled automatically, with the return value used as the program's exit
 * code.
 *
 * If any errors occur during this function, an error message is printed to
 * stderr and the job is terminated.
 *
 */
void upcr_startup_spawn(int *pargc, char ***pargv, 
			uintptr_t static_data_size, 
			uintptr_t default_cache_size, 
			struct upcr_startup_spawnfuncs *spawnfuncs);


/* Runtime shutdown/exit function.
 *
 * This function should be called as the last program statement for all exit
 * paths from a UPC application, with the single exception that the
 * 'main_function' used by upcr_startup_spawn() may simply return an integer,
 * in which case the behavior is the same as if a call to this function had
 * been made with that value.
 *
 * The behavior of any code called after this function is undefined (i.e. it
 * may not execute).
 */
void upcr_exit(int exitcode) GASNETT_NORETURN;
GASNETT_NORETURNP(upcr_exit)


/*
 * "Magic" variables that must appear in the linked executable to support use
 * of the bupc_init() and/or bupc_init_reentrant() functions. 
 *
 * Definitions of all variables with the 'UPCRL_' prefix must be provided by
 * client code.  NULL/zero values can be used if system does not support
 * creating executables that call UPC functions from within a non-UPC C or C++
 * program.  
 */

/* Set to 0 if dynamic threads used, else to the static UPC thread count */
extern upcr_thread_t	UPCRL_static_thread_count; 

/* Default size of shared memory segment and offset */
extern uintptr_t	UPCRL_default_shared_size;
extern uintptr_t	UPCRL_default_shared_offset;

/* Support for systems which store shared variables in a separate linker
 * section. 
 *
 * Some systems (ex: GCC UPC) convert 'shared' static data into a separate
 * linker section.  In this case, the values stored in shared pointers are
 * within that linker section (since they are assigned by the linker).  
 *
 * To work with Berkeley UPC, the linker section must be mapped into a portion
 * of the shared region provided by gasnet.  Also, if pthreads are used, a
 * separate copy of the linker section must exist for each pthread.   
 *
 * These requirements are handled by the runtime so long as
 * UPCR_USING_LINKADDRS is defined, and the beginning/ending addresses of the
 * linker section are provided in 'UPCRL_shared_begin' and 'UPCRL_shared_end'.
 * The runtime uses these addresses to make a copy for each pthread of the
 * linker section.  Then, during each shared <=> local address conversion, an
 * offset is used to convert between the linker-assigned address for a given
 * shared pointer and its the address within a pthread's copy of the static
 * data region.
 * 
 * On ELF-based systems, the beginning and ending addresses are typically
 * provided by arranging for the UPCRL_shared_begin/end to be the first and
 * last variables in the linker section that the linker sees (on most linker
 * this can be achieved by putting the symbols in separate 'first.o' and
 * 'last.o' object files that are then passed to the linker as the first and
 * last objects on the linker command line).
 */
#if UPCRI_USING_GCCUPC || UPCRI_USING_CUPC
  #define UPCRL_shared_begin __upc_shared_start
  #define UPCRL_shared_end __upc_shared_end
#endif
#if UPCRI_HAVE_LINKER_SECTION
  extern char UPCRL_shared_begin[0x10000];
  extern char UPCRL_shared_end[1];
#endif

/* Nonzero to launch an extra progress thread.  Primarily useful for parallel
 * debugger support.  Redundant on some networks, and likely to slow down
 * performance on the others */
extern int              UPCRL_progress_thread;

/* Default size of runtime cache, if used. */
extern uintptr_t	UPCRL_default_cache_size;

/* default flags to pass to upcr_attach, if upcr_startup_init() is used to
 * bootstrap the runtime */
extern int		UPCRL_attach_flags;

/* default pthreads per process: pass 0 if not using pthreads */
extern upcr_thread_t	UPCRL_default_pthreads_per_node;

/* Name used to rename user's main() function
 * - optional: may be set to null. */
extern const char *	UPCRL_main_name;

/* Hook for arbitrary per-process initializations */
extern void	      (*UPCRL_pre_spawn_init)(void);

/* Hook for arbitrary per-pthread initializations */
extern void	      (*UPCRL_per_pthread_init)(void);

/* Heap initialization function to pass to upcr_startup_attach() */
extern void (*UPCRL_heap_init)(void * start, uintptr_t len);

/* Static data initialization function to pass to upcr_startup_attach() */
extern void (*UPCRL_static_init)(void *start, uintptr_t len);

/* Cache initialization function to pass to upcr_startup_attach() */
extern void (*UPCRL_cache_init)(void *start, uintptr_t len);

/* Function to ensure MPI has been initialized.  Use only if both MPI and a
 * gasnet conduit are being used, else set to NULL. This function must not
 * call MPI_Init is it has already been called by gasnet (use
 * MPI_Initialized() to check).  No other code in the application should call
 * MPI_Init(), else behavior is undefined. */
extern void (*UPCRL_mpi_init)(int *pargc, char ***pargv);

/* Function to ensure MPI is shut down at program completion. Use only if both
 * MPI and a gasnet conduit are being used, else set to NULL.  MPI_Finalize
 * should only be called if the UPCRL_mpi_init function called
 * MPI_Initialize().  No other code in the application should call
 * MPI_Finalize(), else behavior is undefined. */
extern void (*UPCRL_mpi_finalize)(void);

/* Function to be called by all nodes during a collective exit to ensure
 * profiling system is correctly finalized, else set to NULL. */
extern void (*UPCRL_profile_finalize)(void);

/* Terminate the current job with a given exit code: non-collective operation.
 * This function may be called by any thread at any time after initialization
 * and will cause the system to flush all I/O, release all resources and
 * terminate the job for all active threads.
 *
 * This function is called automatically by the runtime system in the event of
 * any fatal error or catchable terminate-the-program signals (e.g. segmentation
 * fault).
 *
 * This function must be called at the end of main() after a barrier to ensure
 * proper system exit. The console which initiated the current job will receive
 * the provided exitcode as a program return value in a system-specific way.
 * If more than one thread calls upcr_global_exit() within a given
 * synchronization phase with different exitcode values, the value returned to
 * the console will be one of the provided exit codes (chosen arbitrarily).
 *
 * Implementation notes:
 *   gasnet may send a fatal signal to indicate a remote node exited or crashed
 *   calls gasnet_exit to terminate the job on remote nodes
*/
void upcr_global_exit(int exitcode) GASNETT_NORETURN;
GASNETT_NORETURNP(upcr_global_exit)

/*
 *  Called at normal system exit time (end of main, or exit() called).
 *  Does final barrier, to ensure that this thread's shared memory doesn't go
 *  away before other threads are done using it.
 */
void upcri_do_exit(int exitval) GASNETT_NORETURN;
GASNETT_NORETURNP(upcri_do_exit)

/* 
 * Startup helper functions
 * ========================
 *
 * These functions are used by compiler-generated code to allocate and
 * initializate users' static shared data dynamically at startup.
 */


/* 
 * Allocation information struct for shared arrays that will be striped across
 * the UPC threads (with blocking size != 1 element): 
 *
 *  sptr_addr       The address of the proxy upcr_shared_ptr_t for the memory
 *  blockbytes      Size of each block in bytes
 *  numblocks       Number of blocks to allocate
 *  mult_by_threads Pass nonzero if numblocks should be multiplied by THREADS
 *
 *  Optional elements, used for instrumentation purposes only: (zero values permitted)
 *
 *  elemsz          Value of upc_elemsizeof for this object
 *  namestr         Shared object identifier name
 *  typestr         String encoding of type information for shared object
 *
 */
typedef struct upcr_startup_shalloc_S {
   upcr_shared_ptr_t *sptr_addr;
   size_t blockbytes;
   size_t numblocks;
   int    mult_by_threads;
   size_t elemsz;
   const char *namestr;
   const char *typestr;
} upcr_startup_shalloc_t;

/* 
 * Allocation information struct for indefinitely blocked (or blocksize == 1
 * element) shared arrays.
 *
 *  psptr_addr      The address of the proxy upcr_pshared_ptr_t for the memory
 *  blockbytes      Size of each block in bytes
 *  numblocks       Number of blocks to allocate
 *  mult_by_threads Pass nonzero if numblocks should be multiplied by THREADS
 *
 *  Optional elements, used for instrumentation purposes only: (zero values permitted)
 *
 *  elemsz          Value of upc_elemsizeof for this object
 *  namestr         Shared object identifier name
 *  typestr         String encoding of type information for shared object
 *
 */
typedef struct upcr_startup_pshalloc_S {
   upcr_pshared_ptr_t *psptr_addr;
   size_t blockbytes;
   size_t numblocks;
   int    mult_by_threads;
   size_t elemsz;
   const char *namestr;
   const char *typestr;
} upcr_startup_pshalloc_t;

/*
 * Allocates the specified amount of memory for each shared pointer in the
 * array of info structs.
 *
 * Only performs a given allocation if the memory has not already been allocated
 * for the pointer.  If the pointer was not initialized (i.e., is equal to 0
 * instead of UPCR_INITIALIZED_SHARED), any memory allocated is also memset
 * to 0.
 *
 * This function must be called by all threads collectively (like
 * upc_all_alloc, etc.).  The function does not guarantee that all threads
 * will have received the data when any particular thread
 * returns from the call (i.e. it does not guarantee a barrier is performed
 * after initialization).  The function does guarantee that it may be called
 * repeatedly without the need for client barrier calls to be placed in
 * between the calls. 
 *
 * See the upcr_startup_shalloc_t struct definition for options affecting how
 * memory is allocated.
 */
#define upcr_startup_shalloc(infos, count) \
       _upcr_startup_shalloc(infos, count UPCRI_PT_PASS)

void _upcr_startup_shalloc(upcr_startup_shalloc_t *infos, 
			   size_t count UPCRI_PT_ARG);

/*
 * Allocates the specified amount of memory for each phaseless shared pointer
 * in the array of info structs.
 *
 * Only performs a given allocation if the memory has not already been allocated
 * for the pointer.  If the pointer was not initialized (i.e., is equal to 0
 * instead of UPCR_INITIALIZED_PSHARED), any memory allocated is also memset
 * to 0.
 *
 * This function must be called by all threads collectively (like
 * upc_all_alloc, etc.).  When the function returns, the shared pointers
 * pointed to by 'infos' will be initialized to the correct shared memory
 * location on all UPC threads.
 *
 * See the upcr_startup_shalloc_t struct definition for options affecting how
 * memory is allocated.
 */
#define upcr_startup_pshalloc(infos, count) \
       _upcr_startup_pshalloc(infos, count UPCRI_PT_PASS)

void _upcr_startup_pshalloc(upcr_startup_pshalloc_t *infos, 
			    size_t count UPCRI_PT_ARG);


/*
 * Information for a single dimension of a shared array initialization.
 *
 *	local_elems	    // Number of elements in local init array's dimension
 *	shared_elems	    // Number of elements in shared array's dimension
 *	mult_by_threads	    // Nonzero if shared array's dimension should be 
 *			         multipled by THREADS
 *
 * Note that the UPC language specification mandates that for a dynamic
 * translation environment (i.e. one in which THREADS is not a compile-time
 * constant) only one dimension of a shared array can contain THREADS, and it
 * can only be used once in that dimension, to multiply a constant size.
 */

typedef struct upcr_startup_arrayinit_diminfo {
    size_t local_elems;
    size_t shared_elems;
    int	   mult_by_threads;
} upcr_startup_arrayinit_diminfo_t;

/*
 * Initializes a shared array from a local array, or to 0s if NULL is passed
 * for the local array.
 *
 * This function is used to copy initial values from a local array (generated
 * by the UPC compiler) that contains any initial values provided by the user.
 * The local array does not need to have the same size as the shared array
 * (indeed, if the shared array contains THREADS in one of its dimensions, its
 * size is not even knowable at compile time).  It does, however, need to have
 * the same number of dimensions as the shared array, and the same element
 * size.  All values in the shared array that do not have corresponding values
 * in the local array are memset to 0.
 *
 * The function takes the addresses of the shared and local arrays, a pointer
 * to an array of structures (each of which describes a single dimension of
 * the array), a count of the number of dimensions in the array, the size (in
 * bytes) of the array's element type, and the blocking factor of the array
 * (as a number of elements).
 *
 * If NULL is passed for the local array address, all local array parameters
 * will be ignored, and the function will simply set all elements of the
 * shared array to 0. 
 *
 * Here is an example:
 *
 *  // in UPC program
 *
 *  shared [5] int j[3][4][2*THREADS] = {
 *      {
 *          { 1, 2 },
 *          { 3, 4 },
 *          { 5, 6 },
 *          { 1, 2, 3, 4, 5 }	// the user may specify extra elems if THREADS 
 *				// is part of the dimension
 *      }
 *  };
 *
 * Here the user has only provided a small subset of the inital values in the
 * array (even disregarding the THREADS in the final dimension).  The UPC
 * compiler should place the initial values into a [1][4][5] array, and then
 * setup and call the initialization function:
 *
 *  // output .c file, at file scope  
 *
 *  upcr_shared_ptr_t j = UPCR_INITIALIZED_SHARED;
 *
 *  int j_initarray[1][4][5] = {
 *      {
 *          { 1, 2 },
 *          { 3, 4 },
 *          { 5, 6 },
 *          { 1, 2, 3, 4, 5 }	
 *      }
 *  };
 *
 *  upcr_startup_arrayinit_diminfo_t j_diminfos[] = {
 *      { 1, 3, 0 },
 *      { 4, 4, 0 },
 *      { 5, 2, 1 }
 *  };
 *
 *  // In initialization function  
 *
 *  upcr_startup_initarray(&j, j_initarray, j_diminfos, 3, sizeof(int), 5);
 *
 * This function must be called collectively by each UPC thread for each
 * array, in the same order and with the same arguments.  The function does
 * NOT guarantee that all threads will have completed their initializations
 * when any particular thread returns from the call (i.e. it does not
 * guarantee a barrier is performed after initialization).
 *
 * Implementation notes:
 * --------------------
 *
 * For efficiency, each thread should only copy elements that belong to its
 * portion of the shared array, so the function should not cause any network
 * traffic.  
 *
 * To save space, the local array's dimensions should only be as large
 * as needed to contain all the initial values specified by the user.  
 */
#define upcr_startup_initarray(dst, src, diminfos, dimcnt, elembytes, blockelems) \
	_upcr_startup_initarray(dst, src, diminfos, dimcnt, elembytes, blockelems UPCRI_PT_PASS)

void _upcr_startup_initarray(upcr_shared_ptr_t dst, void * src, 
		            upcr_startup_arrayinit_diminfo_t *diminfos, 
			    size_t dimcnt, size_t elembytes, size_t blockelems UPCRI_PT_ARG);

/*
 * Initializes a phaseless array from a local array, or to 0s if NULL passed.
 *
 * This function is identical to upcr_startup_initarray, except that it takes a
 * phaseless shared ptr.
 *
 * For phaseless shared arrays with indefinite blocksize, pass '0' for the
 * 'blockelems' parameter.
 *
 * Implementor's note:  It should be possible to simply write this as an
 *			inline function that calls upcr_startup_initarray(),
 *			with upcr_pshared_to_shared() used to convert dst to
 *			the correct type.
 */
#define upcr_startup_initparray(dst, src, diminfos, dimcnt, elembytes, blockelems) \
	_upcr_startup_initparray(dst, src, diminfos, dimcnt, elembytes, blockelems UPCRI_PT_PASS)

void _upcr_startup_initparray(upcr_pshared_ptr_t dst, void * src, 
			    upcr_startup_arrayinit_diminfo_t *diminfos, 
			    size_t dimcnt, size_t elembytes, size_t blockelems UPCRI_PT_ARG);


GASNETT_END_EXTERNC

#endif /* UPCR_INIT_H */

