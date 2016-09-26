#!/bin/bash
#
# Copyright (C) 2003-2014 Intel Corporation.  All Rights Reserved.
# 
# The source code contained or described herein and all documents
# related to the source code ("Material") are owned by Intel Corporation
# or its suppliers or licensors.  Title to the Material remains with
# Intel Corporation or its suppliers and licensors.  The Material is
# protected by worldwide copyright and trade secret laws and treaty
# provisions.  No part of the Material may be used, copied, reproduced,
# modified, published, uploaded, posted, transmitted, distributed, or
# disclosed in any way without Intel's prior express written permission.
# 
# No license under any patent, copyright, trade secret or other
# intellectual property right is granted to or conferred upon you by
# disclosure or delivery of the Materials, either expressly, by
# implication, inducement, estoppel or otherwise.  Any license under
# such intellectual property rights must be express and approved by
# Intel in writing.
#
#
# Check for valid use of an MPI driver and its underlying compiler.
# Issue error messages and exit with nonzero status if something wrong.
# Checks to make sure PATH and LD_LIBRARY_PATH are set up right for icc.

get_file_directory_name()
{
    file_dir=
    file_name=

    if [ -z "$1" ]; then return; fi
    case "$1" in
	/ | . | .. ) return ;;
	/*/* )       dirnam="$1" ;;
        /* )
	    file_dir="/"
	    file_name=`echo "$1" | sed -e 's/^\///'`
	    return
	;;
        ./* )        dirnam="$1"   ;;
        ../* )       dirnam="$1"   ;;
        * )          dirnam="./$1" ;;
    esac

    file_dir=`echo "$dirnam" | sed -e 's/\/[^/]*$//'`
    file_name=`echo "$dirnam" | sed -e 's/^.*\///'`
}

check_version_number()
{
    exp_vers="$3"
    if [ -z "$all_version_info" -o -z "$all_version_major" -o -z "$1" -o -z "$2" -o -z "$3" ]; then
	return
    fi
    if [ -n "$desired_vers" ]; then
	if [ "$all_version_info" != "$desired_vers" ]; then
	    exp_vers="$desired_vers"
	    return
	fi
    else
	case "$1" in
	    lt ) if [ $all_version_major -lt $2 ]; then return; fi ;;
	    ge ) if [ $all_version_major -ge $2 ]; then return; fi ;;
	    * )  return ;;
	esac
    fi
    exp_vers=
}

check_path_against_family()
{
    all_version_info=
    all_version_major=

    get_file_directory_name "$2"
    if [ ! -d "$file_dir" ]; then
	echo "ERROR: could not determine $1 directory for driver: $drivername"
	exit 1
    fi
    if [ "$file_name" != "$1" ]; then
	echo "ERROR: problem parsing $1 directory for driver: $drivername"
	exit 1
    fi

    case "$arch_label" in
	32 )  chk_family_f="$5" ; chk_family_c="$3" ;;
	64 )  chk_family_f="$6" ; chk_family_c="$4" ;;
	32e ) chk_family_f="$5" ; chk_family_c="$3" ;;
	* )
	    echo "ERROR: unknown architecture: $arch_label"
	    exit 1
	;;
    esac
    if [ "$lang" = "f" ]; then
	chk_family_p="$chk_family_f"
	chk_family_o="$chk_family_c"
    else
	chk_family_p="$chk_family_c"
	chk_family_o="$chk_family_f"
    fi
    chk_family=
    chk_path="$file_dir/../bin/"
    if [ ! -d $chk_path ]; then
	case "$arch_label" in
	    32 )  chk_path="$file_dir/../../bin/ia32/" 
                  if [ ! -d $chk_path ] ; then 
                    chk_path="$file_dir/../../../bin/ia32/" 
                  fi     
                ;;
	    64 )  chk_path="$file_dir/../../bin/ia64/" ;;
	    32e )
	        if [ "$want_arch_label" == "32" ]; then
	            chk_path="$file_dir/../../bin/ia32/"
                    if [ ! -d $chk_path ] ; then 
                        chk_path="$file_dir/../../../bin/ia32/" 
                    fi     
		else
	            chk_path="$file_dir/../../bin/intel64/"
                    if [ ! -d $chk_path ] ; then 
                        chk_path="$file_dir/../../../bin/intel64/" 
                    fi     
		fi ;;
	    * )
		echo "ERROR: unknown architecture: $arch_label"
		exit 1
	    ;;
	esac
    fi
    if [ -f "$chk_path$chk_family_p" -a -x "$chk_path$chk_family_p" ]; then
	chk_family="$chk_family_p"
    elif [ -f "$chk_path$chk_family_o" -a -x "$chk_path$chk_family_o" ]; then
	chk_family="$chk_family_o"
    fi
    if [ -z "$chk_family" ]; then
	return  # this can happen when checking a 8.0 compiler, 8.0/7.1 both in PATH, 7.1 but not 8.0 in LD_LIBRARY_PATH
		#                                                                 (or 7.1 ahead of 8.0 in LD_LIBRARY_PATH)
    fi

    all_version_info_line=`$chk_path$chk_family -V 2>&1 | grep "Version"`
    all_version_info=`echo "$all_version_info_line" | sed -e 's/^.*Version  *//' -e 's/[^0-9.].*$//'`
    if [ -n "$all_version_info" ]; then
	all_version_major=`echo "$all_version_info" | sed -e 's/\..*$//'`
	case "$all_version_major" in
	    0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12) ;;
	    * ) all_version_major= ;;
	esac
    fi
    case "$arch_label" in
	32 | 64 ) ;;
	32e )
	    if [ $all_version_major -ge 10 ]; then
		echo "$all_version_info_line" | grep "IA-32" > /dev/null 2>&1
	    else
		echo "$all_version_info_line" | grep "32-bit" > /dev/null 2>&1
	    fi
	    if [ $? -eq 0 ]; then
		if [ "$want_arch_label" != "32" ]; then
		    all_version_info="$all_version_info (32-bit)"
		    all_version_major=
		    exp_vers_arch=" ($arch_label_msg)"
		fi
	    else
		if [ "$want_arch_label" != "32e" ]; then
		    all_version_info="$all_version_info ($arch_label_msg)"
		    all_version_major=
		    exp_vers_arch=" (32-bit)"
		fi
	    fi
	;;
	* )
	    echo "ERROR: unknown architecture: $arch_label"
	    exit 1
	;;
    esac
}

