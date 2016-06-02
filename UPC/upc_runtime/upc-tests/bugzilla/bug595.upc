#include <upc.h>
#include <stdlib.h>
#include <stdio.h>

#define DEF_STRUCT(name,contents) \
  typedef struct S_##name {       \
  contents                        \
  } name

#define CONFIRM(sz) do {                                            \
   if (sz != sz1) printf("ERROR: "#sz"(%i) != sz1(%i)\n", sz, sz1); \
 } while (0)

#define _CHECK_STRUCT(name) do {                                  \
  printf("----------------------------------\n");                \
  int zero = 0, one = 1;                                         \
  char *tmp0ptr; char *tmp1ptr;                                  \
  int sz1 = sizeof(name);                                        \
  printf("sizeof(" #name ")=%i\n", sz1);                         \
                                                                 \
  int sz2 = sizeof(shared name);                                 \
  printf("sizeof(shared " #name ")=%i\n", sz2);                  \
  CONFIRM(sz2);                                                  \
                                                                 \
  int sz3 = sizeof(shared [] name);                              \
  printf("sizeof(shared [] " #name ")=%i\n", sz3);               \
  CONFIRM(sz3);                                                  \
                                                                 \
  int sz4 = sizeof(shared [10] name);                            \
  printf("sizeof(shared [10] " #name ")=%i\n", sz4);             \
  CONFIRM(sz4);                                                  \
                                                                 \
  int sz5 = sizeof(shared [1] name);                             \
  printf("sizeof(shared [1] " #name ")=%i\n", sz5);              \
  CONFIRM(sz5);                                                  \
                                                                 \
  shared [] name *p = upc_alloc(sizeof(name)*10);                \
                                                                 \
  int sz20 = (char *)&(p[1]) - (char *)&(p[0]);                  \
  printf("(char *)&(p[1]) - (char *)&(p[0])=%i\n", sz20);        \
  CONFIRM(sz20);                                                 \
                                                                 \
  tmp1ptr = (char *)&(p[1]);                                     \
  tmp0ptr = (char *)&(p[0]);                                     \
  int sz21 = tmp1ptr - tmp0ptr;                                  \
  printf("tmp1ptr - tmp0ptr=%i\n", sz21);                        \
  CONFIRM(sz21);                                                 \
                                                                 \
  int sz22 = (char *)&(p[one]) - (char *)&(p[zero]);             \
  printf("(char *)&(p[one]) - (char *)&(p[zero])=%i\n", sz22);   \
  CONFIRM(sz22);                                                 \
                                                                 \
  tmp1ptr = (char *)&(p[one]);                                   \
  tmp0ptr = (char *)&(p[zero]);                                  \
  int sz23 = tmp1ptr - tmp0ptr;                                  \
  printf("tmp1ptr - tmp0ptr=%i\n", sz23);                        \
  CONFIRM(sz23);                                                 \
                                                                 \
                                                                 \
  name *p2 = malloc(sizeof(name)*10);                            \
                                                                 \
  int sz30 = (char *)&(p2[1]) - (char *)&(p2[0]);                \
  printf("(char *)&(p2[1]) - (char *)&(p2[0])=%i\n", sz30);      \
  CONFIRM(sz30);                                                 \
                                                                 \
  tmp1ptr = (char *)&(p2[1]);                                    \
  tmp0ptr = (char *)&(p2[0]);                                    \
  int sz31 = tmp1ptr - tmp0ptr;                                  \
  printf("tmp1ptr - tmp0ptr=%i\n", sz31);                        \
  CONFIRM(sz31);                                                 \
                                                                 \
  int sz32 = (char *)&(p2[one]) - (char *)&(p2[zero]);           \
  printf("(char *)&(p2[one]) - (char *)&(p2[zero])=%i\n", sz32); \
  CONFIRM(sz32);                                                 \
                                                                 \
  tmp1ptr = (char *)&(p2[one]);                                  \
  tmp0ptr = (char *)&(p2[zero]);                                 \
  int sz33 = tmp1ptr - tmp0ptr;                                  \
  printf("tmp1ptr - tmp0ptr=%i\n", sz33);                        \
  CONFIRM(sz33);                                                 \
                                                                 \
} while (0)

#define CHECK_STRUCT(name) do {   \
  _CHECK_STRUCT(name);            \
  _CHECK_STRUCT(struct S_##name); \
  } while (0)

DEF_STRUCT(s1,  int f1;);
DEF_STRUCT(s2,  double f1; int f2;);
DEF_STRUCT(s3,  int f1; double f2;);
DEF_STRUCT(s4,  double f1; int f2; double f3;);
DEF_STRUCT(s5,  shared void *f1; int f2; );
DEF_STRUCT(s6,  int f1; shared void *f2; );
DEF_STRUCT(s7,  double f1; shared void *f2; );
DEF_STRUCT(s8,  int f1; shared void *f2; int f3; );
DEF_STRUCT(s9,  char f1; shared void *f2; char f3; shared void *f4; );
DEF_STRUCT(s10, shared void *f2[4]; );
DEF_STRUCT(s11, char f1; shared void *f2[4]; );
DEF_STRUCT(s12, int f1; shared void *f2[4]; );
DEF_STRUCT(s13, double f1; shared void *f2[4]; );

DEF_STRUCT(s31,  s1 f1;);
DEF_STRUCT(s32,  s5 f1; s5 f2;);
DEF_STRUCT(s33,  s5 f1; s9 f2; s11 f3; s12 f4; s13 f5;);
DEF_STRUCT(s34,  s33 f1; s33 f2; s32 f3; s12 f4; s13 f5;);
DEF_STRUCT(s35,  s1 f1; s2 f2; s3 f3; s4 f4; s5 f5; s6 f6; s7 f7; s8 f8; s9 f9; s10 f10; s11 f11; s12 f12; s13 f13;);
DEF_STRUCT(s36,  char f1; s34 f2; int f3; s35 f4;);
DEF_STRUCT(s37,  double f1; s36 f2; s36 f3;);


void do1() {
    CHECK_STRUCT(s1);
    CHECK_STRUCT(s2);
    CHECK_STRUCT(s3);
    CHECK_STRUCT(s4);
    CHECK_STRUCT(s5);
}
void do2() {
    CHECK_STRUCT(s6);
    CHECK_STRUCT(s7);
    CHECK_STRUCT(s8);
    CHECK_STRUCT(s9);
    CHECK_STRUCT(s10);
}
void do3() {
    CHECK_STRUCT(s11);
    CHECK_STRUCT(s12);
    CHECK_STRUCT(s13);
}

void do4() {
    CHECK_STRUCT(s31);
    CHECK_STRUCT(s32);
    CHECK_STRUCT(s33);
    CHECK_STRUCT(s34);
    CHECK_STRUCT(s35);
}
void do5() {
    CHECK_STRUCT(s36);
    CHECK_STRUCT(s37);
}

int main() {
  if (MYTHREAD == 0) {
    do1();
    do2();
    do3();
    do4();
    do5();
    printf("done.\n");
  }
  upc_barrier;
  return 0;
}

