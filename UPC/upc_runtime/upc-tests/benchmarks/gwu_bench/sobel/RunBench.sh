#!/bin/sh
#
# Runs the Sobel program with different number of processors and with
# different hand optimization then collect the execution times and
# send them to upc.seas.gwu.edu.

pbsize=2048
make=gmake
threadsnum_list="1 2 4 8 16"
execenv=""

rm -f $file
for opt in NONE PTRCAST ALL ; do
	echo "*** Optimization: ${opt}   Problem Size: ${pbsize}"
	file=sobel-${pbsize}-${opt}.time
	rm -f ${file}
	${make} clean > /dev/null
	for i in ${threadsnum_list} ; do
		echo -n "Compiling for ${i} threads..." && \
		( ${make} THREADNUM=${i} OPT=${opt} IMGSIZE=${pbsize} \
		  2>&1 > make.log ) && \
		echo " done" && \
		( ( echo -n "$i  " && ${execenv} ./sobel-$i ) | tee -a $file )
	done
	scp $file 128.164.159.100:upc/code/benchsuites/upc_bench/measures && \
	rm $file ; echo done
done
