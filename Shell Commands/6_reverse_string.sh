#!/bin/bash

echo "Enter String :"
read str

L=${#str}

for((i=$((L - 1)); i >= 0 ; i--))
do
	rev="$rev${str:$i:1}"
done

echo "Reversed String :"
echo $rev
