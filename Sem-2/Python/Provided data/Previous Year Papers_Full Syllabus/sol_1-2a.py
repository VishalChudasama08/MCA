# -*- coding: utf-8 -*-
"""
Created on Mon Apr 21 09:37:25 2025

@author: Administrator
"""

# User-defined exception class
class InvalidNameError(Exception):
    def __init__(self, message="Name must be a string with alphabetic characters only."):
        self.message = message
        super().__init__(self.message)

# Function to count vowels in a name
def count_vowels(name):
    vowels = 'aeiouAEIOU'
    return sum(1 for char in name if char in vowels)

# Function to get student names with exception handling
def get_student_names():
    students = []
    for i in range(10):
        try:
            name = input(f"Enter name of student {i+1}: ")
            if not name.isalpha():
                raise InvalidNameError()
            students.append(name)
        except InvalidNameError as e:
            print(f"Invalid input: {e}")
            continue
    return students

# Function to sort students by vowel count
def sort_by_vowels(student_list):
    return sorted(student_list, key=count_vowels, reverse=True)

# Main program
student_names = get_student_names()

# If any valid names were entered
if student_names:
    sorted_students = sort_by_vowels(student_names)
    print("\nStudents sorted by number of vowels in their names:")
    for name in sorted_students:
        print(f"{name} (Vowels: {count_vowels(name)})")
else:
    print("No valid student names were entered.")
