"""
1. Create a GUI to input patient details. (ID, Name, Age, Disease, Bill Amount) 2. Save records into a database.  3. Load records into a Pandas DataFrame.  (Hint: df = pd.read_sql_query("SQL Statement / query", conn) 4. Display:  
o Total billing per disease  
o Patients above age 60  5. Plot:  
o Bar chart of patients per disease  
o Histogram of patient ages
"""
import mysql.connector
import pandas as pd
import tkinter as tk
from tkinter import messagebox
import matplotlib.pyplot as plt

conn = mysql.connector.connect(
    host="localhost", port=3306, user="root", password="", database="hospital")
cursor = conn.cursor()

cursor.execute(
    'CREATE TABLE IF NOT EXISTS patients (id INTEGER,name TEXT,age INTEGER,disease TEXT,bill REAL)')
conn.commit()


def insert_data():
    data = (
        id_entry.get(),
        name_entry.get(),
        age_entry.get(),
        disease_entry.get(),
        bill_entry.get()
    )

    cursor.execute("INSERT INTO patients VALUES (?, ?, ?, ?, ?)", data)
    conn.commit()
    messagebox.showinfo("Success", "Record Inserted Successfully")

    id_entry.delete(0, tk.END)
    name_entry.delete(0, tk.END)
    age_entry.delete(0, tk.END)
    disease_entry.delete(0, tk.END)
    bill_entry.delete(0, tk.END)


def analyze_data():
    df = pd.read_sql_query("SELECT * FROM patients", conn)

    print("\n--- Complete Data ---")
    print(df)

    print("\n--- Total Billing per Disease ---")
    billing = df.groupby('disease')['bill'].sum()
    print(billing)

    print("\n--- Patients Above Age 60 ---")
    senior_patients = df[df['age'] > 60]
    print(senior_patients)

    patient_count = df.groupby('disease')['id'].count()
    patient_count.plot(kind='bar')
    plt.title("Number of Patients per Disease")
    plt.xlabel("Disease")
    plt.ylabel("Count")
    plt.show()

    df['age'].plot(kind='hist')
    plt.title("Age Distribution of Patients")
    plt.xlabel("Age")
    plt.ylabel("Frequency")
    plt.show()


root = tk.Tk()
root.title("Hospital Management System")
root.geometry("400x300")

tk.Label(root, text="Patient ID").grid(row=0, column=0)
tk.Label(root, text="Name").grid(row=1, column=0)
tk.Label(root, text="Age").grid(row=2, column=0)
tk.Label(root, text="Disease").grid(row=3, column=0)
tk.Label(root, text="Bill Amount").grid(row=4, column=0)

id_entry = tk.Entry(root)
name_entry = tk.Entry(root)
age_entry = tk.Entry(root)
disease_entry = tk.Entry(root)
bill_entry = tk.Entry(root)

id_entry.grid(row=0, column=1)
name_entry.grid(row=1, column=1)
age_entry.grid(row=2, column=1)
disease_entry.grid(row=3, column=1)
bill_entry.grid(row=4, column=1)

tk.Button(root, text="Insert Record",
          command=insert_data).grid(row=5, column=0)
tk.Button(root, text="Analyze Data",
          command=analyze_data).grid(row=5, column=1)

root.mainloop()
