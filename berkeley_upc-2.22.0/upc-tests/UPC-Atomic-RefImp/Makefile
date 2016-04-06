UPCC ?= upcc
UPCRUN ?= upcrun
THREADS ?= 4
UPCFLAGS ?= -pthreads 
UPCFLAGS := $(UPCFLAGS) -I.
# UPCFLAGS := $(UPCFLAGS) -save-temps
# UPCFLAGS := $(UPCFLAGS) -DFORCE_NDEBUG
# UPCFLAGS := $(UPCFLAGS) -DLOCK_CENTRAL
# UPCFLAGS := $(UPCFLAGS) -DLOCK_FULLDIR
# UPCFLAGS := $(UPCFLAGS) -DLOCK_DIR

LIB = upc_atomic.o

SRCS = \
	atomic_test_simple.upc 	

TGTS   = $(SRCS:.upc=)

.PHONY: all lib clean veryclean run force

all: $(TGTS)

lib: $(LIB)

SPECDIR := ../spec1.3
atomic_test.o: $(SPECDIR)/atomic_test.upc $(SPECDIR)/atomic_test_help.upc upc_atomic.h $(LIB)
	$(UPCC)	$(UPCFLAGS) -o $@ -c $< -I. -I$(SPECDIR)

%.o: %.upc upc_atomic.h
	$(UPCC)	$(UPCFLAGS) -o $@ -c $<

%: %.o $(LIB)
	$(UPCC) $(UPCFLAGS) -o $@ $< $(LIB)

run: $(TGTS)
	@for f in $(TGTS); do \
		echo $(UPCRUN) -np $(THREADS) $$f ; \
        	$(UPCRUN) -np $(THREADS) $$f ; \
	done

run-error: atomic_errors
	@t=1; export UPC_NO_WARN=1; \
	 while [ $$t -le 30 ] ; do \
	   echo $(UPCRUN) -np $(THREADS) $< $$t ; \
           $(UPCRUN) -np $(THREADS) $< $$t && exit 1; \
	   t=`expr $$t + 1`; \
	done

clean:
	rm -f *.o *.stackdump *.i *.trans.c
	
veryclean: clean
	rm -f $(TGTS)

