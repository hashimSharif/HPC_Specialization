
UPCC = upcc 

# Portable way to get C++ compiler: UDP conduit always uses it 
CXX  := $(shell $(UPCC) --network=udp --echo-var UPCR_LD)

# If mpi or vapi conduit used, need MPI C++ linker: guess at name.
# Otherwise, use C++ linker
CC := $(shell $(UPCC) --echo-var UPCR_LD)
ifeq ($(findstring mpicc,$(CC)),mpicc)
    #USE_LD := $(subst mpicc,mpicxx,$(CC))
    USE_LD := $(subst mpicc,mpiCC,$(CC))
else
    # UPD conduit uses C++ compiler
    USE_LD  := $(shell $(UPCC) --network=udp --echo-var UPCR_LD)
endif

CXXFLAGS = 

TARGET = a.out
OBJS   = client.o cpplib.o

.SUFFIXES: .upc .c .cc .o

.upc.o: 
	$(UPCC) -c -o $@ $<	

.cc.o: 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(UPCC) --link-with="$(USE_LD)" $(OBJS) -o $(TARGET)

clean:
	-rm -rf $(OBJS) $(TARGET)$(EXESUFFIX) $(TARGET)_*
