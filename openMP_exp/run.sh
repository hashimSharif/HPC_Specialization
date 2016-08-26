#!/bin/bash

module load hpctoolkit

EXP=exp12
rm -r databases/$EXP/database*
rm -r prof/$EXP/test*

tests=( 1 2 3 8 9 )
if [[ $1 == "build" ]] ;
then
  for test_num in "${tests[@]}"
  do
    hpclink CC src/test${test_num}.c -o build/test${test_num} -openmp
    hpcstruct build/test${test_num} -o hpcstruct/test${test_num}.hpcstruct
  done  
fi

thread_nums=( 2 4 6 8 11 18 23 )

for thread_num in "${thread_nums[@]}"
do
  for test_num in "${tests[@]}"
  do 
    echo $thread_num , $test_num
    export OMP_NUM_THREADS=$thread_num
    srun -n 1 hpcrun -o prof/$EXP/test${test_num}_${thread_num} --trace -e  REALTIME@5000  ./build/test${test_num}
    hpcprof -S hpcstruct/test${test_num}.hpcstruct  prof/$EXP/test${test_num}_${thread_num} -o databases/$EXP/database_test${test_num}_${thread_num}
  done
done

