'''
a = numpy.array([1,2,3,4,5])
print a[1]          #2

b = numpy.array([1,2,3,4,5],float)
print b[1]          #2.0

You are given a space separated list of numbers.
Your task is to print a reversed NumPy array with the element type float.

'''
#!/bin/python3
import numpy	#helps us manipulate large arrays and matrices of numeric data. 

print(numpy.array(input().split(), float)[::-1])
#or
#print (numpy.flipud(numpy.array(input().split(),float)))