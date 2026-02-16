def add(farg,*args):
    sum = 0
    for i in args:
        sum += i
    print("Sum = ",(farg + sum))
def addAll(*args):
    sum = 0
    print(type(args))
    for i in args:
        sum += i
    print("Sum = ",sum)
def function1(no1,no2):
    print("no1 = ",no1 ,
          "no2 =", no2)
function1(no2 = 3,no1=4)
add(1,2)
add(1,2,3)
addAll()
