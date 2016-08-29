#!/bin/bash

module load hpctoolkit

EXP=exp14
rm -r databases/$EXP/database*
rm -r prof/$EXP/test*

tests=( 1 2 8 9 )
if [[ $1 == "build" ]] ;
then
  for test_num in "${tests[@]}"
  do
    hpclink CC src/test${test_num}.c -o build/test${test_num} -openmp
    hpcstruct build/test${test_num} -o hpcstruct/test${test_num}.hpcstruct
  done  
fi

thread_nums=( 1 4 8 16 24 32 47 )
total_threads=( 2 5 9 17 25 33 48 )
i=0

for thread_num in "${thread_nums[@]}"
do
  for test_num in "${tests[@]}"
  do 
    echo $thread_num , $test_num
    echo "threads allocated ", ${total_threads[$i]}
    export OMP_NUM_THREADS=$thread_num
    srun -n 1 -c ${total_threads[$i]}  hpcrun -o prof/$EXP/test${test_num}_${thread_num} --trace -e  REALTIME@1000  ./build/test${test_num}
    hpcprof -S hpcstruct/test${test_num}.hpcstruct  prof/$EXP/test${test_num}_${thread_num} -o databases/$EXP/database_test${test_num}_${thread_num}
  done
  i=$i+1
done

