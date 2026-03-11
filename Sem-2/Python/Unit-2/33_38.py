# Unit-2 PYTHON INDICATIVE LIST.docx
# 33.	Create a tuple of 5 fruits. Ask the user to input a fruit name and search that name in the given fruit tuple. Display suitable messages

tf = ('apple', 'banana', 'orange', 'mango', 'cherry')

fruit = input("Enter Fruit name:")

if fruit in tf:
    print("Present")
else:
    print("Not Present")

# 34.	Create a tuple of cities of Gujarat by taking user input.
cities = input("Enter gujarat cities name separate by comma: ")

lst = cities.split(",")
t5 = tuple(lst)
print(t5)

# 35.	Find the length of name of each city in the above tuple. With and without len() method
print("With len => ")
for i in t5:
    c = i.strip()
    print("\t", c, "=", len(c))

print("Without len => ")
for i in t5:
    c = i.strip()
    count = 0
    for j in c:
        count += 1
    print("\t", c, "= ", count)
"""
# 36.	Create a nested tuple t4 of your (name, (hobbies), (friends), degree)

name = input("Enter name: ")
hob = input("Enter Hobbies: ")
fri = input("Enter Friends name: ")
deg = input("Enter degree: ")

t4 = (name, tuple(hob.split(", ")), tuple(fri.split(", ")), deg)
print(t4)

# 37.	Find an element in the nested tuple (t4) and print its position if found, otherwise print “Not found”

x = input("Enter: ")
flag = 0

for i in range(len(t4)):
    if isinstance(t4[i], tuple):
        for j in range(len(t4[i])):
            if t4[i][j] == x:
                p = (i, j)
                flag = 1
                break
    else:
        if t4[i] == x:
            p = (i)
            flag = 1
            break

if flag == 1:
    if len(p) == 2:
        print("Position of ", x, " is: t4[", p[0], "][", p[1], "]", sep="")
    else:
        print("Position of ", x, " is: t4[", p[0], "]", sep="")
else:
    print("Not found")

# 38.	Take a tuple of 10 integer numbers and segregate odd and even numbers in 2 different tuples.

t5 = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

tEven = ()
tOdd = ()

for i in t5:
    if i % 2 == 0:
        tEven = tEven + (i,)
    else:
        tOdd = tOdd + (i,)

print("Even number tuple:", tEven)
print("Odd number tuple:", tOdd)
"""
