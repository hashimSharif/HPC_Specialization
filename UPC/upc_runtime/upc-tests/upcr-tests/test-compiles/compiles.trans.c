#include "upcr.h" /* MUST come first */
#include <stdio.h>

int32_t UPCR_TLD_DEFINE(bar, 4, 4) = 5;

int user_main(int argc, char **argv)
{
    printf("The UPC runtime compiles OK (what more do you want?)\n");
    printf("done.\n");
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

