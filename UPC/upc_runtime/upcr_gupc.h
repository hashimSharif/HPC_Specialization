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

#ifndef UPCR_GCCUPC_H
#define UPCR_GCCUPC_H


/* The UPC runtime's main program must run first,
 * we rename the user's main to upc_main(). */
#if __MACH__
extern int main () __asm__("_upc_main");
#else
extern int main () __asm__("upc_main");
#endif

/* Remap calls to exit so that they invoke the UPC runtime's
   implementation of exit instead. */
#define exit __upc_exit
extern void __upc_exit (int __status) __attribute__ ((__noreturn__));

typedef unsigned int u_intQI_t __attribute__ ((__mode__(__QI__)));
typedef unsigned int u_intHI_t __attribute__ ((__mode__(__HI__)));
typedef unsigned int u_intSI_t __attribute__ ((__mode__(__SI__)));
typedef unsigned int u_intDI_t __attribute__ ((__mode__(__DI__)));

#if __clang_upc__
/* The Clang UPC compiler does not pre-define upc_shared_ptr_t to
   be the representation of a shared pointer.  */
#if __UPC_PTS_STRUCT_REP__
typedef struct upc_shared_ptr_struct
  {
  #if __UPC_VADDR_FIRST__
    __UPC_VADDR_TYPE__  vaddr;
    __UPC_THREAD_TYPE__ thread;
    __UPC_PHASE_TYPE__  phase;
  #else
    __UPC_PHASE_TYPE__  phase;
    __UPC_THREAD_TYPE__ thread;
    __UPC_VADDR_TYPE__  vaddr;
  #endif
  } upc_shared_ptr_t;
typedef upc_shared_ptr_t *upc_shared_ptr_p;

#elif __UPC_PTS_PACKED_REP__

#if __SIZEOF_LONG__ == 8
#define GUPCR_PTS_REP_T unsigned long                                           
#else                                                                           
#define GUPCR_PTS_REP_T unsigned long long
#endif
typedef GUPCR_PTS_REP_T upc_shared_ptr_t;                                       
typedef upc_shared_ptr_t *upc_shared_ptr_p;

#endif
#endif /* __clang_upc__ */

inline static
upcr_shared_ptr_t
upc_to_upcr (upc_shared_ptr_t ptr)
{
    return *(upcr_shared_ptr_t *)&ptr;
}

inline static
upc_shared_ptr_t
upcr_to_upc (upcr_shared_ptr_t ptr)
{
    return *(upc_shared_ptr_t *)&ptr;
}
 
inline static
shared void *
upcr_to_shared (upcr_shared_ptr_t p) {
  return *(shared void **)&p;
}

inline static
upcr_shared_ptr_t
shared_to_upcr (shared void *p) {
  return *(upcr_shared_ptr_t *)&p;
}

/* --- misc --- */
GASNETT_INLINE(upc_global_exit)
void
upc_global_exit (int exitcode)
{
  UPCR_BEGIN_FUNCTION();
  upcr_global_exit (exitcode);
}

GASNETT_INLINE(upc_addrfield)
size_t
upc_addrfield (shared void *p)
{
  UPCR_BEGIN_FUNCTION();
  return (size_t) upcr_addrfield_shared (shared_to_upcr (p));
}

GASNETT_INLINE(upc_threadof)
size_t
upc_threadof (shared void *p)
{
  UPCR_BEGIN_FUNCTION();
  return (size_t) upcr_threadof_shared (shared_to_upcr (p));
}

GASNETT_INLINE(upc_phaseof)
size_t
upc_phaseof (shared void *p)
{
  UPCR_BEGIN_FUNCTION();
  return (size_t) upcr_phaseof_shared (shared_to_upcr (p));
}

GASNETT_INLINE(upc_affinitysize)
size_t
upc_affinitysize (size_t totalsize, size_t nbytes, size_t threadid)
{
    UPCR_BEGIN_FUNCTION();
    return upcr_affinitysize (totalsize, nbytes, threadid);
}

GASNETT_INLINE(upc_resetphase)
shared void *
upc_resetphase(shared void *p)
{
  UPCR_BEGIN_FUNCTION();
  return upcr_to_shared (upcr_shared_resetphase(shared_to_upcr (p)));
}

