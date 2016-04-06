#ifndef Z_ORDER_H
#define Z_ORDER_H

/**********************************************************************
  Filename  : z-order.h
  Purpose   : Z-order libarary header file
  Version   : 1.0
  Copyright (C) 2001-2002 Michigan Technological University

  Permission is hereby granted to use, reproduce, prepare derivative
  works, and to redistribute to others.

                            DISCLAIMER

  Neither Michigan Technological University, nor any of its employees,
  makes any warranty express or implied, or assumes any legal liability
  or responsibility for the accuracy, completeness, or usefulness of
  any information, apparatus, product, or process disclosed, or
  represents that its use would not infringe privately owned rights.

**********************************************************************/

/*
**++
**  MODULE DESCRIPTION:
** 
**    Convert cartesian indices into Z-order indices for 2-D arrays.
** 
**  MODIFICATION HISTORY:
** 
**  08/22/03 Zhang Zhang: Initial version. (Routine even_dilate() came 
**                        from Dr. Phil Merkey).
**                        
**--
*/


/* A constant whose even bits are 1's and odd bits are 0's */
#define evenbits 0x55555555

/* A constant whose odd bits are 0's and even bits are 1's */
#define oddbits 0xaaaaaaaa

/* Increment or decrement a Z-order index */
#define oddinc(i) (i=((i-oddbits)&oddbits))
#define eveninc(j) (j=((j-evenbits)&evenbits))

/* Get the even dilated-image of an ordinary integer */
static int even_dilate(int val)
{
  int u, v, w, r;
  u = ((val & 0x0000ff00) << 8) | (val & 0x000000ff);
  v = ((  u & 0x00f000f0) << 4) | (  u & 0x000f000f);
  w = ((  v & 0x0c0c0c0c) << 2) | (  v & 0x03030303);
  r = ((  w & 0x22222222) << 1) | (  w & 0x11111111);
  return r;
}

/* Get the odd dilated-image of an ordinary integer */
#define odd_dilate(val) ((even_dilate(val)<<1))

/* A is a pointer to a 2-D Z-order array. This macro calculates
 * the displacement from A to the element A[i,j].
 * */
#define z_index(A, ii, jj) (A+(odd_dilate(ii)|even_dilate(jj)))

#endif /* Z_ORDER_H */


