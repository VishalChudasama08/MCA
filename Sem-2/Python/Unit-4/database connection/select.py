# Unit-4
"""
display record
"""

import mysql.connector

conn = mysql.connector.connect(host="localhost", port=3309, user="root", password="", database="python_db")

c = conn.cursor()

query = "select * from emp"

c.execute(query)

rows = c.fetchall()

for row in rows:
    print(row)

conn.close()