#!/bin/bash
#evaluate the expression and display the output correct to 3 decimal places.
#Sample Input:
#5+50*3/20 + (19*2)/7
#
#Sample Output:
#17.929

read s
printf "%.3f" `echo $s |  bc -l`

#using echo and bs does not round up
#echo "scale = 3; $s" | bc -l