# Unit-2 PYTHON INDICATIVE LIST.docx
# 28.	Create a tuple for name say t1 (FirstName, MiddleName, LastName)

t1 = ("First", "second", "third")

# 29.	Create a tuple say t2 for marks of 5 subjects 

t2 = (50, 60, 70, 80, 90)

# 30.	Make a total of all the marks and print it. (with and without using sum() method)

print(sum(t2))

# 31.	Make a tuple t3 having 2 elements as t1 and t2 (tuples created above) – It is called a nested tuple

t3 = (t1, t2)
print(t3)

     
# 32.	Take an input number and find whether that is present as an element in the tuple t3 or not.

u = eval(input("Enter number: "))
flag=False

for i in t3:
    if isinstance(i, tuple):
        for j in i:
            if (j==u) :
                flag=True
                break
    else:
        if (i==u) :
            flag=True
            break

if flag:
    print("Present")
else:
    print("Not Present")