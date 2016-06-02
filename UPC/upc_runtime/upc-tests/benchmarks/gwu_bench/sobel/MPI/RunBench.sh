#!/bin/sh
#
# Runs the Sobel program with different number of processors and with
# different hand optimization then collect the execution times and
# send them to upc.seas.gwu.edu.

pbsize=2048
make=gmake
threadsnum_list="1 2 4 8 16"
execenv=mpirun

rm -f $file
echo "*** MPI Sobel  -  Problem Size: ${pbsize}"
file=sobel-${pbsize}.mpi.time
rm -f ${file}
${make} clean > /dev/null
${make} IMGSIZE=${pbsize} 2>&1 > make.log && \
for i in ${threadsnum_list} ; do
	( echo -n "$i  " && ${execenv} -np $i ./sobel ) | tee -a $file
done
scp $file 128.164.159.100:upc/code/benchsuites/upc_bench/measures && \
rm $file ; echo done
