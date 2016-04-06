#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

shared int *tentative;
shared int *settoNULL = NULL;
shared int *explicitly_set;

#define betrue(expr)                                         \
    if (expr) {                                              \
	/* yeah, so what? */                                 \
    } else {                                                 \
	fprintf(stderr, "FAILED: '" #expr "' was untrue\n"); \
	errors = 1;                                          \
    }

#define befalse(expr)                                      \
    if (expr) {                                            \
	fprintf(stderr, "FAILED: '" #expr "' was true\n"); \
	errors = 1;                                        \
    }

int main(int argc, char **argv)
{
    int errors = 0;

    befalse(tentative);
    betrue(tentative == NULL);
    befalse(settoNULL);
    betrue(settoNULL == NULL);
    explicitly_set = NULL;
    befalse(explicitly_set);
    betrue(explicitly_set == NULL);


    if (errors) {
	exit(-1);
    } else {
	printf("SUCCESS: the sweet smell thereof\n");
    }

    return 0;
}


