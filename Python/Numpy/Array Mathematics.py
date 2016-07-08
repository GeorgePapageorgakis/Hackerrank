'''
Basic mathematical functions operate element-wise on arrays. They are available both as operator overloads and as functions in the NumPy module.

import numpy

a = numpy.array([1,2,3,4], float)
b = numpy.array([5,6,7,8], float)

print a + b                     #[  6.   8.  10.  12.]
print numpy.add(a, b)           #[  6.   8.  10.  12.]

print a - b                     #[-4. -4. -4. -4.]
print numpy.subtract(a, b)      #[-4. -4. -4. -4.]

print a * b                     #[  5.  12.  21.  32.]
print numpy.multiply(a, b)      #[  5.  12.  21.  32.]

print a / b                     #[ 0.2         0.33333333  0.42857143  0.5       ]
print numpy.divide(a, b)        #[ 0.2         0.33333333  0.42857143  0.5       ]

print a % b                     #[ 1.  2.  3.  4.]
print numpy.mod(a, b)           #[ 1.  2.  3.  4.]

print a**b                      #[  1.00000000e+00   6.40000000e+01   2.18700000e+03   6.55360000e+04]
print numpy.power(a, b)         #[  1.00000000e+00   6.40000000e+01   2.18700000e+03   6.55360000e+04]


You are given two arrays (A & B) of dimensions N x M.
Your task is to perform the following operations:

    Add (A + B)
    Subtract (A - B)
    Multiply (A * B)
    Divide (A / B)
    Mod (A % B)
    Power (A ** B)
'''
#!/bin/python3
import numpy
import sys

N, M = map(int, input().strip().split())
a, b = (numpy.array([input().split() for _ in range(N)], dtype=int) for _ in range(2))

print (numpy.add(a, b))
print (numpy.subtract(a, b))
print (numpy.multiply(a, b))
#In Python 2, when both are integer type, divide will behave like floor_divide. In Python 3, it behaves like true_divide
print (numpy.floor_divide(a, b))
print (numpy.mod(a, b))
print (numpy.power(a, b))
'''
2 4
1 2 3 4
1 2 3 4
5 6 7 7
5 6 7 7

[[ 6  8 10 11]
 [ 6  8 10 11]]
[[-4 -4 -4 -3]
 [-4 -4 -4 -3]]
[[ 5 12 21 28]
 [ 5 12 21 28]]
[[0 0 0 0]
 [0 0 0 0]]
[[1 2 3 4]
 [1 2 3 4]]
[[    1    64  2187 16384]
 [    1    64  2187 16384]]
'''