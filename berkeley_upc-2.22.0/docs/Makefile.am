AUTOMAKE_OPTIONS  = foreign 1.4 no-dependencies
#
# Makefile for upc runtime and general Berkeley UPC user documentation
#
# $Source: bitbucket.org:berkeleylab/upc-runtime.git/docs/Makefile.am $

htmldir = $(datadir)/doc/upcc
EXTRA_DIST = html \
	README.crosscompile \
	README.CrayXT

# Gross hack: the 'html-src' subdir contains the SSI .shtml files we use on our
# website.  To make the .html files we ship in 'html', we hook 'make dist' to
# copy the SSI files and convert all extentions (and hrefs) from .shtml -> .html
html: 
	@echo Building HTML..
	@BUPC_VERSION=@VERSION@ ; export BUPC_VERSION ; \
        if test -d $(top_srcdir)/docs/html-src; then \
	    rm -Rf html ; \
	    cp -r $(top_srcdir)/docs/html-src html; \
	    $(top_srcdir)/docs/deSSI.pl html; \
	    cp -f $(top_srcdir)/upc-examples/upc_collectivev/README html/user/README-collectivev.txt ; \
	fi
	@echo Done.

# If build from src, 'html' in cwd: if build from tarball, in srcdir tree
install-data-local: html
	$(mkinstalldirs) $(DESTDIR)$(htmldir)
	if test -d html; then \
            cp -r html $(DESTDIR)$(htmldir);\
	elif test -d $(top_srcdir)/docs/html; then  \
	    cp -r $(top_srcdir)/docs/html $(DESTDIR)$(htmldir);\
	fi
	-chmod -R a+rX $(DESTDIR)$(htmldir)/html;
	-chmod -R u+w $(DESTDIR)$(htmldir)/html

uninstall-local:
	-chmod -R +w $(DESTDIR)$(htmldir)/html;
	rm -rf $(DESTDIR)$(htmldir)/html;

temp-clean:
	rm -rf Makefile

clean-local:
	-rm -rf html

.PHONY: html
