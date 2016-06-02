#include <upc.h>
#include <stdlib.h>

int foo(int count) {
	int sum = 0;

    #ifdef WORKAROUND1
	int outer;
	for(outer = 0; outer < count; ++outer)
    #else
	for(int outer = 0; outer < count; ++outer)
    #endif
        {
		int temporary = rand();
	    #ifdef WORKAROUND2
		for (int inner = 0; inner < THREADS; inner++)
	    #else
		int inner;
		for (inner = 0; inner < THREADS; inner++)
	    #endif
			{ /* empty loop body */ }
	        sum += temporary;
	}

	return sum;
}
