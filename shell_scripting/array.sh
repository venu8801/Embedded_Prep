#! /bin/bash


#array variable in shell scripting

array_test=(my name is venu gopal)
string="hello moshcip tech"
#echo $string

for names in  ${array_test[*]}
do
    echo $names
    
done

echo "--------------"
