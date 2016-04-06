#include &lt;upcr.h&gt;

/************************************************
 * declarations from foobar.uph 
 ************************************************/

extern int quux; /* no special syntax needed for extern definition of a
		    thread-local variable */

/* definitions of shared variables replaced with proxy pointers with the same
 * name */
upcr_pshared_ptr_t foo;		/* tentative definitions */
upcr_pshared_ptr_t bar;


/************************************************
 * Thread-local variables 
 ************************************************/

/* pquux requires special treatment in initialization function 
 * below, since '&amp;quux' is different for different threads 
 */
int *
UPCR_TLD_DEFINE(pquux, 4) = &amp;quux;

/* pfoo also requires special treatment, since the memory it points to isn't
 * allocated until startup
 */
upcr_pshared_ptr_t
UPCR_TLD_DEFINE(pfoo, 4) = UPCR_INITIALIZED_PSHARED;


/***********************************************************************
 * Function-scope static shared variables 
 * - Proxy pointer used, and is static, but promoted to file scope
 * - Function name added to proxy pointer name to avoid name conflicts 
 ***********************************************************************/
static upcr_shared_ptr_t do_sum_messy = UPCR_INITIALIZED_SHARED;



/**************************************
 * Functions
 **************************************/

double do_sum() {
    UPCR_BEGIN_FUNCTION();
    /* 'messy' moved to file scope, so init function can see it */
    double total;
    int i, j;

    for (i = 0; i < 16; i++)
	for (j = 0; j < upcr_threads(); j++) {
	    double tmp;
	    upcr_get_shared(&amp;tmp, do_sum_messy, 
			    sizeof(double)*(16*i + j), 
			    sizeof(double));
	    total += tmp;				     
	}
    return total;
}


/************************************************
* Startup allocation function
************************************************/

void UPCRI_ALLOC_bar_MANGLE123 (void)
{
    UPCR_BEGIN_FUNCTION();

    upcr_startup_pshalloc_t pinfos[] = {
	{ &amp;foo, sizeof(int), 1, 0 },
	{ &amp;bar, sizeof(int), 1, 0 }
    };

    upcr_startup_shalloc_t infos[] = {
	{ &amp;do_sum_messy, 3*sizeof(double), 16*4*sizeof(double), 1 }
    };

    /* Allocate shared data */
    upcr_startup_pshalloc(pinfos,
	sizeof(pinfos) / sizeof(upcr_startup_pshalloc_t));
    upcr_startup_shalloc(infos,
	sizeof(infos) / sizeof(upcr_startup_shalloc_t));
}

/************************************************
* Startup initialization function 
************************************************/

void UPCRI_INIT_bar_MANGLE123 (void)
{
    UPCR_BEGIN_FUNCTION();

    /*************************************************
     * Initialize shared data 
     *************************************************/

    /* No thread0-specific shared initializations in this file */

    /* Have each UPC thread initialize its part of striped array */
    {	
	double init_messy[1][5] = { { 1, 2, 3, 4, 5 } };
	upcr_startup_arrayinit_diminfo_t init_messy_info[] = {
	    { 1, 16, 0 },
	    { 5, 4,  1 }
	};
	upcr_startup_initarray(do_sum_messy, init_messy, 
			       init_messy_info, 2, 
			       sizeof(double), 3);
    }

    /*************************************************
     * Initialize thread-local data
     *************************************************/

    (*((int**)UPCR_TLD_ADDR(pquux))) = UPCR_TLD_ADDR(quux);
    (*((upcr_pshared_ptr_t*)UPCR_TLD_ADDR(pfoo))) = foo;
}

