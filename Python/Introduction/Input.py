'''
If you need to take two integers say a,b in python you can use map function.
1
5 3
1 2 3 4 5

where 1 represent test case, 5 represent number of values and 3 represents a task value and in next line given 5 values, we can take such input using this method in PYTH 2.x Version.
'''
testCases=int(input())
number, taskValue = map(int, input().split())
array = map(int, input().split())

#
#
var1, var2 = input("Enter two numbers here: ").split()
#However, if you ran the above then var1 and var2 would be both Strings. You can convert them to int using another line

var1, var2 = [int(var1), int(var2)]

#Or you could use list comprehension

var1, var2 = [int(x) for x in [var1, var2]]

#To sum it up, you could have done the whole thing with this one-liner:

var1, var2 = [int(x) for x in input("Enter two numbers here: ").split()]



#array
#1 2
#3 4
#...
p = numpy.array([line.split() for line in stdin], int)