shared struct { void *addr; } foo;
int main(void) {
  int i;
  foo.addr = &i;
  return 0;
}
