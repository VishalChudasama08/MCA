# Unit-3 PYTHON INDICATIVE LIST.docx
"""
54	Read alternate lines from the file.
    1.	Write a python script to read the text file content and print the output in form of line wise total words in the file. 
    File Content as below:
    Hello, How are you?
    Very good morning
    Have a nice day to all
    Good Bye…
    Output: [(1,4), (2,3), (3,6), (4,2)]
    2.	Open a text file using with statement and write and read the content from that file.
    3.	Take the user input for data to be written in the text file. Enter the data line by line, till ‘@’ character is entered by the user at the end.
    4.	Create a text file having string and numeric data. Write a script to separate the string and numbers in two different files [Hint: ch.isdigit() method will return true , if character is a number] 
    5.	Create a menu driven program to perform various file operations through python functions as:
        a)	Create a file – (define the filename as a default argument)
        b)	Read the content of a specified file – Return the content in a string
        c)	Append the content in the specified file
        d)	Rename a file – (Take filename as keyword arguments)
        e)	Delete a file - (define the filename as a default argument)
        f)	Create a directory / folder
        g)	Display all the files present in the specified folder
        h)	Display only .txt file names from the specified folder
        i)	Display the files, starting with letter ‘t’ in their filename.
        j)	Display all python files from a specified folder.(Either .py extension or filename/ folder name contains ‘py’ in between)
        k)	Display the file names having .txt extension

"""



"""
54.1.	Write a python script to read the text file content and print the output in form of line wise total words in the file. 
    File Content as below:
        Hello, How are you?
        Very good morning
        Have a nice day to all
        Good Bye…
    Output: [(1,4), (2,3), (3,6), (4,2)]
"""
"""
f1 = open("D://ACWV//54-1.txt","r")
c = f1.readlines()
l = []
k = 1
for i in c:
    w = i.split(" ")
    t = (k, len(w))
    k=k+1
    l.append(t)

print(l)
f1.close()
"""

# 54.2.	Open a text file using with statement and write and read the content from that file.
"""
with open("D://ACWV//54-2.txt","w+") as f2:
    f2.write("write and read the content from that file.")
    f2.seek(0,0)
    print(f2.read())
        
"""

# 54.3.	Take the user input for data to be written in the text file. Enter the data line by line, till ‘@’ character is entered by the user at the end.
"""
data = input("Enter data: ")
f3 = open('D://ACWV//54-3.txt', "w+")

while data != '@':
    f3.write(data+"\n")
    data = input("Enter data: ")

f3.close()
"""

# 54.4.	Create a text file having string and numeric data. Write a script to separate the string and numbers in two different files [Hint: ch.isdigit() method will return true , if character is a number] 
"""
f4=open("D://ACWV//54-4.txt", "r")
f5=open("D://ACWV//54-4-str.txt", "w")
f6=open("D://ACWV//54-4-num.txt", "w")

data=f4.read();

for d in data:    
    if d.isdigit():
        f6.write(d)
    else :
        f5.write(d)
    
f4.close()
f5.close()
f6.close()
"""

# 54.5.	Create a menu driven program to perform various file operations through python functions as:
# 54.5.a)	Create a file – (define the filename as a default argument) 
# 54.5.b)	Read the content of a specified file – Return the content in a string
# 54.5.c)	Append the content in the specified file
# 54.5.d)	Rename a file – (Take filename as keyword arguments)
# 54.5.e)	Delete a file - (define the filename as a default argument)
# 54.5.f)	Create a directory / folder
# 54.5.g)	Display all the files present in the specified folder
# 54.5.h)	Display only .txt file names from the specified folder
# 54.5.i)	Display the files, starting with letter ‘t’ in their filename.
# 54.5.j)	Display all python files from a specified folder.(Either .py extension or filename/ folder name contains ‘py’ in between)
# 54.5.k)	Display the file names having .txt extension

while True:
    #x = menu()
    
    match menu():
        case 1 : print("String length is" , len(text));
        case 2 : print("String upper case", text.upper());
        
def menu():
    print("0. exit")
    print("1. Create a file")
    print("2. Read the content of a specified file")
    x = int(input("Ener you choise:"))
    return x