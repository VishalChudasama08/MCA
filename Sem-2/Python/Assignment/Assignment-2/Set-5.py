"""
Q-1  Write a Python program to input n email IDs and Create dictionary: Email as key 
and Domain name as value 
1.  Display emails belonging to "gmail.com" in tuple. 
2.  Count emails from each domain. 
3.  Remove duplicate emails using set. 
4.  Display email IDs in sorted order. 
[20] 
"""

# Function 1: Create dictionary (email → domain)
def create_email_dict(emails):
    result = {}
    for email in emails:
        parts = email.split("@")
        if len(parts) == 2:
            result[email] = parts[1]
    return result


# Function 2: Gmail emails (tuple)
def gmail_emails(email_dict):
    return tuple([email for email, domain in email_dict.items() if domain == "gmail.com"])


# Function 3: Count emails per domain
def count_domains(email_dict):
    count = {}
    for domain in email_dict.values():
        count[domain] = count.get(domain, 0) + 1
    return count


# Function 4: Remove duplicates using set
def remove_duplicates(emails):
    return list(set(emails))


# Function 5: Sorted emails
def sorted_emails(emails):
    return sorted(emails)


# MAIN PROGRAM
n = int(input("Enter number of emails: "))
emails = []

for i in range(n):
    email = input(f"Enter email {i+1}: ")
    emails.append(email)

email_dict = create_email_dict(emails)

print("\nEmail Dictionary (email → domain):", email_dict)
print("\n1) Gmail Emails (tuple):", gmail_emails(email_dict))
print("\n2) Count of Emails per Domain:", count_domains(email_dict))
print("\n3) Emails after removing duplicates:", remove_duplicates(emails))
print("\n4) Emails in sorted order:", sorted_emails(remove_duplicates(emails)))


"""
Q-2  Write a Python program to manage Train Ticket Booking System using file 
handling. Use functions to perform the given tasks 
Accept details of 5 passengers: 
1)  Passenger ID 
2)  Passenger Name 
3)  Train Number 
4)  Source Station 
5)  Destination Station 
6)  Ticket Fare 
7)  Number of Seats Booked 
2)  Store in file Train_booking.txt. 
3) Perform: 
1)  Display all bookings for a particular train number (user input). 
2)  Count total seats booked for each train. 
3)  Calculate total fare collected for each train. 
4)  Count the number of train starting from a given source station and 
reaching a specific destination station 
[20] 
"""
def store_bookings():
    file = open("Train_booking.txt", "w")
    bookings = []

    for i in range(5):
        print(f"\nEnter details of Passenger {i+1}:")
        pid = input("Passenger ID: ")
        name = input("Passenger Name: ")
        train_no = input("Train Number: ")
        source = input("Source Station: ")
        dest = input("Destination Station: ")
        fare = float(input("Ticket Fare: "))
        seats = int(input("Seats Booked: "))

        booking = (pid, name, train_no, source, dest, fare, seats)
        bookings.append(booking)

        file.write(f"{pid},{name},{train_no},{source},{dest},{fare},{seats}\n")

    file.close()
    return bookings


def analyze_bookings(bookings):
    t_no = input("\nEnter train number to search: ")
    print("\n--- Bookings for Train ---")
    for b in bookings:
        if b[2] == t_no:
            print(b)

    seat_count = {}
    for b in bookings:
        train = b[2]
        seat_count[train] = seat_count.get(train, 0) + b[6]

    print("\n--- Total Seats per Train ---")
    print(seat_count)

    fare_total = {}
    for b in bookings:
        train = b[2]
        total = b[5] * b[6]
        fare_total[train] = fare_total.get(train, 0) + total

    print("\n--- Total Fare per Train ---")
    print(fare_total)

    src = input("\nEnter source station: ")
    dest = input("Enter destination station: ")
    count = 0

    for b in bookings:
        if b[3] == src and b[4] == dest:
            count += 1

    print("\n--- Number of matching bookings ---")
    print(count)


bookings = store_bookings()
analyze_bookings(bookings)