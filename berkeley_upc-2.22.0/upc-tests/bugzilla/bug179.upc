#include <upc.h>
#define SIZE 3200

shared int *a;
shared int err[THREADS];

int main (void) {

	int i, j, error=0;
	err[MYTHREAD] = 0;
	
	a = upc_all_alloc(SIZE, sizeof(int));
	upc_forall(i = 0; i < SIZE; i++; &a[i]) {
		a[i] = (int)(i);
	}	
	return 0;
} 
