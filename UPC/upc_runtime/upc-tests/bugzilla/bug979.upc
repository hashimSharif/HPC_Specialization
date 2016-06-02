#include <upc_strict.h>

// GS collides w/ a Solaris system header
#ifdef GS
#undef GS
#define GS My_GS
#endif

struct G {
int curid;
  int last;
};

shared struct G* shared GS;
shared struct G* G;

int pid;
int main() {
  G = upc_alloc(sizeof(struct G));
  if (MYTHREAD == 0) GS = G;
  upc_barrier;

  G->last = G->curid = 0;
  G->last += pid;
  pid = GS->curid++; //broken
  pid = G->curid++;
  return 0;
}
