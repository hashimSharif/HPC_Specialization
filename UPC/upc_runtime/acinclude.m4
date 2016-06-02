AC_DEFUN([cv_prefix],[upcr_cv_])

dnl Berkeley UPC package version number
dnl See README.developers for the version numbering scheme
AC_DEFUN([UPCR_VERSION_LIT],[2.22.0])

AC_DEFUN([UPCR_INIT_VERSIONS], [

  dnl set this to default translator for this release
  default_translator="http://upc-translator.lbl.gov/upcc-2.22.0.cgi"

  dnl version of the runtime spec adhered to
  UPCR_RUNTIME_SPEC_MAJOR=3
  UPCR_RUNTIME_SPEC_MINOR=12
  RUNTIME_SPEC="${UPCR_RUNTIME_SPEC_MAJOR}.${UPCR_RUNTIME_SPEC_MINOR}"

  UPCR_VERSION=UPCR_VERSION_LIT
  AC_DEFINE_UNQUOTED(UPCR_VERSION,"$UPCR_VERSION")
  AC_SUBST(UPCR_VERSION)
  AC_SUBST(RUNTIME_SPEC)
  AC_DEFINE_UNQUOTED(UPCR_RUNTIME_SPEC_MAJOR,$UPCR_RUNTIME_SPEC_MAJOR)
  AC_DEFINE_UNQUOTED(UPCR_RUNTIME_SPEC_MINOR,$UPCR_RUNTIME_SPEC_MINOR)
])

dnl code to run very early in configure
AC_DEFUN([UPCR_EARLY_INIT],[

# Implement option and env var aliases for b/w compatibility
if test x${upcri_did_aliases} != x1; then
 if test [$]# -gt 0; then 
  for upcri_arg in "[$]@"; do
    upcri_old=[`expr "x$upcri_arg" : 'x\([^=]*\)'`]
    upcri_new="$upcri_old"
    case "$upcri_arg" in
      --with-gccupc=*) upcri_new="--with-gupc" ;;
      --with-gccupc-version=*) upcri_new="--with-gupc-version" ;;
      GCCUPC_TRANS=*) upcri_new="GUPC_TRANS" ;;
    esac
    if test "$upcri_new" != "$upcri_old"; then
      echo "WARNING: rewriting deprecated option/setting $upcri_old as $upcri_new" 1>&2
      upcri_arg=`echo "x$upcri_arg" | sed s/x$upcri_old/$upcri_new/`
    fi
    set guard "[$]@" "$upcri_arg"; shift; shift;
  done
 fi

  for upcri_var in GCCUPC_TRANS:GUPC_TRANS
  do
    upcri_old=`expr "x$upcri_var" : 'x\(.*\):'`
    upcri_old_val=`eval echo \\${$upcri_old}`
    if test -n "$upcri_old_val"; then
      upcri_new=`expr "x$upcri_var" : 'x.*:\(.*\)'`
      upcri_new_val=`eval echo \\${$upcri_new}`
      if test "$upcri_old_val" = "$upcri_new_val"; then
        : # Nothing to do
      elif test -n "$upcri_new_val"; then
        echo "WARNING: ignoring deprecated envronment variable $upcri_old because $upcri_new is already set" 1>&2
      else
        echo "WARNING: using deprecated environment variable $upcri_old to set $upcri_new" 1>&2
        eval $upcri_new='"$upcri_old_val"'
        export $upcri_new
      fi
    fi
  done

  upcri_did_aliases=1
  export upcri_did_aliases
fi

  # default multiconf setting:
  upcri_multiconf=1
  for upcri_arg in "[$]@"; do
    case "$upcri_arg" in
      --with-multiconf-magic=* | -with-multiconf-magic=*) 
        dnl set with_multiconf_magic just in case configure ever starts ignoring unrecognized options
        with_multiconf_magic=`expr "x$upcri_arg" : 'x[^=]*=\(.*\)'`
        upcri_multiconf_magic=1 ;;
      --with-multiconf* | -with-multiconf*) 
        upcri_multiconf=1 ;;
      --without-multiconf | -without-multiconf) 
        upcri_multiconf=0 ;;
      --reboot | -reboot | --reboot=* | -reboot=*) 
        upcri_reboot=1 ;;
      -help | --help | --hel | --he | -h | -help=r* | --help=r* | --hel=r* | --he=r* | -hr* | -help=s* | --help=s* | --hel=s* | --he=s* | -hs*)
        upcri_help=1 ;;
    esac
  done
  if ( test "$upcri_multiconf" = "1" || test "$upcri_help" = "1" || test "$upcri_reboot" = "1" ) \
     && test "$upcri_multiconf_magic" != "1" ; then
    # find a reasonable perl
    for upcri_perl in $PERL perl /usr/bin/perl /bin/perl /usr/local/bin/perl ; do
      if test "`$upcri_perl -v 2>&1 > /dev/null`" = "" ; then
        break
      fi
    done
    if test "[$]0" = "configure" ; then
      srcdir="."
    else
      srcdir=`echo "[$]0" | "$upcri_perl" -pe 's@/[[^/]]+[$]@@'`
    fi
    if test "$upcri_help" = "1" ; then
      exec "$upcri_perl" "$srcdir/multiconf.pl" --help "[$]@"
    elif test "$upcri_reboot" = "1" && test "$upcri_multiconf" != "1"; then
      set -x
      exec "$upcri_perl" "$srcdir/multiconf.pl" --reboot --without-multiconf "[$]@"
      echo "ERROR: failed to exec multiconf" 1>&2
      exit 1
    else
      echo "Starting multiconf..."
      set -x
      exec "$upcri_perl" "$srcdir/multiconf.pl" "[$]@"
      echo "ERROR: failed to exec multiconf" 1>&2
      exit 1
    fi
  fi
  if test "$upcri_help" != "1" && test "$upcri_hello_shown" != 1; then
    # avoid duplicate messages caused by configure re-execing itself (eg on Tru64)
    upcri_hello_shown=1
    export upcri_hello_shown
    echo 'Configuring Berkeley UPC Runtime version UPCR_VERSION_LIT with the following options:'
    echo "  " "[$]@"
  fi
])

dnl co-opt the AC_REVISION mechanism to run some code very early
AC_REVISION([
UPCR_EARLY_INIT
dnl swallow any autoconf-provided revision suffix: 
echo > /dev/null \
])

dnl uniform interface to GASNET_TRY_CACHE_{RUN,EXTRACT}_EXPR
dnl UPCR_TRY_GET_INT(description,cache_name,headers,expression,result_variable,default)
AC_DEFUN([UPCR_TRY_GET_CPP_INT],[dnl
  if test "$cross_compiling" = "no" ; then
    GASNET_TRY_CACHE_RUN_EXPR([$1],[$2],[$3],[val = $4],[$5])
    if test x"$[$5]" = 'xno'; then [$5]='[$6]'; fi
  else
    GASNET_IFDEF([$4],[
      GASNET_TRY_CACHE_EXTRACT_EXPR([$1 (binary probe)],[$2],[$3],[$4],[$5])
    ],[[$5]='[$6]'])
  fi
])
