# calling two function using decorate
num = 0
def decor1(fun):
    def inner():
        value = fun()
        return value + 2
    return inner
def decor2(fun):
    def inner():
        value = fun()
        return value * 2
    return inner
@decor2
@decor1
#decor1 is called first then decor2
def callNum():
    value = int(input("Enter value: "))
    return value

value = callNum()
print(value)
