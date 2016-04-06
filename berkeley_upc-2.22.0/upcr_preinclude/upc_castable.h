/* Reference implementation of upc_castable.h 
 * Copyright 2012, The Regents of the University of California 
 * This code is under BSD license: http://upc.lbl.gov/download/dist/LICENSE.TXT
 */

#ifndef _UPC_CASTABLE_H
#define _UPC_CASTABLE_H

#if !defined(__BERKELEY_UPC_FIRST_PREPROCESS__) && !defined(__BERKELEY_UPC_ONLY_PREPROCESS__)
#error This file should only be included during initial preprocess
#endif

#if __UPC_CASTABLE__ != 1
#error Bad feature macro predefinition
#endif

#include <stddef.h> /* size_t */

#include <upc_castable_bits.h>

void *upc_cast(const shared void *);

upc_thread_info_t upc_thread_info(size_t);

#endif /* _UPC_CASTABLE_H */
