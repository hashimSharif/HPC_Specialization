TOOLNAME=dump
WRAPPER=upcc-$(TOOLNAME)
LIB=libgasp-$(TOOLNAME).a
LIB_PREFIX=$(exec_prefix)/gasp-$(TOOLNAME)
INCLUDE_PREFIX=$(exec_prefix)/gasp-$(TOOLNAME)
EXEC_PREFIX=$(exec_prefix)
VPATH=$(srcdir)
OBJS=gasp.o
UPCALL_SRCS=gaspu.upc gaspu.h
#GASP_CFLAGS=-O0 -fno-inline -Wall

all: $(LIB) $(builddir)/upcc-$(TOOLNAME)

.c.o:
	$(CC) $(GASP_CFLAGS) -c $< -I$(gasp_incdir)

$(LIB): $(OBJS)
	$(AR) cru $@ $<
	$(RANLIB) $@

$(builddir)/upcc-$(TOOLNAME): force
	@srcfile="$(srcdir)/`basename $@`" ; \
         if test ! -f "$@" -o "`find $$srcfile -newer '$@' 2>&1`" ; then \
          echo $(PERL) -pe 's!\@TOP_SRCDIR\@!$(top_srcdir)!g' \< "$$srcfile" \> $@ ;         \
          $(PERL) -pe 's!\@TOP_SRCDIR\@!$(top_srcdir)!g' < "$$srcfile" > $@ ;         \
	  chmod +x $@ ; \
         fi

clean: force
	rm -f $(LIB) $(OBJS)

install: force
	mkdir -p $(INCLUDE_PREFIX)
	cd $(srcdir) && cp -f $(UPCALL_SRCS) $(INCLUDE_PREFIX)
	mkdir -p $(EXEC_PREFIX)
	cp -f $(WRAPPER) $(EXEC_PREFIX)
	chmod 755 $(EXEC_PREFIX)/$(WRAPPER)
	mkdir -p $(LIB_PREFIX)
	cp -f $(LIB) $(LIB_PREFIX)
	$(RANLIB) $(LIB_PREFIX)/$(LIB)
	chmod 644 $(LIB_PREFIX)/$(LIB)

uninstall: force
	rm -f $(EXEC_PREFIX)/$(WRAPPER) $(LIB_PREFIX)/$(LIB)
	srcs='$(UPCALL_SRCS)' ; for file in $$srcs ; do \
	   rm -f "$(INCLUDE_PREFIX)/$$file" ; \
	done

.PHONY: force
force:

