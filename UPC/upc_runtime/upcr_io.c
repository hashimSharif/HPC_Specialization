/*    $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_io.c $ */
/*  Description: A silly, centralized implementation of UPC-IO over C99/POSIX IO  */
/*  Copyright 2004, Dan Bonachea <bonachea@cs.berkeley.edu> */

#include <upcr_internal.h>

/* Design notes:
   ------------
   This is a silly, centralized implementation of UPC-IO over C99/POSIX IO
   All actual file I/O is performed on thread 0, and all other threads communicate the
   data via the most efficient communication mechanism available (often using Berkeley VIS extensions).
   Includes extensive error checking for parameters and implements the full spec, 
   but little performance tuning has been done.
   The 4 list I/O operations are general enough to implement the rest of the data I/O
   operations, and that's the implementation strategy that has been taken.
   All asynchronous operations are fully blocking.
   All UPC-IO hints are accepted and silently ignored.
   Support sizeof(upc_off_t) <= sizeof(long), due C89's fseek() and ftell() prototypes.

   Future TODO's:
   * Implement asynchronous operations as non-blocking
   * Allow the master thread to be set per-file-handle
   * Reduce barriers required for I/O operations, especially for NOSYNC variants
   * Upgrade to use real parallel I/O interfaces, hints and aggressive buffering
   * Implement 64-bit file operations where sizeof(long) < 8 - currently only support
     upc_off_t no larger than long.  Supporting larger probably might means using 
     non-C99 extensions for 64-bit I/O, and on 32-bit systems also requires a different
     data movement strategy (since the data for the entire I/O operation may not fit in 
     the private memory of the single I/O node).
     Likely extensions for 64-bit I/O are fseeko() and ftello() from POSIX.1
*/

#define UPCRI_IO_PAD 8 /* conservative padding between struct fields */

typedef enum { 
  UPCRI_IO_NOENTRY=0, 
  UPCRI_IO_SINGLEENTRY=1,  /* loc refs single area for single_filevec */
  UPCRI_IO_METADATAONLY=2, /* loc refs a contiguous upcri_metadata_mbox_t, data_len gives size of data */
  UPCRI_IO_FULLDATA=3      /* loc refs a contiguous upcri_fulldata_mbox_t, metadata_len gives size of initial metadata */
  } upcri_mboxref_type_t;

typedef struct {
  upcri_mboxref_type_t type;
  upc_shared_memvec_t loc; /* describes the entire mailbox */
  upc_filevec_t single_filevec;
  size_t metadata_len;
  size_t data_len;
  char _endpost; 
  
  /* start of local fields */
  int errno_result_mboxref;
  upc_off_t size_result;
  bupc_handle_t memcpy_handle;
  bupc_handle_t *memcpy_handle2;
  size_t memcpy_handle2_cnt;
  bupc_handle_t *memcpy_handle3;
  size_t memcpy_handle3_cnt;
  void *buf1; 
  void *buf2; 
} upcri_mboxref_t;


typedef struct {
  size_t filevec_entries;
  size_t memvec_entries;
  /* pad to UPCRI_IO_PAD bytes */
  /* upc_filevec_t filevec[] */
  /* pad to UPCRI_IO_PAD bytes */
  /* upc_shared_memvec_t memvec[] */
} upcri_metadata_mbox_t; /* master does gather/scatter */

GASNETT_INLINE(upcri_metadata_mbox_extractvecs)
void upcri_metadata_mbox_extractvecs(upcri_metadata_mbox_t *lmbox, 
                                     size_t *filevec_entries, upc_filevec_t **filevec,
                                     size_t *memvec_entries,  upc_shared_memvec_t **memvec) {
  size_t const filevec_cnt = lmbox->filevec_entries;
  size_t const memvec_cnt = lmbox->memvec_entries;
  upc_filevec_t * const _filevec = (upc_filevec_t *)UPCRI_ALIGNUP(lmbox+1,UPCRI_IO_PAD);
  upc_shared_memvec_t * const _memvec = (upc_shared_memvec_t *)UPCRI_ALIGNUP(_filevec+filevec_cnt,UPCRI_IO_PAD);
  if (filevec_entries) *filevec_entries = filevec_cnt;
  if (memvec_entries) *memvec_entries = memvec_cnt;
  if (filevec) *filevec = _filevec;
  if (memvec) *memvec = _memvec;
}

/* return the number of separate (complete and partial) blocks represented by this memvec */
GASNETT_INLINE(upcri_memvec_blockcount)
size_t upcri_memvec_blockcount(size_t memvec_cnt, upc_shared_memvec_t const *memvec) {
  size_t i;
  size_t numblocks = 0;
  for (i=0; i < memvec_cnt; i++) {
    size_t const len = memvec[i].len;
    size_t const blocksize = memvec[i].blocksize;
    if (blocksize == 0) numblocks++; /* indef */
    else numblocks += (len / blocksize) + ((len % blocksize)?1:0); /* total + partials */
  }
  return numblocks;
}

#ifndef UPCRI_IO_USE_VIS
#define UPCRI_IO_USE_VIS 1
#endif

/* calculate the number of handles that upcri_memvecmove will require for this memvec */
size_t upcri_memvecmove_handlecount(size_t memvec_cnt, upc_shared_memvec_t const *memvec) {
  size_t i, retval = 0;
  for (i = 0; i < memvec_cnt; i++) {
    if (memvec[i].blocksize == 0 || memvec[i].blocksize >= memvec[i].len) {
      retval++;
    } else {
      size_t num_fullblocks = memvec[i].len / memvec[i].blocksize;
      #if UPCRI_IO_USE_VIS
        retval += MIN(upcr_threads(), num_fullblocks);
      #else
        retval += num_fullblocks;
      #endif
      if (memvec[i].blocksize * num_fullblocks < memvec[i].len) retval++; /* partial block */
    }
  }
  return retval;
}

/* move a the shared data referenced by a upc_shared_memvec_t array
   to/from a contiguous local buffer. 
   localsz must be large enough to hold all the data
   handlecount must be large enough to hold all the handles necessary,
   which can be estimated using upcri_memvecmove_handlecount
   returns the actual number of handles initiated
 */
size_t upcri_memvecmove(int isget, void *_localbuf, size_t localsz,
                        size_t memvec_cnt, upc_shared_memvec_t const *memvec,
                        bupc_handle_t *handles, size_t handlecount UPCRI_PT_ARG) {
  /* Need to gather/scatter all the remote data over a contiguous I/O buffer.
     current strategy is:
     for each memvec entry, execute one contiguous fetch per thread into strided local mem
     (downside: performs poorly with a high number of user-provided list entries)
     other possibilities:
       * vector get with one remote entry per thread per block per memvec entry, 
         and one long contiguous local block
        (bad, because leads to very long remote vectors for small blocksize) 
       * vector get with one remote entry per remote thread per memvec entry
         to fetch all blocks with affinity to that thread. Also requires one 
         local entry per thread per block per memvec entry to scatter the 
         data appropriately, or a complicated post-fetch block transpose step.
        (bad because requires instantiating a long local vector, or doing the
         complicated post-transpose)
   */
  uint8_t *localbuf = _localbuf;
  size_t memvec_idx, handlepos = 0, localpos = 0;
  upcri_assert(handlecount >= upcri_memvecmove_handlecount(memvec_cnt, memvec));
  for (memvec_idx = 0; memvec_idx < memvec_cnt; memvec_idx++) {
    upcr_shared_ptr_t addr = memvec[memvec_idx].baseaddr;
    size_t len = memvec[memvec_idx].len;
    size_t blocksize = memvec[memvec_idx].blocksize;
    if (blocksize == 0 || blocksize >= len) { /* indef blocking, use a simple bulk copy */
      upcri_assert(handlepos < handlecount);
      upcri_assert(localpos + len <= localsz);
      handles[handlepos++] = (isget ?
        _upcr_memget_nb(localbuf+localpos, addr, len UPCRI_PT_PASS) :
        _upcr_memput_nb(addr, localbuf+localpos, len UPCRI_PT_PASS) );
      localpos += len;
    } else {
      /* one or more full blocks, possibly followed by a trailing partial block 
         note that first block need not reside on zero, but it will be a full block
         because we reset phase on input to UPC-IO
         use one strided copy for each thread having full blocks
         use a final single bulk copy for the training partial block if any
          (cannot be included in the strided copy because the size is not a full block)
       */
      size_t fullblocks = len / blocksize;
      size_t fullthreads = MIN(fullblocks, upcr_threads());
      size_t partiallen = len - (fullblocks*blocksize);
      size_t threadid = upcr_threadof_shared(addr);
      size_t midarray_offset = 0;
      upcri_assert(localpos + len <= localsz);
      upcri_assert(upcr_phaseof_shared(addr) == 0);
      #if UPCRI_IO_USE_VIS
        { size_t thread_cnt;
          for (thread_cnt = 0; thread_cnt < fullthreads; thread_cnt++) {
            upcr_shared_ptr_t remoteaddr = upcr_add_shared(addr, 1, thread_cnt*blocksize, blocksize);
            size_t myfullblocks = (fullblocks + upcr_threads() - thread_cnt - 1) / upcr_threads();
            size_t myfullslicelen = blocksize*myfullblocks;
            upcri_assert(handlepos < handlecount);
            upcri_assert(localpos + myfullslicelen <= localsz);
            handles[handlepos++] = (isget ?
              bupc_memget_fstrided_async(localbuf+localpos+midarray_offset, blocksize, blocksize*upcr_threads(), myfullblocks,
                                        remoteaddr, myfullslicelen, myfullslicelen, 1) :
              bupc_memput_fstrided_async(remoteaddr, myfullslicelen, myfullslicelen, 1,
                                        localbuf+localpos+midarray_offset, blocksize, blocksize*upcr_threads(), myfullblocks) );
            threadid = (threadid + 1) % upcr_threads();
            midarray_offset += blocksize;
          }
          localpos += fullblocks*blocksize;
        }
      #else
        { size_t blockid;
          for (blockid = 0; blockid < fullblocks; blockid++) {
            upcr_shared_ptr_t remoteaddr = upcr_add_shared(addr, 1, blockid*blocksize, blocksize);
            upcri_assert(handlepos < handlecount);
            handles[handlepos++] = (isget ?
              _upcr_memget_nb(localbuf+localpos, remoteaddr, blocksize UPCRI_PT_PASS) :
              _upcr_memput_nb(remoteaddr, localbuf+localpos, blocksize UPCRI_PT_PASS) );
            localpos += blocksize;
          }
        }
      #endif
      if (partiallen) {
        upcr_shared_ptr_t remoteaddr = upcr_add_shared(addr, 1, fullblocks*blocksize, blocksize);
        upcri_assert(handlepos < handlecount);
        upcri_assert(localpos + partiallen <= localsz);
        handles[handlepos++] = (isget ?
          _upcr_memget_nb(localbuf+localpos, remoteaddr, partiallen UPCRI_PT_PASS) :
          _upcr_memput_nb(remoteaddr, localbuf+localpos, partiallen UPCRI_PT_PASS) );
        localpos += partiallen;
      }
    }
  }
  upcri_assert(handlepos <= handlecount);
  return handlepos;
}

