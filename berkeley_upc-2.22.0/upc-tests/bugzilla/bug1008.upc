#include <upc.h>
typedef struct inner {
  double a;
  double b;
} INNER;
  
typedef struct T {
  double a;
  double b;
  double c;
  INNER d;
} BADT;
      
shared [] BADT g[1];
shared [] BADT *pg;
BADT l[1],ll;
                                                                                 
               
void f(shared [] BADT *pg) {
  /* INNER i = ll.d; */
   g[0] = l[0];               
}

