#!/bin/sh
# cupc2c_install.sh (Wim Lavrijsen, WLavrijsen@lbl.gov)

#
#  Install the Berkely UPC run-time with clang-based cupc2c as the UPC code
#+ converter under $PWD/upcr.
#
#  Use cupc2c_install.sh -h to see all options.
#
#  This code can be used as documentation for the required steps. For more
#+ detailed install-instructions, to allow customization, see:
#    https://github.com/Intrepid/clang-upc/wiki
#    http://upc.lbl.gov/download/berkeley_upc-2.18.2/INSTALL.TXT
#
#  Sources are retrieved from:
#    https://upc-bugs.lbl.gov/nightly/upc/
#

# clang-upc and berkeley upc versions
CUPC_PKG=clang-upc-3.4.0-1
BUPC_PKG=berkeley_upc-2.18.2

#  script version
VERSION=0.9

######## parameters
#  possible error codes
E_SUCCESS=0
E_INVALID_OPTION=80
E_NO_DOWNLOADER=81
E_FILES_NOT_FOUND=82
E_LLVM_BUILD_FAILED=84
E_UPCR_BUILD_FAILED=86

#  sources
LLVM_SOURCE_BASE=http://upc.lbl.gov/download/clang-upc
LLVM_SOURCE=${CUPC_PKG}.tar.gz
UPCR_SOURCE_BASE=http://upc.lbl.gov/download/release
UPCR_SOURCE=${BUPC_PKG}.tar.gz

######## prerequisites
function check_prereq() {
   if command -v "$1" >/dev/null 2>&1; then
      eval "$2=1"
   else
      eval "$2=0"
   fi
}

#  need a tool to download the sources
check_prereq 'wget'   'HAS_WGET'
check_prereq 'curl'   'HAS_CURL'
check_prereq 'python' 'HAS_PYTHON'

if [ $HAS_WGET -eq 0 ] && [ $HAS_CURL -eq 0 ] && [ $HAS_PYTHON -eq 0 ]; then
   # no downloader, request that the files are pulled in through other
   # means, if not already done so
   if ! [ -f "$LLVM_SOURCE" ] || ! [ -f "$UPCR_SOURCE" ]; then
      read -d '' no_files_msg <<- EOF
No downloader (wget, curl, or python) available and no source files.

Please retrieve:
   $LLVM_SOURCE_BASE/$LLVM_SOURCE
   $UPCR_SOURCE_BASE/$UPCR_SOURCE
EOF
      echo "$no_files_msg"
      exit $E_FILES_NOT_FOUND
   fi
fi

#  need cmake for the full build of clang-upc
check_prereq 'cmake'  'HAS_CMAKE'


######## options
function show_usage() {
   read -d '' help_msg <<- EOF
Usage: `basename $0` [OPTION]
Install the Berkely UPC run-time with clang-based cupc2c.

Available options:
  -h       | --help           this help message
  --enable-dbg                debug build of cupc2c
  --enable-opt                optimized (release) build of cupc2c (default)
  -j <N>   | --jobs <N>       allow N build processes at once (default=2)
  -p <dir> | --prefix <dir>   install directory to use [default=$PWD/upcr]
  -v       | --verbose        verbose output
  -vv, -vvv                   more verbose, and even more verbose output

  --enable-mpi                off by default, as clang-upc does not support it
  --enable-clang-upc          full llvm-upc/clang-upc builds (requires cmake)

  -- [ARGS]                   ARGS will be passed to UPC runtime configure step
EOF
   echo "$help_msg"
}

