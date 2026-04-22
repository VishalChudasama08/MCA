# -*- coding: utf-8 -*-
"""
pie
"""
import matplotlib.pyplot as pl

labels = ['Java', 'C++', 'JavaScript', 'Python', 'PHP']
slices = [30, 22, 15, 12, 21]
colors = ['#135792', '#125410', 'Yellow', 'gray', 'orange']
explode = [0.05, 0.05, 0.05, 0.3, 0.05]

pl.pie(
    slices,
    labels=labels,
    explode=explode,
    colors=colors,
    autopct="%1.2f%%",
    shadow=True,
    startangle=180,
    counterclock=False,
    pctdistance=0.80,
    labeldistance=1.1,
    wedgeprops={'edgecolor': 'black'}
)

pl.title("Programming Language")
pl.show()
