"""
Q-1  Write a Python program to input n integers and perform: Use functions to 
perform the given tasks. 
1.  Store number and whether it is Prime or Not in a dictionary. 
2.  Find sum of even and odd numbers separately. 
3.  Create a set of unique digits from all numbers. 
4.  Multiply each number by its reverse. 
[20] 
"""

def is_prime(num):
    if num < 2:
        return "Not Prime"
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return "Not Prime"
    return "Prime"


def prime_dict(numbers):
    result = {}
    for num in numbers:
        result[num] = is_prime(num)
    return result


def sum_even_odd(numbers):
    even_sum = 0
    odd_sum = 0
    for num in numbers:
        if num % 2 == 0:
            even_sum += num
        else:
            odd_sum += num
    return even_sum, odd_sum


def unique_digits(numbers):
    digit_set = set()
    for num in numbers:
        for digit in str(abs(num)):
            digit_set.add(int(digit))
    return digit_set


def multiply_reverse(numbers):
    result = []
    for num in numbers:
        rev = int(str(abs(num))[::-1])
        result.append(num * rev)
    return result


n = int(input("Enter number of integers: "))
numbers = []

for i in range(n):
    num = int(input(f"Enter number {i+1}: "))
    numbers.append(num)

print("\n1) Prime Dictionary:", prime_dict(numbers))

even, odd = sum_even_odd(numbers)
print("\n2) Sum of Even numbers:", even, "\tSum of Odd numbers:", odd)
print("\n3) Unique digits set:", unique_digits(numbers))
print("\n4) Multiply each number by its reverse:", multiply_reverse(numbers))


"""
Q-2  Write a Python program to manage Student Admission System using file 
handling. Use functions to perform the given tasks 
1)  Accept details of 5 students: 
  Admission Number 
  Name 
  Course 
  Fees Paid 
  Total Fees 
2)  Store in file Student_admission.txt. 
3)  Perform:  
  Count students in each course. 
  Find student who paid highest fees. 
  Display students with pending fees. 
  Calculate total fees collected.
"""

def store_students():
    file = open("Student_admission.txt", "w")
    students = []

    for i in range(5):
        print(f"\nEnter details of Student {i+1}:")
        adm_no = input("Admission Number: ")
        name = input("Name: ")
        course = input("Course: ")
        fees_paid = float(input("Fees Paid: "))
        total_fees = float(input("Total Fees: "))

        student = (adm_no, name, course, fees_paid, total_fees)
        students.append(student)

        file.write(f"{adm_no},{name},{course},{fees_paid},{total_fees}\n")

    file.close()
    return students


def analyze_students(students):
    course_count = {}
    for s in students:
        course = s[2]
        course_count[course] = course_count.get(course, 0) + 1

    print("\n--- Students per Course ---")
    print(course_count)

    max_student = max(students, key=lambda x: x[3])
    print("\n--- Student with Highest Fees Paid ---")
    print(max_student)

    print("\n--- Students with Pending Fees ---")
    for s in students:
        if s[3] < s[4]:
            print(s)

    total_collected = sum(s[3] for s in students)
    print("\n--- Total Fees Collected ---")
    print(total_collected)


students = store_students()
analyze_students(students)