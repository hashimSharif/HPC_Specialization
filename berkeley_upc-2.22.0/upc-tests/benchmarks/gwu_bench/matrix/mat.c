/*
UPC Matrix multiplication
Copyright (C) 2000 Sebastien Chauvin, Tarek El-Ghazawi

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
// UPC Matrix multiplication Example
// a(N, P) is multiplied by b(P, M).  Result is stored in c(N, M)
// In this example, a is distributed by rows while b is distributed by columns.
// We do use the upc_forall construct in this example

#include <upc.h>
#include <upc_relaxed.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>

#ifdef BUPC_TEST
#define N 128
#define M 128
#define P 128
#endif

#if (!defined ELEM_T) || (!defined N) || (!defined M) || (!defined P)
# error "ELEM_T, N, M and P should be defined!"
#endif

typedef ELEM_T elem_t;

#if 0
double second()
{
    double secx;
    struct tms realbuf;

    times(&realbuf);
    secx = ( realbuf.tms_stime + realbuf.tms_utime ) / (float) CLK_TCK;
    return ((double) secx);
}
#else
#include <sys/time.h>
double second() {
    struct timeval tv;
    if (gettimeofday(&tv, NULL)) {
        perror("gettimeofday");
        abort();
    }
    return tv.tv_sec + (tv.tv_usec * 0.000001);
}
#endif


#ifndef BLOCK_BUG
shared [P] elem_t a[N][P];
shared [M] elem_t c[N][M];
shared     elem_t b[P][M];
#else
/* No changes required for square matrices. */
shared     elem_t a[N][P];
shared     elem_t c[N][M];
shared     elem_t b[P][M];
#endif

#if   ((defined OPT_PTRCAST) && (defined OPT_PREFETCH)) || (defined OPT_ALL)
# define OPT_PTRCAST
# define OPT_PREFETCH
# include "mat-opt-prefetch.c"
#elif (defined OPT_PTRCAST)
# include "mat-opt-ptrcast.c"
#elif (defined OPT_PREFETCH)
# include "mat-opt-prefetch.c"
#else
# include "mat-opt-none.c"
#endif

/* vi: ts=2:ai
 */
