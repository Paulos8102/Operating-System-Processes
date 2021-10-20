#!/bin/bash

echo "Enter number : "
read n
echo "First $n natural numbers are :"

for((i=1;i<=n;i++))
do
	echo $i
done
