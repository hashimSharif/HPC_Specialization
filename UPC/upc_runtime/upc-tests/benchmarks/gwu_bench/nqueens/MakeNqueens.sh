#!/bin/sh
#
# This script will compile the N-Queen program for different thread numbers.

MAKE=gmake
EXEC=nqueen

threadsnum_list="1 2 4 8 16"

echo "Compiling and linking Sobel Edge Dectection program..."

for threads_num in ${threadsnum_list} ; do
  ${MAKE} THREADNUM=${threads_num}
  if [ ! $? -eq 0 ] ; then
    echo "Compilation with ${MAKE} failed. Reboot and try again or contact vendor. :)"
    exit 1
  fi
done

echo "Compiling complete."
