/*  upc_extern.h
 *
 *  Header file for C++/C/MPI programs that need to interoperate with UPC
 *  code.
 *
 *  The mechanisms in this header file are not part of the UPC standard, and
 *  are extensions particular to the Berkeley UPC system.  They should be
 *  considered to have 'experimental' status, and may be changed.
 *
 *  $Source: bitbucket.org:berkeleylab/upc-runtime.git/bupc_extern.h $
 */

#ifndef __BUPC_EXTERN_H
#define __BUPC_EXTERN_H

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * Functions for external bootstrapping of the UPC runtime.
 *
 * The 'bupc_init() and 'bupc_init_reentrant()' functions allow 'external'
 * bootstrapping of the UPC runtime, i.e., initialization of the runtime by
 * programs which are not written entirely in UPC, and whose main() does not
 * appear in a UPC file. 
 *****************************************************************************/

/*
 * Public, user-accessible function for bootstrapping the Berkeley UPC runtime
 * from a non-UPC C or C++ program that does not use pthreads. 
 *
 * A call to this function should be the first statement in main(). The
 * semantics of any code appearing before it is implementation-defined (for
 * example, it is undefined how many threads of control will run that code, or
 * whether stdin/stdout/stderr are functional).  The presence of environment
 * variables is also not guaranteed, but after this call returns bupc_getenv()
 * can be used to retrieve them (regular getenv() is not guaranteed to provide
 * them).
 *
 * The addresses of the command-line parameters must be passed, and it is not
 * safe to otherwise refer to them until after this function returns, as it
 * may supplement or modify them.
 *
 * Once bupc_init() has returned, the application may safely call into UPC
 * routines.  All exit paths from the program should call bupc_exit() as
 * their last program statement.  
 *
 * If any errors are encountered during this function's execution, an error
 * message is printed to stderr and the job will be aborted.
 *
 * This call may register UNIX signal handlers.  Client code should not
 * register signal handlers or rely on the correct propagation of signals.
 *
 * This function cannot be used with a pthreaded application.  Use
 * bupc_init_reentrant() instead.
 *
 * This function may be called repeatedly, but only the first invocation will
 * have any effect.
 *
 * If used within a hybrid MPI/UPC program, this function also ensures that
 * MPI_Init() is called, if needed.  MPI_Init() should NOT be called by user
 * code if this function is used.
 */
void bupc_init(int *argc, char ***argv); 

/*
 * A portable version of bupc_init(). A call to the bupc_init_reentrant()
 * function will initialize the Berkeley UPC runtime, regardless of whether
 * pthreads are used or not.
 *
 * In addition to the addresses of the regular main() command-line
 * parameters, this function takes a function pointer.  Calling
 * bupc_init_reentrant() will cause all the pthreads known to the UPC runtime
 * to be launched, and each of them will then call the 'pmain_func()' with
 * their own copy of the command-line parameters.  'pmain_func' may not be
 * NULL.
 *
 * Like with bupc_init(), bupc_exit() should be called at the end of all
 * program exit paths, except for returns from 'pmain_func'.  If
 * 'pmain_func' returns, its return value is used to indicate the exit code
 * of the program, and the UPC runtime will exit correctly without an explicit
 * call to bupc_exit() being required.
 *
 * No meaningful code should follow this function call, as it exits before
 * returning.
 *
 * Within pmain_func(), user code may call into UPC routines.  It is only safe
 * to access UPC routines from the original pthread(s) whose pmain_func() is
 * called, however.  If additional pthreads are launched by the user
 * application, they must not call UPC routines, or behavior is undefined.
 *
 * Within pmain_func, bupc_getenv() can be used to retrieve values of
 * environment variables (regular getenv() is not guranteed to provide them).
 *
 * If any errors are encountered during this function's execution, an error
 * message is printed to stderr and the job will be aborted.
 *
 * This call may register UNIX signal handlers.  Client code should not
 * register signal handlers or rely on the correct propagation of signals.
 *
 * This function may be called repeatedly, but only the first invocation will
 * have any effect.
 *
 * If used within a hybrid MPI/UPC program, this function also ensures that
 * MPI_Init() is called, if needed.  MPI_Init() should NOT be called by user
 * code if this function is used.
 *
 * This function can also be used by UPC compilers to bootstrap a UPC job, if
 * the user's 'main' function is renamed and passed in as the 'pmain_func'
 * parameter.
 */
void bupc_init_reentrant(int *argc, char ***argv, 
			 int (*pmain_func)(int, char **) ); 


/*
 * Runtime shutdown/exit routine.
 *
 * This function should be called as the last program statement by any program
 * that uses bupc_init() to bootstrap the UPC runtime.  It does not need to be
 * used when bupc_init_reentrant() is used.  The 'exitcode' provided will be
 * returned to the console that invoked the job, assuming all of the threads
 * terminate with this function, and use the same exitcode.  If different
 * threads of the program exit with different values, one of the values will
 * be chosen arbitrarily.  The behavior of any program statements after a call
 * to bupc_exit() is undefined.
 *
 * If used within a hybrid MPI/UPC program, bupc_exit() ensures that
 * MPI_Finalize() is called, if needed.  MPI_Finalize should NOT be called
 * by user code if this function is used.
 */
void bupc_exit(int exitcode);

