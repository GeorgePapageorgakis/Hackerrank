from __future__ import division

a = int(input())
b = int(input())

print(a+b)
print(a-b)
print(a*b)

print (a//b)	#integer division
print (a/b)		#float division

#print squares
n = int(input())
for i in range(0, n):
    print (i*i)