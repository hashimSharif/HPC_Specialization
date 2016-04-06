#include <upc.h>
#include <string.h>
#include <stdio.h>

shared int arr[1048576*THREADS];

int main() {
  /* check trace manipulation facilities */
  char tracemask[256];
  strcpy(tracemask,bupc_trace_getmask());
  if (strlen(tracemask)==0) printf("ERROR: trace mask is empty!\n");
  else printf("TRACEMASK: %s\n", tracemask);
  char statsmask[256];
  strcpy(statsmask,bupc_stats_getmask());
  if (strlen(statsmask)==0) printf("ERROR: stats mask is empty!\n");
  else printf("STATSMASK: %s\n", statsmask);
  upc_barrier;
  bupc_trace_setmask("");
  bupc_stats_setmask("");
  if (strlen(bupc_trace_getmask()))  printf("ERROR: trace mask is non-empty!\n");
  if (strlen(bupc_stats_getmask()))  printf("ERROR: stats mask is non-empty!\n");
  upc_barrier;
  bupc_trace_setmask(tracemask);
  bupc_stats_setmask(statsmask);
  upc_barrier;
  if (strcmp(bupc_trace_getmask(),tracemask)) 
    printf("ERROR: failed to reset tracemask to: %s curval: %s",tracemask,bupc_trace_getmask());
  if (strcmp(bupc_stats_getmask(),statsmask)) 
    printf("ERROR: failed to reset statsmask to: %s curval: %s",statsmask,bupc_stats_getmask());

  upc_barrier;
  bupc_trace_settracelocal(0);
  if (bupc_trace_gettracelocal()) printf("ERROR: tracelocal is on!\n");
  upc_barrier;
  bupc_trace_settracelocal(1);
  if (!bupc_trace_gettracelocal()) printf("ERROR: tracelocal is off!\n");

  /* misc goop that generates tracing output */
  upc_barrier;
  arr[(MYTHREAD+1)%THREADS] = MYTHREAD;
  upc_barrier;
  int val = arr[MYTHREAD?(MYTHREAD-1):THREADS-1];
  upc_notify 4;
  upc_wait 4;
  shared strict int *p = upc_all_alloc(THREADS,100);
  p[(MYTHREAD+1)%THREADS] = MYTHREAD;
  shared int *p2 = upc_global_alloc(THREADS,100);
  p2[(MYTHREAD+1)%THREADS] = MYTHREAD;
  shared int *p3 = upc_alloc(THREADS*100);
  int tmp[100];
  upc_memget(tmp,p2+((MYTHREAD+1)%THREADS),100);
  upc_memput(p2+((MYTHREAD+1)%THREADS),tmp,100);
  upc_memcpy(p2+((MYTHREAD+1)%THREADS),p2+(MYTHREAD?(MYTHREAD-1):THREADS-1),100);
  upc_free(p2);
  upc_free(p3);
  upc_lock_t *al = upc_all_lock_alloc();
  upc_lock_t *ml = upc_global_lock_alloc();
  upc_lock(al);
  if (upc_lock_attempt(ml)) upc_unlock(ml);
  upc_lock_free(ml);
  upc_unlock(al);
  upc_barrier;
  int i = 2;
  double A[10];
  A[i] = 123.456;
  bupc_trace_printf(("the value of A[%i] is: %f", i, A[i]));
  upc_barrier;
  printf("done.\n");
  upc_global_exit(0);
}
