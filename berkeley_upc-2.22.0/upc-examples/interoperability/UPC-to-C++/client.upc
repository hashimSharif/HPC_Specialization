#include <stdio.h>

#include "cpplib.h"
#include "upc.h"

int main(int argc, char **argv)
{
    int result;
    int err = 0;

    if ( (result = ask_Adder()) != 5) {
	fprintf(stderr, "FAILED: got %d instead of 5\n", result);
	err = 1;
    }
    if ( (result = ask_BadAdder(2, 2)) != 3) {
	fprintf(stderr, "FAILED: got %d instead of 3\n", result);
	err = 1;
    }
    if (err)
	return -1;
    else
	printf("SUCCESS: C++ calls returned correct values\n");
    return 0;
}


