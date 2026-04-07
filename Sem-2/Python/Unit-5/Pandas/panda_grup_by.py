# -*- coding: utf-8 -*-
"""
Created on Tue Apr  7 14:07:48 2026

@author: mcab250013
"""
import pandas as pd

emp = {'eno':[101,102,103,104,105,106,107,108], 'ename':['Vishal', 'Ajay', 'Vijay', 'Haresh', 'Keval', 'Nayan', 'Hitesh', 'Paresh'], 'city': ['Ahemdabad', 'Rajkot', 'Jamnagar', 'Junagadh', 'Porbandar', 'Dwarka', 'Dhrol', 'Morbi'], 'salary':[80000,70000,60000,50000,40000,30000,20000,25000], 'Department': ['IT', 'HR', 'IT', 'HR', 'IT', 'HR', 'IT', 'HR']}

df=pd.DataFrame(emp)

print(df)

#groupby
print(df.groupby('Department')['salary'].sum())
print(df.groupby('Department')['salary'].mean())
print(df.groupby('Department')['ename'].count())
print(df.groupby('Department')['salary'].agg(['sum', 'mean', 'max', 'min']))