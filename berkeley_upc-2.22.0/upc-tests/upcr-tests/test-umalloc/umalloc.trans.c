#include "upcr.h" /* MUST come first */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <umalloc.h>

int _sizes[] = { 3, 1024, 100000, 1024, 42000, 350, 100, 80, 
	        3,3,3,3,3,3,3,3,3,3,3,3,3,50,
		2049, 4097, 9, 33, 9, 33, 9, 78934, 38496 };

/* Other size test arrays which may be interesting */
/*
  int _sizes[] = { 1024, 100000, 1024, 3 };
  int _sizes[] = { 7, 120546, 32165, 150, 7, 4097, 150, 7, 150, 7 };
  int _sizes[] = { 150, 7, 4097, 150, 7, 150, 7, 7, 120546, 32165 };
 */

#define HEAP_SIZE   (1024*1024) /* Must be larger than the sum of all _sizes in size[] */
#define SIZES_ITERS (1000000)
#define SIZES_NUM   (sizeof _sizes / sizeof _sizes[0])

#define UMALLOC_PAGESIZE 4096

int verbose = 0;

   
void
sizes_test(umalloc_heap_t *pheap, int heapsize, int iters)
{
    int i, j, start, k;
    void *allocs[SIZES_NUM];
    uintptr_t	totsz = 0;

    for (i = 0; i < iters; i++) {

	/* Allocate from size array in jumbled order */
	start = i % SIZES_NUM;

	for (j = 0; j < SIZES_NUM; j++) {
	    k = (start + j) % SIZES_NUM;
	    totsz += _sizes[k];
	    allocs[j] = umalloc(pheap, _sizes[k]);
	    if (verbose)
		printf(">>>> malloc(%d) = %p\n", _sizes[k], allocs[j]);
	    if (allocs[j] == NULL) { 
		fprintf(stderr, "ERROR Ran out of memory after %d allocations "
				"(heapsize=%d,alloc'd=%lu,requested=%d)\n",
				j, heapsize, (unsigned long)totsz, _sizes[k]);
		abort();
	    } 
	}

	/* Deallocate from size array in order */
	for (j = 0; j < SIZES_NUM; j++) {
	    k = (start + j) % SIZES_NUM;
	    if (verbose)
		printf("\n>>>> free(%p,%d)\n", allocs[j], _sizes[k]);
	    ufree(pheap, allocs[j]);
	}
	totsz = 0;
    }
    return;
}

void
twoheap_sizes_test(umalloc_heap_t *upheap, umalloc_heap_t *downheap, int iters, unsigned int seed)
{
    unsigned short rand_state[3];
    void      *allocs[SIZES_NUM*2];
    int	       allocwhich[SIZES_NUM*2];
    int	       which;
    int	       i, j, k;
    int	       start;

    umalloc_heap_t  *heapptr[2];
    const char	    *heapname[] = { "growup  ", "growdown" };

    heapptr[0] = upheap;
    heapptr[1] = downheap;

    memset(rand_state, 0, 3*sizeof(short));
    memcpy(rand_state, &seed, MIN(sizeof(seed), 3*sizeof(short)));

    for (i = 0; i < iters; i++) {
	int        allocnum[2] = { 0, 0 };
	int        sz;
	uintptr_t  totsz[2] = { 0, 0 };

	start = i % SIZES_NUM;

	for (j = 0; j < SIZES_NUM*2; j++) {
	    /* what size are we allocating */
	    k = (start + j) % SIZES_NUM;
	    sz = _sizes[k];

	    /* find out what heap we will be allocating from */
	    which = nrand48(rand_state) % 2;

	    /* switch heap if we are out of allocations on one of them */
	    if (allocnum[which] >= SIZES_NUM)
		which = 1 - which;
	    allocwhich[j] = which;

	    totsz[which] += sz;
	    allocs[j] = umalloc(heapptr[which], sz);
	    if (allocs[j] == NULL) {
		fprintf(stderr, "ERROR Unable to allocate %d bytes for %s heap "
				"(alloc'd %s=%lu, %s=%lu bytes).\n",
				sz, heapname[which], heapname[which],
				(unsigned long) totsz[which], heapname[1-which], 
                                (unsigned long) totsz[1-which]);
		abort();
	    }
	    allocnum[which]++;
	}

	for (j = 0; j < SIZES_NUM*2; j++) {
	    ufree(heapptr[allocwhich[j]], allocs[j]);
	}
    }
}

