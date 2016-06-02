#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct {
    int myintarray[10];
} foo;

typedef struct {
  int myint;
  const char *myptr;
  foo myfoo1;
  double mydoublearray[10];
  foo myfoo2;
} bar;

typedef struct {
  bar mybar1;
  bar mybar2;
} yuk;

foo foo1 = { { 10, 20 } };

bar bar1 = {  100, "hi",
  { { 110, 120 } }, 
   { 2.0, 3.0 }, 
  { { 130, 140 } }
};

yuk yuk1 = {
 {  100, "hello",
  { { 110, 120 } },
   { 3.0, 4.0 },
  { { 130, 140 } }
 },
 {  200, "monkey",
  { { 210, 220 } },
   { 5.0, 6.0 },
  { { 230, 240 } }
 }
};

int main(int argc, char* argv[])
{
assert(foo1.myintarray[0] == 10);
assert(foo1.myintarray[1] == 20);
assert(foo1.myintarray[2] == 0);

assert(bar1.myint == 100);
assert(!strcmp(bar1.myptr,"hi"));
assert(bar1.myfoo1.myintarray[0] == 110);
assert(bar1.myfoo1.myintarray[1] == 120);
assert(bar1.myfoo1.myintarray[2] == 0);
assert(bar1.mydoublearray[0] == 2.0);
assert(bar1.mydoublearray[1] == 3.0);
assert(bar1.mydoublearray[2] == 0.0);
assert(bar1.myfoo2.myintarray[0] == 130);
assert(bar1.myfoo2.myintarray[1] == 140);
assert(bar1.myfoo2.myintarray[2] == 0);

assert(yuk1.mybar1.myint == 100);
assert(!strcmp(yuk1.mybar1.myptr,"hello"));
assert(yuk1.mybar1.myfoo1.myintarray[0] == 110);
assert(yuk1.mybar1.myfoo1.myintarray[1] == 120);
assert(yuk1.mybar1.myfoo1.myintarray[2] == 0);
assert(yuk1.mybar1.mydoublearray[0] == 3.0);
assert(yuk1.mybar1.mydoublearray[1] == 4.0);
assert(yuk1.mybar1.mydoublearray[2] == 0.0);
assert(yuk1.mybar1.myfoo2.myintarray[0] == 130);
assert(yuk1.mybar1.myfoo2.myintarray[1] == 140);
assert(yuk1.mybar1.myfoo2.myintarray[2] == 0);

assert(yuk1.mybar2.myint == 200);
assert(!strcmp(yuk1.mybar2.myptr,"monkey"));
assert(yuk1.mybar2.myfoo1.myintarray[0] == 210);
assert(yuk1.mybar2.myfoo1.myintarray[1] == 220);
assert(yuk1.mybar2.myfoo1.myintarray[2] == 0);
assert(yuk1.mybar2.mydoublearray[0] == 5.0);
assert(yuk1.mybar2.mydoublearray[1] == 6.0);
assert(yuk1.mybar2.mydoublearray[2] == 0.0);
assert(yuk1.mybar2.myfoo2.myintarray[0] == 230);
assert(yuk1.mybar2.myfoo2.myintarray[1] == 240);
assert(yuk1.mybar2.myfoo2.myintarray[2] == 0);

    printf("done.\n");
    return 0;
}
