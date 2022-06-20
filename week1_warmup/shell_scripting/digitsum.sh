#!/bin/bash
num=$1
n=$num
sum=0
while [ $num -gt 0 ]
do
	i=$(( $num % 10 ))
	num=$(( $num / 10 ))
	sum=$(( $sum + $i ))
done
echo "$sum"
