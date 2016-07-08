'''
zeros
	The zeros tool returns a new array with a given shape and type filled with 's.

	import numpy

	print numpy.zeros((1,2))                    #Default type is float
	#Output : [[ 0.  0.]] 
	print numpy.zeros((1,2), dtype = numpy.int) #Type changes to int
	#Output : [[0 0]]

ones
The ones tool returns a new array with a given shape and type filled with 's.

	import numpy

	print numpy.ones((1,2))                    #Default type is float
	#Output : [[ 1.  1.]] 
	print numpy.ones((1,2), dtype = numpy.int) #Type changes to int
	#Output : [[1 1]]   

Print an array of size N and integer type using the tools zeros and ones. N is the space separated list of the dimensions of the array.
'''
import numpy
import sys

N = tuple(map(int, input().strip().split()))

print (numpy.zeros(N, dtype = numpy.int))
print (numpy.ones(N, dtype = numpy.int))


'''
x, y, z = map(int, input().split())
print (numpy.zeros((x, y, z), dtype = numpy.int))
print (numpy.ones((x, y, z), dtype = numpy.int))
'''