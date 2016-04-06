# Compiler spec file for Intrepid Clang UPC

upc_home = /usr/local/llvm-upc/bin

# upc compiler command
upc_compiler = $upc_home$/clang-upc -Wno-duplicate-decl-specifier -Werror=pointer-arith

# upc run command
# Following replacements are performed:
# %N - number of UPC threads
# %P - program executable
# %A - arguments to program
# %B - berkeley-specific upcrun arguments (should appear if and only if this is Berkeley upcrun)
upcrun_command = %P -n %N %A

# default sysconf file to use
default_sysconf = smp-interactive-no-pthreads

# list of supported compiler features
feature_list = driver_cupc,trans_cupc,runtime_cupc,pragma_upc_code,upc_all_free,upc_atomics,upc_castable,upc_collective,upc_nb,upc_tick,upc_types,os_linux,cpu_x86_64,cpu_64,cc_clang

# option to pass upc compiler to get %T static threads
upc_static_threads_option = -fupc-threads-%T

# option for performing just the source-to-source compile step
# or empty if not supported by the compiler
upc_trans_option = 

# colon-delimited path where to find harness.conf files
suite_path = $TOP_SRCDIR$/upc-tests:$TOP_SRCDIR$/upc-examples

# GNU make
gmake = make

# misc system tools
ar = ar
ranlib = ranlib

# C compiler & flags (should be empty on upcr/GASNet to auto-detect)
cc = clang
cflags =
ldflags = 
libs =

# host C compiler (or empty for same as cc)
host_cc =
host_cflags =
host_ldflags =
host_libs =

# OS suffix for exxcutables, or empty for none
exe_suffix = 

# known failures, in the format: test-path/test-name[failure comment] | test-name[failure comment]
# lines may be broken using backslash
# known failures may also include more specific failure/platform selectors, eg:
# mupc/test_stress_05-int [compile-all ; (cpu_ia64 || cpu_i686) && os_linux ; Compile failure on Itanium+x86 Linux... ] 
# known_failures may be empty to use the ones in the harness.conf files
known_failures = \
bug6 [run-all ; cpu_32 && structsptr; EXTERNAL: test requires over 2GB per thread] | \
bug247 [compile-failure ; cpu_32 ; Clang UPC does not support huge pointer offsets on 32-bit targets] | \
bug544 [compile-failure ; cc_xlc ; EXTERNAL: XLC cannot handle the initializer for pcrazy ] | \
bug604 [run-limit ; os_openbsd ; EXTERNAL: non-deterministic rand() on recent OpenBSD] | \
bug846 [compile-failure ; cpu_32 ; Clang UPC does not support the declaration of huge arrays on 32-bit targets] | \
bug899 [compile-failure ;; GCC/UPC does not properly handle #pragma upc c_code, by undefining UPC keywords and reserved identifiers] | \
bug899b [compile-failure ;; GCC/UPC does not properly handle #pragma upc c_code, by undefining UPC keywords and reserved identifiers] | \
bug899c [compile-failure ;; GCC/UPC does not properly handle #pragma upc c_code, by undefining UPC keywords and reserved identifiers] | \
bug922 [compile-failure ;; GCC/UPC does not properly handle #pragma upc c_code, by undefining UPC keywords and reserved identifiers] | \
bug3057 [compile-pass ; ; Clang UPC does not issue an error when compiling a PTS that refers to a multi-dim shared array with THREADS present in more than one dimension] | \
gasnet-tests/testconduitspecific [compile-failure ; ; EXTERNAL: Compile-time warning due to gcc 4.5.1 work-around] | \
gasnet-tests/testgasnet-parsync [compile-failure ; ; EXTERNAL: Missing gasnet-udp-parsync library, Makefile problem] | \
guts_main/barrier_neg [run-crash ; ; EXTERNAL: test intended to FAIL, but harness detects as CRASH] | \
gwu-npb-upc/btio-A [compile-failure ; packedsptr || cpu_32 ; Clang UPC does not support block sizes > 65536 in some configurations] | \
gwu-npb-upc/btio-A [run-match ; ; EXTERNAL: Bug 1508 - btio fails with NaNs] | \
gwu-npb-upc/btio-S [run-match ; ; EXTERNAL: Bug 1508 - btio fails with NaNs] | \
gwu-npb-upc/btio-W [compile-failure ; packedsptr || cpu_32 ; Clang UPC does not support block sizes > 65536 in some configurations] | \
gwu-npb-upc/btio-W [run-match ; ; EXTERNAL: Bug 1508 - btio fails with NaNs] | \
gwu-npb-upc/cg-A [run-match ; ; EXTERNAL: bug 653 - NPBs known to fail verification due to application bugs] | \
gwu-npb-upc/cg-S [run-match ; ; EXTERNAL: bug 653 - NPBs known to fail verification due to application bugs] | \
gwu-npb-upc/cg-W [run-match ; ; EXTERNAL: bug 653 - NPBs known to fail verification due to application bugs] | \
gwu-npb-upc/mg-S [run-match ; ; EXTERNAL: bug 653 - NPBs known to fail verification: mg-S with thread count >= 16] | \
pearls/upcfish [run-match ; os_netbsd || os_netbsdelf || os_openbsd ; EXTERNAL: poor rand() on NetBSD and OpenBSD causes premature exit(2)] | \
upc2c-issue-83 [compile-failure ; ; issue-83: Bad code on shared assignment of anon struct] | \
upc-semantic-checks/assign-pts-with-diff-block-factors-no-cast [compile-warning ; ; Clang UPC issues warning instead of error]
