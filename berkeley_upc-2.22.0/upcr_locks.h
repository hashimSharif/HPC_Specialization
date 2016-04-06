
/*
 * UPC lock functions
 */

#ifndef UPCR_LOCKS_H
#define UPCR_LOCKS_H

#if UPCR_DEBUG
#  define UPCR_LOCK_DEBUG 1
#endif

#define upcri_locksystem_init() \
       _upcri_locksystem_init(UPCRI_PT_PASS_ALONE)
extern void _upcri_locksystem_init(UPCRI_PT_ARG_ALONE);

/*
 * UPC locks
 * =========
 * The following implements UPC locks as specified in language spec
 * version 1.1. This notably differs from the UPC spec 1.0 for upc locks, 
 * specifically in the following ways:
 *   - upc_lock_t is an opaque shared datatype with incomplete type (prohibits
 *     statically-allocated upc_lock_t objects)
 *   - upc_lock_init() is no longer necessary or useful and is removed
 *   - upc_lock_free() is added to allow users to free dynamically-allocated locks
 *   - UPC locks are _not_ recursive (a thread must not attempt to re-acquire a
 *     lock it already owns)
 *
 * In Oct 2011:
 *   - upc_all_lock_free() is added
 *
 * Similar to upc_lock_t, the runtime lock datatype is totally opaque and
 * always manipulated through upcr_shared_ptr_t pointers, which must NEVER be
 * dereferenced by generated code.
 *
 * This spec intentionally doesn't even provide a name or size for the lock
 * datatype the shared pointer returned by the lock allocation routines has
 * reference semantics, (i.e. copying the pointer yields a reference to the
 * same lock) but otherwise need not even be a real pointer. In other words,
 * the thread affinity and addrfield components of these shared pointers is
 * completely undefined, so casting them to a local pointer on _any_ thread
 * may yield a pointer value which doesn't point to a valid memory address (or
 * points to a random object) this allows implementations which (for example)
 * store an integer lock identifier in the address field rather than a true
 * pointer.
 */

/* Non-collective operation (intended to be called by a single thread) which
 * dynamically allocates and initializes a lock, and returns a
 * upcr_shared_ptr_t which references that lock.
 *
 * If insufficient resources are available, the function will print an
 * implementation-defined error message and terminate the job.
 */
#define upcr_global_lock_alloc() \
       (upcri_srcpos(), _upcr_global_lock_alloc(UPCRI_PT_PASS_ALONE))

upcr_shared_ptr_t _upcr_global_lock_alloc(UPCRI_PT_ARG_ALONE);

/* Collective operation which dynamically allocates and initializes a lock,
 * and returns a upcr_shared_ptr_t which references that lock.
 *   
 *   - The function must be called by all threads during the same
 *     synchronization phase, 
 *   - May act as a barrier for all threads, but might not in some
 *     implementations
 *   - All threads receive a copy of the result, and the shared pointer values
 *     will compare equal (according to upcr_isequal_shared_shared()) on all
 *     threads
 *
 * If insufficient resources are available, the function will print an
 * implementation-defined error message and terminate the job.
 */
#define upcr_all_lock_alloc() \
       (upcri_srcpos(), _upcr_all_lock_alloc(UPCRI_PT_PASS_ALONE))

upcr_shared_ptr_t _upcr_all_lock_alloc(UPCRI_PT_ARG_ALONE);

/* Block until the referenced lock can be acquired by this thread.
 *
 * If no other thread is currently holding or contending for the referenced
 * lock, this operation must return within a bounded amount of time
 *
 * Implementations should attempt to provide fairness in the presence of
 * contention for this lock, but this property is not required
 *
 * If lockptr does not reference a valid lock object (i.e. one previously
 * allocated by upcr_global_lock_alloc() or upcr_all_lock_alloc() and not
 * deallocated using upcr_lock_free()) then the results are undefined
 *
 * If the current thread is already holding the referenced lock, the result is
 * undefined (although implementations are recommended to print a useful error
 * message and abort)
 */
#define upcr_lock(lockptr) \
       (upcri_srcpos(), _upcr_lock(lockptr UPCRI_PT_PASS))

void _upcr_lock(upcr_shared_ptr_t lockptr UPCRI_PT_ARG);

/* Attempt to acquire the referenced lock without blocking.
 *
 * The operation always returns immediately, with the value 1 if the lock was
 * successfully acquired, or with the value 0 if the lock could not be
 * acquired at this time.
 *
 * If no other thread is currently holding or contending for the referenced
 * lock, repeated calls to this operation will eventually succeed within a
 * bounded amount of time.
 *
 * If lockptr does not reference a valid lock object then the results are
 * undefined if the current thread is already holding the referenced lock, the
 * result is undefined (although implementations are encouraged to print a
 * useful error message and abort).
 */
#define upcr_lock_attempt(lockptr) \
       (upcri_srcpos(), _upcr_lock_attempt(lockptr UPCRI_PT_PASS))

int _upcr_lock_attempt(upcr_shared_ptr_t lockptr UPCRI_PT_ARG);

/* Unlock the referenced lock. 
 *
 * This operation releases the referenced lock, which must have been
 * previously locked by this thread using upcr_lock(), or a successful call to
 * upcr_lock_attempt() (otherwise the results are undefined).
 *
 * If lockptr does not reference a valid lock object then the results are
 * undefined.
 *
 * This operation always completes within a bounded amount of time
 * implementations are encouraged to detect violations to the locking
 * semantics (e.g. unlock with no matching lock) but this is not required.
 */
#define upcr_unlock(lockptr) \
       (upcri_srcpos(), _upcr_unlock(lockptr UPCRI_PT_PASS))

void _upcr_unlock(upcr_shared_ptr_t lockptr UPCRI_PT_ARG);

/* Free a lock - non-collective operation.
 *
 * This call (always made from a single thread) releases any system resources
 * associated with the referenced lock and makes the lock object "invalid" for
 * all threads.
 *
 * The lock need not have been explicitly created by the current thread (i.e.
 * it may have been created by a call to upcr_global_lock_alloc() on a
 * separate thread and passed to this one).
 *
 * Any subsequent calls from any thread using this invalidated lock object
 * have undefined effects.  If lockptr does not reference a valid lock object
 * then the results are undefined.
 *
 * This operation always completes within a bounded amount of time.
 *
 * Repeated calls to upcr_lock_free(upcr_global_lock_alloc()) must succeed
 * indefinitely (i.e. it must actually reclaim any associated resources).
 *
 * The call will succeed immediately regardless of whether the referenced lock
 * is currently unlocked or currently locked (by any thread).
 */
#define upcr_lock_free(lockptr) \
       (upcri_srcpos(), _upcr_lock_free(lockptr UPCRI_PT_PASS))

void _upcr_lock_free(upcr_shared_ptr_t lockptr UPCRI_PT_ARG);

/* Free a lock - collective operation.
 */
#define upcr_all_lock_free(lockptr) \
       (upcri_srcpos(), _upcr_all_lock_free(lockptr UPCRI_PT_PASS))

void _upcr_all_lock_free(upcr_shared_ptr_t lockptr UPCRI_PT_ARG);


/* LEGACY (to be removed at UPC-1.4) ONLY: */
UPCRI_DEPRECATED_STUB(bupc_all_lock_free)
#define bupc_all_lock_free(lockptr) (bupc_all_lock_free (), upcr_all_lock_free(lockptr))

#endif /* UPCR_LOCKS_H */
