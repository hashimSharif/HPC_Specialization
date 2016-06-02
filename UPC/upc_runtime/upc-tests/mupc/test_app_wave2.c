/* _test_app_wave2.c: decompose vibrating string into pts and update its amplitude. (alt ver.)(X)

        Date created: October 18, 2002
        Date modified: October 23, 2002

        Function tested: get and put operations for double data type.

        Description:
	(Alternate version of test_wave.c. This test case reflects shared programming 
	 techniques better. However, it uses less MuPC functions. This version should
	 give better performance if performance is a concern. )

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
	UPC0			2		October 23, 2002	No	
	UPC0			2,4		November 4, 2002	Yes
	CSE0			2,4,8,12	November 16, 2002	Yes
	LION			2,4,8,16,32	November 18, 2002	No

        Bugs Found:
[See	[10/22/2002] Test case failed for n = 2. Below's the error message. Test case
 Note]     	     passes when run using UPCRTS.
		MPI_Test: process in local group is dead (rank 0, MPI_COMM_WORLD)
	[11/18/2002] On lionel, can't seem to compile.

	Notes:
	[11/04/2002] After the switch fo Compaq's MPI, this test case which used to fail
		     passes.
*/

#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>

#define SECTION 50
#define POINTS (SECTION * THREADS) 
#define TIMESTEPS 20 
#define PI 3.14159265
#define dtime (0.3)
#define c (1.0)
#define	dx (1.0)
#define tausq ((c * dtime / dx)*(c * dtime / dx))

shared [SECTION] double newwave[POINTS];
shared [SECTION] double wave[POINTS];
shared [SECTION] double oldwave[POINTS];


int main(void)
{
     	int loop, i;
     	double total = 0.0;
     	struct timeval starttime, endtime;
     	double st, et;
        double TwoPI = 2.0 * PI;

        /* Initialize wave */

     	/* Calculate initial values based on sine curve */

	upc_forall (i = 0; i < POINTS; i++; &wave[i]) {
                wave[i] = sin ( TwoPI * ( ((double)i)/(double)(POINTS - 1)));
                oldwave[i] = wave[i];
        } 
	upc_barrier;

     	/* Start timing here*/
	if (MYTHREAD == 0) {

             for(i=0; i<POINTS; i++) {
                   printf("[initial] wave[%d] = %1.5f\n", i, wave[i]);
	     }
     	     gettimeofday(&starttime, NULL);
     	     st = starttime.tv_sec + (starttime.tv_usec / 1000000.0);
	}

        if (MYTHREAD == 0 )
            newwave[0] = 0.0;

        if (MYTHREAD == THREADS - 1 )
            newwave[POINTS-1] = 0.0;

        /* Time step loop */
     	for (loop=0; loop < TIMESTEPS; loop++) {

          upc_forall(i=1; i<POINTS-1; i++ ;&wave[i]) {
         	newwave[i] = (2.0 * wave[i]) - oldwave[i] 
        	+ (tausq * (wave[i-1] - (2.0 * wave[i]) + wave[i+1]));
	  }

          upc_barrier;
	  
	  /* slide the values back in time */
	  upc_forall(i = 0; i < POINTS; i++; &wave[i]) {
               oldwave[i] = wave[i];
               wave[i] = newwave[i];
	  }
          upc_barrier;
     
	}

	if (MYTHREAD == 0) { 
     	   /* end timing here */
     	   gettimeofday(&endtime, NULL);
     	   et = endtime.tv_sec + (endtime.tv_usec / 1000000.0);

	   for(i=0; i<POINTS; i++)
                printf("[updated] wave[%d] = %1.5f\n", i, wave[i]);

	   for (i = 0; i < POINTS; i++)
		total += wave[i];

     	   printf("For verification, we sum up all the values in the array.  Sum is: ");
     	   printf("%1.12f\n", total);
     	   printf("Time taken = %3.6f\n", (et - st));
           /* DOB: TODO, add a real result correctness check */
           printf("\nSuccess: application did not crash\n");
	}
 
	return 0;
}

