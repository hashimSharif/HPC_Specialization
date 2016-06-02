#include <upcr.h>
#include <assert.h>

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

    /* 
     * Verify results 
     */

    /* Check for bar == 0 (tentative defs must work) */
    upcr_get_pshared(&checkval, bar, 0, sizeof(int));
    if (checkval == 0) {
	upcri_barprintf("bar=0 (good)");
    } else {
	upcri_barprintf("bar=%d (WRONG!)", checkval);
    }

    /* Check that quux is 0, and TLD_ADDR is working */
    trouble = gethandynumber();
    if (trouble == 3.14159) {
	upcri_sleepprintf("gethandynumber returned Pi (good)");
    } else { 
	upcri_sleepprintf("gethandynumber returned %f (BAD)", trouble);
    }

    /* foo == 3 (init function must have been called, and network gets must be
     * working */
    upcr_get_pshared(&checkval, foo, 0, sizeof(int));
    if (checkval == 3)
	upcri_barprintf("foo=3 (good)");
    else
	upcri_barprintf("foo=%d (WRONG!)", checkval);
    
    /* See that assignment of shared ptr address, and defererence work */
    upcr_get_pshared(&ptmp, pbar, 0, sizeof(upcr_pshared_ptr_t));
    upcr_get_pshared(&checkval, ptmp, 0, sizeof(int));
    if (checkval == 0) {
	upcri_barprintf("*pbar=0 (good)");
    } else {
	upcri_barprintf("*pbar=%d (WRONG!)", checkval);
    }

    /* For yucks, assign pbar = &foo, and check it, too */
    if (upcr_mythread() == 1) {
	upcr_put_pshared(pbar, 0, &foo, sizeof(upcr_pshared_ptr_t));
    }
    upcri_barprintf("Thread 2 assigned pbar=&foo");
    upcr_get_pshared(&ptmp, pbar, 0, sizeof(upcr_pshared_ptr_t));
    upcr_get_pshared(&checkval, ptmp, 0, sizeof(int));
    if (checkval == 3) {
	upcri_barprintf("*pbar=3 (good)");
    } else {
	upcri_barprintf("*pbar=%d (WRONG!)", checkval);
    }

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
	{ &foo,  sizeof(int), 1, 0  },
	{ &pbar, sizeof(upcr_pshared_ptr_t), 1, 0 },
	{ &bar,  sizeof(int), 1, 0 }
    };

/*    upcri_barprintf("foo_alloc: foo=%P, bar=%P\n", &foo, &bar); */

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
     * satisfactorily by runtime.
     */
}


