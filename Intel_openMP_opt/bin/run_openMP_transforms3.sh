#!/bin/bash

# Load the required modules. 
# PrgEnv-intel is required to use libomp.so instead of libgomp.so (GNU implementation)
module load llvm
module load gcc
module unload PrgEnv-gnu
module load PrgEnv-intel
module load impi         # needed for running mpicc with clang - geneting llvm bitcode
module load cray-mpich   # Compiling with CC, cray-mpich is required

# Add paths for custom openMP runtime
work_dir=$( pwd )
export C_INCLUDE_PATH=$work_dir/build/runtime/src/:$C_INCLUDE_PATH
export LD_LIBRARY_PATH=$work_dir/build/runtime/src/:$LD_LIBRARY_PATH
export LIBRARY_PATH=$work_dir/build/runtime/src/:$LIBRARY_PATH

#openMP variables. setting the thread affinity of each openMP thread to a physical core
export OMP_NUM_THREADS=20 # setting default for number of openMP threads per parallel region
export KMP_AFFINITY=verbose,granularity=core,compact,1

# Add paths for clang-3.8 llvm-3.8
export PATH=~/software/llvm-3.8.0.src/build/Release+Asserts/bin/:$PATH

# Set mpicc spefic environment to use clang (instead of gcc)
export OMPI_CC=clang
export OMPI_MPICC=clang
export OMPI_CXX=clang++
export MPICH_ASYNC_PROGRESS=1
export MPICH_NEMESIS_ASYNC_PROGRESS=1
export MPICH_MAX_THREAD_SAFETY=multiple
export MPICH_GNI_USE_UNASSIGNED_CPUS=enabled


# Add path for modified mpicc wrapper - support for clang enabled
export PATH=$work_dir/mpicc_bin/:$PATH

if [[ $1 == "build_runtime" ]] ;
then
  module load cmake
  cd build
  cmake ../
  make clean
  make
  cd ../
fi


if [[ $1 == "build" ]] ;
then
  tests=( MPI_ping_wtime )  
  for test in "${tests[@]}"
  do
    mpicc -cc=clang -c -emit-llvm custom_tests/src/${test}.c -o custom_tests/bc/${test}.bc -fopenmp
    llvm-dis custom_tests/bc/${test}.bc -o custom_tests/ll/${test}.ll
  done
fi


logDir="exp7_wtime"
numProcs=2

if [[ $1 == "run" ]] ;
then
  mkdir custom_tests/logs/${logDir}
  tests=( MPI_ping_wtime_modified  MPI_ping_wtime )
  for test in "${tests[@]}"
  do
    llvm-as custom_tests/ll/${test}.ll -o custom_tests/bc/${test}.bc
    llc custom_tests/bc/${test}.bc -o custom_tests/as/${test}.s
    CC -dynamic custom_tests/as/${test}.s -o custom_tests/bin/${test} -openmp
    srun --ntasks=${numProcs} --ntasks-per-node=1 --cpus-per-task=22 ./custom_tests/bin/${test}  &> custom_tests/logs/${logDir}/${test}.log
  done
fi
