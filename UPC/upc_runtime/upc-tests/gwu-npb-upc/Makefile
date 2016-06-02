SHELL=/bin/sh
CLASS=S
SFILE=config/suite.def
NASVERSION=2.4

default: header
	@ $(SHELL) sys/print_instructions

%-S: force
	$(MAKE) CLASS=S PROGRAM='../$@' EXEC='../$@' `echo $@ | awk -F- '{ print $$1 }'`

%-W: force
	$(MAKE) CLASS=W PROGRAM='../$@' EXEC='../$@' `echo $@ | awk -F- '{ print $$1 }'`

%-A: force
	$(MAKE) CLASS=A PROGRAM='../$@' EXEC='../$@' `echo $@ | awk -F- '{ print $$1 }'`

%-B: force
	$(MAKE) CLASS=B PROGRAM='../$@' EXEC='../$@' `echo $@ | awk -F- '{ print $$1 }'`

%-C: force
	$(MAKE) CLASS=C PROGRAM='../$@' EXEC='../$@' `echo $@ | awk -F- '{ print $$1 }'`

.PHONY: force header release
force:

BT: bt
bt: header
	cd BT; $(MAKE) CLASS=$(CLASS)
		       
SP: sp		       
sp: header	       
	cd SP; $(MAKE) CLASS=$(CLASS)
		       
LU: lu		       
lu: header	       
	cd LU; $(MAKE) CLASS=$(CLASS)
		       
MG: mg		       
mg: header	       
	cd MG; $(MAKE) CLASS=$(CLASS)
		       
FT: ft		       
ft: header	       
	cd FT; $(MAKE) CLASS=$(CLASS)
		       
IS: is		       
is: header	       
	cd IS; $(MAKE) CLASS=$(CLASS)
		       
CG: cg		       
cg: header	       
	cd CG; $(MAKE) CLASS=$(CLASS)
		       
EP: ep		       
ep: header	       
	cd EP; $(MAKE) CLASS=$(CLASS)

BTIO: btio		       
btio: header	       
	cd BTIO; $(MAKE) CLASS=$(CLASS)

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
	- rm -f -r SP/sp.*_pthread-link MG/mg.*_pthread-link FT/ft.*_pthread-link IS/is.*_pthread-link EP/ep.*_pthread-link CG/cg.*_pthread-link
	- rm -f SP/sp.* MG/mg.* FT/ft.* IS/is.* EP/ep.* CG/cg.*

veryclean: clean
	- rm config/make.def config/suite.def Part*
	- rm bin/sp.* bin/lu.* bin/mg.* bin/ft.* bin/bt.* bin/is.* bin/ep.* bin/cg.*

header: 
	rm -f */*.o */npbparams.h sys/setparams
	@ $(SHELL) sys/print_header

kit: 
	- makekit -s100k -k30 * */* */*/*

ChangeLog: force
	svn up
	svn2cl.sh -i -a --linelen=80 --authors=authors.xml --break-before-msg=2 -r BASE:3

release: ChangeLog
	svn export . npb-upc-$(NASVERSION)-`date +%y.%m`
	cp ChangeLog npb-upc-$(NASVERSION)-`date +%y.%m`/
	tar cvfz npb-upc-$(NASVERSION)-`date +%y.%m`.tar.gz npb-upc-$(NASVERSION)-`date +%y.%m`/
	rm -rf npb-upc-$(NASVERSION)-`date +%y.%m`
	cp ChangeLog npb-upc-$(NASVERSION)-`date +%y.%m`-ChangeLog