check_compiler_path_err_chk()
{
    if [ -n "$exp_vers" ]; then
	echo "ERROR: PATH set up wrong for driver: $drivername"
	echo "       $compilername compiler was found in $compilerpath"
	if [ -n "$all_version_info" ]; then
	    echo "       (PATH appears to have $all_version_info compilers set up instead of expected $exp_vers$exp_vers_arch)"
	else
	    echo "       (PATH appears not to have expected $exp_vers compilers set up)"
	fi
	exit 1
    fi
}

check_ld_lib_path_err_chk()
{
    if [ -n "$exp_vers" ]; then
	echo "ERROR: LD_LIBRARY_PATH set up wrong for driver: $drivername"
	echo "       $compilername compiler was found in $compilerpath, but"
	echo "       $1 library was found in $3"
	if [ -n "$all_version_info" ]; then
	    echo "       (LD_LIBRARY_PATH appears to have $all_version_info compilers set up instead of expected $exp_vers$exp_vers_arch)"
	else
	    echo "       (LD_LIBRARY_PATH appears not to have expected $exp_vers compilers set up)"
	fi
	exit 1
    fi
}

check_compiler_path()
{
    case "$family" in
	icc8 )
	    check_path_against_family "$1" "$2" icc icc ifort ifort
	    check_version_number lt 8 "8.x(+)"
	;;
	icc7 )
	    check_path_against_family "$1" "$2" icc ecc ifc efc
	    check_version_number ge 8 "7.1"
	;;
	* )
	    echo "ERROR: unrecognized family for driver: $drivername"
	    exit 1
	;;
    esac
    check_compiler_path_err_chk "$@"
}

