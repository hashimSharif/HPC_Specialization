#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#define N 2
struct s1 {       int inner[N];    };
struct s2 { struct s1 outer[N][N]; };
int main (void) {
   struct s2 *s = calloc(1,sizeof(struct s2));
   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
         for(int k=0; k<N; k++)
            s->outer[i][j].inner[k] = i+j+k;
   if (!MYTHREAD)
      puts ((s->outer[1][1].inner[1] == 3) ? "PASS" : "FAIL");
   return s->outer[0][0].inner[0];
}
