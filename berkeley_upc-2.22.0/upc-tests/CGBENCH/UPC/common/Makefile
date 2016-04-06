SHELL=/bin/sh
include ../config/make.def
OBJ: c_print_results.o c_timers.o  wtime.o  c_${RAND}.o
c_print_results.o  : c_print_results.c
	$(CCOMPILE) -c  c_print_results.c
c_${RAND}.o        : c_${RAND}.c
	$(CCOMPILE) -c c_${RAND}.c
c_timers.o 	   : c_timers.c
	$(CCOMPILE) -c c_timers.c 
wtime.o            : wtime.c
	$(CCOMPILE) -c wtime.c

clean:
	- rm -f core 
	- rm -f *~ *.o 
