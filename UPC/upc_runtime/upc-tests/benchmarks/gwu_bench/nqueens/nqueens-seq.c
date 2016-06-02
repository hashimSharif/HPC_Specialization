/* nqueens-seq.c
 *
 * Sequential version of the N-Queens program
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <strings.h>
#include "defs.h"


#define MEASURE_LOOP 1.0

int n;	/* Chessboard edge size */

int gen(msk_t i_colstk, int i_row, msk_t i_msk, int n)
{ msk_t msk=i_msk;
  msk_t mskstk[MAX_N+2];
  msk_t *pmskstk=mskstk+1;

  msk_t colmsk;

  int col=0;
  msk_t colstk=i_colstk;

  int row=i_row;
  int nsols=0;

  colmsk = BASECOLMSK;

  for(;;)
  { // try to place one queen
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
  }

  return nsols;
}

int main(int argc, char** argv)
{ int i;
  int nsols;

  clock_t clk;

  setbuf(stdout,NULL);

  fprintf(stderr,"Starting test...\n");

  if (argc!=2)
  { fprintf(stderr,"Syntax:\n%s n\n", argv[0]);
  }
  n=atoi(argv[1]);
  if ((n<=0) || (n>16))
  { fprintf(stderr,"0<n<17\n");
  }

  clock();

  for(i=0;i<MEASURE_LOOP;i++)
  { nsols = gen(0,0,0,n);
  }

  { clk = clock();

    fprintf(stderr, "Solutions : %d\n", nsols);
    printf("%f\n", ((double)clk)/((double)(CLOCKS_PER_SEC*MEASURE_LOOP)));
  }
  return 0;
}