typedef struct {
  size_t filevec_entries;
  /* pad to UPCRI_IO_PAD bytes */
  /* upc_filevec_t filevec[] */
  /* pad to UPCRI_IO_PAD bytes */
  /* char data [] */
} upcri_fulldata_mbox_t; /* slave does gather/scatter */

typedef FILE *bupc_filehandle_t;

#define UPCRI_IO_MAGIC (0xFFBE341E101EA2F7ULL)

typedef enum { 
  UPCRI_FILE_NONE=0, 
  UPCRI_FILE_READ=1, 
  UPCRI_FILE_WRITE=2 
} upcri_optype_t;

typedef struct _bupc_file_t {
  int64_t magic;
  int flags;
  const char *fopenflags;
  bupc_filehandle_t filehandle;
  upcri_optype_t last_op;
  upcr_pshared_ptr_t mbox;
  upcr_pshared_ptr_t mbox_ref;

  upc_off_t pos;
  char *fname;
  char *fname_external;

  int async_outstanding;
  int async_initiation;
  upc_flag_t async_sync_mode;
  upc_off_t size_result;

  int errno_result_perthread;
  int errno_result_central;
} bupc_file_t;

/* return given thread's representative for a user-provided (upc_file_t *) */
GASNETT_INLINE(upcri_io_fd_to_lfd)
bupc_file_t *upcri_io_fd_to_lfd(upcr_pshared_ptr_t fd, upcr_thread_t id) {
  (void) upcri_checkvalid_pshared(fd);
  upcri_assert(upcr_threadof_pshared(fd) == 0);
  return upcri_pshared_to_remote(upcr_add_pshared1(fd, sizeof(bupc_file_t), id));
}
#define upcri_io_fd_to_mylfd(fd) upcri_io_fd_to_lfd(fd, upcr_mythread())

GASNETT_INLINE(_upcri_io_barrier)
void _upcri_io_barrier(UPCRI_PT_ARG_ALONE) {
  UPCRI_SINGLE_BARRIER();
}
#define upcri_io_barrier() _upcri_io_barrier(UPCRI_PT_PASS_ALONE)

GASNETT_INLINE(_upcri_io_error)
void _upcri_io_error(int errnum, const char *desc, const char *file, int line) {
  #if UPCR_DEBUG
  { static int firsttime = 1;
    static int quietio;
    if (firsttime) {
      quietio = gasnett_getenv_yesno_withdefault("UPC_QUIET_UPCIO", 0);
      firsttime = 0;
    }
    if (!quietio) {
      upcri_warn("UPC-IO Error at %s:%i: %s", file, line, desc);
    }
  }
  #endif
  errno = errnum; /* must come last after possible output */
}
#define upcri_io_error(errnum, desc) _upcri_io_error(errnum, desc, __FILE__, __LINE__)

#define UPCRI_FD_IS_BAD(lfd)                       \
  ((lfd == NULL || lfd->magic != UPCRI_IO_MAGIC) ? \
    upcri_io_error(EBADF, "bad file handle"), 1 :  \
    0) 

#define UPCRI_CHECK_FD(lfd) \
    if (UPCRI_FD_IS_BAD(lfd)) return -1

#define UPCRI_CHECK_ASYNC(lfd) do {                                                              \
    if (lfd->async_outstanding) {                                                                \
      upcri_io_error(EINPROGRESS,                                                                \
        "operation not permitted while an asynchronous operation is in-flight for this handle"); \
      return -1;                                                                                 \
    }                                                                                            \
  } while (0)

#define UPCRI_CHECK_READ(lfd) do {                                     \
    if (lfd->flags & UPC_WRONLY) {                                     \
      upcri_io_error(EPERM, "attempt to read on a write-only handle"); \
      return -1;                                                       \
    }                                                                  \
  } while (0)

#define UPCRI_CHECK_WRITE(lfd) do {                                    \
    if (lfd->flags & UPC_RDONLY) {                                     \
      upcri_io_error(EPERM, "attempt to write on a read-only handle"); \
      return -1;                                                       \
    }                                                                  \
  } while (0)

#define UPCRI_CHECK_INDIV(lfd) do {                                                         \
    if (lfd->flags & UPC_COMMON_FP) {                                                       \
      upcri_io_error(EINVAL, "operation not permitted on handle with common file pointer"); \
      return -1;                                                                            \
    }                                                                                       \
  } while (0)

#define UPCRI_CHECK_ARG(argcond) do {             \
    if (!(argcond)) {                             \
      upcri_io_error(EINVAL, "invalid argument"); \
      return -1;                                  \
    }                                             \
  } while (0)

#define UPCRI_CHECK_NONNULL(arg) UPCRI_CHECK_ARG((arg) != NULL)

#define UPCRI_IMPLICIT_FSYNC(fd) do { \
    int ret = bupc_all_fsync(fd);     \
    if (ret) return ret;              \
  } while (0)

#define UPCRI_INSYNC_BARRIER(lfd, flag) \
  if ( !((flag) & UPC_IN_NOSYNC) || (lfd->flags & UPC_STRONG_CA) ) upcri_io_barrier()

#define UPCRI_OUTSYNC_BARRIER(lfd, flag) \
  if ( !((flag) & UPC_OUT_NOSYNC) || (lfd->flags & UPC_STRONG_CA) ) upcri_io_barrier()

#define UPCRI_INSYNC  (UPC_IN_NOSYNC  | UPC_IN_MYSYNC  | UPC_IN_ALLSYNC)
#define UPCRI_OUTSYNC (UPC_OUT_NOSYNC | UPC_OUT_MYSYNC | UPC_OUT_ALLSYNC)

#define UPCRI_CHECK_FLAGS(syncflags) \
  UPCRI_CHECK_ARG(UPCRI_IS_POWER_OF_TWO((syncflags)&UPCRI_INSYNC) && \
                  UPCRI_IS_POWER_OF_TWO((syncflags)&UPCRI_OUTSYNC))

/* if sync_mode indicates an async operation, update metadata to start an async initiation, 
   set OUT_NOSYNC (out barrier postponed to async completion)
 */
#define UPCRI_BEGIN_ASYNC(lfd, sync_mode) do {                   \
    upcri_assert(!lfd->async_outstanding);                       \
    if (lfd->async_initiation > 0) { /* nested begin */          \
      lfd->async_initiation++;                                   \
      upcri_assert((sync_mode & UPC_OUT_NOSYNC));                \
    } else if ((sync_mode & UPC_ASYNC)) {  /* outermost begin */ \
      lfd->async_initiation = 1;                                 \
      lfd->async_sync_mode = sync_mode;                          \
      sync_mode = (sync_mode & ~UPCRI_OUTSYNC) | UPC_OUT_NOSYNC; \
    }                                                            \
  } while (0)

/* if we're starting an async initiation and this UPCRI_END_ASYNC matches 
   the outermost nested UPCRI_BEGIN_ASYNC, then save the result and clear the return value
*/
#define UPCRI_END_ASYNC(lfd, result) do {                                 \
    upcri_assert(!lfd->async_outstanding);                                \
    if (lfd->async_initiation > 1) { /* nested end */                     \
      lfd->async_initiation--;                                            \
    } else if (lfd->async_initiation == 1) { /* outermost end */          \
      lfd->async_initiation = 0;                                          \
      lfd->async_outstanding = 1;                                         \
      lfd->size_result = result;                                          \
      if (result < 0) { lfd->errno_result_perthread = errno; errno = 0; } \
      else lfd->errno_result_perthread = 0;                               \
      result = 0;                                                         \
    }                                                                     \
  } while (0)

