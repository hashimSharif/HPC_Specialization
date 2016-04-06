# Makefile for the Sobel UPC program.
# Copyright(C) 2000-2001 Sébastien Chauvin, Ludovic Courtès.
# [released under the terms of the GNU GPL]
#
# Usage: make THREADNUM=n [IMGSIZE=m] [OPT=o]

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

UPCFLAGS += -DBLOCK_BUG -DDEBUG_H=\"$(DEBUG_H)\"
#UPCFLAGS += -DDEBUG -g
LDFLAGS = -lm

### Redefine CC for implicit rules

CC=$(UPC)

### Main rules

exec_prefix = sobel
SRC = sobel.c
OBJ = $(SRC:.c=-$(THREADNUM).o)

# IMGSIZE can be defined at compilation time to use static allocation
# of arrays (does not work with GNU-UPC/Origin 1.8).
ifdef IMGSIZE
UPCFLAGS += -DIMGSIZE=$(IMGSIZE)
else
UPCFLAGS += -DDYNAMIC
endif

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
