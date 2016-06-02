#include <upc.h>
#include <stdio.h>

int main(void)
{
    shared int *p = upc_global_alloc(THREADS, sizeof(int));
    upc_barrier  1; /* Must be a NAMED barrier to reproduce */
    upc_free(p); /* prevents compiler warnings that result if p is unused */
    if (!MYTHREAD) printf("PASS\n");
    return 0;
}