check_ld_lib_path()
{
    if [ -z "$1" -o "$2" != "=>" ]; then
	echo "ERROR: LD_LIBRARY_PATH set up wrong for driver: $drivername"
	echo "       (did not see expected library in test ldd output)"
	exit 1
    fi
    case "$3" in
	/* ) ;;
	* )
	    echo "ERROR: LD_LIBRARY_PATH set up wrong for driver: $drivername"
	    echo "       (did not see expected library in test ldd output)"
	    exit 1
	;;
    esac
    case "$family" in
	icc8 )
	    check_path_against_family "$1" "$3" icc icc ifort ifort
	    check_version_number lt 8 "8.x(+)"
	;;
	icc7 )
	    check_path_against_family "$1" "$3" icc ecc ifc efc
	    check_version_number ge 8 "7.1"
	;;
	* )
	    echo "ERROR: unrecognized family for driver: $drivername"
	    exit 1
	;;
    esac
    check_ld_lib_path_err_chk "$@"
    if [ -f "$compilerroot/lib/$1" -a "$3" != "$compilerroot/lib/$1" ]; then
	get_file_directory_name "$3"
	compilerlib="$file_dir"
	if [ ! -d "$compilerlib" ]; then
	    echo "ERROR: could not determine $compilername compiler lib/ directory for driver: $drivername"
	    exit 1
	fi
	get_file_directory_name "$compilerlib"
	libcompilerroot="$file_dir"
	if [ ! -d "$libcompilerroot" ]; then
	    echo "ERROR: could not determine $compilername compiler lib/ base directory for driver: $drivername"
	    exit 1
	fi
	case "$family" in
	    icc8 )
		check_path_against_family "icc" "$libcompilerroot/bin/icc" icc icc ifort ifort
		check_version_number lt 8 "8.x(+)"
	    ;;
	    icc7 )
		check_path_against_family "$arch7_icc" "$libcompilerroot/bin/$arch7_icc" icc ecc ifc efc
		check_version_number ge 8 "7.1"
	    ;;
	    * )
		echo "ERROR: unrecognized family for driver: $drivername"
		exit 1
	    ;;
	esac
	check_ld_lib_path_err_chk "$@"
    fi
}

get_gcc_version()
{
    version=`$1 -v 2>&1 | grep "gcc " | sed "s/gcc //" | sed "s/ .*//"`
    gcc_version=`$1 -v 2>&1 | grep "gcc ${version}" | sed "s/gcc $version //" | sed "s/ .*//"`
    if [ -z "$gcc_version" ]; then
	echo "ERROR: could not determine version for compiler: $1"
	exit 1
    fi
    gcc_version_major=`echo "$gcc_version" | sed -e 's/\..*$//'`
    case "$gcc_version_major" in
	0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 ) ;;
	* )
	    echo "ERROR: could not determine major version for compiler: $1"
	    exit 1
	;;
    esac
}

