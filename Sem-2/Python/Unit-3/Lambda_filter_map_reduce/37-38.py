# Unit-3 PYTHON INDICATIVE LIST.docx

"""
37  Create a menu driven program with user defined functions to insert update delete  elements in the dictionary object of employees
Emp = {empCode:[name, age, salary, (expert areas)],…..}
"""
emp = {10:['vishal', 23, 80000]}

def menu() :
    print("1. insert\n2. delete\n3. update")
    return int(input("Enter: "))

def insert():
    key = int(input("Enter key: "))
    emp[key] = [input("Enter name: "), input("Enter age: "), input("Enter salary: ")]

def delete():
    i = int(input("Enter key for delete: "))
    del emp[i]
    
def update():
    i = int(input("Enter key for update: "))
    emp[i] = [input("Enter name: "), input("Enter age: "), input("Enter salary: ")]

for j in range(3):
    print(emp)
    n = menu()
    
    if n == 1:
        insert()
        print(emp)
    elif n == 2:
        delete()
        print(emp)
    elif n==3:
        update()
        print(emp)
    
"""
38  Write a python script to generate result for a particular student.
    1.	Create a student data in a dictionary object as shown below:
        stud = {1: {"name":'Amit', "age":23,"marks": [(10,15,12), (11,12,13)]},               
                2: {"name":'Bhumi',"age":22,"marks": [(13,15,11), (10,10,13)]},             
                3: {"name":'Bharat',"age":23,"marks": [(12,12,14), (13,14,15)]}
        }
        NOTE: Here students are getting marks of 3 subjects in 2 attempts of test in a form of tuple
        
    2.	Create separate user defined functions to (Create a menu for options)
        a. Take user input for creating entry of any new student (addStud())
        b. Print all marks of a specific student. (Result(name))
        c. Display overall result of all students in a given format

"""