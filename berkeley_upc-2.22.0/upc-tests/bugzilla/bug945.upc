struct s1 { float aaa[4]; }; struct s2 { struct s1 bbb[8]; };
int main(void)
{
  struct s2 foo, *p;
  p = &foo;
  p->bbb[1].aaa[2] = 3.0;
  return 0;
}