ENABLE_DBG=0
ENABLE_OPT=1
DISABLE_MPI="--disable-mpi"
FULL_CLANG_UPC_BUILD=0
NPROCS=2
INSTALL_PREFIX=''
VERBOSE=0
UPCR_CONFIG_EXTRA=''
while [ $# -gt 0 ]
do
   case "$1" in
      --enable-dbg)
         ENABLE_DBG=1
         ENABLE_OPT=0
         ;;
      --enable-opt)
         ENABLE_DBG=0
         ENABLE_OPT=1
         ;;
      --enable-mpi)
         DISABLE_MPI=''
         ;;
      --enable-clang-upc)
         [ $HAS_CMAKE -eq 1 ] || {
            echo "ERROR: --enable-clang-upc requires cmake (can not find cmake)"
            echo ; show_usage
            exit $E_INVALID_OPTION
         }
         FULL_CLANG_UPC_BUILD=1
         ;;
      -j|--jobs)
         NPROCS="$2"
         case "$NPROCS" in
            ''|*[!0-9]*)
               echo "ERROR: -j | --jobs requires an integer argument"
               echo ; show_usage
               exit $E_INVALID_OPTION
               ;;
         esac
         shift
         ;;
      -h|--help)
         show_usage
         exit $E_SUCCESS
         ;;
      -p|--prefix)
         [ "$2" ] || {
            echo "ERROR: -p | --prefix expects an argument"
            echo ; show_usage
            exit $E_INVALID_OPTION
         }
         INSTALL_PREFIX="$2"
         shift
         ;;
      -v|--verbose)
         VERBOSE=1 
         ;;
      -vv)
         VERBOSE=2
         ;;
      -vvv)
         VERBOSE=3
         ;;
      --version)
         echo "$VERSION"
         exit $E_SUCCESS
         ;;
      --)
         shift
         UPCR_CONFIG_EXTRA="$@"
         break
         ;;
      --*|-?)
         read -d '' error_msg <<- EOF
$0: unrecognized option: \'$1\'
Try \'`basename $0` -h\' for more information.
EOF
         echo "$error_msg"
         exit $E_INVALID_OPTION
         ;;
      -*)
         splitopt=$1
         shift
         set -- $(echo "$splitopt" | cut -c 2- | sed 's/./-& /g') "$@"
         continue
         ;;
      *)
         break
         ;;
   esac
   shift
done

if [ $VERBOSE -ge 3 ]; then
   VERBOSE_V='v'
   VERBOSE_ARG='-v'
   VERBOSE_LONGARG='--verbose'
   VERBOSE_MAKE='VERBOSE=1'
fi


######## relevant directories and global vars
#  These may be used in command arg to sub-shells, thus need exporting. All
#+ temporary directories will be relative to $WORKDIR (pwd).
export WORKDIR="$PWD"
if [ "$INSTALL_PREFIX" == '' ]; then
   export INSTALLDIR="$WORKDIR/upcr"
elif [ "${INSTALL_PREFIX:0:1}" != '/' ]; then
   export INSTALLDIR="$WORKDIR/$INSTALL_PREFIX"
else
   export INSTALLDIR="$INSTALL_PREFIX"
fi
export LOGDIR="$WORKDIR/logs"


######## helpers
#  log with marker to distinguish our messages from that of other output
function logmsg() {
   local _LOG_MARKER='[cupc2c_install]'
   echo "$_LOG_MARKER $1"
}

function on_error() {
   local _ERROR_MARKER='ERROR:'
   [ -z "$1" ] || cat "$1"
   logmsg "$_ERROR_MARKER $2"
   exit $3
}

function run_command() {
   [ $VERBOSE -ge 1 ] && logmsg "$1"
   [ -d "$LOGDIR" ] || mkdir -p "$LOGDIR"
   if [ $VERBOSE -lt 2 ]; then
      eval $1 1>"$LOGDIR/$2.log" 2>"$LOGDIR/$2.err" || {
         on_error "$LOGDIR/$2.err" "$3" $4
      }
   else
      eval $1 2>"$LOGDIR/$2.err" || {
        on_error "$LOGDIR/$2.err" "$3" $4
      } | tee "$LOGDIR/$2.log"
      [ ${PIPESTATUS[0]} -ne 0 ] && exit ${PIPESTATUS[0]}
   fi
}

######## start working
logmsg "installing under: $INSTALLDIR"
logmsg "clang-upc2c: $CUPC_PKG"
logmsg "upcc driver: $BUPC_PKG"


######## getting sources
#  Figure out a down-loader; curl is common on Mac, it and wget are likely
#+ available on Linux; and get the required files.
logmsg "fetching sources ... "
if [ $HAS_WGET -eq 1 ]; then
   run_command "wget -N --tries=3 $VERBOSE_ARG $LLVM_SOURCE_BASE/$LLVM_SOURCE" \
      "wget_llvm" "failed to retrieve $LLVM_SOURCE" $E_FILES_NOT_FOUND
   run_command "wget -N --tries=3 $VERBOSE_ARG $UPCR_SOURCE_BASE/$UPCR_SOURCE" \
      "wget_upcr" "failed to retrieve $UPCR_SOURCE" $E_FILES_NOT_FOUND
