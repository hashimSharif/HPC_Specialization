#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <upc.h>

int main(int argc, char **argv)
{
    if (__UPC_VERSION__ == 200310L) {
	printf("Success\n");
    } else {
	fprintf(stderr, "__UPC_VERSION__ not defined correctly\n");
	exit(-1);
    }

    return 0;
}


