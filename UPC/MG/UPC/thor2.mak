CONDUIT?= udp
OPT?= opt
MAK_VER?= seq

SPLIT_FLAGS=

ifeq ($(NERSC_HOST),cori)
CONDUIT= aries
SPLIT_FLAGS= -DTHOR_SPLIT_LARGE
endif

ifeq ($(NERSC_HOST),edison)
CONDUIT= aries
SPLIT_FLAGS= -DTHOR_SPLIT_LARGE
endif

ifeq ($(NERSC_HOST),babbage)
CONDUIT= ibv
endif

ifneq (, $(filter "x$(NERSC_HOST)", "x" "xshepard"))
   NERSC_HOST=shepard
   CONDUIT=ibv
   CXX=mpicxx
   CC=gcc
endif

THOR_SRC=$(THOR_DIR)
THOR_INC=$(THOR_SRC)

# switched off some warnings as they appear from bupc macro expansions
CC_EXTRAFLAGS = -g -fno-omit-frame-pointer -Wall -Wno-unused-function -Wno-unused-but-set-variable
ifeq ($CC, gcc)
  CC_EXTRAFLAGS+= -Wno-unused-label -Wno-unused-value
endif
UPCC_EXTRAFLAGS = $(CC_EXTRAFLAGS:%=-Wc,%)

UPC_INST?=$(shell upcc -print-include-dir)
include $(UPC_INST)/$(CONDUIT)-conduit/$(CONDUIT)-$(MAK_VER).mak
C_INCL= -I$(UPC_INST) -I$(UPC_INST)/upcr_geninclude  -I$(UPC_INST)/upcr_postinclude -I. $(GASNET_CPPFLAGS)

UPCC = $(shell which upcc) -network $(CONDUIT) --uses-mpi
ifeq ($(MAK_VER),par)
   UPCC+= --uses-threads
endif
UPC_INCL=
#V_OPTS=-DVERBOSE_OUTPUT -D_VERBOSE_OUTPUT
OPTS=-D_GNU_SOURCE $(DS_OPTS) $(V_OPTS)
CCOPT= -fopenmp
ifeq ($(OPT),opt)
	CCOPT+= -O3
endif
UPCCOPT=$(CCOPT:%=-Wc,%)

# targets
THOR_SRCS=$(THOR_SRC)/dispatch_client.c $(THOR_SRC)/dispatch_server.c $(THOR_SRC)/support.c $(THOR_SRC)/system_stats.c
THOR_OBJS=$(THOR_SRCS:c=o)


# build rules
$(THOR_SRC)/dispatch_server.o: $(THOR_SRC)/dispatch_server.c $(THOR_SRC)/support.h $(THOR_SRC)/cliserv_dispatch.h $(THOR_SRC)/thor/system_stats.h $(THOR_SRC)/Makefile
	$(CC) $(CCOPT) $(SPLIT_FLAGS)  $(CC_EXTRAFLAGS) $(GASNET_DEFINES) -c $(OPTS) $(C_INCL) $(UPC_INCL) $*.c -o $*.o

$(THOR_SRC)/support.o: $(THOR_SRC)/support.c $(THOR_SRC)/support.h $(THOR_SRC)/Makefile
	$(CC) $(CCOPT) $(SPLIT_FLAGS)   $(CC_EXTRAFLAGS) $(GASNET_DEFINES) -c $(OPTS) $*.c -o $*.o

%.o: %.c $(THOR_SRC)/support.h $(THOR_SRC)/cliserv_dispatch.h $(THOR_SRC)/thor/system_stats.h $(THOR_SRC)/Makefile
	$(UPCC) $(UPCCOPT) $(UPCC_EXTRAFLAGS) $(SPLIT_FLAGS)  -D_UPC_CLIENT -c $(OPTS) $*.c -o $*.o
