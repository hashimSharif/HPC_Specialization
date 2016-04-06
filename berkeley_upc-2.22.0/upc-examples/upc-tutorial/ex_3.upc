#include <upc_relaxed.h>
#include <stdio.h>
#define TOTALSIZE 16

shared double x[TOTALSIZE*THREADS];
shared double x_new[TOTALSIZE*THREADS];
shared double b[TOTALSIZE*THREADS];

void initialize();

int main()
{
	int j;

	initialize();

	for( j=1; j<(TOTALSIZE*THREADS)-1; j++ )
	{
		if( j%THREADS == MYTHREAD)
		{
			x_new[j] = 0.5*( x[(j-1)]+x[(j+1)]+b[j] );
       	}
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

