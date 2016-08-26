#!/bin/bash

module load hpctoolkit

EXP=exp10
rm -r databases/$EXP/diff/*

tests=( 1 2 3 8 9 )
threads1=( 2 4 8 12 )
threads2=( 4 8 12 24 )
i=0

for thread_num in "${threads1[@]}"
do
  for test_num in "${tests[@]}"
  do 
    hpcprof -S hpcstruct/test${test_num}.hpcstruct  prof/$EXP/test${test_num}_${thread_num}   prof/$EXP/test${test_num}_${threads2[$i]}  -o databases/$EXP/diff/database_diff${test_num}_${thread_num}_${threads2[$i]}
  done
  ((i++))
done

