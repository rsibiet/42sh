#!/bin/zsh

i="1"

while [ $i != "32" ]; do
	~/Projects/sh42/sh42 &
	echo "##### sh42 ####"
	echo "signal :" $i
	killall -`echo $i` sh42
	echo "###############"
	#echo "##### sh ####"
	#killall -$i sh
	#echo "###############"
	let i++
done
