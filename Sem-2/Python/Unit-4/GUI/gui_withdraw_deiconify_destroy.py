# GUI
"""
withdraw()
deiconify()
destroy()
"""

import tkinter as tk

root = tk.Tk()

root.title("Demo")
root.geometry("400x150")

def onSubmit():
    name = txtName.get()
    def onBack():
        nw.destroy()
        root.deiconify()
        
    root.withdraw()
    nw = tk.Toplevel(root)
    nw.title("New window")
    nw.geometry("150x150")
    tk.Label(nw, text="Name: "+name).pack()
    tk.Label(nw, text="Thank you").pack()
    tk.Button(nw, text="Back", command=onBack).pack()

tk.Label(root, text="Enter name: ").place(x=10, y=10)
txtName = tk.Entry(root, width=30)
txtName.place(x=110, y=10)

btnSubmit = tk.Button(root, text="submit", command=onSubmit, width=10)
btnSubmit.place(x=30, y=50)

root.mainloop()
