/*
 * UPC Semaphores, a Berkeley UPC extension 
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_sem.h $
 * Dan Bonachea <bonachea@cs.berkeley.edu>
 */

#ifndef UPCR_SEM_H
#define UPCR_SEM_H

#if UPCR_DEBUG
#  define UPCR_SEM_DEBUG 1
#endif

#define upcri_myseminfo() (&(upcri_auxdata()->sem_info))
#define upcri_hisseminfo(threadid) (             \
  upcri_assert(upcri_thread_is_local(threadid)), \
  (&(upcri_hisauxdata(upcri_thread_to_pthread(threadid))->sem_info)) )

upcr_pshared_ptr_t _bupc_sem_alloc(int flags UPCRI_PT_ARG);
void _bupc_sem_free(upcr_pshared_ptr_t s UPCRI_PT_ARG);

void _bupc_sem_post(upcr_pshared_ptr_t s UPCRI_PT_ARG);
void _bupc_sem_postN(upcr_pshared_ptr_t s, size_t N UPCRI_PT_ARG); /* only valid for INTEGER sems */

void _bupc_sem_wait(upcr_pshared_ptr_t s UPCRI_PT_ARG);
void _bupc_sem_waitN(upcr_pshared_ptr_t s, size_t N UPCRI_PT_ARG); /* only valid for INTEGER sems */

int _bupc_sem_try(upcr_pshared_ptr_t s UPCRI_PT_ARG);
int _bupc_sem_tryN(upcr_pshared_ptr_t s, size_t N UPCRI_PT_ARG); /* only valid for INTEGER sems */

void _bupc_memput_signal(upcr_shared_ptr_t dst, const void *src, size_t nbytes, upcr_pshared_ptr_t s, size_t n UPCRI_PT_ARG);
void _bupc_memput_signal_async(upcr_shared_ptr_t dst, const void *src, size_t nbytes, upcr_pshared_ptr_t s, size_t n UPCRI_PT_ARG);

#if !UPCRI_LIBWRAP
#define bupc_sem_alloc(flags) \
       (upcri_srcpos(), _bupc_sem_alloc(flags UPCRI_PT_PASS))
#define bupc_sem_free(s) \
       (upcri_srcpos(), _bupc_sem_free(s UPCRI_PT_PASS))
#define bupc_sem_post(s) \
       (upcri_srcpos(), _bupc_sem_post(s UPCRI_PT_PASS))
#define bupc_sem_postN(s,N) \
       (upcri_srcpos(), _bupc_sem_postN(s,N UPCRI_PT_PASS))
#define bupc_sem_wait(s) \
       (upcri_srcpos(), _bupc_sem_wait(s UPCRI_PT_PASS))
#define bupc_sem_waitN(s,N) \
       (upcri_srcpos(), _bupc_sem_waitN(s,N UPCRI_PT_PASS))
#define bupc_sem_try(s) \
       (upcri_srcpos(), _bupc_sem_try(s UPCRI_PT_PASS))
#define bupc_sem_tryN(s,N) \
       (upcri_srcpos(), _bupc_sem_tryN(s,N UPCRI_PT_PASS))
#define bupc_memput_signal(dst,src,nbytes,s,n) \
       (upcri_srcpos(), _bupc_memput_signal(dst,src,nbytes,s,n UPCRI_PT_PASS))
#define bupc_memput_signal_async(dst,src,nbytes,s,n) \
       (upcri_srcpos(), _bupc_memput_signal_async(dst,src,nbytes,s,n UPCRI_PT_PASS))
#endif /* !UPCRI_LIBWRAP */

#endif
