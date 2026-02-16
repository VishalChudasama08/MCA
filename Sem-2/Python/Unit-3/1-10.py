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

def uniquelist(l):
    list = []
    for i in l:
        if i in