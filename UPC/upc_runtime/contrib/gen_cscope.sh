#/bin/sh

# (re)builds cscope database for UPC runtime and gasnet
#   - includes C files, perl scripts, and autotools

# go to / to store absolute paths in the cscope database
ROOT=`pwd`
cd / 	

# use 'grep -v' to remove directory trees: find's -prune option leaves top-level
# directory name (which crashes cscope), and no other find options seem to be
# able to get rid of it.
find  $ROOT                         \
        \(     -name "*.[chl]"      \
            -o -name "*.cpp"        \
            -o -name "*.p[lm]"      \
            -o -name "*Makefile.am" \
            -o -name "*.in"         \
            -o -name "*.m4"         \
        \)                          \
        ! -name "*Makefile.in"      \
        ! -name "*aclocal.m4"       \
        ! -name "*upcr_config.h*"   \
        ! -name "*scanner.c"        \
        ! -name "*upc-tests*"       \
        ! -name "*upc-examples*"    \
        | grep -v 'perverse'        \
        | grep -v 'upc-examples'    \
        | grep -v 'tests'           \
        >$ROOT/cscope.files


### Build cscope database
# -q for inverted index (for fast symbol lookup)
# -b to build ref only: no interaction
# add -k if you don't want standard /usr/include files to be parsed
cd $ROOT 
cscope -q -b 


