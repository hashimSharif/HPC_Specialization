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
    USE_LD  := $(CXX)
endif

# Portable way for C++ compiler to find <bupc_extern.h> 
UPC_EXTERN_INCLUDE = `$(UPCC) -print-include-dir`

TARGET = a.out
OBJS   = user.o upclib.o

.SUFFIXES: .upc .c .cc .o

.upc.o:
	$(UPCC) -c -o $@ $<

.cc.o:
	$(CXX) $(CXXFLAGS) -I$(UPC_EXTERN_INCLUDE) -c -o $@ $<

$(TARGET): $(OBJS)
	$(UPCC) --link-with="$(USE_LD)" --extern-main $(OBJS) -o $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET)$(EXESUFFIX)

