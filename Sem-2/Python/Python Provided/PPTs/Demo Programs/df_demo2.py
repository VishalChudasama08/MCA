# -*- coding: utf-8 -*-
"""
Created on Wed Apr  1 09:32:40 2026

@author: Administrator
"""
import pandas as pd

def grade(marks):
    if marks >= 90:
        return "A"
    elif marks >= 75:
        return "B"
    else:
        return "C"
    
data = {
    "Student_ID": [101, 102, 103, 104, 105],
    "Name": ["Amit", "Neha", "Raj", "Simran", "Kunal"],
    "Department": ['MCA','MscIt','MscIt','MCA','MCA'],
    "Percentage": [85, 78, 92, 67, 74],
    "Attendance": [90, 85, 95, 80, 88]
}
l = [(1,'xyz',200),(2,'abcd',340),(3,'pqr',250)]
df1 = pd.DataFrame(l, columns=['Roll_No','Name','Score'])
print(df1)
df = pd.DataFrame(data)
print(df)
print(df.loc[1])
df.set_index('Student_ID',inplace=True)
print(df.loc[105])
l = list(df.loc[105])
print(l[2])
#df.sort_values('Name',inplace=True)
#print(df)
'''
print(df)
df['Grade'] = df['Percentage'].apply(grade)
print(df.groupby('Department')['Percentage'].mean())
print(df.groupby('Department')[['Percentage','Attendance']].mean())
#df.rename()
#print(df)
'''