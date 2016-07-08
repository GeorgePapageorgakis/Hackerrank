'''
dot
The dot tool returns the dot product of two arrays.

	import numpy

	A = numpy.array([ 1, 2 ])
	B = numpy.array([ 3, 4 ])

	print numpy.dot(A, B)       #Output : 11

cross
The cross tool returns the cross product of two arrays.

	import numpy

	A = numpy.array([ 1, 2 ])
	B = numpy.array([ 3, 4 ])

	print numpy.cross(A, B)     #Output : -2

Given two arrays A and B. Both have dimensions of NxN.
Your task is to compute their matrix product.
'''
#!/bin/python3
import numpy
import sys

n = int(input())
a, b = (numpy.array([input().split() for _ in range(n)], dtype=int) for _ in range(2))

#matrix multiplication is like dot product
print(numpy.dot(a, b))