# 60.	Given the sets
class_A = {"Amit", "Neha"}
class_B = {"Amit", "Neha", "Riya", "Karan"}
# write a program to check whether Class A is a subset of Class B.

flag=True

for i in class_A:
    if i not in class_B:
        flag=False        

if flag == True:
    print("yes, Class A is a subset of Class B.")
else :
    print("no, Class A is not a subset of Class B.")