# -*- coding: utf-8 -*-
"""
Created on Sat Apr  4 12:20:00 2026

@author: mcab250013
"""

import matplotlib.pyplot as pl
import pandas as pd

df = pd.read_excel("emp.xlsx")

# print(type(df))

# print(df["Number"] , "\n", df["Name"])

numbers = df["Number"]
n = numbers[0]
print(n*2)












