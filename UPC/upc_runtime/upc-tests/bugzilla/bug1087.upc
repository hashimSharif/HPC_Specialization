#include <stdio.h>
void foo(int firstcall) {
 { static int x; { static int x;
   if (firstcall) x = 5;
   else if (x != 5) printf("ERROR x=%i\n",x);
 } if (firstcall) x = 10; else if (x != 10) printf("ERROR x=%i\n",x); }
}
int main() {
 foo(1);
 foo(0);
 printf("done.\n");
 return 0;
}
