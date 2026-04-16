import java.util.*;
class SeatNotAvailableException extends Exception{
	SeatNotAvailableException(String msg){
		super(msg);
	}
}
interface Reservation{
	public void bookTicket(int seats) throws SeatNotAvailableException;
	public void cancelTicket(int seats);

}

abstract class Flight
{
	String flightNumber;
	int availableSeats;
	String destination;
	
	Flight(String flightNumber, int availableSeats,String destination)
	{
		this.flightNumber=flightNumber;
		this.availableSeats=availableSeats;
		this.destination=destination;
		
	}
	abstract public void display();//abstract method

}
class  DomesticFlight extends Flight implements Reservation
{

	DomesticFlight(String flightNumber, int availableSeats,String destination)
	{
		super(flightNumber,availableSeats,destination);
	}
	public void bookTicket(int seats) throws SeatNotAvailableException{
		if(seats > availableSeats)
		{
			throw new SeatNotAvailableException("Seats not available...");
		}
		else
		{
			availableSeats -= seats;
			System.out.print("\n\t\t"+seats+" booked successfully...");
			
		}
		
	}
	public void cancelTicket(int seats){
			availableSeats += seats;
			System.out.print("\n\t\t"+seats+" Cancel successfully...");
			
	}
	public void display()	{
		System.out.print("\n\n\tFlight No  ::" +flightNumber);
		System.out.print("\n\n\tAvailable Seats ::" +availableSeats);
		System.out.print("\n\n\tDestination  ::" +destination);
	}
	
}
class AirlineDemo
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int choice,seats;
		System.out.print("\n\n\tEnter  Flight No  ::" );
		String flightNumber=sc.next(); //read string
		
		System.out.print("\n\n\tEnter Available Seats ::" );
		int availableSeats=sc.nextInt(); //read int value
		
		System.out.print("\n\n\tEnter Destination  ::" );
		String destination=sc.next();
		
		DomesticFlight dobj = new DomesticFlight(flightNumber,availableSeats,destination);//call constructor
		
		do
		{
		System.out.print("\n\n\t1 Book Ticket ");
		System.out.print("\n\n\t2 Cancel Ticket ");
		System.out.print("\n\n\t3 Display ");
		System.out.print("\n\n\t\t Enter Your choice:: ");
		choice=sc.nextInt();
		
		switch(choice)
		{
			case 1:
				try
				{
					System.out.print("\n\n\tEnter how many  Seats u want to book ::" );
					seats =sc.nextInt(); //read int value
					
					dobj.bookTicket(seats);
					dobj.display();
				}
				catch(SeatNotAvailableException se)
				{
					System.out.print("\n\t"+se.getMessage());
				}
				break;
			case 2:
					System.out.print("\n\n\tEnter how many  Seats u want to cancel ::" );
					seats =sc.nextInt(); //read int value
					dobj.cancelTicket(seats);// call domestic class method cancel ticket
					dobj.display();
			
				break;
			case 3:
					dobj.display();
				break;
			case 4:
				System.exit(0);
				
		}
	}while(choice!= 4);
	}
}

