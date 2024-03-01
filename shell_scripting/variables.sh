#! /bin/bash

# using variables 
#syntax for defining a variable 
#variable_name=variable_value
#these variables are also called as scalar variables which can store only one value at a time


first_name="venu gopal"
COMPANY="MOSCHIP"
readonly last_name="atchyutanna" #this makes it a readonly variable 
# this variable cannot be modified

echo "THIS IS $BASH SHELL"
echo $first_name
echo $last_name
last_name="moschip"
echo $last_name

echo $COMPANY


echo "--------------------"
echo $RED
 echo -e >&2 ${RED}Do not flash the image with Trusty OS to SD card${STD}
#clear

