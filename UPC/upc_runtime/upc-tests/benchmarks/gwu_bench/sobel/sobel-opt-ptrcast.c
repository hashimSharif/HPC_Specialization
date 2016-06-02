/* sobel-opt-ptrcast.c
 *
 * Sobel function with cast from pointers to local shared data
 * to local regular pointers when possible.
 * (should be included in sobel.c)
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upc-tests/benchmarks/gwu_bench/sobel/sobel-opt-ptrcast.c $
 */

#ifdef _BUGGY_BLOCK
# error "Cannot work with wrong data distribution."
#endif

int Sobel(void)
{
  int i,j,d1,d2;
  double magnitude;
 
  BYTET* p_orig0;
  BYTET* p_orig1;
  BYTET* p_orig2;
  BYTET* p_edge;

  upc_forall(i=1; i<(IMGSIZE-1); i++; &edge[i])
  {
#ifdef DEBUG
		fprintf(stderr, "i=%2i  (PREV_ROW=%2i NEXT_ROW=%2i)\n", i, PREV_ROW(i), NEXT_ROW(i));
#endif
    debug(p_edge=(BYTET*)edge[i].r);
    p_orig1=(BYTET*)orig[i].r;

		if (FIRST_ROW(i))
		/* first element of the block */
    {
#ifdef DEBUG
			fprintf(stderr, "\tfirst element of the block\n");
#endif
    	p_orig2=(BYTET*)orig[NEXT_ROW(i)].r;
		
			for (j=1; j<IMGSIZE-1; j++) {
      d1=  (int)orig[PREV_ROW(i)].r[j+1]-orig[PREV_ROW(i)].r[j-1];
      d1+=((int)p_orig1[j+1]    -p_orig1[i-1])<<1;
      d1+= (int)p_orig2[j+1]    -p_orig2[i-1];

      d2=  (int)orig[PREV_ROW(i)].r[j-1]-p_orig2[j-1];
      d2+=((int)orig[PREV_ROW(i)].r[j]  -p_orig2[j]  )<<1;
      d2+= (int)orig[PREV_ROW(i)].r[j+1]-p_orig2[j+1];

      magnitude=sqrt((double)(d1*d1+d2*d2));
      p_edge[j]=magnitude>255? 255:(unsigned char)magnitude;
      }
    }
		else if (LAST_ROW(i))
		/* last element of the block */
    {
#ifdef DEBUG
			fprintf(stderr, "\tlast element of the block\n");
#endif
	    p_orig0=(BYTET*)orig[PREV_ROW(i)].r;
		
			for (j=1; j<IMGSIZE-1; j++) {   
      d1=  (int)p_orig0[j+1]-    p_orig0[PREV_ROW(i)];
      d1+=((int)p_orig1[j+1]-    p_orig1[PREV_ROW(i)])<<1;
      d1+= (int)orig[NEXT_ROW(i)].r[j+1]-orig[NEXT_ROW(i)].r[PREV_ROW(i)];

      d2 = (int)p_orig0[PREV_ROW(i)] - orig[NEXT_ROW(i)].r[PREV_ROW(i)];
      d2+=((int)p_orig0[j]   - orig[NEXT_ROW(i)].r[j]  )<<1;
      d2+= (int)p_orig0[j+1] - orig[NEXT_ROW(i)].r[j+1];

      magnitude=sqrt((double)(d1*d1+d2*d2));
      p_edge[j]=magnitude>255? 255:(unsigned char)magnitude;
      }
    }
    else
		/* any other element of the block */
    { 
	    p_orig0=(BYTET*)orig[PREV_ROW(i)].r;
    	p_orig2=(BYTET*)orig[NEXT_ROW(i)].r;
		
			for (j=1; j<IMGSIZE-1; j++) 
			{
	      d1=(int)   p_orig0[j+1]-p_orig0[PREV_ROW(i)];
	      d1+=((int) p_orig1[j+1]-p_orig1[PREV_ROW(i)])<<1;
	      d1+=(int)  p_orig2[j+1]-p_orig2[PREV_ROW(i)];
	
  	    d2=(int)   p_orig0[PREV_ROW(i)]-p_orig0[PREV_ROW(i)];
	      d2+=((int) p_orig0[j]  -p_orig0[j]  )<<1;
	      d2+=(int)  p_orig0[j+1]-p_orig0[j+1];

	      magnitude=sqrt((double)(d1*d1+d2*d2));
	      p_edge[j]=magnitude>255? 255:(unsigned char)magnitude;
  	  }
    }
  }
  return 0;
}

/* vi:ts=2:ai
 */
