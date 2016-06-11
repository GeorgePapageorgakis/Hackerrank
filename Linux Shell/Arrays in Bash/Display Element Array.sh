# Given a list of countries, each on a new line, your task is to read them into an array and then display the element indexed at 3. Note that indexing starts from 0.
arr=($(cat))
echo ${arr[3]}

#or

awk 'NR==4'

#or  with spawning subshell with piping

echo $(cat) | cut -f4 -d " "

#or without spawning subshell

while read line
do
   # ignore back quotes - web page inserted them
   c[${#c[@]}]=$line
done
echo ${c[3]}