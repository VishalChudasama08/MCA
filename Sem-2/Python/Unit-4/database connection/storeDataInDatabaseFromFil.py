# Unit-4
"""
insert all file data into database table
"""

import mysql.connector

conn = mysql.connector.connect(host="localhost", port=3309, user="root", password="", database="python_db")

c = conn.cursor()

f = open("data.txt", "r")

for r in f:
    value = r.split("\t")
    value[2] = value[2][:-1]
    r=tuple(value)
    print(r)
    query="insert into emp2 values(%s, %s, %s)"
    c.execute(query, r)

print("All data inserted in database")
conn.commit()

f.close()
conn.close()
