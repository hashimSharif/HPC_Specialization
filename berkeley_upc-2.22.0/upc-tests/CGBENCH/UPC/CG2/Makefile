SHELL=/bin/sh
BENCHMARK=cg
BENCHMARKU=CG
include ../config/make.def
PROGRAM  = $(BINDIR)/cgL1.$(CLASS).$(THREADS)
OBJS = cgL1.o ${COMMON}/c_print_results.o  \
	${COMMON}/c_${RAND}.o ${COMMON}/c_timers.o ${COMMON}/wtime.o
include ../sys/make.common
${PROGRAM}: config ${OBJS}
	${CLINK}  ${THREADF} -o ${PROGRAM} ${OBJS} ${C_LIB} ; rm *.o
cgL1.o:           cgL1.upc  npbparams.h
	ln -s cgL1.upc cgL1.${LSUFIX} 2> /dev/null ; exit 0
	${CCOMPILE} ${CFLAG} ${THREADF} cgL1.${LSUFIX}

