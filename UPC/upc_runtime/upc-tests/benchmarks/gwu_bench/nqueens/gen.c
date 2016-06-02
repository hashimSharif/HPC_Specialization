/*
UPC nqueens
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

#include <stdlib.h>
#include <stdio.h>
#include <upc.h>
#include <upc_strict.h>
#include "defs.h"

#ifdef DEBUG
#define DEBUG0
#define DEBUGS
#endif

int gen(msk_t i_colstk, int i_row, msk_t i_msk, int n, sol_t *result)
{ msk_t msk=i_msk;
  msk_t mskstk[MAX_N+2];
  msk_t *pmskstk=mskstk+1;

  msk_t colmsk;

  int col=0;
  msk_t colstk=i_colstk;

  int row=i_row;
  int nsols=0;

  colmsk = BASECOLMSK;

#ifdef DEBUG0
  printf("gen(%5x,%1x,",i_colstk,i_row);
  printbits(msk>>34+n,n);printf("|");
  printbits(msk>>34,n);printf("|");
  printbits(msk>>17,n);printf("|");
  printbits(msk>>0,n);
  printf(",%1x,%p)\n",n,result->psol);
#endif
  for(;;)
  { // try to place one queen
#ifdef DEBUG
    printf("(%d,%d)\n", row, col);
    printf("colmsk : ");
    printbits(colmsk>>34+n,n);printf("|");
    printbits(colmsk>>34,n);printf("|");
    printbits(colmsk>>17,n);printf("|");
    printbits(colmsk>>0,n);printf("|");
    printf("\n");
    printf("msk    : ");
    printbits(msk>>34+n,n);printf("|");
    printbits(msk>>34,n);printf("|");
    printbits(msk>>17,n);printf("|");
    printbits(msk>>0,n);printf("|");
    printf("\n");
#endif
    if (colmsk & msk) 
    { // Can not place her -> try the next one
      col++;
      if (col<n)
        colmsk<<=1;
      else
      { // Go back
        while ((row>i_row) && (col>=n))
        { col=(int)((colstk&0xf))+1;
          colstk>>=4;
          msk=*(pmskstk--);
          colmsk=BASECOLMSK<<col;
          row--;
        };
        if (col>=n)  break;
      }
    }
    else
    { // The queen can be placed here
      row++;
      *(++pmskstk)=msk;
      msk |= colmsk; // We place the queen in the masks.
      if (row==n)
      { 
        // We did it ! One solution has been found.
        // The solution is in colstk.
#ifdef DEBUGS
	printf("Solution (%d)\n",nsols);
#endif
  //      *(result->psol++)=colstk;
        nsols++;
        pmskstk--; // Restitute stacks states
        colmsk=((unsigned)-1); row--; 
        col=n;  // To force the way back
      }
      else
      { msk = (msk&CXMASK) + ((msk&D1MASK) << 1) + ((msk&D2MASK) >> 1);
        colstk<<=4;
        colstk|=col;
        col=0; colmsk=BASECOLMSK;
      }
    } 
#ifdef DEBUG
    printf("\n");
#endif
  }

#ifdef DEBUG0
  printf("                                    -> %d\n", nsols);
#endif
  return nsols;
}
