# Makefile for the UPC N-Queens program
# Copyright(C) 2000-2001 Sebastien Chauvin, Tarek El-Ghazawi.
# [released under the terms of the GNU GPL]
#
# Usage: make [THREADNUM=n]

CONFIGDIR=../../../common
DEBUG_H=$(CONFIGDIR)/debug.h
include $(CONFIGDIR)/makedefs.inc

UPCFLAGS+=-DDEBUG_H=\"$(DEBUG_H)\"
#UPCFLAGS+=-DDEBUG

UPC_EXEC    = nqueens
UPC_SRC     = gen.c sched.c nqueens.c
SEQ_EXEC    = nqueens-seq
SEQ_SRC     = nqueens-seq.c
SEQ_OBJ_UPC = $(SEQ_SRC:%.c=%.upc.o)
SEQ_OBJ_CC  = $(SEQ_SRC:%.c=%.cc.o)

ifndef THREADNUM
# Don't specify the number of threads at compilation time
UPC_OBJ  = $(UPC_SRC:%.c=%.upc.o)
upc_exec = $(UPC_EXEC)
else
# Specify the number of threads at compilation time
UPC_OBJ  = $(UPC_SRC:%.c=%.$(THREADNUM).upc.o)
upc_exec = $(UPC_EXEC)-$(THREADNUM)
endif

### Main rules

all: $(upc_exec) # $(SEQ_EXEC)-upc $(SEQ_EXEC)-cc


$(upc_exec): $(UPC_OBJ)
	$(UPC) -o $@ $^ $(LDFLAGS)

$(SEQ_EXEC)-upc: $(SEQ_OBJ_UPC)
	$(UPC) -o $@ $^ $(LDFLAGS)

$(SEQ_EXEC)-cc: $(SEQ_OBJ_CC)
	$(CC) -o $@ $^ $(LDFLAGS)

ifdef THREADNUM
%.$(THREADNUM).upc.o: %.c
	$(UPC) $(UPCFLAGS) -c $< -o $@
endif

%.upc.o: %.c
	$(UPC) $(UPCFLAGS) -c $< -o $@

%.cc.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

ifdef THREADNUM
clean :
	-rm -f $(UPC_EXEC) $(UPC_OBJ) $(SEQ_OBJ_CC) $(SEQ_OBJ_UPC) $(SEQ_EXEC)-upc $(SEQ_EXEC)-cc core
else
clean:
	-rm -f *.o
endif

.PHONY: clean all
