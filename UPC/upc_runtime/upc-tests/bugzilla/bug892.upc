
void inv_J(double ds[][4])
{
 ds[1][0] = -1;
}

void foo(double param[29][41])
{
  param[0][0] = 1;
  param[0][1] = 2;
  param[1][0] = 3;
}

static double array[29][41];

int main(void)
{
  foo(array);
  return 0;
}
