#include "foobar.uph"

/**************************************
 * Shared variables 
 **************************************/

shared int foo = 3; /* explicit definition overrides tentative declaration in
		       foobar.uph */

shared int *shared pbar = &amp;bar;
      

/**************************************
 * Unshared variables 
 **************************************/

int quux;

/**************************************
 * Functions
 **************************************/

double gethandynumber() {
    /**********************************
     * Unshared static variable
     **********************************/
    static double suspects[] = { 3.14159, 2.71828 };

    assert (quux == 0 || quux == 1);

    return suspects[quux]; 
}

extern double do_sum();

int main(int argc, char **argv)
{
    gethandynumber();
    do_sum();
}

