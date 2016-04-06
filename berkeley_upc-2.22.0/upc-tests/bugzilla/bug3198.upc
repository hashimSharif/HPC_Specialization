#include <stdio.h>
#include <upc.h>

int failed = 0;

void fail(const char *msg) {
  fputs(msg, stderr);
  failed = 1;
}

typedef struct TaskQueue {
   int counter;
   upc_lock_t *lock;
   shared [] int *pointer;
} TaskQueue;

shared int a[THREADS][10];

int main(int argc, char **argv) {
  if (THREADS != 1) {
    fputs("ERROR: test is only valid for 1 thread\n", stderr);
    return 1;
  } 

 if (MYTHREAD == 0) {
    int i, j;

    for (i = 0; i < THREADS; ++i)
      for (j = 0; j < 10; ++j)
        a[i][j] = (10*i) + j;
    
    // The new bug: offset of pts is getting scaled by size of type it points to
    shared [0] TaskQueue *p = upc_alloc(8 * sizeof(TaskQueue));
    size_t base  = (size_t)upc_addrfield(p);
    size_t c_off = (size_t)upc_addrfield(&p->counter) - base;
    size_t l_off = (size_t)upc_addrfield(&p->lock)    - base;
    size_t p_off = (size_t)upc_addrfield(&p->pointer) - base;
    printf("sizeof(*p) = %zu\n", (size_t)sizeof(*p));
    printf("upc_addrfield(p)    = %zu\n", (size_t)upc_addrfield(p));
    printf("offset(&p->counter) = %zu\n", c_off);
    printf("offset(&p->lock)    = %zu\n", l_off);
    printf("offset(&p->pointer) = %zu\n", p_off);
    if (c_off != 0) fail("ERROR: counter offset should be zero\n");
    if (l_off == 0) fail("ERROR: lock offset should be non-zero\n");
    if (p_off == 0) fail("ERROR: pointer offset should be non-zero\n");
    if (p_off+sizeof(shared [] int *) > sizeof(*p))
      fail("ERROR: pointer offset+size extends beyond end of struct\n");

    // Possible regression 1: multi-dimessional arrays
    base = (size_t)upc_addrfield(a[0]);
    size_t a00_off = (size_t)upc_addrfield(&a[0][0]) - base;
    size_t a01_off = (size_t)upc_addrfield(&a[0][1]) - base;
    size_t a02_off = (size_t)upc_addrfield(&a[0][2]) - base;
    printf("upc_addrfield(a[0])     = %zu\n", (size_t)upc_addrfield(a[0]));
    printf("offset(&a[0][0]) = %zu\n", a00_off);
    printf("offset(&a[0][1]) = %zu\n", a01_off);
    printf("offset(&a[0][2]) = %zu\n", a02_off);
    if ((a00_off != 0) || (a01_off != sizeof(int)) || (a02_off != 2*sizeof(int)))
      fail("ERROR: regression on 2-d array accesses\n");

    // Possible regressions on arith as in upc_all_prefix_reduce.c
    shared char *dst = (shared char *)(&a[0][5]);
    i = *((shared const int *)dst - 4);
    if (i != 5-4)
      fail("ERROR: regression on *((cast)p + const) case 1a\n");
    i = *((shared [4] const int *)dst + 4);
    if (i != 5+4)
      fail("ERROR: regression on *((cast)p + const) case 1b\n");

    shared [4] char *dst4 = (shared [4] char *)(&a[0][5]);
    i = *((shared const int *)dst4 - 4);
    if (i != 5-4)
      fail("ERROR: regression on *((cast)p + const) case 2a\n");
    i = *((shared [4] const int *)dst + 4);
    if (i != 5+4)
      fail("ERROR: regression on *((cast)p + const) case 2b\n");

    // Second case:
    shared struct S {
      shared [] int *pts1, *pts2;
    } *s = upc_alloc(sizeof(struct S));
    base = (size_t)upc_addrfield(s);
    size_t off1 = (size_t)upc_addrfield(&s->pts1) - base;
    size_t off2 = (size_t)upc_addrfield(&s->pts2) - base;
    printf("sizeof(*s)       = %zu\n", (size_t)sizeof(*s));
    printf("sizeof(s->pts1)  = %zu\n", (size_t)sizeof(s->pts1));
    printf("sizeof(s->pts2)  = %zu\n", (size_t)sizeof(s->pts2));
    printf("offset(&s->pts1) = %zu\n", off1);
    printf("offset(&s->pts2) = %zu\n", off2);
    if (off2 != sizeof(s->pts1))
      fail("ERROR: bad layout on 2-pts case\n");

    // Possible regression on bug509.upc case:
    p[0].pointer = upc_alloc(4 * sizeof(int));
    int translator_sz1 = sizeof(int);
    char *tp_one = (char*)&(p[0].pointer[1]);
    char *tp_zero = (char*)&(p[0].pointer[0]);
    int translator_sz2 = tp_one - tp_zero;
    printf("translator_sz1 = %d translator_sz2 = %d\n", translator_sz1, translator_sz2);
    if (translator_sz1 != translator_sz2)
      fail("ERROR: regression on bug509.upc\n");

    puts( failed ? "FAIL" : "PASS" );
  }

  upc_barrier;
  return failed;
}
