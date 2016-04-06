/* allocbug - a tester exhibiting some typical local memory management bugs */

#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv) {
  if (argc != 2) {
    printf("%s <testnum>\n",argv[0]);
    exit(1);
  }
  /* malloc some data */
  for (int i=0;i<15;i++) {
    char *p = malloc(1<<i);
  }

  switch (atoi(argv[1])) {
    case 1: { printf("testing duplicate free\n");
      char *p = malloc(20);
      free(p);
      free(p);
      break;
      }
    case 2: { printf("testing overrun\n");
      char *p = malloc(20);
      p[20] = 'f';
      free(p);
      break;
      }
    case 3: { printf("testing underrun (-1-byte)\n");
      char *p = malloc(20);
      *(p-1) = 'f';
      free(p);
      break;
      }
    case 4: { printf("testing underrun (-9-byte)\n");
      char *p = malloc(20);
      *(p-9) = 'f';
      free(p);
      break;
      }
    case 5: { printf("testing underrun (header clobber)\n");
      char *p = malloc(20);
      int header = 16+4*sizeof(void*);
      memset(p-header,'f',header+5);
      free(p);
      break;
      }
    default: printf("unknown test\n");
  }
  printf("ERROR\n");
  exit(1);
}
  

