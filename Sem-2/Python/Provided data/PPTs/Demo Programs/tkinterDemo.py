# -*- coding: utf-8 -*-
"""
Created on Tue Mar 25 11:32:14 2025

@author: Administrator
"""

import tkinter as tk

def on_click():
    lbl.config(text="Button Clicked")
    print(txt.get())
w = tk.Tk()
w.title("Demo")
w.geometry("500x500")

txt = tk.Entry()
txt.pack()
lbl = tk.Label(bg="yellow",fg="red", text="Enter a Number")
lbl.pack()
btn = tk.Button(text="Click", command=on_click)
btn.pack()
w.mainloop()