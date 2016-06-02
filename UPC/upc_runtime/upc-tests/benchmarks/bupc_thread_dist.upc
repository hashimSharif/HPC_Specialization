#include <upc.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main() {
  fflush(NULL);
  upc_barrier;
  if (!MYTHREAD) {
    /* sanity checks */
    assert(BUPC_THREADS_SAME == 0);
    /* table display */
    printf("\n      ");
    for (int j=0; j<THREADS; j++) {
     printf(" %8i",j);
    }
    printf("\n      ");
    for (int j=0; j<THREADS; j++) {
     printf("---------");
    }
    printf("\n    |\n");
    for (int i=0; i<THREADS; i++) {
      printf("%-4i| ",i);
      for (int j=0; j<THREADS; j++) {
         int val = bupc_thread_distance(i,j);
         char str[80];
         assert(val == bupc_thread_distance(j,i));
         if (i == j) assert(val == BUPC_THREADS_SAME);
         else assert(val != BUPC_THREADS_SAME);
         switch (val) {
           #define CASEVAL(name) case BUPC_THREADS_##name: strcpy(str, #name); break;
           CASEVAL(SAME);
           CASEVAL(VERYNEAR);
           CASEVAL(NEAR);
           CASEVAL(FAR);
           CASEVAL(VERYFAR);
           default:
           sprintf(str,"%i",val);
         }
         printf(" %8s",str);
      }
      printf("\n    |\n");
    }
    printf("      ");
    for (int j=0; j<THREADS; j++) {
     printf("---------");
    }
    printf("\n\n");
    /* value key */
    { int val = 0;
      #define PRVAL(name) do { \
        printf("%-22s = %i\n","BUPC_THREADS_"#name, BUPC_THREADS_##name); \
          assert(BUPC_THREADS_##name >= val); val = BUPC_THREADS_##name; \
      } while (0)
      PRVAL(SAME);
      PRVAL(VERYNEAR);
      PRVAL(NEAR);
      PRVAL(FAR);
      PRVAL(VERYFAR);
    }
    
    printf("\ndone.\n");
  }
  fflush(NULL);
  upc_barrier;
}
