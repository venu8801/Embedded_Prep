#! /bin/bash

#shell functions

hello()
{
	echo `expr $1 + $2`
	return 89
}
hello 3 4
var=$?
echo "return value: $var"
