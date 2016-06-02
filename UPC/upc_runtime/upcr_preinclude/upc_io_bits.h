/* upcr_preinclude/upc_io_bits.h */

#ifndef BUPC_IO_BITS
#error This header should not be included directly. Include upc_io.h instead
#endif

#include <upcr_config.h>

/* get upc_flag_t and values */
#include <upcr_preinclude/upc_bits.h>

/* UPC-IO specific upc_flag_t values */
#if __UPC_IO__ >= 2 || UPCRI_BUILDING_LIBUPCR
#define UPC_ASYNC	64
#endif

struct bupc_file_S_trans;
#if defined(__BERKELEY_UPC_FIRST_PREPROCESS__) && defined(__BERKELEY_UPC__)
  #define _BUPC_STRUCT_TAG(tname) tname##_S_trans
  #if __BERKELEY_UPC__ == 2 && __BERKELEY_UPC_MINOR__ < 1
    /* temporary hack workaround for translator bug 784 */
    typedef shared struct _BUPC_STRUCT_TAG(bupc_file) { int _junk; } upc_file_t;
  #else
    typedef shared struct _BUPC_STRUCT_TAG(bupc_file) upc_file_t;
  #endif
  #define _BUPC_FILE_T_PTR upc_file_t *
#elif defined(__BERKELEY_UPC_FIRST_PREPROCESS__) || defined(__BERKELEY_UPC_ONLY_PREPROCESS__)
  #define _BUPC_STRUCT_TAG(tname) tname##_S
  typedef shared struct _BUPC_STRUCT_TAG(bupc_file) upc_file_t;
  #define _BUPC_FILE_T_PTR upc_file_t *
#else
  #define _BUPC_STRUCT_TAG(tname) tname##_S
  typedef struct _BUPC_STRUCT_TAG(bupc_file) upc_file_t;
  #define _BUPC_FILE_T_PTR upcr_pshared_ptr_t
#endif

#if BUPC_IO_64
  typedef int64_t upc_off_t;
  #define UPCRI_MAX_OFF_T ((upc_off_t)(((uint64_t)-1) >> 1))
#else
  typedef int32_t upc_off_t;
  #define UPCRI_MAX_OFF_T ((upc_off_t)(((uint32_t)-1) >> 1))
#endif

typedef struct _BUPC_STRUCT_TAG(bupc_hint) {
    const char *key;
    const char *value;
} upc_hint_t;

typedef struct _BUPC_STRUCT_TAG(bupc_filevec) {
    upc_off_t offset;
    size_t len;
} upc_filevec_t;

typedef struct _BUPC_STRUCT_TAG(bupc_shared_memvec) {
    bupc_sharedptr_t baseaddr;
    size_t blocksize;
    size_t len;
} upc_shared_memvec_t;

typedef struct _BUPC_STRUCT_TAG(bupc_local_memvec) {
    void *baseaddr;
    size_t len;  
} upc_local_memvec_t;

/* indicate that we support the officially deprecated typedef syntax for UPC-IO struct types */
#define __UPC_IO_TYPEDEFS__ 1

/* ensure that "struct upc_filevec" and friends work as expected */
#define upc_hint          _BUPC_STRUCT_TAG(bupc_hint)
#define upc_filevec       _BUPC_STRUCT_TAG(bupc_filevec)
#define upc_shared_memvec _BUPC_STRUCT_TAG(bupc_shared_memvec)
#define upc_local_memvec  _BUPC_STRUCT_TAG(bupc_local_memvec)

#if defined(__BERKELEY_UPC_SECOND_PREPROCESS__)
  /* another translator bug workaround - prevent warnings on listIO arg passing */
  #define _upc_local_memvec_t   void
  #define _upc_shared_memvec_t  void
  #define _upc_filevec_t        void
  #define _upc_hint_t           void
#else
  #define _upc_local_memvec_t   upc_local_memvec_t
  #define _upc_shared_memvec_t  upc_shared_memvec_t
  #define _upc_filevec_t        upc_filevec_t
  #define _upc_hint_t           upc_hint_t
#endif

#define UPC_RDONLY            ((int)(1 << 0))
#define UPC_WRONLY            ((int)(1 << 1))
#define UPC_RDWR              ((int)(1 << 2))
#define UPC_INDIVIDUAL_FP     ((int)(1 << 3))
#define UPC_COMMON_FP         ((int)(1 << 4))
#define UPC_APPEND            ((int)(1 << 5))
#define UPC_CREATE            ((int)(1 << 6))
#define UPC_EXCL              ((int)(1 << 7))
#define UPC_STRONG_CA         ((int)(1 << 8))
#define UPC_TRUNC             ((int)(1 << 9))
#define UPC_DELETE_ON_CLOSE   ((int)(1 << 10))

#define UPC_GET_CA_SEMANTICS          (1 << 0)
#define UPC_SET_WEAK_CA_SEMANTICS     (1 << 1)
#define UPC_SET_STRONG_CA_SEMANTICS   (1 << 2)
#define UPC_GET_FP                    (1 << 3)
#define UPC_SET_COMMON_FP             (1 << 4)
#define UPC_SET_INDIVIDUAL_FP         (1 << 5)
#define UPC_GET_FL                    (1 << 6)
#define UPC_GET_FN                    (1 << 7)
#define UPC_GET_HINTS                 (1 << 8)
#define UPC_SET_HINT                  (1 << 9)
#define UPC_ASYNC_OUTSTANDING         (1 << 10)

#define UPC_SEEK_SET          ((int)(1 << 0))
#define UPC_SEEK_CUR          ((int)(1 << 1))
#define UPC_SEEK_END          ((int)(1 << 2))


