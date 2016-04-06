
# Makefile for UPC collective functions.  Produces upc_collective.o
# and, if you want, a main program for exercises various functions.
#
# P can be "PULL" or "PUSH".  See the README file for details.
# If P is undefined then it is set to PULL in each collective function.
#
# If N is null or N=0 compilation is done in the dynamic threads environment.
# If N>0 compilation is done in the static threads environment for N threads.
#
# Set DEBUG to _UPC_COLL_CHECK_ARGS to use upc_coll_err() to check function
# arguments.  Argument checking invokes two barriers.
#
# For example,  make P=PUSH N=4 DEBUG=_UPC_COLL_CHECK_ARGS
#								Feb. 6, 2004

#DEBUG = NO
DEBUG = _UPC_COLL_CHECK_ARGS

# Path to upc_collective.h

HEADER = .

# Compiler and options

UPCC = upcc
OPTIONS = 

ifeq ($(P),)
	PFLAG =
else
	PFLAG = -D$(P)
endif

ifeq ($(N),)
	THREADS = 
else
	ifeq ($(N),0)
		THREADS =
	else
		THREADS = -T $(N)
	endif
endif

PROGS = try_all try_reduce try_prefix

all	: $(PROGS)

try_all : try_all.c upc_collective.o $(HEADER)/upc_collective.h
	$(UPCC) $(OPTIONS) $(THREADS) -I$(HEADER) \
	-o try_all try_all.c upc_collective.o

try_reduce : try_reduce.c upc_collective.o $(HEADER)/upc_collective.h
	$(UPCC) $(OPTIONS) $(THREADS) -I$(HEADER) \
	-o try_reduce try_reduce.c upc_collective.o

try_prefix : try_prefix.c upc_collective.o $(HEADER)/upc_collective.h
	$(UPCC) $(OPTIONS) $(THREADS) -I$(HEADER) \
	-o try_prefix try_prefix.c upc_collective.o

upc_collective.o : upc_all_*.c upc_coll*.c $(HEADER)/upc_collective.h
	$(UPCC) $(OPTIONS) -D$(DEBUG) $(PFLAG) $(THREADS) -o upc_collective.o -I$(HEADER) \
        -c upc_collective.c

clean	:
	rm -f *.o $(PROGS)

runall	: $(PROGS)
	for t in $(PROGS); do\
	$(RUN) $(PROCS) ./$$t;\
	done
