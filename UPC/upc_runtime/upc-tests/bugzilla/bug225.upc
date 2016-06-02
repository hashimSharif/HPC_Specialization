#include <upc_strict.h>
#include <stdio.h>
#include <stdlib.h>

#define TIMEIT(desc, code)                        \
    {                                                    \
    for(i=0;i<10;i++) {                                  \
      code;                                              \
    }                                             \
    }

int doit(int N) 
{
    int i;
    shared [2] int *s1=0, *s2=0, *s3=0, *s4=0;


    TIMEIT("phased batch o' stuf", s3 = s2++ + i; s1 += i);

    return 0;	
}
