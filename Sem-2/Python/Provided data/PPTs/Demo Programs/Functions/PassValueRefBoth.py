def PassBoth(tupList):
    tupList = (1,2,3)
    print(id(tupList),"type : ",type(tupList))
    for item in tupList:
        print(item)
l = [1,2,4]
tup = (6,7,8)
print(id(tup),"type : ",type(tup))
PassBoth(tup)
print(id(l),"type : ",type(l))
PassBoth(l)
