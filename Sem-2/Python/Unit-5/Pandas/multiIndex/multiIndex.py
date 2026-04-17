# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 09:36:26 2026

@author: mcab250013
"""

# 12.	Create MultiIndex.from_arrays like Students [ ], Score [ ], Age [ ]

import pandas as pd

students = ['a', 'b', 'c', 'd', 'e', 'f']
score = [45, 56, 67, 78, 89, 98]
age = [18,19,20,21,19,20]

index = pd.MultiIndex.from_arrays([students,score,age])

df = pd.DataFrame({"Name":[1,2,3,4,5,6]},index=index)

print(df)


"""
13.	Create MultiIndex.from_frame – 
    a.	Use dictionary object for employee data for empId, Name and Salary
    b.	Create DataFrames by read_excel(), read_csv() and set multiindex
"""

# a.
emp = {"empId":[101,102,103,104,105,106], "name":['a', 'b', 'c', 'd', 'e', 'f'], "salary":[40000,50000,60000,70000,80000,90000]}
data = pd.DataFrame(emp)
index = pd.MultiIndex.from_frame(data)
df2 = pd.DataFrame({"#":[1,2,3,4,5,6]}, index=index)

print(df2)

# b.

emp = pd.read_excel('D://emp.xlsx')
df3 = pd.DataFrame(emp)
df4 = df3.set_index(["Name", "City"])
print(df4)

emp = pd.read_csv('D://emp.csv')
df5 = pd.DataFrame(emp)
df6 = df5.set_index(["Name", "City"])
print(df6)


