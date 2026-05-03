"""
Set-1: Scenario: Fitness Activity Monitor
A fitness trainer wants to track client activity.
Build a program using functions and menu that:
1.	Accepts daily step count of each user for a week.(use any data structure / object)
2.	Calculates: 
	o	Total steps of each user
	o	Average steps taken by all users per day
	o	Highest and lowest activity day of each user
3.	Displays a summary for each user. 
4.	Plot a weekly activity graph and save the image
5.	Store the data in a file / database
"""

import matplotlib.pyplot as pl
import mysql.connector

# fitness_data = {}
fitness_data = {'vishal': [1000, 2000, 3000, 4000, 5000, 1234, 1432], 'kavit': [123, 321, 231, 321, 312, 213, 132], 'raju': [1000, 2000, 3000, 4000, 5000, 6000, 7000]}
fitness_all_data = {}

def getDay(d):
	days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
	return days[d]

def calculates():
	total_step = 0
	for k, v in fitness_data.items():
		for j in v:
			total_step = total_step + j
		highest_day = getDay(v.index(max(v)))
		lowest_day = getDay(v.index(min(v)))
		fitness_all_data[k] = [v, total_step, total_step/7, highest_day, lowest_day]
		total_step = 0

def accept_data():
	name = input("Enter user name: ")
	day1 = int(input("Enter step count for day 1: "))
	day2 = int(input("Enter step count for day 2: "))
	day3 = int(input("Enter step count for day 3: "))
	day4 = int(input("Enter step count for day 4: "))
	day5 = int(input("Enter step count for day 5: "))
	day6 = int(input("Enter step count for day 6: "))
	day7 = int(input("Enter step count for day 7: "))
	fitness_data[name] = [day1, day2, day3, day4, day5, day6, day7]
	calculates()
		

def summary():
	# calculates()
	days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
	print(f"{'#':<3} {'Name':<10} {'Mon':<6}{'Tue':<6}{'Wed':<6}{'Thu':<6}{'Fri':<6}{'Sat':<6}{'Sun':<6} {'Total':<8} {'Average':<8} {'Highest':<8} {'Lowest':<8}")
	i = 1
	for k,v in fitness_all_data.items():
		print(f"{i:<3} {k:<10} {v[0][0]:<6}{v[0][1]:<6}{v[0][2]:<6}{v[0][3]:<6}{v[0][4]:<6}{v[0][5]:<6}{v[0][6]:<6} {v[1]:<8} {v[2]:<8.2f} {v[3]:<8} {v[4]:<8}")
		i = i+1


def plot_graph():
	days = ["Mon","Tue","Wed","Thu","Fri","Sat","Sun"]

	pl.title("Weekly Fitness Activity")
	pl.xlabel("Days")
	pl.ylabel("Steps")

	for k, v in fitness_data.items():
		pl.plot(days, v, marker='o')
		pl.text(days[-1], v[-1], f"      {k}")

	# pl.savefig("weekly_activity.png")
	pl.show()


def saveData():
	# calculates()
	f = open("Fitness_Activity_Monitor.txt", 'w')
	f.write("\t\t ====== Fitness Activity Monitor ====== \n\n")
	f.write("----------------------------------------------------------------------------------------------------\n")
	f.write(f"|{'#':<3}|{'Name':<10}|{'Mon':<6}|{'Tue':<6}|{'Wed':<6}|{'Thu':<6}|{'Fri':<6}|{'Sat':<6}|{'Sun':<6}|{'Total':<8}|{'Average':<8}|{'Highest':<8}|{'Lowest':<8}\n")
	f.write("----------------------------------------------------------------------------------------------------\n")
	i = 1
	for k,v in fitness_all_data.items():
		f.write(f"|{i:<3}|{k:<10}|{v[0][0]:<6}|{v[0][1]:<6}|{v[0][2]:<6}|{v[0][3]:<6}|{v[0][4]:<6}|{v[0][5]:<6}|{v[0][6]:<6}|{v[1]:<8}|{v[2]:<8.2f}|{v[3]:<8}|{v[4]:<8}\n")
		i = i+1 
	f.write("----------------------------------------------------------------------------------------------------\n")
	print("Data Saved in File successfully")
	f.close()

	conn = mysql.connector.connect(host="localhost", port=3306, username="root", password="", database="python")
	cur = conn.cursor()
	cur.execute("CREATE TABLE IF NOT EXISTS Fitness_Activity_Monitor (id int, name varchar(100), week_day text, total int, Average float, Highest varchar(8), Lowest varchar(8))")
	conn.commit()

	i = 1
	for k,v in fitness_all_data.items():
		cur.execute("INSERT INTO Fitness_Activity_Monitor values (%s, %s, %s, %s, %s, %s, %s)", (i, k, str(v[0]), v[1], v[2], v[3], v[4]))
		i = i + 1
		conn.commit()
	print("Data Inserted in Database Successfully")
	conn.close()


def menu():
	print("\n\t\t ====== Fitness Activity Monitor ======")
	print("0. exit program")
	print("1. Add user")
	print("2. Show Summary")
	print("3. Plot Graph")
	print("4. Save Data")
	try:
		return int(input("Enter: "))
	except:
		return 5



users = int(input("Enter how many users: "))
# data = {'vishal': [100, 200, 300, 400, 500, 600, 700], 'kavit': [110, 120, 130, 140, 150, 160, 170]}

for i in range(users):
	accept_data()

while(True):
	x = menu()

	if x == 0: exit("Bye!")
	elif x == 1: accept_data()
	elif x == 2: summary()
	elif x == 3: plot_graph()
	elif x == 4: saveData()
	else : print("Enter valid number from menu")

