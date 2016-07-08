'''
-Transpose
We can generate the transposition of an array using the tool numpy.transpose.
It will not affect the original array, but it will create a new array.

	import numpy
	my_array = numpy.array([[1,2,3], [4,5,6]])
	print numpy.transpose(my_array)

#Output
[[1 4]
 [2 5]
 [3 6]]

-Flatten
The tool flatten creates a copy of the input array flattened to one dimension.

	import numpy
	my_array = numpy.array([[1,2,3], [4,5,6]])
	print my_array.flatten()

#Output
[1 2 3 4 5 6]
'''
from sys import stdin
import numpy

N, M = map(int, input().split())
p = numpy.array([line.split() for line in stdin], int)

print(p.transpose())
print(p.flatten())


'''
N, M = map(int, raw_input().split())
i = numpy.array([raw_input().split() for _ in range(N)], int)
print numpy.transpose(i)
print (i.flatten())



arr = []
input()
p = numpy.array([line.split() for line in stdin], int)
print(p.transpose())
print(p.flatten())
'''