/* ------------------------------------------------------------------------------------ */
int _upcr_all_fopen_checks(const char *fname, int flags, size_t numhints, upc_hint_t const *hints) {
  int i;
  UPCRI_CHECK_NONNULL(fname);
  if (numhints > 0) UPCRI_CHECK_NONNULL(hints);
  for (i = 0; i < numhints; i++) { /* currently ignore all hints - just ensure they look valid */
     UPCRI_CHECK_NONNULL(hints[i].key);
     UPCRI_CHECK_NONNULL(hints[i].value);
  }

  if (!!(flags & UPC_RDONLY) + !!(flags & UPC_WRONLY) + !!(flags & UPC_RDWR) != 1) {
    upcri_io_error(EIO, "upc_all_fopen() flags must specify exactly one of: UPC_RDONLY, UPC_WRONLY, UPC_RDWR");
    return -1;
  }
  if (!!(flags & UPC_INDIVIDUAL_FP) + !!(flags & UPC_COMMON_FP) != 1) {
    upcri_io_error(EIO, "upc_all_fopen() flags must specify exactly one of: UPC_INDIVIDUAL_FP, UPC_COMMON_FP");
    return -1;
  }
  if ((flags & UPC_EXCL) && !(flags & UPC_CREATE)) {
    upcri_io_error(EIO, "UPC_EXCL may only be used with UPC_CREATE");
    return -1;
  }
  if ((flags & UPC_RDONLY) && (flags & UPC_TRUNC)) {
    upcri_io_error(EIO, "UPC_TRUNC may not be used with UPC_RDONLY");
    return -1;
  }
  return 0;
}
upcr_pshared_ptr_t _BUPC_IOFN(open)(const char *fname, int flags, size_t numhints, upc_hint_t const *hints UPCRI_PT_ARG) {
  upcr_shared_ptr_t _fd = upcr_all_alloc(upcr_threads(), sizeof(bupc_file_t));
  upcr_pshared_ptr_t fd = upcr_shared_to_pshared(_fd);
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  int checks;

  /* clear memory */
  memset(lfd, 0, sizeof(bupc_file_t));
  upcri_io_barrier();
  /* ensure single-valued errors for fopen */
  checks = _upcr_all_fopen_checks(fname, flags, numhints, hints);
  if (checks != 0) upcr_put_pshared_val_strict(fd, offsetof(bupc_file_t, errno_result_central), (int)errno, sizeof(lfd->errno_result_central));
  else {
    if (upcr_mythread() == 0) {
      /* Use POSIX IO to help with open flags */
      int oflag = 0;
      int umode =  /* TODO: what is the right creation umode for read-only/write-only? */
          S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
      if (flags & UPC_RDONLY) { 
        oflag = oflag | O_RDONLY; 
        lfd->fopenflags = "rb";  
      }
      if (flags & UPC_WRONLY) { 
        oflag = oflag | O_WRONLY; 
        lfd->fopenflags = "rb+"; 
      }
      if (flags & UPC_RDWR)   { 
        oflag = oflag | O_RDWR;   
        lfd->fopenflags = "rb+"; 
      }
      if (flags & UPC_CREATE) oflag = oflag | O_CREAT;
      if (flags & UPC_EXCL)   oflag = oflag | O_EXCL;
      if (flags & UPC_TRUNC)  oflag = oflag | O_TRUNC;
      checks = open(fname, oflag, umode);
      if (checks == -1) lfd->errno_result_central = errno;
      else {
        checks = close(checks);
        if (checks == -1) lfd->errno_result_central = errno;
        else {
          lfd->filehandle = fopen(fname, lfd->fopenflags);
          if (lfd->filehandle == NULL) lfd->errno_result_central = errno;
        }
      }
    }
  }
  upcri_io_barrier();
  checks = (int)upcr_get_pshared_val_strict(fd, offsetof(bupc_file_t, errno_result_central), sizeof(lfd->errno_result_central));
  if (checks != 0) { 
    upcri_io_barrier();
    if (upcr_mythread() == 0) {
      if (lfd->filehandle != NULL) fclose(lfd->filehandle);
      upcr_free(_fd);
    }
    upcri_io_error(checks, strerror(checks));
    upcr_setnull_pshared(&fd);
    return fd; /* error - return null */
  }

  { /* allocate mailbox */
    upcr_shared_ptr_t mbox = upcr_all_alloc(1, upcr_threads() * sizeof(upcri_mboxref_t));
    lfd->mbox_ref = upcr_shared_to_pshared(mbox);
    if (upcr_mythread() == 0) upcr_memset(mbox, 0, upcr_threads() * sizeof(upcri_mboxref_t));
  }

  lfd->magic = UPCRI_IO_MAGIC;
  lfd->flags = flags;
  lfd->fname = upcri_checkmalloc(strlen(fname)+1);
  lfd->fname_external = upcri_checkmalloc(strlen(fname)+1);
  strcpy(lfd->fname, fname);
  strcpy(lfd->fname_external, fname);

  if (flags & UPC_APPEND) {
    checks = bupc_all_fseek(fd, 0, UPC_SEEK_END);
    if (checks != 0) upcr_put_pshared_val_strict(fd, offsetof(bupc_file_t, errno_result_central), (int)errno, sizeof(lfd->errno_result_central));
    upcri_io_barrier();
    checks = (int)upcr_get_pshared_val_strict(fd, offsetof(bupc_file_t, errno_result_central), sizeof(lfd->errno_result_central));
    if (checks != 0) {
      upcri_io_barrier();
      if (upcr_mythread() == 0) lfd->errno_result_central = 0;
      upcri_io_barrier();
      bupc_all_fclose(fd);
      upcri_io_error(checks, strerror(checks));
      upcr_setnull_pshared(&fd);
      return fd; /* error - return null */
    }
  }
  return fd;
}
/* ------------------------------------------------------------------------------------ */
int         _BUPC_IOFN(close)(upcr_pshared_ptr_t fd UPCRI_PT_ARG) {
  int checks;
  bupc_file_t *lfd;
  int retval;
  /* fd checks performed by fsync */
  checks = bupc_all_fsync(fd);
  /* ensure single-valued errors */
  if (checks != 0) upcr_put_pshared_val_strict(fd, offsetof(bupc_file_t, errno_result_central), (int)errno, sizeof(lfd->errno_result_central));
  upcri_io_barrier();
  lfd = upcri_io_fd_to_mylfd(fd);
  checks = (int)upcr_get_pshared_val_strict(fd, offsetof(bupc_file_t, errno_result_central), sizeof(lfd->errno_result_central));
  if (checks != 0) { 
    upcri_io_barrier();
    if (upcr_mythread() == 0 && !UPCRI_FD_IS_BAD(lfd)) lfd->errno_result_central = 0;
    upcri_io_barrier();
    upcri_io_error(checks, strerror(checks));
    return -1;
  }
  if (upcr_mythread() == 0) {
    retval = fclose(lfd->filehandle); /* fclose closes the stream, even when reporting error */
    if (retval) retval = errno;
    else {
      if (lfd->flags & UPC_DELETE_ON_CLOSE) {
        retval = remove(lfd->fname); 
        if (retval) retval = errno;
      }
    }
  } 
  upcri_broadcast(0, &retval, sizeof(retval));
  if (retval) upcri_io_error(retval, strerror(retval));
  upcri_free(lfd->fname);
  upcri_free(lfd->fname_external);
  lfd->magic = 0;
  upcri_io_barrier();
  if (upcr_mythread() == 0) {
    upcr_free(upcr_pshared_to_shared(lfd->mbox_ref));
    upcr_free(upcr_pshared_to_shared(fd));
  }
  return (retval?-1:0);
}
/* ------------------------------------------------------------------------------------ */
int         _BUPC_IOFN(sync)(upcr_pshared_ptr_t fd UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  int retval = 0;
  int myerrno = 0;
  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  if (lfd->flags & UPC_RDONLY) { 
    upcri_io_barrier();
    /* bug 887: fflush() on a read-only stream has undefined effects */
    return 0;
  }
  if (upcr_mythread() == 0) {
    retval = fflush(lfd->filehandle);
    if (retval) myerrno = errno;
  }
  upcri_io_barrier();
  if (retval) errno = myerrno;
  return retval;
}
/* ------------------------------------------------------------------------------------ */
upc_off_t   _BUPC_IOFN(seek)(upcr_pshared_ptr_t fd, upc_off_t offset, int origin UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  upc_off_t newoffset;
  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  switch (origin) {
    case UPC_SEEK_SET: newoffset = offset; break;
    case UPC_SEEK_CUR: newoffset = lfd->pos + offset; break;
    case UPC_SEEK_END: {
      upc_off_t filelen = bupc_all_fget_size(fd);
      if (filelen < 0) return filelen;
      newoffset = filelen + offset; 
      break;
    }
    default: UPCRI_CHECK_ARG(0);
  }
  if (newoffset < 0) {
    upcri_io_error(EIO, "upc_all_fseek() cannot seek before beginning of file");
    return -1;
  }
  lfd->pos = newoffset;
  return newoffset;
}
/* ------------------------------------------------------------------------------------ */
int         _BUPC_IOFN(set_size)(upcr_pshared_ptr_t fd, upc_off_t size UPCRI_PT_ARG) {
  upc_off_t cursize;
  int retval = 0;
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  UPCRI_CHECK_WRITE(lfd);
  UPCRI_IMPLICIT_FSYNC(fd);
  cursize = bupc_all_fget_size(fd);
  if (size != cursize) { 
    /* size change required - truncation cannot be done using C99-I/O, need to use POSIX IO 
       POSIX IO is probably also equally or more efficient for growing the file, so always use that
     */
    if (upcr_mythread() == 0) {
      retval = fclose(lfd->filehandle);
      if (!retval) retval = truncate(lfd->fname, size);
      if (!retval) lfd->filehandle = fopen(lfd->fname, lfd->fopenflags);
      if (retval || lfd->filehandle == NULL) {
        upcri_io_error(errno, strerror(errno));
        return -1;
      }
    }
  }
  return 0;
}
/* ------------------------------------------------------------------------------------ */
upc_off_t   _BUPC_IOFN(get_size)(upcr_pshared_ptr_t fd UPCRI_PT_ARG) {
  struct upcri_getsz {
    upc_off_t retval;
    int errno_result;
  } tmp;
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  if (upcr_mythread() == 0) {
    int err = fseek(lfd->filehandle, 0, SEEK_END);
    if (err) tmp.retval = -1;
    else tmp.retval = ftell(lfd->filehandle);
    if (tmp.retval < 0) tmp.errno_result = errno;
  }
  upcri_broadcast(0, &tmp, sizeof(tmp));
  if (tmp.retval < 0) upcri_io_error(tmp.errno_result, strerror(tmp.errno_result));
  return tmp.retval;
}
/* ------------------------------------------------------------------------------------ */
int         _BUPC_IOFN(preallocate)(upcr_pshared_ptr_t fd, upc_off_t size UPCRI_PT_ARG) {
  upc_off_t cursize;
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  UPCRI_CHECK_WRITE(lfd);
  cursize = bupc_all_fget_size(fd);
  if (cursize < 0) return cursize;
  if (size > cursize) { /* need to grow */
    return bupc_all_fset_size(fd, size);
  } else return 0; /* nothing to do */
}
/* ------------------------------------------------------------------------------------ */
int         _BUPC_IOFN(cntl)(upcr_pshared_ptr_t fd, int cmd, void *arg UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  UPCRI_CHECK_FD(lfd);
  if (cmd != UPC_ASYNC_OUTSTANDING) UPCRI_CHECK_ASYNC(lfd);

  switch (cmd) {
    case UPC_GET_CA_SEMANTICS: {
      return (lfd->flags & UPC_STRONG_CA);
    }
    case UPC_SET_WEAK_CA_SEMANTICS: {
      UPCRI_IMPLICIT_FSYNC(fd);
      lfd->flags = lfd->flags & ~UPC_STRONG_CA;
      return 0;
    }
    case UPC_SET_STRONG_CA_SEMANTICS: {
      UPCRI_IMPLICIT_FSYNC(fd);
      lfd->flags = lfd->flags | UPC_STRONG_CA;
      return 0;
    }
    case UPC_GET_FP: {
      return lfd->flags & (UPC_INDIVIDUAL_FP | UPC_COMMON_FP);
    }
    case UPC_SET_COMMON_FP: {
      UPCRI_IMPLICIT_FSYNC(fd);
      if (bupc_all_fseek(fd, 0, UPC_SEEK_SET) == -1) return -1;
      lfd->flags = lfd->flags & ~UPC_INDIVIDUAL_FP;
      lfd->flags = lfd->flags | UPC_COMMON_FP;
      return 0;
    }
    case UPC_SET_INDIVIDUAL_FP: {
      UPCRI_IMPLICIT_FSYNC(fd);
      if (bupc_all_fseek(fd, 0, UPC_SEEK_SET) == -1) return -1;
      lfd->flags = lfd->flags & ~UPC_COMMON_FP;
      lfd->flags = lfd->flags | UPC_INDIVIDUAL_FP;
      return 0;
    }
    case UPC_GET_FL: {
      return lfd->flags;
    }
    case UPC_GET_FN: {
      const char **myarg = (const char **)arg;
      UPCRI_CHECK_NONNULL(myarg);
      *myarg = lfd->fname_external;
      return 0;
    }
    case UPC_GET_HINTS: { /* no hints currently supported - all ignored */
      const upc_hint_t **myarg = (const upc_hint_t **)arg;
      UPCRI_CHECK_NONNULL(myarg);
      *myarg = NULL;
      return 0;
    }
    case UPC_SET_HINT: { /* no hints currently supported - all ignored */
      upc_hint_t *myarg = (upc_hint_t *)arg;
      UPCRI_CHECK_NONNULL(myarg);
      return 0;
    }
    case UPC_ASYNC_OUTSTANDING: {
      return lfd->async_outstanding;
    }
    default:
      upcri_io_error(EINVAL, "invalid argument");
      return -1;
  }
  upcri_err("unreachable in _upcr_all_fcntl");
  return 0;
}
/* ------------------------------------------------------------------------------------ */
upc_off_t _BUPC_IOFN(read_local) (upcr_pshared_ptr_t fd, void *buffer, size_t size, size_t nmemb, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  upc_local_memvec_t lmv;
  upc_filevec_t fv;
  upc_off_t result;

  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  UPCRI_CHECK_READ(lfd);
  UPCRI_CHECK_INDIV(lfd);
  UPCRI_CHECK_ARG(buffer != NULL || size == 0 || nmemb == 0);
  UPCRI_CHECK_FLAGS(sync_mode);
  UPCRI_BEGIN_ASYNC(lfd, sync_mode);
  lmv.baseaddr = buffer;
  lmv.len = size * nmemb;
  fv.offset = lfd->pos;
  fv.len = lmv.len;

  result = bupc_all_fread_list_local(fd, 1, &lmv, 1, &fv, sync_mode);
  if (result != -1) lfd->pos += result;
  UPCRI_END_ASYNC(lfd, result);
  return result;
}
/* ------------------------------------------------------------------------------------ */
upc_off_t _BUPC_IOFN(read_shared) (upcr_pshared_ptr_t fd, upcr_shared_ptr_t buffer, size_t blocksize, size_t size, size_t nmemb, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  upc_shared_memvec_t smv;
  upc_filevec_t fv;
  upc_off_t result;

  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  UPCRI_CHECK_READ(lfd);
  UPCRI_CHECK_ARG(!upcr_isnull_shared(buffer) || size == 0 || nmemb == 0);
  UPCRI_CHECK_FLAGS(sync_mode);
  UPCRI_BEGIN_ASYNC(lfd, sync_mode);
  smv.baseaddr = buffer;
  smv.blocksize = size * blocksize;
  smv.len = size * nmemb;
  fv.offset = lfd->pos;
  fv.len = smv.len;

  if (lfd->flags & UPC_COMMON_FP) {
    int myerrno;
    if (upcr_mythread() == 0) result = bupc_all_fread_list_shared(fd, 1, &smv, 1, &fv, sync_mode);
    else                      result = bupc_all_fread_list_shared(fd, 0, NULL, 0, NULL, sync_mode);
    if (result == -1) myerrno = errno; /* save errno before broadcast */
    upcri_broadcast(0, &result, sizeof(result));
    if (result == -1) {
      upcri_broadcast(0, &myerrno, sizeof(myerrno));
      errno = myerrno;
    }
  } else { /* individual fp */
    result = bupc_all_fread_list_shared(fd, 1, &smv, 1, &fv, sync_mode);
  }

  if (result != -1) lfd->pos += result;
  UPCRI_END_ASYNC(lfd, result);
  return result;
}
/* ------------------------------------------------------------------------------------ */
upc_off_t _BUPC_IOFN(write_local) (upcr_pshared_ptr_t fd, void *buffer, size_t size, size_t nmemb, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  upc_local_memvec_t lmv;
  upc_filevec_t fv;
  upc_off_t result;

  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  UPCRI_CHECK_WRITE(lfd);
  UPCRI_CHECK_INDIV(lfd);
  UPCRI_CHECK_ARG(buffer != NULL || size == 0 || nmemb == 0);
  UPCRI_CHECK_FLAGS(sync_mode);
  UPCRI_BEGIN_ASYNC(lfd, sync_mode);
  lmv.baseaddr = buffer;
  lmv.len = size * nmemb;
  fv.offset = lfd->pos;
  fv.len = lmv.len;

  result = bupc_all_fwrite_list_local(fd, 1, &lmv, 1, &fv, sync_mode);
  if (result != -1) lfd->pos += result;
  UPCRI_END_ASYNC(lfd, result);
  return result;
}
/* ------------------------------------------------------------------------------------ */
upc_off_t _BUPC_IOFN(write_shared)(upcr_pshared_ptr_t fd, upcr_shared_ptr_t buffer, size_t blocksize, size_t size, size_t nmemb, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  upc_shared_memvec_t smv;
  upc_filevec_t fv;
  upc_off_t result;

  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  UPCRI_CHECK_WRITE(lfd);
  UPCRI_CHECK_ARG(!upcr_isnull_shared(buffer) || size == 0 || nmemb == 0);
  UPCRI_CHECK_FLAGS(sync_mode);
  UPCRI_BEGIN_ASYNC(lfd, sync_mode);
  smv.baseaddr = buffer;
  smv.blocksize = size * blocksize;
  smv.len = size * nmemb;
  fv.offset = lfd->pos;
  fv.len = smv.len;

  if (lfd->flags & UPC_COMMON_FP) {
    int myerrno;
    if (upcr_mythread() == 0) result = bupc_all_fwrite_list_shared(fd, 1, &smv, 1, &fv, sync_mode);
    else                      result = bupc_all_fwrite_list_shared(fd, 0, NULL, 0, NULL, sync_mode);
    if (result == -1) myerrno = errno; /* save errno before broadcast */
    upcri_broadcast(0, &result, sizeof(result));
    if (result == -1) {
      upcri_broadcast(0, &myerrno, sizeof(myerrno));
      errno = myerrno;
    }
  } else { /* individual fp */
    result = bupc_all_fwrite_list_shared(fd, 1, &smv, 1, &fv, sync_mode);
  }

  if (result != -1) lfd->pos += result;
  UPCRI_END_ASYNC(lfd, result);
  return result;
}

