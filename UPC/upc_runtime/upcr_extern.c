/*
 * UPC runtime functions for external C/C++/MPI code
 *
 * Jason Duell <jcduell@lbl.gov>
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_extern.c $
 *
 */

#include <upcr_internal.h>

static void 
upcri_too_early(const char *func)
{
    fflush(stdout);
    /* NOTE: the test harness scans for "UPC Runtime error:" */
    fprintf(stderr, 
	    "UPC Runtime error: %s called before UPC runtime initialized\n", 
	    func);
    fflush(stderr);

    exit(-1);
}

/* Error if called too soon */
#if UPCR_DEBUG
  #define UPCRI_DIE_IF_TOO_EARLY(func)  \
   if (upcri_startup_lvl == upcri_startup_init)	\
       upcri_too_early(func);
#else
  #define UPCRI_DIE_IF_TOO_EARLY(func)  
#endif

int bupc_extern_mythread()
{
    UPCR_BEGIN_FUNCTION();
    UPCRI_DIE_IF_TOO_EARLY("bupc_extern_mythread");
    return (int) upcr_mythread();
}

int bupc_extern_threads()
{
    UPCR_BEGIN_FUNCTION();
    UPCRI_DIE_IF_TOO_EARLY("bupc_extern_threads");
    return (int) upcr_threads();
}

char * bupc_extern_getenv(const char *env_name)
{
    UPCR_BEGIN_FUNCTION();
    UPCRI_DIE_IF_TOO_EARLY("bupc_extern_getenv");
    return upcr_getenv(env_name);
}

void bupc_extern_notify(int barrier_id)
{
    UPCR_BEGIN_FUNCTION();
    UPCRI_DIE_IF_TOO_EARLY("bupc_extern_notify");
    upcr_notify(barrier_id, 0);
}

void bupc_extern_wait(int barrier_id)
{
    UPCR_BEGIN_FUNCTION();
    UPCRI_DIE_IF_TOO_EARLY("bupc_extern_wait");
    upcr_wait(barrier_id, 0);
}

void bupc_extern_barrier(int barrier_id)
{
    UPCR_BEGIN_FUNCTION();
    UPCRI_DIE_IF_TOO_EARLY("bupc_extern_barrier");
    upcr_notify(barrier_id, 0);
    upcr_wait(barrier_id, 0);
}

void * bupc_extern_alloc(size_t bytes)
{
    UPCR_BEGIN_FUNCTION();
    upcr_shared_ptr_t sptr;
    UPCRI_DIE_IF_TOO_EARLY("bupc_extern_alloc");
    sptr = upcr_alloc(bytes);
    if (upcr_isnull_shared(sptr))
	return NULL;
    return upcr_shared_to_local(sptr);
}

void * bupc_extern_all_alloc(size_t nblocks, size_t blocksz)
{
    UPCR_BEGIN_FUNCTION();
    upcr_shared_ptr_t sptr;
    UPCRI_DIE_IF_TOO_EARLY("bupc_extern_all_alloc");
    sptr = upcr_all_alloc(nblocks, blocksz);
    if (upcr_isnull_shared(sptr))
	return NULL;
    /* Performs equivalent of "(void *)sptr[MYTHREAD]", 
     * but w/o pointer arithmetic */
    return upcri_shared_remote_to_mylocal(sptr);
}


void bupc_extern_free(void *ptr, int thread)
{
    UPCR_BEGIN_FUNCTION();
    UPCRI_DIE_IF_TOO_EARLY("bupc_extern_free");
    if (ptr == NULL)
	return;
    upcr_free(_bupc_local_to_shared(ptr, thread, 0));
}

void bupc_extern_all_free(void *ptr, int thread)
{
    UPCR_BEGIN_FUNCTION();
    UPCRI_DIE_IF_TOO_EARLY("bupc_extern_all_free");
    if (ptr == NULL)
	return;
    upcr_all_free(_bupc_local_to_shared(ptr, thread, 0));
}

