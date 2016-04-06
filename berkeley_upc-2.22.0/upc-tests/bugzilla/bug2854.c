#include <stdio.h>

int y [2][3] = { {1,2},{4,5}, };

int main(void) {
  for (int i=0; i<2; ++i)
    for (int j=0; j<2; ++j)
      printf("y[%i][%i] = %d\n", i,j,y[i][j]);

  if (y[0][0] != 1) puts ("FAIL at y[0][0]");
  if (y[0][1] != 2) puts ("FAIL at y[0][1]");
  if (y[1][0] != 4) puts ("FAIL at y[1][0]");
  if (y[1][1] != 5) puts ("FAIL at y[1][1]");

  puts ("done.");
  return 0;
}
