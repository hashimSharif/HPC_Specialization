#include <upc_relaxed.h>
#include <stdio.h>

#define N 20

typedef struct{
       int X, Y;
}Point;

shared[N/THREADS] Point P[2][N];

int cmp(Point p, Point q){
   return (p.X < q.X || p.X == q.X) && p.Y < q.Y ? -1 :
       p.X == q.X && p.Y == q.Y ? 0 :
       1;
}

int main()
{
   Point p, q;
   if(MYTHREAD == 0){
       printf("%d", cmp(P[0][0], P[0][0]));
   }
   return 0;
}
