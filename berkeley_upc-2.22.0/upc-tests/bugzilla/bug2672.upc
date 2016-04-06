struct foo {
  char No;
  int  a[20];
};

shared [10] struct foo f;

int main(void)
{
  shared [] char * x = &(f.No);
  return (x == 0); // Keep -opt from discarding the problematic code
}
