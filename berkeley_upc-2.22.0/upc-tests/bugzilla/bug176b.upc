#include <upc.h>

/* Test for implementation of upc_assert_type().
 * We desire compilation failure.
 */
int main(void)
{
  int foo;

  upc_assert_type(foo, int);

  return 0;
}
