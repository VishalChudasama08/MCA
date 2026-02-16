import sqlite3
import pandas as pd
import matplotlib.pyplot as plt

# 1. Create SQLite connection and cursor
conn = sqlite3.connect("coaching.db")
cursor = conn.cursor()

# 2. Create the COACHING table
cursor.execute("""
CREATE TABLE IF NOT EXISTS COACHING (
    ID TEXT,
    Name TEXT,
    Age INTEGER,
    City TEXT,
    Fees INTEGER,
    Mobile TEXT
)
""")

# 3. Insert records into the table
data = [
    ('P1', 'Sameer', 34, 'Delhi', 45000, '9811076656'),
    ('P2', 'Aryan', 35, 'Mumbai', 54000, '9911343989'),
    ('P3', 'Ram', 34, 'Chennai', 45000, '9810593578'),
    ('P4', 'Lata', 36, 'Bhopal', 60000, '9910139987'),
    ('P5', 'Shikha', 36, 'Indoore', 34000, '9912139456'),
    ('P6', 'Radha', 33, 'Delhi', 23000, '8110668888'),
]

# Clear old data and insert new
cursor.execute("DELETE FROM COACHING")
cursor.executemany("INSERT INTO COACHING VALUES (?, ?, ?, ?, ?, ?)", data)
conn.commit()

# 4. Generate DataFrame from SQL
df = pd.read_sql_query("SELECT * FROM COACHING", conn)
print(df)

# 5. Bar graph: Student-wise fees
plt.figure(figsize=(8, 5))
plt.bar(df['Name'], df['Fees'], color='skyblue')
plt.title('Student-wise Fees')
plt.xlabel('Name')
plt.ylabel('Fees')
plt.grid(axis='y')
plt.tight_layout()
plt.show()

# 6. Histogram: Age distribution
plt.figure(figsize=(6, 4))
plt.hist(df['Age'], bins=5, color='orange', edgecolor='black')
plt.title('Age Distribution')
plt.xlabel('Age')
plt.ylabel('Frequency')
plt.tight_layout()
plt.show()

# Close the connection
conn.close()
