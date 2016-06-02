union foo { int i; float f; };
int main(void)
{
  union foo bar, *foop = &bar;
  float baz;
  foop->f = 1.5;
  baz = foop->f;
  return 0;
}
