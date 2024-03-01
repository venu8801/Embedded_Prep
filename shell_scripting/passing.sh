#! /bin/bash
# script to pass arguements 
echo $1 $2 $3 # these are like command line arguements 
echo "this is first arguement script file name: $0"

#passing as an array 
args_array=("$@") # "$@ is the sign for array of args passed"
echo   ${args_array[0]} , ${args_array[1]}  
echo "----------------------------------------"
echo $@  #prints all the args passed 
echo "end"