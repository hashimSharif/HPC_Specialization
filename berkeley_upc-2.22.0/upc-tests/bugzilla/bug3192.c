#include <stddef.h>

extern int  f00(int [const]);
extern int  f01(int [volatile]);
extern int  f02(int [restrict]);
extern int  f03(int [const    1]);
extern int  f04(int [volatile 2]);
extern int  f05(int [restrict 3]);
extern int  f06(int [static const    1]);
extern int  f07(int [static volatile 2]);
extern int  f08(int [static restrict 3]);
extern int  f09(int [const static    1]);
extern int  f10(int [volatile static 2]);
extern int  f11(int [restrict static 3]);

extern int  g00(int arr[const]);
extern int  g01(int arr[volatile]);
extern int  g02(int arr[restrict]);
extern int  g03(int arr[const    1]);
extern int  g04(int arr[volatile 2]);
extern int  g05(int arr[restrict 3]);
extern int  g06(int arr[static const    1]);
extern int  g07(int arr[static volatile 2]);
extern int  g08(int arr[static restrict 3]);
extern int  g09(int arr[const static    1]);
extern int  g10(int arr[volatile static 2]);
extern int  g11(int arr[restrict static 3]);

typedef int Int;

extern int  F00(Int [const]);
extern int  F01(Int [volatile]);
extern int  F02(Int [restrict]);
extern int  F03(Int [const    1]);
extern int  F04(Int [volatile 2]);
extern int  F05(Int [restrict 3]);
extern int  F06(Int [static const    1]);
extern int  F07(Int [static volatile 2]);
extern int  F08(Int [static restrict 3]);
extern int  F09(Int [const static    1]);
extern int  F10(Int [volatile static 2]);
extern int  F11(Int [restrict static 3]);

extern int  G00(Int arr[const]);
extern int  G01(Int arr[volatile]);
extern int  G02(Int arr[restrict]);
extern int  G03(Int arr[const    1]);
extern int  G04(Int arr[volatile 2]);
extern int  G05(Int arr[restrict 3]);
extern int  G06(Int arr[static const    1]);
extern int  G07(Int arr[static volatile 2]);
extern int  G08(Int arr[static restrict 3]);
extern int  G09(Int arr[const static    1]);
extern int  G10(Int arr[volatile static 2]);
extern int  G11(Int arr[restrict static 3]);

int f00 (int arr[const]) { return arr[1]; }
int g00 (int arr[const]) { return arr[1]; }
int F00 (Int arr[const]) { return arr[1]; }
int G00 (Int arr[const]) { return arr[1]; }

typedef int (*fptr_t)(float [restrict 10]);
fptr_t F = (int (*)(float [restrict 10]))NULL;

#if 0 // These should be errors but we are too lax to notice:
typedef int t1[restrict 5];//should error
int v1[restrict 6];//should error
#endif


int main(void) { return 0; }
