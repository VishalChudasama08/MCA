# -*- coding: utf-8 -*-
"""
Created on Wed Mar 18 10:00:13 2026

@author: Administrator
"""

import mysql.connector as con

conn = con.connect(host = "localhost",
                   user = "root",
                   password="",
                   port=3306,
                   database = "mydb")

print(conn)
'''
sql = "insert into t1 values(%s,%s,%s)"
no = int(input("Enter number of records you want to insert"))
'''
cur = conn.cursor()
'''
for i in range(no):
    rollno = int(input("Enter rollno"))
    name = input("Enter Name")
    cno = input("Enter contact number")
    values = (rollno,name,cno)
    cur.execute(sql,values)
'''
'''
with open("emp.txt","r") as file:
    #data = file.read()
    
    for i in file:
        l = i.split(" ")
        
        sql = "insert into t1 values(%s,%s,%s)"
        values = tuple(l)
        cur.execute(sql,values)
'''       
sql = "select * from t1"
cur.execute(sql)
rows = cur.fetchall()
print(rows)       
for row in rows:
    if str(row[2]).startswith('9'):
        print(row[1])
        
rno = int(input("Enter a number to delete"))
sql = "delete from t1 where no="+str(rno)
cur.execute(sql)
name1 = input("enter a name to change")
name2 = input("enter a new name")
sql = "update t1 set name= '" + name2 + "' where name = '" + name1 + "'"
cur.execute(sql)
conn.commit()
cur.close()
conn.close()