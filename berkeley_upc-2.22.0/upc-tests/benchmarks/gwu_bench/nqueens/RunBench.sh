#!/bin/sh
#
# Runs the N-Queens program with different number of processors and with
# different hand optimization then collect the execution times and
# send them to upc.seas.gwu.edu.

pbsize=16
make=gmake
threadsnum_list="1 2 4 8 16"
execenv=""

rm -f $file
echo "*** Problem Size: ${pbsize}"
file=nqueens-${pbsize}.time
rm -f ${file}
${make} clean > /dev/null
for i in ${threadsnum_list} ; do
	echo -n "Compiling for ${i} threads..." && \
	( ${make} THREADNUM=${i} 2>&1 > make.log ) && \
	echo " done" && \
	( ( echo -n "$i  " && ${execenv} ./nqueens-$i ${pbsize} ) | tee -a ${file} )
done
scp $file 128.164.159.100:upc/code/benchsuites/upc_bench/measurement && \
rm $file ; echo done
