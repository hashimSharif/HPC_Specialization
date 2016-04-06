#include <upc.h>

shared int foo;

int main()
{
    int *p = (int *)&foo; 

    return 0;
}

