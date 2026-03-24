# unit-4
"""
update data
"""

import mysql.connector

conn = mysql.connector.connect(host="localhost", port=3309, user="root", password="", database="python_db")

c = conn.cursor()

query = "UPDATE emp SET city='Junagadh' WHERE eno=106"

c.execute(query)
conn.commit()
print("data updated successfully")

conn.close()