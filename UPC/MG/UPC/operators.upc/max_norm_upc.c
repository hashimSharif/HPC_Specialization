

#ifdef _UPC
#include <upc_collective.h>
shared double MAX_NORM;
shared double max_norm_sh[THREADS];
#endif 

#ifdef _UPCR
#error Not implemented ...
upcr_pshared_ptr_t MAX_NORM;
upcr_pshared_ptr_t max_norm_sh;
#endif 

#ifdef _UPC
double  do_reduce(double max_norm) {
  int i;
  max_norm_sh[MYTHREAD] = max_norm;
  upc_barrier; // OK
  upc_all_reduceD(&MAX_NORM, &max_norm_sh[MYTHREAD],UPC_MAX, THREADS, 1, NULL, UPC_IN_MYSYNC | UPC_OUT_ALLSYNC);
  upc_all_broadcast(max_norm_sh, &MAX_NORM, sizeof(double), UPC_IN_NOSYNC | UPC_OUT_NOSYNC);
  /*
    upc_barrier;  // OK
  if(MYTHREAD == 0) { 
    MAX_NORM = 0; 
    for(i = 0; i < THREADS; i++) 
      if(max_norm_sh[i] > MAX_NORM) 
   	MAX_NORM = max_norm_sh[i]; 
  } 
  upc_barrier;   // OK
  */
  if(MYTHREAD ==0) MAX_NORM = 0;
  
  return max_norm_sh[MYTHREAD];
  //return MAX_NORM;
}
#endif


