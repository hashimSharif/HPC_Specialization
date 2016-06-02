/* -------------------------------------------------------------------------- */
/*
 * Shared Pointer Representation
 * =============================
 *
 *  *** upcr_shared_ptr_t - general shared pointer
 *  *** upcr_pshared_ptr_t - "phase-less" shared pointer, blocksize == 1 
 *	or blocksize indef
 *
 *  opaque types representing a generic (i.e. untyped) shared pointer defined
 *  by upcr and used by generated code. In general, generated code NEVER looks
 *  inside this opaque type, but there may be cases where we want to expose
 *  some information to the UPC optimizer.
 *
 *  Note these two shared pointer categories are NOT interchangeable - the
 *  generated code must explicitly select the correct category pointer for the
 *  current static blocksize and call the correct version of the appropriate
 *  entry points below
 */

#ifndef UPCR_SPTR_H
#define UPCR_SPTR_H

GASNETT_BEGIN_EXTERNC

/* Set non-zero to be paranoid about shared pointer arithmetic.
 * This enables self-consistency checks beyond normal debugging.
 */
#ifndef UPCRI_DEBUG_SPTR_ARITH
  #define UPCRI_DEBUG_SPTR_ARITH 0
#endif

/*
 * Totalview assistant library doesn't get to just 'read' variables in the
 * runtime--it must use hooks to get such values.  To make sure the assistant
 * lib code hooks all the variables it needs, don't declare any variables in
 * this file when compiling the assistant library.
 *  - The only exception is for upcr_null_{p}shared, which are needed within
 *    this file, yet can't be declared before the sptr rep is defined.
 *  - It also doesn't currently include the gasnet_tools.h header
 */
#ifdef UPCRI_NOT_LINKED_WITH_RUNTIME
  #define UPCRI_SPTR_H_DECLARE_VARIABLES 0
  #define UPCRI_CONSTANT_P(_expr) (0)
#else
  #define UPCRI_SPTR_H_DECLARE_VARIABLES 1
  #define UPCRI_CONSTANT_P(_expr) gasnett_constant_p(_expr)
#endif

/* Totalview assistant library highjacks pthread "extra arg" mechanism, but
 * also requires an extra arg for some functions that don't need it for
 * pthreads.  By default these #define away to nothing. */
#ifndef UPCRI_TV_ARG_ALONE
  #define UPCRI_TV_ARG_ALONE
  #define UPCRI_TV_ARG
  #define UPCRI_TV_PASS_ALONE
  #define UPCRI_TV_PASS
#endif 

/* Make sure Totalview assistant library setup defines this (to 1 or 0) */
#if !defined(UPCRI_SINGLE_ALIGNED_REGIONS) || \
    (UPCRI_SINGLE_ALIGNED_REGIONS != 0 && UPCRI_SINGLE_ALIGNED_REGIONS != 1)
#	error UPCRI_SINGLE_ALIGNED_REGIONS must be defined to 0 or 1!
#endif

/* 
 * "Public size" for phase:  shared pointers may store something smaller.
 */
typedef unsigned int upcr_phase_t;

#if !UPCRI_STRUCT_SPTR && !UPCRI_PACKED_SPTR
  #error No shared pointer format specified!
#endif

/* 
 * Only enable symmetric pointers where symmetric segments are available, and
 * only if pointer width is 64 bits
 */

#if defined(UPCRI_SYMMETRIC_SPTR) && !defined(UPCRI_SYMMETRIC_PSHARED)
  #if UPCRI_SYMMETRIC_SEGMENTS && !(UPCRI_USING_GCCUPC || UPCRI_USING_CUPC)
    #define UPCRI_SYMMETRIC_PSHARED 1
  #else
    #define UPCRI_SYMMETRIC_PSHARED 0
  #endif
#else
  #define UPCRI_SYMMETRIC_PSHARED 0
#endif

#if UPCRI_SYMMETRIC_SEGMENTS
  #if SIZEOF_VOID_P != 8
    #error Symmetric segments only available for 64-bit platforms
  #endif
  #if UPCRI_SPTR_H_DECLARE_VARIABLES
    extern char		*upcri_segsym_base;
    extern char		*upcri_segsym_end;
    extern ptrdiff_t    upcri_segsym_size;
    extern ptrdiff_t    upcri_segsym_region_size;
    extern uintptr_t    upcri_segsym_addrmask; /* Used on systems where heap bits
					        are not known at compile time */
    extern uintptr_t    upcri_segsym_size_mask;
    extern uintptr_t    upcri_segsym_size_shift;
    extern uintptr_t    upcri_segsym_region_size_mask;
    extern uintptr_t    upcri_segsym_region_size_shift;

    extern int		UPCRL_segsym_pow2_opt; /* Set in upcc linker magic */
  #endif
  /* Provide extra support for platforms that can assert segment sizes are
   * powers of two and threads are powers of two 
   */
  #if __BERKELEY_UPC_POW2_SYMPTR__
    #define UPCRI_SYMMETRIC_MOD(a)       ((((ptrdiff_t)(a))&upcri_segsym_size_mask))
    #define UPCRI_SYMMETRIC_DIV(a)       ((((ptrdiff_t)(a))>>upcri_segsym_size_shift))
    #define UPCRI_SYMMETRIC_ADDRFIELD(a) (((uintptr_t)(a))&upcri_segsym_region_size_mask)
    #define UPCRI_SYMMETRIC_THREADOF(a)	 ((a) ? ((uintptr_t)((a)-upcri_segsym_base))>>upcri_segsym_region_size_shift : 0)
  #else
    #define UPCRI_SYMMETRIC_MOD(a)       ((((ptrdiff_t)(a))%upcri_segsym_size))
    #define UPCRI_SYMMETRIC_DIV(a)       ((((ptrdiff_t)(a))/upcri_segsym_size))
    #define UPCRI_SYMMETRIC_ADDRFIELD(a) (((uintptr_t)(a))%upcri_segsym_region_size)
    #define UPCRI_SYMMETRIC_THREADOF(a)	 ((a) ? ((uintptr_t)((a)-upcri_segsym_base))/ \
                                                upcri_segsym_region_size : 0)
  #endif
#endif

/* Allow symmetric pointer representation for pshared pointers to be
 * independent of either packed/unpacked pointer representation.
 */
#if UPCRI_SYMMETRIC_PSHARED 
  /* Allow pointer to have restrict qualifier */
  typedef char * upcr_pshared_ptr_t;
  #define UPCR_RESTRICT_PSHARED    UPCR_RESTRICT
  #define UPCR_NULL_PSHARED	   ((upcr_pshared_ptr_t)0)
  #define UPCR_INITIALIZED_PSHARED ((upcr_pshared_ptr_t)1)
#endif /* UPCRI_SYMMETRIC_PSHARED */

#if UPCRI_PACKED_SPTR 
  /* packed 64 bit representation:
     UPCR and (GCCUPC & !UPCRI_SPTR_ADDR_FIRST)
      | phase (if phased) | thread | addr (low bits) |
     GCCUPC & UPCRI_SPTR_ADDR_FIRST
      | addr(high bits) | thread | phase |
   */
  typedef uint64_t upcr_shared_ptr_t;
  /* representation is an integral type, so restrict prohibited by C compiler */
  #define UPCR_RESTRICT_SHARED
  #define UPCR_NULL_SHARED	    ((upcr_shared_ptr_t) 0)
  #define UPCR_INITIALIZED_SHARED   ((upcr_shared_ptr_t) 1)

  #if !UPCRI_SYMMETRIC_PSHARED
    typedef uint64_t upcr_pshared_ptr_t;
    #define UPCR_RESTRICT_PSHARED
    #define UPCR_NULL_PSHARED	     ((upcr_pshared_ptr_t)0)
    #define UPCR_INITIALIZED_PSHARED ((upcr_pshared_ptr_t)1)
  #endif

  #if UPCRI_ADDR_BITS_OVERRIDE
    /* bit distribution set by configure */
    #define UPCRI_PHASE_BITS  UPCRI_PHASE_BITS_OVERRIDE
    #define UPCRI_THREAD_BITS UPCRI_THREAD_BITS_OVERRIDE
    #define UPCRI_ADDR_BITS   UPCRI_ADDR_BITS_OVERRIDE
  #elif SIZEOF_VOID_P == 4
    #define UPCRI_PHASE_BITS  22
    #define UPCRI_THREAD_BITS 10
    #define UPCRI_ADDR_BITS   32
  #elif SIZEOF_VOID_P == 8
    #define UPCRI_PHASE_BITS  20
    #define UPCRI_THREAD_BITS 10
    #define UPCRI_ADDR_BITS   34
  #else
    #error bad pointer width: only 32/64 bit architectures supported
  #endif
  #if (UPCRI_PHASE_BITS + UPCRI_THREAD_BITS + UPCRI_ADDR_BITS) != 64
    #error Packed shared pointer components do not add up to 64 bits!
  #endif
  #if UPCRI_USING_GCCUPC || UPCRI_USING_CUPC
    /* Presently GCCUPC uses 36 bits for addr, even on 32-bit arch */
  #elif UPCRI_ADDR_BITS > SIZEOF_VOID_P*8
    #error UPCRI_ADDR_BITS is larger than 8*sizeof(void*)
  #endif
  #if UPCRI_PHASE_BITS < 1
    #error UPCRI_PHASE_BITS is less than 1 bit!
  #endif
  #if UPCRI_THREAD_BITS < 1
    #error UPCRI_THREAD_BITS is less than 1 bit!
  #endif
  #if UPCRI_ADDR_BITS < 20
    #error UPCRI_ADDR_BITS is less than 20 bits
  #endif
  #if (UPCRI_USING_GCCUPC || UPCRI_USING_CUPC) && UPCRI_SPTR_ADDR_FIRST
    /* GCCUPC packed pointer: high                 low
                              | addr | thread | phase |
       Different representation then BUPC is chosen because it
       simplifies pointer comparison.
    */
    #define UPCRI_PHASE_SHIFT 0
    #define UPCRI_THREAD_SHIFT (UPCRI_PHASE_BITS) 
    #define UPCRI_ADDR_SHIFT (UPCRI_PHASE_BITS+UPCRI_THREAD_BITS)
  #else
    /* BUPC packed pointer: high                 low
                            | phase | thread | addr | */
    #define UPCRI_PHASE_SHIFT (UPCRI_THREAD_BITS+UPCRI_ADDR_BITS) 
    #define UPCRI_THREAD_SHIFT (UPCRI_ADDR_BITS) 
    #define UPCRI_ADDR_SHIFT 0
  #endif
  #define UPCRI_PHASE_MASK \
    ((uint64_t)((1ull << UPCRI_PHASE_BITS) - 1) << UPCRI_PHASE_SHIFT) 
  #define UPCRI_THREAD_MASK \
    ((uint64_t)((1ull << UPCRI_THREAD_BITS) - 1) << UPCRI_THREAD_SHIFT) 
  #define UPCRI_ADDR_MASK \
    ((uint64_t)((1ull << UPCRI_ADDR_BITS) - 1) << UPCRI_ADDR_SHIFT) 

  #define UPCRI_PHASE_OF(x) \
    ((x & UPCRI_PHASE_MASK) >> UPCRI_PHASE_SHIFT)
  #define UPCRI_THREAD_OF(x) \
    ((x & UPCRI_THREAD_MASK) >> UPCRI_THREAD_SHIFT)
  #define UPCRI_ADDR_OF(x) \
    ((x & UPCRI_ADDR_MASK) >> UPCRI_ADDR_SHIFT)

  #if UPCR_DEBUG
    /* checks to see if addr/offset is too big to fit in address bits */ 
    void upcri_check_addr_overflow(uintptr_t addrfield);
  #else
    #define upcri_check_addr_overflow(addrfield)
  #endif

  #if UPCRI_USING_GCCUPC || UPCRI_USING_CUPC
    /* GCCUPC puts offsets only in addr field */
    #define UPCRI_ADDR_FITS_IN_SPTR   0
  #else
    #define UPCRI_ADDR_FITS_IN_SPTR   (UPCRI_ADDR_BITS >= (SIZEOF_VOID_P * 8))
  #endif

