static int array[10];

int main(void)
{
  int (*foo)[];
  foo = &array;
  return 0;
}
