import java.util.*;

class SeatNotAvailableException extends Exception {
    SeatNotAvailableException(String msg){
        super(msg);
    }
}

interface Reservation {
    public void bookTicket(int seats) throws SeatNotAvailableException;
    public void cancelTicket(int seats);
}

abstract class Flight {
    int flightNumber;
    String destination;
    int availableSeats;

    Flight(int flightNumber, String destination, int availableSeats){
        this.flightNumber=flightNumber;
        this.destination=destination;
        this.availableSeats=availableSeats;
    }

    abstract void display();
}

class DomesticFlight extends Flight implements Reservation {
    DomesticFlight(int flightNumber, String destination, int availableSeats){
        super(flightNumber, destination, availableSeats);
    }
    public void bookTicket(int seats) throws SeatNotAvailableException{
        if(seats>availableSeats) {
            throw new SeatNotAvailableException("Sorry Seat Not Available. only " + availableSeats + " Available");
        } else {
            availableSeats = availableSeats - seats;
            System.out.println(seats + " seat booked.");
        }
    }
    public void cancelTicket(int seats){
        availableSeats = availableSeats + seats;
        System.out.println(seats + " seat canceled.");
    }
    public void display(){
        System.out.println("\n\tFlight Details:");
        System.out.println("\t\tFlight Number: " + flightNumber);
        System.out.println("\t\tDestination: " + destination);
        System.out.println("\t\tAvailable Seats: " + availableSeats);
    }
}
class AirlineDemo {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);

        
        System.out.print("\n\tEnter Flight Number: ");
        int number = scan.nextInt();
        System.out.print("\n\tEnter Flight Destination: ");
        String destination = scan.next();
        System.out.print("\n\tEnter Flight Avalible Seats: ");
        int seat = scan.nextInt();

        DomesticFlight df = new DomesticFlight(number, destination, seat);

        try {
            System.out.print("\n\tHow many seat you want to book: ");
            int seatBook = scan.nextInt();
            df.bookTicket(seatBook);

            System.out.print("\n\tHow many seat you want to cancel: ");
            int cancelSeat = scan.nextInt();
            df.cancelTicket(cancelSeat);

            df.display();
        } catch (SeatNotAvailableException snae){
            System.out.println(snae.getMessage());
        }
    }
} 