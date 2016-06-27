#!/bin/python
'''Given an integer, , perform the following conditional actions:

    If n is odd, print Weird
    If n is even and in the inclusive range of 2 to 5, print Not Weird
    If n is even and in the inclusive range of6  to 20, print Weird
    If n is even and greater than 20, print Not Weird
'''
import sys

N = int(raw_input().strip())
if (N % 2 != 0):
    print("Weird")
else:
    if(N>1 and N<6) or (N>20):
        print("Not Weird")
    elif(N>5 and N<21):
        print("Weird")