#elif UPCRI_STRUCT_SPTR

  #if UPCRI_USING_GCCUPC || UPCRI_USING_CUPC || UPCRI_USING_CUPC2C

    /* Make sure that configure set the appropiate
       field bit size values.  */
    #if !(defined(UPCRI_ADDR_BITS_OVERRIDE) \
         && defined(UPCRI_THREAD_BITS_OVERRIDE) \
         && defined(UPCRI_PHASE_BITS_OVERRIDE))
    #  error the 'struct' sptr field sizes must be defined by configure
    #endif

    /* Make sure that configure set the appropiate
       field type values.  */
    #if !(defined(UPCRI_STRUCT_SPTR_ADDR_TYPE) \
          && defined(UPCRI_STRUCT_SPTR_THREAD_TYPE) \
          && defined(UPCRI_STRUCT_SPTR_PHASE_TYPE))
    #  error the 'struct' sptr field types must be defined by configure
    #endif

    /* Field sizes set by configure */
    #define UPCRI_PHASE_BITS  UPCRI_PHASE_BITS_OVERRIDE
    #define UPCRI_THREAD_BITS UPCRI_THREAD_BITS_OVERRIDE
    #define UPCRI_ADDR_BITS   UPCRI_ADDR_BITS_OVERRIDE

    /* If the sptr field definitions aren't set, then
       make them empty.  */
    #ifndef UPCRI_STRUCT_SPTR_ADDR_FIELD
    #define UPCRI_STRUCT_SPTR_ADDR_FIELD
    #endif
    #ifndef UPCRI_STRUCT_SPTR_THREAD_FIELD
    #define UPCRI_STRUCT_SPTR_THREAD_FIELD
    #endif
    #ifndef UPCRI_STRUCT_SPTR_PHASE_FIELD
    #define UPCRI_STRUCT_SPTR_PHASE_FIELD
    #endif

    typedef struct
#if __GCC_UPC__ || __clang_upc__
    /* Make sure that UPCR's shared pointer struct type isn't
       allowed to 'pun' either GCCUPC's internal shared pointer representation
       type, or pointer-to-shared types.  (See Bug #2424 for details.) */
    __attribute__ ((may_alias))
#endif
    shared_ptr_struct
    {
#if defined(UPCRI_SPTR_ADDR_FIRST)
#  if UPCRI_SPTR_ADDR_FIRST
        uintptr_t s_addr;
	UPCRI_STRUCT_SPTR_THREAD_TYPE s_thread UPCRI_STRUCT_SPTR_THREAD_FIELD;
	UPCRI_STRUCT_SPTR_PHASE_TYPE s_phase UPCRI_STRUCT_SPTR_PHASE_FIELD;
#  else
	UPCRI_STRUCT_SPTR_PHASE_TYPE s_phase UPCRI_STRUCT_SPTR_PHASE_FIELD;
	UPCRI_STRUCT_SPTR_THREAD_TYPE s_thread UPCRI_STRUCT_SPTR_THREAD_FIELD;
        uintptr_t s_addr;
#  endif
#else
        /* 'old' (GCCUPC 4.2.3.x, x <= 4) sptr field ordering. */
	UPCRI_STRUCT_SPTR_PHASE_TYPE s_phase UPCRI_STRUCT_SPTR_PHASE_FIELD;
	UPCRI_STRUCT_SPTR_THREAD_TYPE s_thread UPCRI_STRUCT_SPTR_THREAD_FIELD;
        uintptr_t s_addr;
#endif
    }
#ifdef UPCRI_STRUCT_SPTR_ALIGN
    #if !HAVE_GCC_ATTRIBUTE_ALIGNED
      #error GCCUPC sptr struct alignment is required for this target, but the compiler does not support it? (see bug 1653)
    #endif
      __attribute__ ((__aligned__ (UPCRI_STRUCT_SPTR_ALIGN)))
#endif
      upcr_shared_ptr_t;
    /* pshared ptrs currently not used by GNU UPC or Clang UPC */
    typedef struct shared_ptr_struct upcr_pshared_ptr_t;

    /* TODO: should these adjust for (!UPCRI_SPTR_ADDR_FIRST) ? */
    #define UPCR_NULL_SHARED	    { 0, 0, 0 }
    #define UPCR_NULL_PSHARED	    { 0, 0 }
    #define UPCR_INITIALIZED_SHARED   { 0, 0, 1 }
    #define UPCR_INITIALIZED_PSHARED  { 0, 1 }
    #define UPCRI_ADDR_FITS_IN_SPTR   1
  #else
    /* 
     * "regular" struct pointer representation 
     */
    typedef struct shared_ptr_struct {
        uintptr_t   s_addr;   /* First field to speed pointer use	    */
        uint32_t    s_thread; 
        uint32_t    s_phase;
    } upcr_shared_ptr_t;
    /* representation is a struct type, so restrict prohibited by C compiler */
    #define UPCR_RESTRICT_SHARED
    #define UPCRI_PHASE_BITS     32
    #define UPCRI_THREAD_BITS    32
    /* Don't use (8*SIZEOF_VOID_P) since we _STRINGIFY(UPCRI_ADDR_BITS) */
    #if PLATFORM_ARCH_32
      #define UPCRI_ADDR_BITS    32
    #elif PLATFORM_ARCH_64
      #define UPCRI_ADDR_BITS    64
    #else
      #error "unknown or invalid word size"
    #endif
    #define UPCR_NULL_SHARED	      { 0, 0, 0 }
    #define UPCR_INITIALIZED_SHARED   { 1, 0, 0 }
  
    #if !UPCRI_SYMMETRIC_PSHARED
      typedef struct pshared_ptr_struct {
          uintptr_t s_addr;   /* First field to speed pointer use	    */
          uint32_t  s_thread; 
      } upcr_pshared_ptr_t;
      #define UPCR_NULL_PSHARED	        { 0, 0 }
      #define UPCR_INITIALIZED_PSHARED  { 1, 0 }
      #define UPCR_RESTRICT_PSHARED
    #endif

    #define UPCRI_ADDR_FITS_IN_SPTR   1
  #endif /* UPCRI_USING_GCCUPC || UPCRI_USING_CUPC */

#else
  #error shared pointer representation not defined!
#endif

/* determines if argument looks like a valid shared pointer */
int _upcri_isvalid_shared(upcr_shared_ptr_t sptr);
int _upcri_isvalid_pshared(upcr_pshared_ptr_t sptr);
#define upcr_isvalid_shared(sptr)  _upcri_isvalid_shared(sptr)
#define upcr_isvalid_pshared(sptr) _upcri_isvalid_pshared(sptr)

#if UPCR_DEBUG
  /* asserts argument looks like a valid shared pointer and returns it */
  upcr_shared_ptr_t  _upcri_checkvalid_shared(upcr_shared_ptr_t sptr, int allownull,
                                             const char *filename, int linenum);
  upcr_pshared_ptr_t _upcri_checkvalid_pshared(upcr_pshared_ptr_t psptr, int allownull,
                                             const char *filename, int linenum);
  #define upcri_checkvalid_shared(sptr)  _upcri_checkvalid_shared(sptr,1,__FILE__,__LINE__)
  #define upcri_checkvalid_pshared(sptr) _upcri_checkvalid_pshared(sptr,1,__FILE__,__LINE__)
  /* same, but also tests that ptr != NULL */
  #define upcri_checkvalid_nonnull_shared(sptr)  _upcri_checkvalid_shared(sptr,0,__FILE__,__LINE__)
  #define upcri_checkvalid_nonnull_pshared(sptr) _upcri_checkvalid_pshared(sptr,0,__FILE__,__LINE__)
  /* same, but also tests that ptr != NULL, and has local affinity */
  upcr_shared_ptr_t  _upcri_checkvalidlocal_shared(upcr_shared_ptr_t sptr,
						   const char *filename, int linenum);
  upcr_pshared_ptr_t _upcri_checkvalidlocal_pshared(upcr_pshared_ptr_t psptr,
						    const char *filename, int linenum);
  #define upcri_checkvalidlocal_shared(sptr)  \
	 _upcri_checkvalidlocal_shared(sptr,__FILE__,__LINE__)
  #define upcri_checkvalidlocal_pshared(sptr) \
	 _upcri_checkvalidlocal_pshared(sptr,__FILE__,__LINE__)
#else
  #define upcri_checkvalid_shared(sptr)   (sptr)
  #define upcri_checkvalid_pshared(psptr) (psptr)
  #define upcri_checkvalid_nonnull_shared(sptr)   (sptr)
  #define upcri_checkvalid_nonnull_pshared(psptr) (psptr)
  #define upcri_checkvalidlocal_shared(sptr)  (sptr)
  #define upcri_checkvalidlocal_pshared(sptr) (sptr)
#endif

#if UPCRI_PHASE_BITS >= 31
  #define UPCR_MAX_BLOCKSIZE ((1U << 31)-1) 
#else
  #define UPCR_MAX_BLOCKSIZE (1 << UPCRI_PHASE_BITS) 
#endif
#define UPCR_MAX_THREADS MIN((((uint64_t)1)<<UPCRI_THREAD_BITS),((uint64_t)UPCR_MAXNODES)*UPCR_MAX_PTHREADS)

/* 3 types of shared pointer logic:
 * --------------------------------
 * 0) linker addresses: store full addresses in ptr, with values assigned by
 *    linker, and use per-thread offset (like #3) to translate into gasnet
 *    region addrs.
 * 1) Full address stored in shared pointer: only for aligned, single-threaded
 *    processes not using GASNet process-shared memory (PSHM).
 * 2) Single offset: same as #1, but addresses too big for packed
 *    pointer's address bits.  Uses same offset for all threads.
 * 3) Use per-thread offsets: used when regions unaligned, or multiple
 *    regions mmapped into each process (i.e. pthreads or PSHM used). 
 */
#if UPCR_USING_LINKADDRS
  #if UPCRI_SPTR_H_DECLARE_VARIABLES
    extern uintptr_t			upcri_linksegstart;
    #if !UPCRI_SINGLE_ALIGNED_REGIONS
      extern uintptr_t		       *upcri_linkoffset;
    #endif
    #if UPCRI_UPC_PTHREADS
      #define upcri_mylinkoffset()	upcri_mypthreadinfo()->link_offset
    #else
      extern uintptr_t			upcri_linkoffset_single;
      #define upcri_mylinkoffset()	upcri_linkoffset_single
    #endif
  #endif
  #define UPCRI_SPTRS_USE_OFFSETS 1
  #define UPCRI_PLUS_MY_OFFSET			+ upcri_mylinkoffset()
  #define UPCRI_MINUS_MY_OFFSET			- upcri_mylinkoffset()
  #if UPCRI_SINGLE_ALIGNED_REGIONS
    #define UPCRI_PLUS_REMOTE_OFFSET(thread)	+ upcri_mylinkoffset()
    #define UPCRI_MINUS_REMOTE_OFFSET(thread)	- upcri_mylinkoffset()
  #else
    #define UPCRI_PLUS_REMOTE_OFFSET(thread)	+ upcri_linkoffset[thread]
    #define UPCRI_MINUS_REMOTE_OFFSET(thread)	- upcri_linkoffset[thread]
  #endif
