#!/bin/sh
#
# Runs the N-Queens program with different number of processors and with
# different hand optimization then collect the execution times and
# send them to upc.seas.gwu.edu.

# Between 12 and 16
pbsize=16
make=gmake
threadsnum_list="1 2 4 8 16"
execenv=mpirun

rm -f $file
echo "*** MPI N-Queens  -  Problem Size: ${pbsize}"
file=nqueens-${pbsize}.mpi.time
rm -f ${file}
${make} clean 2>&1 > /dev/null
${make} 2>&1 > make.log && \
for i in ${threadsnum_list} ; do
	( echo -n "$i  " && ${execenv} -np $i ./nqueens ${pbsize} ) | tee -a $file
done
scp $file 128.164.159.100:upc/code/benchsuites/upc_bench/measures && \
rm $file ; echo done
