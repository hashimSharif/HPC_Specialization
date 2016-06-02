#include <upc.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

typedef struct foo_rec {
   int len;
   shared [] float* data;
} foo_t;

shared [] foo_t * foo_alloc(int len)
{
    shared [] foo_t *p;
    
    p = (shared [] foo_t *)upc_alloc(sizeof(foo_t));
    assert(p != NULL);
    p->data = (shared [] float*)upc_alloc(len*sizeof(float));
    assert(p->data != NULL);
    p->len = len;
    return p;
}

void foo_free(shared [] foo_t * p)
{
    assert( upc_threadof(p) == MYTHREAD );
    //printf("Thread %d freeing data field\n",MYTHREAD);
    upc_free(p->data);
    //printf("Thread %d freeing structure\n",MYTHREAD);
    upc_free(p);
}

int main(int argc, char* argv[])
{
    shared [] foo_t *fooptr;
    int numcell = 100 * (MYTHREAD+1);

    //printf("Thread %d Starting, numcell = %d\n",MYTHREAD,numcell);
    //fflush(stdout);
    //upc_barrier;
    
    fooptr = foo_alloc(numcell);

    if (MYTHREAD == 0) {
	foo_t junk;
	int   sz = sizeof(junk);
	int   off = offsetof(foo_t,data);
	printf("foo_t has size %d and data is at offset %d\n",sz,off);
	fflush(stdout);
    }
    upc_barrier;

  for (int th = 0; th < THREADS; ++th) { // Serialize output to avoid corruption
    if (th != MYTHREAD) {
      // Fall through to the barrier
    } else
    if (fooptr->len == numcell) {
	printf("FOO GOOD on Thread [%d] cells = %d\n",MYTHREAD,fooptr->len);
	fflush(stdout);
    } else {
	printf("FOO BAD  on Thread [%d] cells = %d\n",MYTHREAD,fooptr->len);
	fflush(stdout);
    }
    upc_barrier;
  }

    foo_free(fooptr);

    upc_barrier;
    printf("Thread %d Exiting\n",MYTHREAD);
    fflush(stdout);
    upc_global_exit(0);
    return 1;
}
