# Unit-3 PYTHON INDICATIVE LIST.docx
"""
39	Create a text file with different modes like w, w+, a, a+ and write few lines in it
40	Read the content of the whole file together
41	Print the length of the file data
42	Read the file content line by line
43	Print total number of words in each line in the file
44	Print all the words in reverse.
45	Write multiple lines in a text file. Using list object
46	Take a filename from the user to read that file
47	If the file to be read is not available then print suitable message
48	After reading the file content, append the text at the end of the file.
49	Open a file and append a line at the beginning of the file content 
50	Copy the content of one file to another

"""

# 39 Create a text file with different modes like w, w+, a, a+ and write few lines in it
"""
f1 = open("D://ACWV//write_mode.txt", "w")
f1.write("Unit-3\n")
f1.close()

f2 = open("D://ACWV//write_plus_mode.txt", "w+")
f2.write("Unit-3 file in write plus mode\n")
f2.seek(0,0)
print(f2.read())
f2.close()

f3 = open("D://ACWV//append_mode.txt", "a")
f3.write("Unit-3 file write, apped mode\n")
f3.close()

f4 = open("D://ACWV//append_plus_mode.txt", "a+")
f4.write("Unit-3 file in append plus mode\n")
f4.seek(0,0)
print(f4.read())
f4.close()
"""

# 40	Read the content of the whole file together
"""
f5 = open("D://ACWV//append_mode.txt", "r")
print("append_mode.txt file content:-", f5.read())
f5.close()
"""

# 41	Print the length of the file data
"""
f6 = open("D://ACWV//write_plus_mode.txt", "r")
s = f6.read()
print("write_plus_mode.txt file data length:", len(s))
f6.close()
"""

# 42	Read the file content line by line
"""
f7 = open("D://ACWV//append_mode.txt", "r")
print("line by line content:")
sl = f7.readlines()
for s in sl:
    print(s)
f7.close()
"""

# 43	Print total number of words in each line in the file
"""
f8 = open("D://ACWV//append_mode.txt", "r")
sl = f8.readlines()
i=1
for s in sl:
    ws = s.split(" ")
    print("line",i,"total number of words:",len(ws))
    i=i+1;
f8.close()
"""

# 44	Print all the words in reverse.
"""
f9 = open("D://ACWV//append_mode.txt", "r")
sl = f9.readlines()
i=1
print("\n\nappend_mode.txt file Print all the words in reverse: ")
for s in sl:
    ws = s.split(" ")
    print("\nline",i,":",end=" ")
    for w in ws:
        for c in reversed(w): print(c,end="")
        print(" ", end="")
    i=i+1;
f9.close()
"""

# 45	Write multiple lines in a text file. Using list object
"""
f10 = open("D://ACWV//write_multiple_line.txt", "w")
l = ["Write multiple lines in a text file.\n","Using list object.\n", "Print all the words in reverse.\n"]
for i in l:
    f10.write(i)
f10.close()
"""

# 46	Take a filename from the user to read that file
"""
fn = input("Enter File name:") #first.txt
fn = "D://ACWV//"+fn
f11 = open(fn, "r")
print(f11.read())
f11.close()
"""

# 47	If the file to be read is not available then print suitable message
"""
try:
    f12 = open("D://ACWV//second.txt","r")
    print("File content:",f12.read())
    f12.close()
except Exception:
    print("File not present")
"""

# 48	After reading the file content, append the text at the end of the file.
"""
f13 = open("D://ACWV//first.txt","a")
f13.write("\tappend text at last.")
f13.close()
"""

# 49	Open a file and append a line at the beginning of the file content 
"""
f14 = open("D://ACWV//first.txt","r+")
fileContent = f14.read();
# print(fileContent)
f14.seek(0,0)
fileContent = "append text at beginning. "+fileContent
f14.write(fileContent)
f14.close()
"""

# 50	Copy the content of one file to another
"""
f15 = open("D://ACWV//first.txt","r")
f16 = open("D://ACWV//new.txt","w")
f16.write(f15.read())
f15.close()
f16.close()
"""