#Unit-4
"""
Python database connectivity exercise.docx
"""

"""
----- Student Management System -----
1. Add Student
2. View All Students
3. Search Student by Roll No
4. Update Student Details
5. Delete Student
6. Display Topper
7. Count Total Students
8. Exit
Enter your choice:

"""


import mysql.connector

conn = mysql.connector.connect(host="localhost", port=3309, user="root", password="", database="python_db")

c = conn.cursor()

# create Table
# c.execute("CREATE TABLE python_db.student (roll_no INT(5) NOT NULL PRIMARY KEY, name VARCHAR(100) NOT NULL , marks FLOAT(5) NOT NULL , grade VARCHAR(10) NOT NULL)")


# add data in txt file
def addDataInFile():
    f = open("StudentManagementSystemData.txt", "w")
    c.execute("SELECT * FROM student")
    rows = c.fetchall()
    if len(rows) != 0:
        f.write("----- Student Management System -----\n\nNo\tName\tmark\tgrade\n")
        for row in rows:
            f.write(str(row[0])+'\t'+str(row[1])+'\t'+str(row[2])+'\t'+str(row[3])+"\n")
    f.close()

addDataInFile();


def addStudent():
    no = int(input("Entet Student Roll no:"))
    name = input("Enter Student name: ")
    mark = int(input("Enter student mark: "))
    # A (≥75), B (60–74), C (50–59), F (<50) 
    if mark>=75 :
        grade='A'
    elif mark<75 and mark>=60:
        grade='B'
    elif mark<59 and mark>=50:
        grade='C'
    else:
        grade='F'  
    data = (no,name,mark,grade)
    # insert data
    try :
        c.execute("INSERT INTO student values(%s, %s, %s, %s)", data)
        conn.commit()
        print("Student added successfully\n")
        addDataInFile()
    except mysql.connector.errors.IntegrityError:
        print("Duplicate entry! student with roll no",n,"is alredy exist\n")
    
def displayStudent():
    c.execute("SELECT * FROM student")
    rows = c.fetchall()
    if len(rows) != 0:
        print("\nNo\tName\tmark\tgrade")
        for row in rows:
            print(str(row[0])+'\t'+str(row[1])+'\t'+str(row[2])+'\t'+str(row[3]))
        conn.commit()
        print("\n")
    else:
        print("Table is empty!")
    
def updateStdDetails():
    n=int(input("Enter student roll no: "))
    c.execute("SELECT * FROM student WHERE roll_no=%s", (n,))
    row = c.fetchall()
    if len(row) != 0:
        no = int(input("Enter Student updated Roll no:"))
        name = input("Enter Student updated name: ")
        mark = int(input("Enter student updated mark: "))
        # A (≥75), B (60–74), C (50–59), F (<50) 
        if mark>=75 :
            grade='A'
        elif mark<75 and mark>=60:
            grade='B'
        elif mark<59 and mark>=50:
            grade='C'
        else:
            grade='F'
        data = (no,name,mark,grade,n)
        c.execute("UPDATE student SET roll_no=%s, name=%s, marks=%s, grade=%s WHERE roll_no=%s", data)
        conn.commit()
        print("Student details updated successfully\n")
        addDataInFile()
    else :
        print("No any Student existed with roll no",n,"\n")
    
def searchStudent():
    n=int(input("Enter student roll no: "))
    c.execute("SELECT * FROM student WHERE roll_no=%s", (n,))
    rows = c.fetchall()
    if len(rows) != 0:
        print("Here roll no",n,"Student details:-")
        print("\n\tNo\tName\tmark\tgrade")
        for row in rows:
            print('\t'+str(row[0])+'\t'+str(row[1])+'\t'+str(row[2])+'\t'+str(row[3]))
        print("\n")
    else :
        print("No any Student existed with roll no",n,"\n")
    
def deleteStudent():
    n=int(input("Enter student roll no: "))
    c.execute("SELECT * FROM student WHERE roll_no=%s", (n,))
    rows = c.fetchall()
    if len(rows) != 0:
        c.execute("DELETE FROM student WHERE roll_no=%s", (n,))
        conn.commit()
        print("Student Deleted successfully\n")
        addDataInFile()
    else :
        print("No any Student existed with roll no",n,"\n")
        
       
def displayTopper():
    c.execute("SELECT * FROM student")
    rows = c.fetchall()
    if len(rows) != 0:
        mark=0
        name=""
        for row in rows:
            if row[2]>mark:
                mark=row[2]
                name=row[1]
        print("Topper is",name,"with mark:",mark,"\n")
    else:
        print("Table is empty!")
    
def countStudent():
    c.execute("SELECT * FROM student")
    rows = c.fetchall()
    count = len(rows)
    print("Count:",count)
    
while True:
    print('----- Student Management System -----')
    print("1. Add Student")
    print("2. View All Students")
    print("3. Search Student by Roll No")
    print("4. Update Student Details")
    print("5. Delete Student")
    print("6. Display Topper")
    print("7. Count Total Students")
    print("8. Exit")
    n = int(input("Enter your choice: "))
    if n==1: addStudent()
    elif n==2: displayStudent()
    elif n==3: searchStudent()
    elif n==4: updateStdDetails() 
    elif n==5: deleteStudent()
    elif n==6: displayTopper()
    elif n==7: countStudent()
    elif n==8: break
    else : print("Enter value number!")



conn.commit()
conn.close()
