struct X {
  int f[100];
};

shared struct X arr[THREADS];

int main() {
  shared [] int *p1 = arr[0].f;
  shared [] int *p2 = (shared void *)(arr[0].f);
  return 0;
}

