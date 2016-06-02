#!/bin/sh
tuple="Failed to find config.guess"
for d in $(dirname $0)/../.. . .. ../..; do
  if test -e $d/config-aux/config.guess; then
    tuple=$($d/config-aux/config.guess 2>/dev/null)
    break;
  fi
done
if test -z "$tuple"; then
  tmp=$(config.guess 2>/dev/null)
  if test -n "$tmp"; then tuple="$tmp"; fi
fi
echo "Tuple: $tuple"
uname=$(uname -s -r)
echo "Uname: $uname"
case "$tuple" in
  *-darwin*)
    sw_vers
    ;;
  *-linux-*)
    lsb_release -d 2>/dev/null
    if test $? -ne 0; then
      for f in /etc/redhat-release /etc/SuSE-release; do
        test -e $f && cat $f
      done
      grep ^PRETTY_NAME /etc/os-release 2>/dev/null | cut -d\" -f2
    fi
    ;;
esac
exit 0
