#include <upc.h>
#include <stdio.h>
#include <math.h>

#define TOTALSIZE 100
#define EPSILON 0.000001

shared [TOTALSIZE] double x[TOTALSIZE*THREADS];
shared [TOTALSIZE] double x_new[TOTALSIZE*THREADS];
shared [TOTALSIZE] double b[TOTALSIZE*THREADS];
shared double diff[THREADS];
shared double diffmax;

void initialize()
{
    int i;

	b[1] = 1.0; b[(TOTALSIZE*THREADS)-2] = 1.0;
}

int main()
{
	int j;
	int iter = 0;

	if(MYTHREAD == 0)
		initialize();

    upc_barrier;

    while(1)
    {
		iter++;
		diff[MYTHREAD] = 0.0;

        upc_forall( j=1; j<(TOTALSIZE*THREADS)-1; j++; &x_new[j])
        {
			x_new[j] = 0.5*( x[(j-1)]+x[(j+1)]+b[j] );
			if(diff[MYTHREAD] < x_new[j]-x[j])
				diff[MYTHREAD] = x_new[j]-x[j];
		}

		upc_barrier;

		if(MYTHREAD == 0)
		{
			diffmax = diff[0];
			for( j=1; j<THREADS; j++ )
			{
				if( diff[j] > diffmax )
			        diffmax = diff[j];
			}
		}
		upc_barrier;

		if( diffmax <= EPSILON )
			break;
		if( iter > 10000 )
			break;

		upc_forall( j=0; j<(TOTALSIZE*THREADS); j++; &x_new[j])
		{
			x[j] = x_new[j];
		}
		upc_barrier;
	}

	if( MYTHREAD == 0)
	{
		for(j=0; j<(TOTALSIZE*THREADS); j++)
		{
			printf("%f\t", x_new[j]);
		}
		printf("\n");
	}

        printf("done.\n");
	return 0;
}

