#include <stdio.h>
typedef struct ab_struct ab_t;
struct ab_struct
{
    int a, b;
};

struct test_struct 
{
    int a;
    int b;
    int c;
#if TYPEDEFED
    ab_t d;
#else
    struct ab_struct d;
#endif
};

int
main (int argc, char *argv[])
{
    struct test_struct t;

    t.d.b = 1;

    printf ("%p\n", &t.d.b);
    printf ("%d\n", t.d.b);
    printf ("%d\n", *&t.d.b);

    if (t.d.b != 1)  printf("ERROR on %i\n",__LINE__);
    if (*&t.d.b != 1)  printf("ERROR on %i\n",__LINE__);
    printf("done.\n");
    return 0;
}
