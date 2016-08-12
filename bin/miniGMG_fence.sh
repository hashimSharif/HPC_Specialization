#!/bin/bash -l

#SBATCH -p debug     
#SBATCH -N 64        
#SBATCH -t 00:10:00  x
#SBATCH -J my_job    
#SBATCH -L SCRATCH

srun -n 64 -N 64 ../PIN/pin -t ../PIN/source/tools/ManualExamples/obj-intel64/fencecount.so   -- ../test/upcagg_pc 7 1 1 1 4 4 4