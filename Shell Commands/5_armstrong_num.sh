#!/bin/bash

echo "Enter Number :"
read N

len=${#N}
A=0
n=$N

while [ $n -ne 0 ]
do
	r=$((n % 10))
	n=$((n / 10))
	P=$(($r * $r * $r))
	A=$((A + $P))
done

if [ $A -eq $N ]
then
	echo "$N is an Armstrong Number!"
else
	echo "$N is not an Armstrong Number!"
fi
