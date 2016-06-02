#include <upc.h>

shared double x[THREADS];
shared double y[THREADS*2];
shared double x[THREADS*1];

int main() { return 0; }
