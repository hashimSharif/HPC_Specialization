#!/bin/bash
# Author : Hashim Sharif

# set LD_LIBRARY PATH for clang to link to the openMP runtime dynamically
work_dir=$( pwd )
export C_INCLUDE_PATH=$work_dir/build/runtime/src/:$C_INCLUDE_PATH
export LD_LIBRARY_PATH=$work_dir/build/runtime/src/:$LD_LIBRARY_PATH
export LIBRARY_PATH=$work_dir/build/runtime/src/:$LIBRARY_PATH
export OMP_NUM_THREADS=8 # setting default for number of openMP threads per parallel region
echo $LD_LIBRARY_PATH

tests=( omp_for_reduction_opt omp_for_reduction hello_opt hello )
sources=( omp_for_reduction hello )

# build the source to assembly modules
if [[ $1 == "build-as" ]] ;
then
    for source in "${sources[@]}"
    do
	clang -c custom_tests/${source}.c -S -o custom_tests/${source}.s -fopenmp
    done  
fi

# build the assembly modules and run the tests - saving output under /test_logs
if [[ $1 == "build" ]] ;
then
    for test in "${tests[@]}"
    do
	clang custom_tests/${test}.s -o custom_tests/${test} -fopenmp -lm
    done  

    thread_counts=( 8 )

    for thread_count in "${thread_counts[@]}"
    do
	for test in "${tests[@]}"
	do 
	    echo $thread_count, $test
	    export OMP_NUM_THREADS=$thread_count
	    ./custom_tests/$test |& tee test_logs/$test
	done
    done
fi
