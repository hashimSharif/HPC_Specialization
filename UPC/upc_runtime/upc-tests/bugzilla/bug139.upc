#include <stdio.h>

#include <upc.h>

#define SIZE (THREADS * 5)

shared char		CharData[SIZE];
shared short		ShortData[SIZE];

int main (void) {
	
	int errorNum=0;	
	char c = 'A';
	short s = 1;
	int i;

	upc_barrier;
	
	/* Initialize the 6 shared arrays */
	upc_forall(i = 0; i < SIZE; i++; &CharData[i]) {
		CharData[i] = c;
		ShortData[i] = s + i;
	}
	
	upc_barrier;

	/* Update the values of the 4 shared arrays */
	upc_forall(i = 0; i < SIZE; i++; &CharData[i]) {
		CharData[i] = CharData[i] + 1;	
		ShortData[i] = ShortData[i] + 1;
	} 

	upc_barrier;


	if (MYTHREAD == 0) {
	
		for (i = 0; i < SIZE; i++) {
			if (CharData[i] != (c + 1)) {
				printf("ERROR: CharData[%i]=%i, should be %i\n",i,(int)CharData[i],(int)(c+1));
			}

			if (ShortData[i] != (s + i + 1)) {
				printf("ERROR: ShortData[%i]=%i, should be %i\n",i,(int)ShortData[i],(int)(s+i+1));
			}

		}
	}
 printf("done.\n");
 return 0;

}

