# Unit-2
# 26.	Copy the inputted string to another string by replacing the character ‘o’ with ‘@’ Eg. ‘Hello’ will be copied to another string as ‘Hell@’ and ‘Good Morning’ will become ‘G@@d M@rning’ (Without using replace())

a=input("Enter String: ")
b=""
for i in a:
    if i=='o' :
        b += '@'
    else:
        b += i

print(b)