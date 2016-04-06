#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <upc.h>

extern long trouble(shared long *a, shared long *b)
{
    return *a + *b;
}
