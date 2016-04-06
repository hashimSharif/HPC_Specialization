#include <stdio.h>
#include <stdlib.h>

#include "bug7b.h"

int *foo = NULL;

int main(int argc, char* argv[])
{
    int i;

    foo = (int*)malloc(10*sizeof(int));

    for (i = 0; i < 10; i++) {
        foo[i] = 10*i;
    }
    return 0;
}
