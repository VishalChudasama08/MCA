# GUI 
"""
simple python gui program, pack()
"""

import tkinter as tk

w = tk.Tk();

w.title("Python GUI Demo")
w.geometry("600x400")


label1 = tk.Label(bg="white", fg="black", text="Enter your name: ")
label1.pack()

txtbox1 = tk.Entry()
txtbox1.pack()

button1 = tk.Button(text="Click")
button1.pack()

w.mainloop()


