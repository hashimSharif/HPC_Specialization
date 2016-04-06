# Makefile for the Matrices Multiplication UPC program.
# Copyright(C) 2000-2001 Sébastien Chauvin, Ludovic Courtès.
# [released under the terms of the GNU GPL]
#
# Usage: make THREADNUM=n [OPT=o] N=n M=m P=p
#        N, M and P being the size of the edges of the matrices.

CONFIGDIR=../../../common
DEBUG_H=$(CONFIGDIR)/debug.h

include $(CONFIGDIR)/makedefs.inc

ifdef OPT
ifeq ($(OPT), PTRCAST)
UPCFLAGS += -DOPT_PTRCAST
endif
ifeq ($(OPT), PREFETCH)
UPCFLAGS += -DOPT_PREFETCH
endif
ifeq ($(OPT), ALL)
UPCFLAGS += -DOPT_ALL
endif
endif

UPCFLAGS += -DELEM_T=double -DBLOCK_BUG -DDEBUG_H=\"$(DEBUG_H)\"
UPCFLAGS += -DN=$(N) -DM=$(M) -DP=$(P)
#UPCFLAGS += -DDEBUG -g
#LDFLAGS = -lm

### Redefine CC for implicit rules

CC=$(UPC)

### Main rules

exec_prefix = mat
SRC = mat.c
OBJ = $(SRC:.c=-$(THREADNUM).o)

ifndef THREADNUM

err2:
	@echo "Error: You have to specify the threads number for this program (THREADNUM)."

else
# Specify the number of threads at compilation time

$(exec_prefix)-$(THREADNUM): $(OBJ)
	$(UPC) $< -o $@ $(LDFLAGS)

%-$(THREADNUM).o: %.c
	$(UPC) $(UPCFLAGS) -c $< -o $@

endif

#$(EXEC): $(EXEC).c
#	$(UPC) $(UPCFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -f *.o $(exec_prefix)-[0-9][0-9] $(exec_prefix)-[0-9] core

.PHONY: clean
