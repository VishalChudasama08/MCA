# mca sem-2 Mid semester set-2 A05
"""
Q-1 Write a program to input n numbers from the user. Write a program to perform the
following tasks. Use functions to perform the given tasks.
1) Count the total number of digits in each number and store it in a dictionary
with number as key and the number of digits as value.
2) Display all the palindrome numbers from the given set of numbers in a tuple.
3) Find the sum of all the digits of the numbers in the list.
4) Multiply all the numbers with 10.
"""


def count_digits(nums):
    d = {}
    for n in nums:
        i = n
        count = 0
        while i > 0:
            i = i//10
            count = count + 1
        d[n] = count
    return d


def palindrome_nums(nums):
    p = []
    for n in nums:
        if str(n) == str(n)[::-1]:
            p.append(n)
    return tuple(p)


def sum_of_digits(nums):
    total = 0
    for n in nums:
        i = n
        while i > 0:
            digit = i % 10
            total = total + digit
            i = i // 10
    return total


def multiply_by_10(nums):
    result = []
    for n in nums:
        result.append(n * 10)
    return result


n = int(input("Enter number of elements: "))
nums = []

for i in range(n):
    nums.append(int(input("Enter number: ")))


print("Digits dictionary:", count_digits(nums))
print("Palindrome numbers:", palindrome_nums(nums))
print("Sum of all digits:", sum_of_digits(nums))
print("Numbers multiplied by 10:", multiply_by_10(nums))


"""
Q-2 Write a Python program to manage Library Management System using file
handling. Use functions to
Program Requirements:
1. Accept details of 5 books:
a. Book ID
b. Book name
c. List of Author(s)
d. Price
e. Publication
f. Category
2. Count the number of books under each Category.
3. Store all student details in a file named Library.txt.
4. Display:
a. Book with the highest price.
b. Book with only 1 author 
"""


def add_books():
    file = open("Library.txt", "w")

    for i in range(5):
        print("\nEnter book details", i+1)

        bid = input("Book ID: ")
        name = input("Book Name: ")
        authors = input("Authors (comma separated): ")
        price = int(input("Price: "))
        pub = input("Publication: ")
        cat = input("Category: ")

        file.write(bid + "," + name + "," + authors + "," +
                   str(price) + "," + pub + "," + cat + "\n")

    file.close()


def display_data():
    file = open("Library.txt", "r")
    data = file.readlines()

    books = []

    for line in data:
        b = line.strip().split(",")
        b[3] = int(b[3])
        books.append(b)

    file.close()

    # count category
    cat_count = {}
    for b in books:
        cat = b[5]
        if cat in cat_count:
            cat_count[cat] = cat_count[cat] + 1
        else:
            cat_count[cat] = 1

    print("\nBooks count by category:")
    for c in cat_count:
        print(c, ":", cat_count[c])

    # highest price book
    max_book = books[0]
    for b in books:
        if b[3] > max_book[3]:
            max_book = b

    print("\nBook with highest price:")
    print(max_book)

    # book with only 1 author
    print("\nBooks with only 1 author:")
    for b in books:
        authors = b[2].split(",")
        if len(authors) == 1:
            print(b)


add_books()
display_data()
