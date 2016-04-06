#include <upc.h>

struct {
 struct {
  struct {
   struct {
    struct {
     struct {
      struct {
       struct {
        struct {
         struct {
int i;
         } s9;
        } s8;
       } s7;
      } s6;
     } s5;
    } s4;
   } s3;
  } s2;
 } s1;
} X;

int main(void) {
      X.s1.s2.s3.s4.s5.s6.s7.s8.s9.i = 1;
      return 0;
}
