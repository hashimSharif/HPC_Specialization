/* Reference implementation of upc_castable.h 
 * Copyright 2012, The Regents of the University of California 
 * This code is under BSD license: http://upc.lbl.gov/download/dist/LICENSE.TXT
 */

#ifndef _UPC_CASTABLE_BITS_H
#define _UPC_CASTABLE_BITS_H

#define UPC_CASTABLE_ALL_ALLOC      (1<<0)
#define UPC_CASTABLE_GLOBAL_ALLOC   (1<<1)
#define UPC_CASTABLE_ALLOC          (1<<2)
#define UPC_CASTABLE_STATIC         (1<<3)

#define UPC_CASTABLE_ALL  (            \
           UPC_CASTABLE_ALL_ALLOC    | \
           UPC_CASTABLE_GLOBAL_ALLOC | \
           UPC_CASTABLE_ALLOC        | \
           UPC_CASTABLE_STATIC         \
         )

typedef struct _S_upc_thread_info {
  int guaranteedCastable;
  int probablyCastable;
} upc_thread_info_t;

#endif /* _UPC_CASTABLE_H */
