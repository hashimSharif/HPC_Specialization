## Process this file with automake to produce Makefile.in       -*- makefile -*-

AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies

headers = 			\
	clang-upc.h		\
	pupc.h			\
	upc.h			\
	upc_bits.h		\
	upc_castable.h		\
	upc_castable_bits.h	\
	upc_nb.h		\
	upc_types.h		\
	upc_relaxed.h		\
	upc_strict.h		\
	upc_collective.h	\
	bupc_collectivev.h	\
	bupc_extensions.h	\
	upc_collective_bits.h 	\
 	upc_tick.h        	\
 	upc_io.h        	\
	upc_io_bits.h		

EXTRA_DIST = $(headers)

COLLECTIVEV_DIRS = 					\
	$(TOP_SRCDIR)/upc-examples/upc_collectivev	\
	$(TOP_SRCDIR)/upc-tests/benchmarks		

all: 
	@header="bupc_collectivev.h" ; 						\
	 for dir in $(COLLECTIVEV_DIRS) ; do					\
	  if test -d $$dir ; then						\
            if test ! -f "$$dir/$$header" -o 					\
                "`find $(srcdir)/$$header -newer $$dir/$$header 2>&1`" ; then 	\
	      chmod +w $$dir ;      						\
	      echo cp -f $(srcdir)/$$header $$dir ;                        	\
	      cp -f $(srcdir)/$$header $$dir ;                        		\
	    fi ; 								\
	  fi ;									\
	done

install-data-local: $(headers)
	$(mkinstalldirs) $(DESTDIR)$(includedir)/upcr_preinclude
	@list='$(headers)'; for p in $$list; do \
	  if test -f $(srcdir)/$$p; then \
	    filename=`basename $$p`; \
	    echo " $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(includedir)/upcr_preinclude/$$filename"; \
	    $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(includedir)/upcr_preinclude/$$filename; \
	  else :; fi; \
	done

uninstall-local:
	rm -f $(DESTDIR)$(includedir)/upcr_preinclude/*.h

