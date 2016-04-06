
all: doublereduce

doublereduce: doublereduce.upc
	$(UPCC) $(UPCC_FLAGS) -o $@ doublereduce.upc
doublereduce_st%: doublereduce.upc
	$(UPCC) $(UPCC_FLAGS) -o $@ doublereduce.upc

doublereduce_trans: doublereduce.upc
	$(UPCC) $(UPCC_FLAGS) -trans doublereduce.upc
doublereduce_st%_trans: doublereduce.upc
	$(UPCC) $(UPCC_FLAGS) -trans doublereduce.upc

run: doublereduce
	$(UPCRUN) -np $(THREADS) ./doublereduce
clean:
	rm -f doublereduce doublereduce_st* whirl2c.h *.B *.upc.c \
	*.global_data.c *.i *.t \
	*.w2c.* *.upc_symbols upcc-sizes *.N *.o *startup_tmp.c *~
