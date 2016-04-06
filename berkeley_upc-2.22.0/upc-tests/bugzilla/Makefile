UPCC = upcc
THREADS =
UPC_FLAGS = 
UPC_OBJS = bug32 bug63 bug46 bug39 bug31 bug53 bug57 bug58 bug61 bug33 bug88 bug87 bug41x bug91 bug105 bug116 bug116b bug40 bug133 bug137 bug137b bug138 bug139 bug140 bug142 bug145 bug147 bug148 bug149 bug156 bug159 bug164 bug170 bug171 bug174 bug175a bug179 bug192 bug115 bug154 bug201 bug208 bug170b bug209 bug247 bug271 bug176 bug276 bug305 bug306 bug311 bug312 bug319 bug438 barriertest  fpe check checkUPCversion


C_OBJS =
LC = 


.SUFFIXES: .upc .o
default: $(UPC_OBJS) $(C_OBJS)

.PHONY: check

.upc.o:
	$(UPCC)  $(UPC_FLAGS) -c  $<


$(UPC_OBJS): %: %.upc
	$(UPCC)  $(UPC_FLAGS) -o $@ $<


SPECIAL_CASES = bug3 bug39  

bug3: bug3.o  
bug31: bug31.o
bug53: bug53.o
bug33: bug33.o
bug41: bug41.o
bug57: bug57.o
#bug3: bug3.o
#bug6: bug6.o
bug7: bug7.o
bug87: bug87.o
bug32: bug32.o
bug63: bug63.o
bug61: bug61.o
bug64: bug64.o
bug88: bug88.o
bug89: bug89.o
bug41: bug41.o
bug41x: bug41x.o
bug87: bug87.o
bug105: bug105.o
runall: check

bug175: bug175.upc
	$(UPCC) -T 2 -o $@ $<

bug207: bug207.upc
	$(UPCC) -T 1 -o $@ $<

BUG899C_OBJS = bug899c.o bug899c_c.o bug899c_aux.o
bug899c: $(BUG899C_OBJS)
	$(UPCC) $(UPC_FLAGS) -o $@ $(BUG899C_OBJS)
bug899c_c.o: bug899c_c.c # C file to compile w/ upcc
	$(UPCC) $(UPC_FLAGS) -c $<

clean:
	rm -f *.o  whirl2c.h *.w2c.c *.w2c.h $(UPC_OBJS) *_startup_tmp.* *.global_data.c *_symbols *.B *.N *.t *.i *.upc.c upc{c,r}-sizes core*
