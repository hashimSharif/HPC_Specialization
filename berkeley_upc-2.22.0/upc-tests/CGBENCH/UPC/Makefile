SHELL=/bin/sh
CLASS=S
THREADS=1
SFILE=config/suite.def
default: header
	@ $(SHELL) sys/print_instructions

%-S: force
	$(MAKE) CLASS=S PROGRAM='../$@' `echo $@ | awk -F- '{ print $$1 }'`

%-W: force
	$(MAKE) CLASS=W PROGRAM='../$@' `echo $@ | awk -F- '{ print $$1 }'`

%-A: force
	$(MAKE) CLASS=A PROGRAM='../$@' `echo $@ | awk -F- '{ print $$1 }'`

%-B: force
	$(MAKE) CLASS=B PROGRAM='../$@' `echo $@ | awk -F- '{ print $$1 }'`

%-C: force
	$(MAKE) CLASS=C PROGRAM='../$@' `echo $@ | awk -F- '{ print $$1 }'`

.PHONY: force header
force:

CG1: cg1		       
cg1: header	       
	cd CG1; $(MAKE) CLASS=$(CLASS)  THREADS=$(THREADS)
CG2: cg2
cg2: header
	cd CG2; $(MAKE) CLASS=$(CLASS) THREADS=$(THREADS)
CG3: cg3
cg3: header
	cd CG3; $(MAKE) CLASS=$(CLASS) THREADS=$(THREADS)
# Awk script courtesy cmg@cray.com
suite:
	@ awk '{ if ($$1 !~ /^#/ &&  NF > 0)                              \
	printf "make %s CLASS=%s\n", $$1, $$2 }' $(SFILE)  \
	| $(SHELL)
# It would be nice to make clean in each subdirectory (the targets
# are defined) but on a really clean system this will won't work
# because those makefiles need config/make.def
clean:
	- rm -f core 
	- rm -f *~ */core */*~ */*.o */npbparams.h */*.obj */*.exe
	- rm -f sys/setparams sys/makesuite sys/setparams.h
veryclean: clean
	- rm config/make.def config/suite.def Part*
	- rm bin/sp.* bin/lu.* bin/mg.* bin/ft.* bin/bt.* bin/is.* bin/ep.* bin/cg.*
header:
	rm -f common/*.o */npbparams.h
	@ $(SHELL) sys/print_header
kit: 
	- makekit -s100k -k30 * */* */*/*
