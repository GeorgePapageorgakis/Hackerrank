#!/bin/bash
read x
read y
#Arithmetic in POSIX shells is done with $ and double parentheses:
echo "$(($x+$y))"
#You can assign from that (sans echo). There is also expr:
expr $x - $y
#In scripting $(()) is preferable since it avoids a fork/execute for the expr command.
echo "$(($x*$y))"
echo "$(($x/$y))"