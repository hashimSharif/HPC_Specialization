#!/bin/bash
mpicc -cc=clang -emit-llvm -fopenmp -c box.c
mpicc -cc=clang -emit-llvm -fopenmp -c mg.c
mpicc -cc=clang -emit-llvm -fopenmp -c solver.c
mpicc -cc=clang -emit-llvm -fopenmp -c timer.x86.c
mpicc -cc=clang -emit-llvm -fopenmp -c operators.omptask.c

llc box.bc
llc solver.bc
llc mg.bc
llc timer.x86.bc
llc operators.omptask.bc

CC -O3 -openmp mg.s box.s solver.s operators.omptask.s timer.x86.s -D__MPI -D__COLLABORATIVE_THREADING=6 -o run.edison.omptask
#mg.c box.c solver.c operators.omptask.c  timer.x86.c -D__MPI -D__COLLABORATIVE_THREADING=6 -o run.edison.omptask -lm