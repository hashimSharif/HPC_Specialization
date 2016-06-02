#include <upc.h>
#include <stdio.h>


/* Arrays */
int shared si;
int shared [10] si10;                           /* Meaningless blocked scalar ! */
int shared sv10 [10];
int shared [10] sv1020 [20];
int shared svsquare [20][30];
int shared [10] svsquare2 [20][30];
int shared []   svsquare4 [20][30];


typedef int shared[10] s10int;
s10int s10i30 [30] ;
s10int s10i2030 [20][30];


/* We also need some involving THREADS dimensions, but we need to compile the code
 *  * both with and without -fthreads to achieve that, so may need a different test
 *   */


/* Pointers */
int shared * lsp;                               /* Local pointer to shared int */
int shared [10] * lsp1;                         /* Local pointer to blocked ten shared int */


int * shared slp;                               /* Shared point to local int */
int * shared [10] slp1;


int shared * shared sps;                        /* Shared pointer to shared int */
int shared [10] * shared sps1;
int shared * shared [20] sps2;
int shared [10] * shared [20] sps3;


/* CMD: dset BARRIER_STOP_ALL none */


int main (int argc, char ** argv)
{
  int i;


  /* Initialise all our variables just in THREAD 0 */
  if (MYTHREAD == 0)
    {
      si = 1;
      si10 = 10;


      for (i=0; i<10; i++)
      /* STOP: */
        sv10[i] = i;


      for (i=0; i<20; i++)
        {
          int j;


          sv1020[i] = i;
          for (j=0; j<30; j++)
            {
              svsquare [i][j] = i*100+j;
              svsquare2[i][j] = -i*100+j;
              svsquare4[i][j] = -i*100+j;
            }
        }
    }


  /* Set up the local pointers */
  lsp  = &si;
  lsp1 = &si10;


  /* And the shared pointers */
  if (MYTHREAD == 0)
    {
      slp = &i;                                 /* Is this legal ? */
      slp1= &i;
      sps = &si;
      sps1= &sv1020[0];
//printf("KD: 0x%x\n", sps1);
//DOB:
#ifdef __BERKELEY_UPC__
char tmp[ BUPC_DUMP_MIN_LENGTH];
bupc_dump_shared(sps1, tmp,  BUPC_DUMP_MIN_LENGTH);
printf("%s\n",tmp);
#endif
      sps1++;
    }
  /* BARRIER: */
  i = 0;
printf("done.\n");
}

