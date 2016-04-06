#define UPCRI_BUILDING_LIBUPCR 1  /* tests internal functionality, eg upcri_shared_to_remote */
#include "upcr.h" /* MUST come first */
/***************************************************************************** 
 * Correctness tests for shared pointer arithmetic.
 *
 * We use a rather elaborate setup, but it has the advantages that all types
 * of pointers can share most of the logic, and you can add test cases just by
 * defining a few structs.
 *****************************************************************************/

#include <stdio.h>

/***************************************************************************** 
 * Abstract function pointer type for performing shared ptr arithmetic.
 *****************************************************************************/

typedef upcr_shared_ptr_t 
(*add_func) (upcr_shared_ptr_t sptr, size_t elemsz, ptrdiff_t inc, 
	       size_t blockelems);

/* Same, but for functions that modify ptr in place */
typedef void 
(*inc_func) (upcr_shared_ptr_t *sptr, size_t elemsz, ptrdiff_t inc, 
		   size_t blockelems);

/* pointer subtraction */
typedef ptrdiff_t 
(*sub_func)(upcr_shared_ptr_t sptr1, upcr_shared_ptr_t sptr2, size_t elemsz, 
	    size_t blockelems);

/* Same as above two, but for phaseless pointers */

typedef upcr_pshared_ptr_t 
(*padd_func) (upcr_pshared_ptr_t sptr, size_t elemsz, ptrdiff_t inc);

typedef void 
(*pinc_func) (upcr_pshared_ptr_t *psptr, size_t elemsz, ptrdiff_t inc);

typedef ptrdiff_t 
(*psub_func) (upcr_pshared_ptr_t sptr1, upcr_pshared_ptr_t sptr2, 
	      size_t elemsz);

/*****************************************************************************
 * Since the various shared pointer arithmetic functions are all inline, we
 * need to make wrappers for them, so we can use function pointers.
 *****************************************************************************/

static upcr_shared_ptr_t 
wrap_upcr_add_shared(upcr_shared_ptr_t sptr, size_t elemsz, ptrdiff_t inc, 
		     size_t blockelems)
{
    UPCR_BEGIN_FUNCTION();
    return upcr_add_shared(sptr, elemsz, inc, blockelems);
}

static void 
wrap_upcr_inc_shared(upcr_shared_ptr_t *psptr, size_t elemsz, ptrdiff_t inc, 
		     size_t blockelems)
{
    UPCR_BEGIN_FUNCTION();
    upcr_inc_shared(psptr, elemsz, inc, blockelems);
}

static ptrdiff_t 
wrap_upcr_sub_shared(upcr_shared_ptr_t sptr1, upcr_shared_ptr_t sptr2, 
		size_t elemsz, size_t blockelems)
{
    return upcr_sub_shared(sptr1, sptr2, elemsz, blockelems);
}

/* Indefinite phaseless ptr functions */

static upcr_pshared_ptr_t
wrap_upcr_add_psharedI(upcr_pshared_ptr_t sptr, size_t elemsz, ptrdiff_t inc)
{
    return upcr_add_psharedI(sptr, elemsz, inc);
}

static void 
wrap_upcr_inc_psharedI(upcr_pshared_ptr_t *psptr, size_t elemsz, ptrdiff_t inc)
{
    upcr_inc_psharedI(psptr, elemsz, inc);
}

static ptrdiff_t 
wrap_upcr_sub_psharedI(upcr_pshared_ptr_t sptr1, upcr_pshared_ptr_t sptr2, 
		  size_t elemsz)
{
    return upcr_sub_psharedI(sptr1, sptr2, elemsz);
}

/* blocksz==1 phaseless ptr functions */

static upcr_pshared_ptr_t
wrap_upcr_add_pshared1(upcr_pshared_ptr_t sptr, size_t elemsz, ptrdiff_t inc)
{
    return upcr_add_pshared1(sptr, elemsz, inc);
}

static void
wrap_upcr_inc_pshared1(upcr_pshared_ptr_t *psptr, size_t elemsz, ptrdiff_t inc)
{
    upcr_inc_pshared1(psptr, elemsz, inc); 
}

static ptrdiff_t 
wrap_upcr_sub_pshared1(upcr_pshared_ptr_t sptr1, upcr_pshared_ptr_t sptr2, 
		  size_t elemsz)
{
    return upcr_sub_pshared1(sptr1, sptr2, elemsz);
}


/*****************************************************************************
 * Test structures
 *****************************************************************************/

