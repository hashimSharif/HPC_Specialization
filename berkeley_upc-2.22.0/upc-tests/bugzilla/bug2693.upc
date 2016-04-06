#include <stdio.h>
#include <upc_relaxed.h>

typedef struct foostr
{
    int pair[2];
} foo;

foo var;  // this problem seems to occur only when var is global.

int main()
{    
    foo *p;

    // TLD is not applied to following, leading to writes to WRONG location
    var.pair[0] = 10;
    var.pair[1] = 20;

    p = &var; // point p at var - seems to be successful.

    printf("compare pointers: %p %p\n", &var, p);

    // this prints expected results, but read from the (again) WRONG location
    printf("var = %d %d\n", var.pair[0], var.pair[1]); 

    // this properly dereferences p, but does not see the desired value
    printf("p = %d %d\n", p->pair[0], p->pair[1]);

    if(p->pair[0] == var.pair[0]) printf("PASS\n");
    else printf("FAIL\n");

    return 0;
}
