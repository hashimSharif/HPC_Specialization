#include <upc.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int _test_rand(int low, int high) {
  int result;
  assert(low <= high);
  result = low+(int)(((double)(high-low+1))*rand()/(RAND_MAX+1.0));
  assert(result >= low && result <= high);
  return result;
} 
#define TEST_RAND(low,high) _test_rand((low), (high))
#define TEST_RAND_PICK(a,b) (TEST_RAND(0,1)==1?(a):(b))
#define TEST_SRAND(seed)    srand(seed)
#define TEST_RAND_ONEIN(p)  (TEST_RAND(1,p) == 1)
/* 
                   A: Wait-      B: Wait-               C: Wait-
                      FullyAnon     NamedMatch             NamedMisMatch
------------------------------------------------------------------------
1: Notify-         | no error  |       no error         |  no error
    FullyAnon      |           |                        |  
-------------------|-----------|------------------------|----------------
2:Notify-          | no error  | notify_all==wait_all ? |  ERROR
    NamedMatch     |           |    no error : ERROR    |
-------------------|-----------|------------------------|----------------
3:Notify-          | ERROR     |       ERROR            |  ERROR
    NamedMisMatch  |           |                        |
-------------------|-----------|------------------------|----------------

*/

#define MSG(s) if (!MYTHREAD) printf("%s\n",s); upc_barrier;
int main(int argc, char **argv) {
  int i, iters = 0;
  if (argc > 1) iters = atoi(argv[1]);
  if (!iters) iters = 100;

  if (THREADS == 1) {
    MSG("This barrier matching correctness test requires 2 or more threads");
    return 0;
  }

  MSG("Running barrier matching correctness test...");
  if (!MYTHREAD) printf("THREADS=%i  iters=%i\n",THREADS,iters);
  MSG("--------------------------------------------");
  MSG("None of the following should produce errors:");
 
  /* all of the following are legal by UPC 1.2: 6.6.1-7 */
  MSG("1A: anon notify/wait...");
  upc_notify;
  upc_wait;

  MSG("2B-OK: named matching notify/wait...");
  upc_notify 3;
  upc_wait 3;

  MSG("2B-OK: named matching notify/wait mixed with barrier...");
  if (MYTHREAD & 0x1) {
    upc_notify 4;
    upc_wait 4;
  } else {
    upc_barrier 4;
  }

  MSG("2B-OK: named matching notify/wait mixed with fully anon...");
  if (MYTHREAD & 0x1) {
    upc_notify 5;
    upc_wait 5;
  } else { 
    upc_notify;
    upc_wait;
  }

  MSG("2A: named matching notify with anon wait...");
  upc_notify 6;
  upc_wait;

  MSG("1B: anon notify with named matching wait...");
  upc_notify;
  upc_wait 7;

  MSG("1C: anon notify with named mismatching wait...");
  upc_notify;
  upc_wait MYTHREAD;

  MSG("randomized testing...");
  TEST_SRAND(MYTHREAD);
  for (i=10; i < iters; i++) {
    if (i%10 == 0) {
      if (TEST_RAND_ONEIN(2)) upc_barrier; /* anon barrier */
      else {
        upc_notify; /* global anon notify */
        upc_wait TEST_RAND(1, 1<<30); /* random wait */
      }
    } else if (TEST_RAND_ONEIN(4)) {
      if (TEST_RAND_ONEIN(2)) upc_barrier; /* anon barrier */
      else upc_barrier i;  /* named barrier */
    } else { 
      if (TEST_RAND_ONEIN(2)) upc_notify; /* anon notify */
      else upc_notify i; /* named notify */

      if (TEST_RAND_ONEIN(2)) upc_wait; /* anon wait */
      else upc_wait i; /* named matching wait */
    }
  }
  fflush(NULL); upc_barrier;
  MSG("done.");
  MSG("--------------------------------------------");
  MSG("Error cases (should produce runtime error):");
  if (argc > 2) {
   int errcase = atoi(argv[2]);
   int low_half = MYTHREAD < (THREADS / 2);
   switch (errcase) {
     case 1:
       MSG("3A: named mismatched notifys, anon wait..."); fflush(NULL);
       upc_notify MYTHREAD;
       upc_wait;
     break;
     case 2:
       MSG("2B-ERR: some named notifys, same thread different named wait..."); fflush(NULL);
       if (low_half) {
         upc_notify 5;
         upc_wait 6;
       } else { 
         upc_notify;
         upc_wait;
       }
     break;
     case 3:
       MSG("2B-ERR: some named notifys, other thread different named wait..."); fflush(NULL);
       if (low_half) {
         upc_notify 5;
         upc_wait;
       } else { 
         upc_notify;
         upc_wait 6;
       }
     break;
     case 4:
       MSG("2C: matching named notifys, mismatching named wait..."); fflush(NULL);
       if (low_half) {
         upc_notify 5;
         upc_wait 5;
       } else { 
         upc_notify 5;
         upc_wait 6;
       }
     break;
     case 5:
       MSG("3C: named notify/wait, mismatch other thread named notify/wait..."); fflush(NULL);
       if (low_half) {
         upc_notify 5;
         upc_wait 5;
       } else { 
         upc_notify 6;
         upc_wait 6;
       }
     break;
     default:
       printf("Unknown error case %i\n", errcase);
       exit(1);
   }
   upc_barrier;
   printf("*** INCORRECT BEHAVIOR: Error case %i failed to produce an error!\n", errcase);
   exit(1);
  } else { 
    MSG("No error case specified");
    MSG("Usage: ./barriermatch [random_iters] [err_case(1..5)]");
  }
  return 0;
}
