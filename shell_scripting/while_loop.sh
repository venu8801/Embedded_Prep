#! /bin/bash

#while loop in script file
var=10
while [ $var -gt 0 ]
do
	echo $var
	var=`expr $var - 1`
done

