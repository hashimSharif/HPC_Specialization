struct A {
  int x;
  int y;
};
struct S {
  struct A a;
} src;
int main() {
  struct A dest = src.a;
  return 0;
}
