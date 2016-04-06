

UPCC		= upcc
CPPFLAGS 	= -I../../include

OBJS		=  bar.o

.SUFFIXES: .c .o

.c.o:
	$(UPCC) -c $(CPPFLAGS) -o $@ $<

all: $(OBJS)


clean:
	-rm -f bar.o
