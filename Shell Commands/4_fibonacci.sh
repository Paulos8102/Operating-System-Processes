#!/bin/bash

f1=0 #first element
f2=1 #second element

echo "Enter number of elements :"
read n

echo "The fibonacci series :"

echo $f1
for((i=1; i<n; i++))
do
	echo $f2
	next=$((f1 + f2))
	f1=$f2
	f2=$next
done
