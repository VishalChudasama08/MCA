# -*- coding: utf-8 -*-
"""
Created on Fri Apr  3 09:44:31 2026

@author: Administrator
"""

import pandas as pd

df1 = pd.DataFrame({
    "ID": [1, 2, 3],
    "Name": ["A", "B", "C"]
})
df1 = df1.set_index('ID')
df2 = pd.DataFrame({
    "ID": [1, 2, 4],
    "Marks": [80, 90, 70]
})
df2['Grade'] = pd.Series(['A','A+','B'])
df2 = df2.set_index('ID')
result = pd.merge(df1, df2, on="ID", how="inner")
print(result)

d = df1.join(df2)
print(d)