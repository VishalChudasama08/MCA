# GUI
"""
Create form and display submited data
name, email, gender, hobbies
button submit this enter data on file as dictnory
"""

import tkinter as tk
import mysql.connector

def saveDB():
    conn = mysql.connector.connect(host="localhost", post=3309, user="root", password="", database="python_db")
    
    cur = conn.cursor()
    
    name = txtName.get()
    email = txtEmail.get()
    gender = rbGender.get()
    contry = cv.get()
    h = []
    
    if cbGame.get():
        h.append("Game")
    if cbMovie.get():
        h.append("Movie")
    if cbTravel.get():
        h.append("Travel")
    if cbDance.get():
        h.append("Dance")
        
    data = ()
    query = "insert into emp values(%s, %s, %s)"
    cur.execute(query, data)
    conn.commit()
    print("\nValue inserted successfully")
    conn.close()
    
def submitData():
    name = txtName.get()
    email = txtEmail.get()
    gender = rbGender.get()
    contry = cv.get()
    h = []
    
    if cbGame.get():
        h.append("Game")
    if cbMovie.get():
        h.append("Movie")
    if cbTravel.get():
        h.append("Travel")
    if cbDance.get():
        h.append("Dance")
    
    print(h)
    result = f"""
    Name: {name}
    Email: {email}
    Gender: {gender}
    Hobbies: {', '.join(h)}
    Contry: {contry}
    """
    lblAnswer.config(text=result)
    f = open('formData.txt', 'w')
    f.write(result)
    

    
root = tk.Tk()
root.title("Form Demo")
root.geometry("600x400")


tk.Label(root, text="Enter your name:", font=('Arial', 10)).place(x=10, y=10)
txtName = tk.Entry(root, width=30)
txtName.place(x=150, y=10)

tk.Label(root, text="Enter your email:", font=('Arial', 10)).place(x=10, y=40)
txtEmail = tk.Entry(root, width=30)
txtEmail.place(x=150, y=40)

tk.Label(root, text="Select Your Gender:", font=('Arial', 10)).place(x=10, y=70)
rbGender = tk.StringVar(value=('Male'))
tk.Radiobutton(root, text="Male", value="Male", variable=rbGender).place(x=150, y=70)
tk.Radiobutton(root, text="Female", value="Female", variable=rbGender).place(x=200, y=70)


tk.Label(root, text="Select Your Hobbies:", font=('Arial', 10)).place(x=10, y=100)
cbGame = tk.IntVar()
cbMovie = tk.IntVar()
cbTravel = tk.IntVar()
cbDance = tk.IntVar()
tk.Checkbutton(root, text="Game", variable=cbGame).place(x=150, y=100)
tk.Checkbutton(root, text='Movie', variable=cbMovie).place(x=220, y=100)
tk.Checkbutton(root, text='Travel', variable=cbTravel).place(x=290, y=100)
tk.Checkbutton(root, text='Dance', variable=cbDance).place(x=360, y=100)

tk.Label(root, text="Select Your contry:", font=('Arial', 10)).place(x=10, y=130)
list_of_cntry = ['India', 'Canada', 'US', 'Germany', 'UK']
cv = tk.StringVar()
cv.set("select your contry")
dropList = tk.OptionMenu(root, cv, *list_of_cntry)
dropList.config(width=30)
dropList.place(x=150, y=130)




tk.Button(root, text='submit', command=submitData, width=10, font=('Arial', 10, 'bold')).place(x=60, y=200)

tk.Button(root, text='Save in DB', command=saveDB, width=15, font=('Arial', 10, 'bold')).place(x=180, y=200)

lblAnswer = tk.Label(root, text='', font=('Arial', 11, 'bold'))
lblAnswer.place(x=60, y=250)

root.mainloop()
