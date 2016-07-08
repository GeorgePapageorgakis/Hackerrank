'''
The NumPy module also comes with a number of built-in routines for linear algebra calculations. These can be found in the sub-module linalg.

linalg.det
The linalg.det tool computes the determinant of an array.

	print numpy.linalg.det([[1 , 2], [2, 1]])       #Output : -3.0

linalg.eig
The linalg.eig computes the eigenvalues and right eigenvectors of a square array.

	vals, vecs = numpy.linalg.eig([[1 , 2], [2, 1]])
	print vals                                      #Output : [ 3. -1.]
	print vecs                                      #Output : [[ 0.70710678 -0.70710678]
													#          [ 0.70710678  0.70710678]]

linalg.inv
The linalg.inv tool computes the (multiplicative) inverse of a matrix.

	print numpy.linalg.inv([[1 , 2], [2, 1]])       #Output : [[-0.33333333  0.66666667]
													#          [ 0.66666667 -0.33333333]]

Given a square matrix A with dimensions N x N find the determinant.
'''
#!/bin/python3
import numpy
import sys

n = int(input())
A = numpy.array([input().split() for _ in range(n)], dtype=float)
print(numpy.linalg.det(A))