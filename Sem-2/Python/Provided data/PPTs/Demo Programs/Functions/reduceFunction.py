#reduce function
##The reduce() function reduces a sequence of
##elements to a
##single value by processing the elements
##according to a function supplied.
from functools import *

def funMul(lst):
    mul = 1
    for eachnum in lst:
        mul*=eachnum
    return mul
def funMul1(x,y):
    print( "x = ", x,"y = ",y)
    return x * y
def maxV(x,y):
    if x > y:
        return x
    else:
        return y

lst = [1,2,13,4,11]
#result = reduce(maxV,lst)
result = reduce(lambda x,y:x if x > y else y,lst)
print(result)
result = reduce(lambda x,y:x * y,lst)
#reduce function is used
print(result)
##result = funMul(lst)
##print(result)
result = reduce(funMul1,lst)
print(result)

