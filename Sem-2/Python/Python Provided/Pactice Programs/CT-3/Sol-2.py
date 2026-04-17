# -*- coding: utf-8 -*-
"""
Created on Tue Apr  7 12:43:05 2026

@author: Administrator
"""

import sqlite3
import pandas as pd
import tkinter as tk
from tkinter import messagebox
import matplotlib.pyplot as plt

# ---------------- DATABASE SETUP ----------------
conn = sqlite3.connect("ipl_players.db")
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS players (
    player_name TEXT,
    team TEXT,
    match_id INTEGER,
    runs_scored INTEGER,
    balls_faced INTEGER,
    wickets_taken INTEGER
)
""")
conn.commit()

# ---------------- GUI FUNCTION ----------------
def insert_data():
    data = (
        player_entry.get(),
        team_entry.get(),
        match_entry.get(),
        runs_entry.get(),
        balls_entry.get(),
        wickets_entry.get()
    )

    cursor.execute("INSERT INTO players VALUES (?, ?, ?, ?, ?, ?)", data)
    conn.commit()
    messagebox.showinfo("Success", "Record Inserted")

    # Clear fields
    player_entry.delete(0, tk.END)
    team_entry.delete(0, tk.END)
    match_entry.delete(0, tk.END)
    runs_entry.delete(0, tk.END)
    balls_entry.delete(0, tk.END)
    wickets_entry.delete(0, tk.END)


# ---------------- ANALYSIS FUNCTION ----------------
def analyze_data():
    df = pd.read_sql_query("SELECT * FROM players", conn)

    print("\n--- Complete Data ---")
    print(df)

    # ✅ Strike Rate of each player
    print("\n--- Strike Rate of Players ---")
    df['strike_rate'] = (df['runs_scored'] / df['balls_faced']) * 100
    strike_rate = df.groupby('player_name')['strike_rate'].mean()
    print(strike_rate)

    # ✅ Top 5 players based on runs
    print("\n--- Top 5 Players by Runs ---")
    top_players = df.groupby('player_name')['runs_scored'].sum().sort_values(ascending=False).head(5)
    print(top_players)

    # ---------------- PLOTTING ----------------
    
    # Bar Chart: Total Runs by Player
    total_runs = df.groupby('player_name')['runs_scored'].sum()
    total_runs.plot(kind='bar')
    plt.title("Total Runs by Player")
    plt.xlabel("Player")
    plt.ylabel("Runs")
    plt.show()

    # Line Graph: Wickets Taken by Player
    wickets = df.groupby('player_name')['wickets_taken'].sum()
    wickets.plot(kind='line', marker='o')
    plt.title("Wickets Taken by Player")
    plt.xlabel("Player")
    plt.ylabel("Wickets")
    plt.show()


# ---------------- GUI SETUP ----------------
root = tk.Tk()
root.title("IPL Player Performance System")

# Labels
tk.Label(root, text="Player Name").grid(row=0, column=0)
tk.Label(root, text="Team").grid(row=1, column=0)
tk.Label(root, text="Match ID").grid(row=2, column=0)
tk.Label(root, text="Runs Scored").grid(row=3, column=0)
tk.Label(root, text="Balls Faced").grid(row=4, column=0)
tk.Label(root, text="Wickets Taken").grid(row=5, column=0)

# Entry Fields
player_entry = tk.Entry(root)
team_entry = tk.Entry(root)
match_entry = tk.Entry(root)
runs_entry = tk.Entry(root)
balls_entry = tk.Entry(root)
wickets_entry = tk.Entry(root)

player_entry.grid(row=0, column=1)
team_entry.grid(row=1, column=1)
match_entry.grid(row=2, column=1)
runs_entry.grid(row=3, column=1)
balls_entry.grid(row=4, column=1)
wickets_entry.grid(row=5, column=1)

# Buttons
tk.Button(root, text="Insert Record", command=insert_data).grid(row=6, column=0)
tk.Button(root, text="Analyze Data", command=analyze_data).grid(row=6, column=1)

# Run GUI
root.mainloop()