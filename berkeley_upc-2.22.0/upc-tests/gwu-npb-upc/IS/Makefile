SHELL=/bin/sh
BENCHMARK=is
BENCHMARKU=IS
CLASS=S
NP=$(UPCTHREADS)
DEFAULT_VARIANT=O1

include ../config/make.def

OBJS = ${COMMON}/c_${RAND}.o ${COMMON}/c_print_results.o

include ../sys/make.common

ifndef VARIANT
VARIANT = ${DEFAULT_VARIANT}
endif

OBJ-EXEC = ${BENCHMARK}.${CLASS}.${VARIANT}.${NP}.o
SOURCE = variants/${BENCHMARK}.${VARIANT}.c
EXEC = ${PROGRAM}.${VARIANT}.${NP}
CFLAGS += -I./

CCOMPILE += -I$(COMMON) -o ${OBJ-EXEC}
CLINKFLAGS += 

${BENCHMARK}:
	echo "error: must compile with static threads"
	exit 1

${BENCHMARK}_st%:
	$(MAKE) clean
	$(MAKE) config $(OBJS) ${OBJ-EXEC}
	${CLINK} ${OBJ-EXEC} ${CLINKFLAGS} -o $@ ${OBJS} ${C_LIB}

all: $(PROGRAM)

${PROGRAM}: config ${OBJ-EXEC} ${OBJS}
	${CLINK} ${OBJ-EXEC} ${CLINKFLAGS} -o ${EXEC} ${OBJS} ${C_LIB}
#	mv ${EXEC} ${BINDIR}

${OBJ-EXEC}: ${SOURCE} npbparams.h
	${CCOMPILE} ${SOURCE}

clean:
	rm -f *.o *~ ../common/*.o 
	rm -f npbparams.h core ../sys/setconfig
