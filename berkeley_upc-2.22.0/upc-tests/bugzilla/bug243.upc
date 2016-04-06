#include <upc.h>

struct entry64 {
  double x[8];
};

struct entry64 e64[8];

struct entry64 x;

int main() {
  
  x.x[1] = 1.0;
}
