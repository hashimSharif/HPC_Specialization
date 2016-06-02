#if 0
  #include <iostream.h>
#else
  #include <iostream>
  using namespace std;
#endif
#include <stdlib.h>
#include <unistd.h>

#include "cpplib.h"

// The dumbest C++ class in the world
class Adder {
private:
    int a, b; 
public:
    Adder(int x, int y): a(x), b(y) {}
    void setA(int val) { a = val; }
    void setB(int val) { b = val; }
    int add() { return a + b; }
};


// Global object, to test static constructors
Adder adder (2, 3);

/*
 * Extern "C" functions that UPC code can call
 *  - can use C++ inside the functions
 */

int ask_Adder(void)
{
    return adder.add(); 
}

int ask_BadAdder(int a, int b)
{
    Adder badadder(a -1, b);

    // for once, it's not segmentation's fault...
    return badadder.add();
}

