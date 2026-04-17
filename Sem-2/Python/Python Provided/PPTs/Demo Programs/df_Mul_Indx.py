# -*- coding: utf-8 -*-
"""
Created on Fri Apr  3 08:42:46 2026

@author: Administrator
"""

import pandas as pd
'''
years = [2023, 2023, 2024, 2024]
dept = ["IT", "HR", "IT", "HR"]

index = pd.MultiIndex.from_arrays([years, dept], names=["Year", "Department"])

df = pd.DataFrame({"Marks": [80, 75, 85, 78]}, index=index)

print(df)

'''

data = pd.DataFrame({
    "Year": [2023, 2023, 2024, 2024],
    "Department": ["IT", "HR", "IT", "HR"]
})

index = pd.MultiIndex.from_frame(data)

df = pd.DataFrame({"Marks": [80, 75, 85, 78]}, index=index)

print(df)
#print(df.loc['IT'])  
#if the sequesnce of coulumns changes then 
#1st column will be the index column, where search/locate is possible.
print(df.loc[2023])
print(df.groupby(level='Department').mean())
print(df.groupby(level='Year').mean())