/* Test operation:  amount to increment previous ptr by, and correct result */
typedef struct {
				/*** OPERATION ***/
    ptrdiff_t inc;			/* Amount to increment previous pointer by */
				/*** INFO TO VERIFY RESULT    ***/
    uintptr_t cor_off;		/* Correct result address, as element offset from start 
				   i.e. result.addr - (addr_off*elemsz) = start) */
    unsigned short cor_thread;	/* Correct result thread */
    unsigned short cor_phase;	/* Correct result phase */

    const char * desc;
} test_op;

/* Generic test type */
typedef struct {
    void	*add_func;	/* Pointer to shared ptr addition function */
    const char	*add_name;	/*     -- name of the function */ 
    void	*inc_func;	/* '_inc' version of addition function */
    const char	*inc_name;	/*     -- name of the function */ 
    void	*sub_func;	/* pointer subtraction function */
    const char	*sub_name;	/*     -- name of the function */ 
    int is_phaseless;		/* If test uses phaseless pointers */
} test_type; 

/* Per-test info: test type, data type, and blocking */
typedef struct {
    ssize_t elemsz;		/* sizeof element type (int, etc.) */
    ssize_t blockelems;		/* Number of elements per block */
    ssize_t nblocks;		/* Number of blocks needed for test */
    test_type * type;		/* Type of function and sptr used */
} test_info;

/*****************************************************************************
 * Predefined test types 
 *****************************************************************************/

#define TYPE_FUNC(func)  (void *)&wrap_##func, #func

test_type type_phased= { 
    TYPE_FUNC(upcr_add_shared), 
    TYPE_FUNC(upcr_inc_shared), 
    TYPE_FUNC(upcr_sub_shared), 
    0 
}; 

test_type type_indef = { 
    TYPE_FUNC(upcr_add_psharedI), 
    TYPE_FUNC(upcr_inc_psharedI),
    TYPE_FUNC(upcr_sub_psharedI), 
    1 
}; 

test_type type_phase1= { 
    TYPE_FUNC(upcr_add_pshared1), 
    TYPE_FUNC(upcr_inc_pshared1), 
    TYPE_FUNC(upcr_sub_pshared1), 
    1 
}; 


/*****************************************************************************
 * THE TESTS
 *
 * Just add a new testN_info and testN_ops to add a new test (and add a
 * RUN_TEST(N) in user_main(), below).
 *
 * NOTE: these tests rely on the data being laid out across 4 UPC threads. We
 * enforce this requirement in user_main().
 *****************************************************************************/

/* Test general purpose phased pointers */ 
test_info test1_info = { sizeof(int), 3, 72, &type_phased };
test_op test1_ops[] = {
    /* inc	cor_off	    cor_thread	cor_phase   desc	    * 
     * ---	-------     ----------  ---------   -------------   */
    {  0,	0,	    0,		0,    	    "from 0 to 0" },
    {  3,	0,	    1,		0,    	    "from 0 to 3" },
    {  4,	1,	    2,		1,    	    "from 3 to 7" },
    {  4,	2,	    3,		2,    	    "from 7 to 11" },
    {  0,	2,	    3,		2,    	    "from 11 to 11" },
    {  1,	3,	    0,		0,    	    "from 11 to 12" },
    {  12,	6,	    0,		0,    	    "from 12 to 24" },
    {  4,	7,	    1,		1,    	    "from 24 to 28" },
    { -2,	8,	    0,		2,    	    "from 28 to 26" },
    { -26,	0,	    0,		0,    	    "from 26 to 0" },
    {  15,	3,	    1,		0,    	    "from 0 to 15" },
    { -14,	1,	    0,		1,    	    "from 15 to 1" },
    {  32,	6,	    3,		0,    	    "from 1 to 33" },
    { -23,	1,	    3,		1,    	    "from 33 to 10" },
    { -10,	0,	    0,		0,    	    "from 10 to 0" },
    {  13,	4,	    0,		1,    	    "from 0 to 13" },
    {  -1,	3,	    0,		0,    	    "from 13 to 12" },
    { -12,	0,	    0,		0,    	    "from 12 to 0" },
    {  71,	17,	    3,		2,    	    "from 0 to 71" },
    { -68,	0,	    1,		0,    	    "from 71 to 3" }
};

struct mcfoobar {
    long mc;
    char foo;
    char bar;
};

