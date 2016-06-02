#include <stdio.h>

struct T1 {
  int xxx;
  int a[3]; /* if a is not the first field */
};

struct T2 {
  int a;
  struct T1 b[3];
};

struct T3 {
  int a;
  int b;
  struct T2 c;
};

int main(void) {
  char *pc;
  struct T3 t[2];

  /* Following is mistranslated as "pc = (char *)(&t[0]);" */
  pc = (char*)t + 3*sizeof(int);

  if ((int)(pc - (char *)t) != 3*sizeof(int)) {
    printf("FAIL: got %d but expected %d\n", (int)(pc - (char *)t), (int)(3*sizeof(int)));
  } else {
    printf("PASS\n");
  }

  return 0;
}
