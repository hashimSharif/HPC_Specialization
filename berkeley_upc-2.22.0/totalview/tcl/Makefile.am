AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies

TV_tcl_files    = demangle.tcl  replace_BLN.tcl  replace_BMN.tcl \
                  s2s_lines.tvd  s2s_prologue.tvd  s2s_skim.tvd  \
                  s2s_symbols.tvd s2s_setup.tvd sdump.tcl 

# put TCL scripts in 'tcl' subdirectory of libdir
tcldir = $(libdir)/tcl
tcl_DATA   = $(TV_tcl_files)

EXTRA_DIST = $(TV_tcl_files)

# Copy .tcl files if srcdir and builddir differ
if BUILD_IS_SRC
files_we_copy =
else
files_we_copy = $(TV_tcl_files)
$(files_we_copy): force
	@srcfile="$(srcdir)/`basename $@`" ; \
         if test ! -f "$@" -o "`find $$srcfile -newer '$@' 2>&1`" ; then \
          echo cp -f "$$srcfile" . ;         \
          cp -f "$$srcfile" . ;              \
         fi
endif
DISTCLEANFILES = $(files_we_copy)

all-local: $(TV_tcl_files)

force:

.PHONY: force
