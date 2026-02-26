# -*- coding: utf-8 -*-
"""
Created on Sat Feb 14 09:15:22 2026

@author: admin
"""
from functools import reduce
add=lambda num : num+4
print(add(6))

f= lambda x,y : x+y
print(f(3,2))

max= lambda x,y : x if x>y else y
print(max(3,4))

lst =[int(n) for n in input("Enter the two numbers").split(',') if n!='@']
print(lst)

# filter function
def is_even(x):
    if x%2==0:
        return True
    else:
        return False

l1=list(filter(is_even,lst))
print(l1)

l2=list(filter(lambda x: x%2==0,lst))
print(l2)


# reduce function
lst=[1,2,3,4,5]
r=reduce(lambda x,y : x*y,lst)
print(r)


# map function
from functools import *
lst=[1,2,3,4,5]
r=list(map(lambda x:x*x,lst))
print(r)


# sorted for list
words = ["apple", "kiwi", "banana"]

result = sorted(words, key=lambda x: len(x))
print(result)

students = [("Riya", 85,"z"), ("Ankit", 90,"y"), ("Zara", 80,"t")]

result = sorted(students, key = lambda x: x[1])
print(result)

data = {"Riya":85, "Ankit": 90 , "Zara":80}

result = sorted(data.items(), key = lambda x: x[0])
print(result)

result = dict(sorted(data.items(), key = lambda x: x[1]))
print(result)

data = {"Riya":(85,34), "Ankit": (90,75) , "Zara":(80,45)}

result = sorted(data.items(), key = lambda x : x[1][0],reverse=True)
print(result)



    
    
        


