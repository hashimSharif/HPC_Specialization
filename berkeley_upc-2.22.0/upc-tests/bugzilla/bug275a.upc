#include <upc.h>
#include <stdio.h>

typedef struct point_name{
  double x;
  double y;
  int gid;
} point;

typedef struct {
  int n;
  shared [] point *points;
} hullinfo;

shared [] hullinfo *hull;

int main () {
  
  int i = 0;
  printf("%f %f\n%f %f\n\n",hull->points[i].x,hull->points[i].y,
	  hull->points[i+1].x,hull->points[i+1].y);
}
