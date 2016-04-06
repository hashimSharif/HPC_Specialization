/* upcr_io.h */

#ifndef _UPCR_IO_H_
#define _UPCR_IO_H_

#if defined(__BERKELEY_UPC_ONLY_PREPROCESS__)
  typedef shared void *bupc_sharedptr_t;
#else
  typedef upcr_shared_ptr_t bupc_sharedptr_t;
#endif

#define BUPC_IO_BITS
#include <upcr_preinclude/upc_io_bits.h>
#undef BUPC_IO_BITS

#if !UPCRI_LIBWRAP
#define bupc_all_fopen(fname, flags, numhints, hints) \
	(upcri_srcpos(), _upcr_all_fopen(fname, flags, numhints, hints UPCRI_PT_PASS))
#define bupc_all_fclose(fd) \
	(upcri_srcpos(), _upcr_all_fclose(fd UPCRI_PT_PASS))
#define bupc_all_fsync(fd) \
	(upcri_srcpos(), _upcr_all_fsync(fd UPCRI_PT_PASS))
#define bupc_all_fseek(fd, offset, origin) \
	(upcri_srcpos(), _upcr_all_fseek(fd, offset, origin UPCRI_PT_PASS))
#define bupc_all_fset_size(fd, size) \
	(upcri_srcpos(), _upcr_all_fset_size(fd, size UPCRI_PT_PASS))
#define bupc_all_fget_size(fd) \
	(upcri_srcpos(), _upcr_all_fget_size(fd UPCRI_PT_PASS))
#define bupc_all_fpreallocate(fd, size) \
	(upcri_srcpos(), _upcr_all_fpreallocate(fd, size UPCRI_PT_PASS))
#define bupc_all_fcntl(fd, cmd, arg) \
	(upcri_srcpos(), _upcr_all_fcntl(fd, cmd, arg UPCRI_PT_PASS))

#define bupc_all_fread_local(fd, buffer, size, nmemb, sync_mode) \
	(upcri_srcpos(), _upcr_all_fread_local(fd, buffer, size, nmemb, sync_mode UPCRI_PT_PASS))
#define bupc_all_fread_shared(fd, buffer, blocksize, size, nmemb, sync_mode) \
	(upcri_srcpos(), _upcr_all_fread_shared(fd, buffer, blocksize, size, nmemb, sync_mode UPCRI_PT_PASS))
#define bupc_all_fwrite_local(fd, buffer, size, nmemb, sync_mode) \
	(upcri_srcpos(), _upcr_all_fwrite_local(fd, buffer, size, nmemb, sync_mode UPCRI_PT_PASS))
#define bupc_all_fwrite_shared(fd, buffer, blocksize, size, nmemb, sync_mode) \
	(upcri_srcpos(), _upcr_all_fwrite_shared(fd, buffer, blocksize, size, nmemb, sync_mode UPCRI_PT_PASS))

#define bupc_all_fread_list_local(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode) \
	(upcri_srcpos(), _upcr_all_fread_list_local(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode UPCRI_PT_PASS))
#define bupc_all_fread_list_shared(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode) \
	(upcri_srcpos(), _upcr_all_fread_list_shared(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode UPCRI_PT_PASS))
#define bupc_all_fwrite_list_local(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode) \
	(upcri_srcpos(), _upcr_all_fwrite_list_local(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode UPCRI_PT_PASS))
#define bupc_all_fwrite_list_shared(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode) \
	(upcri_srcpos(), _upcr_all_fwrite_list_shared(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode UPCRI_PT_PASS))

#define bupc_all_fread_local_async(fd, buffer, size, nmemb, sync_mode) \
	(upcri_srcpos(), _upcr_all_fread_local_async(fd, buffer, size, nmemb, sync_mode UPCRI_PT_PASS))
#define bupc_all_fread_shared_async(fd, buffer, blocksize, size, nmemb, sync_mode) \
	(upcri_srcpos(), _upcr_all_fread_shared_async(fd, buffer, blocksize, size, nmemb, sync_mode UPCRI_PT_PASS))
#define bupc_all_fwrite_local_async(fd, buffer, size, nmemb, sync_mode) \
	(upcri_srcpos(), _upcr_all_fwrite_local_async(fd, buffer, size, nmemb, sync_mode UPCRI_PT_PASS))
#define bupc_all_fwrite_shared_async(fd, buffer, blocksize, size, nmemb, sync_mode) \
	(upcri_srcpos(), _upcr_all_fwrite_shared_async(fd, buffer, blocksize, size, nmemb, sync_mode UPCRI_PT_PASS))

#define bupc_all_fread_list_local_async(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode) \
	(upcri_srcpos(), _upcr_all_fread_list_local_async(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode UPCRI_PT_PASS))
#define bupc_all_fread_list_shared_async(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode) \
	(upcri_srcpos(), _upcr_all_fread_list_shared_async(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode UPCRI_PT_PASS))
#define bupc_all_fwrite_list_local_async(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode) \
	(upcri_srcpos(), _upcr_all_fwrite_list_local_async(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode UPCRI_PT_PASS))
#define bupc_all_fwrite_list_shared_async(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode) \
	(upcri_srcpos(), _upcr_all_fwrite_list_shared_async(fd, memvec_entries, memvec, filevec_entries, filevec, sync_mode UPCRI_PT_PASS))

#define bupc_all_fwait_async(fd) \
	(upcri_srcpos(), _upcr_all_fwait_async(fd UPCRI_PT_PASS))
#define bupc_all_ftest_async(fd, flag) \
	(upcri_srcpos(), _upcr_all_ftest_async(fd, flag UPCRI_PT_PASS))
#endif

#endif

