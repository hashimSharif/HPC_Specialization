#include <upc.h>

typedef shared [] int *SPtr_t;

shared SPtr_t X[THREADS];

extern int next_idx(void);

// Whirl2C asserts:
SPtr_t foo(int bytes) {
  SPtr_t p;
  p = X[next_idx()] = (SPtr_t)upc_alloc(bytes);
  return p;
}
  
// Whirl2C asserts:
SPtr_t bar(int bytes) {
  return X[next_idx()] = (SPtr_t)upc_alloc(bytes);
}



// The following four variants are all OK.
// This is presumably because they don't "load" from "X[next_idx()]"
  
// This version breaks original into 2 assignments
SPtr_t foo2(int bytes) {
  SPtr_t p;
  p = (SPtr_t)upc_alloc(bytes);
  X[next_idx()] = p;
  return p;
}
  
// This version reorders original to make "X[next_idx()]" leftmost.
SPtr_t foo3(int bytes) {
  SPtr_t p;
  X[next_idx()] = p = (SPtr_t)upc_alloc(bytes);
  return p;
}
  
// This version uses a temporary to hold result of "next_idx()"
SPtr_t bar2(int bytes) {
  int index = next_idx();
  return X[index] = (SPtr_t)upc_alloc(bytes);
}
