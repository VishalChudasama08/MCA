# Practice test.docx

"""
3.	Read the random lists from the text file where numbers are comma separated and one list in one line. Show the list in ascending order

Eg. unsorted list: 95 79 19 43 52 in 1st line of the file) Similarly many more unsorted list are there.
o/p : [19, 43, 52, 79, 95]

"""

import random


l = [] # list as file line 
for i in range(random.randrange(4, 12)):
    l.append(random.randrange(1, 100))

print("random list:",l)

print("Sorted list:",sorted(l))