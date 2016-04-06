#include <upc.h>
typedef struct {
  double a;
  double b;
  int c;
#ifdef BIG
  double aaa[124];
#endif 
} ret_s;

ret_s var;
extern ret_s f() { 
  ret_s result; 
  result = var; 
   return result; 
} 
extern int g() {
  return 0;
}
int i;
int main() {
  i = g();
  var = f();
  return 0;
}
