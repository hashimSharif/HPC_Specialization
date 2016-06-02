#!/bin/bash -l

#SBATCH -p debug     
#SBATCH -N 64        
#SBATCH -t 00:10:00  x
#SBATCH -J my_job    
#SBATCH -L SCRATCH

srun -n 64 -N 64 ../pin -t ../source/tools/SimpleExamples/obj-intel64/opcodemix.so  -- ../bin/upcagg_pc 7 1 1 1 4 4 4