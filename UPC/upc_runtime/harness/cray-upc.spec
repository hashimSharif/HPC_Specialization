# Compiler spec file for Cray UPC (Cray XT and XE)

# upc compiler command
# -h upc enables UPC compilation
# -h c99 enables C99 features (like for loop declarations and mixed code/decls)
# -I. ensures that #include <foo.h> sees ./foo.h
#upc_compiler = $TOP_SRCDIR$/harness/upc-wrapper -h upc -h c99 -I. # for the X1
upc_compiler = cc -h upc -h c99 -I.
dash_O = -O 3

# upc run command
# Following replacements are performed:
# %N - number of UPC threads
# %P - program executable
# %A - arguments to program
# %B - berkeley-specific upcrun arguments (should appear if and only if this is Berkeley upcrun)
upcrun_command = aprun -n %N %P %A

# default sysconf file to use
# -network setting is ignored for non-UPCR compilers, 
# just need a sysconf with a relevant batch policy for job execution
#default_sysconf = mpi-interactive # for the X1
default_sysconf = mpi-interactive

# list of supported compiler features
# add upc_io and upc_collective to enable those tests
#feature_list = driver_cray,trans_cray,runtime_cray,os_unicos,cpu_crayx1,cc_cray # for the X1
feature_list = driver_cray,trans_cray,runtime_cray,os_cnl,os_linux,cpu_x86_64,cpu_64,cc_cray

# option to pass upc compiler to get %T static threads
upc_static_threads_option = -X %T

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
cc = cc
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
# From Cray UPC on the X1:
#known_failures = \
#	perverse naming/p2 [Cray UPC doesnt handle special punctuation characters in filenames] | \
#	bugzilla/checkforall [Cray UPC lacks support for constant address-of-shared] | \
#	bugzilla/bug91 [Cray UPC lacks support for inline assembly] | \
#	bugzilla/bug342 [Cray UPC lacks support for __attribute__] | \
#	bugzilla/bug383 [Cray UPC lacks support for implicit function declaration] | \
#	bugzilla/bug438 [link error on inline function] | \
#	bugzilla/bug547 [Cray UPC warns about floating-point roundoff/overflow] | \
#	bugzilla/bug866-1 [Cray UPC fails to detect misuse of upc_*sizeof] | \
#	bugzilla/bug866-2 [Cray UPC fails to detect misuse of upc_*sizeof] | \
#	bugzilla/bug866-3 [Cray UPC fails to detect misuse of upc_*sizeof] | \
#	bugzilla/bug866-4 [Cray UPC fails to detect misuse of upc_*sizeof] 

