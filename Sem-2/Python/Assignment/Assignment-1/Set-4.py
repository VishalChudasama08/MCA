"""
1. Create a GUI form to input:  
 Student ID, Student Name, Book Title, Genre, Days Issued  2. Store the data in a database.  3. Load the data into a Pandas DataFrame.  4. Display:  
 Most issued books (top records)  
 Students who issued books for more than 10 days  5. Plot:  
 Bar chart of number of books issued per genre  
 Pie chart showing genre distribution 
"""

import mysql.connector
import pandas as pd
import tkinter as tk
from tkinter import messagebox
import matplotlib.pyplot as plt

conn = mysql.connector.connect(
    host="localhost", port=3306, user="root", password="", database="library")
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS library (
    student_id INTEGER,
    student_name TEXT,
    book_title TEXT,
    genre TEXT,
    days_issued INTEGER
)
""")
conn.commit()

def insert_data():
    data = (
        student_id_entry.get(),
        student_name_entry.get(),
        book_entry.get(),
        genre_entry.get(),
        days_entry.get()
    )

    cursor.execute("INSERT INTO library VALUES (?, ?, ?, ?, ?)", data)
    conn.commit()
    messagebox.showinfo("Success", "Record Inserted Successfully")

    student_id_entry.delete(0, tk.END)
    student_name_entry.delete(0, tk.END)
    book_entry.delete(0, tk.END)
    genre_entry.delete(0, tk.END)
    days_entry.delete(0, tk.END)


def analyze_data():
    df = pd.read_sql_query("SELECT * FROM library", conn)

    print("\n--- Complete Data ---")
    print(df)

    print("\n--- Most Issued Books ---")
    top_books = df.groupby('book_title')['student_id'].count().sort_values(ascending=False)
    print(top_books)

    print("\n--- Students with Books Issued > 10 Days ---")
    long_issues = df[df['days_issued'] > 10]
    print(long_issues)

    genre_count = df.groupby('genre')['book_title'].count()

    genre_count.plot(kind='bar')
    plt.title("Number of Books Issued per Genre")
    plt.xlabel("Genre")
    plt.ylabel("Count")
    plt.show()

    genre_count.plot(kind='pie', autopct='%1.1f%%')
    plt.title("Genre Distribution")
    plt.ylabel("")
    plt.show()


root = tk.Tk()
root.title("Library Management System")
root.geometry("400x300")

tk.Label(root, text="Student ID").grid(row=0, column=0)
tk.Label(root, text="Student Name").grid(row=1, column=0)
tk.Label(root, text="Book Title").grid(row=2, column=0)
tk.Label(root, text="Genre").grid(row=3, column=0)
tk.Label(root, text="Days Issued").grid(row=4, column=0)

student_id_entry = tk.Entry(root)
student_name_entry = tk.Entry(root)
book_entry = tk.Entry(root)
genre_entry = tk.Entry(root)
days_entry = tk.Entry(root)

student_id_entry.grid(row=0, column=1)
student_name_entry.grid(row=1, column=1)
book_entry.grid(row=2, column=1)
genre_entry.grid(row=3, column=1)
days_entry.grid(row=4, column=1)

tk.Button(root, text="Insert Record", command=insert_data).grid(row=5, column=0)
tk.Button(root, text="Analyze Data", command=analyze_data).grid(row=5, column=1)

root.mainloop()