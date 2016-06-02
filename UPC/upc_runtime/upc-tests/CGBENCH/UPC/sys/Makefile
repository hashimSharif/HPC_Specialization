include ../config/make.def

# Note that COMPILE is also defined in make.common and should
# be the same. We can't include make.common because it has a lot
# of other garbage. 
FCOMPILE = $(F77) -c $(F_INC) $(FFLAGS)
UCC = cc
UCFLAGS =
all: setparams 

# setparams creates an npbparam.h file for each benchmark 
# configuration. npbparams.h also contains info about how a benchmark
# was compiled and linked
# DOB: use HOST_CC for this, because setparams runs on the compile machine
HOST_CC=$(UCC) $(UCFLAGS)
setparams: setparams.c ../config/make.def
	$(HOST_CC) $(HOST_CFLAGS) -c setparams.c
	$(HOST_CC) $(HOST_LDFLAGS) -o setparams setparams.o $(HOST_LIBS)


clean: 
	-rm -f setparams setparams.h npbparams.h
	-rm -f *~ *.o

