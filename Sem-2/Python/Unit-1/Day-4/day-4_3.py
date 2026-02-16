# day-4

# 3.	If s2 is a part of s1 then print the 1st and last occurrences of it 

# s1 = "Find the length of a string. Print the string in upper case. Print the string in lower case"

# s2 = "the";

s1 = input("Enter first string: ")

s2 = input("Enter second string: ")

a = s1.split(" ");

print(s1.find(s2))
if s2 in s1 :
    print("first:", a[0], "\nlast:", a[len(a)-1])
else:
    print("s2 not present in s1");