parse_arguments()
{
    want_arch_label=
    drivername=
    desired_vers=

    while [ $# -gt 0 ]; do
	arg="$1"
	if [ -n "$arg" ]; then
	    case "$arg" in
		-vers )
		    if [ $# -gt 1 ]; then
			shift
			desired_vers="$1"
			if [ -z "$desired_vers" ]; then
			    echo "ERROR: no value specified for $my_cmd_name option: $arg"
			    exit 1
			fi
		    fi
		;;
		-* )
		    echo "ERROR: unrecognized $my_cmd_name option: $arg"
		    exit 1
		;;
		* )
		    if [ -z "$want_arch_label" -a -z "$drivername" ]; then
			want_arch_label="$arg"
		    elif [ -z "$drivername" ]; then
			drivername="$arg"
		    else
			echo "ERROR: too many arguments: $my_cmd_name $my_cmd_line"
			exit 1
		    fi
		;;
	    esac
	fi
	shift
    done

    if [ -z "$want_arch_label" -o -z "$drivername" ]; then
	echo "ERROR: not enough arguments: $my_cmd_name $my_cmd_line"
	exit 1
    fi

    case "$want_arch_label" in
	32 | i32 )  want_arch_label="32"; want_arch_label_msg="32-bit" ;;
	64 | i64 )  want_arch_label="64"; want_arch_label_msg="64-bit" ;;
	32e | i32em ) want_arch_label="32e"; want_arch_label_msg="Intel(R) 64" ;;
	* )
	    echo "ERROR: invalid architecture flag for command: $my_cmd_name $my_cmd_line"
	    exit 1
	;;
    esac

    get_file_directory_name "$drivername"
    drivername="$file_name"
    if [ -z "$drivername" ]; then
	echo "ERROR: could not find driver name for command: $my_cmd_name $my_cmd_line"
	exit 1
    fi
}

my_cmd_name="$0"
my_cmd_line="$*"
parse_arguments "$@"

case "$drivername" in
    mpigcc   | gcc )       compilername="gcc"   ; lang="c" ; family="gcc"  ; sup_arch="32 64 32e" ;;
    mpigxx   | g++ )       compilername="g++"   ; lang="c" ; family="gcc"  ; sup_arch="32 64 32e" ;;
    mpif77   | g77 )       compilername="g77"   ; lang="f" ; family="gcc"  ; sup_arch="32 64 32e" ;;
    mpif90   | gfortran )       compilername="gfortran"   ; lang="f" ; family="gcc"  ; sup_arch="32 64 32e" ;;
    mpiicc   | icc )       compilername="icc"   ; lang="c" ; family="icc8" ; sup_arch="32 64 32e" ;;
    mpiicpc  | icpc )      compilername="icpc"  ; lang="c" ; family="icc8" ; sup_arch="32 64 32e" ;;
    mpiifort | ifort )     compilername="ifort" ; lang="f" ; family="icc8" ; sup_arch="32 64 32e" ;;
    mpiifc   | ifc )       compilername="ifc"   ; lang="f" ; family="icc7" ; sup_arch="32" ;;
    mpiecc   | ecc )       compilername="ecc"   ; lang="c" ; family="icc7" ; sup_arch="64" ;;
    mpiecpc  | ecpc )      compilername="ecpc"  ; lang="c" ; family="icc7" ; sup_arch="64" ;;
    mpiefc   | efc )       compilername="efc"   ; lang="f" ; family="icc7" ; sup_arch="64" ;;
    * )
	echo "ERROR: unrecognized driver name: $drivername"
	exit 1
    ;;
esac

unamem=`uname -m`
case "$unamem" in
    i686 )
	arch_label="32"
	arch_label_msg="32-bit"
	arch7_icc="ecc"
	if [ "$want_arch_label" != "$arch_label" ]; then
	    echo "ERROR: attempt to run ${want_arch_label_msg} driver on ${arch_label_msg} architecture: $drivername"
	    exit 1
	fi
    ;;
    ia64 )
	arch_label="64"
	arch_label_msg="64-bit"
	arch7_icc="icc"
	if [ "$want_arch_label" != "$arch_label" ]; then
	    echo "ERROR: attempt to run ${want_arch_label_msg} driver on ${arch_label_msg} architecture: $drivername"
	    exit 1
	fi
    ;;
    x86_64 )
	arch_label="32e"
	arch_label_msg="Intel(R) 64"
	arch7_icc=
	if [ "$want_arch_label" != "$arch_label" -a "$want_arch_label" != "32" ]; then
	    echo "ERROR: attempt to run ${want_arch_label_msg} driver on ${arch_label_msg} architecture: $drivername"
	    exit 1
	fi
    ;;
    * )
	echo "ERROR: unknown architecture (uname -m): $unamem"
	exit 1
    ;;
