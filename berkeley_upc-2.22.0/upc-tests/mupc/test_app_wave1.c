/* _test_app_wave1.c: decompose vibrating string into points and update its amplitude. (X)

        Date created: October 18, 2002
        Date modified: October 30, 2002

        Function tested: upc_memset, upc_local_alloc, get and put operations for double.

        Description:
	- A vibrating string is decomposed into points. Each thread is responsible for
	  updating the amplitude of a number of points over time. This is not an
	  embarassingly parallel program because each thread has to send the endpoint
	  values of its portion of the string to its neighbour. 
	- To change the number of points and steps, users can change the POINTS
	  and STEPS constants. 
	- This program first divide-up the workload amongst the threads.
	- Each thread performs initialization of the portion of sine curve it's
	  responsible for.
	- Each thread performs update concurrently on its portion of curve.
	- Each thread calculates subtotal of all the points in its portion of curve.
	- Thread 0 sums up all the subtotals, the total should be close to 0.
 
        Platform Tested         No. Proc        Date Tested             Success
	UPC0			2		October 20, 2002	No	
	CSE0			2		November 16, 2002	No
	LION			2		November 18, 2002	No
	UPC0			2		November 24, 2002	Yes

        Bugs Found:
[FIXED]	[10/20/2002] Test case failed for n = 2. Below's the error message:
		     Bug reported to programmer.
		MPI process rank 0 (n0, p11751) caught a SIGFPE in MPI_Irecv.

	[11/16/2002] Test case failed for P=1K, S=100, n=2. Received the following
		     error message:
		MPI process rank 0 (n0, p9280) caught a SIGSEGV in MPI_Irecv.
	
	[11/18/2002] On lionel, compilation failed. A segmentation fault occurred.

	Note:
	[10/30/2002] If the points used is too few, or the steps is too big,
		     users would start to observe that the final total calculated
		     by thread 0 is not that close to 0 anymore. This is due
	   	     to the way the line is initialized and update. 
*/

#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>

//#define VERBOSE0 1
#define POINTS 1000
#define STEPS 100 
#define PI 3.14159265

void init_param (void);
void init_line (void);
void update (void);

shared int nsteps,                 	/* number of time steps */
           tpoints; 	     		/* total points along string */

shared int portion[THREADS];		/* Stores upper limit of thread's wave section */
shared double subtotal[THREADS];        /* Subtotal of the points on the sine wave */
shared [] double * shared values[THREADS]; 	/* values at time t */

double *oldval;   				/* values at time (t-dt) */
double *newval;   			   	/* values at time (t+dt) */
int rangeBegin, rangeEnd, por;		/* Variables used to determine upper and lower
					   bounds of the wave section a thread's
					   responsible for */ 

void init_line (void) /* Initialize points on line */
{
        int i, j, k;
        double x, fac;

        /* calculate initial values based on sine curve */
        fac = (double)(2.0 * PI);
        k = rangeBegin - 1;

        for (j = 1; j <= por; j++, k++) {
                x = (double)((double)k/(double)(tpoints - 1));
                values[MYTHREAD][j] = (double)(sin(fac * x));
        }

        for (i = 1; i <= por; i++)
                oldval[i] = values[MYTHREAD][i];
}


void do_math (int i) /* Update values using wave equation */
{
        double dtime, c, dx, tau, sqtau;

        dtime = 0.3;
        c = 1.0;
        dx = 1.0;
        tau = (c * dtime / dx);
        sqtau = tau * tau;
        newval[i] = (2.0 * values[MYTHREAD][i]) - oldval[i]
                + (sqtau * (values[MYTHREAD][i-1] - (2.0 * values[MYTHREAD][i]) + values[MYTHREAD][i+1]));
}


void update (void) /* Update the points a specified number of times */
{
        int j;

        /* update values for each point along string */
        for (j = 1; j <= por; j++) { /* Update points along line */

                /* global endpoints */
                if (((MYTHREAD == 0) && (j == 1)) || ((MYTHREAD == (THREADS-1)) && (j  == tpoints)))
                        newval[j] = 0.0;
                else
                        do_math(j);
//              printf("[th=%d] newval[%d] = %1.5f\n", MYTHREAD, j, newval[j]);
        }

        for (j = 1; j <= por; j++) {
               oldval[j] = values[MYTHREAD][j];
               values[MYTHREAD][j] = newval[j];
        }
}


