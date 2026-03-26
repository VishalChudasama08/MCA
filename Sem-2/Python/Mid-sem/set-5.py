# mca sem-2 Mid semester set-5 A05

"""
Q-1 Write a Python program to input n email IDs and Create dictionary: Email as key
and Domain name as value
1. Display emails belonging to "gmail.com" in tuple.
2. Count emails from each domain.
3. Remove duplicate emails using set.
4. Display email IDs in sorted order.
"""


def create_dict(emails):
    d = {}
    for e in emails:
        parts = e.split("@")
        d[e] = parts[1]
    return d


def gmail_emails(emails):
    t = []
    for e in emails:
        parts = e.split("@")
        if parts[1] == "gmail.com":
            t.append(e)
    return tuple(t)


def count_domains(emails):
    d = {}
    for e in emails:
        parts = e.split("@")
        domain = parts[1]

        if domain in d:
            d[domain] = d[domain] + 1
        else:
            d[domain] = 1

    return d


def remove_duplicates(emails):
    return set(emails)


def sort_emails(emails):
    emails.sort()
    return emails


n = int(input("Enter number of emails: "))
emails = []

for i in range(n):
    emails.append(input("Enter email: "))


print("Email dictionary:", create_dict(emails))
print("Gmail emails:", gmail_emails(emails))
print("Domain count:", count_domains(emails))
print("Unique emails:", remove_duplicates(emails))
print("Sorted emails:", sort_emails(emails))


"""
Q-2 Write a Python program to manage Train Ticket Booking System using file
handling. Use functions to perform the given tasks
Accept details of 5 passengers:
1)
	1) Passenger ID
	2) Passenger Name
	3) Train Number
	4) Source Station
	5) Destination Station
	6) Ticket Fare
	7) Number of Seats Booked
2) Store in file Train_booking.txt.
3) Perform:
	1) Display all bookings for a particular train number (user input).
	2) Count total seats booked for each train.
	3) Calculate total fare collected for each train.
	4) Count the number of train starting from a given source station and
reaching a specific destination station
"""


def add_data():
    file = open("Train_booking.txt", "w")

    for i in range(5):
        print("\nEnter passenger details", i+1)

        pid = input("Passenger ID: ")
        name = input("Name: ")
        tno = input("Train Number: ")
        src = input("Source Station: ")
        dest = input("Destination Station: ")
        fare = float(input("Ticket Fare: "))
        seats = int(input("Seats Booked: "))

        file.write(pid + "," + name + "," + tno + "," + src + "," +
                   dest + "," + str(fare) + "," + str(seats) + "\n")

    file.close()


def display_data():
    file = open("Train_booking.txt", "r")
    data = file.readlines()

    bookings = []

    for line in data:
        b = line.strip().split(",")
        b[5] = float(b[5])
        b[6] = int(b[6])
        bookings.append(b)

    file.close()

    tno = input("\nEnter train number to search: ")
    print("\nBookings for train:", tno)

    for b in bookings:
        if b[2] == tno:
            print(b)

    seat_count = {}
    for b in bookings:
        t = b[2]
        if t in seat_count:
            seat_count[t] = seat_count[t] + b[6]
        else:
            seat_count[t] = b[6]

    print("\nTotal seats booked per train:")
    for t in seat_count:
        print(t, ":", seat_count[t])

    fare_count = {}
    for b in bookings:
        t = b[2]
        total = b[5] * b[6]

        if t in fare_count:
            fare_count[t] = fare_count[t] + total
        else:
            fare_count[t] = total

    print("\nTotal fare collected per train:")
    for t in fare_count:
        print(t, ":", fare_count[t])

    src = input("\nEnter source station: ")
    dest = input("Enter destination station: ")

    count = 0
    for b in bookings:
        if b[3] == src and b[4] == dest:
            count = count + 1

    print("\nNumber of bookings from", src, "to", dest, ":", count)


add_data()
display_data()
