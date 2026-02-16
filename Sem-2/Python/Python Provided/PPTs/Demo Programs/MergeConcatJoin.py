# -*- coding: utf-8 -*-
"""
Created on Tue Apr  8 09:28:59 2025

@author: Administrator
"""

import pandas as pd

students = pd.DataFrame({
    'roll_no': [101, 102, 103, 104],
    'name': ['Ankit', 'Bharat', 'Charmi', 'David'],
    'department': ['CS', 'IT', 'CS', 'ECE']
})

print("Students:")
print(students)

# Semester 1 Results
sem1_results = pd.DataFrame({
    'roll_no': [101, 102, 103],
    'SQl': [78, 88, 85],
    'PHP': [82, 90, 80]
})

# Semester 2 Results
sem2_results = pd.DataFrame({
    'roll_no': [101, 102, 104],
    'Python': [81, 85, 77],
    'Java': [83, 89, 79]
})

# Attendance Record

attendance = pd.DataFrame({
    'name': ['Ankit', 'Bharat', 'Charmi'],
    'attendance_%': [92, 87, 90]
})

print("\nSemester 1 Results:")
print(sem1_results)
print("\nSemester 2 Results:")
print(sem2_results)

res1 = pd.merge(students, sem1_results, on="roll_no", how="left")
print(res1)

res2 = pd.merge(students, sem2_results)
print(res2)

finalres = pd.concat([res1,res2],join="inner")
print(finalres)

attendance.set_index("name",inplace=True)
finalres.set_index("name", inplace=True)
finalData = finalres.join(attendance,how="left")
finalData.reset_index()
print(finalData)