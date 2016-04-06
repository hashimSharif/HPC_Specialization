/* Test case for BUPC bug 2899

   Bug occurs when generating code for Y, but only if decl for X seen first.
   + Removing the decl for X resolves the bug.
   + Swapping order of decls for X and Y also resolves the bug.
 */

#include <upc.h>

shared [*] int X[10*THREADS];
shared int Y[THREADS];

int foo(int i) { return Y[i]; }
