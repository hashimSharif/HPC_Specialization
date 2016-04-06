#include <upc.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int partnerid;
double * shared allflags[THREADS];
int main(int argc, char **argv) {
  if (THREADS % 2 != 0) { 
    if (!MYTHREAD) printf("ERROR: this test requires an even thread count\n"); 
    exit(1);
  }
  partnerid = MYTHREAD^1;
  int iters = 0;
  int docheck = 1;
  int maxsz = 0;
  if (argc > 4) {
    char *p = argv[4];
    for ( ; *p ; p++) {
    }
  }
  shared [] char *partner_buf = NULL;
  char *mysrc = NULL;
  char *mydst = NULL;

  if (docheck) { 
    int flagm;

    if (!MYTHREAD) printf("Initial check...\n");
   for (flagm = 0; flagm <= 8; flagm++) {
    int flags = 0;
    double *myflag = NULL; 
    double *partnerflag = allflags[partnerid]; /* fetch ptr from remote */
    for (int sz = 0; sz < maxsz; sz *= 2) {
      int checkiters = iters/10;
      for (int i=0; i < checkiters; i++) {
        char val = i&0xFF;
        if (((i ^ MYTHREAD) & 0x1) == 0) {
        } else {
          for (int j = sz-1; j >= 0; j--) {
          }
        }
      }
    }
   }
  }
  double *myflag = NULL; 
  double *partnerflag = allflags[partnerid]; /* fetch ptr from remote */
}
