/* mat-opt-ptrcast.c
 *
 * Matrix multiplication with cast from pointers to local shared data
 * to local regular pointers when possible.
 * (should be included in mat.c)
 */

int main()
{
  int i,j,l;
  elem_t sum;
  elem_t *pa, *pc;
  double time0, time1;


// Collective arrays initialization   by t

  upc_forall(i=0;i<N;i++;&a[i][0])
    for(j=0;j<P;j++) 
      a[i][j] = i * j + 1;

  for(i=0;i<P;i++)
    upc_forall(j=0;j<M;j++;&b[i][j]) 
      b[i][j] = i * N +j + 3;

  upc_barrier(1);

  time0 = second();

// all threads  perform matrix multiplication

  upc_forall(i=0;i<N;i++;&a[i][0])
  // &a[i][0] specifies that this iteration will be 
  // executed by the thread that has affinity to element a[i][0]
  // This thread will have the affinity with the whole line
  { pa = (elem_t*) &a[i][0];
    pc = (elem_t*) &c[i][0];
    for (j=0; j<M; j++) {
      sum=0;
      for(l=0; l< P; l++) 
        sum +=pa[l]*b[l][j];
      pc[j] = sum;
    }
  }

  upc_barrier(2);

  time1 = second();

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
