# Practice test.docx
"""
4.	Consider the list of STATES that contains its Lok Sabha and Rajya Sabha seats as below:
{"MP": (29, 11), "UP": (80, 31), "TN": (39, 18) ,"MH": (48, 19) ,"GJ": (26, 11), "RJ": (25, 10), "HP": (4, 3) }
Create a menu driven program to find following data. Create user defined functions
•	Total number of seats in all given states.
•	Display the list in descending order of their Lok Sabha seats.
•	States having Least number of Rajya Sabha Seats

"""

d = {"MP": (29, 11), "UP": (80, 31), "TN": (39, 18) ,"MH": (48, 19) ,"GJ": (26, 11), "RJ": (25, 10), "HP": (4, 3) }
"""
for k in d:
    print(k+": Lok Sabha",d[k][0]," and Rajya Sabha",d[k][1])
"""    

print(d)

# •	Total number of seats in all given states.
totalseats = {}

for k in d:
    totalseats[k] = d[k][0]+d[k][1]
    
print("total seats as per state: ", totalseats)



# •	Display the list in descending order of their Lok Sabha seats.
Loklist = []
sortd={}

for k in d:
    Loklist.append(d[k][0])

sortloklist = sorted(Loklist, reverse=True)

for i in sortloklist:
    for k in d:
        if d[k][0]==i:
            sortd[k]=(d[k][0],d[k][1])
            break
                
print(sortd)

# •	States having Least number of Rajya Sabha Seats
 
