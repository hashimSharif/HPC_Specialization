# Compiler spec file for SGI UPC

# upc compiler command
# -I. ensures that #include <foo.h> sees ./foo.h
# -c99 needed for "upc_forall(int i =..."
# -w needed to supress numerous warnings, few of which have any value
upc_compiler = sgiupc -I. -c99 -w
#dash_g = -g   the default
#dash_O = -O   the default

# upc run command
# Following replacements are performed:
# %N - number of UPC threads
# %P - program executable
# %A - arguments to program
# %B - berkeley-specific upcrun arguments (should appear if and only if this is Berkeley upcrun)
upcrun_command = mpirun -np %N %P %A

# default sysconf file to use
# -network setting is ignored for non-UPCR compilers, 
# just need a sysconf with a relevant batch policy for job execution
default_sysconf = shmem-interactive

# list of supported compiler features
# add upc_io and upc_collective to enable those tests
feature_list = driver_sgi,trans_sgi,runtime_sgi,os_linux,cpu_x86_64,cpu_64,cc_intel,upc_collective

# option to pass upc compiler to get %T static threads
upc_static_threads_option = -LANG:upc_threads=%T

# option for performing just the source-to-source compile step
# or empty if not supported by the compiler
# sgiupc has option to keep the intermediate, but not to stop
upc_trans_option = 

# colon-delimited path where to find harness.conf files
suite_path = $TOP_SRCDIR$/upc-tests:$TOP_SRCDIR$/upc-examples

# GNU make
gmake = gmake

# misc system tools
ar = ar
ranlib = ranlib

# C compiler & flags (should be empty on upcr/GASNet to auto-detect)
cc = icc
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
# known_failures may be empt to use the ones in the harness.conf files
known_failures = 
