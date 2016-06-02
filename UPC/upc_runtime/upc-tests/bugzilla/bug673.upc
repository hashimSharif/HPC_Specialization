#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <upc.h>

struct myStruct{
    int i1;
    int i2;
};


int main(int argc, char **argv)
{
    int i;
    shared struct myStruct* s = upc_global_alloc(1, sizeof(struct myStruct));
    s->i1 = 0;
    s->i2 = 3;

    s->i2 = s->i2 - 1; // this line is okay
    s->i2--;           // this line is problematic

    i = s->i2; // this line causes segmentation fault
    
    printf("SUCCESS\n");
    return 0;
}