/* ------------------------------------------------------------------------------------ */
/* Algorithm for list file operations:
   Start by normalizing entries:
   * Read (file -> shared)
      if (no entries) do nothing
      else if (single entry in each vec) {
        write SINGLEENTRY
        finish => no-op
      } else {
        local_alloc metadata only mbox
        write METADATAONLY
        finish => free mbox
      }
   * Read (file -> local)
      if (no entries) do nothing
      else {
        local_alloc fulldata mbox with header space for memvec + UPCRI_IO_PAD-byte pad
        prepend memvec header with true memvec info
        if (single entry in file vec) {
          write SINGLEENTRY pointing to data space
        } else {
          write FULLDATA (master pulls metadata header only, writes back data)
        }
        finish => copy back data (scatter to memvec), free mbox
      }
   * Write (shared -> file)
      if (no entries) do nothing
      else if (single entry in each vec) {
        write SINGLEENTRY
        finish => no-op
      } else {
        local_alloc metadata only mbox
        write METADATAONLY
        finish => free mbox
      }
   * Write (local -> file)
      if (no entries) do nothing
      else {
        local_alloc fulldata mbox
        copy/gather data into bounce buffer
        if (single entry in file vec) {
          write SINGLEENTRY pointing to data space
          finish => free mbox
        } else {
          write FULLDATA 
          finish => free mbox
        }
      }
 */
