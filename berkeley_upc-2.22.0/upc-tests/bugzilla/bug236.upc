#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <upc.h>

/*
 * Bug 236 (and 617)
 *
 * Make sure references to stdout/stderr are working (have been broken on
 * Tru64 and the OSX, where they translate into array references).
 */

int main(int argc, char **argv)
{
    fprintf(stdout, 
	    "SUCCESS: if this broke, it would have been at compile time\n"); 

    fprintf(stderr, 
	    "SUCCESS: if this broke, it would have been at compile time\n"); 

    return 0;
}


