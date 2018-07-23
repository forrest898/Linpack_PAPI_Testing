#!/bin/bash

counter=0
filename="$1"
while read -r line
do
	counter=$((counter + 1))
    name="$line"
	mpirun -np 4 ./xhpl $counter $line > /dev/null < /dev/null
	sleep 5
done < "$filename"
