#ifndef _BOX_H
#define _BOX_H

#ifndef _UPC_DI

#if defined(_UPCR) || defined(_UPC) 
#ifdef _UPCR
//#include "supcr.h" 
#else
//#include "supc.h"
#endif
#endif


//------------------------------------------------------------------------------------------------------------------------------
typedef struct small_box{
  struct {int i, j, k;}low;                  // global coordinates of the first (non-ghost) element of subdomain
  struct {int i, j, k;}dim;                  // dimensions of this box's core (not counting ghost zone)
  struct {int i, j, k;}dim_with_ghosts;      // dimensions of this box's core (not counting ghost zone)
  int ghosts;                                // ghost zone depth
  int pencil,plane,volume;                   // useful for offsets
  int numGrids;
  int                          bufsizes[27]; // = sizes of extracted surfaces and ghost zones (pointer to array of 27 elements)

#if !defined(_UPC) && !defined(_UPCR)
  double    *  __restrict__ surface_bufs[27]; // = extracted surface (rhs on the way down, correction on the way up)
  double    *  __restrict__ ghost_bufs[27]; // = incoming ghost zone (rhs on the way down, correction on the way up)
#endif  

#ifdef _UPCR
  double    *  __restrict__ surface_bufs[27]; // = extracted surface (rhs on the way down, correction on the way up)
  double    *  __restrict__ ghost_bufs[27]; // = incoming ghost zone (rhs on the way down, correction on the way up)
#ifdef NO_PACK
  upcr_pshared_ptr_t surface_bufs_sh[27];
  upcr_pshared_ptr_t ghost_bufs_sh[27]; 
#endif
#endif

#ifdef _UPC
  double    *  surface_bufs[27]; // = extracted surface (rhs on the way down, correction on the way up)
  double    *  ghost_bufs[27]; // = incoming ghost zone (rhs on the way down, correction on the way up)
#ifdef NO_PACK
  shared [] double * surface_bufs_sh[27];
  shared [] double * ghost_bufs_sh[27];
#endif
#endif

  double   ** __restrict__ grids;            // grids[g] = pointer to grid for component g
  uint64_t  * __restrict__ RedBlackMask;     // Red/Black Mask (i.e. 0x0000000000000000ull or 0xFFFFFFFFFFFFFFFFull) within one plane (dim_with_ghosts^2)
  uint8_t   * __restrict__ RedBlack_4BitMask;// Red/Black 4bit bit mask (i.e. 4 elements = 0000b ... 1111b ) for the whole volume
} box_type;
//------------------------------------------------------------------------------------------------------------------------------

void destroy_box(box_type *box);
int create_box(box_type *box, int numGrids, int low_i, int low_j, int low_k, int dim_i, int dim_j, int dim_k, int ghosts);
#endif
#endif
