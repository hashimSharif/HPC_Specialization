#!/bin/bash

module load hpctoolkit

if [[ $1 == "build" ]] ;
then
  hpclink CC src/test1.c -o build/test1 -openmp
  hpclink CC src/test2.c -o build/test2 -openmp
  hpclink CC src/test3.c -o build/test3 -openmp
  hpcstruct build/test1 -o hpcstruct/test1.hpcstruct
  hpcstruct build/test2 -o hpcstruct/test2.hpcstruct
  hpcstruct build/test3 -o hpcstruct/test3.hpcstruct
fi

thread_nums=( 2 4 8 12 24 )

for thread_num in "${thread_nums[@]}"
do
  echo $thread_num
  export OMP_NUM_THREADS=$thread_num
  srun -n 4 -N 4 hpcrun -o prof/test1_$thread_num --trace -e WALLCLOCK@5  ./build/test1
  srun -n 1 hpcrun -o prof/test2_$thread_num --trace -e WALLCLOCK@5  ./build/test2
  srun -n 1 hpcrun -o prof/test3_$thread_num --trace -e WALLCLOCK@5  ./build/test3
  hpcprof -S hpcstruct/test1.hpcstruct  prof/test1_$thread_num -o databases/database_test1_$thread_num
  hpcprof -S hpcstruct/test2.hpcstruct  prof/test2_$thread_num -o databases/database_test2_$thread_num
  hpcprof -S hpcstruct/test3.hpcstruct  prof/test3_$thread_num -o databases/database_test3_$thread_num
done

