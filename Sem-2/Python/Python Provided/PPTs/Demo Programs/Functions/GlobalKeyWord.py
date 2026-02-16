a = 5
def function():
    a = 10
    print("Inside function: " , a)

def functionGlobal():
    #a = 18 # This statement not possible due to a declare as global variable
    #global a
    a = 15
    print("Inside function using gloabal keyword: " ,a)
def functionGlobalS():
    a = 18
    globalA = globals()['a']
    print("Global A: ", globalA)
    print("Local A: ",a)
    #globalA = 11
    globals()['a'] = 11
def funCheck():
    print(b)

b = 7
funCheck()
functionGlobal()
function()
print("Out side function: ",a)

print("Outside function(after using global keyword): ",a)

functionGlobalS()
print("Outside function(after using globalS function): ",a)
