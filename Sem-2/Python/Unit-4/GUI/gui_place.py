# GUI
"""
place(), label, button, textbox
"""

import tkinter as tk


def OnClickAdd():
    n1 = txt1.get()
    n2 = txt2.get()
    ans = int(n1) + int(n2)
    lblAns.config(text = "Answer: " + str(ans))

def OnClickSub():
    n1 = txt1.get()
    n2 = txt2.get()
    ans = int(n1) - int(n2)
    lblAns.config(text = "Answer: " + str(ans))

def OnClickMul():
    n1 = txt1.get()
    n2 = txt2.get()
    ans = int(n1) * int(n2)
    lblAns.config(text = "Answer: " + str(ans))

def OnClickDiv():
    n1 = txt1.get()
    n2 = txt2.get()
    ans = int(n1) / int(n2)
    lblAns.config(text = "Answer: " + str(ans))
    
root = tk.Tk()

root.title("Use Place")
root.geometry("500x300")

lbl1 = tk.Label(root, text="Enter first number:", font=('Roboto', 10))
lbl1.place(x=10, y=10)

txt1 = tk.Entry(root, width=30)
txt1.place(x=160, y=10)

lbl2 = tk.Label(root, text="Enter second number:", font=('Arial', 10))
lbl2.place(x=10, y=40)

txt2 = tk.Entry(root, width=30)
txt2.place(x=160, y=40)

btnAdd = tk.Button(root, text="+", command=OnClickAdd, width=2, font=('Arial', 10, 'bold'))
btnAdd.place(x=30, y=80)
btnSub = tk.Button(root, text="-", command=OnClickSub, width=2, font=('Arial', 10, 'bold'))
btnSub.place(x=70, y=80)
btnMul = tk.Button(root, text="*", command=OnClickMul, width=2, font=('Arial', 10, 'bold'))
btnMul.place(x=110, y=80)
btnDiv = tk.Button(root, text="/", command=OnClickDiv, width=2, font=('Arial', 10, 'bold'))
btnDiv.place(x=150, y=80)

lblAns = tk.Label(root, text="", font=('Arial', 12, 'bold'))
lblAns.place(x=30, y=120)

root.mainloop()
