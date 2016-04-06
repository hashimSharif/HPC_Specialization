#include <upc_relaxed.h>
#include <stdio.h>
#define TOTALSIZE 16

shared [TOTALSIZE] double x[TOTALSIZE*THREADS];
shared [TOTALSIZE] double x_new[TOTALSIZE*THREADS];
shared [TOTALSIZE] double b[TOTALSIZE*THREADS];

void initialize();

int main()
{
	int j;
	int iter;

	initialize();

	for( iter=0; iter<10000; iter++ )
	{
		upc_forall( j=1; j<(TOTALSIZE*THREADS)-1; j++; &x_new[j])
		{
			x_new[j] = 0.5*( x[(j-1)]+x[(j+1)]+b[j] );
		}

		upc_barrier;

		upc_forall( j=0; j<(TOTALSIZE*THREADS); j++; &x_new[j] )
		{
			x[j] = x_new[j];
		}

		upc_barrier;
	}

	if( MYTHREAD == 0)
	{
		for( j=0; j<(TOTALSIZE*THREADS); j++ )
			printf("%f\n", x_new[j]);
	}

        printf("done.\n");
	return 0;
}

void initialize()
{
	int i;

	if( MYTHREAD == 0 )
	{
		b[1] = 1.0; b[(TOTALSIZE*THREADS)-2] = 1.0;
	}
	upc_barrier;
}

