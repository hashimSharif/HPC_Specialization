#!/bin/sh

List="char short int long float double"

for i in ${List} ; do
 	sed 's/DATA/'$i'/' < $2 > prm.c
	run.sh $1 prm.c 
done

#echo "\007" 