#elif UPCRI_SINGLE_ALIGNED_REGIONS && UPCRI_ADDR_FITS_IN_SPTR
  #define UPCRI_SPTRS_USE_ADDRESSES 1
  #define UPCRI_PLUS_MY_OFFSET	
  #define UPCRI_MINUS_MY_OFFSET	
  #define UPCRI_PLUS_REMOTE_OFFSET(thread)
  #define UPCRI_MINUS_REMOTE_OFFSET(thread)
#elif UPCRI_SINGLE_ALIGNED_REGIONS
  #define UPCRI_SPTRS_USE_OFFSETS 1
  #define UPCRI_PLUS_MY_OFFSET			+ upcri_myregion()
  #define UPCRI_MINUS_MY_OFFSET			- upcri_myregion()
  #define UPCRI_PLUS_REMOTE_OFFSET(thread) 	+ upcri_myregion()
  #define UPCRI_MINUS_REMOTE_OFFSET(thread) 	- upcri_myregion()
#else /* !UPCRI_SINGLE_ALIGNED_REGIONS, UPCRI_SYMMETRIC_PSHARED */
  #define UPCRI_SPTRS_USE_OFFSETS 1
  #define UPCRI_PLUS_MY_OFFSET			+ upcri_myregion()
  #define UPCRI_MINUS_MY_OFFSET			- upcri_myregion()
  #define UPCRI_PLUS_REMOTE_OFFSET(thread)	+ upcri_thread2region[thread]
  #define UPCRI_MINUS_REMOTE_OFFSET(thread)	- upcri_thread2region[thread]
#endif

/* 
 * Dummy values used by compiler to indicate a shared pointer that the user
 * has initialized the shared data pointed to by the sptr
 */
#if UPCRI_PACKED_SPTR
  GASNETT_INLINE(upcr_is_init_shared)
  int upcr_is_init_shared(upcr_shared_ptr_t sptr) {
      return (sptr == UPCR_INITIALIZED_SHARED);
  }

#else /* !UPCRI_PACKED_SPTR */
  GASNETT_INLINE(upcr_is_init_shared)
  int upcr_is_init_shared(upcr_shared_ptr_t sptr) {
      return ( ((uintptr_t)sptr.s_addr) == 1) && (sptr.s_thread == 0) && (sptr.s_phase == 0);
  }
#endif

#if UPCRI_PACKED_SPTR || UPCRI_SYMMETRIC_PSHARED
  GASNETT_INLINE(upcr_is_init_pshared)
  int upcr_is_init_pshared(upcr_pshared_ptr_t sptr) {
      return (sptr == UPCR_INITIALIZED_PSHARED);
  }
#else
  GASNETT_INLINE(upcr_is_init_pshared)
  int upcr_is_init_pshared(upcr_pshared_ptr_t sptr) {
      return (sptr.s_addr == 1) && (sptr.s_thread == 0);
  }
#endif

/* 
 * For setting and detecting NULL shared pointers (which for this
 * implementation means all fields are 0)
 */

#if UPCRI_PACKED_SPTR
  GASNETT_INLINE(upcr_setnull_shared)
  void upcr_setnull_shared(upcr_shared_ptr_t *psptr) {
    *psptr = UPCR_NULL_SHARED;
  }
  GASNETT_INLINE(upcr_isnull_shared)
  int upcr_isnull_shared(upcr_shared_ptr_t sptr) {
      (void) upcri_checkvalid_shared(sptr);
      return (sptr == UPCR_NULL_SHARED);
  }
#else /* !UPCRI_PACKED_SPTR */
  GASNETT_INLINE(upcr_setnull_shared)
  void upcr_setnull_shared(upcr_shared_ptr_t *psptr) {
      bzero((void *)psptr, sizeof(upcr_shared_ptr_t));
  }
  GASNETT_INLINE(upcr_isnull_shared)
  int upcr_isnull_shared(upcr_shared_ptr_t sptr) {
      (void) upcri_checkvalid_shared(sptr);
      return !sptr.s_addr;
  }
#endif

#if UPCRI_PACKED_SPTR || UPCRI_SYMMETRIC_PSHARED
  GASNETT_INLINE(upcr_setnull_pshared)
  void upcr_setnull_pshared(upcr_pshared_ptr_t *psptr) {
    *psptr = UPCR_NULL_PSHARED;
  }
  GASNETT_INLINE(upcr_isnull_pshared)
  int upcr_isnull_pshared(upcr_pshared_ptr_t sptr) {
      (void) upcri_checkvalid_pshared(sptr);
      return (sptr == UPCR_NULL_PSHARED);
  }
#else /* !UPCRI_PACKED_SPTR */
  GASNETT_INLINE(upcr_setnull_pshared)
  void upcr_setnull_pshared(upcr_pshared_ptr_t *psptr) {
      bzero((void *)psptr, sizeof(upcr_pshared_ptr_t));
  }
  GASNETT_INLINE(upcr_isnull_pshared)
  int upcr_isnull_pshared(upcr_pshared_ptr_t sptr) {
      (void) upcri_checkvalid_pshared(sptr);
      return !sptr.s_addr;
  }
#endif

/* Note: these variables are declared here even if
 * UPCRI_SPTR_H_DECLARE_VARIABLES is not defined, because they're needed in
 * some of the following functions.  Clients which don't link the runtime
 * (such as the Totalview assistant library) are responsible for ensuring
 * these get defined somewhere.
 */
extern const upcr_shared_ptr_t upcr_null_shared;
extern const upcr_pshared_ptr_t upcr_null_pshared;

/* Returns the thread number that has affinity to the given shared pointer, 
 * or 0 for a NULL shared pointer. If sptr is not a valid shared pointer, 
 * the results are undefined.
 */

GASNETT_INLINE(upcr_threadof_shared)
upcr_thread_t 
upcr_threadof_shared(upcr_shared_ptr_t sptr) 
{
  #if UPCRI_PACKED_SPTR
    return UPCRI_THREAD_OF(sptr);
  #else /* !UPCRI_PACKED_SPTR */
    return sptr.s_thread;
  #endif
}

GASNETT_INLINE(upcr_threadof_pshared)
upcr_thread_t 
upcr_threadof_pshared(upcr_pshared_ptr_t sptr) 
{
  #if UPCRI_SYMMETRIC_PSHARED
    return UPCRI_SYMMETRIC_THREADOF(sptr);
  #elif UPCRI_PACKED_SPTR
    return UPCRI_THREAD_OF(sptr);
  #else /* !UPCRI_PACKED_SPTR */
    return sptr.s_thread;
  #endif
}

/* Returns the phase field of the given shared pointer, 
 * Returns 0 for a NULL shared pointer or any pshared pointer.
 * Phase is expressed in number of elements
 */

GASNETT_INLINE(upcr_phaseof_shared)
upcr_phase_t upcr_phaseof_shared(upcr_shared_ptr_t sptr) 
{
  #if UPCRI_PACKED_SPTR
    return UPCRI_PHASE_OF(sptr);
  #else /* !UPCRI_PACKED_SPTR */
    return sptr.s_phase;
  #endif
}

/* always returns zero */
GASNETT_INLINE(upcr_phaseof_pshared)
upcr_phase_t 
upcr_phaseof_pshared(upcr_pshared_ptr_t sptr)
{
    return 0;
}

/* Returns an implementation-defined value reflecting the local address of the
 * object pointed to. This may or may not be the actual virtual address where
 * the object is stored - use upcr_to_local() when casting shared pointers to
 * local pointers.
 */
GASNETT_INLINE(upcr_addrfield_shared)
uintptr_t 
upcr_addrfield_shared(upcr_shared_ptr_t sptr) 
{
  #if UPCRI_PACKED_SPTR
    return UPCRI_ADDR_OF(sptr);
  #else /* !UPCRI_PACKED_SPTR */
    return sptr.s_addr;
  #endif
}

GASNETT_INLINE(upcr_addrfield_pshared)
uintptr_t 
upcr_addrfield_pshared(upcr_pshared_ptr_t sptr) 
{
  #if UPCRI_SYMMETRIC_PSHARED
    if_pf (sptr == UPCR_NULL_PSHARED)
	return 0;
    else
	return UPCRI_SYMMETRIC_ADDRFIELD((sptr-upcri_segsym_base));
  #elif UPCRI_PACKED_SPTR
    return UPCRI_ADDR_OF(sptr);
  #else /* !UPCRI_PACKED_SPTR */
    return sptr.s_addr;
  #endif
}

/* Creates a shared pointer from its three logical components: offset/addr,
 * thread, and phase (if phased).
 *  - Faster than local_to_shared functions, since no conversion from addr to
 *    offset is ever done.
 */
GASNETT_INLINE(upcri_addrfield_to_shared)
upcr_shared_ptr_t
upcri_addrfield_to_shared(uintptr_t addrfield, upcr_thread_t threadid, 
			  upcr_phase_t phase)
{
    upcr_shared_ptr_t p;

  #if UPCRI_PACKED_SPTR
    upcri_check_addr_overflow(addrfield);
    p = (((uint64_t)addrfield) << UPCRI_ADDR_SHIFT)
	| (((uint64_t)threadid) << UPCRI_THREAD_SHIFT) 
	| (((uint64_t)phase) << UPCRI_PHASE_SHIFT);
  #else
    p.s_addr = addrfield;
    p.s_thread = threadid;
    p.s_phase = phase;
  #endif

    return upcri_checkvalid_shared(p);
}

GASNETT_INLINE(upcri_addrfield_to_pshared)
upcr_pshared_ptr_t
upcri_addrfield_to_pshared(uintptr_t addrfield, upcr_thread_t threadid)
{
    upcr_pshared_ptr_t p;

  #if UPCRI_SYMMETRIC_PSHARED
    p = (upcr_pshared_ptr_t) addrfield UPCRI_PLUS_REMOTE_OFFSET(threadid);
  #elif UPCRI_PACKED_SPTR
    upcri_check_addr_overflow(addrfield);
    p = (((uint64_t)addrfield) << UPCRI_ADDR_SHIFT)
        | (((uint64_t)threadid) << UPCRI_THREAD_SHIFT);
  #else
    p.s_addr = addrfield;
    p.s_thread = threadid;
  #endif

    return upcri_checkvalid_pshared(p);
}

/* Convert a shared ptr with affinity to the current thread into a local
 * pointer.  If sptr does not have affinity to the calling thread the result
 * is implementation-specific
*/
#define upcr_shared_to_local(sptr) _upcr_shared_to_local(sptr UPCRI_PT_PASS)

GASNETT_INLINE(_upcr_shared_to_local)
void * 
_upcr_shared_to_local(upcr_shared_ptr_t sptr UPCRI_PT_ARG) 
{
    (void) upcri_checkvalid_shared(sptr);
    upcri_assert(upcr_isnull_shared(sptr) || upcr_threadof_shared(sptr) == upcr_mythread());
  #if UPCRI_SPTRS_USE_OFFSETS
    if (upcr_isnull_shared(sptr))
	return NULL;
  #endif
    return (void *) (upcr_addrfield_shared(sptr) UPCRI_PLUS_MY_OFFSET);
}

#define upcr_pshared_to_local(sptr) _upcr_pshared_to_local(sptr UPCRI_PT_PASS)

