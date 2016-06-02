/*
 * Broadcast function for collective allocations and a few other startup tasks.
 */

#include <upcr_internal.h>

GASNETT_THREADKEY_DEFINE(_upcri_broadcast_key);

/* Broadcasts data from one UPC thread to all others.
 *
 * Does not guarantee that all threads have received the data when any one of
 * them returns from this function--use a barrier after the function if you
 * need that (like UPC's MY/MY or MPI).
 *
 */
void 
_upcri_broadcast(upcr_thread_t from_thread, void *addr, size_t len UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
#if 1
    /* Work around a behavior in which root thread just sends AMs to others
       so fast that they expend unreasonable amounts of memory to store the
       "eager state" associated with collectives they have not yet reached.
       This is an issue with many back-to-back broadcasts as will happen
       in things like benchmarks of upc_all_alloc() and upc_all_lock_alloc().
       XXX: Real fix belongs in GASNet!
    */
    const unsigned int sync_spacing = 64; /* Must be a power of 2 */
    uintptr_t counter = (uintptr_t)gasnett_threadkey_get(_upcri_broadcast_key);
    const int flags = GASNET_COLL_LOCAL | GASNET_COLL_IN_MYSYNC |
                      ((++counter & (sync_spacing-1)) ? GASNET_COLL_OUT_MYSYNC : GASNET_COLL_OUT_ALLSYNC);

    gasnett_threadkey_set(_upcri_broadcast_key, (void*)counter);
    upcri_assert(UPCRI_IS_POWER_OF_TWO(sync_spacing));
#else
    const int flags = GASNET_COLL_LOCAL | GASNET_COLL_IN_MYSYNC | GASNET_COLL_OUT_MYSYNC;
#endif

    gasnet_coll_broadcast(GASNET_TEAM_ALL, addr, from_thread, addr, len, flags);
}
