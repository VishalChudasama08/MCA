# -*- coding: utf-8 -*-
"""
Created on Tue Feb 24 04:53:21 2026

@author: Administrator
"""

import mysql.connector

conn = mysql.connector.connect(host="localhost",
                               port=3309,
                               user="root",
                               password="",
                               database="mydb")
#print(conn)

sql="select * from t1"
cur = conn.cursor()
cur.execute(sql)

rows = cur.fetchall()
for row in rows:
    print(row[1])

sql = "insert into t1(no,name) values(%s, %s)"
'''
n = int(input("Enter a number"))
name = input("Enter a name")
vals = (n, name)
cur.execute(sql,vals)
'''
vals = [(5,'Sweta'),(6,'Raj'),(7,'Akshay')]
cur.executemany(sql, vals)
conn.commit()

cur.close()
conn.close()