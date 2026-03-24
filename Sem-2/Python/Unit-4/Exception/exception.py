# PYTHON INDICATIVE LIST.docx Unit-4
"""
1.	Write a Python script to take a user input to enter a list of elements for employee data and write it into a file. Handle the following exceptions for it.
    a.	If an age entered is not a number
    b.	If salary is not defined and trying to append in the list
    c.	Entered age must be between 18 and 25 only
    d.	Salary must be greater than or equal to 10000
    e.	Calculate HRA and check for the ZeroDivisionError
    f.	Open a file in read mode and try to write into it
    g.	Try to write the whole list object into a file

    NOTE: 
    •	TypeError: This exception is raised when an operation or function is applied to an object of the wrong type, such as adding a string to an integer.
    •	NameError: This exception is raised when a variable or function name is not found in the current scope.
    •	IndexError: This exception is raised when an index is out of range for a list, tuple, or other sequence types.
    •	KeyError: This exception is raised when a key is not found in a dictionary.
    •	ValueError: This exception is raised when a function or method is called with an invalid argument or input, such as trying to convert a string to an integer when the string does not represent a valid integer.
    •	AttributeError: This exception is raised when an attribute or method is not found on an object, such as trying to access a non-existent attribute of a class instance.
    •	IOError: This exception is raised when an I/O operation, such as reading or writing a file, fails due to an input/output error.
    •	ZeroDivisionError: This exception is raised when an attempt is made to divide a number by zero.
    •	ImportError: This exception is raised when an import statement fails to find or load a module.
    
2.	Create a dictionary object for student details (Rollno, name, age, hobby, marks…)
3.	Create a user defined exception if entered marks are > 50
4.	Store all those dictionary data in a binary file.
5.	Create separate functions for addData, updateData, deleteData from the binary file

"""



class AgeError(Exception):
    def __init__(self, arg):
        self.msg=arg
        
class SalaryError(Exception):
    def __init__(self, arg):
        self.msg=arg



l = []
name = input("Enter name:")
l.append(name)


try:
    age = int(input("Enter age:"))
    if age<18 or age>25:
        raise AgeError("Age between 18 to 25")
    else:
        l.append(age)
        
    salary = int(input("Enter salary:"))
    if salary>=10000:
        l.append(salary)
    else:
        raise SalaryError("Salary must be greater than or equal to 10000")
    
    n = int(input("Enter number for Calculate HRA:"))
    hra = (8*100)/n
    l.append(hra)
    
    f = open("emp.txt", "r")
    f.write(str(l))
    f.close()
    
except Exception as obj:
    print(obj)
    
print(l)

    




# 2.    Create a dictionary object for student details (Rollno, name, age, hobby, marks…)
# 3.    Create a user defined exception if entered marks are > 50
# 4.	Store all those dictionary data in a binary file.
# 5.	Create separate functions for addData, updateData, deleteData from the binary file


class MarksError(Exception):
    def __init__(self, args):
        self.msg = args
        
def addData():
    d1 = {}
    d1["Rollno"] = int(input("Enter Rollno:"))
    d1["name"] = input("Enter name:")
    d1["age"] = int(input("Enter age:"))
    h = input("Enter hobby:")
    d1["hobby"] = h.split(", ")
    d1["marks"] = int(input("Enter marks:"))
    
    f1 = open("data.txt", "a")
    f1.write("\n" + str(d1))
    f1.close()
    
d = {}

try:
    d["Rollno"] = int(input("Enter Rollno:"))
    d["name"] = input("Enter name:")
    d["age"] = int(input("Enter age:"))
    h = input("Enter hobby:")
    d["hobby"] = h.split(", ")
    d["marks"] = int(input("Enter marks:"))
    
    if d["marks"]<50:
        raise MarksError("not valid mark. marks more thaen 50")
        
    f1 = open("data.txt", "w")
    f1.write(str(d))
    f1.close()
    
    addData();
    
        
except Exception as obj:
    print(obj)

print(d)