#if defined(__BERKELEY_UPC_FIRST_PREPROCESS__) || defined(UPCRI_LIBWRAP)
  #define _BUPC_IOFN(name) bupc_all_f ## name
  #define _BUPC_IOPT_ARG 
#else
  #define _BUPC_IOFN(name) _upcr_all_f ## name
  #define _BUPC_IOPT_ARG UPCRI_PT_ARG
#endif

_BUPC_FILE_T_PTR _BUPC_IOFN(open)(const char *_fname, int _flags, size_t _numhints, _upc_hint_t const *_hints _BUPC_IOPT_ARG);
int              _BUPC_IOFN(close)(_BUPC_FILE_T_PTR _fd _BUPC_IOPT_ARG);
int              _BUPC_IOFN(sync)(_BUPC_FILE_T_PTR _fd _BUPC_IOPT_ARG);
upc_off_t        _BUPC_IOFN(seek)(_BUPC_FILE_T_PTR _fd, upc_off_t _offset, int _origin _BUPC_IOPT_ARG);
int              _BUPC_IOFN(set_size)(_BUPC_FILE_T_PTR _fd, upc_off_t _size _BUPC_IOPT_ARG);
upc_off_t        _BUPC_IOFN(get_size)(_BUPC_FILE_T_PTR _fd _BUPC_IOPT_ARG);
int              _BUPC_IOFN(preallocate)(_BUPC_FILE_T_PTR _fd, upc_off_t _size _BUPC_IOPT_ARG);
int              _BUPC_IOFN(cntl)(_BUPC_FILE_T_PTR _fd, int _cmd, void *_arg _BUPC_IOPT_ARG);

upc_off_t _BUPC_IOFN(read_local)  (_BUPC_FILE_T_PTR _fd, void *_buffer, size_t _size, size_t _nmemb, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
upc_off_t _BUPC_IOFN(write_local) (_BUPC_FILE_T_PTR _fd, void *_buffer, size_t _size, size_t _nmemb, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
upc_off_t _BUPC_IOFN(read_shared) (_BUPC_FILE_T_PTR _fd, bupc_sharedptr_t _buffer, size_t _blocksize, size_t _size, size_t _nmemb, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
upc_off_t _BUPC_IOFN(write_shared)(_BUPC_FILE_T_PTR _fd, bupc_sharedptr_t _buffer, size_t _blocksize, size_t _size, size_t _nmemb, upc_flag_t _sync_mode _BUPC_IOPT_ARG);

upc_off_t _BUPC_IOFN(read_list_local)  (_BUPC_FILE_T_PTR _fd, size_t _memvec_entries, _upc_local_memvec_t  const *_memvec, size_t _filevec_entries, _upc_filevec_t const *_filevec, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
upc_off_t _BUPC_IOFN(read_list_shared) (_BUPC_FILE_T_PTR _fd, size_t _memvec_entries, _upc_shared_memvec_t const *_memvec, size_t _filevec_entries, _upc_filevec_t const *_filevec, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
upc_off_t _BUPC_IOFN(write_list_local) (_BUPC_FILE_T_PTR _fd, size_t _memvec_entries, _upc_local_memvec_t  const *_memvec, size_t _filevec_entries, _upc_filevec_t const *_filevec, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
upc_off_t _BUPC_IOFN(write_list_shared)(_BUPC_FILE_T_PTR _fd, size_t _memvec_entries, _upc_shared_memvec_t const *_memvec, size_t _filevec_entries, _upc_filevec_t const *_filevec, upc_flag_t _sync_mode _BUPC_IOPT_ARG);

void _BUPC_IOFN(read_local_async)  (_BUPC_FILE_T_PTR _fd, void *_buffer, size_t _size, size_t _nmemb, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
void _BUPC_IOFN(write_local_async) (_BUPC_FILE_T_PTR _fd, void *_buffer, size_t _size, size_t _nmemb, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
void _BUPC_IOFN(read_shared_async) (_BUPC_FILE_T_PTR _fd, bupc_sharedptr_t _buffer, size_t _blocksize, size_t _size, size_t _nmemb, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
void _BUPC_IOFN(write_shared_async)(_BUPC_FILE_T_PTR _fd, bupc_sharedptr_t _buffer, size_t _blocksize, size_t _size, size_t _nmemb, upc_flag_t _sync_mode _BUPC_IOPT_ARG);

void _BUPC_IOFN(read_list_local_async)  (_BUPC_FILE_T_PTR _fd, size_t _memvec_entries, _upc_local_memvec_t  const *_memvec, size_t _filevec_entries, _upc_filevec_t const *_filevec, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
void _BUPC_IOFN(read_list_shared_async) (_BUPC_FILE_T_PTR _fd, size_t _memvec_entries, _upc_shared_memvec_t const *_memvec, size_t _filevec_entries, _upc_filevec_t const *_filevec, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
void _BUPC_IOFN(write_list_local_async) (_BUPC_FILE_T_PTR _fd, size_t _memvec_entries, _upc_local_memvec_t  const *_memvec, size_t _filevec_entries, _upc_filevec_t const *_filevec, upc_flag_t _sync_mode _BUPC_IOPT_ARG);
void _BUPC_IOFN(write_list_shared_async)(_BUPC_FILE_T_PTR _fd, size_t _memvec_entries, _upc_shared_memvec_t const *_memvec, size_t _filevec_entries, _upc_filevec_t const *_filevec, upc_flag_t _sync_mode _BUPC_IOPT_ARG);

upc_off_t _BUPC_IOFN(wait_async)(_BUPC_FILE_T_PTR _fd _BUPC_IOPT_ARG);
upc_off_t _BUPC_IOFN(test_async)(_BUPC_FILE_T_PTR _fd, int *_flag _BUPC_IOPT_ARG);

#undef _BUPC_FILE_T_PTR

