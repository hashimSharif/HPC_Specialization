#!/bin/sh

srun -n 1 valgrind --tool=callgrind $1