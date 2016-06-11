# Given a list of countries, each on a new line, your task is to read them into an array and then display the count of elements in that array.
arr=($(cat))
echo ${#arr[@]}


#Length of the Bash Array
#We can get the length of an array using the special parameter called $#.

${#arrayname[@]} #gives you the length of the array.

$ cat arraymanip.sh
declare -a Unix=('Debian' 'Red hat' 'Suse' 'Fedora');
echo ${#Unix[@]} #Number of elements in the array
echo ${#Unix}  #Number of characters in the first element of the array.i.e Debian
$./arraymanip.sh
4
6