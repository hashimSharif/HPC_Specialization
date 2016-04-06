TRACEFILE= 
CC=cc
CFLAGS= 
LDFLAGS=
LIBS=

upctrace-testtrace: upctrace-testtrace.c
	$(CC) $(CFLAGS) -o $@.o -c $<
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $@.o $(LIBS)
upctrace-testtrace_st%: upctrace-testtrace.c
	$(CC) $(CFLAGS) -o $@.o -c $<
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $@.o $(LIBS)

