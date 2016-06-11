# Given a list of countries, each on a new line, your task is to read them into an array. Then, concatenate the array with itself (twice) - so that you have a total of two repetitions of the original array - and then display the entire concatenated array, with a space between each of the countries' names.
declare -a array
array=( `cat` )
array+=("${array[@]}" "${array[@]}")
echo ${array[@]}