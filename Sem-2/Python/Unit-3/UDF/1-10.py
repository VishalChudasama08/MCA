# Unit-3 PYTHON INDICATIVE LIST.docx

"""
1.	Take user input and create a menu driven program to perform mathematical operations like addition, subtraction, multiplication, division, integer division, power. Return values from the functions
2.	Create functions to calculate 
    a.	Area of a rectangle = width * length
    b.	Area of a triangle = ½ * Height * Base
    c.	Area of a circle = pi*r*r
3.	Create functions to convert decimal numbers to binary, octal and hexadecimal numbers. Always return values from the functions
4.	Write an UDF to return a list having only unique values by removing duplicate values from the provided input list.
Eg. Sample List : [1,2,3,3,3,3,4,5]
Unique List : [1, 2, 3, 4, 5]
5.	Write a Python function to multiply all the numbers in a list.
6.	Write a UDF to check the inputted number is between specified range or not. 
7.	Write a function to calculate total number of Uppercase and lowercase characters in the string.
8.	Write an UDF to check if the user given number is a prime number or not.
9.	Write a findString() function to find all the positions of occurrences of string2 in string1 and return that value. If string2 is not present in string1 then display suitable message.
Eg. Str1 = Hello all, Good Morning to all. (pass it as a parameter in the function)
       Str2 = ‘all’ (pass it as a parameter, but if not passed take a default argument)
O/p: String 2 found at positions: [6, 27]
10.	Create a list of fruits and using different functions perform the following operations: Show the use of globals() and don’t return from the functions
a.	Add a fruit at the last
b.	Insert a fruit at a particular position (pass it as an argument. If the position is not passed then take default argument as 1)
c.	Update the fruit (use keyword arguments)
d.	Remove a fruit from the list (pass an index position/ pass a name of the fruit as an argument)
e.	Arrange the fruits in an order

"""

# 1.	Take user input and create a menu driven program to perform mathematical operations like addition, subtraction, multiplication, division, integer division, power. Return values from the functions
"""
def menu():
    print("1. addition")
    print("2. subtraction")
    print("3. multiplication")
    print("4. division")
    print("5. integer division")
    print("6. power")
    x = int(input("Enter: "))
    return x

def add(a, b):
    return (a+b)

def sub(a, b):
    return (a-b)

def mul(a, b):
    return (a*b)

def div(a, b):
    return (a/b)

def divint(a, b):
    return int(a/b)

def power(a, b):
    return (a*a, b*b)

while True:
    x = menu()
    if x == 0:
        print("Exit...")
        break
    
    a=int(input("Enter first value:"))
    b=int(input("Enter first value:"))
    if x==1:
        print("\naddition:", add(a,b), "\n")
    elif x == 2:
        print("\nsubtraction:", sub(a,b), "\n")
    elif x == 3:
        print("\nmultiplication:", mul(a,b), "\n")
    elif x == 4:
        print("\ndivision:", div(a,b), "\n")
    elif x == 5:
        print("\ninteger division:", divint(a,b), "\n")
    elif x == 6:
        print("\npower: ")
        ans = power(a,b)
        print("a:", ans[0])
        print("b:", ans[1], "\n")
"""       
        
"""
2.	Create functions to calculate 
    a.	Area of a rectangle = width * length
    b.	Area of a triangle = ½ * Height * Base
    c.	Area of a circle = pi*r*r
"""
"""
def rectangle(width, length):
    return length*width

def triangle(Height, Base):
    return (Height*Base*0.5)

def circle(r):
    return (r*r*3.14)

print("rectangle:",rectangle(12, 13))
print("triangle:",triangle(12, 13))
print("circle:",circle(12))
"""

# 3.	Create functions to convert decimal numbers to binary, octal and hexadecimal numbers. Always return values from the functions
"""
def dtob(decimal):
    return bin(decimal)

def otoh(octal):
    return hex(octal)

print("decimal to binary:", dtob(10))
print("octal to hexadecimal:", otoh(0o10))
"""

"""
4.	Write an UDF to return a list having only unique values by removing duplicate values from the provided input list.
Eg. Sample List : [1,2,3,3,3,3,4,5]
Unique List : [1, 2, 3, 4, 5]
"""
"""
def uniquelist(l):
    ans = []
    for i in set(l):
        ans.append(i)
    return ans
    
listnum = [1,2,3,3,3,3,4,5]
print("List:", listnum)
print("After removing duplicate:",uniquelist(listnum))
"""

