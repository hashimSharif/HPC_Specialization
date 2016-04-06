SHELL=/bin/sh
BENCHMARK=cg
BENCHMARKU=CG
include ../config/make.def
PROGRAM  = $(BINDIR)/cgomp.$(CLASS).$(THREADS)
OBJS = cg.o ${COMMON}/c_print_results.o  \
	${COMMON}/c_${RAND}.o ${COMMON}/c_timers.o ${COMMON}/wtime.o
include ../sys/make.common
${PROGRAM}: config ${OBJS}
	${CLINK} -o ${PROGRAM} ${OBJS} ${C_LIB}  ; rm *.o
cg.o:           cg.c  npbparams.h
	${CCOMPILE} ${CFLAG} cg.c