test_info test2_info = { sizeof(struct mcfoobar), 5, 100, &type_phased };
test_op test2_ops[] = {
    /* inc	cor_off	    cor_thread	cor_phase   desc	    * 
     * ---	-------     ----------  ---------   -------------   */
    {  0,	0,	    0,		0,    	    "from 0 to 0" },
    {  1,	1,	    0,		1,    	    "from 0 to 1" },
    { -1,	0,	    0,		0,    	    "from 1 to 0" },
    { 12,	2,	    2,		2,    	    "from 0 to 12" },
    {-11,	1,	    0,		1,    	    "from 12 to 1" },
    { 43,	14,	    0,		4,    	    "from 1 to 44" },
    { 55,	24,	    3,		4,    	    "from 44 to 99" },
    {-92,	2,	    1,		2,    	    "from 99 to 7" },
    {  6,	3,	    2,		3,    	    "from 7 to 13" },
    {  9,	7,	    0,		2,    	    "from 13 to 22" },
    { 23,	10,	    1,		0,    	    "from 22 to 45" },
    { -4,	11,	    0,		1,    	    "from 45 to 41" },
    { -7,	9,	    2,		4,    	    "from 41 to 34" },
    {  2,	6,	    3,		1,    	    "from 34 to 36" }
};



/* Tests indefinitely blocked shared pointer arithmetic */
test_info test3_info = { sizeof(long), 100, 100, &type_indef};
test_op test3_ops[] = {
    /* inc	cor_off	    cor_thread	cor_phase   desc	    * 
     * ---	-------     ----------  ---------   -------------   */
    {  0,	0,	    0,		0,    	    "from 0 to 0" },
    {  1,	1,	    0,		0,    	    "from 0 to 1" },
    { -1,	0,	    0,		0,    	    "from 1 to 0" },
    { 99,	99,	    0,		0,    	    "from 0 to 99" },
    {-68,	31,	    0,		0,    	    "from 99 to 31" },
    { 34,	65,	    0,		0,    	    "from 31 to 65" },
    {-12,	53,	    0,		0,    	    "from 65 to 53" },
    {  6,	59,	    0,		0,    	    "from 53 to 59" },
    {-42,	17,	    0,		0,    	    "from 59 to 17" },
    { 23,	40,	    0,		0,    	    "from 17 to 40" },
    {-40,	0,	    0,		0,    	    "from 40 to 0" },
    { 77,	77,	    0,		0,    	    "from 0 to 77" },
    {  0,	77,	    0,		0,    	    "from 77 to 77" },
    {-12,	65,	    0,		0,    	    "from 77 to 65" },

};

/* Tests indefinitely blocked shared pointer arithmetic */
test_info test4_info = { sizeof(long), 100, 100, &type_phase1};
test_op test4_ops[] = {
    /* inc	cor_off	    cor_thread	cor_phase   desc	    * 
     * ---	-------     ----------  ---------   -------------   */
    {  0,	0,	    0,		0,    	    "from 0 to 0" },
    {  1,	0,	    1,		0,    	    "from 0 to 1" },
    { -1,	0,	    0,		0,    	    "from 1 to 0" },
    {  4,	1,	    0,		0,    	    "from 0 to 4" },
    { 19,	5,	    3,		0,    	    "from 4 to 23" },
    {-17,	1,	    2,		0,    	    "from 23 to 6" },
    { 18,	6,	    0,		0,    	    "from 6 to 24" },
    {-20,	1,	    0,		0,    	    "from 24 to 4" },
    { 95,	24,	    3,		0,    	    "from 4 to 99" },
    { 0,	24,	    3,		0,    	    "from 99 to 99" },
    {-96,	0,	    3,		0,    	    "from 99 to 3" }
};


/*****************************************************************************
 * Test framework functions.
 *****************************************************************************/

int do_verbose = 0;

GASNETT_FORMAT_PRINTF(verbose,1,2,
void verbose(const char *msg, ...)) {
    va_list args;
    char buf[1000];
    
    if (do_verbose) {
	va_start(args, msg);
	vsprintf(buf, msg, args);
	va_end(args);

	printf(buf);
	fflush(stdout);
    }
}

