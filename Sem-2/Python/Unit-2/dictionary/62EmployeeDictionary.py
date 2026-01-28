# unit-2 PYTHON INDICATIVE LIST.docx

# 62.	Create a dictionary of employees where empId will be the key and value will be the name of an employee

emp = {"e1":"Amit", "e2":"Neha", "e3":"Riya", "e4":"Karan"}
print(emp)

# 1.	Display how many employees are there in the dictionary.
print("total emp:",len(emp))

# 2.	Display all empID and add them in a separate list.
empkeylist = list(emp.keys())
print(empkeylist)

# 3.	Display all employee names and take them to a separate list
empNameList = list(emp.values())
print(empNameList)

# 4.	Take an empId from the user and check if that employee is there in the dictionary or not.
# 5.	If an empID is there in the dictionary then display the name of that employee or if not available then add an ID and Name of the employee in the dictionary
key = input("Entr employee id for find: ")
flag=False

for i in emp:
    if i == key:
        flag=True
        break
if flag==True:
    print("yes, Employee Id is there, and employee name is",emp[key])
else:
    print("no, Employee is not present in dictionary")
    name = input("Entr employee name to add on dictionary: ")
    emp[key]=name
    print("new employee added in dictionary",emp)
    

# 6.	Change the name of the employee of empID taken by the user
key = input("Entr employee id for change it's name: ")
name = input("Entr new name of employee: ")
emp[key]=name

print("updated dictionary:",emp)

# 7.	Remove an employee whose ID is provided by the user
key = input("Entr employee id for remove from dictionary: ")
del emp[key]

print("after remove:", emp)