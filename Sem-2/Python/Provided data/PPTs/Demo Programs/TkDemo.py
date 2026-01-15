# -*- coding: utf-8 -*-
"""
Created on Fri Mar 28 10:20:11 2025

@author: Administrator
"""

import tkinter as tk

def OnClick():
    no1 = txt1.get()
    no2 = txt2.get()
    lbl1.config(text = no1)
    lbl2.config(text = no2)
    
w = tk.Tk()
w.title('Calc')
w.geometry('300x300')

lbl1 = tk.Label(w, text="Enter No 1:", font = ('Arial', 12))
lbl1.place(x=5,y=10)

txt1 = tk.Entry(w,width=20)
txt1.place(x=100, y=10)

txt2 = tk.Entry(w,width=20)
txt2.place(x=100, y=70)

lbl2 = tk.Label(w, text="Enter No 2:", font = ('Arial', 12))
lbl2.place(x=5,y=70)

btn = tk.Button(w, text="Add Numbers", command=OnClick)
btn.place(x=100, y=200)
w.mainloop()