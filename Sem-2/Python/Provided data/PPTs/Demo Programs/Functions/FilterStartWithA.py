def startWithA(value):
    if(value[0] == "a" or value[0] == "A"):
        return True
    else:
        return False

lst = ["Krunal","Krishna","krimesh","arti","Arti"]
listA = list(filter(startWithA,lst))
print(listA)
