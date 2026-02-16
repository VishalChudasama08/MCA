# -*- coding: utf-8 -*-
"""
Created on Wed Feb 14 03:54:58 2024

@author: urja
"""

import pandas as pd

s = pd.Series([10, 20, 30], index=["Math", "Science", "English"])
print(s.max())


calories = {"day1": 420, "day2": 380, "day3": 390}
myvar = pd.Series(calories, index = ["day1", "day2","day3"])
print(myvar.mean())

'''
students = ['Garg','Harsh','Sona','Ritu']
marks = [94,87,90,75]
age = [22,21,23,20]

df = pd.MultiIndex.from_arrays([students,marks,age],names=('Name','Percentage','Age'))
for i in df:
    print(i)


d = {"empid":[1001,1002,1003,1004,1005],
    "ename":['urja','dahrm','aarya','hetansh','purna'],
   "sal":[1000,2000,3000,4000,5000]}

df1 = pd.DataFrame(d)
print(df1)
df1 = pd.MultiIndex.from_frame(df1)
for i in df1:
    print(i)
'''
df = pd.read_excel("empData1.xlsx","Sheet1")
df1 = pd.MultiIndex.from_frame(df)

for i in df1:
    print(i)
'''
l = [(1,'urja',200),(2,'dharm',200),(3,'aarya',150),(4,'het',150),(5,'purna',200)]
df = pd.DataFrame(l,index=['S1','S2','S3','S4','S5'],columns=('RollNo','Name','Score'))
print(df)

g1 = df.groupby("Score")
print(g1.mean())

df = pd.DataFrame( 
    [ 
        ("Corona Positive", 65, 99), 
        ("Corona Negative", 52, 98.7), 
        ("Corona Positive", 43, 100.1), 
        ("Corona Positive", 26, 99), 
        ("Corona Negative", 30, 98.7), 
    ], 
      
    index=["Patient 1", "Patient 2", "Patient 3", 
           "Patient 4", "Patient 5"], 
      
    columns=("Status", "Age(in Years)", "Temperature"), 
) 
'''
#print(df) 
#g2=df.groupby("Status")
#g3 = df.groupby(['Status','Temperature'])
#g4 = df.groupby('Temperature')

#print(g3.min())
#print(g2.max())
#print(g3.count())'''

data = {
    "Employee_ID": [101, 102, 103, 104, 105, 106, 107, 108, 109, 110],
    "Name": ["Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hank", "Ivy", "Jack"],
    "Department": ["IT", "HR", "Finance", "IT", "HR", "Finance", "IT", "HR", "Finance", "IT"],
    "Experience": [5, 3, 8, 3, 5, 7, 6, 7, 9, 5],
    "Salary": [75000, 54000, 82000, 65000, 58000, None, 77000, 62000, 86000, 62000],
    "Performance_Score": [88, 76, 91, 79, 83, 95, 85, None, 92, 80]
}


df = pd.DataFrame(data)
print(df)
print(df["Name"].values)
print(df.sort_values("Department"))

g = df.groupby("Department")

print(g["Salary"].max())
ind = pd.MultiIndex.from_frame(df[["Experience","Department"]])

df1 = pd.DataFrame({"Salary": df["Salary"].values,"Performance":df["Performance_Score"].values},index=ind) 

print(df1.loc[5,"IT"])


countries = ['USA', 'USA', 'Canada', 'Canada']
cities = ['New York', 'Chicago', 'Toronto', 'Vancouver']

multi_index = pd.MultiIndex.from_arrays([countries, cities], names=["Country", "City"])
df2 = pd.DataFrame({'Population': [8.4, 2.7, 2.9, 2.4]}, index=multi_index)

print(df2)



