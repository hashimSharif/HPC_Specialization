TESTS = gwu intrepid bugzilla-compilation bugzilla-run mupc UPC-Coll-RefImp spec1.3
TEST-CLEAN = $(TESTS)
TOP = $(shell pwd)

.PHONY: tests $(TESTS)


tests:: $(TESTS)

$(TESTS)::
	$(MAKE) -C $@ 

clean::
	for t in $(TESTS); do\
	  if [ -d $$t ]; then \
	    cd $$t;\
	    gmake clean;\
	    cd $(TOP);\
	  fi;\
	done

runall:
	for t in $(TESTS); do\
	  if [ -d $$t ]; then \
	    cd $$t;\
	    gmake runall;\
	    cd $(TOP);\
	  fi;\
	done

