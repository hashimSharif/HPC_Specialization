AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies

SUBDIRS       = .

tool_dirs = \
	dump

gasp_headers = \
	gasp.h 		\
	gasp_upc.h 

EXTRA_DIST    = \
	type-mangling-grammar.txt \
	$(gasp_headers) \
	$(tool_dirs)

if BUILDCONFIG_DEBUG
  DEBUG_FLAGS = -DDEBUG
else
  DEBUG_FLAGS = -DNDEBUG
endif

if USING_CUPC2C
  HEADER_DIR = upcr_geninclude2
else
  HEADER_DIR = upcr_geninclude
endif

# @..._TRUE@ hides gmake-specific "include" from automake
@BUILDCONFIG_GASP_TRUE@-include @TOP_BUILDDIR@/gasnet/gasnet_tools-seq.mak

if BUILDCONFIG_GASP
all-local: force
	hdrs='$(gasp_headers)' ; for file in $$hdrs ; do \
	  cp -f "@TOP_SRCDIR@/profile/$$file" "@TOP_BUILDDIR@/$(HEADER_DIR)" || exit $$? ; \
	done
	@$(MAKE) doit MYTARGET=all
clean-local: force
	@$(MAKE) doit MYTARGET=clean
	hdrs='$(gasp_headers)' ; for file in $$hdrs ; do \
	  rm -f "@TOP_BUILDDIR@/$(HEADER_DIR)/$$file" ; \
	done
install-data-local: force
	$(mkinstalldirs) "$(DESTDIR)$(includedir)/$(HEADER_DIR)"
	hdrs='$(gasp_headers)' ; for file in $$hdrs ; do \
	  $(INSTALL_DATA) "@TOP_SRCDIR@/profile/$$file" "$(DESTDIR)$(includedir)/$(HEADER_DIR)" || exit $$? ; \
	done
	@$(MAKE) doit MYTARGET=install
uninstall-local: force
	@$(MAKE) doit MYTARGET=uninstall
	hdrs='$(gasp_headers)' ; for file in $$hdrs ; do \
	  rm -f "$(DESTDIR)$(includedir)/$(HEADER_DIR)/$$file" ; \
	done

doit: force
	@for dir in $(tool_dirs) ; do \
	  mkdir -p $$dir ; \
	  $(MAKE) -C $$dir -f "@TOP_SRCDIR@/profile/$$dir/Makefile" $(MYTARGET) \
             CC="$(GASNETTOOLS_CC) -DHAVE_GASNET_TOOLS $(GASNETTOOLS_CPPFLAGS) $(GASNETTOOLS_CFLAGS) $(DEBUG_FLAGS)" \
             AR="@AR@" RANLIB="@RANLIB@" PERL="@PERL@" \
             top_builddir="@TOP_BUILDDIR@" builddir="@TOP_BUILDDIR@/profile/$$dir" \
             top_srcdir="@TOP_SRCDIR@" srcdir="@TOP_SRCDIR@/profile/$$dir" \
	     gasp_incdir="@TOP_SRCDIR@/profile" \
             include_prefix=$(DESTDIR)$(includedir) exec_prefix=$(DESTDIR)$(bindir) \
             lib_prefix=$(DESTDIR)$(libdir) \
             || exit $$? ; \
 	done

test: all-local
	dump/upcc-dump -network smp -pthreads --inst --inst-local @TOP_SRCDIR@/upc-tests/benchmarks/gasp_test.upc 
	../upcrun -np 4 gasp_test
else
# automake 1.4-p6 doesn't like the following to exist only conditionally:
all-local:
clean-local:
install-data-local:
uninstall-local:
endif

force:

.PHONY: force 

