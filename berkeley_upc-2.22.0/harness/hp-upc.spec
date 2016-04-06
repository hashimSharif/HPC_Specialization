# Compiler spec file for HP/Compaq UPC (Compaq AlphaServer)

# upc compiler command
# need -I. to ensure that #include <foo.h> correctly gets ./foo.h
# need -lm to prevent link failures when calling sin() and sqrt()
upc_compiler = upc -I. -lm

# upc run command
# Following replacements are performed:
# %N - number of UPC threads
# %P - program executable
# %A - arguments to program
# %B - berkeley-specific upcrun arguments (should appear if and only if this is Berkeley upcrun)
upcrun_command = prun -n %N %P %A

# default sysconf file to use
# -network setting is ignored for non-UPCR compilers, 
# just need a sysconf with a relevant batch policy for job execution
default_sysconf = shmem-interactive

# list of supported compiler features
# add upc_io and upc_collective to enable those tests
feature_list = driver_hp,trans_hp,runtime_hp,os_osf,cpu_alphaev67,cc_compaq

# option to pass upc compiler to get %T static threads
upc_static_threads_option = -fthreads %T

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
known_failures = \
bugzilla/bug40 [HP UPC assigns incorrect type to character constants (ISO C 6.4.4.4-9)] | \
bugzilla/bug41 [return type for implicit declarations should not conflict with real declarations] | \
bugzilla/bug87 [HP UPC missing many C99 headers] | \
bugzilla/bug91 [HP UPC does not support inline assembly] | \
bugzilla/bug342 [__attribute__ not supported] | \
bugzilla/bug547 [HP UPC warns about floating point overflow/underflow] | \
bugzilla/bug567 [bogus uninitialized warning for array of structs with initializer] | \
bugzilla/bug575 [bogus uninitialized warning for array of structs with initializer] | \
bugzilla/bug818 [HP UPC fails to generate an error for ISO C 6.8.6.4 constraint violation] | \
bugzilla/bug858 [HP UPC does not implement C99 struct designators] | \
bugzilla/bug866-1 [HP UPC fails to detect misuse of upc_*sizeof] | \
bugzilla/bug866-2 [HP UPC fails to detect misuse of upc_*sizeof] | \
bugzilla/bug866-3 [HP UPC fails to detect misuse of upc_*sizeof] | \
bugzilla/bug866-4 [HP UPC fails to detect misuse of upc_*sizeof] | \
pearls/z_order1 [HP UPC has a small UPC_MAX_BLOCK_SIZE] | \
mg/mg [HP UPC does not provide a poll function] | \
guppie/guppie [HP UPC has a spurious definition in upc.h polluting user namespace] | \
bugzilla/bug247 [HP UPC missing stdint.h] | \
bugzilla/bug673 [HP UPC missing stdint.h] | \
bugzilla/bug738 [HP UPC missing stdint.h] | \
psearch/psearch [HP UPC missing stdint.h] | \
benchmarks/alloc_time [HP UPC missing stdint.h] | \
bugzilla/checkforall [HP UPC rejects initializers on shared data] | \
bugzilla/bug41x [HP UPC rejects initializers on shared data] | \
bugzilla/bug550 [HP UPC rejects initializers on shared data] | \
bugzilla/bug354 [HP UPC rejects initializers on shared data] | \
bugzilla/bug515 [HP UPC rejects initializers on shared data] | \
bugzilla/bug639 [HP UPC rejects initializers on shared data] | \
bugzilla/bug818 [HP UPC rejects initializers on shared data] 

