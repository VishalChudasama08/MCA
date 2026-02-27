"""
Q-2 Write a Python program to develop a Hotel Reservation System with the following requirements:
	•	Store details of N rooms using a list of dictionaries, where each room has: room number, room type, price per day, and availability status 
	•	Display details of all available rooms 
	•	Display room number and price as a tuple for rooms of a given room type 
	•	Identify and display the room(s) having the maximum price per day.
	•	Allow booking of a room using room number and update the availability status
"""

# rooms = []
# n = int(input("Enter total rooms number:"))
# for i in range(0, n):
#     rn = int(input("Enter room number:"))
#     rt = input("Enter room type:")
#     ppd = int(input("Enter price per day:"))
#     avs = input("Enter availability status (true/false):")
#     rooms.append({'rn': rn, 'rt': rt, 'ppd': ppd, 'as': avs})

# print(rooms)

rooms = [
    {'rn': 101, 'rt': 'ac', 'ppd': 800, 'as': 'true'},
    {'rn': 102, 'rt': 'non-ac', 'ppd': 500, 'as': 'true'},
    {'rn': 103, 'rt': 'non-ac', 'ppd': 500, 'as': 'false'},
    {'rn': 104, 'rt': 'ac', 'ppd': 800, 'as': 'true'},
    {'rn': 106, 'rt': 'ac', 'ppd': 500, 'as': 'false'}
]

for i in rooms:
    if i['as'] == 'true':
        print(i)
