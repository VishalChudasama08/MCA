def isEven(num):
    if(num %2 == 0):return True
    else:return False
def isPos(num):
    if(num > 0):return True
    else:return False

##lst=[1,2,6,-99,-33,14]
##lstEven = list(filter(isEven,lst))
###lstEven = filter(lambda no : (no%2 == 0),lst)
##print("All Num ",lst)
##print(type(lstEven))
##print(lstEven)
##for no in lstEven:
##    print(no)
###print("Even numbers",lstEven)
##
##lstPos = list(filter(isPos,lst))
##print(lstPos)
allupper =list( filter(lambda ch : True if ch.isupper() else False,"NikI"))
print(allupper)