int checkresult(int testnum, int opnum, const char *func, test_info *info, 
		test_op *op, ptrdiff_t res_offbytes, size_t res_thread, 
		size_t res_phase)
{
    ptrdiff_t cor_offbytes = op->cor_off * info->elemsz;
    int badoffset = 0;
    int badthread = 0;
    int badphase = 0;

    if (res_offbytes != cor_offbytes) 
	badoffset = 1;
    if (res_thread != op->cor_thread)
	badthread = 1;
    if (!info->type->is_phaseless && (res_phase != op->cor_phase) )
	badphase = 1;

    if (badoffset || badthread || badphase) {
	fprintf(stderr, "  op %2d  [ %-14s ]:  %s()  ERROR\n", opnum, op->desc, func);
	if (badoffset)
	    fprintf(stderr, "    --offset was %ld elements (%ld bytes) instead of %ld (%ld)\n",
		    (long)res_offbytes/info->elemsz, (long)res_offbytes, 
		    (long)op->cor_off, (long)cor_offbytes);
	if (badthread)
	    fprintf(stderr, "    --thread was %lu instead of %lu\n", (unsigned long)res_thread, 
		    (unsigned long)op->cor_thread);
	if (badphase)
	    fprintf(stderr, "    --phase was %lu instead of %lu\n", (unsigned long)res_phase, 
		    (unsigned long)op->cor_phase);
	return -1;
    }

    return 0;
}

int runtest(int testnum, test_info *info, test_op *ops, int opcount)
{
    UPCR_BEGIN_FUNCTION();
    upcr_shared_ptr_t start;
    int i, errs = 0;
    ptrdiff_t subval;		/* for testing subtraction */
    void **baseaddr = upcri_malloc(upcr_threads()*sizeof(void *));

    /* Note: For now, phaseless tests must ensure that the blocksize they pass
     * is at least as large as the total allocation size */
    start = upcr_global_alloc(info->nblocks, info->blockelems * info->elemsz);
    if (upcr_isnull_shared(start)) {
	fprintf(stderr, "upcr_global_alloc failed to allocate memory for test\n");
	return -1;
    }

    for (i=0; i < upcr_threads(); i++) { 
     /* save the starting address of data on each thread, 
        to handle unaligned data segments */
      baseaddr[i] = upcri_shared_to_remote_withthread(start, i);
    }

    verbose("Test %d: %s/%s/%s\n", testnum, info->type->add_name, 
	    info->type->inc_name, info->type->sub_name);

    if (info->type->is_phaseless) {
	upcr_pshared_ptr_t current = upcr_shared_to_pshared(start);
	upcr_pshared_ptr_t next;

	for (i = 0; i < opcount; i++) {
	    test_op *op = &ops[i];
	    padd_func addfunc = (padd_func) info->type->add_func;
	    pinc_func incfunc = (pinc_func) info->type->inc_func;
	    psub_func subfunc = (psub_func) info->type->sub_func;

	    /* Test regular add function */
	    next = addfunc(current, info->elemsz, op->inc);
	    if (checkresult(testnum, i, info->type->add_name, info, op, 
			    ((uintptr_t)upcri_pshared_to_remote(next)) - 
                            ((uintptr_t)baseaddr[upcr_threadof_pshared(next)]),
			    upcr_threadof_pshared(next), 
			    upcr_phaseof_pshared(next)) ) 
		errs = 1;

	    /* Equality function had better fail here (if inc != 0) */
	    if (op->inc != 0 && upcr_isequal_pshared_pshared(next, current)) {
		fprintf(stderr, 
			"  op %2d  [ %-14s ]:  ERROR: ptrs should not be equal!\n", 
			i, op->desc);
		errs = 1;
	    }

	    /* ptr subtraction should yield the increment amount */
	    subval = subfunc(next, current, info->elemsz);
	    if (subval != op->inc) {
		fprintf(stderr, 
			"  op %2d  [ %-14s ]:  ERROR: %s() returned %ld "
			"instead of %ld!\n", i, op->desc, 
			info->type->sub_name, (long)subval, (long)op->inc);
		errs = 1;
	    }

	    /* Test in-place add function */
	    incfunc(&current, info->elemsz, op->inc);
	    if (checkresult(testnum, i, info->type->inc_name, info, op, 
			    ((uintptr_t)upcri_pshared_to_remote(current)) - 
                            ((uintptr_t)baseaddr[upcr_threadof_pshared(current)]),
			    upcr_threadof_pshared(current), 
			    upcr_phaseof_pshared(current)) ) 
		errs = 1;

	    /* Test for equality */
	    if (!upcr_isequal_pshared_pshared(next, current)) {
		fprintf(stderr, 
			"  op %2d  [ %-14s ]:  ERROR: ptrs should be equal!\n", 
			i, op->desc);
		errs = 1;
	    }

	    /* No point continuing with further ops in this test, since each
	     * relies on previous position being correct
	     */
	    if (errs)
		break;
	    else
		verbose("  op %2d  [ %-14s ]:  OK\n", i, op->desc);
	} 
    } else {
	upcr_shared_ptr_t current = start;
	upcr_shared_ptr_t next;

	for (i = 0; i < opcount; i++) {
	    test_op *op = &ops[i];
	    add_func addfunc = (add_func) info->type->add_func;
	    inc_func incfunc = (inc_func) info->type->inc_func;
	    sub_func subfunc = (sub_func) info->type->sub_func;

	    /* Test regular add function */
	    next = addfunc(current, info->elemsz, op->inc, info->blockelems);
	    if (checkresult(testnum, i, info->type->add_name, info, op, 
			    ((uintptr_t)upcri_shared_to_remote(next)) - 
                            ((uintptr_t)baseaddr[upcr_threadof_shared(next)]),
			    upcr_threadof_shared(next), 
			    upcr_phaseof_shared(next)) ) 
		errs = 1;

	    /* Equality function had better fail here (if inc != 0) */
	    if (op->inc != 0 && upcr_isequal_shared_shared(next, current)) {
		fprintf(stderr, 
			"  op %2d  [ %-14s ]:  ERROR: ptrs should not be equal!\n", 
			i, op->desc);
		errs = 1;
	    }

	    /* ptr subtraction should yield the increment amount */
	    subval = subfunc(next, current, info->elemsz, info->blockelems);
	    if (subval != op->inc) {
		fprintf(stderr, 
		    "  op %2d  [ %-14s ]:  ERROR: %s() returned "
		    "%ld instead of %ld!\n", i, op->desc, 
		    info->type->sub_name, (long)subval, (long)op->inc);
		errs = 1;
	    }

	    /* Test in-place add function */
	    incfunc(&current, info->elemsz, op->inc, info->blockelems);
	    if (checkresult(testnum, i, info->type->inc_name, info, op, 
			    ((uintptr_t)upcri_shared_to_remote(current)) - 
                            ((uintptr_t)baseaddr[upcr_threadof_shared(current)]),
			    upcr_threadof_shared(current), 
			    upcr_phaseof_shared(current)) ) 
		errs = 1;

	    /* Test for equality */
	    if (!upcr_isequal_shared_shared(next, current)) {
		fprintf(stderr, 
			"  op %2d  [ %-14s ]:  ERROR: ptrs should be equal!\n", 
			i, op->desc);
		errs = 1;
	    }

	    /* No point continuing with further ops in this test, since each
	     * relies on previous position being correct
	     */
	    if (errs)
		break;
	    else
		verbose("  op %2d  [ %-14s ]:  OK\n", i, op->desc);
	}
    }

    return errs;
}

