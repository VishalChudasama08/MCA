# -*- coding: utf-8 -*-
"""
bar
barh
histogram
"""
import matplotlib.pyplot as pl
student = ["Vishal", "Abhay", "Kalpesh", "Hitesh", "Bhavesh", "Nitin"]
marks = [95, 75, 88, 66, 54, 78]

pl.bar(student, marks, width=0.5, color="gray")
pl.xlabel("Student's")
pl.ylabel("Marks")
pl.title("Student marks bar graph")      
pl.show()

student = ["Vishal", "Abhay", "Kalpesh", "Hitesh", "Bhavesh", "Nitin"]
marks = [95, 75, 88, 66, 54, 78]

# horizontal bar
pl.barh(student, marks, height=0.5, color="gray")
pl.xlabel("Student's")
pl.ylabel("Marks")
pl.title("Student marks bar graph")      
pl.show()


# create histogram
m = [20,24,29,31,33,36,37,41,52,55,58,72,73,77,82,84,86,88,95,95]
pl.hist(m, bins=[10,20,30,40,50,60,70,80,90,100], color="yellow", edgecolor="red")
pl.show()
