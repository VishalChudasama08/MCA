# unit-2 PYTHON INDICATIVE LIST.docx

# 49. Storing student roll numbers in a set and performing set operations

# a. Adding new students to an existing class attendance set
attendance = {"101", "102", "103"}  # existing set of students
attendance.add("104")  # Add a new student
print("Attendance after adding a new student:", attendance)

# b. Removing students who are absent from the attendance set
attendance = {"101", "102", "103", "104"}
attendance.remove("102")  # Remove a student who is absent
print("Attendance after removing an absent student:", attendance)


# 50. Creating sets of courses and checking enrollment

# a. Checking if a student is enrolled in a particular course
course_A = {"Amit", "Neha", "Riya"}
student = "Amit"
if student in course_A:
    print(f"{student} is enrolled in Course A")
else:
    print(f"{student} is not enrolled in Course A")

# b. Finding students enrolled in both courses
course_A = {"Amit", "Neha", "Riya"}
course_B = {"Neha", "Karan", "Pooja"}
common_students = course_A.intersection(course_B)
print("Students enrolled in both courses:", common_students)


# 51. Creating sets for elective subjects and performing operations

# a. Finding students enrolled in at least one of the two subjects
course_A = {"Amit", "Neha", "Riya"}
course_B = {"Riya", "Karan", "Pooja"}
enrolled_in_at_least_one = course_A.union(course_B)
print("Students enrolled in at least one course:", enrolled_in_at_least_one)

# b. Finding students enrolled only in Course A and not in Course B
only_in_A = course_A.difference(course_B)
print("Students enrolled only in Course A:", only_in_A)

# c. Finding students who participated in exactly one of the two courses
only_in_one = course_A.symmetric_difference(course_B)
print("Students enrolled only in one of the two courses:", only_in_one)

# d. Removing duplicates from course sets
course_A = {"Amit", "Neha", "Riya", "Amit"}  # Duplicate "Amit"
course_B = {"Riya", "Karan", "Neha", "Riya"}  # Duplicate "Riya"
course_A = set(course_A)  # Remove duplicates
course_B = set(course_B)  # Remove duplicates
print("Course A after removing duplicates:", course_A)
print("Course B after removing duplicates:", course_B)


# 52. Checking if a student is enrolled in a course
students = {"Amit", "Neha", "Riya", "Karan"}
if "Riya" in students:
    print("Riya is enrolled in the course.")
else:
    print("Riya is not enrolled in the course.")


# 53. Finding students enrolled in both math and CS subjects
math_students = {"Amit", "Neha", "Riya"}
cs_students = {"Riya", "Karan", "Pooja"}
common_students = math_students.intersection(cs_students)
print("Students enrolled in both Math and CS:", common_students)


# 54. Finding students who are members of at least one club
club_A = {"Rahul", "Sneha", "Amit"}
club_B = {"Sneha", "Karan", "Pooja"}
members = club_A.union(club_B)
print("Students who are members of at least one club:", members)


# 55. Finding students enrolled only in Course A
course_A = {"Amit", "Neha", "Riya", "Karan"}
course_B = {"Neha", "Karan"}
only_in_A = course_A.difference(course_B)
print("Students enrolled only in Course A:", only_in_A)


# 56. Finding students who attended exactly one workshop
workshop1 = {"Amit", "Riya", "Pooja"}
workshop2 = {"Riya", "Karan", "Neha"}
exactly_one = workshop1.symmetric_difference(workshop2)
print("Students who attended exactly one workshop:", exactly_one)


# 57. Removing "Neha" from the attendance list
attendance = {"Amit", "Neha", "Riya", "Karan"}
attendance.remove("Neha")
print("Attendance after removing Neha:", attendance)


# 58. Displaying all students using a loop
present_students = {"Ravi", "Sneha", "Amit"}
for student in present_students:
    print(student)


# 59. Removing duplicate email IDs using a set
emails = ["a@gmail.com", "b@gmail.com", "a@gmail.com", "c@gmail.com"]
unique_emails = set(emails)
print("Unique emails:", unique_emails)


# 60. Checking whether Class A is a subset of Class B
class_A = {"Amit", "Neha"}
class_B = {"Amit", "Neha", "Riya", "Karan"}
is_subset = class_A.issubset(class_B)
print("Is Class A a subset of Class B?", is_subset)


# 61. Checking whether two teams are disjoint
team1 = {"Amit", "Riya"}
team2 = {"Karan", "Neha"}
are_disjoint = team1.isdisjoint(team2)
print("Are the two teams disjoint?", are_disjoint)


# 62. Dictionary operations with employee data
employees = {
    "E001": "John",
    "E002": "Alice",
    "E003": "Bob"
}

# 1. Display the number of employees
print("Number of employees:", len(employees))

# 2. Display all empID and add to a list
emp_ids = list(employees.keys())
print("Employee IDs:", emp_ids)

# 3. Display all employee names and add to a list
emp_names = list(employees.values())
print("Employee Names:", emp_names)

# 4. Check if a particular empId exists
emp_id = input("Enter empId to check: ")
if emp_id in employees:
    print(f"Employee {emp_id} exists: {employees[emp_id]}")
else:
    print(f"Employee {emp_id} does not exist.")

# 5. Add new employee if not found
if emp_id not in employees:
    name = input(f"Enter name for empId {emp_id}: ")
    employees[emp_id] = name
    print(f"Added {emp_id}: {name}")

# 6. Change employee name
emp_id = input("Enter empId to change name: ")
if emp_id in employees:
    new_name = input("Enter new name: ")
    employees[emp_id] = new_name
    print(f"Name changed to {new_name}")

# 7. Remove an employee
emp_id = input("Enter empId to remove: ")
if emp_id in employees:
    del employees[emp_id]
    print(f"Employee {emp_id} removed.")


# 63. Student dictionary operations
students_info = {
    "A": [18, "BSc", "Maths"],
    "B": [20, "BA", "English"],
    "C": [19, "BCom", "Commerce"]
}

# 1. Display the youngest student from the dictionary
youngest = min(students_info, key=lambda x: students_info[x][0])
print(f"The youngest student is {youngest}")

# 2. Student marks dictionary
marks = {
    "A": [90, 85, 88, 92, 80],
    "B": [75, 78, 80, 85, 70]
}

# 3. Student results dictionary
results = {}
for rollno, marks_list in marks.items():
    total = sum(marks_list)
    percentage = total / 5
    grade = "A" if percentage >= 90 else "B" if percentage >= 75 else "C"
    results[rollno] = (total, percentage, grade)
print("Results:", results)

# 4. Display rollno who has scored highest marks (total)
highest_scorer = max(results, key=lambda x: results[x][0])
print(f"Highest scorer: {highest_scorer}")

# 5. Take 10 numbers and apply bubble sort
numbers = [int(input(f"Enter number {i+1}: ")) for i in range(10)]
for i in range(len(numbers)):
    for j in range(len(numbers)-1-i):
        if numbers[j] > numbers[j+1]:
            numbers[j], numbers[j+1] = numbers[j+1], numbers[j]
print("Sorted numbers:", numbers)

