import java.util.*;
interface Reservation
{
	public void bookTicket(int seats) throws SeatNotAvailableException; //abstract method
	public void cancelTicket(int seats);

}
//custom Exception

class SeatNotAvailableException extends Exception
{
	SeatNotAvailableException(String msg)
	{
		super(msg);
	}
} 

abstract class Flight
{
	String flightNumber, destination;
	int	availableSeats;
	Flight(){//default
	}
	Flight(String flightNumber,String destination,int availableSeats){//Parameterized constructor
	
		this.flightNumber = flightNumber;
		this.destination = destination;
		this.availableSeats = availableSeats;
		
	}
	abstract public void display(); //abstrct -no method body
	
	
}
class DomesticFlight extends Flight implements Reservation
{
	DomesticFlight(String flightNumber,String destination,int availableSeats)
	{
		super(flightNumber,destination,availableSeats);
	}
	
	public void bookTicket(int seats) throws SeatNotAvailableException //abstract method body
	{
		if(seats > availableSeats)
		{
			throw new  SeatNotAvailableException("Seats not available.....");
		}
		else
		{
			availableSeats -= seats;
			System.out.print("\n\n\t" + seats +" booked successfully...");
		}
	}
	public void cancelTicket(int seats)
	{
		availableSeats += seats;
		System.out.print("\n\n\t" + seats +" canceled successfully...");
		System.out.print("\n\n\t Available seats..."+availableSeats);
	}
	public void display()
	{
		System.out.print("\n\n\t----------------Airline Reservation System--------------\n");
		System.out.print("\n\n\t\tFlight no::" + flightNumber);
		System.out.print("\n\n\t\tDestination::" + destination);
		System.out.print("\n\n\t Available seats::"+availableSeats);
	}
}
class Prog3AirLine
{
	public static void main(String args[]) 
	{
	
		try
		{
			int ch,seats;
			Scanner sc = new Scanner(System.in);
			System.out.print("\n\n\tEnter Flight Number::");
			String flightNumber=sc.next();
			System.out.print("\n\n\tEnter Flight Destination::");
			String destination=sc.next();
			System.out.print("\n\n\tEnter Available seats::");
			int availableSeats=sc.nextInt();
			
			DomesticFlight dobj=new DomesticFlight(flightNumber,destination,availableSeats);
			
			dobj.display();
			do
			{
				System.out.print("\n\n\t1. Book Ticket.");
				System.out.print("\n\n\t2. Cancel Ticket.");
				System.out.print("\n\n\t3. Exit!.");
				
				System.out.print("\n\n\t Enter Your Choice : ");
				ch=sc.nextInt();
				
				switch(ch)
				{
					case 1:
						System.out.print("\n\n\t1. Enter no. of Seats : ");
						seats=sc.nextInt();
						dobj.bookTicket(seats);
						dobj.display();
						break;
					case 2:
						System.out.print("\n\n\t1. Enter no. of Seats : ");
						seats=sc.nextInt();
						dobj.cancelTicket(seats);
						dobj.display();
						break;
					case 3:
						System.out.print("\n\n\t1. Thank you ");
						System.exit(0);
						
					
				}
				
				
			}while(ch!=3);
		}
		catch(SeatNotAvailableException ie)
		{
			System.out.print("In Catch:"+ie);
		}
	}
}