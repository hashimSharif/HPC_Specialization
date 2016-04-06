#include "foobar.uph"

      
int * pquux = &quux;
shared int * pfoo = &foo;


double do_sum() {
    /**********************************
     * Shared static variable
     **********************************/
    static shared [3] double messy[16][4*THREADS] 
	= { { 1, 2, 3, 4, 5 } };
    double total;
    int i, j;

    for (i = 0; i < 16; i++)
	for (j = 0; j < THREADS; j++)
	    total += messy[i][j];
    
    return total;
}

