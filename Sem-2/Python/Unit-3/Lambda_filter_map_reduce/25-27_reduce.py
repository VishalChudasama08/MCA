# Unit-3 PYTHON INDICATIVE LIST.docx

from functools import reduce

# 25	Add all the elements of the list (using reduce())
l = [1,2,4,12,8,9]

add = reduce(lambda x,y:x+y, l, 0)
print("add:",add)

# 26	Multiply all the elements of the list (using reduce())

mul = reduce(lambda x,y:x*y, l, 1)
print("Multiply:",mul)

# 27	Find the maximum element from the list using reduce()

findmax = reduce(lambda x,y:x if x>y else y, l)
print(findmax)
