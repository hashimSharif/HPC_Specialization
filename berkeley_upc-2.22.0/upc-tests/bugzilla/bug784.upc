#include <upc.h>
#include <stdlib.h>
#include <assert.h>

typedef shared struct S_tag mySharedStruct;
typedef shared [10] struct S_tag myBlockedSharedStruct;
typedef shared int mySharedInt;

mySharedStruct *s1; /* should be a phaseless pointer to shared */
shared struct S_tag *s2; /* also a phaseless pointer to shared */

myBlockedSharedStruct *s3; /* should be a phased pointer to shared */
shared [10] struct S_tag *s4; /* also a phased pointer to shared */

mySharedInt *s5; /* should be a phaseless pointer to shared */
shared int *s6; /* also a phaseless pointer to shared */

int main() {
  shared void *x;
  s1 = NULL;
  x = s1;
  s2 = NULL;
  x = s2;
  s3 = NULL;
  x = s3;
  s4 = NULL;
  x = s4;
  s5 = NULL;
  x = s5;
  s6 = NULL;
  x = s6;
  return 0;
}
