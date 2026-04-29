"""
Q-1  
Write a program to input n numbers from the user. Write a program to perform the 
following tasks. Use functions to perform the given tasks. 
1)  Count the total number of digits in each number and store it in a dictionary 
with number as key and the number of digits as value. 
2)  Display all the palindrome numbers from the given set of numbers in a tuple. 
3)  Find the sum of all the digits of the numbers in the list. 
4)  Multiply all the numbers with 10. 
"""
def count_digits_dict(numbers):
    result = {}
    for num in numbers:
        result[num] = len(str(abs(num)))   # abs() handles negative numbers
    return result

def find_palindromes(numbers):
    pal_list = []
    for num in numbers:
        if str(num) == str(num)[::-1]:
            pal_list.append(num)
    return tuple(pal_list)

def sum_of_digits(numbers):
    total = 0
    for num in numbers:
        for digit in str(abs(num)):
            total += int(digit)
    return total


def multiply_by_10(numbers):
    return [num * 10 for num in numbers]


n = int(input("Enter how many numbers: "))
numbers = []

for i in range(n):
    num = int(input(f"Enter number {i+1}: "))
    numbers.append(num)

print("\n1) Digit count dictionary:", count_digits_dict(numbers))
print("\n2) Palindrome numbers (tuple):", find_palindromes(numbers))
print("\n3) Sum of all digits:", sum_of_digits(numbers))
print("\n4) Numbers multiplied by 10:", multiply_by_10(numbers))	


"""
Q-2  
Write a Python program to manage Library Management System using file 
handling. Use functions to 
Program Requirements: 
1.  Accept details of 5 books: 
a.  Book ID 
b.  Book name 
c.  List of Author(s) 
d.  Price 
e.  Publication 
f.  Category 
2.  Count the number of books under each Category. 
3.  Store all student details in a file named Library.txt. 
4.  Display: 
a.  Book with the highest price. 
b.  Book with only 1 author 
"""
def store_books():
    file = open("Library.txt", "w")
    books = []

    for i in range(5):
        print(f"\nEnter details of Book {i+1}:")
        bid = input("Book ID: ")
        name = input("Book Name: ")
        authors = input("Authors (comma separated): ").split(",")
        price = float(input("Price: "))
        publication = input("Publication: ")
        category = input("Category: ")

        book = (bid, name, authors, price, publication, category)
        books.append(book)

        file.write(f"{bid},{name},{'|'.join(authors)},{price},{publication},{category}\n")

    file.close()
    return books


def analyze_books(books):
    category_count = {}
    for book in books:
        cat = book[5]
        category_count[cat] = category_count.get(cat, 0) + 1

    print("\n--- Books per Category ---")
    print(category_count)

    max_book = max(books, key=lambda x: x[3])
    print("\n--- Book with Highest Price ---")
    print(max_book)

    print("\n--- Books with Only One Author ---")
    for book in books:
        if len(book[2]) == 1:
            print(book)


books = store_books()
analyze_books(books)