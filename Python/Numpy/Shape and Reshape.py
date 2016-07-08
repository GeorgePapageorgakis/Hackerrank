'''
 -The shape tool gives a tuple of array dimensions and can be used to change the dimensions of an array.

(a). Using shape to get array dimensions
	my__1D_array = numpy.array([1, 2, 3, 4, 5])
	print my_1D_array.shape     #(5,) -> 5 rows and 0 columns

	my__2D_array = numpy.array([[1, 2],[3, 4],[6,5]])
	print my_2D_array.shape     #(3, 2) -> 3 rows and 2 columns 

(b). Using shape to change array dimensions

	change_array = numpy.array([1,2,3,4,5,6])
	change_array.shape = (3, 2)
	print change_array      

	#Output
	[[1 2]
	[3 4]
	[5 6]]

 -The reshape tool gives a new shape to an array without changing its data. It creates a new array and does not modify the original array itself.
 
	my_array = numpy.array([1,2,3,4,5,6])
	print numpy.reshape(my_array,(3,2))

	#Output
	[[1 2]
	[3 4]
	[5 6]]
'''
#!/bin/python3
import numpy

arr = numpy.array(input().split(),int)
#without rearranging data
print (numpy.reshape(arr,(3,3)))
#rearranges data on arr
arr.shape = (3,3)
print(arr)
#print (numpy.array(input().split(), int).reshape(3,3))