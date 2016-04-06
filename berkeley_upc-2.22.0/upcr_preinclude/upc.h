/* Copyright (C) 2001 Free Software Foundation, Inc.
   This file is part of the UPC runtime Library.
   Written by Gary Funck <gary@intrepid.com>
   and Nenad Vukicevic <nenad@intrepid.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2, or (at
   your option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library; see the file COPYING.  If not, write to
   the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA.

   As a special exception, if you link this library with files
   compiled with a GNU compiler to produce an executable, this does
   not cause the resulting executable to be covered by the GNU General
   Public License.  This exception does not however invalidate any
   other reasons why the executable file might be covered by the GNU
   General Public License.  */

/* Spec 1.3 requires upc_types.h to be included every time */
#include <upc_types.h>

#ifndef _UPC_H_
#define _UPC_H_

#ifndef __BERKELEY_UPC_FIRST_PREPROCESS__
#error This file should only be included during initial preprocess
#endif

/* required, to define size_t */
#include <stddef.h>

#include <upcr_preinclude/upc_bits.h>

#if ! UPC_MAX_BLOCK_SIZE
#  error UPC_MAX_BLOCK_SIZE is not properly defined
#endif

#if __UPC__ != 1
#  error __UPC__ is not properly defined
#endif

/* Note: either __UPC_DYNAMIC_THREADS__ or __UPC_STATIC_THREADS__ must be
 * set to 1 (not merely defined).  JCD
 */
#if __UPC_DYNAMIC_THREADS__ == 1
# if defined(__UPC_STATIC_THREADS__)
#   error Only one of __UPC_DYNAMIC_THREADS__ and __UPC_STATIC_THREADS__ should be defined!
# endif
#elif __UPC_STATIC_THREADS__ != 1
# error either __UPC_DYNAMIC_THREADS__ or __UPC_STATIC_THREADS__ must be defined to 1!
#endif

extern void upc_global_exit (int);

/* TODO: we'll need to intercept exit (and _exit) at link time if we want to
 * intercept all possible calls to it, including those in C code/libraries
 * that we link against -- alternate approach: use atexit()
 */
#include <stdlib.h> /* real exit def must precede redefinition to avoid warnings */
#define exit(x) upcri_do_exit(x)
extern void upcri_do_exit(int);

extern size_t upc_threadof (shared void *);
extern size_t upc_phaseof (shared void *);
extern size_t upc_addrfield (shared void *);

extern shared void *upc_global_alloc (size_t, size_t);
extern shared void *upc_all_alloc (size_t, size_t);
extern shared void *upc_alloc(size_t);
extern void upc_free (shared void *);
extern void upc_all_free (shared void *);

typedef shared void upc_lock_t;

extern void upc_lock_init (upc_lock_t *);
extern upc_lock_t *upc_global_lock_alloc (void);
extern upc_lock_t *upc_all_lock_alloc (void);
extern void upc_lock_free(upc_lock_t *);
extern void upc_all_lock_free(upc_lock_t *);
extern void upc_lock (upc_lock_t *);
extern int upc_lock_attempt (upc_lock_t *);
extern void upc_unlock (upc_lock_t *);

extern void upc_memcpy(shared void *, shared const void *, size_t);
extern void upc_memget(void *, shared const void *, size_t);
extern void upc_memput(shared void *, const void *, size_t);
extern void upc_memset(shared void *, int, size_t);

extern shared void *upc_resetphase(shared void *);
extern size_t upc_affinitysize(size_t, size_t, size_t);

#ifndef BUPC_DISABLE_EXTENSIONS
#include <bupc_extensions.h>
#endif

#endif /* !_UPC_H_ */