# 5.	Write a Python function to multiply all the numbers in a list.
"""
def multiplylist(l):
    ans = 1
    for i in l:
        ans = ans * i
    return ans

listnum = [1,2,3,3,3,3,4,5]
print("multiply answer:", multiplylist(listnum))
"""

# 6.	Write a UDF to check the inputted number is between specified range or not.  
"""
def checkrange(start,end,n):
    if n>start and n<end:
        return True
    else:
        return False
    
num = int(input("Enter number:"))
if checkrange(10, 50, num):
    print("Yes, Number is in range")
else:
    print("No, Number is not in range")
"""

# 7.	Write a function to calculate total number of Uppercase and lowercase characters in the string.
"""
def checkcase(s):
    uc = 0;
    lc = 0;
    for i in s:
        if i.isalpha():
            if i.islower():
                lc = lc+1
            else:
                uc = uc+1
    return uc,lc
 
upper, lower = checkcase("Vishal B Chudasama")

print("Total upper case:", upper)
print("Total lower case:", lower)
"""

# 8.	Write an UDF to check if the user given number is a prime number or not.
"""
def isprime(n):
    ans = True
    for i in range(2, int(n/2)):
        if n%2 == 0:
            ans = False
            break
    return ans

num = int(input("Enter number:"))
if isprime(num):
    print("Number is prime")
else:
    print("Number is not prime")
"""

"""
9.	Write a findString() function to find all the positions of occurrences of string2 in string1 and return that value. If string2 is not present in string1 then display suitable message.
Eg. Str1 = Hello all, Good Morning to all. (pass it as a parameter in the function)
       Str2 = ‘all’ (pass it as a parameter, but if not passed take a default argument)
O/p: String 2 found at positions: [6, 27]
"""
"""
def findString(s1, s2):
    if s2 not in s1:
        return False, "String 2 is not part of String 1"
    else:
        l = []
        i = 0
        while True:
            a = s1.find(s2, i)
            if(a==-1):
                break
            else:
                l.append(a)
                i = a+len(s2)
        return True, l
        
str1 = "Hello all, Good Morning to all."
str2 = "all"

ans, result = findString(str1, str2)

if ans:
    print("all positions of occurrences:", result)
else:
    print(result)
"""



"""
10.	Create a list of fruits and using different functions perform the following operations: Show the use of globals() and don’t return from the functions
    a.	Add a fruit at the last
    b.	Insert a fruit at a particular position (pass it as an argument. If the position is not passed then take default argument as 1)
    c.	Update the fruit (use keyword arguments)
    d.	Remove a fruit from the list (pass an index position/ pass a name of the fruit as an argument)
    e.	Arrange the fruits in an order
"""
fruits = []

def createfruitslist():
    n = int(input("Enter number How many fruits:"))
    for i in range(n):
        f = input("Enter fruit name:")
        fruits.append(f)

createfruitslist()
print(fruits)

# a.	Add a fruit at the last
def add():
    fruits.append(input("Enter fruit name to add on list:"))
    
add()
print(fruits)

# b.	Insert a fruit at a particular position (pass it as an argument. If the position is not passed then take default argument as 1)
def addAtPosition(f, pos=1):
    fruits.insert(pos, f)
          
p = int(input("Enter index:"))
f = input("Enter fruit name to add on perticular index:")
addAtPosition(f, p)
print(fruits)
   
fruits = ["banana", "mango", "kiwi", "orange"] 
# c.	Update the fruit (use keyword arguments)
def update(**args):
    for i,j in args.items():
        if i in fruits:
            index=fruits.index(i)
            fruits[index]=j

update(kiwi="blue kiwi", mango="green mango")
print(fruits)


# d.	Remove a fruit from the list (pass an index position/ pass a name of the fruit as an argument)
def remove(name):
    fruits.remove(name)
    
remove(input("Enter fruits name to delete it:"))
print(fruits)

# e.	Arrange the fruits in an order
def arrange():
    newlist = sorted(fruits)
    return newlist

print(arrange())