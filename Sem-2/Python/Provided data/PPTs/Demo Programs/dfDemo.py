# -*- coding: utf-8 -*-
"""
Created on Tue Apr  1 12:35:51 2025

@author: Administrator
"""

import pandas as pd

df = pd.read_excel("stud.xlsx","Sheet1")
#df = pd.read_csv("studCSV.csv")

#d = {"rollno":[1,2,3,4,5], "Name":['Ohm','Shree','Jay','Kirti','Om']}

#l = [(1,'xyz',200),(2,'abcd',340),(3,'pqr',250)]
#df = pd.DataFrame(l,columns=("RollNo","Name","Marks"))
'''
print(df.shape)

print(df.head(3))
print(df.tail(2))

print(df[5:2:-1])

print(df[["Name","RollNo"]])
print(df["Marks"].min())

print(df[df.Marks == df["Marks"].max()])
print(df.describe())
'''
print(df[["Name","RollNo"]][(df.Marks<=400) & (df.Marks <=200)])
'''
print(df.index)

df1 = df.set_index("RollNo")
print(df1)

print(df1.loc[5])
print(df.sort_values("Marks",ascending=False))
'''





