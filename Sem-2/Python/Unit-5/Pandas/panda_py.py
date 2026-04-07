# -*- coding: utf-8 -*-
"""
Created on Mon Apr  6 12:46:31 2026

@author: mcab250013
"""

import pandas as pd

emp = {'eno':[101,102,103,104,105,106,107,108], 'ename':['Vishal', 'Ajay', 'Vijay', 'Haresh', 'Keval', 'Nayan', 'Hitesh', 'Paresh'], 'city': ['Ahemdabad', 'Rajkot', 'Jamnagar', 'Junagadh', 'Porbandar', 'Dwarka', 'Dhrol', 'Morbi'], 'salary':[80000,70000,60000,50000,40000,30000,20000,25000]}

df=pd.DataFrame(emp)
print(df)
print('\n\n')


l=[(101, 'Vishal', 'Ahemdabad'),(102, 'Ajay', 'Rajkot'),(103,'Vijay','Jamnagar'),(104  , 'Haresh' ,  'Junagadh'),(105,   'Keval' , 'Porbandar')]

df1=pd.DataFrame(l,columns=['eno', 'ename', 'city'])
print(df1)



#finding the number of rows and columns
print(df.shape)

r,c=df.shape
print(" Row =",r,'\n','Column =',c)

#first five rows
print(df.head())
#last five rows
print(df.tail())

print(df.head(2)) #first two
print(df.tail(1)) #last one

#range of rows (slice)
print(df[2:4])

print(df[::2]) #print ulternate
print(df[::-1]) #print reverse

# retrieve columns
print(df.columns)
print(len(df.columns))
print(df.columns[0])

print(df.ename)
print(df.city)
print(df['city'])
print(df[['ename','city']])
print(df[['eno','ename']])
print(df[['ename', 'salary']])

#dosplay the statistical information
print(df.describe())
print(df.describe().count())
print(df.describe().count()['salary'])
print(df.describe().max())
print(df.describe().max()['salary'])

print(df['salary'].min())
print(df['salary'].max())


#apply condition

print(df[df.salary>30000])

print(df[df.city=='Ahemdabad'])

#select all the fields with same condition
print(df[['eno','ename','salary']][df.salary>30000])

#get possition data
print(df.loc[1])

# change index to start from 1
df.index = range(1, len(df) + 1)
print(df)

# set index as any clumn
df2 = df.set_index('eno');
print(df2)

# indexing
df.reset_index(inplace=True)
print(df)

# sorting by column
df3 = df.sort_values('ename')
print(df3)

print(df.sort_values('ename', ascending=False))

