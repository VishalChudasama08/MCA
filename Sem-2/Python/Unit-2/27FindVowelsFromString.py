# Unit-2
# 27.	Take a string as an input from the user. Find total number of vowels in it. (Hint: take a tuple of vowels)

t = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')

st = input("Enter String: ")

total = 0

for i in st:
    if i in t:
        total += 1

print(total)
