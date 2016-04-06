#!/bin/sh

# UPC Testing Suite
# Compiler testing script UpcTest.sh
#
# Usage :
#   ./UpcTest.sh <thread number> <static|dynamic>


# Overall script configuration

CC=upc
#CFLAGS="-O2 -g -DVERBOSE0 -DVERBOSE1"

#UPCC_THREADS_ARG="-fthreads "
CC_NTHREADS="$1"

RUNTIME_NTHREADS="$1"

#Maximum number of line allowed in the std error
#Necessary for the runtime system outputing 1 line all the time
STDERR_MAXL=1

# Read configuration file
CONFIG_CACHE=./config.cache
if [ ! -f ${CONFIG_CACHE} ] ; then
	echo "Configuration file ${CONFIG_CACHE} not found." >&2
	echo "Run configure.sh first." >&2
	exit 1
fi
. ${CONFIG_CACHE}
CFLAGS=${UPCC_ARGS}

# Parsing the arguments
if [ $# -ne 2 ] ; then
	echo "Usage :"
    echo "   ./UpcTest.sh <thread number> <static|dynamic>"
	exit 1
fi

if [ -z "$RUNTIME_NTHREADS" ]  ; then
  echo "Please enter a valid number of threads"
  exit
fi
[ -z "${RUNTIME}" ] || RUNTIME="${RUNTIME} `echo ${RUNTIME_ARGS}` ${RUNTIME_NTHREADS}"
#echo "RUNTIME_PATITION=\"$RUNTIME_PARTITION\""
#echo "RUNTIME_ARGS=\"$RUNTIME_ARGS\""
#echo "RUNTIME=\"$RUNTIME\"" && exit 0

if [ "$2 " = "dynamic " ] ; then
  MODE="dynamic" ;
else
  if [ "$2 " != "static " ] ; then
    echo "Please enter static or dynamic to specify the execution environment"
    exit
  fi
  MODE="static" ;
fi

# The extract program is required to display the header of each test.
# You can specify the compilation rules in a Makefile if necessary.
make extract 

if [ $MODE = "dynamic" ] ; then
  UPCC_THREADS_ARG=""
  CC_NTHREADS=""
fi


### Starting with the compiler tests ###

echo " =======================    UPC Testing Suite   ==============================="
echo " (Oct. 2001 - Version 0.96)"
echo

:> test.passed.lst
:> test.notpassed.lst


for fn in I_*.c II_*.c III_*.c IV_*.c V_*.c VI_*.c  \
          VII_*.c VIII_*.c IX_*.c X_*.c XI_*.c XII_*.c XIII_*.c ; do
  echo
  echo "--------------------- $fn test ------------------------------"
  header=`./extract $fn`
  echo "$header"
  execution=""
  compilation=""
  echo "${CC} ${CFLAGS} ${UPCC_THREADS_ARG}${CC_NTHREADS} $fn -o $fn.exec" > $fn.out
  if ${CC} ${CFLAGS} ${UPCC_THREADS_ARG}${CC_NTHREADS} $fn -o $fn.exec >>$fn.out 2>&1 ; then
    compilation="OK"
    echo -n "Test Output :"

	if [ -z "${RUNTIME}" ]; then
		cmd="./$fn.exec ${RUNTIME_THREADS_ARG}${CC_NTHREADS}"
	else
	    cmd="${RUNTIME} ./$fn.exec"
	fi
	echo "Command: \"${cmd}\"" > $fn.out
    if output=`${cmd} 2>$fn.errout` ; then
      execution=OK 
    fi      

    if [ -z "$output" ] ; then
      echo "   N/A"
    else
      echo 
      echo "$output"
      echo "$output" >> $fn.out
    fi
  else
    echo "Test Output :   N/A (Compilation error)"
	echo "[Compilation error]" >> $fn.out
  fi
  echo -n "Test result: "

  type=`echo "$header" | grep "Type:"`
  testname=`echo "$header" | grep "Test:" | cut -d \: -f 2-`

  if echo "$type" | grep -qi Positive ; then
    if [ -n "$execution" ] ; then 
      echo -n Passed
      if expr `wc -l < $fn.errout` \> $STDERR_MAXL > /dev/null ; then
        echo " but outputs in the std error."
        echo "$testname (with runtime messages)" >> test.passed.lst
      else
        echo "."
        echo "$testname" >> test.passed.lst
      fi
    else
      echo Did NOT pass.
      echo "$testname" >> test.notpassed.lst
    fi
  else
    if echo "$type" | grep -qi Compilation ; then
      if [ -z "$compilation" ] ; then
        echo Passed.
        echo "$testname" >> test.passed.lst
      else
        echo Did NOT pass.
        echo "$testname" >> test.notpassed.lst
      fi
    else
      if [ -z "$execution" ] ; then
        echo Passed.
        echo "$testname" >> test.passed.lst
      else
        echo Did NOT pass.
        echo "$testname" >> test.notpassed.lst
      fi
    fi
  fi 
  echo "------------------- $fn test end -----------------------"
done 

echo "        Test summary :"
echo "  Successful tests (test.passed.lst) :"
cat test.passed.lst
echo
echo "  Unsuccessful tests (test.notpassed.lst) :"
cat test.notpassed.lst
echo
echo
echo "====================== Test end =============================================="
