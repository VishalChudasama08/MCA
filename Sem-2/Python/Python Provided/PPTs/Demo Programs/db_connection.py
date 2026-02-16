# -*- coding: utf-8 -*-
"""
Created on Thu Mar 20 10:03:06 2025

@author: Administrator
"""

import mysql.connector as con
import pandas as pd

# Establish connection
conn = con.connect(
    host="localhost",      # Change to your MySQL server (default: localhost)
    user="root",  # Your MySQL username
    password="",  # Your MySQL password
    database="MyDB"   # Name of your database
)

# Check if connection is successful
if conn.is_connected():
    print("Connected to MySQL Database")

cursor = conn.cursor()

#q = "delete from students"  
cursor.execute('Select * from t1');
row = cursor.fetchall()
df = pd.read_sql_query('Select * from t1', conn)
print(df)

print(row)
#query = "INSERT INTO t1 VALUES (%s, %s)"
#values = [(22,"Alice"), (20,"Bob")]

#cursor.executemany(query, values)  # Insert multiple records

conn.commit()  # Save changes
print(cursor.rowcount, "record(s) inserted.")
# Close the connection
conn.close()
