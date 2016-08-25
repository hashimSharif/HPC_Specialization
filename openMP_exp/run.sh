#!/bin/bash

module load hpctoolkit

rm -r databases/exp3/database*
rm -r prof/exp3/test*

tests=( 1 2 3 4 5 )
if [[ $1 == "build" ]] ;
then
  for test_num in "${tests[@]}"
  do
    hpclink CC src/test${test_num}.c -o build/test${test_num} -openmp
    hpcstruct build/test${test_num} -o hpcstruct/test${test_num}.hpcstruct
  done  
fi

thread_nums=( 2 4 8 12 24 )

for thread_num in "${thread_nums[@]}"
do
  for test_num in "${tests[@]}"
  do 
    echo $thread_num , $test_num
    export OMP_NUM_THREADS=$thread_num
    srun -n 1 hpcrun -o prof/exp3/test${test_num}_${thread_num} --trace -e WALLCLOCK@1  ./build/test${test_num}
    hpcprof -S hpcstruct/test${test_num}.hpcstruct  prof/exp3/test${test_num}_${thread_num} -o databases/exp3/database_test${test_num}_${thread_num}
  done
done

