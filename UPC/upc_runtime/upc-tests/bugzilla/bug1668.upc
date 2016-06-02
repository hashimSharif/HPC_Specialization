shared int a;
int main() {
  shared void *ptr = &a;
  int offset = 4;
  ptr = ptr + offset;
}

