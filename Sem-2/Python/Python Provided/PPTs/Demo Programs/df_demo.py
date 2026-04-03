# -*- coding: utf-8 -*-
"""
Created on Wed Apr  1 09:05:24 2026

@author: Administrator
"""

import pandas as p

def grade(marks):
    if marks >= 70:
        return "A"
    elif marks >= 55:
        return "B"
    else:
        return "C"
    
df = p.read_excel("stud.xlsx")
print(df)

print(df.shape)
print(df.head())
print(df.info())
print(df.describe())
print(list(df.columns))

print(df[2:4])
print(df[1:10:3])
print(list(df.name))
'''
print(df['name'])
print(df[df['m1']==df['m1'].max()])
print(df[df["m2"] >= 40])
df['percentage'] = (df['m1'] + df['m2'] + df['m3'])*100/150
df['Grade'] = df['percentage'].apply(grade)
print(df)
'''