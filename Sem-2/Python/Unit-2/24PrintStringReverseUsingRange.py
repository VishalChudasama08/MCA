# Unit-2

# 24.	Take a string input from user and print it in reverse using range 

a=input("Enter String: ")

for i in range(len(a)):
    print(a[len(a)-i-1], end="")