elif [ $HAS_CURL -eq 1 ]; then
   #  curl does not seem to have an equivalent '-N' option?
   run_command "curl -Rf $VERBOSE_ARG $LLVM_SOURCE_BASE/$LLVM_SOURCE -o $LLVM_SOURCE" \
      "curl_llvm" "failed to retrieve $LLVM_SOURCE" $E_FILES_NOT_FOUND
   run_command "curl -Rf $VERBOSE_ARG $UPCR_SOURCE_BASE/$UPCR_SOURCE -o $UPCR_SOURCE" \
      "curl_upcr" "failed to retrieve $UPCR_SOURCE" $E_FILES_NOT_FOUND
elif [ $HAS_PYTHON -eq 1 ]; then
   #  TODO: python should be able to do time-stamping
   run_command "python -sc$VERBOSE_V 'import urllib; urllib.urlretrieve(\"$LLVM_SOURCE_BASE/$LLVM_SOURCE\", \"$LLVM_SOURCE\")'" \
      "urllib_llvm" "failed to retrieve $LLVM_SOURCE" $E_FILES_NOT_FOUND
   run_command "python -sc$VERBOSE_V 'import urllib; urllib.urlretrieve(\"$UPCR_SOURCE_BASE/$UPCR_SOURCE\", \"$UPCR_SOURCE\")'" \
      "urllib_upcr" "failed to retrieve $UPCR_SOURCE" $E_FILES_NOT_FOUND
fi

if ! [ -f "$LLVM_SOURCE" ] || ! [ -f "$UPCR_SOURCE" ]; then
   on_error "no source files; exiting ... " $E_FILES_NOT_FOUND
fi


######## extract llvm-upc sources
logmsg "extracting ${CUPC_PKG} sources ... "
run_command "tar zxf$VERBOSE_V $LLVM_SOURCE" \
    "extract_llvm" "failed to extract $LLVM_SOURCE" $E_FILES_NOT_FOUND


######## configure and build llvm-upc opt/dbg
#  There are two possible ways of configuring: cmake, or the supplied
#+ configure script. The former is used if --enable-clang-upc is selected,
#+ the latter otherwise (the configure script will only build clang and
#+ clang-upc2c).
function build_llvm() {
   logmsg "now building ${CUPC_PKG} ($1) ... "
   mkdir -p "$WORKDIR/build/llvm_${1}"
   cd "$WORKDIR/build/llvm_${1}"
   logmsg " ... configuring ${CUPC_PKG} ... "
   if [ $FULL_CLANG_UPC_BUILD -eq 1 ]; then
      run_command "cmake $WORKDIR/${CUPC_PKG} -DCMAKE_INSTALL_PREFIX:PATH=$INSTALLDIR/$1 -DLLVM_TARGETS_TO_BUILD:=host -DCMAKE_BUILD_TYPE:=$2" \
         "configure_llvm_${1}" "configuration of llvm/clang failed" $E_LLVM_BUILD_FAILED
   else
      if [ "$2" == "Debug" ]; then
         local BUILD_SWITCH="--disable-optimized"
      else
         local BUILD_SWITCH="--enable-optimized"
      fi
      run_command "$WORKDIR/${CUPC_PKG}/configure --enable-clang-upc2c --prefix=$INSTALLDIR/$1 --enable-targets=host $BUILD_SWITCH" \
         "configure_llvm_${1}" "configuration of llvm/clang failed" $E_LLVM_BUILD_FAILED
   fi
   logmsg " ... building ${CUPC_PKG} ... "
   run_command "make $VERBOSE_MAKE -j $NPROCS" \
      "build_llvm_${1}" "make of llvm/clang failed" $E_LLVM_BUILD_FAILED
   logmsg " ... installing ${CUPC_PKG} ... "
   run_command "make $VERBOSE_MAKE install" \
      "install_llvm_${1}" "installation of llvm/clang failed" $E_LLVM_BUILD_FAILED
   logmsg " ... done with ${CUPC_PKG} ($1)"
   cd "$WORKDIR"
}

if [ $ENABLE_DBG -ne 0 ]; then
   build_llvm "dbg" "Debug"
else
   build_llvm "opt" "Release"
fi


######## extract upcr sources
logmsg "extracting upcr sources ... "

run_command "tar zxf$VERBOSE_V $UPCR_SOURCE" \
    "extract_llvm" "failed to extract $LLVM_SOURCE" $E_FILES_NOT_FOUND


