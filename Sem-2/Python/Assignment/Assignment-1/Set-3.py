"""
1. Create a GUI to input:  
 Match ID, Team Name, Runs Scored, Wickets Lost, Overs Played, Result (Win/Loss)  2. Store the data into a database.  3. Load data into a Pandas DataFrame.  4. Display:  
 Average runs scored by each team  
 Win percentage of each team  5. Plot:  
 Bar chart of win percentage by team  
 Histogram of runs scored 
"""

import mysql.connector
import pandas as pd
import tkinter as tk
from tkinter import messagebox
import matplotlib.pyplot as plt

conn = mysql.connector.connect(
    host="localhost", port=3306, user="root", password="", database="ipl")
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

    match_id_entry.delete(0, tk.END)
    team_entry.delete(0, tk.END)
    runs_entry.delete(0, tk.END)
    wickets_entry.delete(0, tk.END)
    overs_entry.delete(0, tk.END)
    result_entry.delete(0, tk.END)


def analyze_data():
    df = pd.read_sql_query("SELECT * FROM matches", conn)

    print("\n--- Complete Data ---")
    print(df)

    print("\n--- Average Runs by Team ---")
    avg_runs = df.groupby('team_name')['runs_scored'].mean()
    print(avg_runs)

    print("\n--- Win Percentage by Team ---")
    
    total_matches = df.groupby('team_name')['match_id'].count()
    wins = df[df['result'].str.lower() == 'win'].groupby('team_name')['match_id'].count()

    win_percentage = (wins / total_matches) * 100
    win_percentage = win_percentage.fillna(0)  # handle teams with no wins
    print(win_percentage)

    win_percentage.plot(kind='bar')
    plt.title("Win Percentage by Team")
    plt.xlabel("Team")
    plt.ylabel("Win %")
    plt.show()

    df['runs_scored'].plot(kind='hist')
    plt.title("Distribution of Runs Scored")
    plt.xlabel("Runs")
    plt.ylabel("Frequency")
    plt.show()


root = tk.Tk()
root.title("IPL Analysis System")
root.geometry("400x300")

tk.Label(root, text="Match ID").grid(row=0, column=0)
tk.Label(root, text="Team Name").grid(row=1, column=0)
tk.Label(root, text="Runs Scored").grid(row=2, column=0)
tk.Label(root, text="Wickets Lost").grid(row=3, column=0)
tk.Label(root, text="Overs Played").grid(row=4, column=0)
tk.Label(root, text="Result (Win/Loss)").grid(row=5, column=0)

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

tk.Button(root, text="Insert Record", command=insert_data).grid(row=6, column=0)
tk.Button(root, text="Analyze Data", command=analyze_data).grid(row=6, column=1)

root.mainloop()