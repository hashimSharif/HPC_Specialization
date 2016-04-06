struct X {
  int f[100];
};

shared struct X a;

int main() {
  shared [] int *p1 = a.f;
  shared [] int *p2 = (shared void *)(a.f);
  return 0;
}