######## configure and build upcr/gasnet
#  Configuration of UPCR picks up the previously build version of clang for
#+ both the C and C++ compiler. It uses clan-upc2c as the translator.
#
#  Bootstrapping is done conditionally on the appropriate configure files
#+ existing or not, mainly because it would otherwise pull in a large number
#+ of additional dependencies (autoconf, automake, etc.).
#
#  Current configuration disables MPI by default (can be overridden by the
#+ user), as otherwise GCC is picked for as the MPI compiler, if available.
#
#  For SuSE, there are extra configuration arguments to prevent part of UPCR
#+ installed in lib, with another part in lib64.

if [ ! -f "$WORKDIR/${BUPC_PKG}/configure" ]; then
   logmsg "bootstrapping upcr ... "
   cd "$WORKDIR/${BUPC_PKG}"
   run_command "./Bootstrap" "Bootstrap_upcr" $E_UPCR_BUILD_FAILED
   cd "$WORKDIR"
fi

function build_upcr() {
   LDPATH_OLD="$LD_LIBRARY_PATH"
   export LD_LIBRARY_PATH="$INSTALLDIR/$1/lib:$LD_LIBRARY_PATH"

   logmsg "now building upcr ... "
   mkdir -p "$WORKDIR/build/upcr"
   cd "$WORKDIR/build/upcr"
   logmsg " ... configuring upcr ... "
   UPCR_CONFIG_COMMAND="$WORKDIR/${BUPC_PKG}/configure $VERBOSE_LONGARG --with-multiconf=+opt_cupc2c,+dbg_cupc2c CUPC2C_TRANS=$INSTALLDIR/$1/bin/clang-upc2c CC=$INSTALLDIR/$1/bin/clang CXX=$INSTALLDIR/$1/bin/clang++ --prefix=$INSTALLDIR $DISABLE_MPI"
   if [ -f "/etc/SuSE-release" ]; then
      NPROCS=1                      #  experimentally determined: gasnet fails
      export prefix="$INSTALLDIR"   #+ to pick up prefix otherwise
      UPCR_CONFIG_COMMAND="$UPCR_CONFIG_COMMAND --libdir='\$(prefix)/lib' --libexecdir='\$(prefix)/libexec'"
   fi
   run_command "$UPCR_CONFIG_COMMAND $UPCR_CONFIG_EXTRA" \
      "configure_upcr" "configuration of upcr failed" $E_UPCR_BUILD_FAILED
   logmsg " ... building upcr ... "
   run_command "make $VERBOSE_MAKE -j $NPROCS" \
      "build_upcr" "make of upcr failed" $E_UPCR_BUILD_FAILED
   logmsg " ... installing upcr ... "
   run_command "make $VERBOSE_MAKE install" \
      "install_upcr" "installation of upcr failed" $E_LLVM_BUILD_FAILED
   logmsg " ... done with upcr"
   cd "$WORKDIR"

   export LD_LIBRARY_PATH="$LDPATH_OLD"
}

#  arg is the clang-upc build type
if [ $ENABLE_OPT -ne 0 ]; then
   build_upcr "opt"
else
   build_upcr "dbg"
fi 

######## install alternate multiconf
logmsg "generating multiconf.conf ... "
cat > $INSTALLDIR/etc/multiconf.conf <<'EOF'
# Configuration file for Berkeley UPC multiplexing compiler driver
ENABLED_CONFS=dbg_cupc2c opt_cupc2c dbg opt
;;;
error ; the -cupc2c and -bupc flags are mutually exclusive; $opt{'cupc2c'} && $opt{'bupc'} ;
dbg ; IGNORED ; $opt{'bupc'} && $opt{'g'} ; -bupc
opt ; IGNORED ; $opt{'bupc'} ; -bupc
dbg_cupc2c ; IGNORE ; $opt{'g'} ; -cupc2c
opt_cupc2c ; IGNORE ; 1 ; -cupc2c
;;;
Multiconf options:
   -show-confs        Show the multiconf variations which are installed
   -cupc2c            Use the Intrepid clang-upc2c translator [default]
   -bupc              Use the Berkeley UPC translator
   -g                 Enable system-wide debugging symbols and assertions
EOF

######## create setup script
logmsg "generating setup.sh ... "
if [ $ENABLE_OPT -ne 0 ]; then
   echo 'BUILDTYPE="opt"' >setup.sh
