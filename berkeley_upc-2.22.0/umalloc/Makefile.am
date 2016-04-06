AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies

# name(s) of final output
lib_LIBRARIES   = libumalloc.a

# sources we no longer use or maintain
legacy_srcs =	\
	keys.c		\
	ucalloc.c	\
	umcheck.c	\
	umemalign.c	\
	umtrace.c	\
	urealloc.c	\
	uvalloc.c

libumalloc_a_srcs =	\
	attach.c	\
	ufree.c		\
	umalloc.c	\
	umstats.c

libumalloc_a_hdrs =	\
	umprivate.h	\
	umalloc.h	\
	umalloc_2_upcr.h

# source files (.c and .h, also .l, .y)
libumalloc_a_SOURCES= $(libumalloc_a_srcs) $(libumalloc_a_hdrs)

libumalloc_a_CFLAGS = $(AM_CFLAGS) @UPCR_UMALLOC_CFLAGS@

# all .c files include umprivate.h which includes umalloc.h
# those two include portable_platform.h, portable_inttypes.h and  upcr_config.h
$(libumalloc_a_OBJECTS): umprivate.h umalloc.h \
        $(top_srcdir)/gasnet/other/portable_inttypes.h \
        $(top_srcdir)/gasnet/other/portable_platform.h \
        $(top_builddir)/upcr_config.h

docs = COPYING.LIB ChangeLog TODO umalloc.texi

EXTRA_DIST = $(legacy_srcs) $(docs) umtrace.awk

INCLUDES        =  -I$(top_srcdir) -I$(top_srcdir)/gasnet/other

if BUILDCONFIG_DEBUG
  DEBUG_FLAGS = -DDEBUG -DUPCR_DEBUG
else
  DEBUG_FLAGS = -DNDEBUG -DUPCR_NDEBUG
endif

CFLAGS_STAMP=$(top_builddir)/umalloc/.set-cflags

$(CFLAGS_STAMP): $(srcdir)/Makefile.in $(top_builddir)/gasnet/Makefile
	cd $(top_builddir) && CONFIG_HEADERS= CONFIG_FILES=umalloc/Makefile ./config.status
	eval `$(MAKE) --no-print-directory -f $(top_builddir)/gasnet/Makefile echovar VARNAME=CFLAGS` ; \
        mv Makefile Makefile.bak &&                                                                     \
	@PERL@ -p -e 's|^\s*CFLAGS\s*=(.*)$$|CFLAGS='"$$CFLAGS"' $(DEBUG_FLAGS)|' Makefile.bak >Makefile &&  \
 	rm -f Makefile.bak
	touch $(CFLAGS_STAMP)

Makefile: $(CFLAGS_STAMP)
	touch Makefile

CLEANFILES=$(CFLAGS_STAMP)

