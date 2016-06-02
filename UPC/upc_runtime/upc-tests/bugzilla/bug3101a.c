// This works:
extern int p;
int p = 0;

// but this crashes:
extern int q;
int q = 0;
extern int q;
