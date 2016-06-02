/* test the UPC_DEBUG_MALLOC checking in debug mode */
#include <upc.h>
#include <stdio.h>
#include <string.h>

void wait() {
  for (int i=0; i < 10000; i++) bupc_poll();
}

int main(int argc, char **argv) {
  int test = 0;
  int allocm = 1;
  if (argc != 3 || 
      (allocm=atoi(argv[1])) < 1 || allocm > 5 ||
      (test=atoi(argv[2])) < 1 || test > 8) {
     printf("usage: %s <allocmethod(1..5)> <testnum(1..8)> \n", argv[0]); exit(1); 
  }
  char *p;
  if (!MYTHREAD) { printf("setting up...\n"); fflush(stdout); }
  upc_barrier;
  switch(allocm) {
    case 1:
      p = malloc(10);
      printf("Initial contents: 0x%016llx %8.3E\n", *(unsigned long long*)p, *(double *)p);
      break;
    case 2:
      p = calloc(2,5);
      break;
    case 3:
      p = malloc(5);
      p = realloc(p,10);
      break;
    case 4: {
      char *tmp = malloc(10);
      strcpy(tmp, "123456789");
      p = strdup(tmp);
      free(tmp);
      break;
    }
    case 5: {
      char *tmp = malloc(50);
      strcpy(tmp, "12345678901234567890");
      p = strndup(tmp,9);
      free(tmp);
      break;
    }
  }
  upc_barrier;
  if (!MYTHREAD) { printf("running test...\n"); fflush(stdout); }
  upc_barrier;
  switch(test) {
    case 1:
      free(p);
      free(p);
      break;
    case 2:
      free(p+1);
      break;
    case 3:
      free(p-1);
      break;
    case 4:
      p[10] = 'x';
      wait();
      break;
    case 5:
      *--p = 'x';
      wait();
      break;
    case 6: {
      char *tmp = realloc(p, 20);
      free(tmp);
      free(p);
      break;
    }
    case 7:
      free(p);
      wait();
      upc_barrier;
      if (!MYTHREAD) { printf("completed successfully.\n"); fflush(stdout); }
      return 0;
    case 8: {
      free(p);
      printf("Freed contents: 0x%016llx %8.3E\n", *(unsigned long long*)p, *(double *)p);
      p[4] = 'x'; 
      wait();
      break;
    }
  }
  printf("ERROR: corruption not detected!\n");
  return 0;
}
