#! /bin/bash

var=10

while [ $var -lt 100 ]
do 
	echo $var
	var=`expr $var + 10`
done


