mul = lambda x,y: x*y
maxV = lambda x,y:x if x > y else y
num = lambda allList: [n for n in allList if type(n)==int or type(n) == float]
string =lambda allList:[value for value in allList if type(value) == str]
no1 = int(input("Enter no1: "))
no2 = int(input("Enter no2: "))
ans = mul(no1,no2)
print("Multiplication: ",ans)
print("Maximum : ", maxV(no1,no2))
allList = [1,4,7,"Niki",3.4,"Kiran","Komal"]
numList = num(allList)
print(numList)
allString = string(allList)
print(allString)
