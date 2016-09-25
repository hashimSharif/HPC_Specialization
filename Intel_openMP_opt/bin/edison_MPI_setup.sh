#!/bin/bash

#module unload PrgEnv-gnu
#module load PrgEnv-intel
#module load llvm

work_dir=$( pwd )
export C_INCLUDE_PATH=$work_dir/build/runtime/src/:$C_INCLUDE_PATH
export LD_LIBRARY_PATH=$work_dir/build/runtime/src/:$LD_LIBRARY_PATH
export LIBRARY_PATH=$work_dir/build/runtime/src/:$LIBRARY_PATH
export OMP_NUM_THREADS=8 # setting default for number of openMP threads per parallel region

CC custom_tests/hello.c  -dynamic -o custom_tests/hello_new_static -openmp
srun -n 1 ./custom_tests/hello_new_static 

