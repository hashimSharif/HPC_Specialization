AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies

# .pl files to install in bindir, but w/o exec permissions
dotpldir = $(bindir)
dotpl_DATA = upcdecl.pl
bin_SCRIPTS   = upcdecl

# .pl libraries needed by $(dotpl_DATA)
perl_libs = \
	upcdecl_R.pl	\
	upcdecl_TRP.pl

include_HEADERS= $(perl_libs)

EXTRA_DIST = \
        upcdecl.extraman \
	ctests.txt	\
	upctests.txt	\
	mygram.txt	\
	cdeclgram.txt   \
	$(dotpl_DATA)

$(top_builddir)/gasnet/other/perlstart: $(top_srcdir)/gasnet/other/perlstart.in
	@$(MAKE) -C $(top_builddir)/gasnet/other perlstart

upcdecl: $(top_builddir)/gasnet/other/perlstart upcdecl.pl $(perl_libs)

# Things to copy from srcdir to buildir when they differ
if BUILD_IS_SRC
files_we_copy =
else
files_we_copy =  $(dotpl_DATA) $(perl_libs)
$(files_we_copy): force
	@srcfile="$(srcdir)/`basename $@`" ; \
         if test ! -f "$@" -o "`find $$srcfile -newer '$@' 2>&1`" ; then \
          echo cp -f "$$srcfile" . ;         \
          cp -f "$$srcfile" . ;              \
         fi
endif

DISTCLEANFILES = $(files_we_copy)

force:

check: upcdecl
	./upcdecl -t $(srcdir)/ctests.txt
	./upcdecl -t $(srcdir)/upctests.txt

