#!/bin/sh

for i in *in*
do
	cat $i
	./a.out < $i
	echo
done
