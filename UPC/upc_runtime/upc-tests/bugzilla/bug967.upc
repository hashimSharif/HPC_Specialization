shared volatile int x;
typedef struct s {
 volatile int f1;
} S;
volatile S ps;
S ps2;
shared volatile S ss;
int main() {
  x = 4;
  ps.f1 = 5;
  ps2.f1 = 5;
  ss.f1 = 5;
  ps = ss;
  ss = ps;
  return 0;
}
