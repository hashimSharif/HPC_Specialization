#include <upc.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct Foo_Rec {
    double vec[10];
    int    cnt;
    int    pad;  /* ensure 8-byte aligned size, otherwise FooUnion may need padding for initial ptr */
} Foo;

typedef union FooUnion_Rec {
    Foo    foo;
    union  FooUnion_Rec *next;
} FooUnion;

int main(int argc, char* argv[])
{
    printf("Sizeof Foo = %d\n",(int)sizeof(Foo));
    printf("Sizeof FooUnion = %d\n",(int)sizeof(FooUnion));

    if (sizeof(Foo) == sizeof(FooUnion)) {
      printf("Success\n");
    } else {
      printf("Failure\n");
    }
    return 0;
}
