int bug521c_beforeupcrelaxed;
#include <upc_relaxed.h>
int bug521_afterupcrelaxed;

int bug521_beforebug521h;
#include <triangle.h>
int bug521c_afterbug521h;

#include <stdio.h>

int main() 
{
    printf("SUCCESS\n");
    return 0;
}
