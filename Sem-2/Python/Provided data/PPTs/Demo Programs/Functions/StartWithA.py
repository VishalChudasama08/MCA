

def readData():
    print("enter name separated by comma: ")
    allName = [ name for name in input().split(',')]
    return allName
def startWith(srcLst,start):
    startWithSome = [name for name in srcLst if name[0] in start]
    return startWithSome

allName = readData()
start = input("Enter first charcter for starting search: ").upper()
end = input("Enter first charcter for ending search: ").upper()
if ord(start) > ord(end):
    end,start = start,end
searchChar=[]
for asc in range(ord(start),ord(end)+1):
    searchChar.append(chr(asc))
    searchChar.append(chr(asc+32))
print(searchChar)
searchAns = startWith(allName,searchChar)

print("Searching output: ")
print(searchAns)

