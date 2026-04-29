"""
Write a program to input a string from the user. Write a program to perform the 
following tasks. Use functions to perform the tasks. 
1)  Count the total number of words starting with a vowel. 
2)  Create a dictionary containing the word as the key and the value is its reversed 
word. 
3)  Display the longest and the shortest word from the string. 
4)  Display all the words having more than 4 characters.
"""

def count_vowel_words(words):
    count = 0
    vowels = "aeiouAEIOU"
    for word in words:
        if word[0] in vowels:
            count += 1
    return count

def create_reverse_dict(words):
    rev_dict = {}
    for word in words:
        rev_dict[word] = word[::-1]
    return rev_dict

def longest_shortest(words):
    longest = max(words, key=len)
    shortest = min(words, key=len)
    return longest, shortest

def words_more_than_4(words):
    return [word for word in words if len(word) > 4]

text = input("Enter a string: ")

punct = ".,!?;:'\"()-"
for ch in punct:
    text = text.replace(ch, "")

words = text.split()

print("\n1) Words starting with vowel:", count_vowel_words(words))
print("\n2) Dictionary (word → reversed):", create_reverse_dict(words))

longest, shortest = longest_shortest(words)
print("\n3) Longest word:", longest, "\tShortest word:", shortest)
print("\n4) Words with more than 4 characters:", words_more_than_4(words))



"""
Write a Python program to manage a Medical Store Inventory System using file handling. Program Requirements 
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
def store_data():
    file = open("medical_store.txt", "w")

    medicines = []

    for i in range(5):
        print(f"\nEnter details of Medicine {i+1}:")
        mid = input("Medicine ID: ")
        name = input("Medicine Name: ")
        price = float(input("Price per unit: "))
        qty = int(input("Quantity: "))

        total_value = price * qty
        medicines.append((mid, name, price, qty, total_value))
        file.write(f"{mid},{name},{price},{qty},{total_value}\n")

    file.close()
    return medicines


def analyze_data(medicines):
    max_med = max(medicines, key=lambda x: x[4])

    total_store_value = sum(med[4] for med in medicines)
    low_stock = [med for med in medicines if med[3] < 10]

    print("\n--- Medicine with Highest Stock Value ---")
    print(max_med)

    print("\n--- Total Value of Store ---")
    print(total_store_value)

    print("\n--- Low Stock Medicines (Qty < 10) ---")
    for med in low_stock:
        print(med)


medicines = store_data()
analyze_data(medicines)