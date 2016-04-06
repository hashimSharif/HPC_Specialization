#!/bin/sh

List="int long float double"
List2="2"

# tests that only compile in static threads environment
staticonly="test_app_matmult.c"

# num threads for running dynamic compilation
dynthreads=2

# MuPC compiler
#upcc="mupcc -C "
#staticoption="-f "
#upcrun="mupcrun -C -n "

# Berkeley UPC compiler
upcc="upcc"
#upcc="myupcc"
#upcc="myupcc64"
staticoption="-T " 
#upcrun="upcrun -np "
#upcrun="echo upcrun -np "


for fn in test_getput*.c test_barrier*.c test_locks*.c test_memory*.c  \
	   test_string*.c test_int_*.c test_stress_*.c test_app_*.c test_globalexit.c ; do
   pg=`echo $fn | sed 's/\.c//'`
   for i in ${List} ; do
      sed 's/DATA/'$i'/' < $fn > prm.c

      if test `echo ${staticonly} | grep "${fn}"` ; then
        echo "--- $fn, dynamic threads, datatype=$i --- (test skipped)"
      else
        echo "--- $fn, dynamic threads, datatype=$i ---"
        #${upcc} prm.c 
        ${upcc} -o ${pg}-dynamic-$i prm.c 
      fi

      #${upcrun}${dynthreads} a.out

      for j in ${List2} ; do
         echo "--- $fn, $j static threads, datatype=$i ---"
         #${upcc} ${staticoption}$j prm.c 
         ${upcc} ${staticoption}$j -o ${pg}-static${j}-$i prm.c 

         #${upcrun}$j a.out
      done 
   done
done


