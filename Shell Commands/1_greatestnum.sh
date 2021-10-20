#!/bin/bash

#shell script for greatest of 3 numbers

echo "Number 1 : "
read n1
echo "Number 2 : "
read n2
echo "Number 3 : "
read n3

echo "Greatest Number is : "

if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then
	echo $n1
elif [ $n2 -gt $n3 ]
then
	echo $n2
else
	echo $n3
fi
