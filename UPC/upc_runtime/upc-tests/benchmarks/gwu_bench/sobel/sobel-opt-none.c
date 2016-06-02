/* sobel-opt-none.c
 *
 * No hand-optimizations.
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upc-tests/benchmarks/gwu_bench/sobel/sobel-opt-none.c $
 */

int Sobel(void)
{
  int i,j,d1,d2;
  double magnitude;
//	volatile BYTET* p;
  
//  upc_forall(i=NEXT_ROW(0); i<PREV_ROW(IMGSIZE); i=NEXT_ROW(i); &edge[i])	// row
  upc_forall(i=1; i<IMGSIZE-1; i++; &edge[i].r[0])
  {
	#ifdef DEBUG
		fprintf(stderr, "CURR=%i PREV_ROW=%i NEXT_ROW=%i\n", i, PREV_ROW(i), NEXT_ROW(i));
	#endif
		/* Check if the actual data distribution */
//		p = (BYTET*)&edge[NEXT_ROW(i)].r[0];
//		p = (BYTET*)&edge[PREV_ROW(i)].r[0];
//		assert(upc_threadof(&orig[NEXT_ROW(i)].r[0])==upc_threadof(&orig[i].r[0]));
//		assert(upc_threadof(&orig[PREV_ROW(i)].r[0])==upc_threadof(&orig[i].r[0]));
		
    for (j=1; j<IMGSIZE-1; j++)	// col
		{
	#ifdef DEBUG
			if (NEXT_ROW(i)>=IMGSIZE)
			{	fprintf(stderr, "*** NEXT_ROW(%i)=%i\n", i, NEXT_ROW(i));
			  exit(1);
			}
			if (PREV_ROW(i)<0)
			{	fprintf(stderr, "*** PREV_ROW(%i)=%i\n", i, PREV_ROW(i));
			  exit(1);
			}
	#endif
	
      d1=(int)   orig[PREV_ROW(i)].r[j+1]  -orig[PREV_ROW(i)].r[j-1];
      d1+=((int) orig[i].r[j+1]  -orig[i].r[j-1])<<1;
      d1+=(int)  orig[NEXT_ROW(i)].r[j+1]  -orig[NEXT_ROW(i)].r[j-1];

      d2=(int)   orig[PREV_ROW(i)].r[j-1]-orig[NEXT_ROW(i)].r[j-1];
      d2+=((int) orig[PREV_ROW(i)].r[j]  -orig[NEXT_ROW(i)].r[j])<<1;
      d2+=(int)  orig[PREV_ROW(i)].r[j+1]-orig[NEXT_ROW(i)].r[j+1];

      magnitude=sqrt((double)(d1*d1+d2*d2));
      edge[i].r[j]=(magnitude>255)?255:(unsigned char)magnitude;
    }
  }
  return 0;
}

/* vi:ts=2:ai
 */
