# -*- coding: utf-8 -*-
"""
Created on Tue Apr  7 12:26:35 2026

@author: Administrator
"""

import sqlite3
import pandas as pd
import tkinter as tk
from tkinter import messagebox
import matplotlib.pyplot as plt

# ---------------- DATABASE SETUP ----------------
conn = sqlite3.connect("ipl.db")
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS matches (
    match_id INTEGER,
    team_name TEXT,
    runs_scored INTEGER,
    wickets_lost INTEGER,
    overs_played REAL,
    result TEXT
)
""")
conn.commit()

# ---------------- GUI FUNCTION ----------------
def insert_data():
    data = (
        match_id_entry.get(),
        team_entry.get(),
        runs_entry.get(),
        wickets_entry.get(),
        overs_entry.get(),
        result_entry.get()
    )

    cursor.execute("INSERT INTO matches VALUES (?, ?, ?, ?, ?, ?)", data)
    conn.commit()
    messagebox.showinfo("Success", "Record Inserted")

    # Clear fields
    match_id_entry.delete(0, tk.END)
    team_entry.delete(0, tk.END)
    runs_entry.delete(0, tk.END)
    wickets_entry.delete(0, tk.END)
    overs_entry.delete(0, tk.END)
    result_entry.delete(0, tk.END)


# ---------------- ANALYSIS FUNCTION ----------------
def analyze_data():
    df = pd.read_sql_query("SELECT * FROM matches", conn)

    print("\n--- Complete Data ---")
    print(df)

    # ✅ Average runs by team
    print("\n--- Average Runs by Team ---")
    avg_runs = df.groupby('team_name')['runs_scored'].mean()
    print(avg_runs)

    # ✅ Win Percentage calculation
    print("\n--- Win Percentage by Team ---")
    
    total_matches = df.groupby('team_name')['match_id'].count()
    wins = df[df['result'].str.lower() == 'win'].groupby('team_name')['match_id'].count()

    win_percentage = (wins / total_matches) * 100
    win_percentage = win_percentage.fillna(0)  # handle teams with no wins
    print(win_percentage)

    # ---------------- PLOTTING ----------------
    
    # Bar Chart: Win Percentage
    win_percentage.plot(kind='bar')
    plt.title("Win Percentage by Team")
    plt.xlabel("Team")
    plt.ylabel("Win %")
    plt.show()

    # Histogram: Runs Scored
    df['runs_scored'].plot(kind='hist')
    plt.title("Distribution of Runs Scored")
    plt.xlabel("Runs")
    plt.ylabel("Frequency")
    plt.show()


# ---------------- GUI SETUP ----------------
root = tk.Tk()
root.title("IPL Analysis System")

# Labels
tk.Label(root, text="Match ID").grid(row=0, column=0)
tk.Label(root, text="Team Name").grid(row=1, column=0)
tk.Label(root, text="Runs Scored").grid(row=2, column=0)
tk.Label(root, text="Wickets Lost").grid(row=3, column=0)
tk.Label(root, text="Overs Played").grid(row=4, column=0)
tk.Label(root, text="Result (Win/Loss)").grid(row=5, column=0)

# Entry Fields
match_id_entry = tk.Entry(root)
team_entry = tk.Entry(root)
runs_entry = tk.Entry(root)
wickets_entry = tk.Entry(root)
overs_entry = tk.Entry(root)
result_entry = tk.Entry(root)

match_id_entry.grid(row=0, column=1)
team_entry.grid(row=1, column=1)
runs_entry.grid(row=2, column=1)
wickets_entry.grid(row=3, column=1)
overs_entry.grid(row=4, column=1)
result_entry.grid(row=5, column=1)

# Buttons
tk.Button(root, text="Insert Record", command=insert_data).grid(row=6, column=0)
tk.Button(root, text="Analyze Data", command=analyze_data).grid(row=6, column=1)

# Run GUI
root.mainloop()