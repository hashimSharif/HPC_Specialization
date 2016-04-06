#include <upc.h>
#include <upc_collective.h>

// Allocate an array of 'count' locks and cache it in private arrays.
//
// The actual array is replicated THREADS time in the shared heap, but
// this function returns a pointer to a private piece of the array.
//
// The lock allocation calls are distributed over the threads as if
// implemented by the following:
//      upc_lock_t* shared [*] table[count];
//      upc_forall(int i=0; i<count; ++i; &table[count])
//        table[i] = upc_global_lock_alloc();
// followed by local replication of the table.
//
// This code works for any non-zero value of 'count'.
// This function must be called collectively.
//
upc_lock_t **allocate_lock_array(unsigned int count) {
  const unsigned int blksize = ((count + THREADS - 1) / THREADS); // Round up for "[*]"
  const unsigned int padded_count = blksize * THREADS;
  upc_lock_t* shared *tmp = upc_all_alloc(padded_count, sizeof(upc_lock_t*));
  upc_lock_t* shared *table = upc_all_alloc(padded_count*THREADS, sizeof(upc_lock_t*));

  // Allocate lock pointers into a temporary array.
  // This code overlays an array of blocksize [*] on the cyclic one.
  upc_lock_t** ptmp = (upc_lock_t**)(&tmp[MYTHREAD]); // Private array "slice"
  const int my_count = upc_affinitysize(count,blksize,MYTHREAD);
  for (int i=0; i<my_count; ++i) ptmp[i] = upc_global_lock_alloc();

  // Replicate the temporary array THREADS times into the shared table array.
  // IN_MYSYNC:   Since each thread generates its local portion of input.
  // OUT_ALLSYNC: Ensures upc_free() occurs only after tmp is unneeded.
  upc_all_gather_all(table, tmp, blksize * sizeof(upc_lock_t*),
                     UPC_IN_MYSYNC|UPC_OUT_ALLSYNC);

  if (!MYTHREAD) upc_free(tmp);  // Free the temporary array exactly once

  // Return a pointer-to-private for local piece of replicated table
  return (upc_lock_t**)(&table[MYTHREAD]);
} 