GASNETT_INLINE(_upcr_pshared_to_local)
void *
_upcr_pshared_to_local(upcr_pshared_ptr_t sptr UPCRI_PT_ARG) 
{
    (void) upcri_checkvalid_pshared(sptr);
    upcri_assert(upcr_isnull_pshared(sptr) || upcr_threadof_pshared(sptr) == upcr_mythread());
  #if UPCRI_SPTRS_USE_OFFSETS
    if (upcr_isnull_pshared(sptr))
	return NULL;
  #endif
  #if UPCRI_SYMMETRIC_PSHARED
    return (void *) (sptr); /* free! */
  #else
    return (void *) (upcr_addrfield_pshared(sptr) UPCRI_PLUS_MY_OFFSET);
  #endif
}

/* 'Fast' versions of cast to _to_local.
 * - These are used by get and put functions
 * - Pointer should be non-NULL.  Check for NULL and throw error only in debug
 *   mode, to avoid overhead for optimized programs
 */
#define upcri_shared_to_local_fast(sptr) \
       _upcri_shared_to_local_fast(sptr, __FILE__, __LINE__ UPCRI_PT_PASS)

GASNETT_INLINE(_upcri_shared_to_local_fast)
void * 
_upcri_shared_to_local_fast(upcr_shared_ptr_t sptr, const char *filename, 
			    int linenum UPCRI_PT_ARG) 
{
  #if UPCR_DEBUG
    _upcri_checkvalidlocal_shared(sptr, filename, linenum);
  #endif
    return (void *) (upcr_addrfield_shared(sptr) UPCRI_PLUS_MY_OFFSET);
}

#define upcri_pshared_to_local_fast(sptr) \
       _upcri_pshared_to_local_fast(sptr, __FILE__, __LINE__ UPCRI_PT_PASS)

GASNETT_INLINE(_upcri_pshared_to_local_fast)
void *
_upcri_pshared_to_local_fast(upcr_pshared_ptr_t sptr, const char *filename, 
			    int linenum UPCRI_PT_ARG) 
{
  #if UPCR_DEBUG
    _upcri_checkvalidlocal_pshared(sptr, filename, linenum);
  #endif
  #if UPCRI_SYMMETRIC_PSHARED
    return (void *) (sptr); /* free! */
  #else
    return (void *) (upcr_addrfield_pshared(sptr) UPCRI_PLUS_MY_OFFSET);
  #endif
}


/* Get 'local' portion of shared pointer, regardless of the thread it points
 * to.  Equivalent to forcing threadof(sptr) to MYTHREAD, then casting to
 * local.
 */
#define upcri_shared_remote_to_mylocal(sptr) \
       _upcri_shared_remote_to_mylocal(sptr UPCRI_PT_PASS)

GASNETT_INLINE(_upcri_shared_remote_to_mylocal)
void * 
_upcri_shared_remote_to_mylocal(upcr_shared_ptr_t sptr UPCRI_PT_ARG) 
{
    (void) upcri_checkvalid_shared(sptr);
  #if UPCRI_SPTRS_USE_OFFSETS
    if (upcr_isnull_shared(sptr))
	return NULL;
  #endif
    return (void *) (upcr_addrfield_shared(sptr) UPCRI_PLUS_MY_OFFSET);
}
/* 
 * Return local address for shared data on a remote node.
 *  - will give correct addr if pointer points to local shared
 *    memory, but is slower than using upcr_shared_to_local.
 *  - offset versions: offset is applied to remote addr, not shared pointer
 *  - 'withthread' version: returns virtual address corresponding to shared
 *    ptr's addrfield on an arbitrary thread.
 */

#define upcri_shared_to_remote(sptr) \
       _upcri_shared_to_remote(sptr UPCRI_TV_PASS)

GASNETT_INLINE(_upcri_shared_to_remote)
void *
_upcri_shared_to_remote(upcr_shared_ptr_t sptr UPCRI_TV_ARG)
{
    (void) upcri_checkvalid_shared(sptr);
    return (void*) ( upcr_addrfield_shared(sptr) 
	             UPCRI_PLUS_REMOTE_OFFSET(upcr_threadof_shared(sptr)) );
}

#define upcri_shared_to_remote_off(sptr, offset) \
       _upcri_shared_to_remote_off(sptr, offset UPCRI_TV_PASS)

GASNETT_INLINE(_upcri_shared_to_remote_off)
void *
_upcri_shared_to_remote_off(upcr_shared_ptr_t sptr, ptrdiff_t offset UPCRI_TV_ARG)
{
    (void) upcri_checkvalid_shared(sptr);
    return (void*) ( upcr_addrfield_shared(sptr) + offset
	             UPCRI_PLUS_REMOTE_OFFSET(upcr_threadof_shared(sptr)) );
}

#define upcri_pshared_to_remote(sptr) \
       _upcri_pshared_to_remote(sptr UPCRI_TV_PASS)

GASNETT_INLINE(_upcri_pshared_to_remote)
void *
_upcri_pshared_to_remote(upcr_pshared_ptr_t sptr UPCRI_TV_ARG)
{
    (void) upcri_checkvalid_pshared(sptr);
    #if UPCRI_SYMMETRIC_PSHARED
      return (void*) (sptr); /* free */
    #else
      return (void*) ( upcr_addrfield_pshared(sptr) 
	             UPCRI_PLUS_REMOTE_OFFSET(upcr_threadof_pshared(sptr)) );
    #endif
}

#define upcri_pshared_to_remote_off(sptr, offset) \
       _upcri_pshared_to_remote_off(sptr, offset UPCRI_TV_PASS)

GASNETT_INLINE(_upcri_pshared_to_remote_off)
void *
_upcri_pshared_to_remote_off(upcr_pshared_ptr_t sptr, ptrdiff_t offset UPCRI_TV_ARG)
{
    (void) upcri_checkvalid_pshared(sptr);
    #if UPCRI_SYMMETRIC_PSHARED
      return (void*) (sptr + offset);
    #else
      return (void*) ( upcr_addrfield_pshared(sptr) + offset
	               UPCRI_PLUS_REMOTE_OFFSET(upcr_threadof_pshared(sptr)) );
    #endif
}

/* Returns virtual address corresponding to shared ptr's addrfield, but on an
 * arbitrary thread, i.e. returns the virtual address "as if" you changed the
 * ptr's thread field to the specified value.
 */
#define upcri_shared_to_remote_withthread(sptr, thread) \
       _upcri_shared_to_remote_withthread(sptr, thread UPCRI_TV_PASS)

GASNETT_INLINE(_upcri_shared_to_remote_withthread)
void *
_upcri_shared_to_remote_withthread(upcr_shared_ptr_t sptr, upcr_thread_t threadno UPCRI_TV_ARG)
{
    (void) upcri_checkvalid_shared(sptr);
    upcri_assert(threadno < upcr_threads());
    return (void *) (upcr_addrfield_shared(sptr)
		     UPCRI_PLUS_REMOTE_OFFSET(threadno));
}

#define upcri_pshared_to_remote_withthread(sptr, thread) \
       _upcri_pshared_to_remote_withthread(sptr, thread UPCRI_TV_PASS)

GASNETT_INLINE(_upcri_pshared_to_remote_withthread)
void *
_upcri_pshared_to_remote_withthread(upcr_pshared_ptr_t sptr, upcr_thread_t threadno UPCRI_TV_ARG)
{
    (void) upcri_checkvalid_pshared(sptr);
    upcri_assert(threadno < upcr_threads());
    return (void *) (upcr_addrfield_pshared(sptr)
		     UPCRI_PLUS_REMOTE_OFFSET(threadno));
}

/* Convert a local ptr in the current thread's shared memory space into a
 * shared pointer appropriate for use in remote operations from other threads.
 * The phase field is set to zero. Some implementations may issue an error if
 * lptr does not point into the shared region for the current thread.  Note this
 * operation is not accessible from the UPC source level, but may be useful for
 * generated code nonetheless (e.g. to support a debugger) The _ref versions
 * modify a shared pointer in place rather than returning a shared pointer
 * value, which may be more efficient in some implementations
*/

#define upcr_local_to_shared(void_lptr) \
       _upcr_local_to_shared(void_lptr UPCRI_PT_PASS)
#define upcr_local_to_shared_ref(void_lptr, result) \
       _upcr_local_to_shared_ref(void_lptr, result UPCRI_PT_PASS) 
#define upcr_local_to_pshared(void_lptr) \
       _upcr_local_to_pshared(void_lptr UPCRI_PT_PASS)
#define upcr_local_to_pshared_ref(lptr, result) \
       _upcr_local_to_pshared_ref(lptr, result, UPCRI_PT_PASS)

