struct s1 { int i; }; struct s2 { struct s1 xx; };
int main(void)
{
  struct s1 foo;
  struct s2 bar;
  bar.xx.i = 123;
  foo = bar.xx;
  return 0;
}