#define MAX_TESTS 100
int test_errs[MAX_TESTS];

#define RUNTEST(testnum)					     \
do {								     \
    if (runtest(testnum, &test##testnum##_info, test##testnum##_ops, \
		sizeof(test##testnum##_ops) / sizeof(test_op) )) {   \
	fprintf(stderr, "Test %d failed!\n", testnum);		     \
	test_errs[testnum] = 1;					     \
    } else {							     \
	printf("Test %d OK\n", testnum);			     \
    }								     \
} while (0)

#define BARRIER() do { fflush(NULL); upcr_notify(__LINE__, 0); upcr_wait(__LINE__,0); } while(0)

int user_main(int argc, char **argv) 
{
    UPCR_BEGIN_FUNCTION();
    int errs = 0;
    int i;

    if ( (argc > 1) && argv[1][0] == '-' && argv[1][1] == 'v')
	do_verbose = 1;

    if (upcr_threads() != 4)
	upcri_err("Threads must equal 4 (not %d) for this test!\n", upcr_threads());

    if (upcr_mythread() == 0) 
	printf("Running test with %d nodes and %d threads\n", (int)gasnet_nodes(), (int)upcr_threads());

    BARRIER();    
    RUNTEST(1);
    BARRIER();    
    RUNTEST(2);
    BARRIER();    
    RUNTEST(3);
    BARRIER();    
    RUNTEST(4);
    BARRIER();    

    if (upcr_mythread() == 0) {
	for (i  = 0; i < MAX_TESTS; i++) {
	    if (test_errs[i]) {
		fprintf(stderr, "-------- Test %d failed! --------\n", i);
		errs = 1;
	    }
	}
        printf("done.\n");
    }
    BARRIER();
    upcr_global_exit(0);
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
