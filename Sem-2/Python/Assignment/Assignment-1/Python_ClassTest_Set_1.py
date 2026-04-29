"""
Python Practical Test Paper – Set – 1
Q1.
Write a Python program to display words in a sentence that appeared more than once in the 
input string entered by the user (with their count).
Eg. Input: Python is very powerful language. I like it very much. Coding in Python language 
is very easy.
Python – 2, very – 3,   language – 2 
Q2.
Create a dictionary that stores electricity usage ranges (in units) with per-unit rates.
Accept total units consumed from the user and calculate the total electricity bill accordingly.
Eg. Take the Static dictionary object as below.
rates = {
    (0,100): 3.00,
    (101,200): 4.50,
    (201,300): 6.00,
    (301,100000): 8.00   # upper bound large number
}
Input by the user:
Enter total units consumed: 350
Total Electricity Bill =   1975.0
Q3.
Take input of 2 sets from the students. Find if the sets are equal or not. If not equal find are 
they unique or one set is the subset of another.
Eg. 
(1) Input S1 = (1,2,3)               S2 = (4,5,6)       Output: 2 different sets
(2) Input S1 = (1, 2, 3, 4, 5)    S2 = (2, 4, 5)     Output: s2 is the subset of s1.
"""

# Q1 
text = input("Enter a sentence: ")

import string
for ch in string.punctuation:
    text = text.replace(ch, "")

words = text.lower().split()

word_count = {}

for word in words:
    word_count[word] = word_count.get(word, 0) + 1

print("\nWords appearing more than once:")

for word, count in word_count.items():
    if count > 1:
        print(f"{word} - {count}")
        

# Q2 
rates = {
    (0,100): 3.00,
    (101,200): 4.50,
    (201,300): 6.00,
    (301,100000): 8.00
}

units = int(input("Enter total units consumed: "))
bill = 0

for (start, end), rate in rates.items():
    if units >= start:
        if units <= end:
            bill += (units - start + 1) * rate
            break
        else:
            bill += (end - start + 1) * rate

print("Total Electricity Bill =", bill)


# Q3 
s1 = set(map(int, input("Enter elements of Set 1 (space separated): ").split()))
s2 = set(map(int, input("Enter elements of Set 2 (space separated): ").split()))

if s1 == s2:
    print("Both sets are equal")
elif s2.issubset(s1):
    print("S2 is a subset of S1")
elif s1.issubset(s2):
    print("S1 is a subset of S2")
else:
    print("2 different sets")