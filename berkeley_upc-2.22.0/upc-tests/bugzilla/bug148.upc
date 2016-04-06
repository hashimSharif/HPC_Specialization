#include <upc.h>

/* upc_lock_t is a "shared datatype with incomplete type" */
/* NOTE:  this test _should_ compile under both static AND dynamic threads */

upc_lock_t *lock_1[100];  /* private array of pointer-to-lock */

typedef upc_lock_t *LOCK;
LOCK lock_2[100];  /* also a private array of pointer-to-lock */

int main() { 
  return 0; 
}
