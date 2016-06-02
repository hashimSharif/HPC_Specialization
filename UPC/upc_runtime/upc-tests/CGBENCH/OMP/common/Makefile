SHELL=/bin/sh
include ../config/make.def
OBJ: c_print_results.o c_timers.o  wtime.o  c_${RAND}.o
c_print_results.o  : c_print_results.c
	cc -c  c_print_results.c
c_${RAND}.o        : c_${RAND}.c
	cc -c c_${RAND}.c
c_timers.o 	   : c_timers.c
	cc -c c_timers.c 
wtime.o            : wtime.c
	cc -c wtime.c

clean:
	- rm -f core 
	- rm -f *~ *.o 