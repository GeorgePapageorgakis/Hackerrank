#!/bin/bash
read c
if [[ "$c" == "Y" || "$c" == "y" ]]; 
then
    echo "YES"
elif [[ "$c" == "N" || "$c" == "n" ]]; 
then
    echo "NO"
fi


:`
You can use either [[ or (( keyword. When you use [[ keyword, you have to use string operators such as -eq, -lt. I think, (( is most preferred for arithmetic, because you can directly use operators such as ==, < and >.

#Using [[ operator
a=$1
b=$2
if [[ a -eq 1 || b -eq 2 ]] || [[ a -eq 3 && b -eq 4 ]]
then
     echo "Error"
else
     echo "No Error"
fi

#Using (( operator
a=$1
b=$2
if (( a == 1 || b == 2 )) || (( a == 3 && b == 4 ))
then
	echo "Error"
else
	echo "No Error"
fi
`