typedef struct { int i; } S;
int func1(S *arg) { return arg[1].i; }
int func2(S arg[]) { return arg[1].i; }
int main(void) { return 0; }
