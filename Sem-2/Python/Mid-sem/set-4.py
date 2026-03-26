# mca sem-2 Mid semester set-4 A05

"""
Q-1 Write a Python program to input n integers and perform: Use functions to
perform the given tasks.
1. Store number and whether it is Prime or Not in a dictionary.
2. Find sum of even and odd numbers separately.
3. Create a set of unique digits from all numbers.
4. Multiply each number by its reverse.
"""


def check_prime(nums):
    d = {}
    for n in nums:
        if n <= 1:
            d[n] = "Not Prime"
        else:
            flag = 1
            i = 2
            while i < n:
                if n % i == 0:
                    flag = 0
                    break
                i = i + 1

            if flag == 1:
                d[n] = "Prime"
            else:
                d[n] = "Not Prime"

    return d


def sum_even_odd(nums):
    even = 0
    odd = 0
    for n in nums:
        if n % 2 == 0:
            even = even + n
        else:
            odd = odd + n

    return even, odd


def unique_digits(nums):
    s = set()
    for n in nums:
        i = n
        if i < 0:
            i = -i
        if i == 0:
            s.add(0)
        while i > 0:
            digit = i % 10
            s.add(digit)
            i = i // 10
    return s


def multiply_with_reverse(nums):
    result = []
    for n in nums:
        i = n
        if i < 0:
            i = -i

        rev = 0
        temp = i
        while temp > 0:
            digit = temp % 10
            rev = rev * 10 + digit
            temp = temp // 10

        result.append(n * rev)

    return result


n = int(input("Enter number of elements: "))
nums = []

for i in range(n):
    nums.append(int(input("Enter number: ")))

print("Prime Dictionary:", check_prime(nums))

even, odd = sum_even_odd(nums)
print("Sum of even:", even)
print("Sum of odd:", odd)

print("Unique digits set:", unique_digits(nums))
print("Multiply with reverse:", multiply_with_reverse(nums))


"""
Q-2 Write a Python program to manage Student Admission System using file
handling. Use functions to perform the given tasks
1) Accept details of 5 students:
 Admission Number
 Name
 Course
 Fees Paid
 Total Fees
2) Store in file Student_admission.txt.
3) Perform:
 Count students in each course.
 Find student who paid highest fees.
 Display students with pending fees.
 Calculate total fees collected. 
"""


def add_students():
    file = open("Student_admission.txt", "w")
    for i in range(5):
        print("\nEnter student details", i+1)
        adm = input("Admission Number: ")
        name = input("Name: ")
        course = input("Course: ")
        paid = float(input("Fees Paid: "))
        total = float(input("Total Fees: "))

        file.write(adm + "," + name + "," + course + "," +
                   str(paid) + "," + str(total) + "\n")

    file.close()


def display_data():
    file = open("Student_admission.txt", "r")
    data = file.readlines()
    students = []
    for line in data:
        s = line.strip().split(",")
        s[3] = float(s[3])
        s[4] = float(s[4])
        students.append(s)

    file.close()

    count = {}
    for s in students:
        c = s[2]
        if c in count:
            count[c] = count[c] + 1
        else:
            count[c] = 1

    print("\nStudents in each course:")
    for c in count:
        print(c, ":", count[c])

    max_student = students[0]
    for s in students:
        if s[3] > max_student[3]:
            max_student = s

    print("\nStudent who paid highest fees:")
    print(max_student)

    print("\nStudents with pending fees:")
    for s in students:
        if s[3] < s[4]:
            print(s)

    total_collected = 0
    for s in students:
        total_collected = total_collected + s[3]

    print("\nTotal fees collected:", total_collected)


add_students()
display_data()
