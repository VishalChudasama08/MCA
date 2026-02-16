# Unit-2 PYTHON INDICATIVE LIST.docx

# remove element form list by value => list.remove(value)
# by index => del li[index]
# insert in any position => list.insert(index,value)
# marge lists => list1.extend(list2)
# count all occurence => list.count(value)
# delete last element => list.pop()
# sorting element => list.sort(), for reverse sorting => list.sort(reverse=True)
# make reverse list => list.reverse()
# clear all element => list.clear()
# find max,min,lenght => max(list), min(list), len(list)


# 39.	Create a list of students say L1
l1 = eval(input("Enter student list, in list format: "))
print(l1)
"""
# a.	Count total number of students from the list L1
print("Total number of student in list is:", len(l1))

# b.	Add one more student in the list L1
s1 = input("Enter student name: ")
l1.append(s1)
print(l1)
"""

# c.	Display all the students in the sorted order
"""
print(sorted(l1))
"""

# d.	Check a particular student’s name is present in the list or not
# e.	If the student’s name is present in the list, print total number of same name students in the list L1 and display the position of 1st student
"""
s2 = input("Enter student name: ")
flag = False
pos = ()
count = 0

for i in l1:
    if i == s2 :
        flag = True
        count = count + 1 
        pos = pos + (l1.index(i),)
    
if flag == True:
    print("This student is present in list")
    print("Total count of this student:", count)
    print("1st student name position:", pos[0])
else :
    print("This student is not present in list")

# f.	Remove the last student from the list L1
print("Last deleted element is:", l1.pop())
print("List is:", l1)
"""
# g.	Remove a particular student from the list. (Take a name of student from the user.)
"""
s3 = input("Enter student name for remove from list:")
flag=False
for i in l1:
    if i==s3:
        flag=True
        l1.remove(i)
        break

if flag == True:
    print(s3,"removed")
    print("Now list is:", l1)
else:
    print(s3,"not present in list")
 """
   
# h.	While removing the student from the list, if multiple students have same name then remove all of them from the list.
s4 = input("Enter student name for that all remove from list:")
flag = False

for i in l1:
    if i==s4:
        flag=True
        l1.remove(i)

if flag == True:
    print(s4,"removed")
    print("Now list is:", l1)
else:
    print(s4,"not present in list")
