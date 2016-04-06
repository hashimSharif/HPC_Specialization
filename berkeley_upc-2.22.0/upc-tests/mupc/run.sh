#!/bin/sh

mupcc -C -f $1 -lm $2
mupcrun -C -n $1 a.out
