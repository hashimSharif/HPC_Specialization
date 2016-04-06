#include <upc.h>

void fun1(shared     int *arg) { ; }
void fun2(shared [1] int *arg) { ; }

shared     int *ptr1;
shared [1] int *ptr2;

int main()
{
    ptr1 = ptr2;  // INCORRECT WARNING
    ptr2 = ptr1;  // INCORRECT WARNING

    fun1(ptr1);
    fun1(ptr2);  // INCORRECT WARNING

    fun2(ptr1);  // INCORRECT WARNING
    fun2(ptr2);

    return 0;
}

