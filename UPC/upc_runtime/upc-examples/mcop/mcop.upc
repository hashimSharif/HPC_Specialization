/*
  MCOP classic matrix chain ordering problem
  written in UPC

  by Mike Merrill, mhmerrill@mac.com

  shared matrix layout is distributed cyclic by columns
  so:
    iCost[r][c] is on thread c%THREADS

  in the algorithm iCost[i][j] a function of entries in row i and
column j

  basic approach:
    loop over diagonals call them t=0 to n-1
        for the (i,j)th subproblem i = j-t on the diagonal
        compute min of the recurrance below
        barrier between diagonals

    cost is the recurrance:
    iCost[i][j] = min{k=i+1 to j} of (iCost[i][k-1] + iCost[k][j]
                                      + (iDims[i] * iDims[k] *
iDims[j+1]))

    each sucsessive diagonal represents t+1 long sub-problems
    the first diagonal has 1 long sub-problems because they are
       the i==j entries these all cost 0
    the second diagonal has 2 long sub-problems
    the third diagonal has 3 long sub-problems
    ... until you get to the last diagonal which has one entry :-)

    The innermost loop might be a little confusing because
    it is unrolled by a factor of four. This loop can probably be
    rolled up and vectorized (I think)

    Anyway it just more fodder for people to look at...

    Mike.

*/

/* make UPC default to relaxed references */
#include <upc_relaxed.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <limits.h>

/* Macros for timing */
struct tms t;
#define WSEC() (times(&t) / (double)sysconf(_SC_CLK_TCK))
#define CPUSEC() (clock() / (double)CLOCKS_PER_SEC)

/* define max problem size must be <= local size * THREADS */
/* need to use compile time THREADS environment for UPC */
#define PSIZE (4096)

/* dimensions of matrices */
int iDims[PSIZE+1];
shared int shared_iDims[PSIZE+1];

/* distributed cost matrix */
/* last dimension of iCost and iBest are distributed cyclicly across
threads */
shared int iCost[PSIZE][PSIZE];
shared int iBest[PSIZE][PSIZE];

void print(int iPsize)
{
    int i, j;

    /* all threads print out the dimensions */
    printf("iDims\n");
    for(i = 0; i < iPsize+1; i++)
        printf("%10d",iDims[i]);
    printf("\n");

    /* print out the cost table */
    printf("iCost\n");
    for(i = 0; i < iPsize; i++)
    {
        for(j = 0; j < iPsize; j++)
        {
            printf("%10d",iCost[i][j]);
        }
        printf("\n");
    }

    /* print out the best table */
    printf("iBest\n");
    for(i = 0; i < iPsize; i++)
    {
        for(j = 0; j < iPsize; j++)
        {
            printf("%10d",iBest[i][j]);
        }
        printf("\n");
    }
}

void order(int i, int j)
{
    if (i == j)
    {
        printf("%c", (char) ('A'+i));
    }
    else
    {
        printf("(");
        order(i, iBest[i][j]-1);
        order(iBest[i][j], j);
        printf(")");
    }
}

void genData(int iPsize)
{
    int i;

    /* get arround the fact that rand() is not thread safe */
    /* and the berkeley pthread based upc does not handle correctly */
    /* have thread 0 gen and store all dims in shared array */
    if(MYTHREAD == 0)
        for(i = 0; i < iPsize+1; i++)
            shared_iDims[i] = (rand() % 29) + 5;
    upc_barrier 1000;

    /* read dims into a loacal array before use */
    for(i = 0; i < iPsize+1; i++)
        iDims[i] = shared_iDims[i];
    upc_barrier 1001;

}

