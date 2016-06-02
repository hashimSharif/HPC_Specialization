#include <stdlib.h>
#include <stdio.h>

#ifdef NOT_UPC
int THREADS = 1;
int MYTHREAD = 0;
#else
#include <upc.h>
#endif

int foo_l(void)
{
    long x = 24;

    if (MYTHREAD == 0) {
	printf("foo_l: value = %ld\n",x);
    }
    return (int)x;
}

int foo_ll(void)
{
    long long x = 48;

    if (MYTHREAD == 0) {
	printf("foo_ll: value = %lld\n",x);
    }
    return (int)x;
}

int main(int argc, char* argv[])
{
    int foo_out;
    int err = 0;


    if (MYTHREAD == 0) {
	printf("sizeof(int)       = %d\n",(int)sizeof(int));
	printf("sizeof(long)      = %d\n",(int)sizeof(long));
	printf("sizeof(long long) = %d\n",(int)sizeof(long long));
	printf("sizeof(void*)     = %d\n",(int)sizeof(void*));
	printf("sizeof(double)    = %d\n",(int)sizeof(double));
    }

    foo_out = foo_l();
    if (foo_out != 24) err += 1;
    if (MYTHREAD == 0) {
        printf("foo_out from foo_l = %d\n",foo_out);
    }

    foo_out = foo_ll();
    if (foo_out != 48) err += 10;
    if (MYTHREAD == 0) {
        printf("foo_out from foo_ll = %d\n",foo_out);
    }

    if (err == 0) {
	printf("SUCCESS on thread %d\n",MYTHREAD);
    } else {
	printf("FAILURE with err = %d on thread %d\n",err,MYTHREAD);
    }

    return err;

}
