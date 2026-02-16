# -*- coding: utf-8 -*-
"""
Created on Mon Apr 21 09:45:15 2025

@author: Administrator
"""

import matplotlib.pyplot as plt

# Input student data
students = []

print("Enter data for 5 students:")
for i in range(5):
    try:
        roll = int(input(f"\nEnter roll number for student {i+1}: "))
        name = input("Enter name: ")
        s1 = int(input("Enter marks in Subject 1: "))
        s2 = int(input("Enter marks in Subject 2: "))
        s3 = int(input("Enter marks in Subject 3: "))
        students.append((roll, name, s1, s2, s3))
    except ValueError:
        print("Invalid input! Please enter numeric values for roll and marks.")
        continue

# Analysis
# 1. Who scored highest in subject-1?
highest_s1 = max(students, key=lambda x: x[2])
print(f"\n1. Highest marks in Subject 1: {highest_s1[1]} with {highest_s1[2]} marks")

# 2. Average score of subject-2
avg_s2 = sum(student[3] for student in students) / len(students)
print(f"2. Average marks in Subject 2: {avg_s2:.2f}")

# 3. Line chart for subject marks
names = [student[1] for student in students]
subject1 = [student[2] for student in students]
subject2 = [student[3] for student in students]
subject3 = [student[4] for student in students]

plt.figure(figsize=(10, 6))
plt.plot(names, subject1, marker='o', label='Subject 1', color='blue')
plt.plot(names, subject2, marker='s', label='Subject 2', color='green')
plt.plot(names, subject3, marker='^', label='Subject 3', color='red')
plt.title('Student Marks in 3 Subjects')
plt.xlabel('Student Name')
plt.ylabel('Marks')
plt.legend()
# plt.grid(True)
# plt.tight_layout()
plt.show()
