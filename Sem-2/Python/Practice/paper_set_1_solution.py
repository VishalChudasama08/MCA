"""
Q1.
Write a Python program to display words in a sentence that appeared more than once in the input string entered by the user (with their count).
Eg. Input: Python is very powerful language. I like it very much. Coding in Python language is very easy.
Python – 2, very – 3,   language – 2 

"""
"""
s = "Python is very powerful language. I like it very much. Coding in Python language is very easy."

s = s.lower()
s = s.replace('.', '')
words = s.split(" ")

# dictionary
count = {}

# here .get(key, default) if this key exit in dictionary than return it value, else return default value (0)
#
for w in words:
    count[w] = count.get(w, 0) + 1

for k in count:
    if count[k] > 1:
        print(k, ":", count[k])
"""


"""
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
Total Electricity Bill = ₹ 1975.0
"""
rates = {
    (0, 100): 3.00,
    (101, 200): 4.50,
    (201, 300): 6.00,
    (301, 100000): 8.00
}
units = int(input("Enter total units consumed:"))
bill = 0

for range, rate in rates.items():
    lower, upper = range
    print(bill)
    if units > lower:
        used_unit = min(units, upper) - lower
        bill += rate * used_unit

print(bill)


"""
Q3.
Take input of 2 sets from the students. Find if the sets are equal or not. If not equal find are they unique or one set is the subset of another.
Eg. 
(1)	Input S1 = (1,2,3)               S2 = (4,5,6)       Output: 2 different sets
(2)	Input S1 = (1, 2, 3, 4, 5)    S2 = (2, 4, 5)     Output: s2 is the subset of s1.

"""
