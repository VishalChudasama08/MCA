// Unit-3 interfacesProgram.docx program-2

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
    Passenger(){}
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
    GeneralPassenger(String name, int age, String gender, int seatNumber, String coachType){
        super(name, age, gender);
        this.seatNumber = seatNumber;
        this.coachType = coachType;
    }
    public void displayDetails() { // Displays passenger information
        System.out.println("Passenger Infomation:\nName: " + name + "\tAge: " + age + "\tGender: " + gender + "Seat Number: " + seatNumber + "\tCoach Type: " + coachType);
    } 
    public void reserveTicket(){
        System.out.println("Ticket Reserved Successfully (General Class)");
    }
    public void cancelTicket(){
        System.out.println("Ticket Cancelled Successfully");
    }
}

class TatkalPassenger extends Passenger implements Reservable, Cancellable {
    public int seatNumber;
    public double extraCharges;

    TatkalPassenger(String name, int age, String gender, int seatNumber, double extraCharges){
        super(name, age, gender);
        this.seatNumber = seatNumber;
        this.extraCharges = extraCharges;
    }

    public void displayDetails() { // Displays passenger information
        System.out.println("Passenger Infomation:\nName: " + name + "\tAge: " + age + "\tGender: " + gender + "Seat Number: " + seatNumber + "\tCoach Type: " + extraCharges);
    } 
    public void reserveTicket(){
        System.out.println("Reserves ticket under Tatkal quota");
    }
    public void cancelTicket(){
        System.out.println("Cancels the ticket (with applicable deduction)");
    }
}
class RailwayReservationSystem {
    public static void main(String [] args){
        GeneralPassenger gp = new GeneralPassenger("vishal", 23, "male", 5, "General Class");
        gp.reserveTicket();
        gp.displayDetails();
        gp.cancelTicket();

        System.out.println();

        TatkalPassenger tp = new TatkalPassenger("ayush", 21, "male", 4, 123);
        tp.reserveTicket();
        tp.displayDetails();
        tp.cancelTicket();
    }
}