GASNETT_INLINE(__cvtaddr)
void *
__cvtaddr (upc_shared_ptr_t p)
{
    UPCR_BEGIN_FUNCTION();
    return upcr_shared_to_local(upc_to_upcr (p));
}

GASNETT_INLINE(__getaddr)
void *
__getaddr (upc_shared_ptr_t p)
{
    UPCR_BEGIN_FUNCTION();
    void *local_addr = (void *) upcr_shared_to_local(upc_to_upcr (p));
    return local_addr;
}

/* --- barrier --- */
#define ANON_BARRIER_ID (1U << (sizeof(int)*8-1))

GASNETT_INLINE(__upc_barrier)
void
__upc_barrier (int barrier_id)
{
    UPCR_BEGIN_FUNCTION();
    const int anon_flag = (barrier_id == ANON_BARRIER_ID);
    upcr_notify(barrier_id, anon_flag);
    upcr_wait(barrier_id, anon_flag);
}

GASNETT_INLINE(__upc_notify)
void
__upc_notify (int barrier_id)
{
    UPCR_BEGIN_FUNCTION();
    const int anon_flag = (barrier_id == ANON_BARRIER_ID);
    upcr_notify(barrier_id, anon_flag);
}

GASNETT_INLINE(__upc_wait)
void
__upc_wait (int barrier_id)
{
    UPCR_BEGIN_FUNCTION();
    const int anon_flag = (barrier_id == ANON_BARRIER_ID);
    upcr_wait(barrier_id, anon_flag);
}

/* --- relaxed get --- */

GASNETT_INLINE(__getqi2)
u_intQI_t
__getqi2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    u_intQI_t result;
    upcr_get_shared(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__gethi2)
u_intHI_t
__gethi2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    u_intHI_t result;
    upcr_get_shared(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getsi2)
