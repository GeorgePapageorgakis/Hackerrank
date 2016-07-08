'''
inner
The inner tool returns the inner product of two arrays.

	import numpy

	A = numpy.array([0, 1])
	B = numpy.array([3, 4])

	print numpy.inner(A, B)     #Output : 4

outer
The outer tool returns the outer product of two arrays.

	import numpy

	A = numpy.array([0, 1])
	B = numpy.array([3, 4])

	print numpy.outer(A, B)     #Output : [[0 0]
								#          [3 4]]


Given two arrays: A and B.
Compute their inner and outer product.
'''
#!/bin/python3
import numpy
import sys

a, b = (numpy.array(input().split(), dtype=int) for _ in range(2))
print(numpy.inner(a, b))
print(numpy.outer(a, b))