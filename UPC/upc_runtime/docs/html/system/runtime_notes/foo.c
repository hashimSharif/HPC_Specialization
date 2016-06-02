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
 * Proxy pointers to shared variables
 ************************************************/

/* explicit definition overrides above tentative definition */
upcr_pshared_ptr_t foo = UPCR_INITIALIZED_PSHARED; 

upcr_pshared_ptr_t pbar = UPCR_INITIALIZED_PSHARED;


/************************************************
 * Thread-local variables 
 ************************************************/

int 
UPCR_TLD_DEFINE_TENTATIVE(quux, 4);

/* Use typedef for array. Also, move static to global scope, 
 * and mangle name to avoid name collisions.  */
typedef double _type_suspects_MANGLED[2];

_type_suspects_MANGLED 
UPCR_TLD_DEFINE(suspects_MANGLED, 8) = { 3.14159, 2.71828 };


/**************************************
 * Functions
 **************************************/

double gethandynumber() {
    UPCR_BEGIN_FUNCTION();
    /* declaration of static 'suspects' moved to global, 
     * unstatic scope */

    assert( *((int*)UPCR_TLD_ADDR(quux)) == 0
	 || *((int*)UPCR_TLD_ADDR(quux)) == 1);

    return ((double*)UPCR_TLD_ADDR(suspects_MANGLED))[*((int*)UPCR_TLD_ADDR(quux))];
}

extern double do_sum();

/************************************************
 * UPC compiler must rename 'main' to 'user_main'
 ************************************************/

int user_main(int argc, char **argv)
{
    UPCR_BEGIN_FUNCTION();
    double trouble;
    int checkval;
    upcr_pshared_ptr_t ptmp;

    gethandynumber();
    do_sum();

    return 0;
}

/************************************************
 * Allocate/init shared variables.
 * -- run once on each node
 ************************************************/

void UPCRI_ALLOC_foo_MANGLE123 (void)
{
    UPCR_BEGIN_FUNCTION();

    upcr_startup_pshalloc_t pinfos[] = {
	{ &amp;foo,  sizeof(int), 1, 0  },
	{ &amp;pbar, sizeof(upcr_pshared_ptr_t), 1, 0 },
	{ &amp;bar,  sizeof(int), 1, 0 }
    };

    /* Allocate shared data */
    upcr_startup_pshalloc(pinfos, 
	sizeof(pinfos)/sizeof(upcr_startup_pshalloc_t));

}

/************************************************
 * Initialization function for TLD variables
 * -- run once per pthread per node.
 ************************************************/

void UPCRI_INIT_foo_MANGLE123 (void)
{
    UPCR_BEGIN_FUNCTION();

    /*************************************************
     * Initialize shared data 
     *************************************************/

    /* Explicit initializations of variables living only 
     * on UPC thread 0 
     */
    if (upcr_mythread() == 0) {
       *((int*)upcr_pshared_to_local(foo)) = 3;
       *((upcr_pshared_ptr_t*)upcr_pshared_to_local(pbar)) = bar;
    } 

    /* No striped arrays to initialize in this file */

    /*************************************************
     * Initialize thread-local data
     *************************************************/

    /* Both quux and suspects_MANGLED_123 are initialized 
     * satisfactorily by runtime: no special logic needed here
     */
}


