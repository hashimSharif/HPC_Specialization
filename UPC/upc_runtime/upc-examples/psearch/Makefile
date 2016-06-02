
MYTARGET = psearch

SRCS   = $(MYTARGET).upc sha1.upc
OBJS   = $(SRCS:.upc=.o)

UPCC   = upcc
UPCC_FLAGS = 

$(MYTARGET):
	$(UPCC) -o $@ $(UPCC_FLAGS) $(SRCS)
$(MYTARGET)_st%: 
	$(UPCC) -o $@ $(UPCC_FLAGS) $(SRCS)

run: $(MYTARGET)
	./$(MYTARGET) -m 8 -q 0.124999

clean:
	-rm -f $(OBJS) $(MYTARGET) $(MYTARGET)_st* *.out *.err
