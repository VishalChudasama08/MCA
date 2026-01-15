from tkinter import *
import mysql.connector as con
db=con.connect(host='localhost',user='root',password='',database='student')
cur=db.cursor()

w=Tk()
w.geometry("400x400")
w.title('Name update')
w.configure(bg='orange')
def clicked():
    uid=int(e1.get())
    name=e2.get()
    data=(name,uid)
    sql="update stud set name='%s' where rollno=%d"
    cur.execute(sql %data)
    
    l3.configure(text="updated")
    w2=Tk()
    w2.geometry("350x350")
    lb=Label(w2,text="data updated.....",font=('verdana',15)).place(x=100,y=100)
    btn1=Button(w2,width=20,text="OK",command=w2.destroy)
    btn1.place(x=100,y=150)
def insert():
    uid=int(e1.get())
    name=e2.get()
    data=(uid,name)
    sql="insert into stud values(%d,'%s')"
    cur.execute(sql %data)
    l3.configure(text="inserted")

def delete():
    uid=int(e1.get())
    sql="delete from stud where rollno=%d"
    data=()
    data+=(uid,)
    cur.execute(sql %data)
    l3.configure(text="deleted")
    
l=Label(w,text='id',font=('courier',12),foreground='white',bg='black')
l.place(x=10,y=5)
e1=Entry(w,width=20,font=('courier',12))
e1.place(x=100,y=10)

l2=Label(w,text='Name',font=('courier',12),foreground='white',bg='black')
l2.place(x=10,y=40)
e2=Entry(w,width=20,font=('courier',12))
e2.place(x=100,y=40)

insertbtn=Button(w,text='Insert',bg='dodgerblue',foreground='white',font=('courier',12),command=insert).place(x=120,y=200)
deletebtn=Button(w,text='Delete',bg='dodgerblue',foreground='white',font=('courier',12),command=delete).place(x=200,y=200)
btn=Button(w,text='update',bg='dodgerblue',foreground='white',font=('courier',12),command=clicked).place(x=40,y=200)
l3=Label(w,text='data will be updated......',font=('verdana',12))
l3.place(x=50,y=300)

w.mainloop()
