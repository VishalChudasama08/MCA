# Unit-3 PYTHON INDICATIVE LIST.docx
"""
51	Read 10th to 15th byte from the file and print.
52	Read an existing file and take a user input string to be appended in that file. Also ask the position where new line need to be appended. Update the file content and print the updated file. [Hint: Make a file with new line character after each line]
53	Read an alternate bytes/ character from the file.

"""

# 51	Read 10th to 15th byte from the file and print.
"""
f1 = open("D://ACWV//first.txt","r")
f1.seek(10)
# print(f1.tell())
print(f1.read(5))
f1.close()
"""

# 52	Read an existing file and take a user input string to be appended in that file. Also ask the position where new line need to be appended. Update the file content and print the updated file. [Hint: Make a file with new line character after each line]
"""
f2 = open("D://ACWV//second.txt","r+")
userstr = input("Enter string:")
userstr = userstr+"\n"
pos = int(input("Enter line position where new line add:"))
l = f2.readlines()
l.insert(pos, userstr)
# print(f2.tell(), l)
f2.seek(0,0)
f2.writelines(l)
f2.seek(0,0)
print(f2.read())
f2.close()
"""

# 53	Read an alternate bytes/ character from the file.

f3 = open("D://ACWV//first.txt","r")
c = f3.read()
for i in range(0, len(c), 2):
    print(c[i], end=' ')
f3.close()