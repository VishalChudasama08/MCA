# Decorate function
##A decorator is a function that accepts a function as parameter
##and returns a function. A decorator takes the result of a function,
##modifies the result and returns it.

## 1.We should define a decorator function with another function name
##as parameter. As an example, let’s define a decorator function decor()
##with ‘fun’as parameter.

##2.We should define a function inside the decorator function.
##This function actually modifies or decorates the value of the
##function passed to the decorator function.

##3.Return the inner function that has processed or decorated the value.
# In following example decorate function is not used 
def decorNot(fun):
    def inner():
        num = int(input("Enter value: "))
        value = fun(num)
        return value + 2
    return inner
def getNum(value):
    return value
resultDec = decorNot(getNum)
print(type(resultDec))
value = resultDec()
print(value)

# In following example decorate function is used
def decorNum(fun):
    def inner():
        num = int(input("Enter value (for decorate): "))
        value = fun(num)
        return value * 2
    return inner
@decorNum #here using @ symbol we used decorate function
def getDecor(value):
    return value
value1 = getDecor( )
print(value1)