int main(void)
{
     	int i, j, section;
     	double total = 0.0;
     	struct timeval starttime, endtime;
     	double st, et;

     	/* Initialize wave values */
	tpoints = POINTS;
	nsteps = STEPS;

	section = tpoints/THREADS;
	rangeBegin = MYTHREAD*section+1;
	
	if (MYTHREAD == (THREADS-1))
		rangeEnd = tpoints;
	else
		rangeEnd = (MYTHREAD+1)*section;

	subtotal[MYTHREAD] = 0.0;	
	portion[MYTHREAD] = rangeEnd - rangeBegin + 1;
	por = rangeEnd - rangeBegin + 1;  /* This variable is used to determine the
					     upper limit of the section that this
					     thread is responsible for */
#ifdef VERBOSE0
	printf("[th=%d] rangeBegin=%d, rangeEnd=%d, portion=%d, por=%d\n", 
		MYTHREAD, rangeBegin, rangeEnd, portion[MYTHREAD], por);
#endif
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
	values[MYTHREAD] = upc_alloc((por+2) * sizeof(double));
#else   
	values[MYTHREAD] = upc_local_alloc((por+2), sizeof(double));
#endif
	oldval = (double *)malloc((por+2) * sizeof(double));
	newval = (double *)malloc((por+2) * sizeof(double));

	upc_memset (values[MYTHREAD], 0, (por+2)*sizeof(double));
	memset (oldval, 0, (por+2)*sizeof(double));
	memset (newval, 0, (por+2)*sizeof(double));

     	/* start timing here*/
	if (MYTHREAD == 0) {
     		gettimeofday(&starttime, NULL);
     		st = starttime.tv_sec + (starttime.tv_usec / 1000000.0);
	}

     	init_line();
	upc_barrier;
	
/*
     	for (i = 0; i <= (rangeEnd-rangeBegin+1); i++)
        	printf("[th=%d] values[%d][%d] = %1.5f\n", 
			MYTHREAD, MYTHREAD, i, values[MYTHREAD][i]);
*/
     	
	/* Update values along the line for nstep time steps */
     	for (i = 0; i < nsteps; i++) {
		if (MYTHREAD != 0) 
			values[MYTHREAD][0] = values[MYTHREAD-1][portion[MYTHREAD-1]];	

		if (MYTHREAD != (THREADS-1)) {
			values[MYTHREAD][portion[MYTHREAD]+1] = values[MYTHREAD+1][1];
		}
        /*     	
     		for (j = 0; j <= portion[MYTHREAD]+1; j++)
        		printf("[th=%d] values[%d][%d] = %1.5f\n", 
				MYTHREAD, MYTHREAD, j, values[MYTHREAD][j]);
	*/
		update();
		upc_barrier;
	}
     
	for (i = 1; i <= portion[MYTHREAD]; i++)
        	printf("values[%d][%d] = %1.5f\n", MYTHREAD, i, values[MYTHREAD][i]);

	
     	for (i = 1; i <= por; i++)  {
        	subtotal[MYTHREAD] += values[MYTHREAD][i];
#ifdef VERBOSE0
		printf("subtotal[%d] = %1.12f\n", MYTHREAD, subtotal[MYTHREAD]);
#endif
     	}

	upc_barrier;

	if (MYTHREAD == 0) { 
		for (i = 0; i < THREADS; i++) 
			total += subtotal[i];

     		/* end timing here */
     		gettimeofday(&endtime, NULL);
     		et = endtime.tv_sec + (endtime.tv_usec / 1000000.0);
     		printf("For verification, we sum up all the values in the array.  Sum is: ");
     		printf("%1.12f\n", total);
     		printf("Time taken = %3.6f\n", (et - st));
                /* DOB: TODO, add a real result correctness check */
                printf("\nSuccess: application did not crash\n");
	}
     	
	return 0;
}
