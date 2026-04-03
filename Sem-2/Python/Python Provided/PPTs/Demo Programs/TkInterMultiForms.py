# -*- coding: utf-8 -*-
"""
Created on Wed Mar 25 10:42:37 2026

@author: Administrator
"""

import tkinter as tk

def OnCheck():
    print(Cricket.get())

def onClick():
    def onBack():
        nw.destroy()  #hide the new window
        w.deiconify() #display the main window It reverses the action of withdraw()
        
    print(gender.get())  
    w.withdraw()
    nw = tk.Toplevel(w)  #Create a new window
    
    tk.Label(nw,text="thank you").pack()
    tk.Button(nw, text="Back", command=onBack).pack()


w = tk.Tk()  #create a main window

Cricket = tk.IntVar()
tk.Checkbutton(w,variable=Cricket, text="Cricket", command=OnCheck).pack()

gender = tk.StringVar(value="Male")
tk.Radiobutton(w,text="Male",variable=gender, value="Male").pack()
tk.Radiobutton(w,text="Female", variable=gender, value="Female").pack()

tk.Button(w, text="Display", command=onClick).pack()

w.mainloop()