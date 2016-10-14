#!/bin/bash

# Author: Hashim Sharif
# Description: This script is specific to running miniGMG

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
export OMP_NUM_THREADS=12 # setting default for number of openMP threads per parallel region
export KMP_AFFINITY=verbose,granularity=core,compact,1

# Add paths for clang-3.8 llvm-3.8
export PATH=~/software/llvm-3.8.0.src/build/Release+Asserts/bin/:$PATH

# wllvm variables
export PATH=$work_dir/whole-program-llvm/:$PATH
export LLVM_COMPILER=clang

# Set mpicc spefic environment to use clang (instead of gcc)
export OMPI_CC=clang
export OMPI_MPICC=clang
export OMPI_CXX=clang++
export MPICH_ASYNC_PROGRESS=1
export MPICH_NEMESIS_ASYNC_PROGRESS=1
export MPICH_MAX_THREAD_SAFETY=multiple
export MPICH_GNI_USE_UNASSIGNED_CPUS=enabled
export MPICH_GNI_NDREG_MAXSIZE=10000000

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
  cd custom_tests/src/miniGMG
  mpicc -cc=wllvm -fopenmp -O3 operators.omptask.c bench.c mg.c box.c solver.c  timer.x86.c -D__MPI -D__COLLABORATIVE_THREADING=6 -o miniGMG -lm -lomp

  extract-bc miniGMG
  cp miniGMG.bc ../../bc/miniGMG.bc
  cd ../../../
  llvm-dis custom_tests/bc/miniGMG.bc -o custom_tests/ll/miniGMG.ll
fi

experimentNum=1
logs=( 1 2 3 )
tests=( miniGMG_modified  miniGMG )

if [[ $1 == "run" ]];
then
  for test in "${tests[@]}"
  do
    llvm-as custom_tests/ll/${test}.ll -o custom_tests/bc/${test}.bc
    llc custom_tests/bc/${test}.bc -o custom_tests/as/${test}.s
    CC -O3 -dynamic custom_tests/as/${test}.s -o custom_tests/bin/${test} -openmp

    for logNum in "${logs[@]}"
    do 
      logDir=exp${logNum}_miniGMG_new_${experimentNum}
      mkdir custom_tests/logs/${logDir}    
      srun --ntasks=64 --ntasks-per-node=2 --cpus-per-task=12 ./custom_tests/bin/${test}  6  2 2 2  4 4 4  &> custom_tests/logs/${logDir}/${test}.log
    done
  done
fi