# -*- coding: utf-8 -*-
"""
Created on Fri Apr 11 09:14:55 2025

@author: Administrator
"""

#import pylab as pl
import matplotlib.pyplot as pl
import pandas as pd

df = pd.read_excel("EmpData1.xlsx",names=("Dept","Profile","Male","Female"))
print(df)
pl.plot([1,4,8,2],"go--",[1,5,1,3],"r+-.")
#pl.plot(df.Male.values,linestyle=":",marker="o",color="red")
#pl.plot(df.Female.values)
pl.title("Demo")
pl.xlabel("employees")
pl.ylabel("count")
pl.grid(axis="y")
pl.rcParams['lines.linewidth']=5
pl.bar(['a','b','c','d'],[1,5,1,3])
pl.show()