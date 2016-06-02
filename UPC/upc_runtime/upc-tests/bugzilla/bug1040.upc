typedef struct {
  char r[100];
} RowOfBytes;

shared[10] RowOfBytes edge[THREADS];

int main() {
  shared char *x;
  int i = 0;
  //x = (shared char *)&(edge[i].r[0]); // WORKS
  x = (shared char*)edge[i].r; // FAILS
  return 0;
}
