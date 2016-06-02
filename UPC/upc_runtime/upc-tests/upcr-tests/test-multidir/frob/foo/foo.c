#include <upc.h> // for upc_global_exit()
#include <unistd.h> // for sleep()
#include <string.h>
// this must be found in the same directory as this file
#include "foo_private.h"

#include "../../boo/bar/bar.h"

#include "shared.h"

typedef struct bar {
    int frobbitzim[3];
    char * str;
} Bar;

int main()
{
    int x = MAGIC_NUM;
    char p[100];
    strcpy(p, "skiddoo");
    THINGIE = { {1,2,3}, p };
    int result;

    result = foo(x, bell.frobbitzim[2]);

    bar(private_int, globalint);

    if (result != 6) {
	fprintf(stderr, "ERROR: result should have been 6, was %d\n", 
		result);
	fflush(stderr);
	sleep(2);
	upc_global_exit(-1);
    }
    printf("done.\n");
    return 0;
}


int foo(int a, int b)
{
    return a + b;
}


