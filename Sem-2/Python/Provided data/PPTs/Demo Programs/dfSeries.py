# -*- coding: utf-8 -*-
"""
Created on Fri Apr  4 09:29:00 2025

@author: Administrator
"""

import pandas as pd


a = ["Apple","Banana","Orange","Pinaple"]
#df = pd.Series(a, index=("F1","F2","F3","F4"))
df = pd.Series(a, index=(tuple(map(lambda x: "F"+str(x), range(1,5,1)))))
print(df["F1"])

d = {"Python": 40,"Java":45,"DS": 35}
df = pd.Series(d)
print(df.sort_values())

emp = ["a","b","c","d"]
sal = [20000,35000,25000,22000]
exp = [3,2,4,1]

ind = pd.MultiIndex.from_arrays([emp,exp],names=("Name","Experience"))
#print(df)
df = pd.DataFrame({"Sal":[20000,35000,25000,22000]},index=ind)

print(df)

ind = pd.MultiIndex.from_tuples([("A",72),("B",60),("B",55),("A",40)],names=("Div","Strength"))
df = pd.DataFrame({"Sub":["Python","DS","Java","Laravel"]},index=ind)
print(df)

df = pd.read_excel("empData1.xlsx","Sheet1")
df1 = pd.MultiIndex.from_frame(df)
for i in df1:
    print(i)
    
l = [(1,'Usha','A',200),(2,'Dharm','B', 200),(3,'Aarya','C',150),(4,'Het','B', 150),(5,'Purna','A', 250)]
df = pd.DataFrame(l,index=['S1','S2','S3','S4','S5'],columns=('RollNo','Name','Div','Score'))
print(df)
g = df.groupby("Div")
print(g.min())


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

print(df) 
g2=df.groupby("Status")
#g3 = df.groupby(['Status','Temperature'])
#g4 = df.groupby('Temperature')

#print(g3.min())
print(g2.max())
#print(g3.count())  
