AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies
#
# Makefile for building Totalview UPC assistant library
# Jason Duell <jcduell@lbl.gov>, 2005
#

upcr_bld = $(top_builddir)/..
upcr_src   = $(top_srcdir)/..

# source files
libupcda_srcs = bupc_assistant.c catch_missing_symbols.c
libupcda_hdrs = bupc_assistant.h bupc_totalview_sptr.h

# Because of tracing/stats macros we must recompile when GASNet headers change.
# We avoid needing to keep the list current by using overkill.
# Note that using $(shell find ...) makes automake very unhappy.
gasnet_hdrs = $(upcr_bld)/gasnet/gasnet_config.h \
              $(upcr_src)/gasnet/*.h             \
              $(upcr_src)/gasnet/*/*.h           \
              $(upcr_src)/gasnet/*/*/*.h

libupcda_deps = $(libupcda_srcs) $(libupcda_hdrs) $(gasnet_hdrs)  \
                $(upcr_bld)/acconfig.h  $(upcr_bld)/upcr_config.h \
                $(upcr_bld)/upcr_sptr.h $(srcdir)/Makefile.am 
                

INCLUDES = -I$(upcr_src)

UPCR_CFG    = $(UPCR_CONDUIT)-$(UPCR_PARSEQ)
RUNTIME_LIB = $(upcr_bld)/libupcr-$(UPCR_CFG).a

if CROSS_COMPILING
UPCR_MAK_HOSTCC = yes
endif

# Hack: figure out if we've got aligned segments by grepping for Gasnet's config
# string in the appropriate runtime library. 
# - Note that this would not be enough to determine UPCRI_SINGLE_ALIGNED_REGIONS
#   if pthreads could be used, but we're not supporting pthreads + Totalview
ALIGNED_SEGS  = $(shell if grep '$$GASNetConfig:.*,align,' $(RUNTIME_LIB) >/dev/null; then echo 1; else echo 0; fi)


# Since different conduits may use different shared pointer representations, we
# build a separate assistant library for each non-pthreaded version of the runtime,
# using the same logic as for libupcr.
EXTRA_LTLIBRARIES   = libupcda-mpi-tv.la   \
                      libupcda-udp-tv.la   \
                      libupcda-pami-tv.la  \
                      libupcda-ibv-tv.la  \
                      libupcda-portals4-tv.la \
                      libupcda-gemini-tv.la \
                      libupcda-aries-tv.la \
                      libupcda-shmem-tv.la \
                      libupcda-ofi-tv.la   \
                      libupcda-mxm-tv.la   \
                      libupcda-smp-tv.la

# list of libraries to actually build, determined at configure time
lib_LTLIBRARIES       = @ASSISTANTLIBS@


# Each version of the library is built via a recursive make call with
# different parameters

libupcda_mpi_tv_la_SOURCES   = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-mpi-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=mpi UPCR_PARSEQ=tv build_lib

libupcda_udp_tv_la_SOURCES   = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-udp-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=udp UPCR_PARSEQ=tv build_lib

libupcda_pami_tv_la_SOURCES  = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-pami-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=pami UPCR_PARSEQ=tv build_lib

libupcda_smp_tv_la_SOURCES   = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-smp-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=smp UPCR_PARSEQ=tv build_lib

libupcda_shmem_tv_la_SOURCES   = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-shmem-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=shmem UPCR_PARSEQ=tv build_lib

libupcda_ibv_tv_la_SOURCES   = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-ibv-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=ibv UPCR_PARSEQ=tv build_lib

libupcda_portals4_tv_la_SOURCES   = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-portals4-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=portals4 UPCR_PARSEQ=tv build_lib

libupcda_gemini_tv_la_SOURCES   = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-gemini-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=gemini UPCR_PARSEQ=tv build_lib

libupcda_aries_tv_la_SOURCES   = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-aries-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=aries UPCR_PARSEQ=tv build_lib

libupcda_ofi_tv_la_SOURCES   = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-ofi-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=ofi UPCR_PARSEQ=tv build_lib

libupcda_mxm_tv_la_SOURCES   = $(libupcda_srcs) $(libupcda_hdrs)
libupcda-mxm-tv.la: $(libupcda_deps)
	$(MAKE) UPCR_CONDUIT=mxm UPCR_PARSEQ=tv build_lib


#
# Each version of the totalview assistant library is built via a recursive make
# call--we need this since each requires different CFLAGS settings, GASNET libs,
# etc., depending on the conduit/shared-pointer-rep.
#
# We include upcr.mak, which figures out which GASNet .mak fragment has the
# correct settings for the version of the runtime library we want to build.
# We have to do this in a separate file since we can't put GNU make conditionals
# in this file (or automake will barf).
#
# Silly: automake uses 'include' for its own purposes, so use an autoconf
# variable to sneak one past it to regular GNU make...
@MAKE_INCLUDE@ $(upcr_bld)/upcr.mak

# templatized library build
$(gasnet_makfile):
	$(MAKE) -C $(upcr_bld)/gasnet/$(UPCR_CONDUIT)-conduit $(UPCR_CFG).mak

# Note: we build object files with different names in order to allow parallel
# make.  Right now we've only got one .c file, so we use it.  If we add multiple
# C files, consider using a single 'glob.c' file that #includes the others, like
# libupcr does
build_lib: $(gasnet_makfile)
	$(LIBTOOL) @UPCR_LIBTOOL_TAG@ --mode=compile $(UPCR_CC) -c $(EXTRA) $(UPCR_CPPFLAGS) $(UPCR_CFLAGS) \
            -DUPCRI_SINGLE_ALIGNED_REGIONS=$(ALIGNED_SEGS) \
	    -o bupc_assistant-$(UPCR_CFG).lo $(srcdir)/bupc_assistant.c
	$(LIBTOOL) @UPCR_LIBTOOL_TAG@ --mode=link $(UPCR_LD) -no-undefined -rpath '$(libdir)' -o libupcda-$(UPCR_CFG).la \
            bupc_assistant-$(UPCR_CFG).lo
	$(UPCR_CC) $(UPCR_CPPFLAGS) $(UPCR_CFLAGS) -o catch_missing_symbols-$(UPCR_CFG).o \
                                                   -c $(srcdir)/catch_missing_symbols.c
	$(LIBTOOL) @UPCR_LIBTOOL_TAG@ --mode=link $(UPCR_LD) $(UPCR_LDFLAGS) -o catch_missing_symbols-$(UPCR_CFG) \
            catch_missing_symbols-$(UPCR_CFG).o libupcda-$(UPCR_CFG).la || (rm libupcda-$(UPCR_CFG).la && false)
	rm catch_missing_symbols-$(UPCR_CFG) catch_missing_symbols-$(UPCR_CFG).o
	-rm -f bupc_assistant-$(UPCR_CFG).lo



