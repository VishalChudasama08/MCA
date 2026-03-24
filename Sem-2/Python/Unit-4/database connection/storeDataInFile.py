# unit-4
"""
store data in text file
"""

import mysql.connector

conn = mysql.connector.connect(host="localhost", port=3309, user="root", password="", database="python_db")

c = conn.cursor()

query = "select * from emp"

c.execute(query)

rows = c.fetchall()


f = open("data.txt", "w")

for row in rows:
    f.write(str(row[0]) + "\t" + row[1] + "\t" + row[2] + "\n")
    
print("store all data in data.txt file successfully")
f.close()

conn.close()