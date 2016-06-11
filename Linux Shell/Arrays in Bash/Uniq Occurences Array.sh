# There are N integers in an array A. All but one integer occur in pairs. Your task is to find the number that occurs only once.
read
declare -a arr
arr=($(cat))
printf "%s\n" "${arr[@]}" | sort | uniq -u