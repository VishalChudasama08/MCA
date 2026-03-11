# Unit-2

# 24.	Take a string input from user and print it in reverse using range

a = input("Enter String: ")

rev = ""

for i in range(len(a)-1, -1, -1):
    rev += a[i]

print(rev)