static void upcri_signal_mbox(upcr_pshared_ptr_t fd, int islocal, int isread,
                              size_t memvec_entries, void const *_memvec, 
                              size_t filevec_entries, upc_filevec_t const *filevec UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  size_t i,j;
  upcr_pshared_ptr_t mbox;
  upcri_mboxref_t mboxref;
  ssize_t filevec_cnt=0, filevec_first=-1, memvec_cnt=0, memvec_first=-1;
  upc_off_t file_minoffset = UPCRI_MAX_OFF_T;
  upc_off_t file_maxoffset = -1;
  upc_off_t file_maxlocation = -1;
  upc_off_t filesz=0, memsz=0;

  /* init I/O state */
  upcr_setnull_pshared(&mbox);
  upcr_setnull_pshared(&lfd->mbox);
  lfd->errno_result_perthread = 0;
  lfd->size_result = 0;

  /* scan vec entries, check legality */
  for (i = 0; i < filevec_entries; i++) {
    if_pt (filevec[i].len > 0) {
      if_pf (filevec[i].offset < 0) {
        upcri_io_error(EINVAL,"filevec offset must be >= 0");
        lfd->errno_result_perthread = EINVAL;
        return;
      }
      if (filevec_first == -1) filevec_first = i;
      filevec_cnt++;
      filesz += filevec[i].len;
      if ((isread && filevec[i].offset <= file_maxoffset) ||
         (!isread && filevec[i].offset <= file_maxlocation)) {
        if (isread)
          upcri_io_error(EINVAL,"filevec must specify regions in monotonically non-decreasing order");
        else
          upcri_io_error(EINVAL,"filevec must specify non-overlapping regions in monotonically non-decreasing order");
        lfd->errno_result_perthread = EINVAL;
        return;
      }
      file_minoffset = MIN(file_minoffset, filevec[i].offset);
      file_maxoffset = MAX(file_maxoffset, filevec[i].offset);
      file_maxlocation = MAX(file_maxlocation, filevec[i].offset + filevec[i].len - 1);
    }
  }
  for (i = 0; i < memvec_entries; i++) {
    upc_off_t thislen = (islocal? ((upc_local_memvec_t*) _memvec)[i].len:
                                  ((upc_shared_memvec_t*)_memvec)[i].len);
    if_pt (thislen > 0) { 
      if (memvec_first == -1) memvec_first = i;
      memvec_cnt++;
      memsz += thislen;
      if ((islocal && ((upc_local_memvec_t*) _memvec)[i].baseaddr == NULL) ||
          (!islocal && upcr_isnull_shared(((upc_shared_memvec_t*) _memvec)[i].baseaddr))) {
        upcri_io_error(EINVAL,"invalid memvec baseaddr");
        lfd->errno_result_perthread = EINVAL;
        return;
      }
    #if UPCR_DEBUG
      if (isread) { /* check for non-overlapping memvec - expensive, so only do it for debugging */
        if (islocal) {
          /* this is a naive N^2 algorithm - if it ever becomes a performance problem,
           * it can be replaced with an O(N log N) sort of the baseaddrs followed by an 
           * O(N) scan for overlapping intervals
           */
          upc_local_memvec_t* memvec = (upc_local_memvec_t*) _memvec;
          char *thisbase = memvec[i].baseaddr;
          char *thisend = thisbase+thislen-1;
          for (j = 0; j < memvec_entries; j++) {
            upc_off_t otherlen = memvec[j].len;
            if (otherlen > 0 && i != j) {
              char *otherbase = memvec[j].baseaddr;
              char *otherend = otherbase+otherlen-1;
              if (!(thisend < otherbase || otherend < thisbase)) {
                upcri_io_error(EINVAL,"memvec must specify non-overlapping regions for a read");
                lfd->errno_result_perthread = EINVAL;
                return;
              }
            }
          }
        } else {
          upc_shared_memvec_t* memvec = (upc_shared_memvec_t*) _memvec;
          size_t thisblocksz = memvec[i].blocksize == 0 ? thislen : memvec[i].blocksize;
          upcr_shared_ptr_t thisbase = upcr_shared_resetphase(memvec[i].baseaddr);
          upcr_shared_ptr_t thisend = upcr_add_shared(thisbase, 1, thislen-1, thisblocksz);
          upcr_thread_t thisbase_th = upcr_threadof_shared(thisbase);
          upcr_thread_t thisend_th = upcr_threadof_shared(thisend);
          upcr_thread_t thisend_vth = thisbase_th <= thisend_th ? thisend_th : thisend_th + upcr_threads();
          size_t thisnumblocks = thislen / thisblocksz + (thislen % thisblocksz == 0 ? 0 : 1);
          int thisnonwrap = (thislen < upcr_threads()*thisblocksz);
          uint8_t **minval_th = NULL;
          uint8_t **maxval_th = NULL;
          for (j = 0; j < memvec_entries; j++) {
            upc_off_t otherlen = ((upc_shared_memvec_t*)_memvec)[j].len;
            size_t otherblocksz = memvec[j].blocksize == 0 ? otherlen : memvec[j].blocksize;
            if (otherlen > 0 && i != j) {
              upcr_shared_ptr_t otherbase = upcr_shared_resetphase(memvec[j].baseaddr);
              upcr_shared_ptr_t otherend = upcr_add_shared(otherbase, 1, otherlen-1, otherblocksz);
              upcr_thread_t otherbase_th = upcr_threadof_shared(otherbase);
              upcr_thread_t otherend_th = upcr_threadof_shared(otherend);
              upcr_thread_t otherend_vth = otherbase_th <= otherend_th ? otherend_th : otherend_th + upcr_threads();
              int othernonwrap = (otherlen < upcr_threads()*otherblocksz);
              /* computing fully general shared region overlap can be very complicated 
                 the fastest algorithm to solve this in general is probably to view the
                 shared regions as shapes in a 2-d plane with the axes of shared heap offsets
                 and thread affinity. Every shared region can be decomposed into at most
                 five 2-d rectangles in this space (four if you assume phase==0 for starting addr)
                 then one can apply standard algorithms for 2-d rectangular collision detection
                 to the set of generated fragments to find any overlap (eg project the rectangles
                 onto each axis in turn and run a 1-d sort-and-scan algorithm to detect possible conflicts)
                 The total asymptotic complexity for that approach is somewhere around O(k N log N)
                 where k is the maximum number of possible conflicts for a given fragment along the 
                 first projection axis which is chosen (a nontrivial choice).
                 Rather than implementing this very complicated approach, we opt for a simpler
                 approach which is more expensive in general, but optimizes for some hopefully
                 common special cases
               */
              /* first check for a few cases that trivially imply no overlap */

              /* no thread overlap for non-thread-wrapping regions */
              if (thisnonwrap && othernonwrap &&
                  (thisend_vth < otherbase_th || otherend_vth < thisbase_th)) continue;
              /* thisend < otherbase */
              if (upcr_sub_shared(otherbase, thisend, 1, thisblocksz) > 0) continue;
              /* otherend < thisbase */
              if (upcr_sub_shared(thisbase, otherend, 1, otherblocksz) > 0) continue;

              /* do the very expensive check that catches anything */
              if (!minval_th) { /* init thread regions for this */
                size_t thisblkstarts = MIN(thisnumblocks, upcr_threads());
                size_t partiallen = thislen;
                size_t i;
                minval_th = UPCRI_XCALLOC(uint8_t*,upcr_threads());
                maxval_th = UPCRI_XCALLOC(uint8_t*,upcr_threads());
                for (i = 0; i < thisblkstarts; i++) {
                  upcr_thread_t threadid = (thisbase_th+i)%upcr_threads();
                  upcr_shared_ptr_t blkstart = upcr_add_shared(thisbase, 1, i*thisblocksz, thisblocksz);
                  size_t locallen = upcr_affinitysize(partiallen, thisblocksz, 0);
                  minval_th[threadid] = upcri_shared_to_remote(blkstart);
                  maxval_th[threadid] = minval_th[threadid] + locallen - 1;
                  partiallen -= thisblocksz;
                }
              }
              { size_t othernumblocks = otherlen / otherblocksz + (otherlen % otherblocksz == 0 ? 0 : 1);
                size_t otherblkstarts = MIN(othernumblocks, upcr_threads());
                size_t i;
                for (i = 0; i < otherblkstarts; i++) {
                  upcr_thread_t threadid = (otherbase_th+i)%upcr_threads();
                  uint8_t *blkstart = upcri_shared_to_remote(
                                      upcr_add_shared(otherbase, 1, i*otherblocksz, otherblocksz));
                  if (blkstart >= minval_th[threadid] && blkstart <= maxval_th[threadid]) {
                    upcri_io_error(EINVAL,"memvec must specify non-overlapping regions for a read");
                    lfd->errno_result_perthread = EINVAL;
                    return;
                  }
                }
              }
            }
          }
          if (minval_th) upcri_free(minval_th);
          if (maxval_th) upcri_free(maxval_th);
        }
      }
    #endif
    }
  }
  if (filesz != memsz) {
    upcri_io_error(EINVAL,"filevec and memvec must specify areas of equal size");
    lfd->errno_result_perthread = EINVAL;
    return;
  }
  if (filesz == 0) return; /* thread has no entries - nothing to do */

  mboxref.metadata_len = 0;
  memset(&mboxref.single_filevec, 0, sizeof(upc_filevec_t));
  mboxref.data_len = memsz;
  /* assume result will be full-sized unless we hear otherwise */
  lfd->size_result = memsz;
  if (!islocal) { /* shared reads/writes */
    if (memvec_cnt == 1 && filevec_cnt == 1) {
      mboxref.type = UPCRI_IO_SINGLEENTRY;
      mboxref.loc = ((upc_shared_memvec_t*)_memvec)[memvec_first];
      upcr_shared_resetphase_ref(&(mboxref.loc.baseaddr));
      mboxref.single_filevec = filevec[filevec_first];
      /* mbox NULL - no-op completion */
    } else { /* general case */
      upcri_metadata_mbox_t *lmbox;
      size_t mbox_sz = UPCRI_IO_PAD + sizeof(upcri_metadata_mbox_t) + 
                       UPCRI_IO_PAD + filevec_cnt*sizeof(upc_filevec_t) + 
                       UPCRI_IO_PAD + memvec_cnt*sizeof(upc_shared_memvec_t);
      upcr_shared_ptr_t smbox = upcr_alloc(mbox_sz);
      upc_shared_memvec_t *memvec = (upc_shared_memvec_t*)_memvec;
      upc_filevec_t *mbox_filevec;
      upc_shared_memvec_t *mbox_memvec;
      mbox = upcr_shared_to_pshared(smbox);
      lmbox = (upcri_metadata_mbox_t *)UPCRI_ALIGNUP(upcr_pshared_to_local(mbox),UPCRI_IO_PAD);
      mbox_filevec = (upc_filevec_t *)UPCRI_ALIGNUP(lmbox + 1,UPCRI_IO_PAD);
      mbox_memvec =  (upc_shared_memvec_t *)UPCRI_ALIGNUP(mbox_filevec + filevec_cnt,UPCRI_IO_PAD);
      mboxref.type = UPCRI_IO_METADATAONLY;
      mboxref.loc.baseaddr = upcr_local_to_shared(lmbox);
      mboxref.loc.blocksize = 0;
      mboxref.metadata_len = (uint8_t*)(mbox_memvec+memvec_cnt) - (uint8_t*)lmbox;
      mboxref.loc.len = mboxref.metadata_len;
      /* copy vectors, remove empties, reset phase */
      for (i = memvec_first, j = 0; i < memvec_entries && j < memvec_cnt; i++) {
        if (memvec[i].len > 0) {
          mbox_memvec[j].baseaddr = upcr_shared_resetphase(memvec[i].baseaddr);
          mbox_memvec[j].blocksize = memvec[i].blocksize;
          mbox_memvec[j].len = memvec[i].len;
          j++;
        }
      }
      lmbox->memvec_entries = memvec_cnt;
      for (i = filevec_first, j = 0; i < filevec_entries && j < filevec_cnt; i++) {
        if (filevec[i].len > 0) {
          mbox_filevec[j] = filevec[i];
          j++;
        }
      }
      lmbox->filevec_entries = filevec_cnt;
    }
  } else { /* local reads/writes */
    size_t memvec_hdrsz = (isread?(memvec_cnt+1)*sizeof(upc_local_memvec_t):0);
    size_t bufsz = memvec_hdrsz + UPCRI_IO_PAD + 
      sizeof(upcri_fulldata_mbox_t)+UPCRI_IO_PAD+filevec_cnt*sizeof(upc_filevec_t)+UPCRI_IO_PAD+memsz;
    upcr_shared_ptr_t smbox = upcr_alloc(bufsz);
    upcri_fulldata_mbox_t *lmbox = (upcri_fulldata_mbox_t *)UPCRI_ALIGNUP(((uint8_t*)upcr_shared_to_local(smbox)) + memvec_hdrsz, UPCRI_IO_PAD);
    upc_local_memvec_t *memvec = (upc_local_memvec_t*)_memvec;
    upc_local_memvec_t *mbox_memvec = (upc_local_memvec_t*)upcr_shared_to_local(smbox);
    upc_filevec_t *mbox_filevec = (upc_filevec_t *)UPCRI_ALIGNUP(lmbox+1,UPCRI_IO_PAD);
    uint8_t *mbox_data = (uint8_t *)UPCRI_ALIGNUP(mbox_filevec+filevec_cnt,UPCRI_IO_PAD);
    uint8_t *mbox_data_end = mbox_data;
    mbox = upcr_shared_to_pshared(smbox);

    for (i = filevec_first, j = 0; i < filevec_entries && j < filevec_cnt; i++) {
      if (filevec[i].len > 0) {
        mbox_filevec[j] = filevec[i];
        j++;
      }
    }
    lmbox->filevec_entries = filevec_cnt;

    if (isread) { /* stash memvec_cnt in a dummy first entry */
      mbox_memvec[0].baseaddr = NULL;
      mbox_memvec[0].len = memvec_cnt;
    }
    for (i = memvec_first, j = 0; i < memvec_entries && j < memvec_cnt; i++) {
      if (memvec[i].len > 0) {
        if (isread) {
          /* copy memvec info we'll need later */
          mbox_memvec[j+1].baseaddr = memvec[i].baseaddr;
          mbox_memvec[j+1].len = memvec[i].len;
        } else {
          /* gather data into mbox */
          memcpy(mbox_data_end, memvec[i].baseaddr, memvec[i].len);
        }
        mbox_data_end += memvec[i].len;
        j++;
      }
    }

    if (filevec_cnt == 1) { /* single file region */
      mboxref.type = UPCRI_IO_SINGLEENTRY;
      mboxref.loc.baseaddr = upcr_local_to_shared(mbox_data);
      mboxref.loc.blocksize = 0;
      mboxref.loc.len = memsz;
      mboxref.single_filevec = filevec[filevec_first];
    } else { /* general case */
      mboxref.type = UPCRI_IO_FULLDATA;
      mboxref.loc.baseaddr = upcr_local_to_shared(lmbox);
      mboxref.loc.blocksize = 0;
      mboxref.loc.len = mbox_data_end - (uint8_t *)lmbox;
      mboxref.metadata_len = mbox_data - (uint8_t *)lmbox;
    }
  }
  /* relaxed put, because master doesn't inspect until after next barrier anyhow */ 
  upcr_put_pshared(lfd->mbox_ref, sizeof(upcri_mboxref_t)*upcr_mythread(), &mboxref, offsetof(upcri_mboxref_t, _endpost));
  lfd->mbox = mbox;
  return;
}

