TARGETDIR=.
UPCC		= upcc
CPPFLAGS 	= -Iinclude -DTHINGIE="Bar bell" -D MAGIC_NUM=3

OBJS		=  frob/foo/foo.o boo/bar/bar.o

.SUFFIXES: .c .o

.c.o:
	$(UPCC) -c $(CPPFLAGS) -o $@ $<

multidir:  $(OBJS)
	$(UPCC) -o $(TARGETDIR)/$@ $(OBJS)
multidir_st%:  $(OBJS)
	$(UPCC) -o $(TARGETDIR)/$@ $(OBJS)

# build in subdir, in order to test '-I../include'
boo/bar/bar.o:
	$(MAKE) -C boo/bar

clean:
	-rm -f a.out frob/foo/foo.o *.i *.w2c.*
	$(MAKE) -C boo/bar clean
