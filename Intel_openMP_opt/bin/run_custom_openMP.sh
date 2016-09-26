#!/bin/bash

module unload PrgEnv-gnu
module load PrgEnv-intel
module load impi
module load llvm

# Add paths for custom openMP runtime
work_dir=$( pwd )
export C_INCLUDE_PATH=$work_dir/build/runtime/src/:$C_INCLUDE_PATH
export LD_LIBRARY_PATH=$work_dir/build/runtime/src/:$LD_LIBRARY_PATH
export LIBRARY_PATH=$work_dir/build/runtime/src/:$LIBRARY_PATH
export OMP_NUM_THREADS=8 # setting default for number of openMP threads per parallel region

# Add paths for clang-3.8 llvm-3.8
export PATH=~/software/llvm-3.8.0.src/build/Release+Asserts/bin/:$PATH
export OMPI_CC=clang
export OMPI_MPICC=clang
export OMPI_CXX=clang++

# Add path for modified mpicc wrapper - support for clang enabled
export PATH=$work_dir/mpicc_bin/:$PATH

# Build and execute with the mpic wrappers
mpicc -cc=clang custom_tests/MPI_waitall.c -o custom_tests/MPI_waitall_clang -fopenmp
mpirun -n 2 custom_tests/MPI_waitall_clang


#CC -S custom_tests/MPI_waitall.c -o custom_tests/MPI_waitall.s -openmp
#CC custom_tests/MPI_waitall.s  -dynamic -o custom_tests/MPI_new_static -openmp
#srun -n 2 ./custom_tests/MPI_new_static 

#CC -S custom_tests/hello.c -o custom_tests/hello.s -openmp
#CC custom_tests/hello.s  -dynamic -o custom_tests/hello_new_static -openmp
#srun -n 1 ./custom_tests/hello_new_static 

#CC custom_tests/MPI_waitall_mod.s  -dynamic -o custom_tests/MPI_new_static_mod -openmp
#srun -n 2 ./custom_tests/MPI_new_static_mod 