static void upcri_process_mbox(upcr_pshared_ptr_t fd, int islocal, int isread UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  upcri_optype_t this_op = (isread ? UPCRI_FILE_READ : UPCRI_FILE_WRITE);
  upcr_thread_t threadid;
  int metadataonly_cnt = 0, fulldata_cnt = 0;
  upcri_mboxref_t *lmbox_ref = upcr_pshared_to_local(lfd->mbox_ref);

  upcri_assert(upcr_mythread() == 0);
  /* pass 1 - alloc bufs, start memcpy */
  for (threadid = 0; threadid < upcr_threads(); threadid++) {
    lmbox_ref[threadid].memcpy_handle = BUPC_COMPLETE_HANDLE;
    lmbox_ref[threadid].buf2 = NULL;
    lmbox_ref[threadid].memcpy_handle2 = NULL;
    switch (lmbox_ref[threadid].type) {
      case UPCRI_IO_SINGLEENTRY: {
        if (!isread) { /* write: fetch bytes to write */
          upc_shared_memvec_t single_memvec;
          size_t len = lmbox_ref[threadid].data_len;
          size_t handlecnt;
          uint8_t *buf;
          single_memvec.baseaddr = lmbox_ref[threadid].loc.baseaddr;
          single_memvec.blocksize = lmbox_ref[threadid].loc.blocksize;
          single_memvec.len = len;
          handlecnt = upcri_memvecmove_handlecount(1, &single_memvec);
          buf = upcri_checkmalloc(len);
          /* use memcpy_handle2/memcpy_handle2_cnt here, because UPCRI_IO_SINGLEENTRY wont need them */
          lmbox_ref[threadid].memcpy_handle2 = upcri_checkmalloc(sizeof(bupc_handle_t)*handlecnt);
          lmbox_ref[threadid].buf1 = buf;
          lmbox_ref[threadid].memcpy_handle2_cnt = 
            upcri_memvecmove(1, buf, len, 
                             1, &single_memvec, 
                             lmbox_ref[threadid].memcpy_handle2, handlecnt UPCRI_PT_PASS);
        } else { /* read - alloc space to recv result */
          lmbox_ref[threadid].buf1 = upcri_checkmalloc(lmbox_ref[threadid].data_len);
        }
        break;
      }
      case UPCRI_IO_METADATAONLY: 
        metadataonly_cnt++;
      case UPCRI_IO_FULLDATA: 
        fulldata_cnt++;
      {
        upcr_shared_ptr_t addr = lmbox_ref[threadid].loc.baseaddr;
        size_t mboxlen = lmbox_ref[threadid].loc.len;
        size_t metadata_len = lmbox_ref[threadid].metadata_len;
        size_t fetchsz = (isread ? metadata_len : mboxlen);
      #if UPCR_DEBUG
        size_t blocksize = lmbox_ref[threadid].loc.blocksize;
        upcri_assert(blocksize == 0 || blocksize >= mboxlen);
      #endif
        if (lmbox_ref[threadid].type == UPCRI_IO_FULLDATA) upcri_assert(islocal);
        if (lmbox_ref[threadid].type == UPCRI_IO_METADATAONLY) {
          upcri_assert(!islocal);
          if (isread) mboxlen += (UPCRI_IO_PAD + lmbox_ref[threadid].data_len);
        }
        lmbox_ref[threadid].buf1 = upcri_checkmalloc(UPCRI_IO_PAD+mboxlen);
        lmbox_ref[threadid].memcpy_handle = 
          _upcr_memget_nb((void *)UPCRI_ALIGNUP(lmbox_ref[threadid].buf1,UPCRI_IO_PAD), 
                            addr, fetchsz UPCRI_PT_PASS);
        break;
      }
      case UPCRI_IO_NOENTRY: break;
      default: upcri_err("bad upcri_mboxref_type_t");
    }
  }
  /* pass 2 - finish metadata fetch, start data gather fetch */
  if (!isread && metadataonly_cnt) {
    for (threadid = 0; threadid < upcr_threads(); threadid++) {
      switch (lmbox_ref[threadid].type) {
        case UPCRI_IO_METADATAONLY: {
          size_t memvec_cnt;
          upc_shared_memvec_t *memvec;

          _upcr_waitsync(lmbox_ref[threadid].memcpy_handle UPCRI_PT_PASS);
          lmbox_ref[threadid].memcpy_handle = BUPC_COMPLETE_HANDLE;

          upcri_metadata_mbox_extractvecs((upcri_metadata_mbox_t *)UPCRI_ALIGNUP(lmbox_ref[threadid].buf1,UPCRI_IO_PAD),
            NULL, NULL, &memvec_cnt, &memvec);
          { 
            /* alloc space for data gather and handles  */
            size_t handle_count = upcri_memvecmove_handlecount(memvec_cnt, memvec);
            size_t datasz = lmbox_ref[threadid].data_len;
            void *buf2 = upcri_checkmalloc(UPCRI_IO_PAD + datasz + UPCRI_IO_PAD +
                                      handle_count*sizeof(bupc_handle_t)); 
            uint8_t *dataptr = (uint8_t *)UPCRI_ALIGNUP(buf2, UPCRI_IO_PAD);
            bupc_handle_t *handle2 = (bupc_handle_t *)UPCRI_ALIGNUP(dataptr+datasz,UPCRI_IO_PAD);
            
            handle_count = upcri_memvecmove(1, dataptr, datasz, 
                                            memvec_cnt, memvec, 
                                            handle2, handle_count UPCRI_PT_PASS);

            lmbox_ref[threadid].buf2 = buf2;
            lmbox_ref[threadid].memcpy_handle2 = handle2;
            lmbox_ref[threadid].memcpy_handle2_cnt = handle_count;
          }
          break;
        }
        default: ; /* do nothing */
      }
    }
  }
  /* pass 3 - complete memcpy, perform I/O, start copy back */
  if (lfd->last_op != UPCRI_FILE_NONE && lfd->last_op != this_op) {
    fflush(lfd->filehandle); /* flush required by C99 I/O */
  }
  lfd->last_op = this_op;
  for (threadid = 0; threadid < upcr_threads(); threadid++) {
    if (lmbox_ref[threadid].type != UPCRI_IO_NOENTRY) {
      /* complete any pending data fetches */
      _upcr_waitsync(lmbox_ref[threadid].memcpy_handle UPCRI_PT_PASS);
      lmbox_ref[threadid].memcpy_handle = BUPC_COMPLETE_HANDLE;
      if (lmbox_ref[threadid].memcpy_handle2 != NULL) {
        int hidx;
        for (hidx = 0; hidx < lmbox_ref[threadid].memcpy_handle2_cnt; hidx++) {
          _upcr_waitsync(lmbox_ref[threadid].memcpy_handle2[hidx] UPCRI_PT_PASS);
        }
        if (lmbox_ref[threadid].type == UPCRI_IO_SINGLEENTRY) /* METADATA only, this is not a malloc buf */
          upcri_free(lmbox_ref[threadid].memcpy_handle2);
      }
      lmbox_ref[threadid].memcpy_handle3 = NULL;
      /* perform I/O */
      { size_t filevec_cnt;
        size_t filevec_idx;
        upc_filevec_t *filevec;
        size_t memvec_cnt;
        upc_shared_memvec_t *memvec;
        upc_shared_memvec_t single_memvec;
        size_t handle_sz;
        uint8_t *dataptr;
        uint8_t *datapos;
        switch (lmbox_ref[threadid].type) { 
          case UPCRI_IO_SINGLEENTRY: 
            upcri_assert(lmbox_ref[threadid].single_filevec.len == lmbox_ref[threadid].data_len);
            filevec_cnt = 1;
            filevec = &(lmbox_ref[threadid].single_filevec);
            dataptr = lmbox_ref[threadid].buf1;
            memvec_cnt = 1;
            memvec = &(lmbox_ref[threadid].loc);
            break;
          case UPCRI_IO_METADATAONLY: {
            upcri_metadata_mbox_extractvecs((upcri_metadata_mbox_t *)UPCRI_ALIGNUP(lmbox_ref[threadid].buf1,UPCRI_IO_PAD),
              &filevec_cnt, &filevec, &memvec_cnt, &memvec);
            if (isread) dataptr = (uint8_t *)UPCRI_ALIGNUP(memvec+memvec_cnt, UPCRI_IO_PAD);
            else        dataptr = (uint8_t *)UPCRI_ALIGNUP(lmbox_ref[threadid].buf2, UPCRI_IO_PAD);
            break;
          }
          case UPCRI_IO_FULLDATA: {
            upcri_fulldata_mbox_t *lmbox = 
              (upcri_fulldata_mbox_t *)UPCRI_ALIGNUP(lmbox_ref[threadid].buf1,UPCRI_IO_PAD);
            filevec_cnt = lmbox->filevec_entries;
            filevec = (upc_filevec_t *)UPCRI_ALIGNUP(lmbox+1,UPCRI_IO_PAD);
            dataptr = (uint8_t *)UPCRI_ALIGNUP(filevec+filevec_cnt,UPCRI_IO_PAD);
            memvec_cnt = 1;
            memvec = &single_memvec;
            memvec->baseaddr = upcr_local_to_shared_withphase(
              (void *)UPCRI_ALIGNUP(((uint8_t*)upcri_shared_to_remote(lmbox_ref[threadid].loc.baseaddr))+
                                     lmbox_ref[threadid].metadata_len,UPCRI_IO_PAD), 0, threadid);
            memvec->blocksize = 0;
            memvec->len = lmbox_ref[threadid].data_len;
            break;
          }
          default:
            filevec_cnt = 0; /* warning suppression */
            upcri_err("bad lmbox_ref type");
        }
        #if UPCR_DEBUG
        { upc_off_t filevec_datasz = 0, memvec_datasz = 0;
          size_t i;
          for (i = 0; i < filevec_cnt; i++) filevec_datasz += filevec[i].len;
          for (i = 0; i < memvec_cnt; i++)  memvec_datasz  += memvec[i].len;
          upcri_assert(memvec_datasz == lmbox_ref[threadid].data_len);
          upcri_assert(filevec_datasz == lmbox_ref[threadid].data_len);
        }
        #endif
        lmbox_ref[threadid].size_result = 0;
        lmbox_ref[threadid].errno_result_mboxref = 0;
        datapos = dataptr;
        for (filevec_idx = 0; filevec_idx < filevec_cnt; filevec_idx++) {
          if (fseek(lfd->filehandle, filevec[filevec_idx].offset, SEEK_SET)) {
            lmbox_ref[threadid].errno_result_mboxref = errno;
            upcri_io_error(errno, "Error in fseek while preparing for I/O");
            errno = 0;
            break; /* abandon further I/O operations from this thread */
          } else if (isread) { /* I/O read */
            upc_off_t result = fread(datapos, 1, filevec[filevec_idx].len, lfd->filehandle);
            lmbox_ref[threadid].size_result += result;
            if (result != filevec[filevec_idx].len) {
              if (ferror(lfd->filehandle)) {
                upcri_io_error(errno, "I/O error in fread");
                lmbox_ref[threadid].errno_result_mboxref = errno;
              } else upcri_assert(feof(lfd->filehandle)); /* leave errno == 0 for EOF */
              errno = 0;
              { /* cut off the memvec to reflect only the values we plan to write back */
                size_t memvec_idx;
                upc_off_t dataread = 0;
                for (memvec_idx = 0; ; memvec_idx++) {
                  upcri_assert(memvec_idx <= memvec_cnt);
                  if (dataread + memvec[memvec_idx].len >= lmbox_ref[threadid].size_result) {
                    memvec[memvec_idx].len = lmbox_ref[threadid].size_result - dataread;
                    memvec_cnt = memvec_idx + 1;
                    break;
                  } else {
                    dataread += memvec[memvec_idx].len;
                  }
                }
              }
              /* abandon further I/O operations from this thread */
              break; 
            }
          } else { /* I/O write */
            /* C99 does not guarantee behavior for writes after a seek past EOF,
               but POSIX guarantees zero-extension, so use that for now
               another option would be to detect cases where we need to grow the file,
               and execute an fclose/ftruncate/fopen to grow it to the new max size
             */
            upc_off_t result = fwrite(datapos, 1, filevec[filevec_idx].len, lfd->filehandle);
            lmbox_ref[threadid].size_result += result;
            if (result != filevec[filevec_idx].len) {
              int myerrno = errno;
              upcri_assert(ferror(lfd->filehandle));
              clearerr(lfd->filehandle);
              upcri_io_error(myerrno, "I/O error in fwrite");
              lmbox_ref[threadid].errno_result_mboxref = myerrno;
              errno = 0;
              break; /* abandon further I/O operations from this thread */
            }  
          }
          datapos += filevec[filevec_idx].len;
        } /* filevec loop */
        /* initiate write-back */
        handle_sz = 0;
        if (lmbox_ref[threadid].errno_result_mboxref != 0) handle_sz++;
        else if (lmbox_ref[threadid].size_result != lmbox_ref[threadid].data_len) handle_sz++;
        if (isread) handle_sz += upcri_memvecmove_handlecount(memvec_cnt, memvec);
        if (handle_sz > 0)
          lmbox_ref[threadid].memcpy_handle3 = upcri_checkmalloc(handle_sz*sizeof(bupc_handle_t));
        else lmbox_ref[threadid].memcpy_handle3 = NULL;
        lmbox_ref[threadid].memcpy_handle3_cnt = 0;
        if (isread) {
          if ((lfd->flags & UPC_STRONG_CA) && threadid > 0) { 
            /* ensure overlapping regions of shared data (specified by diff threads)
               are written-back atomically by thread */
            upcri_mboxref_t * prev_mboxref = &(lmbox_ref[threadid-1]);
            if (prev_mboxref->type != UPCRI_IO_NOENTRY && prev_mboxref->memcpy_handle3) {
              int hidx;
              for (hidx = 0; hidx < prev_mboxref->memcpy_handle3_cnt; hidx++) {
                _upcr_waitsync(prev_mboxref->memcpy_handle3[hidx] UPCRI_PT_PASS);
              }
              upcri_free(prev_mboxref->memcpy_handle3);
              prev_mboxref->memcpy_handle3 = NULL;
            }
          }
          lmbox_ref[threadid].memcpy_handle3_cnt = 
            upcri_memvecmove(0, dataptr, lmbox_ref[threadid].size_result, 
                                memvec_cnt, memvec, 
                                lmbox_ref[threadid].memcpy_handle3, handle_sz UPCRI_PT_PASS);
        }
        if (lmbox_ref[threadid].errno_result_mboxref != 0) { /* hit an I/O error - report to initiator in fd->errno_result */
          lmbox_ref[threadid].memcpy_handle3[lmbox_ref[threadid].memcpy_handle3_cnt] = 
            _upcr_memput_nb(upcr_pshared_to_shared(
                               upcr_add_psharedI(upcr_add_pshared1(fd, sizeof(bupc_file_t), threadid),
                                                  1, offsetof(bupc_file_t, errno_result_perthread))),
                                &(lmbox_ref[threadid].errno_result_mboxref),
                                sizeof(int) UPCRI_PT_PASS);
          lmbox_ref[threadid].memcpy_handle3_cnt++;
          upcri_assert(lmbox_ref[threadid].memcpy_handle3_cnt <= handle_sz);
        } else if (lmbox_ref[threadid].size_result != lmbox_ref[threadid].data_len) {
          /* read hit EOF, write back modified result to reader's fd->size_result */
          upcri_assert(isread && lmbox_ref[threadid].size_result < lmbox_ref[threadid].data_len);
          lmbox_ref[threadid].memcpy_handle3[lmbox_ref[threadid].memcpy_handle3_cnt] = 
            _upcr_memput_nb(upcr_pshared_to_shared(
                               upcr_add_psharedI(upcr_add_pshared1(fd, sizeof(bupc_file_t), threadid),
                                                1, offsetof(bupc_file_t, size_result))),
                              &(lmbox_ref[threadid].size_result),
                              sizeof(lmbox_ref[threadid].size_result) UPCRI_PT_PASS);
          lmbox_ref[threadid].memcpy_handle3_cnt++;
          upcri_assert(lmbox_ref[threadid].memcpy_handle3_cnt <= handle_sz);
        }
      }
    }
  }
  /* pass 4 - complete copyback, free bufs, clear type flag */
  for (threadid = 0; threadid < upcr_threads(); threadid++) {
    if (lmbox_ref[threadid].type != UPCRI_IO_NOENTRY) {
      if (lmbox_ref[threadid].memcpy_handle3 != NULL) {
        int hidx;
        for (hidx = 0; hidx < lmbox_ref[threadid].memcpy_handle3_cnt; hidx++) {
          _upcr_waitsync(lmbox_ref[threadid].memcpy_handle3[hidx] UPCRI_PT_PASS);
        }
        upcri_free(lmbox_ref[threadid].memcpy_handle3);
      }

      if (lmbox_ref[threadid].buf1) upcri_free(lmbox_ref[threadid].buf1);
      if (lmbox_ref[threadid].buf2) upcri_free(lmbox_ref[threadid].buf2);
      lmbox_ref[threadid].type = UPCRI_IO_NOENTRY;
    }
  }
}