esac

found=
for i in $sup_arch; do
    if [ "$i" = "$arch_label" ]; then
	found=true
	break
    fi
done
if [ -z "$found" ]; then
    echo "ERROR: attempt to run non-${arch_label_msg} driver on ${arch_label_msg} architecture: $drivername"
    exit 1
fi

compilerpath=`which $compilername 2> /dev/null`
if [ -f "$compilerpath" -a -x "$compilerpath" ]; then
    get_file_directory_name "$compilerpath"
    compilerbin="$file_dir"
    if [ ! -d "$compilerbin" ]; then
	echo "ERROR: could not determine $compilername compiler bin/ directory for driver: $drivername"
	exit 1
    fi
else
    echo "ERROR: $compilername compiler is not in PATH for driver: $drivername"
    exit 1
fi

if [ "$family" = "gcc" ]; then
    case "$drivername" in
	mpif77 | mpif90 | mpigcc | gcc | g++ | g77 | gfortran ) ;;
	mpicxx2 )
	    get_gcc_version "$compilername"
	    if [ $gcc_version_major -ge 3 ]; then
		echo "ERROR: wrong $compilername compiler being used for driver: $drivername"
		echo "       (PATH appears to have $gcc_version compilers set up instead of expected 2.x)"
		exit 1
	    fi
	;;
	mpigxx )
	    get_gcc_version "$compilername"
	    if [ $gcc_version_major -lt 3 ]; then
		echo "ERROR: wrong $compilername compiler being used for driver: $drivername"
		echo "       (PATH appears to have $gcc_version compilers set up instead of expected 3.x)"
		exit 1
	    fi
	;;
	* )
	    echo "ERROR: unrecognized $family driver name: $drivername"
	    exit 1
	;;
    esac
else
    exp_vers_arch=
    get_file_directory_name "$compilerbin"
    compilerroot="$file_dir"
    if [ ! -d "$compilerroot" ]; then
	echo "ERROR: could not determine $compilername compiler base directory for driver: $drivername"
	exit 1
    fi
    check_compiler_path "$compilername" "$compilerpath"

    ldlib_rest=`echo "$LD_LIBRARY_PATH" | sed -e 's/::*/:/g' -e 's/^://' -e 's/:$//'`
    lib_checked=
    while [ -n "$ldlib_rest" ]; do
	case "$ldlib_rest" in
	    *:* )
		ldlib_next=`echo $ldlib_rest | sed -e 's/:.*$//'`
		ldlib_next=`echo $ldlib_next | sed -e 's/\/*$//'`
		ldlib_rest=`echo $ldlib_rest | sed -e 's/^[^:]*://'`
	    ;;
	    * )
		ldlib_next="$ldlib_rest"
		ldlib_rest=
	    ;;
	esac
	if [ -n $all_version_major -a $all_version_major -ge 10 ]; then
	    if [ -n "$ldlib_next" -a -f "$ldlib_next/libcxaguard.so" ]; then
		check_ld_lib_path "libcxaguard.so" "=>" "$ldlib_next/libcxaguard.so" "(0x00000000)"
		lib_checked=true
		break
	    fi
	else
	    if [ -n "$ldlib_next" -a -f "$ldlib_next/libcxa.so" ]; then
		check_ld_lib_path "libcxa.so" "=>" "$ldlib_next/libcxa.so" "(0x00000000)"
		lib_checked=true
		break
	    fi
	fi
    done
    if [ -z "$lib_checked" ]; then
	echo "ERROR: LD_LIBRARY_PATH set up wrong for driver: $drivername"
	echo "       (could not find expected library in LD_LIBRARY_PATH)"
	exit 1
    fi
fi

exit 0
