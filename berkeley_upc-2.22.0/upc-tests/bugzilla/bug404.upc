#include <upc.h>
#include <stdio.h>

/* =============================================================
   This also fails if declared in external .h file
   =============================================================
*/ 

extern int A[];

/* =============================================================
   End of external .h file
   =============================================================
*/ 


#define ARRAY_SIZE 2

int A[ARRAY_SIZE];

int main(void)
{
	A[0] = 1;
	return 0;
}
