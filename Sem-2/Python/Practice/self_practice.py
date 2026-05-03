"""
Student Registration form
"""

import tkinter as tk
from tkinter import messagebox
import mysql.connector 

def toggleSubmit():
	if agreeCheck.get() == 1:
		submitButton.config(state="normal")
	else :
		submitButton.config(state="disabled")


def validate(name, rollNumber, address, hobbies, gender, division):
	if len(name) == 0: 
		messagebox.showwarning("Warning", "Enter Student name") 
		return False
	if len(rollNumber) == 0: 
		messagebox.showwarning("Warning", "Enter Roll Number")
		return False
	if len(address) <= 1: 
		messagebox.showwarning("Warning", "Enter Address")
		return False
	if len(hobbies) == 0: 
		messagebox.showwarning("Warning", "Select at least one hobby")
		return False
	if len(gender) == 0: 
		messagebox.showwarning("Warning", "Select Gender")
		return False
	if len(division) == 0: 
		messagebox.showwarning("Warning", "Select Division")
		return False
	return True

def saveOnDB(name, rollNumber, address, hobbies, gender, division):
	if not validate(name, rollNumber, address, hobbies, gender, division):
		return

	# print("not good")
	conn = mysql.connector.connect(host="localhost", port=3306, username="root", password="", database="python")
	cur = conn.cursor()
	
	cur.execute("CREATE TABLE IF NOT EXISTS student ( id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(100), rollNumber INT, address TEXT, hobbies VARCHAR(255), gender ENUM('Male', 'Female'), division VARCHAR(50))")
	conn.commit()
	
	hobbies = ', '.join(hobbies)
	address = address.strip()

	data = (name, int(rollNumber), address, hobbies, gender, division)
	print(data, "Inserted in DB")
	cur.execute("INSERT INTO student (name, rollNumber, address, hobbies, gender, division) VALUES(%s, %s, %s, %s, %s, %s)", data)
	conn.commit()

	resultLabel.config(text="Add data submit and save successfully")
	clearData()
	cur.close()
	conn.close()

def saveData():
	name = nameEntry.get()
	rollNumber = rollNumberEntry.get()
	address = addressEntry.get("1.0", "end")

	hobbies = []

	if cbGame.get():
		hobbies.append("Game")
	if cbMovie.get():
		hobbies.append("Movie")
	if cbTravel.get():
		hobbies.append("Travel")

	gender = ""
	if genderRadioButton.get() != "None": gender = genderRadioButton.get()
	
	division = ""
	if divisionVar.get() != "Select":
		division = divisionVar.get()

	saveOnDB(name, rollNumber, address, hobbies, gender, division)

	# print(name, rollNumber, address, hobbies, gender, division)
	
def clearData():
    nameEntry.delete(0, tk.END)
    rollNumberEntry.delete(0, tk.END)
    addressEntry.delete("1.0", tk.END)
    cbGame.set(0)
    cbMovie.set(0)
    cbTravel.set(0)
    genderRadioButton.set("None")
    divisionVar.set("Select")
    agreeCheck.set(0)
    submitButton.config(state="disabled")

frame = tk.Tk()
frame.title("Student Registration Form")
frame.geometry("600x600")

tk.Label(frame, text="Student Registration Form", font=("Arial", 14)).place(x=180, y=12)

tk.Label(frame, text="Enter Student Name: ").place(x=80, y=60)
tk.Label(frame, text="Enter Student Roll Number: ").place(x=80, y=100)
tk.Label(frame, text="Enter Student Address: ").place(x=80, y=140)
tk.Label(frame, text="Enter Student Hobbies: ").place(x=80, y=220)
tk.Label(frame, text="Select Student Gender: ").place(x=80, y=260)
tk.Label(frame, text="Select Student Division: ").place(x=80, y=300)


nameEntry = tk.Entry(frame, width=30)
nameEntry.place(x=260, y=60)

rollNumberEntry = tk.Entry(frame, width=30)
rollNumberEntry.place(x=260, y=100)

addressEntry = tk.Text(frame, width=22, height=4)
addressEntry.place(x=260, y=140)

cbGame = tk.IntVar()
cbMovie = tk.IntVar()
cbTravel = tk.IntVar()
hobbiesCheckButtonGame = tk.Checkbutton(frame, text="Game", variable=cbGame).place(x=260, y=220)
hobbiesCheckButtonMovie = tk.Checkbutton(frame, text="Movie", variable=cbMovie).place(x=340, y=220)
hobbiesCheckButtonTravel = tk.Checkbutton(frame, text="Travel", variable=cbTravel).place(x=420, y=220)

genderRadioButton = tk.StringVar(value="None")
# genderRadioButton.set("")
genderRadioButtonMale = tk.Radiobutton(frame, text="Male", variable=genderRadioButton, value="Male")
genderRadioButtonMale.place(x=260, y=260)
genderRadioButtonFemale = tk.Radiobutton(frame, text="Female", variable=genderRadioButton, value="Female")
genderRadioButtonFemale.place(x=340, y=260)

divisionVar = tk.StringVar()
divisionVar.set("Select")
options = ["A", "B", "C", "D", "E"]
dropdown = tk.OptionMenu(frame, divisionVar, *options)
dropdown.place(x=260, y=300)

agreeCheck = tk.IntVar()
agreeCheckButton = tk.Checkbutton(frame, text="I Am Agree", variable=agreeCheck, command=toggleSubmit)
agreeCheckButton.place(x=100, y=360)

submitButton = tk.Button(frame, text="Submit", command=saveData, width=10, state="disabled")
submitButton.place(x=222, y=360)

clearButton = tk.Button(frame, text="Clear", command=clearData, width=10)
clearButton.place(x=360, y=360)

resultLabel = tk.Label(frame, text="", font=("Arial", 10))
resultLabel.place(x=100, y=444)

frame.mainloop()
