1SHELL=/bin/sh
BENCHMARK=cg
BENCHMARKU=CG
include ../config/make.def
PROGRAM  = $(BINDIR)/cgB.$(CLASS).$(THREADS)
OBJS = cgB.o ${COMMON}/c_print_results.o  \
	${COMMON}/c_${RAND}.o ${COMMON}/c_timers.o ${COMMON}/wtime.o
include ../sys/make.common
cgB.o:           cgB.upc  npbparams.h
	ln -s cgB.upc cgB.${LSUFIX} 2> /dev/null ; exit 0
	${CCOMPILE} ${THREADF} cgB.${LSUFIX}
${PROGRAM}: config ${OBJS}
	${CLINK} ${THREADF} -o ${PROGRAM} ${OBJS} -lm; rm *.o

