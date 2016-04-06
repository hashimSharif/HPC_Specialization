extern struct {
  unsigned F1:8;
  unsigned F2:8;
} A[1];

int main(void) {
  return A[0].F2;
}
