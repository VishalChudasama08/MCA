"""either pass by value or in pass by reference object reference is passed whose memory stored in heap
but when we passed integer
or string or float or tuple object as parameter than copy of object is created due to immutable.
when we passed list or dictionaries as paramater than object is passed as reference due to mutable."""

def PassByValueNormal(value):
    value = 15
    print(id(value)," : Inside function(we change value,integer): ",value)
def PassByValueTuple(tup):
    tup = (7)
    print(id(tup),": Inside function(we change value,tuple): ",tup)
def PassByRef(l):
    l[0] = [6,7]
    print(id(l),": Inside function(we change value,list): ",l)

value = 10
print(id(value)," : Before function called(integer): ",value)
PassByValueNormal(value)
print(id(value)," : After function called(integer): ",value)
tup1 = (1)
print(id(tup1)," :Before function called(tuple): ",tup1)
PassByValueTuple(tup1)
print(id(tup1),": After function called(tuple): ",tup1)
lst = [1,3,5]
print(id(lst)," :Before function called(List): ",lst)
PassByRef(lst)
print(id(lst)," :After function called(List): ",lst)
