#! /bin/bash

for i in `seq 1 1000`
do
	startTime=$(( (RANDOM % 99) + 1 ))
	size=$(( (RANDOM % 63) + 1 ))
	endTime=$(( (RANDOM % 9) + 1 ))
	
	echo "$startTime,$size,$endTime" >> temp
done

sort -g temp &> $1

rm temp
