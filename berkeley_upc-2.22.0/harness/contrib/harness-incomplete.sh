#!/bin/sh
# This is a simple script to find runlists are not yet completed.
# Optional arguments indicate directories to search, default is '.'
# Flag '-q' will list the qscript(s) instead of the runlist(s)
# Exit is zero (shell true) if compilation or runs are incomplete.
if [ x"$1" = 'x-q' ] ; then
  shift;
  dash_q=1
else
  dash_q=0
fi
output=`mktemp /tmp/harn-inc.XXXXXX`
find ${*:-.} -type d -print |\
while read dir; do
  if [ -e $dir/compile.rpt ]; then
    if [ \! -e $dir/compile-complete ]; then
      result=0
      echo $dir/compile-complete missing
    fi
    find $dir -name 'qscript_*' -print |\
    while read qscript; do
      f=$dir/`perl -ne 'if (m/(runlist[0-9_]*)/) { print "$1\n"; }' -- $qscript`-complete
      if [ \! -e $f ] ; then
        if [ $dash_q = 1 ]; then
          echo $qscript incomplete
        else
          echo $f missing
        fi
      fi
    done
  fi
done | tee $output
[ -s $output ]; result=$?
rm $output
exit $result
