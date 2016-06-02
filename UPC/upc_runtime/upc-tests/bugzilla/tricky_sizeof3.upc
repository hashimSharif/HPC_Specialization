#include <stdio.h>

struct S;
typedef shared [10] struct S t_S;

int main() {
//printf("%i\n",upc_blocksizeof(t_S));
//printf("%i\n",sizeof(t_S));
printf("%i\n",(int)upc_localsizeof(t_S));
return 0;
}
