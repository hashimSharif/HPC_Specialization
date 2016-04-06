
MYTARGET = guppie

SRCS   = $(MYTARGET).upc
OBJS   = $(SRCS:.upc=.o)

UPCC   = upcc
UPCC_FLAGS = 

$(MYTARGET):
	$(UPCC) -o $@ -DLTABSIZE=19L $(UPCC_FLAGS) $(SRCS)
$(MYTARGET)_st%: 
	$(UPCC) -o $@ -DLTABSIZE=19L $(UPCC_FLAGS) $(SRCS)

run: $(MYTARGET)
	./$(MYTARGET) 

clean:
	-rm -f $(OBJS) $(MYTARGET) $(MYTARGET)_st* *.out *.err
