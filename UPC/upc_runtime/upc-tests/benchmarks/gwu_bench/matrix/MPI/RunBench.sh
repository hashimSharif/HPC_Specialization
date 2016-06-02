#!/bin/sh
#
# Runs the Sobel program with different number of processors and with
# different hand optimization then collect the execution times and
# send them to upc.seas.gwu.edu.

pbsize=256
make=gmake
threadsnum_list="1 2 4 8 16"
execenv=mpirun

rm -f $file
echo "*** MPI Sobel  -  Problem Size: ${pbsize}"
file=mat-${pbsize}.mpi.time
rm -f ${file}
for i in ${threadsnum_list} ; do
	${make} clean 2>&1 > /dev/null
	${make} NP=$i M=${pbsize} N=${pbsize} P=${pbsize} 2>&1 > make.log && \
	( echo -n "$i  " && ${execenv} -np $i ./mat ) | tee -a $file
done
scp $file 128.164.159.100:upc/code/benchsuites/upc_bench/measures && \
rm $file ; echo done
