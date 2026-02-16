def functionAsArgu(L,f):
    for loop in range(len(L)):
        L[loop] = f(L[loop])

def sumNum(num):
    sum = 0
    for loop in range(1,num+1):
        sum = sum + loop
    return sum
L = [1,-2,3.33]
print("L = ", L)
functionAsArgu(L,abs)
print(" After abs ",L)
functionAsArgu(L,int)
print(" After converting in integer ",L)
functionAsArgu(L,sumNum)
print(" Sum of Each Number ",L)
def message():
    return "How are you ?"
def display(fun):
    return "Hello : " + fun
def display1(name):
    def message():
        return "I am Fine "
    value = message() + name
    return value
msg = display(message())
print(msg)
msg = display1("Urja")
print(msg)
