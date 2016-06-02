#include <stdio.h>
typedef struct ab_struct ab_t;
struct ab_struct
{
    int a;
    int b;
};

struct test_struct_typedef 
{
    int a;
    int b;
    int c;
    ab_t d;
};

struct test_struct_struct
{
    int a;
    int b;
    int c;
    struct ab_struct d;
};

int
main (int argc, char *argv[])
{
    struct test_struct_typedef t_typedef;
    struct test_struct_struct t_struct;
    struct ab_struct ab1;
    ab_t ab2;

    if (&(t_typedef.d.b) - (int*)&t_typedef != 4) printf("ERROR on %i\n",__LINE__);
    if (&(t_struct.d.b) - (int*)&t_struct != 4) printf("ERROR on %i\n",__LINE__);

    if (&(t_typedef.d.b) - &(t_typedef.d.a) != 1) printf("ERROR on %i\n",__LINE__);
    if (&(t_struct.d.b) - &(t_struct.d.a) != 1) printf("ERROR on %i\n",__LINE__);

    t_typedef.a = 100;
    t_typedef.b = 101;
    t_typedef.c = 102;
    t_typedef.d.a = 103;
    t_typedef.d.b = 104;

    for (int i=0; i < 5; i++) {
      if (((int*)&t_typedef)[i] != 100+i) printf("ERROR on %i at i=%i\n",__LINE__,i);
    }

    t_struct.a = 100;
    t_struct.b = 101;
    t_struct.c = 102;
    t_struct.d.a = 103;
    t_struct.d.b = 104;

    for (int i=0; i < 5; i++) {
      if (((int*)&t_struct)[i] != 100+i) printf("ERROR on %i at i=%i\n",__LINE__,i);
    }

    ab1.a = 10;
    ab1.b = 20;
    ab2.a = 10;
    ab2.b = 20;

    printf("done.\n");
    return 0;
}
