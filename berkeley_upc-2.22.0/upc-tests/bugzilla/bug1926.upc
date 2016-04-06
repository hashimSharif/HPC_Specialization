#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdint.h>
#include <upc.h>


typedef struct timeval TIMESTRUCT;

int main(int argc, char **argv)
{
    TIMESTRUCT t1, t2;
    
    gettimeofday(&t1, 0);
    gettimeofday(&t2, 0);
    printf("Hello: inteval%ld=\n", (long)(t2.tv_sec - t1.tv_sec));

    return 0;
}


