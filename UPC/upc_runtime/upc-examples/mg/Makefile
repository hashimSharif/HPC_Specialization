.SUFFIXES:

SRC = mg.upc c_print_results.upc c_timers.upc wtime.upc
OBJ = $(SRC:.upc=.o)
TRANS = $(SRC:.upc=.trans.c)
HEADERS = globals.uph npbparams.uph wtime.uph npb-C.uph

# make all objects depend on all headers for simplicity

$(OBJ) : $(HEADERS)

# how to compile an object

%.o : %.upc
	$(UPCC) $(UPCC_FLAGS) -c $<

%.trans.c : %.upc
	$(UPCC) $(UPCC_FLAGS) -trans $<

mg_trans : force
	$(MAKE) clean
	$(MAKE) $(TRANS)
mg_st%_trans : force
	$(MAKE) clean
	$(MAKE) $(TRANS)

mg : force
	$(MAKE) clean
	$(MAKE) $(OBJ)
	$(UPCC) $(UPCC_FLAGS) -o $@ $(OBJ) -lm
	rm -f $(OBJ)
mg_st%: force
	$(MAKE) clean
	$(MAKE) $(OBJ)
	$(UPCC) $(UPCC_FLAGS) -o $@ $(OBJ) -lm
	rm -f $(OBJ)

run: mg
	$(UPCRUN) -np $(THREADS) ./mg

clean:
	rm -f whirl2c.h *.trans.c *.B *.upc.c *.global_data.c *.i *.t \
	*.w2c.* *.upc_symbols upcc-sizes *.N *.o *startup_tmp.c *~ core*

veryclean: clean
	rm -f mg mg_st*

force:

.PHONY: run clean veryclean force
