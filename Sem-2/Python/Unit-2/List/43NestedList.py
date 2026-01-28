# unit-2 PYTHON INDICATIVE LIST.docx
# 43.	Create a list of employees (nested list) with their personal details like [name, age, salary, expertise] in a list. Ask the user to enter name and display the details of that employee. If the employee is not in the list, print error message.

emp = [["vishal", 20, 80000, "C"], ["dipak", 19, 90000, "Java"], ["bhavesh", 20, 85000, "Python"], ["nitin", 21, 75000, "DBMS"]]


name = input("Enter Employee name: ")
flag=False
j=0
for i in emp:
    if i[0] == name:
        flag=True
        j=emp.index(i)
        break
    
if flag==True:
    print("Employee name: ", emp[j][0], ", age: ", emp[j][1], ", salary: ", emp[j][2], ", expertise: ", emp[j][3], sep="")
else :
    print("Employee not found in list")