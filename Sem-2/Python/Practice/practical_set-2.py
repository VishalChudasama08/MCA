"""
Set-2: Scenario: Movie Rating & Recommendation System
A streaming platform wants to analyze user ratings.
Develop a program using functions and menu that:
1.	Reads movie names and ratings from multiple users from an excel file. 
	Columns in the excel sheet :(UserId, MovieName, Rating(0-10))
2.	Calculates: 
	o	Average rating per movie 
	o	Top-rated movie 
	o	Display average rating given by each user
3.	Display the movie names in a descending order of ratings. 
4.	Show ratings using a bar chart or histogram. 
5.	Save the data analysis in the text file
"""

import pandas as pd
import matplotlib.pyplot as pl

data = pd.read_excel('movie_ratings.xlsx')

df = pd.DataFrame(data)

avg_rat_by_movie = df.groupby('MovieName')['Rating'].mean()
avg_rate_by_user = df.groupby('UserId')['Rating'].mean()

def read():
	print(df)

def avg():
	print("Average rating per movie: ")
	for k,v in avg_rat_by_movie.items():
		print(k, ":", f"{v:.2f}")

def topRate():
	name = avg_rat_by_movie.idxmax()
	top = avg_rat_by_movie.max()
	print("Top-rated movie:", name, "it average rate:", top)

def avgRate():
	print("Display average rating given by each user: ")
	for k,v in avg_rate_by_user.items():
		print("\tUserID:",k,"Average Rating:", f"{v:.2f}")

def movieNameDict():
	print("Display the movie names in a descending order of ratings\n",df.sort_values('Rating', ascending=False))

def chartHist():
	avgList = []
	nameList = []
	i = 0
	for k,v in avg_rat_by_movie.items():
		avgList.insert(i, round(float(v), 2))
		nameList.insert(i, k)
		i = i+1
		
	pl.bar(nameList, avgList)
	pl.title("Movie Average Rating Chart")
	pl.xlabel("Movie Name")
	pl.ylabel("Average Rating")
	pl.show()

	ratings = list(df["Rating"].values)
	# print(list(df["Rating"]))
	pl.hist(ratings, bins=[1,2,3,4,5,6,7,8,9,10,11])
	pl.show()

def saveData():
	f = open("Movie_Analysis_Report.txt", "w")
	f.write("--- Movie Analysis Report ---\n\n")
	f.write("Average Rating per Movie:\n")
	for k,v in avg_rat_by_movie.items():
		f.write(f"\t{k:<15} : {v:.2f}\n")

	f.write("\nTop Rated Movie:\n")
	name = avg_rat_by_movie.idxmax()
	top = avg_rat_by_movie.max()
	f.write(f"\t{name:<15} : {top:.2f}\n")

	f.write("\nAverage Rating per User:\n")
	for k,v in avg_rate_by_user.items():
		f.write(f"\tUserID: {k:<3} : {v:.2f}\n")

	f.close()
	print("Data save in file successfully\n")

def menu():	
	print("\n\t\t ====== Movie Rating & Recommendation System ====== ")
	print("0. Exit program")
	print("1. Read data")
	print("2. Average rating per movie")
	print("3. Top-rated movie")
	print("4. Display average rating given by each user")
	print("5. Display the movie names in a descending order of ratings")
	print("6. Show ratings using a bar chart or histogram. ")
	print("7. Save the data analysis in the text file")
	try:
		return int(input("Enter: "))
	except:
		return 8



while(True):
	x = menu()
	if x == 0: exit("Bye!")
	elif x == 1: read()
	elif x == 2: avg()
	elif x == 3: topRate()
	elif x == 4: avgRate()
	elif x == 5: movieNameDict()
	elif x == 6: chartHist()
	elif x == 7: saveData()
	else : print("Enter valid number from menu!")