u_intSI_t
__getsi2 (upc_shared_ptr_t src)
{    
    UPCR_BEGIN_FUNCTION(); 
    u_intSI_t result;
    upcr_get_shared(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
} 

GASNETT_INLINE(__getdi2)
u_intDI_t
__getdi2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    u_intDI_t result;
    upcr_get_shared(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getsf2)
float
__getsf2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    float result;
    upcr_get_shared(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getdf2)
double
__getdf2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    double result;
    upcr_get_shared(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__gettf2)
long double
__gettf2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    long double result;
    upcr_get_shared(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getxf2)
long double
__getxf2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    long double result;
    upcr_get_shared(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getblk3)
void
__getblk3 (void *dest, upc_shared_ptr_t src, size_t len)
{
    UPCR_BEGIN_FUNCTION();
    upcr_get_shared(dest, upc_to_upcr (src), 0, len);
}

GASNETT_INLINE(__getsqi2)
u_intQI_t
__getsqi2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    u_intQI_t result;
    upcr_get_shared_strict(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getshi2)
u_intHI_t
__getshi2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    u_intHI_t result;
    upcr_get_shared_strict(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getssi2)
u_intSI_t
__getssi2 (upc_shared_ptr_t src)
{    
    UPCR_BEGIN_FUNCTION(); 
    u_intSI_t result;
    upcr_get_shared_strict(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
} 

GASNETT_INLINE(__getsdi2)
u_intDI_t
__getsdi2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    u_intDI_t result;
    upcr_get_shared_strict(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getssf2)
float
__getssf2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    float result;
    upcr_get_shared_strict(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getsdf2)
double
__getsdf2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    double result;
    upcr_get_shared_strict(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getstf2)
long double
__getstf2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    long double result;
    upcr_get_shared_strict(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getsxf2)
long double
__getsxf2 (upc_shared_ptr_t src)
{
    UPCR_BEGIN_FUNCTION();
    long double result;
    upcr_get_shared_strict(&result, upc_to_upcr (src), 0, sizeof(result));
    return result;
}

GASNETT_INLINE(__getsblk3)
void
__getsblk3 (void *dest, upc_shared_ptr_t src, size_t len)
{
    UPCR_BEGIN_FUNCTION();
    upcr_get_shared_strict(dest, upc_to_upcr (src), 0, len);
}

/* --- put --- */

GASNETT_INLINE(__putqi2)
void
__putqi2 (upc_shared_ptr_t dest, u_intQI_t v)
{
    UPCR_BEGIN_FUNCTION();
    const u_intQI_t src = v;
    upcr_put_shared (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__puthi2)
void
__puthi2 (upc_shared_ptr_t dest, u_intHI_t v)
{
    UPCR_BEGIN_FUNCTION();
    const u_intHI_t src = v;
    upcr_put_shared (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putsi2)
void
__putsi2 (upc_shared_ptr_t dest, u_intSI_t v)
{
    UPCR_BEGIN_FUNCTION();
    const u_intSI_t src = v;
    upcr_put_shared (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putdi2)
void
__putdi2 (upc_shared_ptr_t dest, u_intDI_t v)
{
    UPCR_BEGIN_FUNCTION();
    const u_intDI_t src = v;
    upcr_put_shared (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putsf2)
void
__putsf2 (upc_shared_ptr_t dest, float v)
{
    UPCR_BEGIN_FUNCTION();
    const float src = v;
    upcr_put_shared (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putdf2)
void
__putdf2 (upc_shared_ptr_t dest, double v)
{
    UPCR_BEGIN_FUNCTION();
    const double src = v;
    upcr_put_shared (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__puttf2)
void
__puttf2 (upc_shared_ptr_t dest, long double v)
{
    UPCR_BEGIN_FUNCTION();
    const long double src = v;
    upcr_put_shared (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putxf2)
void
__putxf2 (upc_shared_ptr_t dest, long double v)
{
    UPCR_BEGIN_FUNCTION();
    const long double src = v;
    upcr_put_shared (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putblk3)
void
__putblk3 (upc_shared_ptr_t dest, void *src, size_t len)
{
    UPCR_BEGIN_FUNCTION();
    upcr_put_shared(upc_to_upcr (dest), 0, src, len);
}

GASNETT_INLINE(__copyblk3)
void
__copyblk3 (upc_shared_ptr_t dest, upc_shared_ptr_t src, size_t len)
{
    UPCR_BEGIN_FUNCTION();
    upcr_memcpy(upc_to_upcr (dest), upc_to_upcr (src), len);
}

GASNETT_INLINE(__putsqi2)
void
__putsqi2 (upc_shared_ptr_t dest, u_intQI_t v)
{
    UPCR_BEGIN_FUNCTION();
    const u_intQI_t src = v;
    upcr_put_shared_strict (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putshi2)
void
__putshi2 (upc_shared_ptr_t dest, u_intHI_t v)
{
    UPCR_BEGIN_FUNCTION();
    const u_intHI_t src =  v;
    upcr_put_shared_strict (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putssi2)
void
__putssi2 (upc_shared_ptr_t dest, u_intSI_t v)
{
    UPCR_BEGIN_FUNCTION();
    const u_intSI_t src = v;
    upcr_put_shared_strict (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putsdi2)
void
__putsdi2 (upc_shared_ptr_t dest, u_intDI_t v)
{
    UPCR_BEGIN_FUNCTION();
    const u_intDI_t src = v;
    upcr_put_shared_strict (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putssf2)
void
__putssf2 (upc_shared_ptr_t dest, float v)
{
    UPCR_BEGIN_FUNCTION();
    const float src = v;
    upcr_put_shared_strict (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putsdf2)
void
__putsdf2 (upc_shared_ptr_t dest, double v)
{
    UPCR_BEGIN_FUNCTION();
    const double src = v;
    upcr_put_shared_strict (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putstf2)
void
__putstf2 (upc_shared_ptr_t dest, long double v)
{
    UPCR_BEGIN_FUNCTION();
    const long double src = v;
    upcr_put_shared_strict (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putsxf2)
void
__putsxf2 (upc_shared_ptr_t dest, long double v)
{
    UPCR_BEGIN_FUNCTION();
    const long double src = v;
    upcr_put_shared_strict (upc_to_upcr (dest), 0, (void *) &src, sizeof(src));
}

GASNETT_INLINE(__putsblk3)
void
__putsblk3 (upc_shared_ptr_t dest, void *src, size_t len)
{
    UPCR_BEGIN_FUNCTION();
    upcr_put_shared_strict(upc_to_upcr (dest), 0, src, len);
}

GASNETT_INLINE(__copysblk3)
void
__copysblk3 (upc_shared_ptr_t dest, upc_shared_ptr_t src, size_t len)
{
    UPCR_BEGIN_FUNCTION();
    upcr_memcpy(upc_to_upcr (dest), upc_to_upcr (src), len);
}

#endif /* !UPCR_GCCUPC_H */
