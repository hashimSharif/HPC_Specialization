#include "upcr.h" /* MUST come first */
#include <stdio.h>
#include <limits.h>

int user_main(int argc, char **argv)
{ UPCR_BEGIN_FUNCTION();
    uintptr_t blocks = 4;
    uintptr_t blocksz = 512;
    uintptr_t total = 0;

    upcri_barprintf("I'm gonna grab memory until I blow myself up (tee hee!)\n");

    for (;;) {
	upcr_shared_ptr_t sp;

	total += blocks*blocksz;
	upcri_barprintf("%i: allocating %lu * %lu-byte blocks = %lu bytes (total=%lu MB)\n", 
                (int)upcr_mythread(),
		(unsigned long)blocks, 
                (unsigned long)blocksz, 
                (unsigned long)blocks*blocksz, 
                (unsigned long)total/(1024*1024));
	sp = upcr_all_alloc(blocks, blocksz);
	blocks <<= 1;
	if (blocks > UINT_MAX)
	    blocks = UINT_MAX;


    }
    printf("ERROR\n"); /* test is expected to fail.. */
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
