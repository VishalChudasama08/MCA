def gen(no):
    loop =1
    while(loop <= no):
        if(loop %2 == 0):
            yield loop
        loop+=1

no = int(input("Enter no : "))
genr = gen(no)
for each in genr:
    print(each)
lst = list(genr)
