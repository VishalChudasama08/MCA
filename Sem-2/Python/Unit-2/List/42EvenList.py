# unit-2 PYTHON INDICATIVE LIST.docx
# 42.	Create a list of even numbers between 1 to 21 using range()

l = []

for i in range(1,21):
    if i%2 == 0:
        l.append(i)

print("List of even numbers between 1 to 21:", l)