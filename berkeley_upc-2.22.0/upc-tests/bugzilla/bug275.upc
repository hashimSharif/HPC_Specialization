#include <stdio.h>
#include <stdlib.h>

typedef struct point_name{
  double x;
  double y;
  int gid;
} point;

/* A convex hull.  Length and list of points */
typedef struct lhullinfo_name {
  int n;
  point *points;
} lhullinfo;

int main(int argc,char **argv)
{
  int i;
  lhullinfo hull;
  hull.n = 0; hull.points = NULL;

  for(i=0;i < hull.n-1;i++) {
    printf("%f %f\n%f %f\n\n",hull.points[i].x,hull.points[i].y,
                                      hull.points[i+1].x,hull.points[i+1].y);

  }
  return 0;
}
