# Compiler spec file for IBM UPC (AIX)

# upc compiler command
# -qsourcetype=upc ensures we always get UPC compilation
# -I. ensures #includes for headers in the current directory are honored
# Suppress warnings:
# 1506-224 bogus warnings about #pragma upc (compiler bug)
# 1500-029 warnings about failed inlining to UPC shared ptr ops
upc_compiler = /usr/upc/bin/xlupc -qsourcetype=upc -I. -qsuppress=1506-224:1500-029

# upc run command
# Following replacements are performed:
# %N - number of UPC threads
# %P - program executable
# %A - arguments to program
# %B - berkeley-specific upcrun arguments (should appear if and only if this is Berkeley upcrun)
upcrun_command = UPC_NTHREADS=%N %P %A

# default sysconf file to use
# -network setting is ignored for non-UPCR compilers, 
# just need a sysconf with a relevant batch policy for job execution
default_sysconf = shmem-interactive

# list of supported compiler features
feature_list = driver_ibm,trans_ibm,runtime_ibm,os_aix,cpu_powerpc,cpu_32,cc_xlc

# option to pass upc compiler to get %T static threads
upc_static_threads_option = -qupcthreads=%T

# option for performing just the source-to-source compile step
# or empty if not supported by the compiler
upc_trans_option = 

# colon-delimited path where to find harness.conf files
suite_path = $TOP_SRCDIR$/upc-tests:$TOP_SRCDIR$/upc-examples

# GNU make
gmake = gmake

# misc system tools
ar = ar
ranlib = ranlib

# C compiler & flags (should be empty on upcr/GASNet to auto-detect)
cc = xlc
cflags =
ldflags = 
libs =

# host C compiler (or empty for same as cc)
host_cc = 
host_cflags =
host_ldflags =
host_libs = 

# known failures, in the format: test-path/test-name[failure comment] | test-name[failure comment]
# lines may be broken using backslash
# known_failures may be empty to use the ones in the harness.conf files
known_failures = \
	bugXXX [Example failure: known failure description]
