# You are given a list of countries, each on a new line. Your task is to read them into an array and then filter out (remove) all the names containing the letter 'a' or 'A'.
grep -vi a

or

declare -a array
array=( `cat` )
echo ${array[@]/*[aA]*/}

or

echo $(sed /[aA]/g)
