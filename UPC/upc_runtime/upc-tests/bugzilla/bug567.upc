#include <upc.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct {
  shared void *sp;
  void *p;
  int x;
} S;
shared int sh[100*THREADS];
int a;
int main() {
 static int b;
 int c;

 S list[4] = {
    { &(sh[0]), &a, 4 },
    { &(sh[10]), &b },
    { NULL, &c, 10 }
 };

 if (list[0].sp != &(sh[0])) printf("ERROR at %i\n",__LINE__);
 if (list[0].p != &a) printf("ERROR at %i\n",__LINE__);
 if (list[0].x != 4) printf("ERROR at %i\n",__LINE__);

 if (list[1].sp != &(sh[10])) printf("ERROR at %i\n",__LINE__);
 if (list[1].p != &b) printf("ERROR at %i\n",__LINE__);
 if (list[1].x != 0) printf("ERROR at %i\n",__LINE__);

 if (list[2].sp != NULL) printf("ERROR at %i\n",__LINE__);
 if (list[2].p != &c) printf("ERROR at %i\n",__LINE__);
 if (list[2].x != 10) printf("ERROR at %i\n",__LINE__);

 if (list[3].sp != NULL) printf("ERROR at %i\n",__LINE__);
 if (list[3].p != NULL) printf("ERROR at %i\n",__LINE__);
 if (list[3].x != 0) printf("ERROR at %i\n",__LINE__);

 printf("done.\n");
 return 0;
}
