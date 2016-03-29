#!/bin/sh
clang-3.8 -fopenmp -I openmp/build/runtime/src -L openmp/build/runtime/src $1 -o test_bin/$2
