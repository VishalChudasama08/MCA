// Unit-3 program-2

interface Reservable{
    public void reserveTicket(); // Used for reserving tickets.
}

interface Cancellable{
    public void cancelTicket(); // Used for cancelling tickets.
}

abstract class Passenger{
    public String name;
    public int age;
    public String gender;

    Passenger(String name, int age, String gender){
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    abstract public void displayDetails();
}
class GeneralPassenger extends Passenger implements Reservable, Cancellable { // extends abstract class and implements all interface
    public int seatNumber;
    public String coachType;
    public void displayDetails() { // Displays passenger information
        System.out.println("Passenger Infomation:\nName: " + name + "\tAge: " + age + "\tGender: " + gender);
        System.out.println("Seat Number: " + seatNumber + "\tCoach Type: " + coachType);
    } 
    public void reserveTicket(){
        System.out.println("Reserves a general class seat // Ticket Reserved Successfully (General Class)")
    }
 }
class RailwayReservationSystem {
    public static void main(String [] args){

    }
}