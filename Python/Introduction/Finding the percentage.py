'''
You have a record of N students. Each record contains the student's name, and their percent marks in Maths, Physics and Chemistry. The marks can be floating values. The user enters some integer N followed by the names and marks for N students. You are required to save the record in a dictionary data type. The user then enters a student's name. Output the average percentage marks obtained by that student, correct to two decimal places.
Sample Input
3
Krishna 67 68 69
Arjun 70 98 63
Malika 52 56 60
Malika

Sample Output
56.00
'''
#!/bin/python3
import sys

dictionary = {}
n = int(input())

for line in range(n):
    #get input, split it by space and store as list [Krishna, 67, 68, 69]...
    info = input().split(" ")
    #map scores from list
    scores = map(float, info[1:])
    #assign average score to each key (name)
    dictionary[info[0]] = sum(scores) / len(info[1:])
print ("%.2f" % dictionary[input()])