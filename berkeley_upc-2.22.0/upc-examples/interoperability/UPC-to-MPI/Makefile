UPCC 	= upcc

# Portable way to get local MPI compiler/linker's path
MPICC  := $(shell $(UPCC) --print-mpicc)

TARGET = a.out
OBJS   = UPC_to_MPI.o

.SUFFIXES: .upc .o

.upc.o:
	$(UPCC) -c --uses-mpi -o $@ $<

$(TARGET): $(OBJS)
	$(UPCC) $(UPCFLAGS) --uses-mpi $(OBJS)

clean:
	-rm -f $(OBJS) $(TARGET)
