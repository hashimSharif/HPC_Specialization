## Process this file with automake to produce Makefile.in       -*- makefile -*-

AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies

SUBDIRS = sys

built_headers = 	\
	bupc_atomics.h.in \
	upcr_atomic_defs.h.in \
	ctype.h.in	\
	byteswap.h.in	\
	alloca.h.in	\
	fenv.h.in	\
	inttypes.h.in	\
	iso646.h.in	\
	limits.h.in	\
	math.h.in	\
	time.h.in	\
	stdarg.h.in	\
	stdbool.h.in	\
	stddef.h.in	\
	stdint.h.in 	\
	stdlib.h.in	\
	stdio.h.in	\
	string.h.in

all_headers = $(built_headers:.h.in=.h)
EXTRA_DIST = README $(built_headers) genfile.pl upcr_atomic.subst
DISTCLEANFILES = $(all_headers)

all: $(all_headers)

builddir = $(top_builddir)/$(subdir)

UPCR_SUBST_CMD = @PERL@ -- $(srcdir)/genfile.pl
UPCR_ATOMIC_SUBST = $(srcdir)/upcr_atomic.subst

upcr_atomic_defs.h: $(srcdir)/upcr_atomic_defs.h.in $(UPCR_ATOMIC_SUBST)
	$(UPCR_SUBST_CMD) $(UPCR_ATOMIC_SUBST) $< >$@
bupc_atomics.h: $(srcdir)/bupc_atomics.h.in $(UPCR_ATOMIC_SUBST)
	$(UPCR_SUBST_CMD) $(UPCR_ATOMIC_SUBST) $< >$@

# Note that bupc_atomics.h must be placed in upcr_preinclude/
all-local: bupc_atomics.h
	cp -f bupc_atomics.h "@TOP_BUILDDIR@/upcr_preinclude/"
clean-local:
	rm -f "@TOP_BUILDDIR@/upcr_preinclude/bupc_atomics.h"

inst-bupc-atomics: force
	@list='bupc_atomics.h'; for p in $$list; do \
	  if test -f $(builddir)/$$p; then \
	    filename=`basename $$p`; \
	    echo " $(INSTALL_DATA) $(builddir)/$$p $(DESTDIR)$(includedir)/upcr_preinclude/$$filename"; \
	    $(INSTALL_DATA) $(builddir)/$$p $(DESTDIR)$(includedir)/upcr_preinclude/$$filename; \
	  else :; fi; \
	done

if USING_CUPC2C
# automake 1.4-p6 doesn't like anything to exist only conditionally
install-data-local: inst-bupc-atomics
uninstall-local:
else
install-data-local: $(all_headers) inst-bupc-atomics
	$(mkinstalldirs) $(DESTDIR)$(includedir)/upcr_geninclude
	@list='$(all_headers)'; for q in $$list; do \
	  if test -f $(builddir)/$$q; then \
	    filename=`basename $$q`; \
	    echo " $(INSTALL_DATA) $(builddir)/$$q $(DESTDIR)$(includedir)/upcr_geninclude/$$filename"; \
	    $(INSTALL_DATA) $(builddir)/$$q $(DESTDIR)$(includedir)/upcr_geninclude/$$filename; \
	  else :; fi; \
	done

uninstall-local:
	rm -f $(DESTDIR)$(includedir)/upcr_geninclude/*.h
endif

.PHONY: force inst-bupc-atomics
