# mca sem-2 Mid semester set-3 A05
"""
Q-1 Write a Python program to input n words and perform:
1. Create dictionary:
o Word as key
o Number of vowels as value
2. Display words starting and ending with same letter in a tuple.
3. Reverse each word.
4. Create a set of words having more than 5 characters.
"""


def count_vowels(words):
    d = {}
    for w in words:
        count = 0
        for ch in w:
            if ch in "aeiouAEIOU":
                count = count + 1
        d[w] = count
    return d


def same_start_end(words):
    t = []
    for w in words:
        if len(w) > 0 and w[0] == w[-1]:
            t.append(w)
    return tuple(t)


def reverse_words(words):
    rev_list = []
    for w in words:
        rev = ""
        for i in range(len(w)-1, -1, -1):
            rev = rev + w[i]
        rev_list.append(rev)
    return rev_list


def more_than_5(words):
    s = set()
    for w in words:
        if len(w) > 5:
            s.add(w)
    return s


n = int(input("Enter number of words: "))
words = []

for i in range(n):
    words.append(input("Enter word: "))


print("Vowel dictionary:", count_vowels(words))
print("Same start and end:", same_start_end(words))
print("Reversed words:", reverse_words(words))
print("Words > 5 letters:", more_than_5(words))


"""
Q-2 Write a Python program to manage Bank Accounting System using file
handling.
1) Program Requirements:
 Accept details of 5 customers:
 Account Number
 Name
 Account Type (Saving/Current)
 Balance
2) Store in file Bank.txt.
3) Perform:
 Count customers in each account type.
 Display customer with highest balance.
 Apply 5% interest to Saving accounts.
 Display customers having balance less than 5000.
"""


def add_customers():
    file = open("Bank.txt", "w")

    for i in range(5):
        print("\nEnter customer details", i+1)

        acc = input("Account Number: ")
        name = input("Name: ")
        acc_type = input("Account Type (Saving/Current): ")
        bal = float(input("Balance: "))

        file.write(acc + "," + name + "," + acc_type + "," + str(bal) + "\n")

    file.close()


def display_data():
    file = open("Bank.txt", "r")
    data = file.readlines()

    customers = []

    for line in data:
        c = line.strip().split(",")
        c[3] = float(c[3])
        customers.append(c)

    file.close()

    count = {}
    for c in customers:
        t = c[2]
        if t in count:
            count[t] = count[t] + 1
        else:
            count[t] = 1

    print("\nCustomers in each account type:")
    for t in count:
        print(t, ":", count[t])

    max_cust = customers[0]
    for c in customers:
        if c[3] > max_cust[3]:
            max_cust = c

    print("\nCustomer with highest balance:")
    print(max_cust)

    print("\nAfter applying 5% interest (Saving accounts):")
    for c in customers:
        if c[2] == "Saving":
            new_bal = c[3] + (c[3] * 5 / 100)
            print(c[0], c[1], "New Balance:", new_bal)

    print("\nCustomers with balance less than 5000:")
    for c in customers:
        if c[3] < 5000:
            print(c)


add_customers()
display_data()
