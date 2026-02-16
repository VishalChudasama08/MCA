# -*- coding: utf-8 -*-
"""
Created on Mon Apr  7 09:09:38 2025

@author: Administrator
"""

import pandas as pd

d = {"day1": 40, "day2": 41, "day3":39, "day4": 41, "day5":40}

df = pd.Series(d)
print(df.to_frame(name="Temperature"))

df = pd.DataFrame(list(d.items()),columns=("Days","Temperature"))
print(df)

Id = [1,2,3,4,5]
Stud = ["Aryan","Josh","Ohm","Shree","Kirti"]
Score = [450,340,250,350,435]
Age = [22,21,20,22,21]

ind = pd.MultiIndex.from_arrays([Id, Stud],names=("ID","Name"))
df = pd.DataFrame({"Score":Score,"Age":Age},index=ind)
print(df)

df = pd.read_excel("EmpData1.xlsx","Sheet1")
df = df.set_index(['Department','Job'])
print(df.groupby(level=['Department','Job']).sum())

students_data = [
    ['Pass', 85, 78, 92],
    ['Fail', 45, 56, 49],
    ['Fail', 45, 58, 49],
    ['Pass', 90, 84, 91],
    ['Fail', 55, 60, 48]
]

# Custom index values (e.g., Student names)
index_labels = ['Student1', 'Student2', 'Student3', 'Student4', 'Student5']

# Column names
columns = ['Result', 'Subject1', 'Subject2', 'Subject3']

# Create the DataFrame
df = pd.DataFrame(students_data, index=index_labels, columns=columns)

print(df)

pass_fail_by_subject = df[['Subject1', 'Subject2', 'Subject3']] >= 50
pass_fail_by_subject['Result'] = df["Result"]
print(pass_fail_by_subject)

print(pass_fail_by_subject.groupby("Result").count())
min_marks = df[['Subject1', 'Subject2', 'Subject3']].min()
max_marks = df[['Subject1', 'Subject2', 'Subject3']].max()

print("Minimum Marks:\n", min_marks)
print("\nMaximum Marks:\n", max_marks)