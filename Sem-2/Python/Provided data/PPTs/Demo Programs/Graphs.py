# -*- coding: utf-8 -*-
"""
Created on Sat Feb 17 04:41:18 2024

@author: urja
"""
#import pylab as pb
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import random

x = np.array(["A", "B", "C", "D"])
y = np.array([3, 8, 1, 10])
#
#plt.bar(x,y, color='#A4B5C6',width=0.1)
#plt.show()
#
#x = np.array(["A", "B", "C", "D"])
#y = np.array([3, 8, 1, 10])
#

#plt.show()
#
#d={'Name':['A','B','C'],'Age':[20,22,24]}
#df = pd.DataFrame(d)
#x=df.Name
#y=df.Age
#plt.bar(x,y,color='red',width=0.2)
#print(df)

#x = np.random.normal(2, 50, 4)
#x=[23,22,30,35,20,43,45,33,44,55,60,25,35,45,50,43,33,34,54,45,43,44,55,25,36,38,32]
#x = np.random.normal(2,5,100)
# x=[]
# for i in range(1,50):
#     e= random.randint(25,55)
#     x.append(e)
# print(x)
# plt.hist(x)

# x = np.array([25,50,30,33,45,20])
fruits = ['Apple','Kiwi','Pinaple','Orange','Grapes','Banana']
price = [120,200,100,150,180,80]


# plt.bar(fruits, price)
# plt.xlabel('Fruits')
# plt.ylabel('Price')
# plt.title('Fruit price Bar Graph')
# plt.show()

marks = [55, 60, 65, 70, 70, 72, 75, 75, 78, 80, 82, 85, 88, 90, 92, 95, 95, 98]

# Create histogram
plt.hist(marks, bins=[50, 60, 70, 80, 90, 100], color='lightgreen', edgecolor='black')

# Add labels and title
plt.xlabel('Marks Range')
plt.ylabel('Number of Students')
plt.title('Distribution of Student Marks')

# Show the histogram
plt.show()

labels = ['Python', 'Java', 'C++', 'JavaScript']
sizes = [40, 25, 20, 15]
colors = ['#66b3ff', '#99ff99', '#ffcc99', '#ff9999']
explode = [0.1, 0.5, 0, 0]  # Explode first slice (Python)

# Create pie chart
plt.pie(
    sizes,
    labels=labels,
    colors=colors,
    explode=explode,
    autopct='%1.2f%%',
    startangle=180,
    shadow=True,
    counterclock=False,
    pctdistance=0.75,
    labeldistance=1.1,
    wedgeprops={'edgecolor': 'black'}
)
plt.title('Programming Language Popularity')
plt.show()


