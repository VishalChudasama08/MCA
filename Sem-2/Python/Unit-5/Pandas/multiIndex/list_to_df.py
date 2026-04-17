# -*- coding: utf-8 -*-
"""
14.	Create DataFrame from List object with Index values
List object contains details for 5 students’ result: Pass /Fail with scores in 3 subjects
"""
import pandas as pd

std_result = [
    ['Pass', 87,65,75],
    ['Fail', 29,31,25],
    ['Pass', 80,60,70],
    ['Fail', 27,30,28],
    ['Pass', 88,66,77]
]

std_name = ['a', 'b', 'c', 'd', 'e']

df = pd.DataFrame(data=std_result, index=std_name, columns=['status','c','java','php'])
print(df)


# 15.	Find total number of ‘pass’ students and ‘fail’ students in each subject from above list – use of groupby

total_number = df.groupby('status')['status'].count().reset_index(name='Total')
print(total_number)

# 16.	Find minimum and maximum marks of each subject

minimum = df[['c','java','php']].min()
maximum = df[['c','java','php']].max()

print(minimum)
print(maximum)

# 17.	Create 2 data frames from SQL tables and merge them based on common column (keys)

df1 = pd.DataFrame({'name':['abc','def', 'ghi']},index=[1,2,3])
df2 = pd.DataFrame({'city':['ahm','surat','jam']}, index=[1,2,4])

df3 = marge(df1,df2,)

print()