else
   echo 'BUILDTYPE="dbg"' >setup.sh
fi
cat >>setup.sh <<'EOF'
if [ $# -gt 0 ]; then
   if [ $# -ne 1 ] || ( [ "$1" != "opt" ] && [ "$1" != "dbg" ] ); then
      echo "Usage: source setup.sh [opt|dbg]"
      return 1
   fi
   BUILDTYPE=$1
fi

UPCRHOME="$INSTALLDIR"

echo "setting up upcr using:" $BUILDTYPE

_UPCRSETUP_REMOVEPATHDIRS=(
   "$UPCRHOME/opt/opt_cupc2c/bin"
   "$UPCRHOME/dbg/dbg_cupc2c/bin"
   "$UPCRHOME/opt/bin"
   "$UPCRHOME/dbg/bin"
)

_UPCRSETUP_ADDPATHDIRS=(
   "$UPCRHOME/bin"
   "$UPCRHOME/${BUILDTYPE}/bin"
)

_UPCRSETUP_REMOVELDPATHDIRS=(
   "$UPCRHOME/opt/opt_cupc2c/lib"
   "$UPCRHOME/dbg/dbg_cupc2c/lib"
   "$UPCRHOME/opt/lib"
   "$UPCRHOME/dbg/lib"
)

_UPCRSETUP_ADDLDPATHDIRS=(
   "$UPCRHOME/${BUILDTYPE}/lib"
)


case "$is" in
   zsh)
      _UPCRSETUP_NEWPATH=()
      for _upcr_dir in $path; do
        if [[ "${_UPCRSETUP_REMOVEPATHDIRS[(r)$_upcr_dir]}" != "$_upcr_dir" ]]; then
           _UPCRSETUP_NEWPATH+=$_upcr_dir;
        fi
      done
      path=($_UPCRSETUP_ADDPATHDIRS $_UPCRSETUP_NEWPATH)
      unset _UPCRSETUP_NEWPATH

      if [[ "$ld_library_path" == "" ]]; then
         typeset -T LD_LIBRARY_PATH ld_library_path
      fi
      _UPCRSETUP_NEWLDPATH=()
      for _upcr_dir in $ld_library_path; do
         if [[ "${_UPCRSETUP_REMOVELDPATHDIRS[(r)$_upcr_dir]}" != "$_upcr_dir" ]]; then
            _UPCRSETUP_NEWLDPATH+=$_upcr_dir;
         fi
      done
      unset _upcr_dir

      ld_library_path=($_UPCRSETUP_ADDLDPATHDIRS $_UPCRSETUP_NEWLDPATH)
      unset _UPCRSETUP_NEWLDPATH
      ;;

   *)
      for _upcr_dir in ${_UPCRSETUP_REMOVEPATHDIRS[@]}; do
         PATH=$(IFS=':';t=($PATH);unset IFS;t=(${t[@]%%"$_upcr_dir"});IFS=':';echo "${t[*]}")
      done
      for (( _upcr_idx=${#_UPCRSETUP_ADDPATHDIRS[@]}-1 ; _upcr_idx>=0 ; _upcr_idx-- )) ; do
         PATH="${_UPCRSETUP_ADDPATHDIRS[_upcr_idx]}:$PATH"
      done

      if [ -z "$LD_LIBRARY_PATH" ]; then
         export LD_LIBRARY_PATH=''
      fi
      for _upcr_dir in ${_UPCRSETUP_REMOVELDPATHDIRS[@]}; do
         LD_LIBRARY_PATH=$(IFS=':';t=($LD_LIBRARY_PATH);unset IFS;t=(${t[@]%%$_upcr_dir});IFS=':';echo "${t[*]}")
      done
      for (( _upcr_idx=${#_UPCRSETUP_ADDLDPATHDIRS[@]}-1 ; _upcr_idx>=0 ; _upcr_idx-- )) ; do
         LD_LIBRARY_PATH="${_UPCRSETUP_ADDLDPATHDIRS[_upcr_idx]}:$LD_LIBRARY_PATH"
      done

      unset _upcr_dir _upcr_idx
      ;;

esac

unset _UPCRSETUP_REMOVEPATHDIRS _UPCRSETUP_ADDPATHDIRS
unset _UPCRSETUP_REMOVELDPATHDIRS _UPCRSETUP_ADDLDPATHDIRS
EOF

logmsg "all done"

######## end
exit $E_SUCCESS
