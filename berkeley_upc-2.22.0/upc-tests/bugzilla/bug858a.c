#include <assert.h>
#include <stdio.h>
#include <stdint.h>

int test_a(void) { // struct designator + designator in array w/i the struct
    typedef struct type_a {
        int x;
        int y;
        int arr[10];
    } type_a;

    type_a a = { .x = 1, .y = 2, .arr = { [2] = 4, [5] = 16 } };

    assert(a.x == 1); a.x = 0;
    assert(a.y == 2); a.y = 0;
    assert(a.arr[0] == 0);
    assert(a.arr[1] == 0);
    assert(a.arr[2] == 4); a.arr[2] = 0;
    assert(a.arr[3] == 0);
    assert(a.arr[4] == 0);
    assert(a.arr[5] == 16); a.arr[5] = 0;
    assert(a.arr[6] == 0);
    assert(a.arr[7] == 0);
    assert(a.arr[8] == 0);
    assert(a.arr[9] == 0);

    puts("test_a() passed");
    return 0;
}

int test_b(void) { // array of ints
    int b[4] = { [1] = 1, [3] = 3 };

    assert(b[0] == 0);
    assert(b[1] == 1);
    assert(b[2] == 0);
    assert(b[3] == 3);

    puts("test_b() passed");
    return 0;
}

int test_c(void) { // array of floats
    float c[6] = { [1] = 0.125, [3] = 0.375, 0.875 };

    assert(c[0] == 0.0);
    assert(c[1] == 0.125);
    assert(c[2] == 0.0);
    assert(c[3] == 0.375);
    assert(c[4] == 0.875);
    assert(c[5] == 0.0);

    puts("test_c() passed");
    return 0;
}


int test_d(void) { // array of pointers
    char * d[4] = { [1] = (char*)(intptr_t)1, [3] = (char*)(intptr_t)2 };

    assert(d[0] == NULL);
    assert((intptr_t)d[1] == 1);
    assert(d[2] == NULL);
    assert((intptr_t)d[3] == 2);

    puts("test_d() passed");
    return 0;
}

int test_e(void) { // partial initialization of struct
    typedef struct type_e {
        int x;
        int y;
        struct { char ca[2]; int i; float f; } s;
        int z;
    } type_e;

    type_e e1 = { .x = 1, .z = 2 };

    assert(e1.x == 1);
    assert(e1.y == 0);
    assert(e1.s.ca[0] == 0);
    assert(e1.s.ca[1] == 0);
    assert(e1.s.i == 0);
    assert(e1.s.f == 0.0);
    assert(e1.z == 2);

    type_e e2 = { .s = { .ca = {1,}, .f = 1.25 } };

    assert(e2.x == 0);
    assert(e2.y == 0);
    assert(e2.s.ca[0] == 1);
    assert(e2.s.ca[1] == 0);
    assert(e2.s.i == 0);
    assert(e2.s.f == 1.25);
    assert(e2.z == 0);

    puts("test_e() passed");
    return 0;
}

int test_f(void) { // designators for array of structs and array of arrays
    typedef struct { int x; int y; } type_f1;
    typedef char type_f2 [6];

    type_f1 f1[3] = { [1] = {1,2} };

    assert(f1[0].x == 0);
    assert(f1[0].y == 0);
    assert(f1[1].x == 1); f1[1].x = 0;
    assert(f1[1].y == 2); f1[1].y = 0;
    assert(f1[2].x == 0);
    assert(f1[2].y == 0);

    type_f2 f2[3] = { [1] = {[2] = 3,4} };

    assert(f2[0][0] == 0);
    assert(f2[0][1] == 0);
    assert(f2[0][2] == 0);
    assert(f2[0][3] == 0);
    assert(f2[0][4] == 0);
    assert(f2[0][5] == 0);
    assert(f2[1][0] == 0);
    assert(f2[1][1] == 0);
    assert(f2[1][2] == 3); f2[1][2] = 0;
    assert(f2[1][3] == 4); f2[1][3] = 0;
    assert(f2[1][4] == 0);
    assert(f2[1][5] == 0);
    assert(f2[2][0] == 0);
    assert(f2[2][1] == 0);
    assert(f2[2][2] == 0);
    assert(f2[2][3] == 0);
    assert(f2[2][4] == 0);
    assert(f2[2][5] == 0);

    puts("test_f() passed");
    return 0;
}


int test_g(void) { // designators for array of unions
    typedef union { int x; char y; } type_g;

    type_g g[5] = { {.x=1}, {.x=2}, {.x=3}, [4]={.x=5} };

    assert(g[0].x == 1); g[0].x = 0;
    assert(g[1].x == 2); g[1].x = 0;
    assert(g[2].x == 3); g[2].x = 0;
    assert(g[3].x == 0);
    assert(g[4].x == 5); g[4].x = 0;

    puts("test_g() passed");
    return 0;
}

int main(void) {
    test_a();
    test_b();
    test_c();
    test_d();
    test_e();
    test_f();
    test_g();

    puts("done.");
    return 0;
}
