/*
 * Functions for accessing shared memory
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_shaccess.h $
 * Jason Duell <jcduell@lbl.gov>
 */

#ifndef UPCR_SHACCESS_H
#define UPCR_SHACCESS_H

/* -------------------------------------------------------------------------- */
/*
 * Tracing macros
 * ==============
 * Since we bypass gasnet for local gets/puts we must log them ourselves
 */
#if GASNET_TRACE
  extern int upcri_trace_suppresslocal;
  #if UPCR_DEBUG /* include extra info when debugging */
    #define _UPCRI_TRACE_LOCAL_PUTGET(name,dest,src,nbytes) do {              \
      if (!upcri_trace_suppresslocal) {                                       \
        unsigned long long _nbytes = (nbytes);                                \
        const char *_src = (const char *)(src);                               \
        char _data_tmp[80];                                                   \
        _data_tmp[0] = '\0';                                                  \
        if (_nbytes <= 16) {                                                  \
           char *_p_out = _data_tmp; int _i;                                  \
           strcpy(_p_out,"  data: "); _p_out += strlen(_p_out);               \
           for (_i = 0; _i < (int)_nbytes; _i++) {                            \
             snprintf(_p_out,4,"%02x ", (unsigned int)_src[_i]); _p_out += 3; \
           }                                                                  \
        }                                                                     \
        UPCRI_TRACE_PRINTF_NOPOS(("%s: sz = %6llu  dst=<%p>  src=<%p>%s",     \
                          (name), _nbytes, (void *)(dest), _src, _data_tmp)); \
      }                                                                       \
    } while (0)
  #else
    #define _UPCRI_TRACE_LOCAL_PUTGET(name,dest,src,nbytes) \
      if (!upcri_trace_suppresslocal)                \
        UPCRI_TRACE_PRINTF_NOPOS(("%s: sz = %6llu", (name), (unsigned long long)(nbytes)))
  #endif
  #define UPCRI_TRACE_GET(name,dest,node,src,nbytes) _UPCRI_TRACE_LOCAL_PUTGET(#name,dest,src,nbytes)
  #define UPCRI_TRACE_PUT(name,node,dest,src,nbytes) _UPCRI_TRACE_LOCAL_PUTGET(#name,dest,src,nbytes)
  #define UPCRI_TRACE_CPY(namestr,dest,src,nbytes) _UPCRI_TRACE_LOCAL_PUTGET(namestr,dest,src,nbytes)
  #define UPCRI_TRACE_MEMSET(name,node,dest,val,nbytes) \
    if (!upcri_trace_suppresslocal)                   \
      UPCRI_TRACE_PRINTF_NOPOS((#name ": sz = %6llu", (unsigned long long)(nbytes)))
  #define UPCRI_TRACE_STRICT(isstrict) \
      if (isstrict) UPCRI_TRACE_PRINTF_NOPOS(("STRICT: the next get or put from this UPC thread is strict"))
#else /* make absolutely certain these always compile away to nothing for non-tracing */
  #define UPCRI_TRACE_GET(name,dest,node,src,nbytes)    ((void)0)
  #define UPCRI_TRACE_PUT(name,node,dest,src,nbytes)    ((void)0)
  #define UPCRI_TRACE_CPY(namestr,dest,src,nbytes)      ((void)0)
  #define UPCRI_TRACE_MEMSET(name,node,dest,val,nbytes) ((void)0)
  #define UPCRI_TRACE_STRICT(isstrict)                  ((void)0)
#endif

/* GASP instrumentation helper macros */
#define upcri_pevt_put(ps,code) \
        upcri_pevt(GASP_UPC_PUT, upcri_pevt_tmp_##ps##setup(dest, destoffset), code)
#define upcri_pevt_put_local(ps,code) \
  upcri_pevt_local(GASP_UPC_PUT, upcri_pevt_tmp_##ps##setup(dest, destoffset), code)
#define upcri_pevt_putnb(ps,code) \
        upcri_pevt(GASP_UPC_NB_PUT_INIT, upcri_pevt_tmp_##ps##setup(dest, destoffset), code)
#define upcri_pevt_putnb_local(ps,code) \
  upcri_pevt_local(GASP_UPC_NB_PUT_INIT, upcri_pevt_tmp_##ps##setup(dest, destoffset), code)

#define upcri_pevt_get(ps,code) \
        upcri_pevt(GASP_UPC_GET, upcri_pevt_tmp_##ps##setup(src, srcoffset), code)
#define upcri_pevt_get_local(ps,code) \
  upcri_pevt_local(GASP_UPC_GET, upcri_pevt_tmp_##ps##setup(src, srcoffset), code)
#define upcri_pevt_getnb(ps,code) \
        upcri_pevt(GASP_UPC_NB_GET_INIT, upcri_pevt_tmp_##ps##setup(src, srcoffset), code)
#define upcri_pevt_getnb_local(ps,code) \
  upcri_pevt_local(GASP_UPC_NB_GET_INIT, upcri_pevt_tmp_##ps##setup(src, srcoffset), code)

#if PLATFORM_COMPILER_MTA /* workaround a buggy pragma */
  #undef GASNETT_MTA_PRAGMA_EXPECT_OVERRIDE
  #define GASNETT_MTA_PRAGMA_EXPECT_OVERRIDE GASNETT_MTA_PRAGMA_EXPECT_DISABLED
#endif
/* -------------------------------------------------------------------------- */
/*
 * Miscellaneous shared pointer functions
 * ======================================
 *
 * These could logically have existed in upcr_sptr.h, but turn out to cause
 * some dependencies that are undesirable for Totalview support, so they've
 * been moved here.
 */
#if GASNET_CONDUIT_SMP && !GASNET_PSHM
  /* special case - conduit smp only supports one node, so skip the lookup costs */
  #define upcri_shared_nodeof(sptr)  (upcri_checkvalid_shared(sptr), ((gasnet_node_t)0))
  #define upcri_pshared_nodeof(sptr) (upcri_checkvalid_pshared(sptr), ((gasnet_node_t)0))
#else
  GASNETT_INLINE(upcri_shared_nodeof)
  gasnet_node_t
  upcri_shared_nodeof(upcr_shared_ptr_t sptr)
  {
      (void) upcri_checkvalid_shared(sptr);
      return upcri_thread_to_node(upcr_threadof_shared(sptr));
  }

  GASNETT_INLINE(upcri_pshared_nodeof)
  gasnet_node_t
  upcri_pshared_nodeof(upcr_pshared_ptr_t sptr)
  {
      (void) upcri_checkvalid_pshared(sptr);
      return upcri_thread_to_node(upcr_threadof_pshared(sptr));
  }
#endif

/* -------------------------------------------------------------------------- */
/*
 * Shared Memory Access Functions
 * ==============================
 *
 * Transfer scalar values to/from shared memory which may or may not be remote
 *
 * These comments apply to all put/get functions:
 *
 *  Only functions suffixed with '_strict' can be used to implement a strict
 *  operation: all other data movement functions in this specification are
 *  implicitly relaxed.
 *
 *  Nbytes should be a compile-time constant whenever possible.
 *
 *  Nbytes must be >= 0 and has no maximum size, but implementations will
 *  likely optimize for small powers of 2.
 *
 *  Source and target addresses (both local and shared) are assumed to be
 *  properly aligned for accessing objects of size nbytes.
 *
 *  If nbytes extends beyond the current block the results are undefined.
 *
 *  Destoffset(srcoffset) is an optional positive or negative BYTE offset,
 *  which is added to the address indicated by dest(src) to determine the
 *  target(source) address for the put(get) operation (Useful for puts(gets)
 *  with shared structures).
 *
 *  If adding the number of bytes indicated by destoffset(srcoffset) to
 *  dest(src) would cause dest(src) to pass the end of the current block, the
 *  result is undefined.
 *
 *  If the source and target memory areas overlap (for memory-to-memory
 *  transfers) but do not exactly coincide, the resulting target memory
 *  contents are undefined.
 *
 *  Implementations are likely to optimize for the important special case of
 *  zero destoffset(srcoffset).
*/

/* 
 * Fast logic for determining if a memory reference is local 
 */
#if GASNET_CONDUIT_SMP && !GASNET_PSHM
  typedef int upcri_local_t;   /* compiler should throw all these out */
  #define upcri_s_islocal(sptr) 1
  #define upcri_p_islocal(sptr) 1
  #define upcri_s_nodeof(s)	((gasnet_node_t)0)
  #define upcri_p_nodeof(p)	((gasnet_node_t)0)
  #if UPCRI_SINGLE_ALIGNED_REGIONS
    #define upcri_s2local(fastlocal, sptr) upcri_shared_to_local_fast(sptr)
    #define upcri_s2localoff(fastlocal, sptr, offset) \
  	  ((void*)((uintptr_t)upcri_shared_to_local_fast(sptr) + offset))
    #define upcri_p2local(fastlocal, sptr) upcri_pshared_to_local_fast(sptr)
    #define upcri_p2localoff(fastlocal, sptr, offset) \
  	  ((void*)((uintptr_t)upcri_pshared_to_local_fast(sptr) + offset))
  #else
    #define upcri_s2local(fastlocal, sptr)			  \
  	  (void *)(upcri_thread2local[upcr_threadof_shared(sptr)] \
		   + upcr_addrfield_shared(sptr))
    #define upcri_s2localoff(fastlocal, sptr, offset) \
  	  (void *)(upcri_thread2local[upcr_threadof_shared(sptr)] \
		   + upcr_addrfield_shared(sptr) + offset)
    #define upcri_p2local(fastlocal, sptr)			  \
  	  (void *)(upcri_thread2local[upcr_threadof_pshared(sptr)] \
		   + upcr_addrfield_pshared(sptr))
    #define upcri_p2localoff(fastlocal, sptr, offset) \
  	  (void *)(upcri_thread2local[upcr_threadof_pshared(sptr)] \
		   + upcr_addrfield_pshared(sptr) + offset)
  #endif
#else /* !(GASNET_CONDUIT_SMP && !GASNET_PSHM) */
  #if UPCRI_SINGLE_ALIGNED_REGIONS
    typedef int upcri_local_t;
    #define upcri_s_nodeof(s)	upcri_shared_nodeof(s)
    #define upcri_p_nodeof(p)	upcri_pshared_nodeof(p)
    #define upcri_s_islocal(sptr) \
  	  (upcr_threadof_shared(sptr) == upcr_mythread())
    #define upcri_s2local(fastlocal, sptr) \
  	  upcri_shared_to_local_fast(sptr)
    #define upcri_s2localoff(fastlocal, sptr, offset) \
  	  ((void*)((uintptr_t)upcri_shared_to_local_fast(sptr) + offset))
    #define upcri_p_islocal(sptr) \
  	  (upcr_threadof_pshared(sptr) == upcr_mythread())
    #define upcri_p2local(fastlocal, sptr) \
  	  upcri_pshared_to_local_fast(sptr)
    #define upcri_p2localoff(fastlocal, sptr, offset) \
  	  ((void*)((uintptr_t)upcri_pshared_to_local_fast(sptr) + offset))
  #else /* !UPCRI_SINGLE_ALIGNED_REGIONS */
    typedef uintptr_t upcri_local_t;
    #if GASNET_CONDUIT_SHMEM && (PLATFORM_ARCH_CRAYX1 || GASNETI_ARCH_ALTIX)
      /* Special case -- these conduits know to ignore the node field */
      #define upcri_s_nodeof(s)	((gasnet_node_t)-1)
      #define upcri_p_nodeof(p)	((gasnet_node_t)-1)
    #else
      #define upcri_s_nodeof(s)	upcri_shared_nodeof(s)
      #define upcri_p_nodeof(p)	upcri_pshared_nodeof(p)
    #endif

    #define upcri_s_islocal(sptr) \
  	  upcri_thread2local[upcr_threadof_shared(sptr)]	  
    #define upcri_s2local(fastlocal, sptr) \
  	  ((void *)(fastlocal + upcr_addrfield_shared(sptr)))
    #define upcri_s2localoff(fastlocal, sptr, offset) \
  	  ((void *)(fastlocal + upcr_addrfield_shared(sptr) + offset))
    #if UPCRI_SYMMETRIC_PSHARED 
      #if __BERKELEY_UPC_POW2_SYMPTR__
	#define upcri_p_islocal(sptr) upcri_thread2local[upcr_threadof_pshared(sptr)]
      #else
        /* without power-of-two opt, we skip the slower threadof op */
        #define upcri_p_islocal(sptr) \
	        ((uintptr_t)(sptr) >= upcri_thread2region[upcr_mythread()] && \
		 (uintptr_t)(sptr)  < upcri_thread2region[upcr_mythread()]+upcri_segsym_region_size)
      #endif
      #define upcri_p2local(fastlocal, sptr) (sptr)
      #define upcri_p2localoff(fastlocal, sptr, offset) ((sptr) + offset)
    #else
      #define upcri_p_islocal(sptr) \
  	  upcri_thread2local[upcr_threadof_pshared(sptr)]	  
      #define upcri_p2local(fastlocal, sptr) \
  	    ((void *)(fastlocal + upcr_addrfield_pshared(sptr)))
      #define upcri_p2localoff(fastlocal, sptr, offset) \
  	    ((void *)(fastlocal + upcr_addrfield_pshared(sptr) + offset))
    #endif
  #endif /* UPCRI_SINGLE_ALIGNED_REGIONS */
#endif /* GASNET_CONDUIT_SMP && !GASNET_PSHM */

#if UPCRI_UPC_PTHREADS
  /* Pass gasnet threadinfo to gasnet functions */
  #define UPCRI_PASS_GAS() \
	  GASNET_POST_THREADINFO(upcri_mypthreadinfo()->gasnet_tinfo)
 #if 0
  /* DOB: this scheme is broken under GASNETI_LAZY_BEGINFUNCTION
     and causes failures because there's one place that upcr needs GASNET_GET_THREADINFO()
     to work as usual (namely, the during pthread initialization) 
   */
  /* Turn off gasnet's clever mechanism for fetching thread info if we forget
   * to pass it, so we'll get an error (or at least a warning) if we
   * forget to pass it (since gasnete_threadinfo_cache will be undefined, or
   * assumed to be an int). */
  #undef GASNET_GET_THREADINFO
  #define GASNET_GET_THREADINFO()  gasnete_threadinfo_cache 
 #endif
#else
  /* prevent a compile error due to semicolon */
  #define UPCRI_PASS_GAS() static char _bupc_dummy_PASS_GAS = (char)sizeof(_bupc_dummy_PASS_GAS)
#endif

/* 
 * Memory copying macros 
 */
#define UPCRI_ALIGNED_MEMCPY(dest, src, nbytes) \
	GASNETT_FAST_ALIGNED_MEMCPY(dest, src, nbytes)

#define UPCRI_UNALIGNED_MEMCPY(dest, src, nbytes) \
	GASNETT_FAST_UNALIGNED_MEMCPY(dest, src, nbytes)

#define UPCRI_VALUE_ASSIGN(dest, value, nbytes) \
	GASNETT_VALUE_ASSIGN(dest, value, nbytes)

#define UPCRI_VALUE_RETURN(src, nbytes) \
	GASNETT_VALUE_RETURN(src, nbytes)

/* upcr_(p)shared_to_processlocal - public version of upcri_(p)shared_to_remote
 * Convert a pointer-to-shared into a virtual address usable by the calling thread
 * The pointer target must refer to shared memory with affinity to the calling thread, 
 * or otherwise to shared memory which the calling thread has the ability to access 
 * directly via load/store to virtual memory, otherwise the call is erroneous.
 * The extent of memory which falls into the latter category is implementation-dependent
 * and may be empty. Furthermore, the virtual addresses returned by this function
 * are only guaranteed to be valid on the calling thread.
 */
#define upcr_shared_to_processlocal(sptr) \
       _upcr_shared_to_processlocal(sptr UPCRI_TV_PASS)

GASNETT_INLINE(_upcr_shared_to_processlocal)
void *_upcr_shared_to_processlocal(upcr_shared_ptr_t sptr UPCRI_TV_ARG) {
    (void) upcri_checkvalid_shared(sptr);
    upcri_assert(upcri_s_islocal(sptr));
#if UPCRI_USING_PSHM
    return upcri_s2local(upcri_s_islocal(sptr), sptr);
#else
    return upcri_shared_to_remote(sptr);
#endif
}
#define upcr_pshared_to_processlocal(sptr) \
       _upcr_pshared_to_processlocal(sptr UPCRI_TV_PASS)

GASNETT_INLINE(_upcr_pshared_to_processlocal)
void *_upcr_pshared_to_processlocal(upcr_pshared_ptr_t sptr UPCRI_TV_ARG) {
    (void) upcri_checkvalid_pshared(sptr);
    upcri_assert(upcri_p_islocal(sptr));
#if UPCRI_USING_PSHM
    return upcri_p2local(upcri_p_islocal(sptr), sptr);
#else
    return upcri_pshared_to_remote(sptr);
#endif
}

/* upc_cast()  */
GASNETT_INLINE(upcri_castable)
int upcri_castable(upcr_shared_ptr_t sptr) {
  (void) upcri_checkvalid_shared(sptr);
#if UPCRI_SYMMETRIC_SEGMENTS
  return 1;
#else
  return upcri_s_islocal(sptr) || upcr_isnull_shared(sptr);
#endif
}
GASNETT_INLINE(upcr_cast)
void *upcr_cast(upcr_shared_ptr_t sptr) {
  if (upcr_isnull_shared(sptr) || !upcri_castable(sptr)) return NULL;
  else return upcr_shared_to_processlocal(sptr);
}

/* LEGACY (to be removed at UPC-1.4) ONLY: */
/* bupc_cast() family.  See upcr_preinclude/bupc_extensions.h */
GASNETT_INLINE(bupc_castable) GASNETT_DEPRECATED
int bupc_castable(upcr_shared_ptr_t sptr) {
  return upcri_castable(sptr);
}
GASNETT_INLINE(bupc_thread_castable) GASNETT_DEPRECATED
int bupc_thread_castable(unsigned int thr) {
  return upcri_thread_is_addressable(thr);
}
GASNETT_INLINE(bupc_cast) GASNETT_DEPRECATED
void *bupc_cast(upcr_shared_ptr_t sptr) {
  return upcr_cast(sptr);
}

/* 
 * UPCR_ATOMIC_MEMSIZE() is a macro describing the datatype sizes at which
 * memory accesses will be done atomically. Given a datatype width sz (in
 * bytes) it will return non-zero at compile time iff a local or shared memory
 * access of exactly sz bytes, to an address aligned by sz bytes, will happen
 * atomically with respect to accesses from other threads to the same
 * location.
 *
 * A non-zero return value for a given size does not guarantee atomicity for
 * smaller sizes or unaligned accesses of the given size.
 *
 * Some architectures may provide no atomic sizes.
 *
 * UPCR_ATOMIC_MEMSIZE(0) will return the largest atomic size available, or
 * zero if none exists.
*/
#define UPCR_ATOMIC_MEMSIZE(sz) ???


/* perform memory barriers before/after strict gets/puts 
 * necessary even on uniprocessors because NIC is potentially an extra CPU
 *
 * For strict GETs and PUTs:
 * + We need a WMB before a strict GET/PUT to ensure all preceeding stores
 *   are completed before this operation begins.
 * + We need an RMB after a strict GET/PUT to prevent subsequent loads from
 *   being issued too early.
 *
 * For strict PUTs only:  
 * + For strict PUTs performed locally (as stores to memory) we also need a
 *   WMB after, ensuring the PUT will be made visible to subsequent GETs
 *   from other threads (either on the same SMP, or via an RDMA-capable
 *   conduit).
 *
 * For strict GETs only:
 * + For strict GETs performed locally (as loads from memory) we also need a
 *   RMB before, ensuring that preceeding loads are completed before the new
 *   one is issued.
 *
 * When operations are performed to/from local memory we will require both an
 * RMB and a WMB, which will be combined into a single "full" MB().
 *
 * All this boils down to the following pseudo code for blocking operations:
 *   strict_PUT(...) {
 *     WMB();
 *
 *     do_put(...);
 *
 *     if (is_local) MB();
 *     else RMB();
 *   }
 *
 *   strict_GET(...) {
 *     if (is_local) MB();
 *     else WMB();
 *
 *     do_get(...);
 *
 *     RMB();
 *   }
 *
 * For non-blocking operations performed through GASNet, the memory barriers
 * required before the operation are done in the initiation function and the
 * required RMB() is normally performed in the synchronization function.
 * However, if a non-blocking call to GASNet for a strict operation returns
 * GASNET_INVALID_HANDLE, then the required RMB() will be performed in the
 * initiation function (this would happen, for instance, with a GASNet
 * implementation that performs blocking operations in place of some/all
 * explicit non-blocking operations).
 *
 * For non-blocking operations performed locally all required memory barriers
 * are performed at initiation and a return of UPCR_INVALID_HANDLE ensures no
 * additional memory barriers are performed at synchronization.
 */
#define upcri_strict_wmb(isstrict)	if (isstrict) gasnett_local_wmb()
#define upcri_strict_rmb(isstrict)	if (isstrict) gasnett_local_rmb()
#define upcri_strict_mb(isstrict)	if (isstrict) gasnett_local_mb()

/* When a network conduit is in-order, we can optionally turn some blocking
 * Put operations into (non-bulk) non-blocking operations, with the addition
 * of some extra logic at strict references.
 */
#if defined(GASNET_CONDUIT_MXM) && defined(UPCRI_STRICT_HOOK_ENABLED)
  #define UPCRI_DO_MEMPUT_NBI 1
#endif

/* When performing certain relaxed memory ops using non-blocking network ops
 * (for instance when UPCRI_DO_MEMPUT_NBI is defined) we need to "sync" any
 * such operations which are outstanding at any strict reference (including
 * upc_fence, locks, barriers, etc.).
 */
#ifdef UPCRI_STRICT_HOOK_ENABLED
#define upcri_strict_hook() _upcri_strict_hook(UPCRI_PT_PASS_ALONE)
GASNETT_INLINE(_upcri_strict_hook)
void _upcri_strict_hook(UPCRI_PT_ARG_ALONE)
{
  #if defined(UPCRI_DO_MEMPUT_NBI)
    UPCRI_PASS_GAS();
    gasnet_wait_syncnbi_all();
  #endif
}
#else
  #define upcri_strict_hook() ((void)0)
#endif /* UPCRI_STRICT_HOOK_ENABLED */

#define UPCRI_STRICT_HOOK_IF(isstrict) if (isstrict) upcri_strict_hook()

/* Ick - We can use a non-bulk operation only when src and dst are both
 *    "properly aligned for accessing objects of size nbytes"
 *
 * This may be interpreted strictly as requring that when nbytes is a
 * power-of-two no larger than the native word size (e.g. 4 or 8 bytes)
 * the addresses must be a multiple of nbytes.  This ensures that 16-bit,
 * 32-bit and 64-bit loads and stores may be used without raising
 * exceptions.  For instance when nbytes=4 we require src and dst be
 * 4-byte aligned.
 *
 * However, on some platforms unaligned loads and stores are legal (and
 * incur either no penalty or one small enough not to justify the
 * overhead of checking).  On such systems the strict interpretation is
 * unnecessary.
 * 
 * TODO: Remove when GASNet-EX separates alignment from local completion.
 */
#if PLATFORM_ARCH_X86 || PLATFORM_ARCH_X86_64
  #define upcri_is_aligned(nbytes, addr1, addr2) 1
#else
  #define upcri_is_aligned(nbytes, addr1, addr2) \
              (((nbytes)>sizeof(void*)) || \
               !UPCRI_IS_POWER_OF_TWO(nbytes) || \
               !(((nbytes)-1)&((uintptr_t)(addr1)|(uintptr_t)(addr2))))
#endif


/* --- Blocking memory-to-memory puts and gets ---
 *
 * A call to these functions will block until the transfer is complete, and
 * the contents of the destination memory are undefined until it completes. 
 *
 * If the contents of the source memory change while the operation is in
 * progress the result will be implementation-specific.
 */
#define upcr_put_shared(dest, destoffset, src, nbytes) \
       (upcri_srcpos(), _upcr_put_shared(dest, destoffset, src, nbytes, 0 UPCRI_PT_PASS))
#define upcr_put_shared_strict(dest, destoffset, src, nbytes) \
       (upcri_srcpos(), _upcr_put_shared(dest, destoffset, src, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_shared)
void 
_upcr_put_shared(upcr_shared_ptr_t dest, ptrdiff_t destoffset, const void *src, 
		 size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dest);
    (void) upcri_checkvalid_nonnull_shared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, src, nbytes
    if (local) upcri_pevt_put_local(s,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_LOCAL, gasnet_mynode(),
			upcri_s2localoff(local, dest, destoffset),
			src, nbytes);
	UPCRI_ALIGNED_MEMCPY(upcri_s2localoff(local, dest, destoffset),
			     src, nbytes);
	upcri_strict_mb(isstrict);
    }); else upcri_pevt_put(s,{
        upcri_strict_wmb(isstrict);
	gasnet_put(upcri_s_nodeof(dest),
		   upcri_shared_to_remote_off(dest, destoffset),
		   (void *)src, nbytes);
	upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_put_pshared(dest, destoffset, src, nbytes) \
       (upcri_srcpos(), _upcr_put_pshared(dest, destoffset, src, nbytes, 0 UPCRI_PT_PASS))
#define upcr_put_pshared_strict(dest, destoffset, src, nbytes) \
       (upcri_srcpos(), _upcr_put_pshared(dest, destoffset, src, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_pshared)
void 
_upcr_put_pshared(upcr_pshared_ptr_t dest, ptrdiff_t destoffset, const void *src, 
		  size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(dest);
    (void) upcri_checkvalid_nonnull_pshared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, src, nbytes
    if (local) upcri_pevt_put_local(p,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_LOCAL, gasnet_mynode(),
			upcri_p2localoff(local, dest, destoffset),
			src, nbytes);
	UPCRI_ALIGNED_MEMCPY(upcri_p2localoff(local, dest, destoffset),
			     src, nbytes);
	upcri_strict_mb(isstrict);
    }); else upcri_pevt_put(p,{
        upcri_strict_wmb(isstrict);
	gasnet_put(upcri_p_nodeof(dest),
		   upcri_pshared_to_remote_off(dest, destoffset),
		   (void *)src, nbytes);
	upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_get_shared(dest, src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_shared(dest, src, srcoffset, nbytes, 0 UPCRI_PT_PASS))
#define upcr_get_shared_strict(dest, src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_shared(dest, src, srcoffset, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_shared)
void 
_upcr_get_shared(void *dest, upcr_shared_ptr_t src, ptrdiff_t srcoffset, 
		 size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(src);
    (void) upcri_checkvalid_nonnull_shared(src);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, dest, &UPCRI_PEVT_PTMP, nbytes
    if (local) upcri_pevt_get_local(s,{
	UPCRI_TRACE_GET(GET_LOCAL, dest, gasnet_mynode(),
			upcri_s2localoff(local, src, srcoffset), nbytes);
	upcri_strict_mb(isstrict);
	UPCRI_ALIGNED_MEMCPY(dest, upcri_s2localoff(local, src, srcoffset),
			     nbytes);
        upcri_strict_rmb(isstrict);
    }); else upcri_pevt_get(s,{
	upcri_strict_wmb(isstrict);
	gasnet_get(dest, upcri_s_nodeof(src),
		   upcri_shared_to_remote_off(src, srcoffset),
		   nbytes);
        upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_get_pshared(dest, src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_pshared(dest, src, srcoffset, nbytes, 0 UPCRI_PT_PASS))
#define upcr_get_pshared_strict(dest, src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_pshared(dest, src, srcoffset, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_pshared)
void 
_upcr_get_pshared(void *dest, upcr_pshared_ptr_t src, ptrdiff_t srcoffset, 
		  size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(src);
    (void) upcri_checkvalid_nonnull_pshared(src);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, dest, &UPCRI_PEVT_PTMP, nbytes
    if (local) upcri_pevt_get_local(p,{
	UPCRI_TRACE_GET(GET_LOCAL, dest, gasnet_mynode(),
			upcri_p2localoff(local, src, srcoffset), nbytes);
	upcri_strict_mb(isstrict);
	UPCRI_ALIGNED_MEMCPY(dest, upcri_p2localoff(local, src, srcoffset),
			     nbytes);
        upcri_strict_rmb(isstrict);
    }); else upcri_pevt_get(p,{
	upcri_strict_wmb(isstrict);
	gasnet_get(dest, upcri_p_nodeof(src),
		   upcri_pshared_to_remote_off(src, srcoffset),
		   nbytes);
        upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
}
/* --- Type-based gets/puts --- 
 * The following 'functions' are all preprocessor
 * macros, which take a type name (e.g. '_INT32', 'struct mcfoo') as one of
 * their arguments.  This is referred to as 'TYPE' in the arguments.  The
 * reason for this interface's existence is that casts to the exact destination
 * type for a get/put allow it to be transformed into a regular assignment
 * statement, rather than a memget() style call, which requires that the
 * address be taken, which causes performance degradation for many back-end C
 * compilers.  Also, having the exact type (as opposed to casting to some
 * generic type of the same size) avoids potential aliasing errors (or lost
 * optimization possibilities).
 *
 * TYPE            // the C type of the value being assigned ("_INT32",
 *                 // "struct mfoo", etc.).  Array types are NOT permitted.
 * LVALUE          // any lvalue of type TYPE
 * VALUE           // any expression of type TYPE
 *
 * --- Relaxed gets ---
 *  void upcr_get_shared_type(LVALUE dest, upcr_shared_ptr_t src, ptrdiff_t srcbyteoffset, TYPE type) \
 *  void upcr_get_pshared_type(LVALUE dest, upcr_pshared_ptr_t src, ptrdiff_t srcbyteoffset, TYPE type) \
 *
 * --- Strict gets ---
 *  void upcr_get_shared_type_strict(LVALUE dest, upcr_shared_ptr_t src, ptrdiff_t srcbyteoffset, TYPE type) \
 *  void upcr_get_pshared_type_strict(LVALUE dest, upcr_pshared_ptr_t src, ptrdiff_t srcbyteoffset, TYPE type) \
 *
 * --- Relaxed puts --- 
 *  void upcr_put_shared_type(upcr_shared_ptr_t dest, ptrdiff_t destbyteoffset, VALUE val, TYPE type) \
 *  void upcr_put_pshared_type(upcr_pshared_ptr_t dest, ptrdiff_t destbyteoffset, VALUE val, TYPE type) \
 *
 * --- Strict puts --- 
 *  void upcr_put_shared_type_strict(upcr_shared_ptr_t dest, ptrdiff_t destbyteoffset, VALUE val, TYPE type) \
 *  void upcr_put_pshared_type_strict(upcr_pshared_ptr_t dest, ptrdiff_t destbyteoffset, VALUE val, TYPE type) \
 *
 */

/* relaxed gets */
#define upcr_get_shared_type(dest, src, srcbyteoffset, type) \
       _upcr_get_shared_type((dest), (src), (srcbyteoffset), type, 0)
#define upcr_get_pshared_type(dest, src, srcbyteoffset, type) \
       _upcr_get_pshared_type((dest), (src), (srcbyteoffset), type, 0)
 /* strict gets */
#define upcr_get_shared_type_strict(dest, src, srcbyteoffset, type) \
       _upcr_get_shared_type((dest), (src), (srcbyteoffset), type, 1)
#define upcr_get_pshared_type_strict(dest, src, srcbyteoffset, type) \
       _upcr_get_pshared_type((dest), (src), (srcbyteoffset), type, 1)

#define _upcr_get_shared_type(dest, src, srcbyteoffset, type, isstrict) \
    do {                                                                \
        upcri_srcpos();                                                 \
        _upcr_get_shared(&(dest), (src), (srcbyteoffset), sizeof(type), \
			 isstrict UPCRI_PT_PASS);                       \
    } while (0)

#define _upcr_get_pshared_type(dest, src, srcbyteoffset, type, isstrict) \
    do {                                                                 \
        upcri_srcpos();                                                  \
        _upcr_get_pshared(&(dest), (src), (srcbyteoffset), sizeof(type), \
			  isstrict UPCRI_PT_PASS);                       \
    } while (0)

 /* relaxed puts */
#define upcr_put_shared_type(dest, destbyteoffset, val, type) \
       _upcr_put_shared_type((dest), (destbyteoffset), (val), type, 0)
#define upcr_put_pshared_type(dest, destbyteoffset, val, type) \
       _upcr_put_pshared_type((dest), (destbyteoffset), (val), type, 0)
 /* strict puts */
#define upcr_put_shared_type_strict(dest, destbyteoffset, val, type) \
       _upcr_put_shared_type((dest), (destbyteoffset), (val), type, 1)
#define upcr_put_pshared_type_strict(dest, destbyteoffset, val, type) \
       _upcr_put_pshared_type((dest), (destbyteoffset), (val), type, 1)

#define _upcr_put_shared_type(dest, destbyteoffset, val, type, isstrict) \
    do {                                                                 \
	type upcri_tmp = (val);                                          \
        upcri_srcpos();                                                  \
        _upcr_put_shared((dest), (destbyteoffset), &upcri_tmp,           \
			 sizeof(upcri_tmp), isstrict UPCRI_PT_PASS);     \
    } while (0)

#define _upcr_put_pshared_type(dest, destbyteoffset, val, type, isstrict) \
    do {                                                                  \
	type upcri_tmp = (val);                                           \
        upcri_srcpos();                                                   \
        _upcr_put_pshared((dest), (destbyteoffset), &upcri_tmp,           \
			  sizeof(upcri_tmp), isstrict UPCRI_PT_PASS);     \
    } while (0)

/* --- Non-blocking operations --- 
 *
 * The following functions provide non-blocking, split-phase memory access to
 * shared data.  All such non-blocking operations require an initiation (put
 * or get) and a subsequent synchronization on the completion of that
 * operation before the result is guaranteed.  
 *
 * Synchronization of a get operation means the local result is ready to be
 * examined, and will contain a value held by the shared location at some time
 * in the interval between the call to the initiation function and the
 * successful completion of the synchronization (note this specifically allows
 * implementations to delay the underlying read until the synchronization
 * operation is called, provided they preserve the blocking semantics of the
 * synchronization function).
 *
 * Synchronization of a put operation means the source data has been written
 * to the shared location and get operations issued subsequently by any thread
 * will receive the new value or a subsequently written value (assuming no
 * other threads are writing the location).
 *
 * There are two categories of non-blocking operations:
 *
 *   "explicit handle" (nb) - return a specific handle to caller which is used
 *   for synchronization.  This handle can be used to synchronize a specific
 *   subset of the nb operations in-flight.
 *
 *   "implicit handle" (nbi) - don't return a handle - synchronization is
 *   accomplished by calling a synchronization routine that synchronizes all
 *   outstanding nbi operations.
 *
 * Note that the order in which non-blocking operations complete is
 * intentionally unspecified.  The system is free to coalesce and/or reorder
 * non-blocking operations with respect to other blocking or non-blocking
 * operations, or operations initiated from a separate thread.  The only
 * ordering constraints that must be satisfied are those explicitly enforced
 * using the synchronization functions (i.e. the non-blocking operation is
 * only guaranteed to occur somewhere in the interval between initiation and
 * successful synchronization on that operation).
 *
 * The compiler bears full responsibility for maintaining the memory
 * consistency semantics presented to the UPC user when using non-blocking
 * operations.  The compiler must generate synchronizations at the appropriate
 * points (e.g. before calling upcr_unlock() or upcr_notify()).   
 *
 * Implementors should attempt to make the non-blocking operations return as
 * quickly as possible--however in some cases (e.g. when a large number of
 * non-blocking operations have been issued or the network is otherwise busy)
 * it may be necessary to block temporarily while waiting for the network to
 * become available.  In any case, all implementations must support an
 * unlimited number of non-blocking operations in-progress--that is, the
 * client is free to issue an unlimited number of non-blocking operations
 * before issuing a sync operation, and implementations must handle this
 * correctly without deadlock. 
 *
 * The '_strict' versions of these functions implement strict nonblocking UPC
 * puts/gets.  It is an error for any nonblocking (relaxed or strict)
 * operation to overlap a strict put/get.  Only one strict nonblocking
 * operation may be pending at any time, and no other operation (relaxed or
 * strict) may be initiated or completed in between that strict operation's
 * initiation and its completion.
 */

/* 
 * upcr_handle_t is a datatype used for representing a non-blocking operation
 * currently in-flight that was initiated with an "explicit handle"
 * non-blocking operation. The contents are implementation-defined.
 *
 * UPCR_INVALID_HANDLE is a compile-time constant which can be used as a
 * "dummy" handle value, which is ignored by all the operations that take
 * upcr_handle_t's.  Furthermore this value must be the result of setting all
 * the bits in the upcr_handle_t datatype to zero.
 *
 * Implementations are free to define the upcr_handle_t type to be any
 * reasonable and appropriate size, although they are recommended to use a
 * type which fits within a single standard register on the target
 * architecture.  In any case, the datatype should be wide enough to express
 * at least 2^16-1 different handle values, to prevent limiting the number of
 * non-blocking operations in progress due to the number of handles available.
 *
 * upcr_handle_t values are thread-specific.  In other words, it is an error
 * to obtain a handle value by initiating a non-blocking operation on one
 * thread, and later pass that handle into a synchronization function from a
 * different thread (results are undefined).
 *
 * Similarly, synchronization functions for "implicit handle" non-blocking
 * operations only synchronize on "implicit handle" operations initiated from
 * the calling thread.
 *
 * It _is_ legal to pass upcr_handle_t values into function callees or back to
 * function callers.
 */
typedef gasnet_handle_t upcr_handle_t;

#define UPCR_INVALID_HANDLE GASNET_INVALID_HANDLE

/* --- Non-blocking memory-to-memory, explicit handle (nb) ---
 *
 *  These calls initiate a non-blocking operation and return "immediately"
 *  with a non-blocking handle that can be used to later synchronize the
 *  operation, using one of the explicit sync operations.
 *
 *  Once the put version returns, the source memory may safely be overwritten.
 *  For the get version, if the contents of the source memory change while the
 *  operation is in progress the result will be implementation-specific.
 *
 *  The contents of the destination memory address are undefined until a
 *  synchronization completes successfully for the non-blocking operation. 
 *
 *  The operations may return UPCR_INVALID_HANDLE to indicate it was possible
 *  to complete the operation immediately without blocking (e.g. operations on
 *  shared memory with affinity to this thread)
 *
 *  It is an error to discard the upcr_handle_t value for an operation
 *  in-flight - i.e. to initiate an operation and never synchronize on its
 *  completion
 */
#define upcr_put_nb_shared(dest, destoffset, src, nbytes) \
       (upcri_srcpos(), _upcr_put_nb_shared(dest, destoffset, src, nbytes, 0 UPCRI_PT_PASS))
#define upcr_put_nb_shared_strict(dest, destoffset, src, nbytes) \
       (upcri_srcpos(), _upcr_put_nb_shared(dest, destoffset, src, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_nb_shared) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t 
_upcr_put_nb_shared(upcr_shared_ptr_t dest, ptrdiff_t destoffset, const void *src, 
		    size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcr_handle_t h = UPCR_INVALID_HANDLE;
    upcri_local_t local = upcri_s_islocal(dest);
    (void) upcri_checkvalid_nonnull_shared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, src, nbytes, (h==UPCR_INVALID_HANDLE?GASP_UPC_NB_TRIVIAL:h)
    if (local) upcri_pevt_putnb_local(s,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_NB_LOCAL, gasnet_mynode(),
			upcri_s2localoff(local, dest, destoffset),
			src, nbytes);
	UPCRI_ALIGNED_MEMCPY(upcri_s2localoff(local, dest, destoffset),
			     src, nbytes);
	upcri_strict_mb(isstrict);
	h = UPCR_INVALID_HANDLE;
    }); else upcri_pevt_putnb(s,{
        upcri_strict_wmb(isstrict);
	h = gasnet_put_nb(upcri_s_nodeof(dest),
				upcri_shared_to_remote_off(dest, destoffset),
				(void *)src, nbytes);
	if_pf (h == UPCR_INVALID_HANDLE)
	    upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return h;
}

#define upcr_get_nb_shared(dest, src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_nb_shared(dest, src, srcoffset, nbytes, 0 UPCRI_PT_PASS))
#define upcr_get_nb_shared_strict(dest, src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_nb_shared(dest, src, srcoffset, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_nb_shared) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t 
_upcr_get_nb_shared(void *dest, upcr_shared_ptr_t src, ptrdiff_t srcoffset, 
		    size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcr_handle_t h = UPCR_INVALID_HANDLE;
    upcri_local_t local = upcri_s_islocal(src);
    (void) upcri_checkvalid_nonnull_shared(src);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, dest, &UPCRI_PEVT_PTMP, nbytes, (h==UPCR_INVALID_HANDLE?GASP_UPC_NB_TRIVIAL:h)
    if (local) upcri_pevt_getnb_local(s,{
	UPCRI_TRACE_GET(GET_NB_LOCAL, dest, gasnet_mynode(),
			upcri_s2localoff(local, src, srcoffset), nbytes);
	upcri_strict_mb(isstrict);
	UPCRI_ALIGNED_MEMCPY(dest, upcri_s2localoff(local, src, srcoffset),
			     nbytes);
	upcri_strict_rmb(isstrict);
	h = UPCR_INVALID_HANDLE;
    }); else upcri_pevt_getnb(s,{
	upcri_strict_wmb(isstrict);
	h = gasnet_get_nb(dest, upcri_s_nodeof(src),
			  upcri_shared_to_remote_off(src, srcoffset), nbytes);
	if_pf (h == UPCR_INVALID_HANDLE)
	    upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return h;
}

#define upcr_put_nb_pshared(dest, destoffset, src, nbytes) \
       (upcri_srcpos(), _upcr_put_nb_pshared(dest, destoffset, src, nbytes, 0 UPCRI_PT_PASS))
#define upcr_put_nb_pshared_strict(dest, destoffset, src, nbytes) \
       (upcri_srcpos(), _upcr_put_nb_pshared(dest, destoffset, src, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_nb_pshared) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t 
_upcr_put_nb_pshared(upcr_pshared_ptr_t dest, ptrdiff_t destoffset, const void *src, 
		     size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcr_handle_t h = UPCR_INVALID_HANDLE;
    upcri_local_t local = upcri_p_islocal(dest);
    (void) upcri_checkvalid_nonnull_pshared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, src, nbytes, (h==UPCR_INVALID_HANDLE?GASP_UPC_NB_TRIVIAL:h)
    if (local) upcri_pevt_putnb_local(p,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_NB_LOCAL, gasnet_mynode(),
			upcri_p2localoff(local, dest, destoffset),
			src, nbytes);
	UPCRI_ALIGNED_MEMCPY(upcri_p2localoff(local, dest, destoffset),
			     src, nbytes);
	upcri_strict_mb(isstrict);
	h = UPCR_INVALID_HANDLE;
    }); else upcri_pevt_putnb(p,{
        upcri_strict_wmb(isstrict);
	h = gasnet_put_nb(upcri_p_nodeof(dest),
				upcri_pshared_to_remote_off(dest, destoffset),
				(void *)src, nbytes);
	if_pf (h == UPCR_INVALID_HANDLE)
	    upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return h;
}

#define upcr_get_nb_pshared(dest, src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_nb_pshared(dest, src, srcoffset, nbytes, 0 UPCRI_PT_PASS))
#define upcr_get_nb_pshared_strict(dest, src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_nb_pshared(dest, src, srcoffset, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_nb_pshared) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t 
_upcr_get_nb_pshared(void *dest, upcr_pshared_ptr_t src, ptrdiff_t srcoffset, 
		     size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcr_handle_t h = UPCR_INVALID_HANDLE;
    upcri_local_t local = upcri_p_islocal(src);
    (void) upcri_checkvalid_nonnull_pshared(src);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, dest, &UPCRI_PEVT_PTMP, nbytes, (h==UPCR_INVALID_HANDLE?GASP_UPC_NB_TRIVIAL:h)
    if (local) upcri_pevt_getnb_local(p,{
	UPCRI_TRACE_GET(GET_NB_LOCAL, dest, gasnet_mynode(),
			upcri_p2localoff(local, src, srcoffset), nbytes);
	upcri_strict_mb(isstrict);
	UPCRI_ALIGNED_MEMCPY(dest, upcri_p2localoff(local, src, srcoffset),
			     nbytes);
	upcri_strict_rmb(isstrict);
	h = UPCR_INVALID_HANDLE;
    }); else upcri_pevt_getnb(p,{
	upcri_strict_wmb(isstrict);
	h = gasnet_get_nb(dest, upcri_p_nodeof(src),
			  upcri_pshared_to_remote_off(src, srcoffset), nbytes);
	if_pf (h == UPCR_INVALID_HANDLE)
	    upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return h;
}

/* --- Explicit handle synchronization (for get_nb and put_nb) ---
 *
 * The UPC Runtime supports two basic variants of synchronization for
 * non-blocking operations - trying (polling) and waiting (blocking). 

 * All explicit synchronization functions take one or more upcr_handle_t
 * values as input and either return an indication of whether the operation
 * has completed or block until it completes. 
 */

/* Single operation explicit synchronization
 *
 * Synchronize on the completion of a single, particular non-blocking
 * operation that was initiated by this thread. 
 *
 * upcr_wait_syncnb() blocks until the specified operation has completed (or
 * returns immediately if it has already completed).  In any case, the handle
 * value is "dead" after upcr_wait_syncnb() returns and may not be passed to
 * future synchronization operations.
 *
 * upcr_try_syncnb() always returns immediately, with the value 1 if the
 * operation is complete (at which point the handle value is "dead", and may
 * not be used in future synchronization operations), or 0 if the operation is
 * not yet complete and future synchronization is necessary to complete this
 * operation.
 *
 * upcr_{try,wait}_syncnb_strict() operate just as upcr_{try.wait}_syncnb() do,
 * but must be used for strict operations (and only for strict operations).
 *
 * It is legal to pass UPCR_INVALID_HANDLE as input to these functions:
 * upcr_wait_syncnb{,_strict}(UPCR_INVALID_HANDLE) return immediately and
 * upcr_try_syncnb{,_strict}(UPCR_INVALID_HANDLE) return 1.
 */

GASNETT_INLINE(_upcr_wait_syncnb)
void _upcr_wait_syncnb(upcr_handle_t handle UPCRI_PT_ARG_IFINST) {
  #define UPCRI_PEVT_ARGS , handle
  upcri_pevt(GASP_UPC_NB_SYNC,{},{
    gasnet_wait_syncnb(handle);
  });
  #undef UPCRI_PEVT_ARGS
}
#define upcr_wait_syncnb(handle) \
       (upcri_srcpos(), _upcr_wait_syncnb(handle UPCRI_PT_PASS_IFINST))

GASNETT_INLINE(_upcr_wait_syncnb_strict)
void _upcr_wait_syncnb_strict(upcr_handle_t handle UPCRI_PT_ARG) {
  #define UPCRI_PEVT_ARGS , handle
  upcri_pevt(GASP_UPC_NB_SYNC,{},{
    gasnet_wait_syncnb(handle);
    upcri_strict_hook();
    upcri_strict_rmb(handle != UPCR_INVALID_HANDLE);
  });
  #undef UPCRI_PEVT_ARGS
}
#define upcr_wait_syncnb_strict(handle) \
       (upcri_srcpos(), _upcr_wait_syncnb_strict(handle UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_try_syncnb)
int _upcr_try_syncnb(upcr_handle_t handle UPCRI_PT_ARG_IFINST) {
  int retval = 0;
  #define UPCRI_PEVT_ARGS , handle, retval
  upcri_pevt(GASP_BUPC_NB_TRYSYNC,{},{
    retval = (gasnet_try_syncnb(handle) == GASNET_OK);
  });
  #undef UPCRI_PEVT_ARGS
  return retval;
}
#define upcr_try_syncnb(handle) \
       (upcri_srcpos(), _upcr_try_syncnb(handle UPCRI_PT_PASS_IFINST))

GASNETT_INLINE(_upcr_try_syncnb_strict)
int _upcr_try_syncnb_strict(upcr_handle_t handle UPCRI_PT_ARG) {
  int retval = 0;
  #define UPCRI_PEVT_ARGS , handle, retval
  upcri_pevt(GASP_BUPC_NB_TRYSYNC,{},{
    retval = (gasnet_try_syncnb(handle) == GASNET_OK);
    UPCRI_STRICT_HOOK_IF(retval);
    upcri_strict_rmb(retval && (handle != UPCR_INVALID_HANDLE));
  });
  #undef UPCRI_PEVT_ARGS
  return retval;
}
#define upcr_try_syncnb_strict(handle) \
       (upcri_srcpos(), _upcr_try_syncnb_strict(handle UPCRI_PT_PASS))

/* Multiple operation explicit synchronization 
 *
 * Synchronize on the completion of an array of non-blocking operation handles
 * (all of which were initiated by this thread). 
 *
 * 'numhandles' specifies the number of handles in the provided array of
 * handles, and this number must be > 0. 
 *
 * upcr_wait_syncnb_all() blocks until all the specified operations have
 * completed (or returns immediately if they have all already completed). 
 *
 * upcr_try_syncnb_all() always returns immediately, with the value 1 if all
 * the specified operations have completed, or 0 if one or more of the
 * operations is not yet complete and future synchronization is necessary to
 * complete some of the operations.
 *
 * upcr_try_syncnb_all() will modify the provided array to reflect
 * completions: handles whose operations have completed are overwritten with
 * the value UPCR_INVALID_HANDLE, and the client may test against this value
 * when upcr_try_syncnb_all() returns 0 to determine which operations are
 * complete and which are still pending.
 *
 * Implementations of upcr_wait_syncnb_all() _may_ modify the provided array
 * to reflect completions, but this is not required (and is not needed by
 * the client since it always blocks until all operations in the list are
 * complete).
 *
 * It is legal to pass the value UPCR_INVALID_HANDLE in some or all of the
 * array entries, and both functions will ignore them so those values have no
 * effect on behavior.  If all entries in the array are UPCR_INVALID_HANDLE
 * (or numhandles==0), then upcr_try_syncnb_all() will return 1.
 *
 * Note that there are no strict variants, since the UPC memory consistency
 * model prevents multiple outstanding strict operations.
 */

GASNETT_INLINE(_upcr_wait_syncnb_all)
void 
_upcr_wait_syncnb_all(upcr_handle_t *phandles, size_t numhandles)
{
    gasnet_wait_syncnb_all(phandles, numhandles);
}
#define upcr_wait_syncnb_all(handle) \
       (upcri_srcpos(), _upcr_wait_syncnb_all(handle))

GASNETT_INLINE(_upcr_try_syncnb_all)
int
_upcr_try_syncnb_all(upcr_handle_t *phandles, size_t numhandles)
{
    return (gasnet_try_syncnb_all(phandles, numhandles) == GASNET_OK);
}
#define upcr_try_syncnb_all(handle) \
       (upcri_srcpos(), _upcr_try_syncnb_all(handle))

/* 
 * These operate analogously to the syncnb_all variants, except they only
 * wait/test for at least one operation corresponding to a _valid_ handle in
 * the provided list to be complete (the valid handles values are all those
 * which are not UPCR_INVALID_HANDLE). 
 *
 * Specifically, upcr_wait_syncnb_some() will block until at least one of the
 * valid handles in the list has completed, and indicate the operations that
 * have completed by setting the corresponding handles to the value
 * UPCR_INVALID_HANDLE. 
 *
 * Similarly, upcr_try_syncnb_some will check if at least one valid handle in
 * the list has completed (setting all completed handles to
 * UPCR_INVALID_HANDLE) and return 1 if it detected at least one completion or
 * 0 otherwise (except as below).
 *
 * Both functions ignore UPCR_INVALID_HANDLE values. If the input list is
 * empty or consists only of UPCR_INVALID_HANDLE values, upcr_wait_syncnb_some
 * will return immediately and upcr_try_sync_some will return 1.
*/

GASNETT_INLINE(_upcr_wait_syncnb_some)
void 
_upcr_wait_syncnb_some(upcr_handle_t *phandles, size_t numhandles)
{
    gasnet_wait_syncnb_some(phandles, numhandles);
}
#define upcr_wait_syncnb_some(handle) \
       (upcri_srcpos(), _upcr_wait_syncnb_some(handle))

GASNETT_INLINE(_upcr_try_syncnb_some)
int
_upcr_try_syncnb_some(upcr_handle_t *phandles, size_t numhandles)
{
    return (gasnet_try_syncnb_some(phandles, numhandles) == GASNET_OK);
}
#define upcr_try_syncnb_some(handle) \
       (upcri_srcpos(), _upcr_try_syncnb_some(handle))


/* --- Non-blocking memory-to-memory, implicit handle (nbi) ---
 *
 * These calls initiate a non-blocking operation and return "immediately".
 * The operation must later be completed using a call to one of the implicit
 * sync functions.
 *
 * Once the put version returns, the source memory may safely be overwritten.
 *
 * For a get operation, if the contents of the source memory change while the
 * operation is in progress the result will be implementation-specific.
 *
 * The contents of the destination memory address are undefined until a
 * synchronization completes successfully for the non-blocking operation. 
 *
 * There are no strict nbi operations, as the UPC memory consistency model
 * prohibits multiple outstanding strict operations.
 */
#define upcr_put_nbi_shared(dest, destoffset, src, nbytes) \
       (upcri_srcpos(), _upcr_put_nbi_shared(dest, destoffset, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_nbi_shared)
void 
_upcr_put_nbi_shared(upcr_shared_ptr_t dest, ptrdiff_t destoffset, const void *src, 
		     size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dest);
    (void) upcri_checkvalid_nonnull_shared(dest);
    #define UPCRI_PEVT_ARGS , 1, &UPCRI_PEVT_PTMP, src, nbytes, GASP_UPC_NBI_TRIVIAL
    if (local) upcri_pevt_putnb_local(s,{
	UPCRI_TRACE_PUT(PUT_NBI_LOCAL, gasnet_mynode(),
			upcri_s2localoff(local, dest, destoffset),
			src, nbytes);
	UPCRI_ALIGNED_MEMCPY(upcri_s2localoff(local, dest, destoffset),
			     src, nbytes);
    }); else upcri_pevt_putnb(s,{
	gasnet_put_nbi(upcri_s_nodeof(dest),
		       upcri_shared_to_remote_off(dest, destoffset), (void *)src, nbytes);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_get_nbi_shared(dest, src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_nbi_shared(dest, src, srcoffset, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_nbi_shared)
void 
_upcr_get_nbi_shared(void *dest, upcr_shared_ptr_t src, ptrdiff_t srcoffset, 
		     size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(src);
    (void) upcri_checkvalid_nonnull_shared(src);
    #define UPCRI_PEVT_ARGS , 1, dest, &UPCRI_PEVT_PTMP, nbytes, GASP_UPC_NBI_TRIVIAL
    if (local) upcri_pevt_getnb_local(s,{
	UPCRI_TRACE_GET(GET_NBI_LOCAL, dest, gasnet_mynode(),
			upcri_s2localoff(local, src, srcoffset), nbytes);
	UPCRI_ALIGNED_MEMCPY(dest, upcri_s2localoff(local, src, srcoffset),
			     nbytes);
    }); else upcri_pevt_getnb(s,{
	gasnet_get_nbi(dest, upcri_s_nodeof(src),
		       upcri_shared_to_remote_off(src, srcoffset), nbytes);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_put_nbi_pshared(dest, destoffset, src, nbytes) \
       (upcri_srcpos(), _upcr_put_nbi_pshared(dest, destoffset, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_nbi_pshared)
void 
_upcr_put_nbi_pshared(upcr_pshared_ptr_t dest, ptrdiff_t destoffset, const void *src, 
		      size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(dest);
    (void) upcri_checkvalid_nonnull_pshared(dest);
    #define UPCRI_PEVT_ARGS , 1, &UPCRI_PEVT_PTMP, src, nbytes, GASP_UPC_NBI_TRIVIAL
    if (local) upcri_pevt_putnb_local(p,{
	UPCRI_TRACE_PUT(PUT_NBI_LOCAL, gasnet_mynode(),
			upcri_p2localoff(local, dest, destoffset),
			src, nbytes);
	UPCRI_ALIGNED_MEMCPY(upcri_p2localoff(local, dest, destoffset),
			     src, nbytes);
    }); else upcri_pevt_putnb(p,{
	gasnet_put_nbi(upcri_p_nodeof(dest),
		       upcri_pshared_to_remote_off(dest, destoffset), (void *)src, nbytes);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_get_nbi_pshared(dest, src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_nbi_pshared(dest, src, srcoffset, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_nbi_pshared)
void 
_upcr_get_nbi_pshared(void *dest, upcr_pshared_ptr_t src, ptrdiff_t srcoffset, 
		      size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(src);
    (void) upcri_checkvalid_nonnull_pshared(src);
    #define UPCRI_PEVT_ARGS , 1, dest, &UPCRI_PEVT_PTMP, nbytes, GASP_UPC_NBI_TRIVIAL
    if (local) upcri_pevt_getnb_local(p,{
	UPCRI_TRACE_GET(GET_NBI_LOCAL, dest, gasnet_mynode(),
			upcri_p2localoff(local, src, srcoffset), nbytes);
	UPCRI_ALIGNED_MEMCPY(dest, upcri_p2localoff(local, src, srcoffset),
			     nbytes);
    }); else upcri_pevt_getnb(p,{
	gasnet_get_nbi(dest, upcri_p_nodeof(src),
		       upcri_pshared_to_remote_off(src, srcoffset), nbytes);
    });
    #undef UPCRI_PEVT_ARGS
}

/* --- Implicit handle synchronization (for get_nbi and put_nbi) --- */

/* Synchronize on an implicit list of outstanding non-blocking operations.
 *
 * These functions implicitly specify a one of the following sets of
 * non-blocking operations on which to synchronize - 
 *
 *   1) All outstanding implicit-handle gets initiated by this thread, 
 *   2) All outstanding implicit-handle puts initiated by this thread, or
 *   3) All outstanding implicit-handle operations (both puts and gets)
 *      initiated by this thread (where outstanding is defined as all those
 *      operations which have been initiated but not yet completed through a
 *      successful implicit-handle synchronization). 
 *
 * The wait variants block until all operations in this implicit set have
 * completed.  The try variants test whether all operations in the implicit
 * set have completed, and return 1 if so (or if there are no outstanding
 * implicit-handle operations) or 0 otherwise.
 *
 * Implicit synchronization functions will synchronize operations initiated
 * within other function frames by this thread.
 *
 * As with the initiation functions, there are no strict variants here.
 */

#define upcr_wait_syncnbi_gets() (upcri_srcpos(), _upcr_wait_syncnbi_gets(UPCRI_PT_PASS_ALONE))

GASNETT_INLINE(_upcr_wait_syncnbi_gets)
void _upcr_wait_syncnbi_gets(UPCRI_PT_ARG_ALONE) {
  UPCRI_PASS_GAS();
  #define UPCRI_PEVT_ARGS , GASP_UPC_NBI_TRIVIAL
  upcri_pevt(GASP_UPC_NB_SYNC,{},{
    gasnet_wait_syncnbi_gets();
  });
  #undef UPCRI_PEVT_ARGS
}

#define upcr_wait_syncnbi_puts() (upcri_srcpos(), _upcr_wait_syncnbi_puts(UPCRI_PT_PASS_ALONE))

GASNETT_INLINE(_upcr_wait_syncnbi_puts)
void _upcr_wait_syncnbi_puts(UPCRI_PT_ARG_ALONE) {
  UPCRI_PASS_GAS();
  #define UPCRI_PEVT_ARGS , GASP_UPC_NBI_TRIVIAL
  upcri_pevt(GASP_UPC_NB_SYNC,{},{
    gasnet_wait_syncnbi_puts();
  });
  #undef UPCRI_PEVT_ARGS
}

#define upcr_wait_syncnbi_all() (upcri_srcpos(), _upcr_wait_syncnbi_all(UPCRI_PT_PASS_ALONE))

GASNETT_INLINE(_upcr_wait_syncnbi_all)
void _upcr_wait_syncnbi_all(UPCRI_PT_ARG_ALONE) {
  UPCRI_PASS_GAS();
  #define UPCRI_PEVT_ARGS , GASP_UPC_NBI_TRIVIAL
  upcri_pevt(GASP_UPC_NB_SYNC,{},{
    gasnet_wait_syncnbi_all();
  });
  #undef UPCRI_PEVT_ARGS
}

#define upcr_try_syncnbi_gets() (upcri_srcpos(), _upcr_try_syncnbi_gets(UPCRI_PT_PASS_ALONE))

GASNETT_INLINE(_upcr_try_syncnbi_gets)
int _upcr_try_syncnbi_gets(UPCRI_PT_ARG_ALONE) {
  UPCRI_PASS_GAS();
  int result = 0;
  #define UPCRI_PEVT_ARGS , GASP_UPC_NBI_TRIVIAL, result
  upcri_pevt(GASP_BUPC_NB_TRYSYNC,{},{
    result = (gasnet_try_syncnbi_gets() == GASNET_OK);
  });
  #undef UPCRI_PEVT_ARGS
  return result;
}

#define upcr_try_syncnbi_puts() (upcri_srcpos(), _upcr_try_syncnbi_puts(UPCRI_PT_PASS_ALONE))

GASNETT_INLINE(_upcr_try_syncnbi_puts)
int _upcr_try_syncnbi_puts(UPCRI_PT_ARG_ALONE) {
  UPCRI_PASS_GAS();
  int result = 0;
  #define UPCRI_PEVT_ARGS , GASP_UPC_NBI_TRIVIAL, result
  upcri_pevt(GASP_BUPC_NB_TRYSYNC,{},{
    result = (gasnet_try_syncnbi_puts() == GASNET_OK);
  });
  #undef UPCRI_PEVT_ARGS
  return result;
}

#define upcr_try_syncnbi_all() (upcri_srcpos(), _upcr_try_syncnbi_all(UPCRI_PT_PASS_ALONE))

GASNETT_INLINE(_upcr_try_syncnbi_all)
int _upcr_try_syncnbi_all(UPCRI_PT_ARG_ALONE) {
  UPCRI_PASS_GAS();
  int result = 0;
  #define UPCRI_PEVT_ARGS , GASP_UPC_NBI_TRIVIAL, result
  upcri_pevt(GASP_BUPC_NB_TRYSYNC,{},{
    result = (gasnet_try_syncnbi_all() == GASNET_OK);
  });
  #undef UPCRI_PEVT_ARGS
  return result;
}

/* --- Implicit region synchronization --- */

/* 
 * In some cases, it may be useful or desirable to initiate a number of
 * non-blocking shared-memory operations (possibly without knowing how many at
 * compile-time) and synchronize them at a later time using a single, fast
 * synchronization.
 *
 * Simple implicit handle synchronization may not be appropriate for this
 * situation if there are intervening implicit accesses which are not to be
 * synchronized.
 *
 * This situation could be handled using explicit-handle non-blocking
 * operations and a list synchronization (e.g. upcr_wait_syncnb_all()), but
 * this may not be desirable because it requires managing an array of handles
 * (which could have negative cache effects on performance, or could be
 * expensive to allocate when the size is not known until runtime).
 *
 * To handle these cases, we provide "implicit access region" synchronization,
 * described below.
 */

/* 
 * upcr_begin_nbi_accessregion() and upcr_end_nbi_accessregion() are used to
 * define an implicit access region (any code which dynamically executes
 * between the begin and end calls is said to be "inside" the region).  
 *
 * The begin and end calls must be paired, and may not be nested recursively
 * or the results are undefined.  It is erroneous to call any implicit-handle
 * synchronization function within the region.
 *
 * All implicit-handle non-blocking operations initiated inside the region
 * become "associated" with the abstract region handle being constructed.
 * upcr_end_nbi_accessregion() returns an explicit handle which collectively
 * represents all the associated implicit-handle operations (those initiated
 * within the region). 
 *
 * This handle can then be passed to the regular explicit-handle
 * synchronization functions, and will be successfully synchronized when all
 * of the associated non-blocking operations initiated in the region have
 * completed. 
 *
 * The associated operations cease to be implicit-handle operations, and are
 * _not_ synchronized by subsequent calls to the implicit-handle
 * synchronization functions (e.g. upcr_wait_syncnbi_all()).
 *
 * Explicit-handle operations initiated within the region operate as usual and
 * do _not_ become associated with the region.
 */
#define upcr_begin_nbi_accessregion() \
       (upcri_srcpos(), _upcr_begin_nbi_accessregion(UPCRI_PT_PASS_ALONE))

GASNETT_INLINE(_upcr_begin_nbi_accessregion)
void
_upcr_begin_nbi_accessregion(UPCRI_PT_ARG_ALONE)
{
    UPCRI_PASS_GAS();
    gasnet_begin_nbi_accessregion();
}

#define upcr_end_nbi_accessregion() \
       (upcri_srcpos(), _upcr_end_nbi_accessregion(UPCRI_PT_PASS_ALONE))

GASNETT_INLINE(_upcr_end_nbi_accessregion) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t 
_upcr_end_nbi_accessregion(UPCRI_PT_ARG_ALONE)
{
    UPCRI_PASS_GAS();
    return gasnet_end_nbi_accessregion();
}

/* sample code:
 *
 *  upcr_begin_nbi_accessregion();  // begin the region
 *
 *  upcr_put_nbi_shared(...);	    // becomes associated with this region
 *  while (...) {
 *	upcr_put_nbi_shared(...);   // becomes associated with this region
 *  }
 *
 *  // unrelated explicit-handle operation not associated with region
 *  h2 = upcr_get_nb_shared(...); 
 *  upcr_wait_syncnb(h2);
 *
 *  handle = upcr_end_nbi_accessregion(); // end the region and get the handle
 *
 *  .... // other code, which may include unrelated implicit-handle
 *	 // operations+syncs, or other regions, etc.
 *
 *  upcr_wait_syncnb(handle);	    // wait for all the operations associated 
 *				    // with the region to complete
 */

/* --- Register-memory operations --- */

/* 
 * upcr_register_value_t represents the largest unsigned integer type that can
 * fit entirely in a single CPU register for the current architecture and ABI. 
 *
 * SIZEOF_UPCR_REGISTER_T is a preprocess-time literal integer constant (i.e.
 * not "sizeof()") indicating the size of this type in bytes
 */
typedef gasnet_register_value_t upcr_register_value_t;
#define SIZEOF_UPCR_REGISTER_VALUE_T SIZEOF_GASNET_REGISTER_VALUE_T

/* Helper for local gets */
GASNETT_INLINE(upcri_get_value)
upcr_register_value_t
upcri_get_value(void *src, size_t nbytes) {
  UPCRI_VALUE_RETURN(src, nbytes);
}

/* 
 * Value forms of put - these take the value to be put as input parameter to
 * avoid forcing outgoing values to local memory in generated code.
 * Otherwise, the behavior is identical to the memory-to-memory versions of
 * put above.
 *
 * Requires: nbytes > 0 && nbytes <= SIZEOF_UPCR_REGISTER_VALUE_T.
 *
 * The value written to the target address is a direct byte copy of the
 * 8*nbytes low-order bits of value, written with the endianness appropriate
 * for an nbyte integral value on the current architecture.
 *
 * The non-blocking forms of value put must be synchronized using the explicit
 * or implicit synchronization functions defined above, as appropriate.
 *
 * The semantics of the _strict versions are the same as for the regular,
 * non-value put/get functions
 */
#define upcr_put_shared_val(dest, destoffset, value, nbytes) \
       (upcri_srcpos(), _upcr_put_shared_val(dest, destoffset, value, nbytes, 0 UPCRI_PT_PASS))
#define upcr_put_shared_val_strict(dest, destoffset, value, nbytes) \
       (upcri_srcpos(), _upcr_put_shared_val(dest, destoffset, value, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_shared_val)
void
_upcr_put_shared_val(upcr_shared_ptr_t dest, ptrdiff_t destoffset, 
		     upcr_register_value_t value, size_t nbytes, 
		     int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dest);
    (void) upcri_checkvalid_nonnull_shared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, &value, nbytes
    if (local) upcri_pevt_put_local(s,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_VAL_LOCAL, gasnet_mynode(),
			upcri_s2localoff(local, dest, destoffset),
			&value, nbytes);
	UPCRI_VALUE_ASSIGN(upcri_s2localoff(local, dest, destoffset),
			     value, nbytes);
	upcri_strict_mb(isstrict);
    }); else upcri_pevt_put(s,{
        upcri_strict_wmb(isstrict);
	gasnet_put_val(upcri_s_nodeof(dest),
		       upcri_shared_to_remote_off(dest, destoffset),
		       value, nbytes);
	upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_put_nb_shared_val(dest, destoffset, value, nbytes) \
       (upcri_srcpos(), _upcr_put_nb_shared_val(dest, destoffset, value, nbytes, 0 UPCRI_PT_PASS))
#define upcr_put_nb_shared_val_strict(dest, destoffset, value, nbytes) \
       (upcri_srcpos(), _upcr_put_nb_shared_val(dest, destoffset, value, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_nb_shared_val) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t
_upcr_put_nb_shared_val(upcr_shared_ptr_t dest, ptrdiff_t destoffset, 
			upcr_register_value_t value, size_t nbytes, 
			int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcr_handle_t h = UPCR_INVALID_HANDLE;
    upcri_local_t local = upcri_s_islocal(dest);
    (void) upcri_checkvalid_nonnull_shared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, &value, nbytes, (h==UPCR_INVALID_HANDLE?GASP_UPC_NB_TRIVIAL:h)
    if (local) upcri_pevt_putnb_local(s,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_NB_VAL_LOCAL, gasnet_mynode(),
			upcri_s2localoff(local, dest, destoffset),
			&value, nbytes);
	UPCRI_VALUE_ASSIGN(upcri_s2localoff(local, dest, destoffset),
			     value, nbytes);
	upcri_strict_mb(isstrict);
	h = UPCR_INVALID_HANDLE;
    }); else upcri_pevt_putnb(s,{
        upcri_strict_wmb(isstrict);
	h = gasnet_put_nb_val(upcri_s_nodeof(dest),
				    upcri_shared_to_remote_off(dest, destoffset),
				    value, nbytes);
	if_pf (h == UPCR_INVALID_HANDLE)
	    upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return h;
}

#define upcr_put_nbi_shared_val(dest, destoffset, value, nbytes) \
       (upcri_srcpos(), _upcr_put_nbi_shared_val(dest, destoffset, value, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_nbi_shared_val)
void
_upcr_put_nbi_shared_val(upcr_shared_ptr_t dest, ptrdiff_t destoffset, 
			 upcr_register_value_t value, size_t nbytes
			 UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dest);
    (void) upcri_checkvalid_nonnull_shared(dest);
    #define UPCRI_PEVT_ARGS , 1, &UPCRI_PEVT_PTMP, &value, nbytes, GASP_UPC_NBI_TRIVIAL
    if (local) upcri_pevt_putnb_local(s,{
	UPCRI_TRACE_PUT(PUT_NBI_VAL_LOCAL, gasnet_mynode(),
			upcri_s2localoff(local, dest, destoffset),
			&value, nbytes);
	UPCRI_VALUE_ASSIGN(upcri_s2localoff(local, dest, destoffset),
			     value, nbytes);
    }); else upcri_pevt_putnb(s,{
	gasnet_put_nbi_val(upcri_s_nodeof(dest),
			   upcri_shared_to_remote_off(dest, destoffset),
			   value, nbytes);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_put_pshared_val(dest, destoffset, value, nbytes) \
       (upcri_srcpos(), _upcr_put_pshared_val(dest, destoffset, value, nbytes, 0 UPCRI_PT_PASS))
#define upcr_put_pshared_val_strict(dest, destoffset, value, nbytes) \
       (upcri_srcpos(), _upcr_put_pshared_val(dest, destoffset, value, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_pshared_val)
void
_upcr_put_pshared_val(upcr_pshared_ptr_t dest, ptrdiff_t destoffset, 
		      upcr_register_value_t value, size_t nbytes, 
		      int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(dest);
    (void) upcri_checkvalid_nonnull_pshared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, &value, nbytes
    if (local) upcri_pevt_put_local(p,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_VAL_LOCAL, gasnet_mynode(),
			upcri_p2localoff(local, dest, destoffset),
			&value, nbytes);
	UPCRI_VALUE_ASSIGN(upcri_p2localoff(local, dest, destoffset),
			     value, nbytes);
	upcri_strict_mb(isstrict);
    }); else upcri_pevt_put(p,{
        upcri_strict_wmb(isstrict);
	gasnet_put_val(upcri_p_nodeof(dest),
		       upcri_pshared_to_remote_off(dest, destoffset), 
		       value, nbytes);
	upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_put_nb_pshared_val(dest, destoffset, value, nbytes) \
       (upcri_srcpos(), _upcr_put_nb_pshared_val(dest, destoffset, value, nbytes, 0 UPCRI_PT_PASS))
#define upcr_put_nb_pshared_val_strict(dest, destoffset, value, nbytes) \
       (upcri_srcpos(), _upcr_put_nb_pshared_val(dest, destoffset, value, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_nb_pshared_val) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t 
_upcr_put_nb_pshared_val(upcr_pshared_ptr_t dest, ptrdiff_t destoffset, 
			 upcr_register_value_t value, size_t nbytes, 
			 int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcr_handle_t h = UPCR_INVALID_HANDLE;
    upcri_local_t local = upcri_p_islocal(dest);
    (void) upcri_checkvalid_nonnull_pshared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, &value, nbytes, (h==UPCR_INVALID_HANDLE?GASP_UPC_NB_TRIVIAL:h)
    if (local) upcri_pevt_putnb_local(p,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_NB_VAL_LOCAL, gasnet_mynode(),
			upcri_p2localoff(local, dest, destoffset),
			&value, nbytes);
	UPCRI_VALUE_ASSIGN(upcri_p2localoff(local, dest, destoffset),
			     value, nbytes);
	upcri_strict_mb(isstrict);
	h = UPCR_INVALID_HANDLE;
    }); else upcri_pevt_putnb(p,{
        upcri_strict_wmb(isstrict);
	h = gasnet_put_nb_val(upcri_p_nodeof(dest),
				    upcri_pshared_to_remote_off(dest, destoffset),
				    value, nbytes);
	if_pf (h == UPCR_INVALID_HANDLE)
	    upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return h;
}

#define upcr_put_nbi_pshared_val(dest, destoffset, value, nbytes) \
       (upcri_srcpos(), _upcr_put_nbi_pshared_val(dest, destoffset, value, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_nbi_pshared_val)
void
_upcr_put_nbi_pshared_val(upcr_pshared_ptr_t dest, ptrdiff_t destoffset, 
			  upcr_register_value_t value, size_t nbytes 
			  UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(dest);
    (void) upcri_checkvalid_nonnull_pshared(dest);
    #define UPCRI_PEVT_ARGS , 1, &UPCRI_PEVT_PTMP, &value, nbytes, GASP_UPC_NBI_TRIVIAL
    if (local) upcri_pevt_putnb_local(p,{
	UPCRI_TRACE_PUT(PUT_NBI_VAL_LOCAL, gasnet_mynode(),
			upcri_p2localoff(local, dest, destoffset),
			&value, nbytes);
	UPCRI_VALUE_ASSIGN(upcri_p2localoff(local, dest, destoffset),
			     value, nbytes);
    }); else upcri_pevt_putnb(p,{
	gasnet_put_nbi_val(upcri_p_nodeof(dest),
			   upcri_pshared_to_remote_off(dest, destoffset),
			   value, nbytes);
    });
    #undef UPCRI_PEVT_ARGS
}


/* Blocking value get - these return the fetched value to avoid forcing
 * incoming values to local memory in generated code.  Otherwise, the behavior
 * is identical to the memory-to-memory blocking get.
 *
 * Requires: nbytes > 0 && nbytes <= SIZEOF_UPCR_REGISTER_VALUE_T.
 *
 * The value returned is the one obtained by reading the nbytes bytes starting
 * at the source address with the endianness appropriate for an nbyte integral
 * value on the current architecture and setting the high-order bits (if any)
 * to zero (i.e. no sign-extension).
 *
 * The semantics of the _strict versions are the same as for the regular,
 * non-value put/get functions
 */
#define upcr_get_shared_val(src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_shared_val(src, srcoffset, nbytes, 0 UPCRI_PT_PASS))
#define upcr_get_shared_val_strict(src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_shared_val(src, srcoffset, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_shared_val)
upcr_register_value_t 
_upcr_get_shared_val(upcr_shared_ptr_t src, ptrdiff_t srcoffset, 
		     size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcr_register_value_t retval;
    upcri_local_t local = upcri_s_islocal(src);
    (void) upcri_checkvalid_nonnull_shared(src);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &retval, &UPCRI_PEVT_PTMP, nbytes
    if (local) upcri_pevt_get_local(s,{
	UPCRI_TRACE_GET(GET_VAL_LOCAL, NULL, gasnet_mynode(),
			upcri_s2localoff(local, src, srcoffset), nbytes);
	upcri_strict_mb(isstrict);
	retval = upcri_get_value(upcri_s2localoff(local, src, srcoffset), nbytes);
        upcri_strict_rmb(isstrict);
    }); else upcri_pevt_get(s,{
	upcri_strict_wmb(isstrict);
	retval = gasnet_get_val(upcri_s_nodeof(src),
				upcri_shared_to_remote_off(src, srcoffset), nbytes);
        upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return retval;
}

#define upcr_get_pshared_val(src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_pshared_val(src, srcoffset, nbytes, 0 UPCRI_PT_PASS))
#define upcr_get_pshared_val_strict(src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_pshared_val(src, srcoffset, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_pshared_val)
upcr_register_value_t 
_upcr_get_pshared_val(upcr_pshared_ptr_t src, ptrdiff_t srcoffset, 
		      size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(src);
    upcr_register_value_t retval;
    (void) upcri_checkvalid_nonnull_pshared(src);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &retval, &UPCRI_PEVT_PTMP, nbytes
    if (local) upcri_pevt_get_local(p,{
	UPCRI_TRACE_GET(GET_VAL_LOCAL, NULL, gasnet_mynode(),
			upcri_p2localoff(local, src, srcoffset), nbytes);
	upcri_strict_mb(isstrict);
	retval = upcri_get_value(upcri_p2localoff(local, src, srcoffset), nbytes);
        upcri_strict_rmb(isstrict);
    }); else upcri_pevt_get(p,{
	upcri_strict_wmb(isstrict);
	retval = gasnet_get_val(upcri_p_nodeof(src),
				upcri_pshared_to_remote_off(src, srcoffset), nbytes);
        upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return retval;
}

/* Non-blocking value get - useful for NIC's that can target register-like
 * storage such as T3E's eregisters or Quadric's memory-mapped NIC FIFO's
 *
 * These operate similarly to the blocking form of value get, but are
 * split-phase.
 *
 * upcr_get_nb_(p)shared_val initiates a non-blocking value get and returns an
 * explicit handle which MUST be synchronized using upcr_wait_syncnb_valget().
 *
 * upcr_wait_syncnb_valget() synchronizes an outstanding get_nb_val operation
 * and returns the retrieved value as described for the blocking version.
 *
 * Note that upcr_valget_handle_t and upcr_handle_t are completely different
 * datatypes and may not be intermixed (i.e. upcr_valget_handle_t's cannot be
 * used with other explicit synchronization functions, and upcr_handle_t's
 * cannot be passed to upcr_wait_syncnb_valget().
 *
 * There is no try variant of value get synchronization, and no "nbi" variant.
 *
 * Implementors are recommended to make sizeof(upcr_valget_handle_t) <=
 * sizeof(upcr_register_value_t) to facilitate register reuse.
*/

typedef gasnet_valget_handle_t upcr_valget_handle_t;

#if 0 /* XXX: These are missing loopback implementations and membars for strict ops */

#define upcr_get_nb_shared_val(src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_nb_shared_val(src, srcoffset, nbytes, 0 UPCRI_PT_PASS))
#define upcr_get_nb_shared_val_strict(src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_nb_shared_val(src, srcoffset, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_nb_shared_val)
upcr_valget_handle_t 
_upcr_get_nb_shared_val(upcr_shared_ptr_t src, ptrdiff_t srcoffset, 
			size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    (void) upcri_checkvalid_nonnull_shared(src);
    UPCRI_TRACE_STRICT(isstrict);
    return gasnet_get_nb_val(upcri_s_nodeof(src),
			     upcri_shared_to_remote_off(src, srcoffset),
			     nbytes);
}

#define upcr_get_nb_pshared_val(src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_nb_pshared_val(src, srcoffset, nbytes, 0 UPCRI_PT_PASS))
#define upcr_get_nb_pshared_val_strict(src, srcoffset, nbytes) \
       (upcri_srcpos(), _upcr_get_nb_pshared_val(src, srcoffset, nbytes, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_nb_pshared_val)
upcr_valget_handle_t 
_upcr_get_nb_pshared_val(upcr_pshared_ptr_t src, ptrdiff_t srcoffset, 
			size_t nbytes, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    (void) upcri_checkvalid_nonnull_pshared(src);
    UPCRI_TRACE_STRICT(isstrict);
    return gasnet_get_nb_val(upcri_p_nodeof(src),
			     upcri_pshared_to_remote_off(src, srcoffset),
			     nbytes);
}

GASNETT_INLINE(upcr_wait_syncnb_valget)
upcr_register_value_t 
upcr_wait_syncnb_valget(upcr_valget_handle_t handle)
{
    return gasnet_wait_syncnb_valget(handle);
}
#endif


/* Blocking value puts/gets for floating-point quantities (float, double).
 *
 * These operate similarly to the blocking value puts/get for integral types,
 * except are specialized for the float and double types on the current
 * platform.
 *
 * The source/target address is assumed to be correctly aligned for accessing
 * the given FP type.  The primary motivation is to permit puts/gets directly
 * between local shared memory locations and the floating point registers,
 * without forcing the use of an integer register or stack temporary as an
 * intermediary (which would be otherwise necessary without these functions).
 *
 * There are no non-blocking variants for these functions because they are
 * meant primarily for optimizing low-latency local memory accesses.
 */
#define upcr_put_shared_floatval(dest, destoffset, value) \
       (upcri_srcpos(), _upcr_put_shared_floatval(dest, destoffset, value, 0 UPCRI_PT_PASS))
#define upcr_put_shared_floatval_strict(dest, destoffset, value) \
       (upcri_srcpos(), _upcr_put_shared_floatval(dest, destoffset, value, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_shared_floatval)
void
_upcr_put_shared_floatval(upcr_shared_ptr_t dest, ptrdiff_t destoffset, 
			  float value, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dest);
    (void) upcri_checkvalid_nonnull_shared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, &value, sizeof(float)
    if (local) upcri_pevt_put_local(s,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_VAL_LOCAL, gasnet_mynode(),
			upcri_s2localoff(local, dest, destoffset),
			&value, sizeof(float));
	*(float*)(upcri_s2localoff(local, dest, destoffset)) = value;
	upcri_strict_mb(isstrict);
    }); else upcri_pevt_put(s,{
        upcri_strict_wmb(isstrict);
	gasnet_put(upcri_s_nodeof(dest),
		   upcri_shared_to_remote_off(dest, destoffset), 
		   &value, sizeof(float));
	upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_put_shared_doubleval(dest, destoffset, value) \
       (upcri_srcpos(), _upcr_put_shared_doubleval(dest, destoffset, value, 0 UPCRI_PT_PASS))
#define upcr_put_shared_doubleval_strict(dest, destoffset, value) \
       (upcri_srcpos(), _upcr_put_shared_doubleval(dest, destoffset, value, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_shared_doubleval)
void
_upcr_put_shared_doubleval(upcr_shared_ptr_t dest, ptrdiff_t destoffset, 
			   double value, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dest);
    (void) upcri_checkvalid_nonnull_shared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, &value, sizeof(double)
    if (local) upcri_pevt_put_local(s,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_VAL_LOCAL, gasnet_mynode(),
			upcri_s2localoff(local, dest, destoffset),
			&value, sizeof(double));
	*(double*)(upcri_s2localoff(local, dest, destoffset)) = value;
	upcri_strict_mb(isstrict);
    }); else upcri_pevt_put(s,{
        upcri_strict_wmb(isstrict);
	gasnet_put(upcri_s_nodeof(dest),
		   upcri_shared_to_remote_off(dest, destoffset), 
		   &value, sizeof(double));
	upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_get_shared_floatval(src, srcoffset) \
       (upcri_srcpos(), _upcr_get_shared_floatval(src, srcoffset, 0 UPCRI_PT_PASS))
#define upcr_get_shared_floatval_strict(src, srcoffset) \
       (upcri_srcpos(), _upcr_get_shared_floatval(src, srcoffset, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_shared_floatval)
float
_upcr_get_shared_floatval(upcr_shared_ptr_t src, ptrdiff_t srcoffset, 
			  int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(src);
    float retval;
    (void) upcri_checkvalid_nonnull_shared(src);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &retval, &UPCRI_PEVT_PTMP, sizeof(float)
    if (local) upcri_pevt_get_local(s,{
	UPCRI_TRACE_GET(GET_VAL_LOCAL, NULL, gasnet_mynode(),
			upcri_s2localoff(local, src, srcoffset), sizeof(float));
	upcri_strict_mb(isstrict);
	retval = *(float*)(upcri_s2localoff(local, src, srcoffset));
        upcri_strict_rmb(isstrict);
    }); else upcri_pevt_get(s,{
	float tmp; /* TODO: try to eliminate this stack temporary */
	upcri_strict_wmb(isstrict);
	gasnet_get(&tmp, upcri_s_nodeof(src),
		   upcri_shared_to_remote_off(src, srcoffset), sizeof(float));
	retval = tmp;
        upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return retval;
}

#define upcr_get_shared_doubleval(src, srcoffset) \
       (upcri_srcpos(), _upcr_get_shared_doubleval(src, srcoffset, 0 UPCRI_PT_PASS))
#define upcr_get_shared_doubleval_strict(src, srcoffset) \
       (upcri_srcpos(), _upcr_get_shared_doubleval(src, srcoffset, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_shared_doubleval)
double 
_upcr_get_shared_doubleval(upcr_shared_ptr_t src, ptrdiff_t srcoffset, 
			   int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(src);
    double retval;
    (void) upcri_checkvalid_nonnull_shared(src);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &retval, &UPCRI_PEVT_PTMP, sizeof(double)
    if (local) upcri_pevt_get_local(s,{
	UPCRI_TRACE_GET(GET_VAL_LOCAL, NULL, gasnet_mynode(),
			upcri_s2localoff(local, src, srcoffset), sizeof(double));
	upcri_strict_mb(isstrict);
	retval = *(double*)(upcri_s2localoff(local, src, srcoffset));
        upcri_strict_rmb(isstrict);
    }); else upcri_pevt_get(s,{
	double tmp; /* TODO: try to eliminate this stack temporary */
	upcri_strict_wmb(isstrict);
	gasnet_get(&tmp, upcri_s_nodeof(src),
		   upcri_shared_to_remote_off(src, srcoffset), sizeof(double));
	retval = tmp;
        upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return retval;
}

#define upcr_put_pshared_floatval(dest, destoffset, value) \
       (upcri_srcpos(), _upcr_put_pshared_floatval(dest, destoffset, value, 0 UPCRI_PT_PASS))
#define upcr_put_pshared_floatval_strict(dest, destoffset, value) \
       (upcri_srcpos(), _upcr_put_pshared_floatval(dest, destoffset, value, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_pshared_floatval)
void
_upcr_put_pshared_floatval(upcr_pshared_ptr_t dest, ptrdiff_t destoffset, 
			   float value, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(dest);
    (void) upcri_checkvalid_nonnull_pshared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, &value, sizeof(float)
    if (local) upcri_pevt_put_local(p,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_VAL_LOCAL, gasnet_mynode(),
			upcri_p2localoff(local, dest, destoffset),
			&value, sizeof(float));
	*(float*)(upcri_p2localoff(local, dest, destoffset)) = value;
	upcri_strict_mb(isstrict);
    }); else upcri_pevt_put(p,{
        upcri_strict_wmb(isstrict);
	gasnet_put(upcri_p_nodeof(dest),
		   upcri_pshared_to_remote_off(dest, destoffset), 
		   &value, sizeof(float));
	upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_put_pshared_doubleval(dest, destoffset, value) \
       (upcri_srcpos(), _upcr_put_pshared_doubleval(dest, destoffset, value, 0 UPCRI_PT_PASS))
#define upcr_put_pshared_doubleval_strict(dest, destoffset, value) \
       (upcri_srcpos(), _upcr_put_pshared_doubleval(dest, destoffset, value, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_put_pshared_doubleval)
void
_upcr_put_pshared_doubleval(upcr_pshared_ptr_t dest, ptrdiff_t destoffset, 
			    double value, int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(dest);
    (void) upcri_checkvalid_nonnull_pshared(dest);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &UPCRI_PEVT_PTMP, &value, sizeof(double)
    if (local) upcri_pevt_put_local(p,{
        upcri_strict_wmb(isstrict);
	UPCRI_TRACE_PUT(PUT_VAL_LOCAL, gasnet_mynode(),
			upcri_p2localoff(local, dest, destoffset),
			&value, sizeof(double));
	*(double*)(upcri_p2localoff(local, dest, destoffset)) = value;
	upcri_strict_mb(isstrict);
    }); else upcri_pevt_put(p,{
        upcri_strict_wmb(isstrict);
	gasnet_put(upcri_p_nodeof(dest),
		   upcri_pshared_to_remote_off(dest, destoffset), 
		   &value, sizeof(double));
	upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
}

#define upcr_get_pshared_floatval(src, srcoffset) \
       (upcri_srcpos(), _upcr_get_pshared_floatval(src, srcoffset, 0 UPCRI_PT_PASS))
#define upcr_get_pshared_floatval_strict(src, srcoffset) \
       (upcri_srcpos(), _upcr_get_pshared_floatval(src, srcoffset, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_pshared_floatval)
float
_upcr_get_pshared_floatval(upcr_pshared_ptr_t src, ptrdiff_t srcoffset, 
			   int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(src);
    float retval;
    (void) upcri_checkvalid_nonnull_pshared(src);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &retval, &UPCRI_PEVT_PTMP, sizeof(float)
    if (local) upcri_pevt_get_local(p,{
	UPCRI_TRACE_GET(GET_VAL_LOCAL, NULL, gasnet_mynode(),
			upcri_p2localoff(local, src, srcoffset), sizeof(float));
	upcri_strict_mb(isstrict);
	retval = *(float*)(upcri_p2localoff(local, src, srcoffset));
        upcri_strict_rmb(isstrict);
    }); else upcri_pevt_get(p,{
	float tmp; /* TODO: try to eliminate this stack temporary */
	upcri_strict_wmb(isstrict);
	gasnet_get(&tmp, upcri_p_nodeof(src),
		   upcri_pshared_to_remote_off(src, srcoffset), sizeof(float));
	retval = tmp;
        upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return retval;
}

#define upcr_get_pshared_doubleval(src, srcoffset) \
       (upcri_srcpos(), _upcr_get_pshared_doubleval(src, srcoffset, 0 UPCRI_PT_PASS))
#define upcr_get_pshared_doubleval_strict(src, srcoffset) \
       (upcri_srcpos(), _upcr_get_pshared_doubleval(src, srcoffset, 1 UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_get_pshared_doubleval)
double
_upcr_get_pshared_doubleval(upcr_pshared_ptr_t src, ptrdiff_t srcoffset, 
			    int isstrict UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_p_islocal(src);
    double retval;
    (void) upcri_checkvalid_nonnull_pshared(src);
    UPCRI_TRACE_STRICT(isstrict);
    UPCRI_STRICT_HOOK_IF(isstrict);
    #define UPCRI_PEVT_ARGS , !isstrict, &retval, &UPCRI_PEVT_PTMP, sizeof(double)
    if (local) upcri_pevt_get_local(p,{
	UPCRI_TRACE_GET(GET_VAL_LOCAL, NULL, gasnet_mynode(),
			upcri_p2localoff(local, src, srcoffset), sizeof(double));
	upcri_strict_mb(isstrict);
	retval = *(double*)(upcri_p2localoff(local, src, srcoffset));
        upcri_strict_rmb(isstrict);
    }); else upcri_pevt_get(p,{
	double tmp; /* TODO: try to eliminate this stack temporary */
	upcri_strict_wmb(isstrict);
	gasnet_get(&tmp, upcri_p_nodeof(src),
		   upcri_pshared_to_remote_off(src, srcoffset), sizeof(double));
	retval = tmp;
        upcri_strict_rmb(isstrict);
    });
    #undef UPCRI_PEVT_ARGS
    return retval;
}

/* -------------------------------------------------------------------------- */
/*
 * Shared Memory Bulk Memory Operations
 * ====================================
 * Transfer bulk data to/from shared memory which may be remote.
 *
 * Note these operations all take upcr_shared_ptr_t's (not phaseless ptrs).
 * All sizes are specified in BYTES, nbytes >= 0.
 *
 * Semantics are the same as those specified in the UPC spec.
 *
 * These operations are "relaxed" in terms of the UPC memory consistency model.
 *
 * Implementations will likely optimize for larger values of nbytes.
 * If the source and target memory areas overlap (but do not exactly
 * coincide), the resulting target memory contents are undefined.
 *
 * The motivation for having memget and memput, separately from the memory ops
 * above:
 *   - well defined semantics for crossing block boundaries
 *   - no alignment constraints on the pointers
 *   - non-blocking memput constrains source memory from changing while
 *     operation is in progress to avoid a potential buffering copy
 *   - optimize for large sizes
 *
 * Implementor's notes: 
 *   upcr_memset() can be implemented on GASNet using a single small active
 *   message, which makes it very efficient in terms of network communication
 */

#define upcr_memget(dst, src, nbytes) \
       (upcri_srcpos(), _upcr_memget(dst, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_memget)
void
_upcr_memget(void *dst, upcr_shared_ptr_t src, size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(src);
    (void) upcri_checkvalid_nonnull_shared(src);
    #define UPCRI_PEVT_ARGS , dst, &src, nbytes
    upcri_pevt_start(GASP_UPC_MEMGET);
    if (local) {
	UPCRI_TRACE_GET(GET_BULK_LOCAL, dst, gasnet_mynode(),
			upcri_s2local(local, src), nbytes);
	UPCRI_UNALIGNED_MEMCPY(dst, upcri_s2local(local, src), nbytes);
    } else {
	gasnet_get_bulk(dst, upcri_s_nodeof(src), 
			upcri_shared_to_remote(src), nbytes);
    }
    upcri_pevt_end(GASP_UPC_MEMGET);
    #undef UPCRI_PEVT_ARGS
}

#define upcr_memput(dst, src, nbytes) \
       (upcri_srcpos(), _upcr_memput(dst, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_memput)
void
_upcr_memput(upcr_shared_ptr_t dst, const void *src, size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dst);
    (void) upcri_checkvalid_nonnull_shared(dst);
    #define UPCRI_PEVT_ARGS , &dst, src, nbytes
    upcri_pevt_start(GASP_UPC_MEMPUT);
    if (local) {
	UPCRI_TRACE_PUT(PUT_BULK_LOCAL, gasnet_mynode(),
			upcri_s2local(local, dst), src, nbytes);
	UPCRI_UNALIGNED_MEMCPY(upcri_s2local(local, dst), src, nbytes);
#if defined(UPCRI_DO_MEMPUT_NBI)
    } else if (upcri_is_aligned(nbytes, src, upcr_addrfield_shared(dst))) {
	gasnet_put_nbi(upcri_s_nodeof(dst), upcri_shared_to_remote(dst),
			(void *)src, nbytes);
#endif
    } else {
	gasnet_put_bulk(upcri_s_nodeof(dst), upcri_shared_to_remote(dst),
			(void *)src, nbytes);
    }
    upcri_pevt_end(GASP_UPC_MEMPUT);
    #undef UPCRI_PEVT_ARGS
}

#define upcr_memset(dst, c, nbytes) \
       (upcri_srcpos(), _upcr_memset(dst, c, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_memset)
void
_upcr_memset(upcr_shared_ptr_t dst, int c, size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dst);
    (void) upcri_checkvalid_nonnull_shared(dst);
    #define UPCRI_PEVT_ARGS , &dst, c, nbytes
    upcri_pevt_start(GASP_UPC_MEMSET);
    if (local) {
	UPCRI_TRACE_MEMSET(MEMSET_LOCAL, gasnet_mynode(),
			   upcri_s2local(local, dst), c, nbytes);
	memset(upcri_s2local(local, dst), c, nbytes);
    } else {
	gasnet_memset(upcri_s_nodeof(dst), upcri_shared_to_remote(dst), 
		      c, nbytes);
    }
    upcri_pevt_end(GASP_UPC_MEMSET);
    #undef UPCRI_PEVT_ARGS
}

/* Non-blocking versions of the bulk memory operations.
 *
 * Must be synchronized using explicit or implicit synchronization as with
 * non-blocking scalar memory access operations.
 *
 * The contents of the memory referenced by src must NOT change between
 * initiation and successful synchronization, or the result is undefined.
 */

#define upcr_nb_memget(dst, src, nbytes) \
       (upcri_srcpos(), _upcr_nb_memget(dst, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_nb_memget) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t
_upcr_nb_memget(void *dst, upcr_shared_ptr_t src, size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcr_handle_t h = UPCR_INVALID_HANDLE;
    upcri_local_t local = upcri_s_islocal(src);
    (void) upcri_checkvalid_nonnull_shared(src);
    #define UPCRI_PEVT_ARGS , dst, &src, nbytes, (h==UPCR_INVALID_HANDLE?GASP_UPC_NB_TRIVIAL:h)
    upcri_pevt_start(GASP_BUPC_NB_MEMGET_INIT);
    if (local) {
	UPCRI_TRACE_GET(GET_NB_BULK_LOCAL, dst, gasnet_mynode(),
			 upcri_s2local(local, src), nbytes);
	UPCRI_UNALIGNED_MEMCPY(dst, upcri_s2local(local, src), nbytes);
	h = UPCR_INVALID_HANDLE;
    } else {
	h = gasnet_get_nb_bulk(dst, upcri_s_nodeof(src), 
				  upcri_shared_to_remote(src), nbytes);
    }
    upcri_pevt_end(GASP_BUPC_NB_MEMGET_INIT);
    #undef UPCRI_PEVT_ARGS
    return h;
}

#define upcr_nb_memput(dst, src, nbytes) \
       (upcri_srcpos(), _upcr_nb_memput(dst, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_nb_memput) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t
_upcr_nb_memput(upcr_shared_ptr_t dst, const void *src, size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcr_handle_t h = UPCR_INVALID_HANDLE;
    upcri_local_t local = upcri_s_islocal(dst);
    (void) upcri_checkvalid_nonnull_shared(dst);
    #define UPCRI_PEVT_ARGS , &dst, src, nbytes, (h==UPCR_INVALID_HANDLE?GASP_UPC_NB_TRIVIAL:h)
    upcri_pevt_start(GASP_BUPC_NB_MEMPUT_INIT);
    if (local) {
	UPCRI_TRACE_PUT(PUT_NB_BULK_LOCAL, gasnet_mynode(),
			upcri_s2local(local, dst), src, nbytes);
	UPCRI_UNALIGNED_MEMCPY(upcri_s2local(local, dst), src, nbytes);
	h = UPCR_INVALID_HANDLE;
    } else {
	h = gasnet_put_nb_bulk(upcri_s_nodeof(dst), 
				  upcri_shared_to_remote(dst),
				  (void *)src, nbytes);
    }
    upcri_pevt_end(GASP_BUPC_NB_MEMPUT_INIT);
    #undef UPCRI_PEVT_ARGS
    return h;
}

#define upcr_nb_memset(dst, c, nbytes) \
       (upcri_srcpos(), _upcr_nb_memset(dst, c, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_nb_memset) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t
_upcr_nb_memset(upcr_shared_ptr_t dst, int c, size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dst);
    (void) upcri_checkvalid_nonnull_shared(dst);
    if (local) {
	UPCRI_TRACE_MEMSET(MEMSET_NB_LOCAL, gasnet_mynode(),
			   upcri_s2local(local, dst), c, nbytes);
	memset(upcri_s2local(local, dst), c, nbytes);
	return UPCR_INVALID_HANDLE;
    } else {
	return gasnet_memset_nb(upcri_s_nodeof(dst), 
				upcri_shared_to_remote(dst), c, nbytes);
    }
}

#define upcr_nbi_memget(dst, src, nbytes) \
       (upcri_srcpos(), _upcr_nbi_memget(dst, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_nbi_memget)
void
_upcr_nbi_memget(void *dst, upcr_shared_ptr_t src, size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(src);
    (void) upcri_checkvalid_nonnull_shared(src);
    #define UPCRI_PEVT_ARGS , dst, &src, nbytes, GASP_UPC_NBI_TRIVIAL
    upcri_pevt_start(GASP_BUPC_NB_MEMGET_INIT);
    if (local) {
	UPCRI_TRACE_GET(GET_NBI_BULK_LOCAL, dst, gasnet_mynode(),
			upcri_s2local(local, src), nbytes);
	UPCRI_UNALIGNED_MEMCPY(dst, upcri_s2local(local, src), nbytes);
    } else {
	gasnet_get_nbi_bulk(dst, upcri_s_nodeof(src), 
			    upcri_shared_to_remote(src), nbytes);
    }
    upcri_pevt_end(GASP_BUPC_NB_MEMGET_INIT);
    #undef UPCRI_PEVT_ARGS
}

#define upcr_nbi_memput(dst, src, nbytes) \
       (upcri_srcpos(), _upcr_nbi_memput(dst, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_nbi_memput)
void
_upcr_nbi_memput(upcr_shared_ptr_t dst, const void *src, size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dst);
    (void) upcri_checkvalid_nonnull_shared(dst);
    #define UPCRI_PEVT_ARGS , &dst, src, nbytes, GASP_UPC_NBI_TRIVIAL
    upcri_pevt_start(GASP_BUPC_NB_MEMPUT_INIT);
    if (local) {
	UPCRI_TRACE_PUT(PUT_NBI_BULK_LOCAL, gasnet_mynode(),
			upcri_s2local(local, dst), src, nbytes);
	UPCRI_UNALIGNED_MEMCPY(upcri_s2local(local, dst), src, nbytes);
    } else {
	gasnet_put_nbi_bulk(upcri_s_nodeof(dst), 
			    upcri_shared_to_remote(dst), (void *)src, nbytes);
    }
    upcri_pevt_end(GASP_BUPC_NB_MEMPUT_INIT);
    #undef UPCRI_PEVT_ARGS
}

#define upcr_nbi_memset(dst, c, nbytes) \
       (upcri_srcpos(), _upcr_nbi_memset(dst, c, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_nbi_memset)
void
_upcr_nbi_memset(upcr_shared_ptr_t dst, int c, size_t nbytes UPCRI_PT_ARG)
{
    UPCRI_PASS_GAS();
    upcri_local_t local = upcri_s_islocal(dst);
    (void) upcri_checkvalid_nonnull_shared(dst);
    if (local) {
	UPCRI_TRACE_MEMSET(MEMSET_NBI_LOCAL, gasnet_mynode(),
			   upcri_s2local(local, dst), c, nbytes);
	memset(upcri_s2local(local, dst), c, nbytes);
    } else {
	gasnet_memset_nbi(upcri_s_nodeof(dst), 
			  upcri_shared_to_remote(dst), c, nbytes);
    }
}


/*
 * memcpy functions.
 *
 * These get a bit funky, so I've segregated them here.
 *
 * These functions take two shared pointers, so it's possible both regions are
 * on remote nodes.  If this is the case and both regions are on the same
 * node, we send an Active Message that causes a regular memcpy on the remote
 * node.  Otherwise we have to revert to the boneheaded strategy of copying
 * the source memory to our node, then copying it over to the destination.
 * Not performance-enhancing...
 */

/* 
 * Sends an active message that does memcpy on remote node.
 *
 * Since we can't know when the copy will be completed except by waiting, the
 * 'nonblocking' version actually blocks.  
 */
GASNETT_INLINE(upcri_do_remote_memcpy) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t
upcri_do_remote_memcpy(gasnet_node_t node, void * dst, void * src, 
		       size_t nbytes)
{	    
    volatile int trigger = UPCRI_REQUEST_BLOCKED;
    volatile int *ptrigger = &trigger;

    /* Send nbytes as ptr, since size_t may be 64 bits */
    UPCRI_AM_CALL(UPCRI_SHORT_REQUEST(4, 8,
		  (node, UPCRI_HANDLER_ID(upcri_remote_memcpy_SRequest),
			UPCRI_SEND_PTR(dst),
			UPCRI_SEND_PTR(src),
			UPCRI_SEND_PTR(nbytes),
			UPCRI_SEND_PTR(ptrigger))));

    GASNET_BLOCKUNTIL(trigger == UPCRI_REQUEST_DONE);

    return UPCR_INVALID_HANDLE;
}

/* 
 * The function below is a bit hairy, but many of the conditionals will be
 * resolved at compile time, since the memcpy_type will be a constant.
 */
enum {
    upcri_memcpy_type_block = 0,
    upcri_memcpy_type_nb,
    upcri_memcpy_type_nbi
};

#define upcr_do_memcpy(dst, src, nbytes, memcpy_type) \
       _upcr_do_memcpy(dst, src, nbytes, memcpy_type UPCRI_PT_PASS)

extern upcr_handle_t _upcr_do_memcpy(upcr_shared_ptr_t dst, upcr_shared_ptr_t src, 
				     size_t nbytes, int memcpy_type UPCRI_PT_ARG);

#define upcr_memcpy(dst, src, nbytes)               \
       (upcri_srcpos(), _upcr_memcpy(dst, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_memcpy)
void
_upcr_memcpy(upcr_shared_ptr_t dst, upcr_shared_ptr_t src, 
	     size_t nbytes UPCRI_PT_ARG)
{
    #define UPCRI_PEVT_ARGS , &dst, &src, nbytes
    upcri_pevt_start(GASP_UPC_MEMCPY);

    upcr_do_memcpy(dst, src, nbytes, upcri_memcpy_type_block);

    upcri_pevt_end(GASP_UPC_MEMCPY);
    #undef UPCRI_PEVT_ARGS
}

#define upcr_nb_memcpy(dst, src, nbytes)               \
       (upcri_srcpos(), _upcr_nb_memcpy(dst, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_nb_memcpy) GASNETT_WARN_UNUSED_RESULT
upcr_handle_t
_upcr_nb_memcpy(upcr_shared_ptr_t dst, upcr_shared_ptr_t src, 
	       size_t nbytes UPCRI_PT_ARG)
{
    upcr_handle_t h = UPCR_INVALID_HANDLE;

    #define UPCRI_PEVT_ARGS , &dst, &src, nbytes, (h==UPCR_INVALID_HANDLE?GASP_UPC_NB_TRIVIAL:h)
    upcri_pevt_start(GASP_BUPC_NB_MEMCPY_INIT);

    h = upcr_do_memcpy(dst, src, nbytes, upcri_memcpy_type_nb);

    upcri_pevt_end(GASP_BUPC_NB_MEMCPY_INIT);
    #undef UPCRI_PEVT_ARGS
    return h;
}

#define upcr_nbi_memcpy(dst, src, nbytes)               \
       (upcri_srcpos(), _upcr_nbi_memcpy(dst, src, nbytes UPCRI_PT_PASS))

GASNETT_INLINE(_upcr_nbi_memcpy)
void
_upcr_nbi_memcpy(upcr_shared_ptr_t dst, upcr_shared_ptr_t src, 
		size_t nbytes UPCRI_PT_ARG)
{
    #define UPCRI_PEVT_ARGS , &dst, &src, nbytes, GASP_UPC_NBI_TRIVIAL
    upcri_pevt_start(GASP_BUPC_NB_MEMCPY_INIT);

    upcr_do_memcpy(dst, src, nbytes, upcri_memcpy_type_nbi);

    upcri_pevt_end(GASP_BUPC_NB_MEMCPY_INIT);
    #undef UPCRI_PEVT_ARGS
}

#if PLATFORM_COMPILER_MTA /* restore pragma */
  #undef GASNETT_MTA_PRAGMA_EXPECT_OVERRIDE
  #define GASNETT_MTA_PRAGMA_EXPECT_OVERRIDE GASNETT_MTA_PRAGMA_EXPECT_ENABLED
#endif

#endif /* UPCR_SHACCESS_H */
