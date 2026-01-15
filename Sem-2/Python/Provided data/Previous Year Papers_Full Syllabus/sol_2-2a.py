# State dictionary with (Lok Sabha seats, Rajya Sabha seats)
STATES = {
    "MP": (29, 11),
    "UP": (80, 31),
    "TN": (39, 18),
    "MH": (48, 19),
    "GJ": (26, 11),
    "RJ": (25, 10),
    "HP": (4, 3)
}

# Function 1: Total number of seats
def total_seats(states):
    total_lok = sum(seats[0] for seats in states.values())
    total_rajya = sum(seats[1] for seats in states.values())
    print(f"\nTotal Lok Sabha Seats: {total_lok}")
    print(f"Total Rajya Sabha Seats: {total_rajya}")
    print(f"Grand Total Seats: {total_lok + total_rajya}\n")

# Function 2: Display states in descending order of Lok Sabha seats
def sort_by_lok_sabha(states):
    sorted_states = sorted(states.items(), key=lambda x: x[1][0], reverse=True)
    print("\nStates sorted by Lok Sabha seats (descending):")
    for state, seats in sorted_states:
        print(f"{state} -> Lok Sabha: {seats[0]}, Rajya Sabha: {seats[1]}")
    print()

# Function 3: Find states with the least Rajya Sabha seats
def least_rajya_seats(states):
    min_rajya = min(seats[1] for seats in states.values())
    least_states = [state for state, seats in states.items() if seats[1] == min_rajya]
    print(f"\nStates with the least Rajya Sabha seats ({min_rajya} seats): {', '.join(least_states)}\n")

# Menu-driven logic
def main():
    while True:
        print("====== MENU ======")
        print("1. Total number of seats")
        print("2. List in descending order of Lok Sabha seats")
        print("3. States with least number of Rajya Sabha seats")
        print("4. Exit")

        choice = input("Enter your choice (1-4): ")

        if choice == '1':
            total_seats(STATES)
        elif choice == '2':
            sort_by_lok_sabha(STATES)
        elif choice == '3':
            least_rajya_seats(STATES)
        elif choice == '4':
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please select from 1 to 4.\n")

# Run the program
main()
