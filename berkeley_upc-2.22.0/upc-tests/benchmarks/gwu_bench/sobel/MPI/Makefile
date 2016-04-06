# Makefile for the MPI Sobel edge detection program

MPI_INC_DIR = /usr/include
MPI_LIB_DIR = /usr/lib32
EXEC = sobel

#CC = /usr/freeware/bin/gcc
CC      = cc
CFLAGS  = -I$(MPI_INC_DIR) -g # -DDEBUG
LDFLAGS = -L$(MPI_LIB_DIR) -lmpi # -lm
ifdef IMGSIZE
CFLAGS += -DIMGSIZE=$(IMGSIZE)
else
CFLAGS += -DDYNAMIC
endif

all: $(EXEC)

$(EXEC): $(EXEC).o
	$(CC) $^ $(LDFLAGS) -o $@

$(EXEC).o: $(EXEC).c

clean:
	-rm -f $(EXEC) $(EXEC).o

.PHONY: all
