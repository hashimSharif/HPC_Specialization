#include <stdio.h>
#define TOTALSIZE 16

double x_new[TOTALSIZE];
double x[TOTALSIZE];
double b[TOTALSIZE];

void initialize();

int main()
{
	int  j;
	
	initialize();

	for( j=1; j< TOTALSIZE-1; j++ )
	{
		x_new[j] = 0.5*( x[(j-1)]+x[(j+1)]+b[j] );
	}

	for( j=0; j< TOTALSIZE; j++ )
	{
		printf("%f\n", x_new[j]);
	}
		
        printf("done.\n");
	return 0;
}

void initialize()
{
	int i;

	b[1] = 1.0; b[TOTALSIZE-2] = 1.0;
}

