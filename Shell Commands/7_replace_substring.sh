#!/bin/bash

echo "Enter string :"
read str

echo "Enter char to be replaced :"
read a

echo "Enter char to replace :"
read b

replace=${str//[$a]/$b}

echo "New string :"
echo $replace
