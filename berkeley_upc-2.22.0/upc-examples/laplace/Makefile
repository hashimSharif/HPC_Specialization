stencil: stencil.upc
	$(UPCC) $(UPCC_FLAGS) -o $@ stencil.upc
stencil_st%: stencil.upc
	$(UPCC) $(UPCC_FLAGS) -o $@ stencil.upc

stencil_trans: stencil.upc
	$(UPCC) $(UPCC_FLAGS) -trans stencil.upc
stencil_st%_trans: stencil.upc
	$(UPCC) $(UPCC_FLAGS) -trans stencil.upc

run: stencil
	$(UPCRUN) -np $(THREADS) ./stencil
clean:
	rm -f stencil stencil_st* whirl2c.h *.trans.c *.B *.upc.c \
	*.global_data.c *.i *.t \
	*.w2c.* whirl2c.h *.upc_symbols upcc-sizes *.N *.o *startup_tmp.c *~
