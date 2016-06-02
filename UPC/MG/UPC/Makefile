.PHONY: all
all: upcagg_bar upcagg_pc upcimm_pc upcimm_bar

THOR_DIR=.
include $(THOR_DIR)/thor.mak

COMPILE_IN_THOR=n

# force pthreads version (PTH) and dispatch server (DS)
DS=1
PTH=0

#BYPASS?=-Wno-cpp
CC+= -xSSE3 -fno-alias -fno-fnalias $(BYPASS)
##CC=gcc -msse3 -O0  $(BYPASS)
DS_OPTS= #-DMG_NO_CA #-D_USE_GET #-D_UPC_OUTSEG 
MG_OPTS=  -D__PRINT_NORM -D__PRINT_COMMUNICATION_BREAKDOWN -D__FUSION_RESIDUAL_RESTRICTION -D__COLLABORATIVE_THREADING=6   -D__PREFETCH_NEXT_PLANE_FROM_DRAM_INTERLEAVED  $(DS_OPTS)
#MG_OPTS=-D__PRINT_COMMUNICATION_BREAKDOWN

ifeq ($(COMPILE_IN_THOR), y)
  MG_OPTS+=-DTHOR_ENABLED
endif

ifdef USE_GET
	DS_OPTS+=-D_USE_GET
endif

ifdef NO_CA
  MG_OPTS+=-DMG_NO_CA
endif

ifdef NO_COMPUTE
  MG_OPTS+=-DNO_COMPUTE
endif

ifdef PROFILE
  UPCC+=-trace
  MG_OPTS+=-DMG_NO_WARMUP
endif

ifdef DEBUG
  UPCC+= -D_DEBUG
  CC+= -D_DEBUG
  CCOPT+=-fkeep-inline-functions
  UPCCOPT+=-Wc,-fkeep-inline-functions
endif

ifeq ($(COMPILE_IN_THOR), y)
  INCL:= -I$(THOR_INC)
  OBJS= $(THOR_OBJS)
else
  INCL=
endif

INCL+= -I.

bar=_BARRIER_SYNC
pc=PC_NO_DB
pcdb=PC_DB

default: upcagg_bar upcagg_pc upcagg_pcdb
default2: upcimm_bar upcimm_pc

upcagg_%: bench.c mg.c box.c operators.native.c operators.upc/exchange_boundary.aggregate.c operators.upc/bench_upc.c operators.upc/max_norm_upc.c $(OBJS) Makefile
	$(CC) $(CCOPT) $(MG_OPTS) $(C_INCL) -D_UPCR -c operators.native.c mg.c box.c bench.c timer.x86.c -D$($*)
	$(UPCC) $(UPCCOPT) $(INCL) $(DS_OPTS) -D_UPC -trans operators.upc/max_norm_upc.c operators.upc/bench_upc.c -D$($*)
	$(UPCC) $(UPCCOPT) $(INCL) -c -D_UPC_DI max_norm_upc.trans.c bench_upc.trans.c
	$(UPCC) $(UPCCOPT) $(INCL) bench.o mg.o box.o operators.native.o timer.x86.o max_norm_upc.o bench_upc.o -o $@ -Wl,-fopenmp $(OBJS)

upcimm_%: bench.c mg.c box.c operators.native.c operators.upc/exchange_boundary.immediate.c operators.upc/bench_upc.c operators.upc/max_norm_upc.c $(OBJS) Makefile
	$(CC) $(CCOPT) $(MG_OPTS) $(C_INCL) -DNO_PACK -D_UPCR -c operators.native.c mg.c box.c bench.c timer.x86.c -D$($*)
	$(UPCC) $(UPCCOPT) $(INCL) -DNO_PACK -D_UPC -trans operators.upc/max_norm_upc.c operators.upc/bench_upc.c -D$($*)
	$(UPCC) $(UPCCOPT) $(INCL) -DNO_PACK -D_UPC_DI -c max_norm_upc.trans.c bench_upc.trans.c
	$(UPCC) $(UPCCOPT) bench.o mg.o box.o operators.native.o timer.x86.o max_norm_upc.o bench_upc.o -o $@ -Wl,-fopenmp $(OBJS)

clean:
	rm -fr *.B *.t *.i *.trans.c *_temps *~ *.N *.o upcagg_* upcimm_*
