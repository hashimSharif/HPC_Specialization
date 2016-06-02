#!/bin/tcsh

set LC = `grep volatile bug46.upc.w2c.c | wc -l`
if($LC == 4) then
    echo "Passed: bug46"
else
    echo "Error: bug46"
endif

set LC = `grep UPCR_SHARED_TO_LOCAL  bug39.upc.w2c.c | wc -l`
if($LC == 2) then
    echo "Passed: bug39"
else
    echo "Error: bug39"
endif

set LC = `grep UPCR_SHARED_TO_PSHARED  bug31.upc.w2c.c | wc -l`
if($LC == 1) then
    echo "Passed: bug31"
else
    echo "Error: bug31"
endif

set LC = `filetest -e bug53.upc.w2c.c`
if($LC == 1) then
    echo "Passed: bug53"
else
    echo "Error: bug53"
endif

set LC = `grep upcr_mythread  bug33.upc.w2c.c | wc -l`
if($LC == 2) then
    echo "Passed: bug33"
else
    echo "Error: bug33"
endif
