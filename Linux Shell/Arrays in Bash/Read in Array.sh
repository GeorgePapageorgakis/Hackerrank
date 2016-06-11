# Given a list of countries, each on a new line, your task is to read them into an array and then display the entire array, with a space between each of the countries' names. 
#! /bin/bash
declare -a myArray
myArray=( `cat`)
printf '%s ' "${myArray[@]}"

or

#! /bin/bash
while read line
do
    my_array=("${my_array[@]}" $line)	# or simply my_array+=( $line )
done
printf '%s ' "${my_array[@]}"
