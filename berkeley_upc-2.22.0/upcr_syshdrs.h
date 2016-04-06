/*
 * UPC Runtime sys headers we need
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_syshdrs.h $
 */

#ifndef UPCR_SYSHDRS_H
#define UPCR_SYSHDRS_H

#include <upcr_config.h>

#if defined(__PGI) && defined(GASNETT_RESTRICT) && !defined(__restrict)
  /* work around a stupid PGI Linux header bug */
  #define __restrict GASNETT_RESTRICT
#endif

#include "portable_inttypes.h"
#include "portable_platform.h"

/* 
 * common definitions/macros/etc.
 */

/* bug 1330: include all the C99 headers, to help ensure any wrapped versions are
 * all initially included directly from a user-source build environment 
 */
#if HAVE_ASSERT_H
#  include <assert.h>
#endif
#if 0 && HAVE_COMPLEX_H /* not supported or used */
#  include <complex.h>
#endif
#if HAVE_CTYPE_H
#  include <ctype.h>
#endif
#if HAVE_ERRNO_H
#  include <errno.h>
#endif
#if HAVE_FENV_H
#  include <fenv.h>
#endif
#if HAVE_FLOAT_H
#  include <float.h>
#endif
#if HAVE_INTTYPES_H
#  include <inttypes.h>
#endif
#if 0 && HAVE_ISO646_H /* alternate spellings off by default */
#  include <iso646.h>
#endif
#if HAVE_LIMITS_H
#  include <limits.h>
#endif
#if HAVE_LOCALE_H
#  include <locale.h>
#endif
#if HAVE_MATH_H
#  include <math.h>
#endif
#if 0 && HAVE_SETJMP_H /* not supported or used */
#  include <setjmp.h>
#endif
#if HAVE_SIGNAL_H
#  include <signal.h>
#endif
#if HAVE_STDARG_H
#  include <stdarg.h>
#endif
#if HAVE_STDBOOL_H
#  include <stdbool.h>
#endif
#if HAVE_STDDEF_H
#  include <stddef.h>
#endif
#if HAVE_STDINT_H
#  include <stdint.h>
#endif
#if HAVE_STDIO_H
#  include <stdio.h>
#endif
#if HAVE_STDLIB_H
#  include <stdlib.h>
#endif
#if HAVE_STRING_H
#  include <string.h>
#endif
#if 0 && HAVE_TGMATH_H /* not supported or used */
#  include <tgmath.h>
#endif
#if HAVE_TIME_H
#  include <time.h>
#endif
#if HAVE_WCHAR_H
#  include <wchar.h>
#endif
#if HAVE_WCTYPE_H \
    && !PLATFORM_COMPILER_PGI /* avoid annoying warning on PGI */
#  include <wctype.h>
#endif

/* other misc POSIX and system headers */
#if HAVE_UNISTD_H
#  include <unistd.h>
#endif
#if HAVE_FCNTL_H
#  include <fcntl.h>
#endif
#if HAVE_SYS_TYPES_H
#  include <sys/types.h>
#endif
#if HAVE_SYS_STAT_H
#  include <sys/stat.h>
#endif
#if HAVE_STRINGS_H
#  include <strings.h>
#endif
#if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
#endif
#if HAVE_MALLOC_H && !PLATFORM_OS_OPENBSD /* OpenBSD warns that malloc.h is obsolete */
#  include <malloc.h>
#endif

/* Some systems don't have INFINITY, or only have it if certain 
 * conditions are met (ex: in glibc, depends on _GNU_SOURCE, which we
 * currently define only if using pthreads).  Also ensure NAN works. */

/* note this not C99's float INFINITY, its what the translator issues 
 * to indicate double INFINITY - we should probably fix this name collision
 */
#ifndef INFINITY
  #if defined(DBL_INFINITY)
    #define INFINITY DBL_INFINITY
  #elif defined(HUGE_VAL)
    #define INFINITY HUGE_VAL
  #elif defined(HAVE_BUILTIN_HUGE_VAL) /* favor hugeval, never issues a diagnostic */
    #define INFINITY __builtin_huge_val()
  #elif defined(HAVE_BUILTIN_INF)
    #define INFINITYF __builtin_inf()
  #else
    /* used by cygwin, and possibly others */
    #define INFINITY (1.0/0.0)
  #endif
#endif

#ifndef INFINITYF
  #if defined(FLT_INFINITY)
    #define INFINITYF FLT_INFINITY
  #elif defined(HAVE_BUILTIN_HUGE_VALF)
    #define INFINITYF __builtin_huge_valf()
  #elif defined(HAVE_BUILTIN_INFF)
    #define INFINITYF __builtin_inff()
  #else
    #define INFINITYF ((float)INFINITY)
  #endif
#endif

/* provide the math.h huge vals */
#ifndef HUGE_VAL
#define HUGE_VAL INFINITY
#endif
#ifndef HUGE_VALF
#define HUGE_VALF INFINITYF
#endif

#if PLATFORM_COMPILER_XLC && !PLATFORM_OS_AIX
  /* bug 1504: on non-AIX, xlc's NAN definition is non-functional */
  #undef NAN
#endif

#ifndef NAN
  #if defined(DBL_QNAN)
    #define NAN DBL_QNAN
  #elif defined(NaN)
    #define NAN NaN
  #elif defined(HAVE_BUILTIN_NAN)
    #define NAN __builtin_nan("")
  #else
    #define NAN (0.0/0.0)
  #endif
#endif

#ifndef NANF
  #if defined(FLT_QNAN)
    #define NANF FLT_QNAN
  #elif defined(HAVE_BUILTIN_NANF)
    #define NANF __builtin_nanf("")
  #else
    #define NANF ((float)NAN)
  #endif
#endif

/* handled specially in configure.in */
#ifdef UPCRI_SUPPORT_PTHREADS
#  include <pthread.h>
#endif

/* Posix vs. BSD va_args headers */
#if !HAVE_STDARG_H && HAVE_VARARGS_H
#    include <varargs.h>
#endif

/* From Vaughn et al., Autoconf book, p59:
 * Some systems don't define errno, but it will 
 * be #defined if we're reeentrant
 */
#ifndef errno
  extern int errno;
#endif

#if HAVE_SYS_MMAN_H
#  include <sys/mman.h>
#endif

/* Honor Richard Stevens' wish (UNPv1, p 8) and prefer the foolishly 
 * deprecated bzero to the error-prone memset */
#if !HAVE_BZERO
#  define bzero(addr, len) ((void) memset(addr, 0, len))
#endif

#ifndef STDIN_FILENO
  #define STDIN_FILENO 0
#endif
#ifndef STDOUT_FILENO
  #define STDOUT_FILENO 1
#endif
#ifndef STDERR_FILENO
  #define STDERR_FILENO 2
#endif

#endif /* UPCR_SYSHDRS_H */
