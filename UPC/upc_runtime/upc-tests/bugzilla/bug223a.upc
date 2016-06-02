#include <upc_strict.h>
#include <stdlib.h>

int main() 
{
    int i = 0 ,j = 0;
    int *l1, *l2;
    shared [2] int *s1=NULL, *s2=NULL;
    shared int *p1=NULL, *p2;
    shared [] int *pI=NULL, *pII;
    
    s1 = s1 - (i+j);
    s2 = s2 + (i+j);
    p1 = p1 - (i-1);
    pI = pI - i;

    return 0;
}
