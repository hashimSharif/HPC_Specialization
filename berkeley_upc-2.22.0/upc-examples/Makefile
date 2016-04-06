# Define path to upcc and upcrun here
export UPCC = upcc
export UPCRUN = upcrun

# Supply upcc flags here, such as which network to use
export UPCC_FLAGS =
#export UPCC_FLAGS = -network mpi

DIRS = cpi doublereduce laplace mg
TOP = $(shell pwd)
THREADS=2
examples:
	for d in $(DIRS); do\
	(cd $$d && $(MAKE))\
	done

clean:
	for d in $(DIRS); do\
	(cd $$d && $(MAKE) clean)\
	done

runall:
	for d in $(DIRS); do\
	(cd $$d && $(MAKE) run THREADS=$(THREADS))\
	done

