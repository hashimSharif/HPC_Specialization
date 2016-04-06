# Makefile for the MPI Matrix Multiplication program
# [distributed under the terms of the GPL]
#
# Usage: make NP=<number of processes> N=<n> M=<m> P=<p>

EXEC = mat

ifdef NP

MPI_INC_DIR = /usr/include
MPI_LIB_DIR = /usr/lib32

CC      = cc
CFLAGS  = -I$(MPI_INC_DIR) -g # -DDEBUG
CFLAGS += -DNUM_PROC=$(NP) -DELEM_T=double -DN=$(N) -DM=$(M) -DP=$(P)
LDFLAGS = -L$(MPI_LIB_DIR) -lmpi # -lm
#CFLAGS += -DDYNAMIC

all: $(EXEC)

$(EXEC): $(EXEC).o
	$(CC) $^ $(LDFLAGS) -o $@

$(EXEC).o: $(EXEC).c

.PHONY: all

else

error:
	@echo "NP undefined (number of MPI processes)."

.PHONY: error

endif

clean:
	-rm -f $(EXEC) $(EXEC).o

.PHONY: clean
