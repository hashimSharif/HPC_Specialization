/* mat-opt-prefetch.c
 *
 * Matrix multiplication with remote data prefetching to local data,
 * and with or without local-shared pointers casting (according to
 * OPT_PTRCAST).
 */

elem_t blocal[P][M];

#define STRUCTSIZE 6

typedef struct { elem_t a[STRUCTSIZE]; } cpstruct;

int main()
{
  int i,j,l;
  elem_t sum;
#ifdef OPT_PTRCAST
  elem_t *pa, *pc;
#endif
	double time0, time1;


#ifdef DEBUG
	if(!MYTHREAD)
	{
		fprintf(stderr, "threadof(&a)=%i\n", upc_threadof(&a));
		for(i=0; i<N; i++)
			fprintf(stderr, "threadof(&a[% 3i])=%i\n", i, upc_threadof(&a[i]));
	}
	upc_barrier;
#endif

// Collective arrays initialization 

  upc_forall(i=0;i<N;i++;&a[i][0])
    for(j=0;j<P;j++) 
      a[i][j] = i * j + 1;

  for(i=0;i<P;i++)
    upc_forall(j=0;j<M;j++;&b[i][j]) 
      b[i][j] = i * N +j + 3;

  upc_barrier(1);

  time0=second();

#if 0
   for(i=0;i<P;i++)
    { shared cpstruct *pss = (shared void*)(&b[i]); 
      cpstruct *psp = (void*)(&blocal[i]);

      for(j=0; j<M; j+=STRUCTSIZE) *(psp++) = *(pss++);
    }
#else
 #if 0 
  /* DOB: this is completely broken and wrong */
  upc_memget(&blocal[i], &b[i], P*sizeof(elem_t));
 #else
  /* this is more complicated (mostly by the need to reblock from cyclic dist), 
   * but has the nice side-effect of being correct */
  bupc_handle_t h[THREADS];
  for (int i=0; i < THREADS; i++) {
    int th = (MYTHREAD+i)%THREADS;
    size_t thsz = upc_affinitysize(P*M*sizeof(elem_t), sizeof(elem_t), th);
    h[i] = bupc_memget_fstrided_async(&blocal[0][th], sizeof(elem_t), THREADS*sizeof(elem_t), thsz/sizeof(elem_t),
                        &b[0][th], thsz, thsz, 1);
  } 
  bupc_waitsync_all(h, THREADS);
 #endif
#endif

// all threads  perform matrix multiplication

  time1=second();

#ifdef DEBUG
  if (!MYTHREAD)
  { printf("Prefetching time (sec): %f\n", time1-time0);
  }
#endif

  upc_barrier(1);

  time0=second();

  upc_forall(i=0;i<N;i++;&a[i][0])
  // &a[i][0] specifies that this iteration will be 
  // executed by the thread that has affinity to element a[i][0]
  // This thread will have the affinity with the whole line
#ifdef OPT_PTRCAST
  {  pa = (elem_t*) &a[i][0];
     pc = (elem_t*) &c[i][0];

     for (j=0; j<M; j++)
		 {
       sum=0;
       for(l=0; l< P; l++) 
         sum +=pa[l]*blocal[l][j];
       pc[j] = sum;
     }
  }
#else /* prefetching only */
  {  for (j=0; j<M; j++) {
       sum=0;
       for(l=0; l< P; l++) 
         sum +=a[i][l]*blocal[l][j];
       c[i][j] = sum;
     }
  }
#endif

  upc_barrier 2;

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
