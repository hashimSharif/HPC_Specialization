/* mat-opt-all.c
 *
 * Matrix multiplication with remote data prefetching to local data.
 */

elem_t blocal[P][M];

#define STRUCTSIZE 6

typedef struct { elem_t a[STRUCTSIZE]; } cpstruct;

int main()
{
  int i,j,l;
  elem_t sum;
  elem_t *pa, *pc;

  double time0, time1;

// Collective arrays initialization 

  upc_forall(i=0;i<N;i++;&a[i][0])
    for(j=0;j<P;j++) 
      a[i][j] = i * j + 1;

  for(i=0;i<P;i++)
    upc_forall(j=0;j<M;j++;&b[i][j]) 
      b[i][j] = i * N +j + 3;

  upc_barrier(1);

  time0=second();

  for(i=0;i<P;i++)
    { shared cpstruct *pss = (shared void*)(&b[i]); 
      cpstruct *psp = (void*)(&blocal[i]);

      for(j=0; j<M; j+=STRUCTSIZE) *(psp++) = *(pss++);
    }

// all threads  perform matrix multiplication

  time1=second();

#ifdef DEBUG
  if (MYTHREAD==0)
  { printf("Prefetching time (sec): %f\n", time1-time0);
  }
#endif

  upc_barrier(1);

  time0=second();

  upc_forall(i=0;i<N;i++;&a[i][0])
  // &a[i][0] specifies that this iteration will be 
  // executed by the thread that has affinity to element a[i][0]
  // This thread will have the affinity with the whole line
  {  pa = (elem_t*) &a[i][0];
     pc = (elem_t*) &c[i][0];

     for (j=0; j<M; j++) {
       sum=0;
       for(l=0; l< P; l++) 
         sum +=pa[l]*blocal[l][j];
       pc[j] = sum;
     }
  }


  upc_barrier(2);

  time1=second();

  if (MYTHREAD==0)
  {
    printf("time = %f seconds\n", time1-time0);
  }

//  thread 0 displays results
#if 0
        printf("\n\n");
        for(i=0;i<N;i++)
           for(j=0;j<M;j++)
            printf("c[%d][%d]=%lf\n",i,j,c[i][j]);
#endif

  return 0;
}

/* vi:ts=2:ai
 */
