#include <upc.h>

/* Test for implementation of bupc_assert_type().
 * We desire compilation success.
 */

int main(void)
{
  int foo;

  /* Bonus compile-time check */
  bupc_assert_type(foo, int);

  return 0;
}
