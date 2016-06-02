#include "upc.h"
#include <inttypes.h>
#include <stdio.h>

shared int foo;  // not thread-local: uses a global upcr_pshared_ptr_t
shared int *p;   // thread local: uses a TLD_DEFINE/TLD_ADDR to define/ref
shared int *shared sp; // not thread local: uses a upcr_pshared_ptr_t 
shared [2] int *shared sp2; // not thread local: uses a upcr_shared_ptr_t 

int main() 
{
    printf("T%d: foo=%d\n", MYTHREAD, foo);
    printf("T%d: p=0x%08x\n", MYTHREAD, (int)(uintptr_t)p);
    printf("T%d: sp=0x%08x\n", MYTHREAD, (int)(uintptr_t)sp);
    printf("T%d: sp2=0x%08x\n", MYTHREAD, (int)(uintptr_t)sp2);

    return 0;
}
