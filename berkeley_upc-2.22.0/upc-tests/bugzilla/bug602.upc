#include <stdio.h>
#include <upc.h>

typedef struct S_s1 {int f1;} s1;

shared [] s1 S;

int main() {
  int sz1;
  shared [] s1 *p = &S; 
  int sz20;
  s1 pS;
  s1 *p1 = &pS;

  if (MYTHREAD == 0) { /* Can only cast S to local on thread 0 */
    sz1 = ((char *)&(p1[1])) - ((char *)&(p1[0])); 
    sz20 = ((char *)&(p[1])) - ((char *)&(p[0])); 
  
    printf("(char *)&(p[1]) - (char *)&(p[0])=%i\n", sz20); 
  
    if (sz20 != sz1) 
      printf("ERROR: ""sz20""(%i) != sz1(%i)\n", sz20, sz1); 
 
    printf("done.\n"); 
  }

  return 0;
}
