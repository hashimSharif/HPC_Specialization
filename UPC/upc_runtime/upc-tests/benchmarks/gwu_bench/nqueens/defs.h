/* defs.h
 *
 * Common definitions.
 */


#ifndef __DEF_H__
#define __DEF_H__

#include <inttypes.h>
#define UINT64 uint64_t

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
#define CXMASK 0x00001fffe0000
#define D1MASK 0x3fffc00000000

extern int gen(msk_t colstk, int i_row, msk_t i_msk, int n,sol_t * result);

/* from sched.h */

extern int sched(int nbQueens, int level, int method);

#define MAX_LEVEL 3
#define MAX_N 16
#define MAX_JOBS 70000
#define MAX_NSOL 15000000

#define METH_ROUND 2
#define METH_CHUNKING 1


#endif