int main(int argc, char *argv[])
{
    int iPsize = 26; /* 'A' - 'Z' */
    int i,j,k,t;
    int lcol, rcol, rproc;
    int iTemp1, iTemp;
    int iSub1Cost, iSub2Cost, iOldCost, iOldBest;
    int iSub1Cost1, iSub1Cost2, iSub1Cost3;
    float time1, time2;
    int *lpCost_ij, *lpCost_kj, *lpBest_ij;

    if(argc >= 2)
    {
        iPsize = atoi(argv[1]);
    }

    if((iPsize > PSIZE) || (iPsize < 2))
    {
        printf("error: input problem size out of bounds: %d\n", iPsize);
        exit(1);
    }

    if(MYTHREAD == 0)
    {
        printf("Number of threads  = %d\n", THREADS);
        printf("Max Problem Size   = %d\n", PSIZE);
        printf("Input problem size = %d\n", iPsize);
    }

    /* generate input data for problem */
    genData(iPsize);

    /* initialize cost table */
    for(j = MYTHREAD; j < iPsize; j += THREADS)
    {
        /* fill with INT_MAX down column to diagonal */
        for(i = 0; i < j; i++)
            iCost[i][j] = INT_MAX;

        /* fill diagonal with 0 */
        iCost[j][j] = 0;

        /* fill rest with -1 */
        for(i = j+1; i < iPsize; i++)
            iCost[i][j] = -1;
    }

    /* wait until intialization is done on all threads */
    upc_barrier 1;

    time1 = CPUSEC();

    /* loop over diagonals */
    /* each sucsessive diagonal represents n long sub-problems */
    /* the first diagonal has 1 long sub-problems these all cost 0 */
    /* the second diagonal has 2 long sub-problems */
    /* the third diagonal has 3 long sub-problems */
    /* ... until you get to the last one which has one entry :-) */
    /* don't need to look at diag t=0 because these all cost 0 */
    for(t = 1; t < iPsize; t++)
    {
        /* start at MYTHREAD */
        for(j = MYTHREAD; j < iPsize; j += THREADS)
        {
            /* does this column participate in the diagonal */
            if(j >= t)
            {
                /* row for this diagonal */
                i = j - t;

                /* local fetch */
                lpCost_ij = (int *) &(iCost[i][j]);
                iOldCost = (*lpCost_ij);

                /* init best loc */
                iOldBest = -1;

                /* UNROLLED by 4... pick up all pairs of sub problems */
                for(k=i+1; k <= j-4; k += 4)
                {
                    /* remote pre-fetch */
                    iSub1Cost = iCost[i][k-1];
                    /* remote pre-fetch */
                    iSub1Cost1 = iCost[i][k];
                    /* remote pre-fetch */
                    iSub1Cost2 = iCost[i][k+1];
                    /* remote pre-fetch */
                    iSub1Cost3 = iCost[i][k+2];

                    /* local fetch */
                    lpCost_kj = (int *) &(iCost[k][j]);
                    iSub2Cost = (*lpCost_kj);

                    /* compute cost of these pair of sub problems */
                    iTemp1 = iDims[i] * iDims[k] * iDims[j+1];
                    iTemp = iSub1Cost + iSub2Cost + iTemp1;

                    /* check if less than old cost */
                    if(iTemp < iOldCost)
                    {
                        /* save values might be optimal */
                        iOldCost = iTemp;
                        iOldBest = k;
                    }

                    /* local fetch */
                    lpCost_kj = (int *) &(iCost[k+1][j]);
                    iSub2Cost = (*lpCost_kj);

                    /* compute cost of these pair of sub problems */
                    iTemp1 = iDims[i] * iDims[k+1] * iDims[j+1];
                    iTemp = iSub1Cost1 + iSub2Cost + iTemp1;

                    /* check if less than old cost */
                    if(iTemp < iOldCost)
                    {
                        /* save values might be optimal */
                        iOldCost = iTemp;
                        iOldBest = k+1;
                    }

                    /* local fetch */
                    lpCost_kj = (int *) &(iCost[k+2][j]);
                    iSub2Cost = (*lpCost_kj);

                    /* compute cost of these pair of sub problems */
                    iTemp1 = iDims[i] * iDims[k+2] * iDims[j+1];
                    iTemp = iSub1Cost2 + iSub2Cost + iTemp1;

                    /* check if less than old cost */
                    if(iTemp < iOldCost)
                    {
                        /* save values might be optimal */
                        iOldCost = iTemp;
                        iOldBest = k+2;
                    }

                    /* local fetch */
                    lpCost_kj = (int *) &(iCost[k+3][j]);
                    iSub2Cost = (*lpCost_kj);

                    /* compute cost of these pair of sub problems */
                    iTemp1 = iDims[i] * iDims[k+3] * iDims[j+1];
                    iTemp = iSub1Cost + iSub2Cost + iTemp1;

                    /* check if less than old cost */
                    if(iTemp < iOldCost)
                    {
                        /* save values might be optimal */
                        iOldCost = iTemp;
                        iOldBest = k+3;
                    }
                }
                /* pick up rest */
                for(; k <= j; k++)
                {
                    /* remote pre-fetch */
                    iSub1Cost = iCost[i][k-1];

                    /* local fetch */
                    lpCost_kj = (int *) &(iCost[k][j]);
                    iSub2Cost = (*lpCost_kj);

                    /* compute cost of these pair of sub problems */
                    iTemp1 = iDims[i] * iDims[k] * iDims[j+1];
                    iTemp = iSub1Cost + iSub2Cost + iTemp1;

                    /* check if less than old cost */
                    if(iTemp < iOldCost)
                    {
                        /* save values might be optimal */
                        iOldCost = iTemp;
                        iOldBest = k;
                    }
                }

                /* local stores */
                *lpCost_ij = iOldCost;
                lpBest_ij = (int *) &(iBest[i][j]);
                *lpBest_ij = iOldBest;

            }
        }

        /* make everyone wait until diagonal is done */
        upc_barrier 2;
    }
    time2 = CPUSEC();

    if(MYTHREAD == 0)
    {
        if(iPsize <= 26)
        {
            print(iPsize);
            order(0, iPsize-1);
        }

        printf("\n");
        printf("best cost = %d\n", iCost[0][iPsize-1]);
        printf("%f seconds\n", (time2-time1));
    }

    if(iPsize <= 10)
    {
        for(i=0;i<THREADS;i++)
        {
            if(MYTHREAD==i)
                print(iPsize);
            upc_barrier 3;
        }
    }

   printf("done.\n");

}

/* emacs stuff */
/** Local Variables: **/
/** mode: c **/
/** End: **/

