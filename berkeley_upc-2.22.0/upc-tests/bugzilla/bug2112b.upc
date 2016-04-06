extern struct {
  unsigned F1:4;
  unsigned F2:4;
} A[1];

int main(void) {
  return A[0].F2;
}
