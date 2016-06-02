#include <upc_relaxed.h>
#include <stdio.h>

#define N (2*THREADS)
#define MODE_ELLIPSE 0
#define MODE_RECTANGLE 1

typedef struct {
    int X, Y;
} Point;

typedef struct {
    shared[] Point * pts;
    int leftest;
    int end;
} Hull;

void hullcpy(shared Hull* dst, shared Hull* src){
    int i;
    dst->pts = (shared[] Point *)upc_alloc(src->end*sizeof(Point));

    printf("t%d:hullcpy thread of dst->pts=%d\n", MYTHREAD, (int)upc_threadof(dst->pts));
    upc_memcpy(dst->pts, src->pts, src->end*sizeof(Point));
    dst->end = src->end;
    dst->leftest = src->leftest;
}

int prod(Point p1, Point q1, Point p2, Point q2){
    return (q1.X - p1.X)*(q2.Y - p2.Y) -  (q1.Y - p1.Y)*(q2.X - p2.X);
}


/*********************************** MAIN ***********************************/
int main(){

    if(MYTHREAD == 0){
        Hull H;
        H.end = 7;
        H.leftest = 4;
        H.pts = (shared[] Point *)upc_alloc(H.end*sizeof(Point));

        H.pts[0].X = 9; H.pts[0].Y = 4;
//      H.pts[1].X = 9; H.pts[1].Y = 6;
        H.pts[2].X = 6; H.pts[2].Y = 8;
        H.pts[3].X = 5; H.pts[3].Y = 7;
        H.pts[4].X = 5; H.pts[4].Y = 6;
        H.pts[5].X = 6; H.pts[5].Y = 4;
        H.pts[6].X = 8; H.pts[6].Y = 3;

        Point P, Q;
        P.X = 1; P.Y = 5;
        Q.X = 4; Q.Y = 6;

        //int over = PQLeftOverH(P, Q, H);
//      printf("over=%d", over);
    }

    return 0;
}

