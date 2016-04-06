SHELL=/bin/sh
BENCHMARK=cg
BENCHMARKU=CG
include ../config/make.def
PROGRAM  = $(BINDIR)/cgL2.$(CLASS).$(THREADS)
OBJS = cgL2.o ${COMMON}/c_print_results.o  \
	${COMMON}/c_${RAND}.o ${COMMON}/c_timers.o ${COMMON}/wtime.o
include ../sys/make.common
${PROGRAM}: config ${OBJS}
	${CLINK}  ${THREADF} -o ${PROGRAM} ${OBJS} ${C_LIB} ; rm *.o
cgL2.o:           cgL2.upc  npbparams.h
	ln -s cgL2.upc cgL2.${LSUFIX} 2> /dev/null ; exit 0
	${CCOMPILE} ${CFLAG} ${THREADF} cgL2.${LSUFIX}

