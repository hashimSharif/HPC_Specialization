/*  From Bug 2061, reported by Gary Funck:

Given

shared int * shared ptr;

The expression (ptr + 1) is being evaluated with the same type as ptr. Almost 
right.  The problem is that 'ptr' lives in shared memory, therefore its type 
has the "shared" qualifier asserted.  This could lead to incorrect code, if 
the compiler targets the result to a temporary, which must live in shared 
memory, but should not.

The fix is to drop the "shared" qualifier when evalutating shared pointer sums.

This program should fail with an error diagnostic if the bug is fixed:

t.upc: In function 'main':
t.upc:6: error: upc_blocksizeof applied to a non-shared type

If it passes, then the bug is present.

*/


#include <upc.h>

shared [5] int * shared ptr;
int main()
{
  int k = upc_blocksizeof (ptr + 1);
  return 0;
}
