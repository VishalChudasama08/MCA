from tkinter import *
w=Tk()
w.geometry('350x350')
w.title("calculator")
w.configure(bg='white')

val1=Entry(w,font=('verdana',14),width=15)
val1.place(x=30,y=20)
cls=Button(w,text='clear',font=('verdana',12),command=lambda:clear()).place(x=250,y=20)

def value(val):
    val1.insert(15,val)

def operation():
    data=eval(val1.get())
    val1.delete(0,'end')
    val1.insert(15,data)

def clear():
    val1.delete(0,'end')
    
b1=Button(w,text='1',font=('verdana',14),command=lambda:value('1')).place(x=30,y=70)
b2=Button(w,text='2',font=('verdana',14),command=lambda:value('2')).place(x=80,y=70)
b3=Button(w,text='3',font=('verdana',14),command=lambda:value('3')).place(x=125,y=70)
b4=Button(w,text='4',font=('verdana',14),command=lambda:value('4')).place(x=30,y=125)
b5=Button(w,text='5',font=('verdana',14),command=lambda:value('5')).place(x=80,y=125)
b6=Button(w,text='6',font=('verdana',14),command=lambda:value('6')).place(x=125,y=125)
b7=Button(w,text='7',font=('verdana',14),command=lambda:value('7')).place(x=30,y=180)
b8=Button(w,text='8',font=('verdana',14),command=lambda:value('8')).place(x=80,y=180)
b9=Button(w,text='9',font=('verdana',14),command=lambda:value('9')).place(x=125,y=180)
b0=Button(w,text='0',font=('verdana',14),command=lambda:value('0')).place(x=80,y=230)
bequal=Button(w,text='=',font=('verdana',14),width=5,command=lambda:operation()).place(x=120,y=230)
bplus=Button(w,text='+',font=('verdana',14),command=lambda:value('+')).place(x=200,y=70)
bminus=Button(w,text='-',font=('verdana',14),width=2,command=lambda:value('-')).place(x=200,y=125)
bdiv=Button(w,text='/',font=('verdana',14),width=2,command=lambda:value('/')).place(x=200,y=180)
bmul=Button(w,text='x',font=('verdana',14),width=2,command=lambda:value('*')).place(x=200,y=230)

