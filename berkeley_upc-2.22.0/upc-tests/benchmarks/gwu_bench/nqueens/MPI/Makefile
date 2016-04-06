# Makefile for the MPI version of the N-Queen program
# Copyright(C) 2000-2001 Sebastien Chauvin, Tarek El-Ghazawi.
# [released under the terms of the GNU GPL]
#
# You need to define UINT64 as an unsigned 64 bit-integer type (otherwise
# you will not be able to run the program).
#
# Note: "long long" is 64 bits on the SGI Origin 2k/Irix 6.5/mips-4

MPI_INC_DIR = /usr/include
MPI_LIB_DIR = /usr/lib32

CC      = cc
CFLAGS  = -I$(MPI_INC_DIR) -g -DDEBUG
LDFLAGS = -L$(MPI_LIB_DIR) -lmpi # -lm
CFLAGS += -DUINT64="unsigned long long"

# GCC settings below
#CC = gcc
#CFLAGS = -Wall -I/usr/include -I$(MPIDIR)/include #-DDEBUG
#LDFLAGS = -L$(MPIDIR)/lib -lmpich
#CFLAGS += -DUINT64="unsigned long long"
#CFLAGS += -DUINT64="unsigned long"


EXEC = nqueens
SRC = gen.c sched.c nqueens.c
OBJ = $(SRC:.c=.o)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean :
	rm -f $(OBJ) $(EXEC)

.PHONY: clean
