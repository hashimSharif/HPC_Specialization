#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

#include <upc.h>

#define ERROR(str)                           \
    do {                                     \
	fprintf(stderr, "ERROR: %s", (str)); \
	upc_global_exit(-1);                 \
    } while (0)

int main(int argc, char **argv)
{
    void *p = NULL;
    shared void * s = NULL;

    if (p != (void *)s) 
	ERROR("p != (void *)s\n");
    
    printf("SUCCESS\n");

    return 0;
}


