/*
MPI nqueens
Copyright (C) 2000 Ludovic Courtes, Tarek El-Ghazawi

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

/* defs.h
 *
 * Common definitions.
 */

#ifndef UINT64
# error "You must specify a 64-bit unsigned integer type `UINT64'!"
#endif


#ifndef __DEF_H__
#define __DEF_H__

/* from gen.h */

typedef UINT64 msk_t;

typedef struct
{ 
  msk_t* sol;    // Base of the array of solutions
  msk_t* psol;   // Pointer on the first free element
} sol_t;

#define B1 ((msk_t)1)
#define BASECOLMSK (B1+(B1<<17)+(B1<<34))

#define D2MASK 0x000000000ffff
#define CMASK  0x00001fffe0000
#define D1MASK 0x3fffc00000000

/* from sched.h */

#define MAX_LEVEL 3
#define MAX_N 16
#define MAX_JOBS 70000
#define MAX_NSOL 15000000

#define METH_ROUND 2
#define METH_CHUNKING 1


#endif
