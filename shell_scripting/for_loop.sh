#! /bin/bash

#for loop in scripting


var=10

for var in 10 20 30
do
	echo $var
	var=`expr $var + 10`
done

