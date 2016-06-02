#include <assert.h>

struct mat {
  double x[64][64];
};

struct mat a,b;

int main() {
  int i = 10, j = 20;
  a.x[i][j] = 347.5;
  b.x[i][j] = 347.5;
  assert(a.x[i][j] == 347.5);
  assert(a.x[i][j] == b.x[i][j]);
}
