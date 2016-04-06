#!/bin/sh

#List="1 3 5 6 7 9 10 11 12 13 14 15 16"
#List="1 2 3 4 5 6 7 8"
#List="9 10 11 12 13 14 15 16"
#List="2 4 8 16 32"
List="2"


for i in ${List} ; do
	./run.sh $i $1
done
