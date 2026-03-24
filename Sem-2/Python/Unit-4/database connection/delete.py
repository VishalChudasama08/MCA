# Unit-4
"""
delete
"""

import mysql.connector

conn = mysql.connector.connect(host="localhost", port=3309, user="root", password="", database="python_db")

c = conn.cursor()

eno = int(input("Enter employee no for delete: "))

data = (eno)

query = "delete from emp where eno=%s"

c.execute(query, eno)

conn.commit()

print("Record Deleted successfully")

conn.close()