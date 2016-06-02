#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <upc.h> 

#define LENGTH 10

shared [] int *pBuf;

int main (int argc, char **argv) {
  pBuf = upc_alloc(LENGTH * sizeof(int));

  if (MYTHREAD == 0) {
    sleep(1);
  }

  for (int i=0; i<LENGTH; i++) {
    int t = upc_threadof(&(pBuf[i]));
    printf("thread %d: %d\n", MYTHREAD, t);
    assert(t == MYTHREAD);
  }
  printf("done.\n");
  return 0;
}

