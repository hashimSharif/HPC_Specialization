## Process this file with automake to produce Makefile.in       -*- makefile -*-

AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies

SUBDIRS =

built_headers = 	\
	stdlib.h.in	\
	math.h.in

built_headers_nodist = \
	upcr_atomic_defs.h.in

all_headers = $(built_headers:.h.in=.h) $(built_headers_nodist:.h.in=.h)
EXTRA_DIST = README $(built_headers)
DISTCLEANFILES = $(all_headers)

all: $(all_headers)

GENINLCUDE_DIR = $(top_srcdir)/upcr_geninclude
UPCR_SUBST_CMD = @PERL@ -- $(GENINLCUDE_DIR)/genfile.pl
UPCR_ATOMIC_SUBST = $(GENINLCUDE_DIR)/upcr_atomic.subst

upcr_atomic_defs.h: $(GENINLCUDE_DIR)/upcr_atomic_defs.h.in $(UPCR_ATOMIC_SUBST)
	$(UPCR_SUBST_CMD) $(UPCR_ATOMIC_SUBST) $< >$@

builddir = $(top_builddir)/$(subdir)

if USING_CUPC2C
install-data-local: $(all_headers)
	$(mkinstalldirs) $(DESTDIR)$(includedir)/upcr_geninclude2
	@list='$(all_headers)'; for q in $$list; do \
	  if test -f $(builddir)/$$q; then \
	    filename=`basename $$q`; \
	    echo " $(INSTALL_DATA) $(builddir)/$$q $(DESTDIR)$(includedir)/upcr_geninclude2/$$filename"; \
	    $(INSTALL_DATA) $(builddir)/$$q $(DESTDIR)$(includedir)/upcr_geninclude2/$$filename; \
	  else :; fi; \
	done

uninstall-local:
	rm -f $(DESTDIR)$(includedir)/upcr_geninclude2/*.h
else
# automake 1.4-p6 doesn't like the following to exist only conditionally:
install-data-local:
uninstall-local:
endif
