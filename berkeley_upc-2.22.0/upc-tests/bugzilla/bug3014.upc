#include <upc.h>
typedef struct S { long data; } S_t;
shared S_t S2;

int main(void)
{
    int dummy; /* help prevent optimzer from discarding the test */

    dummy = upc_blocksizeof( *(&S2.data) );
    dummy += upc_blocksizeof( S2.data );

    dummy += upc_localsizeof( *(&S2.data) );
    dummy -= upc_localsizeof( S2.data );

    return dummy; /* Will be zero if compiler is conforming */
}