static upc_off_t upcri_finish_mbox(upcr_pshared_ptr_t fd, int islocal, int isread UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  if (lfd->errno_result_perthread != 0) upcri_io_error(lfd->errno_result_perthread, strerror(lfd->errno_result_perthread));
  if (upcr_isnull_pshared(lfd->mbox)) {
    return (lfd->errno_result_perthread ? -1 : lfd->size_result); /* nothing else to do */
  }
  
  if (islocal && isread) { /* the only case where additional work is required */
    upc_local_memvec_t *mbox_memvec = upcr_pshared_to_local(lfd->mbox);
    size_t memvec_cnt = mbox_memvec[0].len;
    upcri_fulldata_mbox_t *lmbox = (upcri_fulldata_mbox_t *)UPCRI_ALIGNUP(mbox_memvec+memvec_cnt+1,UPCRI_IO_PAD);
    uint8_t *mbox_data = (uint8_t *)UPCRI_ALIGNUP(((upc_filevec_t *)UPCRI_ALIGNUP(lmbox+1,UPCRI_IO_PAD))+lmbox->filevec_entries,UPCRI_IO_PAD);
    size_t i;
    mbox_memvec++; /* skip dummy */
    for (i=0; i < memvec_cnt; i++) { /* scatter data read into local bufs */
      memcpy(mbox_memvec[i].baseaddr, mbox_data, mbox_memvec[i].len);
      mbox_data += mbox_memvec[i].len;
    }
  }

  upcr_free(upcr_pshared_to_shared(lfd->mbox));
  upcr_setnull_pshared(&lfd->mbox);
  return (lfd->errno_result_perthread ? -1 : lfd->size_result);
}

