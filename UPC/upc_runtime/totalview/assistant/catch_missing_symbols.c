/*
 * Test program for Totalview assistant library.
 *
 * Make sure that there are no undefined symbols in the assistant library that
 * would cause it to fail when linked (by this program) or loaded (by
 * Totalview's dlopen()).
 */

#include "bupc_assistant.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int (*P_uda_index_pts) (uda_thread *thr,
			uda_debugger_pts *p,
			uda_tword blocksize,
			uda_tword element_size, 
			uda_tword upc_threads, uda_tword delta);

int main(int argc, char **argv)
{
    /* use a symbol from the lib, to ensure we link the assistant library's
     * symbols in (there's only one object file in the library, so this should
     * slurp */
    P_uda_index_pts = &uda_index_pts;
    printf("If this linked, we're good\n");

    return 0;
}


