## Process this file with automake to produce Makefile.in       -*- makefile -*-

AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies

headers = 			\
	bupc_extensions.h	\
	bupc_wrappers.h		\
	pupc.h			\
	upc_castable.h		\
	upc_castable_bits.h	\
	upc_collective.h	\
	upc_collective_bits.h	\
	upc_nb.h		\
	upc_tick.h		\
	upc_io.h		\
	upc_io_bits.h		\
	clang-upc-lib.h		\
	gcc-upc-lib.h

EXTRA_DIST = $(headers)

built_headers =                 \
	libgupc.h

DISTCLEANFILES = $(built_headers)

# Same file needs different name depending on gccupc/gupc version
libgupc.h: $(srcdir)/gcc-upc-lib.h
	cp -f $< $@

install-data-local: $(headers) $(built_headers)
	$(mkinstalldirs) $(DESTDIR)$(includedir)/upcr_extinclude
	@list='$(headers)'; for p in $$list; do \
	  if test -f $(srcdir)/$$p; then \
	    filename=`basename $$p`; \
	    echo " $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(includedir)/upcr_extinclude/$$filename"; \
	    $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(includedir)/upcr_extinclude/$$filename; \
	  else :; fi; \
	done
	@list='$(built_headers)'; for p in $$list; do \
	  if test -f $$p; then \
	    echo " $(INSTALL_DATA) $$p $(DESTDIR)$(includedir)/upcr_extinclude/$$p"; \
	    $(INSTALL_DATA) $$p $(DESTDIR)$(includedir)/upcr_extinclude/$$p; \
	  else :; fi; \
	done

uninstall-local:
	rm -f $(DESTDIR)$(includedir)/upcr_extinclude/*.h

