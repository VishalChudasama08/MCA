# mca sem-2 Mid semester set-1 A05
"""
Q-1 Write a program to input a string from the user. Write a program to perform the following tasks. Use functions to perform the tasks.
	1) Count the total number of words starting with a vowel.
	2) Create a dictionary containing the word as the key and the value is its reversed word.
	3) Display the longest and the shortest word from the string.
	4) Display all the words having more than 4 characters.
"""

s = input("Enter String: ")

vowel = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')

word = s.split()
total = 0
for i in word:
    if i[0] in vowel:
        total = total + 1
print('Total:', total)
d = {}

for i in word:
    d[i] = i[::-1]

print(d)

sort = 'IAmLongWorldInTheWordThisIsRight'
long = 'a'

for i in word:
    if len(i) > len(long):
        long = i
    if len(i) < len(sort):
        sort = i
print("Sort word:", sort, 'Long word:', long)
print("more then 4 char word: ")
for i in word:
    if len(i) > 4:
        print(i)

"""
Q-2 Write a Python program to manage a Medical Store Inventory System using file handling. Program Requirements
1. Accept details of 5 medicines:
	 Medicine ID
	 Medicine Name
	 Price per unit
	 Quantity available
2. Calculate:
	 Total value of each medicine stock = Price × Quantity
3. Store all medicine details in a file named medical_store.txt.
4. Display:
	 Medicine having the highest stock value
	 Total value of all medicines in the store
	 List of medicines with quantity less than 10 (low stock medicines) 
"""

file = open("medical_store.txt", "w")

medicines = []

for i in range(5):
    print("Enter details of medicine", i+1)

    mid = input("Medicine ID: ")
    name = input("Medicine Name: ")
    price = int(input("Price per unit: "))
    qty = int(input("Quantity: "))

    total = price * qty

    medicines.append([mid, name, price, qty, total])

    file.write(mid + "," + name + "," + str(price) +
               "," + str(qty) + "," + str(total) + "\n")

file.close()


max_value = medicines[0][4]
max_med = medicines[0]

for m in medicines:
    if m[4] > max_value:
        max_value = m[4]
        max_med = m


total_stock = 0
for m in medicines:
    total_stock += m[4]


# display results
print("Medicine with highest stock value:")
print(max_med)

print("Total value of all medicines:", total_stock)

print("Low stock medicines (quantity < 10):")
for m in medicines:
    if m[3] < 10:
        print(m)
