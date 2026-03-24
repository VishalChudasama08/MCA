# unit-4
"""
insert
"""

import mysql.connector

conn = mysql.connector.connect(host="localhost", port=3309, user="root", password="", database="python_db")

c = conn.cursor()

eno = int(input("Enter employee no: "))
ename = input("Enter employee name: ")
city = input("Enter employee city: ")

data = (eno, ename, city)

query = "insert into emp values(%s, %s, %s)"

c.execute(query, data)

conn.commit()

print("\nValue inserted successfully")

conn.close()
