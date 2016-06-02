#!/bin/sh
# This is a simple script to report status of run.rpt and compile.rpt
(echo /fake/entry; find ${*:-.} \( -name run.rpt -o -name compile.rpt \) -print) |\
  sed -e 's:^\./::' | xargs -n1 dirname | uniq |\
  while read dir; do if [ "$dir" != '/fake' ]; then
    echo ${dir}
    echo "  Compile:"
    if [ -f "$dir/compile.rpt" ] ; then
      echo "    SUCCESS:  `grep -cw SUCCESS $dir/compile.rpt`"
      echo "      KNOWN:  `grep -cw KNOWN $dir/compile.rpt`"
      echo "        NEW:  `grep -cw NEW $dir/compile.rpt`"
    else
      echo "   No status to report"
    fi
    echo "  Run:"
    if [ -f "$dir/run.rpt" ] ; then
      s=`cat $dir/run_*.log | grep -cw SUCCESS`
      k=`cat $dir/run_*.log | grep -cw KNOWN`
      n=`cat $dir/run_*.log | grep -c  /NEW`
      t=`cat $dir/run_*.log | grep -cw TIME/NEW`
      m=`cat $dir/run_*.log | grep -cw MEM/NEW`
      echo "    SUCCESS:  $s"
      echo "      KNOWN:  $k"
      echo "        NEW:  `expr $n - $t - $m`"
      [ $t != 0 ] && echo "       TIME:  $t"
      [ $m != 0 ] && echo "        MEM:  $m"
    else
      echo "   No status to report"
    fi
    y=`find $dir -name 'runlist_*' -print | egrep 'runlist_[0-9]+_[0-9]+$' | \
       while read f; do test -e ${f}-complete || echo $f; done`
    i=`echo $y | wc -w`
    if [ "$i" -gt 0 ]; then
      echo "   + $i runlist(s) pending (`cat $y 2>/dev/null | wc -l` entries)"
    fi
  fi; done
