"""
Q-1  Write a Python program to input n words and perform: 
1.  Create dictionary: 
o  Word as key 
o  Number of vowels as value 
2.  Display words starting and ending with same letter in a tuple. 
3.  Reverse each word. 
4.  Create a set of words having more than 5 characters. 
[20] 
"""

def vowel_count_dict(words):
    vowels = "aeiouAEIOU"
    result = {}
    for word in words:
        count = 0
        for ch in word:
            if ch in vowels:
                count += 1
        result[word] = count
    return result


def same_start_end(words):
    result = []
    for word in words:
        if word[0].lower() == word[-1].lower():
            result.append(word)
    return tuple(result)


def reverse_words(words):
    return [word[::-1] for word in words]


def words_length_set(words):
    return {word for word in words if len(word) > 5}


n = int(input("Enter number of words: "))
words = []

for i in range(n):
    w = input(f"Enter word {i+1}: ")
    words.append(w)

print("\n1) Dictionary (word → vowel count):", vowel_count_dict(words))	
print("\n2) Words starting & ending with same letter:", same_start_end(words))
print("\n3) Reversed words:", reverse_words(words))
print("\n4) Words with more than 5 characters (set):", words_length_set(words))


"""
Q-2  Write a Python program to manage Bank Accounting System using file 
handling. 
1)  Program Requirements: 
  Accept details of 5 customers: 
  Account Number 
  Name 
  Account Type (Saving/Current) 
  Balance 
2)  Store in file Bank.txt. 
3)  Perform: 
  Count customers in each account type. 
  Display customer with highest balance. 
  Apply 5% interest to Saving accounts. 
  Display customers having balance less than 5000. 
[20] 
"""

def store_customers():
    file = open("Bank.txt", "w")
    customers = []

    for i in range(5):
        print(f"\nEnter details of Customer {i+1}:")
        acc_no = input("Account Number: ")
        name = input("Name: ")
        acc_type = input("Account Type (Saving/Current): ")
        balance = float(input("Balance: "))

        customer = (acc_no, name, acc_type, balance)
        customers.append(customer)

        file.write(f"{acc_no},{name},{acc_type},{balance}\n")

    file.close()
    return customers


def analyze_customers(customers):
    count = {}
    for c in customers:
        acc_type = c[2]
        count[acc_type] = count.get(acc_type, 0) + 1

    print("\n--- Customers per Account Type ---")
    print(count)

    max_customer = max(customers, key=lambda x: x[3])
    print("\n--- Customer with Highest Balance ---")
    print(max_customer)

    print("\n--- After 5% Interest (Saving Accounts) ---")
    updated = []
    for c in customers:
        acc_no, name, acc_type, balance = c
        if acc_type.lower() == "saving":
            balance += balance * 0.05
        updated.append((acc_no, name, acc_type, balance))
        print((acc_no, name, acc_type, balance))

    print("\n--- Customers with Balance < 5000 ---")
    for c in updated:
        if c[3] < 5000:
            print(c)


customers = store_customers()
analyze_customers(customers)