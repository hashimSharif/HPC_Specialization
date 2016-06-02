runall:
	./runall.sh
	./execute-all

clean:
	rm -f *.o  whirl2c.h *.w2c.c *.w2c.h $(UPC_OBJS) *_startup_tmp.* *.global_data.c *_symbols *.B *.N *.t *.i *.upc.c upc{c,r}-sizes
	rm -f *-static*-int *-static*-float *-static*-double *-static*-long *-dynamic-int *-dynamic-float *-dynamic-double *-dynamic-long
	rm -f `find . -maxdepth 1 -type l -name '*.upc' -print`
	rm -f prm prm.c
