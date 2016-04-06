union foo { int i; float f; };
int main(void)
{
  union foo bar;
  float baz;
  bar.f = 1.5;
  baz = bar.f;
  return 0;
}

