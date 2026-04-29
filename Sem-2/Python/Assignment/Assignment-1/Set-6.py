"""
1. Create a GUI to input: (Hospital ID, Patient Name, Disease, Age, Bill Amount) 
2. Store the records in a database table. 
3. Load data into a Pandas DataFrame from the database. 
4. Perform and Display: 
	o Total billing per disease 
	o Patients above age 60 
	o Sort patients by bill amount (descending) 
5. Plot: 
	o Bar chart of total billing per disease 
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
cursor.execute("""
CREATE TABLE IF NOT EXISTS patients (
	hospital_id INTEGER,
	patient_name TEXT,
	disease TEXT,
	age INTEGER,
	bill_amount REAL
)
""")

def insert_data():
	data = (
		hospital_id_entry.get(),
		patient_name_entry.get(),
		disease_entry.get(),
		age_entry.get(),
		bill_amount_entry.get()
	)

	cursor.execute("INSERT INTO patients VALUES (?, ?, ?, ?, ?)", data)
	conn.commit()
	messagebox.showinfo("Success", "Record Inserted Successfully")

	hospital_id_entry.delete(0, tk.END)
	patient_name_entry.delete(0, tk.END)
	disease_entry.delete(0, tk.END)
	age_entry.delete(0, tk.END)
	bill_amount_entry.delete(0, tk.END)

def analyze_data():
	df = pd.read_sql_query("SELECT * FROM patients", conn)

	print("\n--- Complete Data ---")
	print(df)

	print("\n--- Total Billing per Disease ---")
	billing = df.groupby('disease')['bill_amount'].sum()
	print(billing)

	print("\n--- Patients Above Age 60 ---")
	senior_patients = df[df['age'] > 60]
	print(senior_patients)

	print("\n--- Patients Sorted by Bill Amount (Descending) ---")
	sorted_patients = df.sort_values(by='bill_amount', ascending=False)
	print(sorted_patients)

	billing.plot(kind='bar')
	plt.title("Total Billing per Disease")
	plt.xlabel("Disease")
	plt.ylabel("Total Billing")
	plt.show()

	df['age'].plot(kind='hist', bins=10)
	plt.title("Histogram of Patient Ages")
	plt.xlabel("Age")
	plt.ylabel("Frequency")
	plt.show()

root = tk.Tk()
root.title("Hospital Patient Records")
root.geometry("400x300")

tk.Label(root, text="Hospital ID").grid(row=0, column=0)
tk.Label(root, text="Patient Name").grid(row=1, column=0)
tk.Label(root, text="Disease").grid(row=2, column=0)
tk.Label(root, text="Age").grid(row=3, column=0)
tk.Label(root, text="Bill Amount").grid(row=4, column=0)

hospital_id_entry = tk.Entry(root)
patient_name_entry = tk.Entry(root)
disease_entry = tk.Entry(root)
age_entry = tk.Entry(root)
bill_amount_entry = tk.Entry(root)
hospital_id_entry.grid(row=0, column=1)
patient_name_entry.grid(row=1, column=1)
disease_entry.grid(row=2, column=1)
age_entry.grid(row=3, column=1)
bill_amount_entry.grid(row=4, column=1)

tk.Button(root, text="Insert Record", command=insert_data).grid(row=5, column=0)
tk.Button(root, text="Analyze Data", command=analyze_data).grid(row=5, column=1)

root.mainloop()