#include <stdio.h>
#include <upc.h>

shared [] int *x1;
shared [] int *x2 = NULL;
shared int *x3;
shared int *x4 = NULL;
shared [4] int *x5;
shared [4] int *x6 = NULL;
int *x7;
int *x8 = NULL;

shared [] int * shared sx1;
shared [] int * shared sx2 = NULL;
shared int * shared sx3;
shared int * shared sx4 = NULL;
shared [4] int * shared sx5;
shared [4] int * shared sx6 = NULL;
int * shared sx7;
int * shared sx8 = NULL;

int main() {
#define CHECK(var) do { \
  if (var != NULL) printf("ERROR in init at %i\n", __LINE__); \
  var = NULL; \
  if (var != NULL) printf("ERROR in set at %i\n", __LINE__); \
} while (0)
 
CHECK(x1);
CHECK(x2);
CHECK(x3);
CHECK(x4);
CHECK(x5);
CHECK(x6);
CHECK(x7);
CHECK(x8);

CHECK(sx1);
CHECK(sx2);
CHECK(sx3);
CHECK(sx4);
CHECK(sx5);
CHECK(sx6);
CHECK(sx7);
CHECK(sx8);
printf("done.\n");
return 0;
}
