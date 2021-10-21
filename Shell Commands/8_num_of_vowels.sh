#!/bin/bash

echo "Enter string :"
read str

L=${#str}

cnt=0

while [ $L -gt 0 ]
do
	ch=`expr $str | cut -c $L` #cuts a single char from first
	case $ch in 
	
	[aeiouAEIOU]) cnt=$(($cnt + 1))
	;;
	esac
	L=$((L - 1))
done

echo "No. of vowels :"
echo $cnt
