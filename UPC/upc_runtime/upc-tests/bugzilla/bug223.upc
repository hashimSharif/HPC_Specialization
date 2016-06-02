#include <stdio.h>
#include "upc.h"
shared [2] int *shptr; 

int main()
{
    shptr++;
    printf("shptr plusplus\n");
    shptr--;
    printf("shptr minusminus\n");

    return 0;
}
