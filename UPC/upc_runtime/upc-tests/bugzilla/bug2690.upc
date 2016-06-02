/* Based on EXAMPLE 2 on p31 of UPC spec 1.2 */
#include <upc.h>
#include <stdio.h>

int c1, c2, c3, c4;

int foo1 (void) { c1++; return 0; }
int foo2 (void) { c2++; return 0; }
int foo3 (void) { c3++; return 0; }
int foo4 (void) { c4++; return 0; }

int main(void)
{
    int i;

    c1 = c2 = c3 = c4 = 0;
    upc_forall ((foo1(), i = 0); (foo2(), i < 10); (foo3(), i++); i)
    {
        foo4();
    }
    upc_barrier;

    printf("TH%d: i=%d c1=%d c2=%d c3=%d c4=%d\n", MYTHREAD,i,c1,c2,c3,c4);

// UPC SPEC says in describing the example:
// --begin quote--
//   Each thread evaluates foo1() exactly once, before any further action on that
//   thread. Each thread will execute foo2() and foo3() in alternating sequence, 10
//   times on each thread. Assuming there is no enclosing upc forall loop, foo4()
//   will be evaluated exactly 10 times total before the last thread exits the loop,
//   once with each of i=0..9. Evaluations of foo4() may occur on different threads
//   (as determined by the affinity clause) with no implied synchronization or
//   serialization between foo4() evaluations or controlling expressions on different
//   threads. The final value of i is 10 on all threads.
// --end quote--
// UPC SPEC language above says foo2() is executed 10 times, but does not say
// that those are the ONLY 10 times.  The NORMATIVE portion of the spec says
// in 6.6.2:11
// --begin quote--
//   Every thread evaluates the first three clauses of a upc forall statement
//   in accordance with the semantics of the corresponding clauses for the for
//   statement, as defined in [ISO/IEC00 Sec. 6.8.5.3]. Every thread evaluates
//   the fourth clause of every iteration.
// --end quote--
// That C spec text implies foo2() is run 11 times.
//
// So, we expect 
//   foo1() executes exactly 1 time
//   foo2() executes exactly 11 times
//   foo3() executes exactly 10 times
//   foo4() executes as determined by the affinity expression

    if (i != 10) {
      puts ("FAIL - bad i");
    }
    if (c1 != 1) {
      puts ("FAIL - bad c1");
    }
    if (c2 != 11) {
      puts ("FAIL - bad c2");
    }
    if (c3 != 10) {
      puts ("FAIL - bad c3");
    }
    if (c4 != ((10 + THREADS - 1 - MYTHREAD) / THREADS)) {
      puts ("FAIL - bad c4");
    }

    upc_barrier;
    if (!MYTHREAD) puts("done.");

    return 0;
}
