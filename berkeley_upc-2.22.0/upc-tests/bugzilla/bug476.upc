static double foo(int x);
extern double bar();

static double foo(int x) {
  return x*0.1;
}
extern double bar() {
  return 3.14;
}
int yomama() {
  return 5;
}
int main() { 
  double d = foo(5)+bar()+yomama();
  return 0; 
}
