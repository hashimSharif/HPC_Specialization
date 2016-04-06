UPCC	= upcc

# Portable way to get local MPI compiler/linker's path
MPICC  := $(shell $(UPCC) --print-mpicc)

# Portable way for C++ compiler to find <bupc_extern.h> 
UPC_EXTERN_INCLUDE := $(shell $(UPCC) -print-include-dir)

TARGET = a.out
OBJS   = MPI_main.o UPC_functions.o

.SUFFIXES: .upc .c .o

.upc.o:
	$(UPCC) -c -o $@ $<

.c.o:
	$(MPICC) $(CXXFLAGS) -I$(UPC_EXTERN_INCLUDE) -c -o $@ $<

$(TARGET): $(OBJS)
	$(UPCC) --uses-mpi --extern-main $(OBJS)

clean:
	-rm -f $(OBJS) $(TARGET)

echo: 
	echo USE_LD=$(USE_LD)
