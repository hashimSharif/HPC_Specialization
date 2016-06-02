AR = ar
RANLIB = ranlib
UPCC = upcc
TARGETDIR=.

c_link: c_link.o sum.o libsq.a
	$(UPCC) -o $(TARGETDIR)/$@ c_link.o sum.o -L. -lsq
c_link_st%: c_link.o sum.o libsq.a
	$(UPCC) -o $(TARGETDIR)/$@ c_link.o sum.o -L. -lsq

c_link.o: c_link.c
	$(UPCC) -c c_link.c

sum.o: sum.c
	$(CC) -c sum.c

libsq.a: 
	$(CC) -c sq.c
	$(AR) cru libsq.a sq.o
	$(RANLIB) libsq.a

clean:
	-rm -f sum.o c_link.o sq.o libsq.a c_link
