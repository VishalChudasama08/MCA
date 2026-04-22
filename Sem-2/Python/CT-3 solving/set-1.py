# CT-3 set-1
"""
1. Create a GUI to input patient details. (ID, Name, Age, Disease, Bill Amount)
2. Save records into a database.
3. Load records into a Pandas DataFrame.
    (Hint: df = pd.read_sql_query("SQL Statement / query", conn)
4. Display:
    o Total billing per disease
    o Patients above age 60
5. Plot:
    o Bar chart of patients per disease
    o Histogram of patient ages 
"""

import tkinter as tk
import mysql.connector
import pandas as pd

conn = mysql.connector.connect(
    host="localhost", port=3306, user="root", password="", database="python")


def loadByPandas():
    data = pd.read_sql_query("select * from patient", conn)
    df = pd.DataFrame(data)
    print(df)

    print("Total billing per disease:\n",
          df.groupby('Disease')['Bill_Amount'].sum())
    print("Patients above age 60:\n", df[df.Age > 60])


loadByPandas()


def removeData():
    txtID.delete(0, 'end')
    txtName.delete(0, 'end')
    txtAge.delete(0, 'end')
    txtDisease.delete(0, 'end')
    txtBillAmount.delete(0, 'end')


def submitForm():
    Id = txtID.get()
    name = txtName.get()
    age = txtAge.get()
    disease = txtDisease.get()
    billAmount = txtBillAmount.get()

    if len(Id) == 0 or len(name) == 0 or len(age) == 0 or len(disease) == 0 or len(billAmount) == 0:
        lblMsg.config(text="Please fill all fields", fg="red")
    else:
        cur = conn.cursor()

        data = (Id, name, int(age), disease, float(billAmount))

        lblMsg.config(text=data)

        query = "insert into patient values(%s, %s, %s, %s, %s)"
        cur.execute(query, data)
        conn.commit()

        lblMsg.config(text="data save successfully", fg="green")
        removeData()


root = tk.Tk()
root.title("Collect patient details form")
root.geometry("500x500")

tk.Label(root, text="Fill Patient Details",
         font=('Arial', 15)).place(x=60, y=20)
tk.Label(root, text="Enter patient ID: ").place(x=30, y=60)
txtID = tk.Entry(root, width=30)
txtID.place(x=180, y=60)

tk.Label(root, text="Enter patient Name: ").place(x=30, y=90)
txtName = tk.Entry(root, width=30)
txtName.place(x=180, y=90)

tk.Label(root, text="Enter patient Age: ").place(x=30, y=120)
txtAge = tk.Entry(root, width=30)
txtAge.place(x=180, y=120)

tk.Label(root, text="Enter patient Disease: ").place(x=30, y=150)
txtDisease = tk.Entry(root, width=30)
txtDisease.place(x=180, y=150)

tk.Label(root, text="Enter patient Bill Amount: ").place(x=30, y=180)
txtBillAmount = tk.Entry(root, width=30)
txtBillAmount.place(x=180, y=180)

tk.Button(root, text="submit", command=submitForm,
          width=10).place(x=100, y=230)
tk.Button(root, text="remove", command=removeData,
          width=10).place(x=200, y=230)

lblMsg = tk.Label(root, text="")
lblMsg.place(x=30, y=280)

root.mainloop()
conn.close()
