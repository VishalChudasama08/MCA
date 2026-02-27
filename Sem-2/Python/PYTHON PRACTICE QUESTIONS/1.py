"""
Write a Python program that accepts a string from the user and performs the following operations:
	•	Display the string in reverse order.
	•	Count the number of vowels and consonants in the string.
	•	Check whether the string is a palindrome.
	•	Replace all vowels in the string with * and display the modified string.
"""

s = input("Enter string:")
r = ""
for i in reversed(s):
    r += i
print(r)

v = ""
count = 0
vowels = "aeiouAEIOU"
for i in s:
    if i in vowels:
        count = count + 1
        v += i

print("total:", count, "consonants:", v)

if s == r:
    print("string is palindrome")
else:
    print("String is not palindrome")

m = ""
for i in s:
    if i in vowels:
        m += "*"
    else:
        m += i

print(m)
