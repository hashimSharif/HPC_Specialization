#include <upc.h>
#include "bug1926a.uph" // defines mystruct1 and foo1()
#include "bug1926a.h"   // defines mystruct2 and foo2()

typedef struct mystruct1 MYSTRUCT1;
typedef struct mystruct2 MYSTRUCT2;

MYSTRUCT1 p1;
MYSTRUCT2 p2;

shared MYSTRUCT1 s1;
shared MYSTRUCT2 s2;
    
int main(int argc, char **argv)
{
    MYSTRUCT1 a1;
    MYSTRUCT2 a2;
    
    foo1(&p1);
    foo1(&a1);
    if (upc_threadof(&s1)) foo1((MYSTRUCT1 *)&s1);

    foo2(&p2);
    foo2(&a2);
    if (upc_threadof(&s2)) foo2((MYSTRUCT2 *)&s2);

    return 0;
}