/*****************************************************************************
 * Utility functions for external code that links with UPC routines.
 *
 * These routines could all be written by hand in UPC and called from external
 * C/C++/MPI code, but are provided as a convenience.
 *
 * Usage restrictions:  
 * - These functions cannot be called until either bupc_init() or
 *   bupc_init_reentrant() has been called first.
 *
 * - These functions are equivalent to calling a UPC function, and so if MPI
 *   calls also appear in your code, the usual rules for avoiding deadlock
 *   between UPC and MPI apply:
 *
 *   1) After one or more MPI functions have been called, 'MPI_Barrier()' 
 *      must be performed before the next UPC function call can be made.
 *
 *   2) After one or more UPC functions have been called, 'upc_barrier' or
 *      'bupc_extern_barrier' must be performed before the next MPI function
 *      call can be made.
 *
 * - These functions can only be called within threads launched by the UPC
 *   runtime (i.e., not pthreads that have been launched by other calls to
 *   pthread_create()).
 *****************************************************************************/

/* Returns value of UPC's 'MYTHREAD' */
int bupc_extern_mythread(void);

/* Returns value of UPC's 'THREADS' */
int bupc_extern_threads(void);

/* Retrieves value of an environment variable.  This function should be used
 * instead of getenv(), which is not guaranteed to return correct
 * results. 
 *
 * At present this function is only guaranteed to retrieve the same value
 * for all threads if the environment variable's name begins with 'UPC_' or
 * 'GASNET_'.
 *
 * The 'setenv()' and 'unsetenv' functions are not guaranteed to work in a
 * Berkeley UPC runtime environment, and should be avoided.
 */
char * bupc_extern_getenv(const char *env_name);

/* Equivalent of 'upc_notify barrier_id' */
void bupc_extern_notify(int barrier_id);

/* Equivalent of 'upc_wait barrier_id' */
void bupc_extern_wait(int barrier_id);

/* Equivalent of 'upc_barrier barrier_id' */
void bupc_extern_barrier(int barrier_id);

/******************************************************************************* 
 * UPC shared memory allocation/manipulation functions.
 *
 * The following functions allow non-UPC code to allocate and free UPC shared
 * memory.
 *******************************************************************************/

/* Performs equivalent of
 *
 *	return (void *) upc_alloc(bytes);
 *
 * The value returned from this function can be passed as 'ptr' to UPC code
 * running in the same UPC thread, which can then use
 *
 *	shared <type> *q = bupc_local_to_shared(ptr, MYTHREAD, 0);
 *
 * to recover the original shared pointer returned from upc_alloc.
 */
void * bupc_extern_alloc(size_t bytes);

/* Performs equivalent of
 *
 *	shared char * sptr = (shared char *)upc_all_alloc(nblocks, blocksz);
 *	return (void *) &sptr[MYTHREAD];
 *
 * In other words, a pointer to the start of the calling thread's local
 * portion of the allocation is returned to each thread.  
 *
 * The 'void *' value returned from this function can be passed as 'p' to UPC
 * functions running on the same UPC thread, and then 
 *
 *	shared <type> *q = bupc_local_to_shared(p, 0, 0);
 *
 * can be used to recover the original shared pointer returned from
 * upc_all_alloc (which always points to a location on UPC thread 0, with
 * phase 0).
 *
 * The address 'p' returned from this function is valid ONLY on the thread
 * that received it.  It is NOT safe to directly pass 'p' to another thread,
 * and then have that thread dereference it and/or pass it to UPC code which
 * calls bupc_local_to_shared() on it.  
 *
 * Note that if 'nblocks' is less than the number of UPC threads running, some
 * threads will not actually be allocated any memory.  They will nevertheless
 * receive the same non-NULL local pointer (equivalent to '&sptr[MYTHREAD]')
 * as if nblocks >= MYTHREADS.   In this case, the pointer 'p' returned by
 * this function is not safe to dereference, but UPC code running on the same
 * thread can still use bupc_local_to_shared(p, 0, 0) to recover the original
 * shared pointer 'sptr'.
 */
void * bupc_extern_all_alloc(size_t nblocks, size_t blocksz);


/* C interface to 'upc_free'.
 *
 * 'ptr': value returned from bupc_extern_alloc() or bupc_extern_all_alloc().
 *
 * 'thread': For memory allocated with bupc_extern_alloc(), pass the number of 
 *	     the thread that made the call.  For memory allocated with
 *	     bupc_extern_all_alloc(), pass 0.
 *
 * Note that each allocation call must be balanced by (no more than) one
 * call to bupc_extern_free().  So, while all threads collectively call
 * bupc_extern_all_alloc(), only a single thread must call bupc_extern_free().
 */
void bupc_extern_free(void *ptr, int thread);

/* C interface to 'upc_all_free'.
 *
 * 'ptr': value returned from bupc_extern_alloc() or bupc_extern_all_alloc().
 *
 * 'thread': For memory allocated with bupc_extern_alloc(), pass the number of 
 *	     the thread that made the call.  For memory allocated with
 *	     bupc_extern_all_alloc(), pass 0.
 *
 * Unlike bupc_extern_free(), this is a collective call and should be called
 * concurrently by all threads with identical arguments.
 */
void bupc_extern_all_free(void *ptr, int thread);


#ifdef __cplusplus
}
#endif

#endif /* __BUPC_EXTERN_H */