GASNETT_INLINE(_upcr_local_to_shared)
upcr_shared_ptr_t 
_upcr_local_to_shared(void *lptr UPCRI_PT_ARG) 
{
    upcr_shared_ptr_t p;
    if (lptr == NULL)
	return upcr_null_shared;
  #if UPCRI_PACKED_SPTR
    upcri_check_addr_overflow( ((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET);
    p = (((uint64_t) (((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET)) << UPCRI_ADDR_SHIFT)
	  | (((uint64_t)upcr_mythread()) << UPCRI_THREAD_SHIFT);
  #else /* struct-based ptr w/aligned segments */
    p.s_addr = ((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET;
    p.s_thread = upcr_mythread();
    p.s_phase = 0;
  #endif
    return upcri_checkvalid_shared(p);
}

GASNETT_INLINE(_upcr_local_to_shared_ref)
void 
_upcr_local_to_shared_ref(void *lptr, upcr_shared_ptr_t *result UPCRI_PT_ARG) 
{
    if (lptr == NULL) { 
	*result = upcr_null_shared; /* thread/phase must be 0 for NULL ptr */
	return;
    }
  #if UPCRI_PACKED_SPTR
    upcri_check_addr_overflow( ((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET);
    *result = (((uint64_t) (((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET)) << UPCRI_ADDR_SHIFT)
	        | (((uint64_t)upcr_mythread()) << UPCRI_THREAD_SHIFT);
  #else
    result->s_addr = ((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET;
    result->s_thread = upcr_mythread();
    result->s_phase = 0;
  #endif
  (void) upcri_checkvalid_shared(*result);
}

GASNETT_INLINE(_upcr_local_to_pshared)
upcr_pshared_ptr_t 
_upcr_local_to_pshared(void *lptr UPCRI_PT_ARG) 
{
    upcr_pshared_ptr_t p;
    if (lptr == NULL) 
	return upcr_null_pshared; /* thread/phase must be 0 for NULL ptr */
  #if UPCRI_SYMMETRIC_PSHARED
    p = (upcr_pshared_ptr_t)(lptr); /* free */
  #elif UPCRI_PACKED_SPTR
    upcri_check_addr_overflow( ((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET);
    p = (((uint64_t) (((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET)) << UPCRI_ADDR_SHIFT)
	  | (((uint64_t)upcr_mythread()) << UPCRI_THREAD_SHIFT);
  #else
    p.s_addr = ((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET;
    p.s_thread = upcr_mythread();
  #endif
    return upcri_checkvalid_pshared(p);
}

GASNETT_INLINE(_upcr_local_to_pshared_ref)
void 
_upcr_local_to_pshared_ref(void *lptr, upcr_pshared_ptr_t *result UPCRI_PT_ARG) 
{
    if (lptr == NULL)
	*result = upcr_null_pshared; /* thread/phase must be 0 for NULL ptr */
  #if UPCRI_SYMMETRIC_PSHARED
    *result = (upcr_pshared_ptr_t)(lptr); /* free */
  #elif UPCRI_PACKED_SPTR
    upcri_check_addr_overflow( ((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET);
    *result = (((uint64_t) (((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET)) << UPCRI_ADDR_SHIFT)
	        | (((uint64_t)upcr_mythread()) << UPCRI_THREAD_SHIFT);
  #else
    result->s_addr = ((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET;
    result->s_thread = upcr_mythread();
  #endif
  (void) upcri_checkvalid_pshared(*result);
}

/* Same as above, but sets the phase and thread to a particular value. 
 * Phase is expressed in number of elements
 * AM-safe
 */

#define upcr_local_to_shared_withphase(lptr, phase, threadid) \
       _upcr_local_to_shared_withphase(lptr, phase, threadid UPCRI_TV_PASS)

GASNETT_INLINE(_upcr_local_to_shared_withphase)
upcr_shared_ptr_t 
_upcr_local_to_shared_withphase(void *lptr, upcr_phase_t phase, 
			        upcr_thread_t threadid UPCRI_TV_ARG) 
{
    upcr_shared_ptr_t p;
    if (lptr == NULL) 
	return upcr_null_shared; /* thread/phase must be 0 for NULL ptr */
  #if UPCRI_PACKED_SPTR
    upcri_check_addr_overflow(((uintptr_t)lptr)
				UPCRI_MINUS_REMOTE_OFFSET(threadid));
    p = (((uint64_t) (((uintptr_t)lptr) UPCRI_MINUS_REMOTE_OFFSET(threadid))) << UPCRI_ADDR_SHIFT)
	| (((uint64_t)threadid) << UPCRI_THREAD_SHIFT) 
	| (((uint64_t)phase) << UPCRI_PHASE_SHIFT);
  #else
    p.s_addr = ((uintptr_t)lptr) UPCRI_MINUS_REMOTE_OFFSET(threadid);
    p.s_thread = threadid;
    p.s_phase = phase;
  #endif
    return upcri_checkvalid_shared(p);
}

#define upcr_local_to_shared_ref_withphase(lptr, phase, threadid, ref) \
       _upcr_local_to_shared_ref_withphase(lptr, phase, threadid, ref UPCRI_TV_PASS)

GASNETT_INLINE(_upcr_local_to_shared_ref_withphase)
void 
_upcr_local_to_shared_ref_withphase(void *lptr, upcr_phase_t phase, 
		    upcr_thread_t threadid, upcr_shared_ptr_t *ref UPCRI_TV_ARG) 
{
    if (lptr == NULL) 
	*ref = upcr_null_shared; /* thread/phase must be 0 for NULL ptr */
  #if UPCRI_PACKED_SPTR
    upcri_check_addr_overflow(((uintptr_t)lptr)
				UPCRI_MINUS_REMOTE_OFFSET(threadid));
    *ref = (((uint64_t) (((uintptr_t)lptr) UPCRI_MINUS_REMOTE_OFFSET(threadid))) << UPCRI_ADDR_SHIFT)
	   | (((uint64_t)threadid) << UPCRI_THREAD_SHIFT) 
	   | (((uint64_t)phase) << UPCRI_PHASE_SHIFT);
  #else
    ref->s_addr = ((uintptr_t)lptr) UPCRI_MINUS_REMOTE_OFFSET(threadid);
    ref->s_thread = threadid;
    ref->s_phase = phase;
  #endif
  (void) upcri_checkvalid_shared(*ref);
}

/* Converts a local ptr value to a shared ptr, always using the current
 * thread's offset, but setting the thread/phase to any arbitrary value. 
 */
#define upcr_mylocal_to_shared_withphase(lptr, phase, threadid) \
       _upcr_mylocal_to_shared_withphase(lptr, phase, threadid UPCRI_PT_PASS)

GASNETT_INLINE(_upcr_mylocal_to_shared_withphase)
upcr_shared_ptr_t 
_upcr_mylocal_to_shared_withphase(void *lptr, upcr_phase_t phase, 
			        upcr_thread_t threadid UPCRI_PT_ARG) 
{
    upcr_shared_ptr_t p;
    if (lptr == NULL) 
	return upcr_null_shared; /* thread/phase must be 0 for NULL ptr */
  #if UPCRI_PACKED_SPTR
    upcri_check_addr_overflow(((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET);
    p = (((uint64_t) (((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET)) << UPCRI_ADDR_SHIFT)
	| (((uint64_t)threadid) << UPCRI_THREAD_SHIFT) 
	| (((uint64_t)phase) << UPCRI_PHASE_SHIFT);
  #else
    p.s_addr = ((uintptr_t)lptr) UPCRI_MINUS_MY_OFFSET;
    p.s_thread = threadid;
    p.s_phase = phase;
  #endif
    return upcri_checkvalid_shared(p);
}

/* Convert back and forth between shared and pshared representations
 * upcr_pshared_to_shared sets phase to zero The _ref versions modify a shared
 * pointer in place rather than returning a shared pointer value, which may be
 * more efficient in some implementations
 */

GASNETT_INLINE(upcr_shared_to_pshared)
upcr_pshared_ptr_t 
upcr_shared_to_pshared(upcr_shared_ptr_t sptr)
{
    upcr_pshared_ptr_t p;
   
  (void) upcri_checkvalid_shared(sptr); 
  #if UPCRI_SYMMETRIC_PSHARED
    if (upcr_isnull_shared(sptr))
	p = UPCR_NULL_PSHARED;
    else
        p = (upcr_pshared_ptr_t) (
	     upcr_addrfield_shared(sptr) 
	     UPCRI_PLUS_REMOTE_OFFSET(upcr_threadof_shared(sptr)));
  #elif UPCRI_PACKED_SPTR
    p = (sptr & ~UPCRI_PHASE_MASK);
  #else
    p.s_addr = sptr.s_addr;
    p.s_thread = sptr.s_thread;
  #endif
    return upcri_checkvalid_pshared(p);
}

GASNETT_INLINE(upcr_shared_to_pshared_ref)
void 
upcr_shared_to_pshared_ref(upcr_shared_ptr_t sptr, upcr_pshared_ptr_t *result)
{
  (void) upcri_checkvalid_shared(sptr);
  #if UPCRI_SYMMETRIC_PSHARED
    if (upcr_isnull_shared(sptr))
	*result = UPCR_NULL_PSHARED;
    else
        *result = (upcr_pshared_ptr_t) (
	  upcr_addrfield_shared(sptr) 
	  UPCRI_PLUS_REMOTE_OFFSET(upcr_threadof_shared(sptr)));
  #elif UPCRI_PACKED_SPTR
    *result = (sptr & ~UPCRI_PHASE_MASK);
  #else
    result->s_addr = sptr.s_addr;
    result->s_thread = sptr.s_thread;
  #endif
  (void) upcri_checkvalid_pshared(*result);
}

GASNETT_INLINE(upcr_pshared_to_shared)
upcr_shared_ptr_t 
upcr_pshared_to_shared(upcr_pshared_ptr_t sptr)
{
  (void) upcri_checkvalid_pshared(sptr);
  #if UPCRI_PACKED_SPTR
    #if UPCRI_SYMMETRIC_PSHARED
      return upcri_checkvalid_shared(
	    ((((uint64_t) upcr_addrfield_pshared(sptr)) << UPCRI_ADDR_SHIFT)
            | (((uint64_t)upcr_threadof_pshared(sptr)) << UPCRI_THREAD_SHIFT))
	   );
    #else
      return upcri_checkvalid_shared((upcr_shared_ptr_t)sptr);
    #endif
  #else
    { 
	upcr_shared_ptr_t p;
	p.s_addr = upcr_addrfield_pshared(sptr);
	p.s_thread = upcr_threadof_pshared(sptr);
	p.s_phase = 0;
	return upcri_checkvalid_shared(p);
    }
  #endif
}

GASNETT_INLINE(upcr_pshared_to_shared_ref)
void 
upcr_pshared_to_shared_ref(upcr_pshared_ptr_t sptr, upcr_shared_ptr_t *result)
{
  (void) upcri_checkvalid_pshared(sptr);
  #if UPCRI_PACKED_SPTR
    #if UPCRI_SYMMETRIC_PSHARED
      *result =  ((((uint64_t) upcr_addrfield_pshared(sptr)) << UPCRI_ADDR_SHIFT)
	         | (((uint64_t)upcr_threadof_pshared(sptr)) << UPCRI_THREAD_SHIFT));
    #else
      upcri_assert((sptr & UPCRI_PHASE_MASK) == 0);
      *result = sptr;
    #endif
  #else
    result->s_addr = upcr_addrfield_pshared(sptr);
    result->s_thread = upcr_threadof_pshared(sptr);
    result->s_phase = 0;
  #endif
  (void) upcri_checkvalid_shared(*result);
}

/* Same as above, but sets the phase to a particular value. 
 * phase is expressed in number of elements
 */

GASNETT_INLINE(upcr_pshared_to_shared_withphase)
upcr_shared_ptr_t 
upcr_pshared_to_shared_withphase(upcr_pshared_ptr_t sptr, upcr_phase_t phase)
{
    upcr_shared_ptr_t p;

  (void) upcri_checkvalid_pshared(sptr);
  #if UPCRI_PACKED_SPTR
    #if UPCRI_SYMMETRIC_PSHARED
      p = (((uint64_t) upcr_addrfield_pshared(sptr)) << UPCRI_ADDR_SHIFT)
	  | (((uint64_t)upcr_threadof_pshared(sptr)) << UPCRI_THREAD_SHIFT)
	  | ((((uint64_t)phase << UPCRI_PHASE_SHIFT)) & UPCRI_PHASE_MASK);
    #else
      p = sptr | (((uint64_t)phase << UPCRI_PHASE_SHIFT) 
		& UPCRI_PHASE_MASK);
    #endif
  #else
    p.s_addr = upcr_addrfield_pshared(sptr);
    p.s_thread = upcr_threadof_pshared(sptr);
    p.s_phase = phase;
  #endif
    return upcri_checkvalid_shared(p);
}

GASNETT_INLINE(upcr_pshared_to_shared_ref_withphase)
void 
upcr_pshared_to_shared_ref_withphase(upcr_pshared_ptr_t sptr, upcr_phase_t phase, 
				   upcr_shared_ptr_t *result)
{
  (void) upcri_checkvalid_pshared(sptr);
  #if UPCRI_PACKED_SPTR
    #if UPCRI_SYMMETRIC_PSHARED
      *result = (((uint64_t) upcr_addrfield_pshared(sptr)) << UPCRI_ADDR_SHIFT)
	        | (((uint64_t)upcr_threadof_pshared(sptr)) << UPCRI_THREAD_SHIFT)
	        | (((uint64_t)phase << UPCRI_PHASE_SHIFT) & UPCRI_PHASE_MASK);
    #else
      *result = sptr | ((((uint64_t)phase) << UPCRI_PHASE_SHIFT)
			  & UPCRI_PHASE_MASK);
    #endif
  #else
    result->s_addr = (uintptr_t) upcr_addrfield_pshared(sptr);
    result->s_thread = upcr_threadof_pshared(sptr);
    result->s_phase = phase;
  #endif
  (void) upcri_checkvalid_shared(*result);
}

/* Reset the phase field of a given shared pointer to zero
 * (used for casting between block sizes)
 */

GASNETT_INLINE(upcr_shared_resetphase)
upcr_shared_ptr_t 
upcr_shared_resetphase(upcr_shared_ptr_t sptr)
{
    upcr_shared_ptr_t p;

  (void) upcri_checkvalid_shared(sptr);
  #if UPCRI_PACKED_SPTR
    p = (sptr & ~UPCRI_PHASE_MASK);
  #else
    p.s_addr = sptr.s_addr;
    p.s_thread = sptr.s_thread;
    p.s_phase = 0;
  #endif
    return upcri_checkvalid_shared(p);
}

GASNETT_INLINE(upcr_shared_resetphase_ref)
void 
upcr_shared_resetphase_ref(upcr_shared_ptr_t *sptr)
{
  (void) upcri_checkvalid_shared(*sptr);
  #if UPCRI_PACKED_SPTR
    *sptr &= ~UPCRI_PHASE_MASK;
  #else
    sptr->s_phase = 0;
  #endif
  (void) upcri_checkvalid_shared(*sptr);
}

/* upcr_affinitysize calculates the exact size of the local portion of the
 * data in a shared object with affinity to a given thread, specified by
 * threadid.  totalsize should be the total number of bytes in the shared
 * object. nbytes is the block size in BYTES.
 */
#define upcri_divfloor(a,b) ((a)/(b))
#define upcri_divceil(a,b) ((((a)-1)/(b)) + 1)

#define upcr_affinitysize(totalsize, nbytes, threadid) \
       _upcr_affinitysize(totalsize, nbytes, threadid UPCRI_TV_PASS)

GASNETT_INLINE(_upcr_affinitysize)
size_t 
_upcr_affinitysize(size_t totalsize, size_t nbytes, upcr_thread_t threadid UPCRI_TV_ARG) 
{
    if (nbytes == 0 || totalsize == 0 || nbytes >= totalsize) 
        return (size_t) (threadid == 0 ? totalsize : 0);
    else {
      upcr_thread_t const numthreads = upcr_threads();
      size_t const nblocks = upcri_divfloor(totalsize, nbytes);
      size_t const cutoff = (nblocks % numthreads);

      if (threadid < (upcr_thread_t)cutoff)
        return (size_t) (upcri_divceil(nblocks, numthreads) * nbytes);
      else if (threadid > (upcr_thread_t)cutoff)
        return (size_t) (upcri_divfloor(nblocks, numthreads) * nbytes);
      else /* threadid == cutoff */
	return (size_t) (upcri_divfloor(nblocks, numthreads) * nbytes) +
                        totalsize - nblocks * nbytes;
    }
}


/* Shared pointer increments/decrements - 
 * add a positive or negative displacement to a shared pointer. 
 * Both the inc and blockelems arguments should be expressed in number of elements
 * elemsz is the target element size in bytes
 * The "add" versions return an updated shared pointer, 
 * the "inc" versions modify the input shared pointer in place. 
 *
 * Pointers with a definite static blocksize > 1 should use the "shared" version, 
 * shared pointers with indef blocksize use the "psharedI" version
 * shared pointers with blocksize == 1 use the "pshared1" version
 */
#define upcr_add_shared(sptr, elemsz, inc, blockelems) \
       _upcr_add_shared(sptr, elemsz, inc, blockelems UPCRI_PT_PASS)

GASNETT_INLINE(_upcr_add_shared)
upcr_shared_ptr_t 
_upcr_add_shared(upcr_shared_ptr_t sptr, size_t elemsz, ptrdiff_t inc, 
		size_t blockelems UPCRI_PT_ARG)
{
    uintptr_t out_addr;
    upcr_thread_t out_thread;
    upcr_phase_t out_phase;
    ssize_t block_incr;

    size_t const numthreads = upcr_threads();
    upcr_thread_t const sptr_thread = upcr_threadof_shared(sptr);
    upcr_phase_t const sptr_phase = upcr_phaseof_shared(sptr);
    ptrdiff_t const phase_plus = sptr_phase + inc;

    (void) upcri_checkvalid_shared(sptr);
    upcri_assert(elemsz > 0);
    upcri_assert((ssize_t)blockelems > 0);
    upcri_assert((ssize_t)numthreads > 0);

    if (UPCRI_CONSTANT_P(inc) && (inc == 0)) {
      return sptr;
    } else
    if (UPCRI_CONSTANT_P(inc) && (inc == 1)) {
      out_phase = phase_plus;
      out_thread = sptr_thread;
      block_incr = 0;
      if (phase_plus == (ptrdiff_t)blockelems) { /* Wrap */
        out_phase = 0;
        if (++out_thread == numthreads) { /* Wrap */
          out_thread = 0;
          block_incr = 1;
        }
      }
    } else
    if (UPCRI_CONSTANT_P(inc) && (inc == -1)) {
      out_phase = phase_plus;
      out_thread = sptr_thread;
      block_incr = 0;
      if (!sptr_phase) { /* Wrap */
        out_phase = blockelems - 1;
        if (out_thread-- == 0) { /* Wrap */
          out_thread = numthreads - 1;
          block_incr = -1;
        }
      }
    } else
    if (UPCRI_CONSTANT_P(inc) && UPCRI_CONSTANT_P(blockelems) && (inc == blockelems)) {
      out_phase = sptr_phase;
      out_thread = sptr_thread + 1;
      block_incr = 0;
      if (out_thread == numthreads) { /* Wrap */
        out_thread = 0;
        block_incr = 1;
      }
    } else
    if (UPCRI_CONSTANT_P(inc) && UPCRI_CONSTANT_P(blockelems) && (inc == -blockelems)) {
      out_phase = sptr_phase;
      out_thread = sptr_thread - 1;
      block_incr = 0;
      if (sptr_thread == 0) { /* Wrap */
        out_thread = numthreads - 1;
        block_incr = -1;
      }
    } else
    #if __UPC_STATIC_THREADS__
      if (UPCRI_CONSTANT_P(inc) && UPCRI_CONSTANT_P(blockelems) &&
          (inc > 0) && !(inc % (blockelems * THREADS))) {
        out_phase = sptr_phase;
        out_thread = sptr_thread;
        block_incr = inc / (blockelems * THREADS); /* compile-time constant */
      } else
      if (UPCRI_CONSTANT_P(inc) && UPCRI_CONSTANT_P(blockelems) &&
          (inc < 0) && !(-inc % (blockelems * THREADS))) {
        out_phase = sptr_phase;
        out_thread = sptr_thread;
        block_incr = - ((-inc) / (blockelems * THREADS)); /* compile-time constant */
      } else
    #endif
    if (inc >= 0) {
	size_t thread_incr;
        if (UPCRI_CONSTANT_P(inc) && UPCRI_CONSTANT_P(blockelems) && !(inc % blockelems)) {
	    thread_incr = inc / blockelems; /* compile-time constant */
	    out_phase = sptr_phase;
        } else
        {
	    thread_incr = phase_plus / blockelems;
	    out_phase = phase_plus % blockelems;
        }
	block_incr = (sptr_thread + thread_incr) / numthreads;
	out_thread = (sptr_thread + thread_incr) % numthreads;
    } else {
	ssize_t numer, denom, thread_incr; /* These must be signed */

        if (UPCRI_CONSTANT_P(inc) && UPCRI_CONSTANT_P(blockelems) && !(-inc % blockelems)) {
	    thread_incr = - ((-inc) / blockelems); /* compile-time constant */
	    out_phase = sptr_phase;
        } else
        {
	    denom = blockelems;
	    numer = phase_plus + (1 - denom);
	    thread_incr = numer / denom;
	    out_phase = (numer % denom) + (denom - 1);
        }

	denom = numthreads;
	numer = sptr_thread + thread_incr + (1 - denom);
      #if PLATFORM_COMPILER_PATHSCALE /* Bug 2935 */
        {
          ldiv_t ld = ldiv(numer, denom);
          block_incr = ld.quot;
          out_thread = ld.rem + (denom - 1);
        }
      #else
	block_incr = numer / denom;
	out_thread = (numer % denom) + (denom - 1);
      #endif
    }

    #if UPCRI_DEBUG_SPTR_ARITH
    {
      const ptrdiff_t ph_diff = (ptrdiff_t)out_phase - (ptrdiff_t)sptr_phase;
      const ptrdiff_t th_diff = (ptrdiff_t)out_thread - (ptrdiff_t)sptr_thread;
      if_pf (inc != (ph_diff + blockelems*(th_diff + numthreads * block_incr))) {
        upcri_err("phased shared pointer add FAILED for incr=%ld\n", (long)inc);
      }
    }
    #endif

    {
      size_t elemaddr_incr = ((ssize_t)out_phase - sptr_phase) + (block_incr*blockelems);
      out_addr = upcr_addrfield_shared(sptr) + (elemaddr_incr*(ssize_t)elemsz);
    }

    return upcri_checkvalid_shared(
           upcri_addrfield_to_shared(out_addr, out_thread, out_phase));
}

#define upcr_inc_shared(psptr, elesz, inc, blockelems) \
       _upcr_inc_shared(psptr, elesz, inc, blockelems UPCRI_PT_PASS)

GASNETT_INLINE(_upcr_inc_shared)
void 
_upcr_inc_shared(upcr_shared_ptr_t *psptr, size_t elemsz, ptrdiff_t inc, 
		size_t blockelems UPCRI_PT_ARG)
{
    /* TODO: write a real version */
    (void) upcri_checkvalid_shared(*psptr);
    upcri_assert(elemsz > 0);
    *psptr = upcr_add_shared(*psptr, elemsz, inc, blockelems);
    (void) upcri_checkvalid_shared(*psptr);
}


/*  Adds shared pointers with indef blocksize */
GASNETT_INLINE(upcr_inc_psharedI)
void
upcr_inc_psharedI(upcr_pshared_ptr_t *psptr, size_t elemsz, ptrdiff_t inc)
{
  (void) upcri_checkvalid_pshared(*psptr);
  upcri_assert(elemsz > 0);
  #if UPCRI_SYMMETRIC_PSHARED
    *psptr = (char *) (*psptr + (inc * (ssize_t)elemsz));
  #elif UPCRI_PACKED_SPTR
    /* must use fully-signed math for negative inc to work correctly */
    *psptr = (uint64_t) (((int64_t)*psptr) + ((int64_t)(inc * (ssize_t)elemsz) << UPCRI_ADDR_SHIFT));
  #else
    psptr->s_addr += (inc * elemsz);
  #endif
  (void) upcri_checkvalid_pshared(*psptr);
}

GASNETT_INLINE(upcr_add_psharedI)
upcr_pshared_ptr_t 
upcr_add_psharedI(upcr_pshared_ptr_t sptr, size_t elemsz, ptrdiff_t inc)
{
    upcr_pshared_ptr_t out;
  (void) upcri_checkvalid_pshared(sptr);
  upcri_assert(elemsz > 0);
  #if UPCRI_SYMMETRIC_PSHARED
    out = (char *) (sptr + (inc * (ssize_t)elemsz));
  #elif UPCRI_PACKED_SPTR
    out = (uint64_t) (((int64_t)sptr) + ((int64_t)(inc * (ssize_t)elemsz) << UPCRI_ADDR_SHIFT));
  #else
    out = sptr;  /* bitwise copy */
    upcr_inc_psharedI(&out, elemsz, inc); 
  #endif
    return upcri_checkvalid_pshared(out);
}

#if UPCRI_SYMMETRIC_PSHARED
GASNETT_INLINE(upcr_inc_pshared1)
void
upcr_inc_pshared1(upcr_pshared_ptr_t *psptr, size_t elemsz, ptrdiff_t inc)
{
    char    *ptr_off;

    upcri_assert(elemsz > 0);
    if (inc >= 0) {
	ptr_off = (*psptr - upcri_segsym_base) + 
		  (char *)(inc*upcri_segsym_region_size);
	*psptr = upcri_segsym_base + UPCRI_SYMMETRIC_MOD(ptr_off)
		 + UPCRI_SYMMETRIC_DIV(ptr_off)*elemsz;
    }
    else {
	ptr_off = (char *)(upcri_segsym_end - elemsz - *psptr - 
			   inc*upcri_segsym_region_size);
	*psptr  = (char *)(upcri_segsym_end - elemsz - 
			   (UPCRI_SYMMETRIC_MOD(ptr_off) + 
			    UPCRI_SYMMETRIC_DIV(ptr_off)*elemsz));
    }

    (void) upcri_checkvalid_pshared(*psptr);
}

#else /* !UPCRI_SYMMETRIC_PSHARED */

#define upcr_inc_pshared1(psptr, elemsz, inc) \
       _upcr_inc_pshared1(psptr, elemsz, inc UPCRI_TV_PASS)

GASNETT_INLINE(_upcr_inc_pshared1)
void
_upcr_inc_pshared1(upcr_pshared_ptr_t *psptr, size_t elemsz, ptrdiff_t inc UPCRI_TV_ARG)
{
    #if PLATFORM_COMPILER_GCC && PLATFORM_COMPILER_VERSION_EQ(3,2,3) && PLATFORM_ARCH_X86_64
      /* bug1486: workaround a gcc optimizer crash tickled by this code on XT-3 */
      long numthreads = upcri_threads;
    #else
      long numthreads = upcr_threads();
    #endif
    uintptr_t addr;
    ptrdiff_t block_incr;
    upcr_thread_t threadid;

    (void) upcri_checkvalid_pshared(*psptr);
    upcri_assert(elemsz > 0);

    /* TODO: result of division/modulo of negative numbers are not
     * standardized in ANSI C: will need different logic for architectures
     * that do not round negative results up toward 0. 
     * PHH: C99 requires "truncation toward zero", right?
     */
    if (UPCRI_CONSTANT_P(inc) && (inc == 0)) {
      return;
    } else
    if (UPCRI_CONSTANT_P(inc) && (inc == 1)) {
      threadid = upcr_threadof_pshared(*psptr);
      block_incr = 0;
      if (++threadid == numthreads) { /* Wrap */
        threadid = 0;
        block_incr = 1;
      }
    } else
    if (UPCRI_CONSTANT_P(inc) && (inc == -1)) {
      threadid = upcr_threadof_pshared(*psptr);
      block_incr = 0;
      if (threadid-- == 0) { /* Wrap */
        threadid = numthreads - 1;
        block_incr = -1;
      }
    } else
    #if __UPC_STATIC_THREADS__
      if (UPCRI_CONSTANT_P(inc) && (inc > 0) && !(inc % THREADS)) {
        threadid = upcr_threadof_pshared(*psptr);
        block_incr = inc / THREADS; /* compile-time constant */
      } else
      if (UPCRI_CONSTANT_P(inc) && (inc < 0) && !(-inc % THREADS)) {
        threadid = upcr_threadof_pshared(*psptr);
        block_incr = - ((-inc) / THREADS); /* compile-time constant */
      } else
    #endif
    {
      ptrdiff_t const modoff = (inc >= 0) ? 0 : 1 - numthreads;
      ptrdiff_t const tsum = upcr_threadof_pshared(*psptr) + inc + modoff;
      block_incr = tsum / numthreads;
      threadid = (tsum % numthreads) - modoff;
    }

    #if UPCRI_DEBUG_SPTR_ARITH
    {
      const ptrdiff_t th_diff = (ptrdiff_t)threadid - (ptrdiff_t)upcr_threadof_pshared(*psptr);
      if_pf (inc != (th_diff + numthreads * block_incr)) {
        upcri_err("cyclic shared pointer inc FAILED for incr=%ld\n", (long)inc);
      }
    }
    #endif

    addr = upcr_addrfield_pshared(*psptr) + block_incr * elemsz;

    #if UPCRI_PACKED_SPTR
      upcri_check_addr_overflow(addr);
      *psptr = (((uint64_t)addr) << UPCRI_ADDR_SHIFT) 
               | (((uint64_t)threadid) << UPCRI_THREAD_SHIFT);
    #else
      psptr->s_thread = threadid;
      psptr->s_addr = addr;
    #endif

    (void) upcri_checkvalid_pshared(*psptr);
}
#endif

#if UPCRI_SYMMETRIC_PSHARED
GASNETT_INLINE(upcr_add_pshared1)
upcr_pshared_ptr_t
upcr_add_pshared1(upcr_pshared_ptr_t psptr, size_t elemsz, ptrdiff_t inc)
{
    char *result, *ptr_off;

    (void) upcri_checkvalid_pshared(psptr);
    upcri_assert(elemsz > 0);

    if (inc >= 0) {
	ptr_off = (psptr - upcri_segsym_base) + 
		  (char *)(inc*upcri_segsym_region_size);
	result  = upcri_segsym_base + UPCRI_SYMMETRIC_MOD(ptr_off)
		  + UPCRI_SYMMETRIC_DIV(ptr_off)*elemsz;
    }
    else {
	ptr_off = (char *)(upcri_segsym_end - elemsz - psptr - 
			   inc*upcri_segsym_region_size);
	result  = (char *)(upcri_segsym_end - elemsz - 
			   (UPCRI_SYMMETRIC_MOD(ptr_off) + 
			    UPCRI_SYMMETRIC_DIV(ptr_off)*elemsz));
    }

    (void) upcri_checkvalid_pshared(result);
    return result;
}

#else /* !UPCRI_SYMMETRIC_PSHARED */

#define upcr_add_pshared1(sptr, elemsz, inc) \
       _upcr_add_pshared1(sptr, elemsz, inc UPCRI_TV_PASS)

GASNETT_INLINE(_upcr_add_pshared1)
upcr_pshared_ptr_t
_upcr_add_pshared1(upcr_pshared_ptr_t sptr, size_t elemsz, ptrdiff_t inc UPCRI_TV_ARG)
{
    #if PLATFORM_COMPILER_GCC && PLATFORM_COMPILER_VERSION_EQ(3,2,3) && PLATFORM_ARCH_X86_64
      /* bug1486: workaround a gcc optimizer crash tickled by this code on XT-3 */
      long numthreads = upcri_threads;
    #else
      long numthreads = upcr_threads();
    #endif
    uintptr_t addr;
    ptrdiff_t block_incr;
    upcr_thread_t threadid;

    (void) upcri_checkvalid_pshared(sptr);
    upcri_assert(elemsz > 0);

    /* TODO: result of division/modulo of negative numbers are not
    * standardized in ANSI C: will need different logic for architectures
    * that do not round negative results up toward 0. 
    * PHH: C99 requires "truncation toward zero", right?
    */
    if (UPCRI_CONSTANT_P(inc) && (inc == 0)) {
      return sptr;
    } else
    if (UPCRI_CONSTANT_P(inc) && (inc == 1)) {
      threadid = upcr_threadof_pshared(sptr);
      block_incr = 0;
      if (++threadid == numthreads) { /* Wrap */
        threadid = 0;
        block_incr = 1;
      }
    } else
    if (UPCRI_CONSTANT_P(inc) && (inc == -1)) {
      threadid = upcr_threadof_pshared(sptr);
      block_incr = 0;
      if (threadid-- == 0) { /* Wrap */
        threadid = numthreads - 1;
        block_incr = -1;
      }
    } else
    #if __UPC_STATIC_THREADS__
      if (UPCRI_CONSTANT_P(inc) && (inc > 0) && !(inc % THREADS)) {
        threadid = upcr_threadof_pshared(sptr);
        block_incr = inc / THREADS; /* compile-time constant */
      } else
      if (UPCRI_CONSTANT_P(inc) && (inc < 0) && !(-inc % THREADS)) {
        threadid = upcr_threadof_pshared(sptr);
        block_incr = - ((-inc) / THREADS); /* compile-time constant */
      } else
    #endif
    {
      ptrdiff_t const modoff = (inc >= 0) ? 0 : 1 - numthreads;
      ptrdiff_t const tsum = upcr_threadof_pshared(sptr) + inc + modoff;
      block_incr = tsum / numthreads;
      threadid = (tsum % numthreads) - modoff;
    }

    #if UPCRI_DEBUG_SPTR_ARITH
    {
      const ptrdiff_t th_diff = (ptrdiff_t)threadid - (ptrdiff_t)upcr_threadof_pshared(sptr);
      if_pf (inc != (th_diff + numthreads * block_incr)) {
        upcri_err("cyclic shared pointer add FAILED for incr=%ld\n", (long)inc);
      }
    }
    #endif

    addr = upcr_addrfield_pshared(sptr) + block_incr * elemsz;

  #if UPCRI_PACKED_SPTR
    upcri_check_addr_overflow(addr);
    return upcri_checkvalid_pshared(((uint64_t)addr) << UPCRI_ADDR_SHIFT) | 
                                    (((uint64_t)threadid) << UPCRI_THREAD_SHIFT);
  #else
    { upcr_pshared_ptr_t result;
      result.s_thread = threadid;
      result.s_addr = addr;
      return upcri_checkvalid_pshared(result);
    }
  #endif
}
#endif

/* Return non-zero iff ptr1 and ptr2 are both null, 
   or if they currently reference the same memory location
 */
GASNETT_INLINE(upcr_isequal_shared_shared)
int 
upcr_isequal_shared_shared(upcr_shared_ptr_t ptr1, upcr_shared_ptr_t ptr2)
{
  (void) upcri_checkvalid_shared(ptr1);
  (void) upcri_checkvalid_shared(ptr2);
  #if UPCRI_PACKED_SPTR
    return (ptr1 & ~UPCRI_PHASE_MASK) == (ptr2 & ~UPCRI_PHASE_MASK);
  #else
    return ptr1.s_addr == ptr2.s_addr && ptr1.s_thread == ptr2.s_thread;
  #endif
}

GASNETT_INLINE(upcr_isequal_shared_pshared)
int 
upcr_isequal_shared_pshared(upcr_shared_ptr_t ptr1, upcr_pshared_ptr_t ptr2)
{
  (void) upcri_checkvalid_shared(ptr1);
  (void) upcri_checkvalid_pshared(ptr2);
    /* The way we've implemented phase, we don't care about it for the
     * comparison--if the virtual addr and thread are same, they're equal */
  #if UPCRI_SYMMETRIC_PSHARED 
    return (upcr_shared_to_pshared(ptr1) == ptr2);
  #elif UPCRI_PACKED_SPTR
    upcri_assert((ptr2 & UPCRI_PHASE_MASK) == 0);
    return (ptr1 & ~UPCRI_PHASE_MASK) == ptr2;
  #else
    return (ptr1.s_addr == ptr2.s_addr && ptr1.s_thread == ptr2.s_thread);
  #endif
}

GASNETT_INLINE(upcr_isequal_pshared_pshared)
int 
upcr_isequal_pshared_pshared(upcr_pshared_ptr_t ptr1, upcr_pshared_ptr_t ptr2)
{
  (void) upcri_checkvalid_pshared(ptr1);
  (void) upcri_checkvalid_pshared(ptr2);
  #if UPCRI_SYMMETRIC_PSHARED
    return ptr1 == ptr2;
  #elif UPCRI_PACKED_SPTR
    upcri_assert((ptr1 & UPCRI_PHASE_MASK) == 0);
    upcri_assert((ptr2 & UPCRI_PHASE_MASK) == 0);
    return ptr1 == ptr2;
  #else
    return ptr1.s_addr == ptr2.s_addr && ptr1.s_thread == ptr2.s_thread;
  #endif
}

#define upcr_isequal_shared_local(ptr1, ptr2) \
       _upcr_isequal_shared_local(ptr1, ptr2, UPCRI_PT_PASS)

GASNETT_INLINE(_upcr_isequal_shared_local)
int 
_upcr_isequal_shared_local(upcr_shared_ptr_t ptr1, void *ptr2 UPCRI_PT_ARG)
{
    (void) upcri_checkvalid_shared(ptr1);
    /* Should work for all representations */
    return (upcri_shared_to_remote(ptr1) == ptr2)
	&& (upcr_threadof_shared(ptr1) == upcr_mythread() || ptr2 == NULL);
}

#define upcr_isequal_pshared_local(ptr1, ptr2) \
       _upcr_isequal_pshared_local(ptr1, ptr2, UPCRI_PT_PASS)

GASNETT_INLINE(_upcr_isequal_pshared_local)
int 
_upcr_isequal_pshared_local(upcr_pshared_ptr_t ptr1, void *ptr2 UPCRI_PT_ARG)
{
    (void) upcri_checkvalid_pshared(ptr1);
    /* Should work for all representations */
    return (upcri_pshared_to_remote(ptr1) == ptr2)
	&& (upcr_threadof_pshared(ptr1) == upcr_mythread() || ptr2 == NULL);
}

#define UPCRI_FAST_INTDIV(result,a,b) do { \
 switch(b) {                               \
   case 1:   result = (a); break;          \
   case 2:   result = ((a)>>1); break;     \
   case 4:   result = ((a)>>2); break;     \
   case 8:   result = ((a)>>3); break;     \
   case 16:  result = ((a)>>4); break;     \
   case 32:  result = ((a)>>5); break;     \
   case 64:  result = ((a)>>6); break;     \
   default:  result = (a)/(b);             \
 } } while(0)

#define UPCRI_FAST_INTDIVRET(a,b) do { \
 switch(b) {                        \
   case 1:   return (a);            \
   case 2:   return ((a)>>1);       \
   case 4:   return ((a)>>2);       \
   case 8:   return ((a)>>3);       \
   case 16:  return ((a)>>4);       \
   case 32:  return ((a)>>5);       \
   case 64:  return ((a)>>6);       \
   default:  return (a)/(b);        \
 } } while(0)

/* Shared pointer / Shared pointer comparison and subtraction -
  Compare shared pointers sptr1 and sptr2 and calculate sptr1 - sptr2.
    Blockelems is the block size for both ptrs, expressed in num elements
      (UPC type compatibility semantics require both pointers have the 
       same block count)
    Elemsz is the target element size in bytes

  Pointers with a definite static blocksize > 1 should use the "shared" version, 
  shared pointers with indef blocksize use the "psharedI" version
  shared pointers with blocksize == 1 use the "pshared1" version
  
 There are three possible cases:
  Returns 0 if sptr1 and sptr2 currently reference the same memory cell 
    (i.e. upcr_isequal() would return true)
  Returns a positive or negative value N (the difference in elements) to 
    indicate that upcr_add_shared(sptr2, N, blockelems) would yield a shared
    pointer that is upcr_isequal() to sptr1 (if N > 0, we say that sptr1 is
    "greater than" sptr2, and if N < 0 we say that sptr1 is "less than" sptr2)
  Otherwise, fatal error if there is no value which can be added to sptr1 to 
    make it equal sptr2 (e.g. sptr1 and sptr2 are indef blocksize pointers 
    with different affinities)
*/

#define upcr_sub_shared(sptr, sptr2, elemsz, blockelems) \
       _upcr_sub_shared(sptr, sptr2, elemsz, blockelems UPCRI_TV_PASS)

GASNETT_INLINE(_upcr_sub_shared)
ptrdiff_t 
_upcr_sub_shared(upcr_shared_ptr_t sptr1, upcr_shared_ptr_t sptr2, 
		size_t elemsz, size_t blockelems UPCRI_TV_ARG)
{
    /* use signed types to avoid errors with negatives values */
    ptrdiff_t addr1 = upcr_addrfield_shared(sptr1);
    ptrdiff_t addr2 = upcr_addrfield_shared(sptr2);
    ssize_t numthreads = upcr_threads();
    ssize_t thread1 = upcr_threadof_shared(sptr1);
    ssize_t thread2 = upcr_threadof_shared(sptr2);
    ssize_t phase1 = upcr_phaseof_shared(sptr1);
    ssize_t phase2 = upcr_phaseof_shared(sptr2);
    ssize_t blkelems = blockelems;
    ptrdiff_t temp;

    (void) upcri_checkvalid_shared(sptr1);
    (void) upcri_checkvalid_shared(sptr2);
    upcri_assert(elemsz > 0);

    UPCRI_FAST_INTDIV(temp, (addr1 - addr2), (ssize_t)elemsz);

    return ((temp + (phase2-phase1))*numthreads) 
	 + (thread1-thread2)*blkelems + (phase1 - phase2);
}


GASNETT_INLINE(upcr_sub_psharedI)
ptrdiff_t 
upcr_sub_psharedI(upcr_pshared_ptr_t sptr1, upcr_pshared_ptr_t sptr2, 
		  size_t elemsz)
{
    /* use signed values to avoid errors with negatives values */
    ptrdiff_t addr1 = upcr_addrfield_pshared(sptr1);
    ptrdiff_t addr2 = upcr_addrfield_pshared(sptr2);
  #if UPCR_DEBUG
    size_t t1 = upcr_threadof_pshared(sptr1);
    size_t t2 = upcr_threadof_pshared(sptr2);

    if (t1 != t2)
	upcri_err("Illegal: subtraction of indefinite pointers with affinity to "
		  "different UPC threads (%u and %u)", (unsigned int)t1, (unsigned int)t2);
  #endif

  (void) upcri_checkvalid_pshared(sptr1);
  (void) upcri_checkvalid_pshared(sptr2);
  upcri_assert(elemsz > 0);

  UPCRI_FAST_INTDIVRET((addr1 - addr2), (ssize_t)elemsz);
}

#if UPCRI_SYMMETRIC_PSHARED
GASNETT_INLINE(upcr_sub_pshared1)
ptrdiff_t 
upcr_sub_pshared1(upcr_pshared_ptr_t sptr1, upcr_pshared_ptr_t sptr2, 
		  size_t elemsz)
{
    /* use signed values to avoid errors with negatives values */
    ssize_t thread1 = upcr_threadof_pshared(sptr1);
    ssize_t thread2 = upcr_threadof_pshared(sptr2);
    ptrdiff_t addr1 = (uintptr_t)sptr1 UPCRI_MINUS_REMOTE_OFFSET(thread1);
    ptrdiff_t addr2 = (uintptr_t)sptr2 UPCRI_MINUS_REMOTE_OFFSET(thread2);
    ssize_t numthreads = upcr_threads();
    ptrdiff_t temp;

    (void) upcri_checkvalid_pshared(sptr1);
    (void) upcri_checkvalid_pshared(sptr2);
    upcri_assert(elemsz > 0);

    UPCRI_FAST_INTDIV(temp,((addr1 - addr2) * numthreads), (ssize_t)elemsz);

    return temp + (thread1 - thread2);
}
#else /* !UPCRI_SYMMETRIC_PSHARED */
#define upcr_sub_pshared1(sptr, sptr2, elemsz) \
       _upcr_sub_pshared1(sptr, sptr2, elemsz UPCRI_TV_PASS)

GASNETT_INLINE(_upcr_sub_pshared1)
ptrdiff_t 
_upcr_sub_pshared1(upcr_pshared_ptr_t sptr1, upcr_pshared_ptr_t sptr2, 
		   size_t elemsz UPCRI_TV_ARG)
{
    /* use signed values to avoid errors with negatives values */
    ptrdiff_t addr1 = upcr_addrfield_pshared(sptr1);
    ptrdiff_t addr2 = upcr_addrfield_pshared(sptr2);
    ssize_t thread1 = upcr_threadof_pshared(sptr1);
    ssize_t thread2 = upcr_threadof_pshared(sptr2);
    ssize_t numthreads = upcr_threads();
    ptrdiff_t temp;

    (void) upcri_checkvalid_pshared(sptr1);
    (void) upcri_checkvalid_pshared(sptr2);
    upcri_assert(elemsz > 0);

    UPCRI_FAST_INTDIV(temp,((addr1 - addr2) * numthreads), (ssize_t)elemsz);

    return temp + (thread1 - thread2);
}
#endif


/* Affinity checks - return non-zero iff the given shared pointer currently
    has affinity to the calling thread (or indicated thread, respectively)
 */

#define upcr_hasMyAffinity_shared(sptr) \
       _upcr_hasMyAffinity_shared(sptr UPCRI_PT_PASS)

GASNETT_INLINE(_upcr_hasMyAffinity_shared)
int 
_upcr_hasMyAffinity_shared (upcr_shared_ptr_t sptr UPCRI_PT_ARG)
{
    (void) upcri_checkvalid_shared(sptr);
    return (upcr_threadof_shared(sptr) == upcr_mythread());
}

#define upcr_hasMyAffinity_pshared(sptr) \
       _upcr_hasMyAffinity_pshared(sptr UPCRI_PT_PASS)

GASNETT_INLINE(_upcr_hasMyAffinity_pshared)
int 
_upcr_hasMyAffinity_pshared(upcr_pshared_ptr_t sptr UPCRI_PT_ARG)
{
    (void) upcri_checkvalid_pshared(sptr);
    return (upcr_threadof_pshared(sptr) == upcr_mythread());
}

GASNETT_INLINE(upcr_hasAffinity_shared)
int 
upcr_hasAffinity_shared (upcr_shared_ptr_t sptr,  upcr_thread_t threadid)
{
    (void) upcri_checkvalid_shared(sptr);
    return (upcr_threadof_shared(sptr) == threadid);
}

GASNETT_INLINE(upcr_hasAffinity_pshared)
int 
upcr_hasAffinity_pshared(upcr_pshared_ptr_t sptr, upcr_thread_t threadid)
{
    (void) upcri_checkvalid_pshared(sptr);
    return (upcr_threadof_pshared(sptr) == threadid);
}

/* -------------------------------------------------------------------------- */

/* Note: this must be kept in sync with UPC_DUMP_MIN_LENGTH in upc.h */
#define UPCRI_DUMP_MIN_LENGTH 100

/* For printing shared ptrs (to stdout) within library/w2c.c/debugger */
extern void upcri_print_shared(upcr_shared_ptr_t sptr);
extern void upcri_print_pshared(upcr_pshared_ptr_t sptr);
extern int _bupc_dump_shared(upcr_shared_ptr_t ptr, char *buf, int maxlen);
#define upcri_dump_shared _bupc_dump_shared

/* misc user-level functions */
#define _bupc_ptradd(p, blockelems, elemsz, elemincr) (  \
  upcri_assert((elemsz) > 0),                            \
  ((blockelems) == 0 ?                                   \
   upcr_pshared_to_shared(                               \
     upcr_add_psharedI(                                  \
       upcr_shared_to_pshared(p), (elemsz), (elemincr))): \
   upcr_add_shared((p), (elemsz), (elemincr), (blockelems))))

upcr_shared_ptr_t _bupc_local_to_shared(void *ptr, int thread, int phase);
upcr_shared_ptr_t _bupc_inverse_cast(void *ptr);

#include "upcr_preinclude/upc_castable_bits.h"
upc_thread_info_t upcr_thread_info(size_t th);

GASNETT_END_EXTERNC
#endif /* UPCR_SPTR_H */
