#ifndef _UPC_BITS_H_
#define _UPC_BITS_H_

/* This file contains typedefs and constants needed by both the library
 * build and by application builds.  This file contains only C.
 */

/* many bits are now contained in the standard header added by spec 1.3 */
#include <upcr_preinclude/upc_types.h>

/* flags for bupc_thread_distance */
#define BUPC_THREADS_SAME       0
#define BUPC_THREADS_VERYNEAR 100
#define BUPC_THREADS_NEAR     200
#define BUPC_THREADS_FAR      300
#define BUPC_THREADS_VERYFAR  400

/* flags for bupc_sem_alloc: */
#define BUPC_SEM_BOOLEAN    1
#define BUPC_SEM_INTEGER    2
#define BUPC_SEM_SPRODUCER  4   /* only a single thread will ever post this sem */
#define BUPC_SEM_MPRODUCER  8
#define BUPC_SEM_SCONSUMER  16  /* only a single thread will ever wait this sem */
#define BUPC_SEM_MCONSUMER  32
#define BUPC_SEM_MASK       63

#define BUPC_SEM_MAXVALUE   65535

#endif
