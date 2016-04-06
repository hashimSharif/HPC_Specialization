/*
 * This file is done by hand here, since we're writing straight to the runtime
 * API, but is generated for a UPC program by the 'upcc' linker script.  
 *
 * It contains two well-known functions which the runtime library calls in
 * order to have the allocation and initialization functions of each file in
 * the program called.  All of the allocation functions are called before the
 * initialization function, but the order in which each file's functions
 * within each category are called is arbitrary.
 *
 * See 'Allocating and Initializing Static Data in the Berkeley UPC Compiler"
 * on the UPC website for details.
 */

#include <upcr.h>
#if UPCRI_USING_PTHREADS
  GASNETT_IDENT(UPCRI_IdentString_DefaultPthreadCount, 
   "$UPCRDefaultPthreadCount: 2 $");
  
  #if UPCRI_USING_TLD
    #undef UPCR_TLD_DEFINE
    #define UPCR_TLD_DEFINE(name, size, align) extern int name;
    #define UPCR_TRANSLATOR_TLD(type, name, initval) extern type name;
    #include "global.tld"
    #include <upcr_translator_tld.h>
    #undef UPCR_TLD_DEFINE
    #undef UPCR_TRANSLATOR_TLD
  #endif /* UPCRI_USING_TLD */
  
  upcri_pthreadinfo_t*
  upcri_linkergenerated_tld_init()
  {
      struct upcri_tld_t *_upcri_p = UPCRI_XMALLOC(struct upcri_tld_t, 1);
  
  #if UPCRI_USING_TLD
    #define UPCR_TRANSLATOR_TLD(type, name, initval) memcpy(&_upcri_p->name, &name, sizeof(type));
    #include <upcr_translator_tld.h>
    #define UPCR_TLD_DEFINE(name, size, align) memcpy(&_upcri_p->name, &name, size);
    #include "global.tld"
  #endif /* UPCRI_USING_TLD */
      return (upcri_pthreadinfo_t *) _upcri_p;
  }
  
#endif /* UPCRI_USING_PTHREADS */

static
void perfile_allocs() 
{
    /* poop ! */
}

static
void perfile_inits()
{
    /* poop ! */
}

static
void static_init(void *start, uintptr_t len)
{
    UPCR_BEGIN_FUNCTION();
    /* we ignore the start/len params, since we allocate all static 
     * data off the heap */

    /* Call per-file alloc/init functions */
    perfile_allocs();

    /* Do a barrier to make sure all allocations finish, before calling
     * initialization functions.  */
    /* UPCR_SET_SRCPOS() was already done in perfile_allocs() */ ;
    upcr_notify(0, UPCR_BARRIERFLAG_ANONYMOUS);
    upcr_wait(0, UPCR_BARRIERFLAG_ANONYMOUS);

    /* now set any initial values (also for TLD) */
    perfile_inits();
}

extern void upcri_init_heaps(void *start, uintptr_t len);
extern void upcri_init_cache(void *start, uintptr_t len);

/* Magic linker variables, for initialization */
upcr_thread_t   UPCRL_static_thread_count       = 0;
uintptr_t       UPCRL_default_shared_size       = 64 << 20;
uintptr_t       UPCRL_default_shared_offset     = 0 << 20;
uintptr_t	UPCRL_default_cache_size        = 0;
int		UPCRL_attach_flags              = UPCR_ATTACH_ENV_OVERRIDE|UPCR_ATTACH_SIZE_WARN;
const char *	UPCRL_main_name;
#if UPCRI_USING_PTHREADS
upcr_thread_t   UPCRL_default_pthreads_per_node = 2;
#else
upcr_thread_t   UPCRL_default_pthreads_per_node = 0;
#endif
void (*UPCRL_pre_spawn_init)()                       = NULL;
void (*UPCRL_per_pthread_init)()                     = NULL;
void (*UPCRL_static_init)(void *, uintptr_t)         = &static_init;
void (*UPCRL_heap_init)(void * start, uintptr_t len) = &upcri_init_heaps;
void (*UPCRL_cache_init)(void *start, uintptr_t len) = &upcri_init_cache;
void (*UPCRL_mpi_init)(int *pargc, char ***pargv);
void (*UPCRL_mpi_finalize)();


int UPCRI_compiled_thread_count = 0;
const char * UPCRI_compiled_heapoffset = "0";
const char *UPCRI_compiled_sharedheapsz = "4MB"; 
GASNETT_IDENT(UPCRI_IdentString_HeapSz, 
"$UPCRDefaultHeapSizes: UPC_SHARED_HEAP_OFFSET=0 UPC_SHARED_HEAP_SIZE=4MB $");

/* strings for configuration consistency checks */
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


/* linker config strings */
GASNETT_IDENT(UPCRI_IdentString_link_GASNetConfig, 
 "$GASNetConfig: (<link>) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_link_UPCRConfig,
 "$UPCRConfig: (<link>) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_link_upcver, 
 "$UPCVersion: (<link>) 1.0.1 $");
GASNETT_IDENT(UPCRI_IdentString_link_compileline, 
 "$UPCCompileLine: (<link>) [hand-linked test executable] $");

/* The main() event */
extern int user_main(int, char**);
const char * UPCRL_main_name = "user_main";

int main(int argc, char **argv)
{
    bupc_init_reentrant(&argc, &argv, &user_main);
    return 0;
}

