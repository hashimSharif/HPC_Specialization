#include <string.h>
#include <upc_strict.h>

struct list {
  int *p;
  shared [] struct list * next;
};

int main() {

  struct list *l1 = NULL;
  shared [] struct list * l2 = NULL;
  int * p = NULL;
  l1->p = p;
  l1->next = l2;
}

