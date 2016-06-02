UPCC = upcc
THREADS =
UPC_FLAGS =  -T=$(THREADS) -DVERBOSE -DVERBOSE0 -DVERBOSE1
UPC_OBJS = I_case1_v \
I_case2_i \
I_case2_ii \
I_case3_i \
I_case4_i \
I_case5_i \
I_case5_ii \
II_case1_i \
II_case2_i \
II_case3_i \
III_case1_i \
IV_case1_i \
IV_case2_i \
IX_case1_i \
V_case1_i \
V_case2_i \
V_case4_i \
V_case4_ii \
VI_case1_i \
VII_case1_i \
VII_case1_ii \
VII_case1_iii \
VII_case2_i \
VII_case2_ii \
VII_case2_iii \
VII_case3_i \
VII_case4_i \
VIII_case1_i \
VIII_case1_ii \
VIII_case1_iii \
VIII_case1_iv \
VIII_case1_v \
VIII_case2_i \
X_case1_i \
XI_case1_i \
XI_case2_i \
XI_case3_i \
XII_case1_ii \
XII_case2_i \
XII_case2_ii \
XIII_case1_i \
XIII_case4_i \
XIII_case2_i \
XIII_case3_i \
#V_case5_i whirl2c -> generates bogus_field_name
#XII_case1_i - brain dead test, uses static locks, FE crashes on
#
C_OBJS =



.SUFFIXES: .upc .upo
default: $(UPC_OBJS) $(C_OBJS)

.upc.upo:
	$(UPCC)  $(UPC_FLAGS) -o $@ $<


$(UPC_OBJS): %: %.upc
	$(UPCC)  $(UPC_FLAGS) -o $@ $<

runall:
	for t in $(UPC_OBJS); do\
	$(RUN) $(PROCS) $$t;\
	done

clean:
	rm -f *.upo  whirl2c.h *.w2c.c *.w2c.h $(UPC_OBJS) *startup* *.o *global* *_symbols* *.B *.N *.t *.i *.upc.c *.o
