#!/bin/sh

# This script builds the UPC Matrix multiplication program for several numbers
# of bytes per row and several numbers of threads.


MAKE=gmake

threadsnum_list="1 2 4 8 16"

echo "Compiling and linking the UPC Matrix multiplication program..."

for threads_num in ${threadsnum_list} ; do
  ${MAKE} THREADNUM=${threads_num}
  if [ ! $? -eq 0 ] ; then
    echo "Compilation with ${MAKE} failed. Reboot and try again or contact vendor. :)"
    exit 1
  fi
done
echo "Compiling and linking completed."
