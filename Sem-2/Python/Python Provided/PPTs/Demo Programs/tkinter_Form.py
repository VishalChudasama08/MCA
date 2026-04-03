# -*- coding: utf-8 -*-
"""
Created on Tue Mar 24 06:17:54 2026

@author: Administrator
"""

import tkinter as tk
from tkinter import messagebox

# Function to handle submit button click
def submit_form():
    name = entry_name.get()
    email = entry_email.get()
    gender = gender_var.get()
    
    # Checkbox values
    skills = []
    if python_var.get():
        skills.append("Python")
    if java_var.get():
        skills.append("Java")
    if cpp_var.get():
        skills.append("C++")

    # Display result
    result = f"""
    Name: {name}
    Email: {email}
    Gender: {gender}
    Skills: {', '.join(skills)}
    """

    # Show in popup
    messagebox.showinfo("Submitted Data", result)

    # OR display in label
    result_label.config(text=result)


# Main window
root = tk.Tk()
root.title("User Entry Form")
root.geometry("400x500")

# Labels and Entry fields
tk.Label(root, text="Name").pack()
entry_name = tk.Entry(root)
entry_name.pack()

tk.Label(root, text="Email").pack()
entry_email = tk.Entry(root)
entry_email.pack()

# Radio Buttons (Gender)
tk.Label(root, text="Gender").pack()

gender_var = tk.StringVar(value="Male")

tk.Radiobutton(root, text="Male", variable=gender_var, value="Male").pack()
tk.Radiobutton(root, text="Female", variable=gender_var, value="Female").pack()


# Checkboxes (Skills)
tk.Label(root, text="Skills").pack()

python_var = tk.IntVar()
java_var = tk.IntVar()
cpp_var = tk.IntVar()

tk.Checkbutton(root, text="Python", variable=python_var).pack()
tk.Checkbutton(root, text="Java", variable=java_var).pack()
tk.Checkbutton(root, text="C++", variable=cpp_var).pack()

# Submit Button
tk.Button(root, text="Submit", command=submit_form).pack(pady=10)

# Label to display result
result_label = tk.Label(root, text="", justify="left")
result_label.pack()

# Run the application
root.mainloop()
