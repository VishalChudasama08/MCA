# GUI
"""
place(), string, textbox
"""

import tkinter as tk

root = tk.Tk()

root.title("String concate")
root.geometry("500x300")

def fullName():
    name = "xyz"
    
lblFName = tk.Label(root, text="Enter First Name:")
lblFName.place(x=10, y=10)



lblLName = tk.Label(root, text="Enter Last Name:")
lblLName.place(x=40, y=10)

lblMName = tk.Label(root, text="Enter Middle Name:")
lblMName.place(x=70, y=10)
 
