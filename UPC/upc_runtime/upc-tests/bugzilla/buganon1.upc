struct A {
  int x;
  int y;
};
shared [] struct A g[1];
struct A l[1];
int main() {
  g[0] = l[0];
  return 0;
}
