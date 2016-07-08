
'''
mean
The mean tool computes the arithmetic mean along the specified axis.

	import numpy

	my_array = numpy.array([ [1, 2], [3, 4] ])

	print numpy.mean(my_array, axis = 0)        #Output : [ 2.  3.]
	print numpy.mean(my_array, axis = 1)        #Output : [ 1.5  3.5]
	print numpy.mean(my_array, axis = None)     #Output : 2.5
	print numpy.mean(my_array)                  #Output : 2.5

By default, the axis is None. Therefore, it computes the mean of the flattened array.

var
The var tool computes the arithmetic variance along the specified axis.

	import numpy

	my_array = numpy.array([ [1, 2], [3, 4] ])

	print numpy.var(my_array, axis = 0)         #Output : [ 1.  1.]
	print numpy.var(my_array, axis = 1)         #Output : [ 0.25  0.25]
	print numpy.var(my_array, axis = None)      #Output : 1.25
	print numpy.var(my_array)                   #Output : 1.25

By default, the axis is None. Therefore, it computes the variance of the flattened array.

std
The std tool computes the arithmetic standard deviation along the specified axis.

	import numpy

	my_array = numpy.array([ [1, 2], [3, 4] ])

	print numpy.std(my_array, axis = 0)         #Output : [ 1.  1.]
	print numpy.std(my_array, axis = 1)         #Output : [ 0.5  0.5]
	print numpy.std(my_array, axis = None)      #Output : 1.11803398875
	print numpy.std(my_array)                   #Output : 1.11803398875

By default, the axis is None. Therefore, it computes the standard deviation of the flattened array.

You are given a 2-D array of size X, find:
   1. The mean along axis 1
   2. The var along axis 0
   3. The std along axis None
'''
#!/bin/python3
import numpy
from sys import stdin

N, M = map(int, input().split())
p = numpy.array([line.split() for line in stdin], int)

print (numpy.mean(p, axis = 1))
print (numpy.var(p, axis = 0))
print (numpy.std(p, axis = None))