/* ------------------------------------------------------------------------------------ */
upc_off_t _BUPC_IOFN(read_list_local)  (upcr_pshared_ptr_t fd, size_t memvec_entries, upc_local_memvec_t const *memvec, size_t filevec_entries, upc_filevec_t const *filevec, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  upc_off_t retval;
  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  UPCRI_CHECK_READ(lfd);
  UPCRI_CHECK_INDIV(lfd);
  UPCRI_CHECK_ARG((memvec != NULL || memvec_entries == 0) && (filevec != NULL || filevec_entries == 0));
  UPCRI_CHECK_FLAGS(sync_mode);
  UPCRI_BEGIN_ASYNC(lfd, sync_mode);
  UPCRI_INSYNC_BARRIER(lfd, sync_mode);
  upcri_signal_mbox(fd, 1, 1,  
                    memvec_entries, memvec, filevec_entries, filevec UPCRI_PT_PASS);
  upcri_io_barrier();
  if (upcr_mythread() == 0) upcri_process_mbox(fd, 1, 1 UPCRI_PT_PASS);
  upcri_io_barrier();
  retval = upcri_finish_mbox(fd, 1, 1 UPCRI_PT_PASS);

  UPCRI_OUTSYNC_BARRIER(lfd, sync_mode);
  UPCRI_END_ASYNC(lfd, retval);
  return retval;
}
/* ------------------------------------------------------------------------------------ */
upc_off_t _BUPC_IOFN(read_list_shared) (upcr_pshared_ptr_t fd, size_t memvec_entries, upc_shared_memvec_t const *memvec, size_t filevec_entries, upc_filevec_t const *filevec, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  upc_off_t retval;
  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  UPCRI_CHECK_READ(lfd);
  UPCRI_CHECK_ARG((memvec != NULL || memvec_entries == 0) && (filevec != NULL || filevec_entries == 0));
  UPCRI_CHECK_FLAGS(sync_mode);
  UPCRI_BEGIN_ASYNC(lfd, sync_mode);
  UPCRI_INSYNC_BARRIER(lfd, sync_mode);
  upcri_signal_mbox(fd, 0, 1,  
                    memvec_entries, memvec, filevec_entries, filevec UPCRI_PT_PASS);
  upcri_io_barrier();
  if (upcr_mythread() == 0) upcri_process_mbox(fd, 0, 1 UPCRI_PT_PASS);
  upcri_io_barrier();
  retval = upcri_finish_mbox(fd, 0, 1 UPCRI_PT_PASS);

  UPCRI_OUTSYNC_BARRIER(lfd, sync_mode);
  UPCRI_END_ASYNC(lfd, retval);
  return retval;
}
/* ------------------------------------------------------------------------------------ */
upc_off_t _BUPC_IOFN(write_list_local) (upcr_pshared_ptr_t fd, size_t memvec_entries, upc_local_memvec_t const *memvec, size_t filevec_entries, upc_filevec_t const *filevec, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  upc_off_t retval;
  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  UPCRI_CHECK_WRITE(lfd);
  UPCRI_CHECK_INDIV(lfd);
  UPCRI_CHECK_ARG((memvec != NULL || memvec_entries == 0) && (filevec != NULL || filevec_entries == 0));
  UPCRI_CHECK_FLAGS(sync_mode);
  UPCRI_BEGIN_ASYNC(lfd, sync_mode);
  UPCRI_INSYNC_BARRIER(lfd, sync_mode);
  upcri_signal_mbox(fd, 1, 0,  
                    memvec_entries, memvec, filevec_entries, filevec UPCRI_PT_PASS);
  upcri_io_barrier();
  if (upcr_mythread() == 0) upcri_process_mbox(fd, 1, 0 UPCRI_PT_PASS);
  upcri_io_barrier();
  retval = upcri_finish_mbox(fd, 1, 0 UPCRI_PT_PASS);

  UPCRI_OUTSYNC_BARRIER(lfd, sync_mode);
  UPCRI_END_ASYNC(lfd, retval);
  return retval;
}
/* ------------------------------------------------------------------------------------ */
upc_off_t _BUPC_IOFN(write_list_shared)(upcr_pshared_ptr_t fd, size_t memvec_entries, upc_shared_memvec_t const *memvec, size_t filevec_entries, upc_filevec_t const *filevec, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  upc_off_t retval;
  UPCRI_CHECK_FD(lfd);
  UPCRI_CHECK_ASYNC(lfd);
  UPCRI_CHECK_WRITE(lfd);
  UPCRI_CHECK_ARG((memvec != NULL || memvec_entries == 0) && (filevec != NULL || filevec_entries == 0));
  UPCRI_CHECK_FLAGS(sync_mode);
  UPCRI_BEGIN_ASYNC(lfd, sync_mode);
  UPCRI_INSYNC_BARRIER(lfd, sync_mode);
  upcri_signal_mbox(fd, 0, 0,  
                    memvec_entries, memvec, filevec_entries, filevec UPCRI_PT_PASS);
  upcri_io_barrier();
  if (upcr_mythread() == 0) upcri_process_mbox(fd, 0, 0 UPCRI_PT_PASS);
  upcri_io_barrier();
  retval = upcri_finish_mbox(fd, 0, 0 UPCRI_PT_PASS);

  UPCRI_OUTSYNC_BARRIER(lfd, sync_mode);
  UPCRI_END_ASYNC(lfd, retval);
  return retval;
}
/* ------------------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------------------ */
/* ASYNC FUNCTIONS */
/* ------------------------------------------------------------------------------------ */
upc_off_t _BUPC_IOFN(wait_async)(upcr_pshared_ptr_t fd UPCRI_PT_ARG) {
  while (1) {
    int flag;
    upc_off_t result = bupc_all_ftest_async(fd, &flag);
    if (flag) return result;
    upcr_poll();
    gasnett_sched_yield();
  }
}
/* ------------------------------------------------------------------------------------ */
upc_off_t _BUPC_IOFN(test_async)(upcr_pshared_ptr_t fd, int *flag UPCRI_PT_ARG) {
  bupc_file_t *lfd = upcri_io_fd_to_mylfd(fd);
  UPCRI_CHECK_NONNULL(flag);
  if (UPCRI_FD_IS_BAD(lfd)) {
    upcri_io_error(EINVAL, "bad file handle passed to bupc_all_ftest/fwait_async");
    *flag = 1;
    return -1;
  }
  if (!lfd->async_outstanding) {
    upcri_io_error(EINVAL, "bupc_all_ftest/fwait_async called while no asynchronous operation pending");
    *flag = 1;
    return -1;
  }

  *flag = 0;
  /* currently async ops are completed synchronously -
     otherwise, thread 0 would broadcast the async results (isdone, errno) here
   */

  UPCRI_OUTSYNC_BARRIER(lfd, lfd->async_sync_mode);
  lfd->async_outstanding = 0;
  *flag = 1;
  if (lfd->errno_result_perthread != 0) { /* I/O failure */
    upcri_io_error(lfd->errno_result_perthread, strerror(lfd->errno_result_perthread));
    return -1;
  } else { /* success */
    return lfd->size_result;
  }
}
/* ------------------------------------------------------------------------------------ */
void _BUPC_IOFN(read_local_async) (upcr_pshared_ptr_t fd, void *buffer, size_t size, size_t nmemb, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_all_fread_local(fd, buffer, size, nmemb, (sync_mode | UPC_ASYNC));
}
/* ------------------------------------------------------------------------------------ */
void _BUPC_IOFN(read_shared_async) (upcr_pshared_ptr_t fd, upcr_shared_ptr_t buffer, size_t blocksize, size_t size, size_t nmemb, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_all_fread_shared(fd, buffer, blocksize, size, nmemb, (sync_mode | UPC_ASYNC));
}
/* ------------------------------------------------------------------------------------ */
void _BUPC_IOFN(write_local_async) (upcr_pshared_ptr_t fd, void *buffer, size_t size, size_t nmemb, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_all_fwrite_local(fd, buffer, size, nmemb, (sync_mode | UPC_ASYNC));
}
/* ------------------------------------------------------------------------------------ */
void _BUPC_IOFN(write_shared_async)(upcr_pshared_ptr_t fd, upcr_shared_ptr_t buffer, size_t blocksize, size_t size, size_t nmemb, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_all_fwrite_shared(fd, buffer, blocksize, size, nmemb, (sync_mode | UPC_ASYNC));
}
/* ------------------------------------------------------------------------------------ */
void _BUPC_IOFN(read_list_local_async)  (upcr_pshared_ptr_t fd, size_t memvec_entries, upc_local_memvec_t const *memvec, size_t filevec_entries, upc_filevec_t const *filevec, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_all_fread_list_local(fd, memvec_entries, memvec, filevec_entries, filevec, (sync_mode | UPC_ASYNC));
}
/* ------------------------------------------------------------------------------------ */
void _BUPC_IOFN(read_list_shared_async) (upcr_pshared_ptr_t fd, size_t memvec_entries, upc_shared_memvec_t const *memvec, size_t filevec_entries, upc_filevec_t const *filevec, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_all_fread_list_shared(fd, memvec_entries, memvec, filevec_entries, filevec, (sync_mode | UPC_ASYNC));
}
/* ------------------------------------------------------------------------------------ */
void _BUPC_IOFN(write_list_local_async) (upcr_pshared_ptr_t fd, size_t memvec_entries, upc_local_memvec_t const *memvec, size_t filevec_entries, upc_filevec_t const *filevec, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_all_fwrite_list_local(fd, memvec_entries, memvec, filevec_entries, filevec, (sync_mode | UPC_ASYNC));
}
/* ------------------------------------------------------------------------------------ */
void _BUPC_IOFN(write_list_shared_async)(upcr_pshared_ptr_t fd, size_t memvec_entries, upc_shared_memvec_t const *memvec, size_t filevec_entries, upc_filevec_t const *filevec, upc_flag_t sync_mode UPCRI_PT_ARG) {
  bupc_all_fwrite_list_shared(fd, memvec_entries, memvec, filevec_entries, filevec, (sync_mode | UPC_ASYNC));
}
/* ------------------------------------------------------------------------------------ */
