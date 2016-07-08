'''
Sample Input
3

Sample Output
123
'''
#!/bin/python
from __future__ import print_function
import sys

N = int(input())
for i in range(1, N+1):
    print(i, end='')

#operator '*' allows you to pass an array
#print(*range(1, int(input())+1), sep='')