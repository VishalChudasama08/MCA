# use generator function
##Generators are functions that return a sequence of values.
##A generator function is written like an ordinary function
##but it uses ‘yield’ statement. This statement is useful to
##return the value.
def printGen(g):
    value = next(g)
    try:
        while (True):
            print(value)
            value = next(g)
    except StopIteration:
        pass

def mygen(x,y):
    while(x <=y):
        yield x
        x+=1
def evenGen(no):
    loop =1
    while(loop<no):
        if(loop%2==0):
            yield loop
        loop+=1
g = mygen(4,9)
printGen(g)
gEven = evenGen(5)
printGen(gEven)
#for no in g:
#    print(no,end=" ")


