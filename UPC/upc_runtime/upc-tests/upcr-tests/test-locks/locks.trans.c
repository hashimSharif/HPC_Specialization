#include "upcr.h" /* MUST come first */
#include <stdio.h>

int user_main(int argc, char **argv)
{ UPCR_BEGIN_FUNCTION();
    upcr_shared_ptr_t lock, datum;
    int i = 0;

    upcri_barprintf("%i: Allocating lock with upcr_global_lock_alloc\n", (int)upcr_mythread());
    lock = upcr_all_lock_alloc();
    upcri_barprintf("%i: OK\n", (int)upcr_mythread());

    upcri_barprintf("%i: Allocating datum\n", (int)upcr_mythread());
    datum = upcr_all_alloc(1, sizeof(int));
    /* Thread 0 inits to 0 */
    if (upcr_mythread() == 0)
	upcr_put_shared(datum, 0, &i, sizeof(int));
    upcri_barprintf("%i: OK\n", (int)upcr_mythread());

    for (i = 0; i < upcr_threads(); i++) {
	if (upcr_mythread() == i) {
	    int val;
	    upcr_lock(lock);
	    upcr_get_shared(&val, datum, 0, sizeof(int));
	    val++;
	    upcr_put_shared(datum, 0, &val, sizeof(int));
	    upcri_sleepprintf("%i: got lock, incremented datum from %d to %d, and unlocked\n", 
		    (int)upcr_mythread(), val-1, val);
	    upcr_unlock(lock);
	}
    }

    upcri_barprintf("done.\n");
    return 0;
}

#ifdef __BERKELEY_UPC_RUNTIME__
/* strings for upcc configuration consistency checks */
/* UPC Runtime specification expected: 3.0 */
GASNETT_IDENT(UPCRI_IdentString_foo_upc_1053613370_GASNetConfig_gen,
 "$GASNetConfig: (foo.upc.w2c.c) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_foo_upc_1053613370_UPCRConfig_gen,
 "$UPCRConfig: (foo.upc.w2c.c) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_foo_upc_1053613370_GASNetConfig_obj,
 "$GASNetConfig: (foo.o) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_foo_upc_1053613370_UPCRConfig_obj,
 "$UPCRConfig: (foo.o) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_foo_upc_1053613370_translator,
 "$UPCTranslator: (foo.o) [written by hand for upcr interface] $");
#else
/* not using upcc - simulate it */
#include "commonlink.c"
#endif

