/* Reference implementation of UPC atomics from UPC 1.3 
 * Written by Dan Bonachea 
 * Copyright 2013, The Regents of the University of California 
 * See LICENSE.TXT for licensing information.
 * See README for more information
 */

#undef _RUPC_HAVE_UPC13
#if __UPC_VERSION__ >= 201311
#define _RUPC_HAVE_UPC13 1
#endif

/* Every inclusion of <upc_atomic.h> has the effect of including <upc_types.h> */
#if (_RUPC_HAVE_UPC13 && !defined(MISSING_UPC_TYPES_H)) || defined(HAVE_UPC_TYPES_H)
  /* Include the compiler's upc_types.h if possible */
  #include <upc_types.h>
#else /* For older UPC compilers lacking upc_types.h, use our reference version */
  #include <rupc_types.h>
#endif

#ifndef _RUPC_ATOMIC_H
#define _RUPC_ATOMIC_H

#ifndef __UPC_ATOMIC__
#define __UPC_ATOMIC__ 1
#endif

/* upc_atomicdomain_t is a shared datatype with incomplete type */
typedef shared void rupc_atomicdomain_t;
#define upc_atomicdomain_t rupc_atomicdomain_t

/* Provide library upc_op_t values
 * The values defined in upc_types.h are guaranteed to be less than 2^16,
 * so we use the upper word to guarantee lack of conflicts
 */
#ifndef UPC_GET
#define UPC_GET   (1UL<<16)
#endif
#ifndef UPC_SET
#define UPC_SET   (1UL<<17)
#endif
#ifndef UPC_CSWAP
#define UPC_CSWAP (1UL<<18)
#endif
#ifndef UPC_SUB
#define UPC_SUB   (1UL<<19)
#endif
#ifndef UPC_INC
#define UPC_INC   (1UL<<20)
#endif
#ifndef UPC_DEC
#define UPC_DEC   (1UL<<21)
#endif

typedef int rupc_atomichint_t;
#define upc_atomichint_t rupc_atomichint_t

#ifndef UPC_ATOMIC_HINT_DEFAULT
#define UPC_ATOMIC_HINT_DEFAULT    (0)
#endif

#ifndef UPC_ATOMIC_HINT_LATENCY
#define UPC_ATOMIC_HINT_LATENCY    (1<<0)
#endif

#ifndef UPC_ATOMIC_HINT_THROUGHPUT
#define UPC_ATOMIC_HINT_THROUGHPUT (1<<1)
#endif

upc_atomicdomain_t *rupc_all_atomicdomain_alloc(upc_type_t type, upc_op_t ops, upc_atomichint_t hints);
#define upc_all_atomicdomain_alloc rupc_all_atomicdomain_alloc

void rupc_all_atomicdomain_free(upc_atomicdomain_t *ptr);
#define upc_all_atomicdomain_free rupc_all_atomicdomain_free

void rupc_atomic_strict(upc_atomicdomain_t *domain,
    void * restrict fetch_ptr, upc_op_t op,
    shared void * restrict target,
    const void * restrict operand1,
    const void * restrict operand2);
#define upc_atomic_strict rupc_atomic_strict

void rupc_atomic_relaxed(upc_atomicdomain_t *domain,
    void * restrict fetch_ptr, upc_op_t op,
    shared void * restrict target,
    const void * restrict operand1,
    const void * restrict operand2);
#define upc_atomic_relaxed rupc_atomic_relaxed

int rupc_atomic_isfast(upc_type_t type, upc_op_t ops, shared void *addr);
#define upc_atomic_isfast rupc_atomic_isfast

#endif

