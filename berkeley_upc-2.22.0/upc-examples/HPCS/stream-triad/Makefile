
MYTARGET = stream-triad

SRCS   = $(MYTARGET).upc
OBJS   = $(SRCS:.upc=.o)

UPCC   = upcc
#UPCC_FLAGS = -shared-heap=256MB

$(MYTARGET):
	$(UPCC) -o $@ $(UPCC_FLAGS) $(SRCS)
$(MYTARGET)_st%: 
	$(UPCC) -o $@ $(UPCC_FLAGS) $(SRCS)

run: $(MYTARGET)
	./$(MYTARGET) 1000000 1.5  #<num elements in array> <scale factor>

clean:
	-rm -f $(OBJS) $(MYTARGET) $(MYTARGET)_st* *.out *.err
