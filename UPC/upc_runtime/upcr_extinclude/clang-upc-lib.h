#ifndef _CLANG_UPC_LIB_H_
#define _CLANG_UPC_LIB_H_

#pragma upc c_code
#ifdef __UPC_STATIC_THREADS__
/* defined at compile time by the -fupc-threads-N switch */
#define __UPC_N_THREADS__ THREADS
#else
/* defined at run time */
// extern const int THREADS;
#define __UPC_N_THREADS__ -1
#endif

#ifdef __UPC_PTHREADS_MODEL_TLS__
extern __thread const int MYTHREAD;
#else
// extern const int MYTHREAD;
#endif

/* Depth count used to implement the semantics of
   nested upc_forall statements.  */
#ifdef __UPC_PTHREADS_MODEL_TLS__
extern __thread int __upc_forall_depth;
#else
extern int __upc_forall_depth;
#endif

/* UPCR requires upc_fence to poll network devices */
#undef upc_fence
#define upc_fence upcr_poll()
#undef upc_poll
#define upc_poll() upcr_poll()
 
#endif /* !_CLANG_UPC_LIB_H_ */