void
limit_test(umalloc_heap_t *pheap, int heapsize)
{
    char *test1, *test2, *test3;

    test1 = umalloc(pheap, heapsize/4);
    if (!test1) { 
	fprintf(stderr, "> ERROR umalloc fails to allocate 1/4 the heap!\n");
	exit(-1);
    }
    printf("> Allocated 1/4 the heap: got addr=%p\n", test1);

    test2 = umalloc(pheap, heapsize/4);
    if (!test2) { 
	fprintf(stderr, "ERROR umalloc fails to allocate 1/2 the heap!\n");
	exit(-1);
    }
    printf("> Allocated 1/4 the heap: got addr=%p\n", test2);

    test3 = umalloc(pheap, heapsize/2 + 1);
    if (test3) { 
	fprintf(stderr, "ERROR umalloc should have failed!\n");
	exit(-1);
    }
    printf("> Failed to allocate 100%%+1 of the heap (good)\n");

    /* If we free previous allocations, should work now */
    ufree(pheap, test1);
    ufree(pheap, test2);

    test3 = umalloc(pheap, heapsize/2 + 1);
    if (!test3) { 
	fprintf(stderr, "> ERROR Alloc should have worked after ufree!\n");
	exit(-1);
    }
    printf("> Got 1/2 of heap after ufree; addr=%p\n", test3);

    test1 = umalloc(pheap, heapsize/2);
    if (test1) { 
	fprintf(stderr, "> ERROR umalloc should have failed!\n");
	exit(-1);
    }
    printf("> Failed to allocate 100%%+ again (good)\n");

    /* Should work after we double heap size */
    umalloc_provide_pages(pheap, heapsize);
    test2 = umalloc(pheap, heapsize/2);
    if (!test2) { 
	fprintf(stderr, "> ERROR umalloc should have worked after provide_pages!\n");
	exit(-1);
    }
    printf("> Allocation of 100%%+ of orig. heap OK after doubling heap size\n");
    /* Free heaps before continuing */
    ufree(pheap, test1);
    ufree(pheap, test2);
}


int user_main(int argc, char **argv)
{ UPCR_BEGIN_FUNCTION();
    int id = upcr_mythread();
    umalloc_heap_t *pheap_down, *pheap_up;
    size_t twoheapsz = HEAP_SIZE*2;
    char * area;
    int iters = SIZES_ITERS;
    unsigned long seed;
    int heapsize = sizeof(char) * 2 * twoheapsz;

    if (argc > 1) iters = atoi(argv[1]);
    seed = id + ((argc > 2) ? atoi(argv[2]) : time(NULL));

    /* umalloc requires that this area be aligned to a 4096 byte
       boundary */
    area = (char *)UPCRI_ALIGNUP(malloc(heapsize + UMALLOC_PAGESIZE), UMALLOC_PAGESIZE);

    if (!area) {
	fprintf(stderr, "ERROR Malloc failed!\n");
	exit(-1);
    }

    printf("Got heap area at addr=%p-%p of size %lu\n", 
           area, area + (2*twoheapsz) - 1, (unsigned long)twoheapsz * 2);

    /* Sanity test, pretty average test since there is usually some waste in
     * every heap allocator */
    {
	size_t totsz = 0;
	int i;
	for (i = 0; i < SIZES_NUM; i++) 
	    totsz += _sizes[i];
	if (totsz > HEAP_SIZE) {
	    fprintf(stderr, 
		"ERROR fatal test parameters: sum of sizes larger than heapsize\n");
	    return 1;
	}
    }

    pheap_up = umalloc_makeheap(area, HEAP_SIZE, UMALLOC_HEAP_GROWS_UP);
    pheap_down = umalloc_makeheap(area+2*twoheapsz-1, HEAP_SIZE, UMALLOC_HEAP_GROWS_DOWN);

    printf("\n%i: Running limit test on growup   heap\n", id); fflush(stdout);
    limit_test(pheap_up, HEAP_SIZE);

    printf("\n%i: Running limit test on growdown heap\n", id); fflush(stdout);
    limit_test(pheap_down, HEAP_SIZE);

    printf("\n%i: Running sizes test on growup   heap with %d iterations\n", id, iters); fflush(stdout);
    sizes_test(pheap_up, HEAP_SIZE, iters);

    printf("\n%i: Running sizes test on growdown heap with %d iterations\n", id, iters); fflush(stdout);
    sizes_test(pheap_down, HEAP_SIZE, iters);

    printf("\n%i: Running two-heap concurrent sizes test with %d iterations (seed %lu)\n", id, iters, seed); fflush(stdout);
    twoheap_sizes_test(pheap_up, pheap_down, iters, seed);

    
    printf("%i: All tests passed\n", id); fflush(stdout);
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

