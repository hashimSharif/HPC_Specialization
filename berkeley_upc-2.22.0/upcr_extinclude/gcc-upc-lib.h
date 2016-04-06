/* Copyright (C) 2001-2004 Free Software Foundation, Inc.
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

#ifndef _GCC_UPC_LIB_H_
#define _GCC_UPC_LIB_H_

#pragma upc c_code
#ifdef __UPC_STATIC_THREADS__
/* defined at compile time by the -fupc-threads-N switch */
#define __UPC_N_THREADS__ THREADS
#else
/* defined at run time */
extern const int THREADS;
#define __UPC_N_THREADS__ -1
#endif

#ifdef __UPC_PTHREADS_MODEL_TLS__
extern __thread const int MYTHREAD;
#else
extern const int MYTHREAD;
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
 
#endif /* !_GCC_UPC_LIB_H_ */
