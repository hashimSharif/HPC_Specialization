#include "upc.h"
#include <stdio.h>

typedef struct {
  double x;
  double y;
  int gid;
} point;

point getmedian(point *localpoints,int n,int m)
{
  point x;
  x.x = 0;
  x.y = 0;
  x.gid = 0;
  return(x);
}

int main() {

  point * l=NULL, r1, r2;
  int i=0;
  r1 = getmedian(l, i, i);
  r2 = getmedian(l, i, i);
 
}


