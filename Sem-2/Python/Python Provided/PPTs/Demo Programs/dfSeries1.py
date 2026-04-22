# -*- coding: utf-8 -*-
"""
Created on Mon Apr 20 13:16:36 2026

@author: admin
"""
import pandas as pd
#nm=['raj','sejal','payal','sunnuy','rahul']
df=pd.DataFrame([(1,'raj'),(2,'sejal'),(3,'payal'),(4,'sunny'),(5,'rahul')],columns=['rollno','name'])
print(df)


a=[23,34,56,67,70]
d=pd.Series(a,name='marks')
print(d)
#print(d['raj'])

#d=d*2
print(d)


print(d)

df=pd.concat([df,d],axis=1)
print(df)
