## Process this file with automake to produce Makefile.in       -*- makefile -*-

AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies

headers = 		

built_headers = 	\
	stat.h.in

EXTRA_DIST = $(headers) $(built_headers)

all: $(built_headers:.h.in=.h)

builddir = $(top_builddir)/$(subdir)

if USING_CUPC2C
# automake 1.4-p6 doesn't like the following to exist only conditionally:
install-data-local:
uninstall-local:
else
install-data-local: $(headers) $(built_headers)
	$(mkinstalldirs) $(DESTDIR)$(includedir)/upcr_geninclude/sys
	@list='$(headers)'; for p in $$list; do \
	  if test -f $(srcdir)/$$p; then \
	    filename=`basename $$p`; \
	    echo " $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(includedir)/upcr_geninclude/sys/$$filename"; \
	    $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(includedir)/upcr_geninclude/sys/$$filename; \
	  else :; fi; \
	done
	@list='$(built_headers)'; for p in $$list; do \
	  q=`basename $$p .in`; \
	  if test -f $(builddir)/$$q; then \
	    filename=`basename $$q`; \
	    echo " $(INSTALL_DATA) $(builddir)/$$q $(DESTDIR)$(includedir)/upcr_geninclude/sys/$$filename"; \
	    $(INSTALL_DATA) $(builddir)/$$q $(DESTDIR)$(includedir)/upcr_geninclude/sys/$$filename; \
	  else :; fi; \
	done

uninstall-local:
	rm -f $(DESTDIR)$(includedir)/upcr_geninclude/sys/*.h
endif

