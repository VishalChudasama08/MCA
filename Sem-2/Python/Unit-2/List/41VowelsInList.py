# unit-2 PYTHON INDICATIVE LIST.docx

# 41.	Create a list of alphabets and count total number of vowels in it.

l = ['a', 'b', 'c', 'd', 'e', 'f', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'o', 'a', 'z', 'c', 'i', 'm', 'n', 'u']

vowels = ['a', 'e', 'i', 'o', 'u']
count = 0

for i in l:
    if i in vowels:
        count += 1;

print("Total vowels in alphabets list:", count)