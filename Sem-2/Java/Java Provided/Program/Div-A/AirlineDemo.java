import java.util.*;
class SeatNotAvailableException extends Exception
{
	SeatNotAvailableException(String msg)
	{
		super(msg);
	}
}
interface Reservation
{
	public void bookTicket(int seats) throws SeatNotAvailableException; //abstract method so no method body
	public void cancelTicket(int seats);

}
abstract class Flight
{
	String flightNumber, destination;
	int availableSeats;
	
	Flight(String flightNumber,String destination,int availableSeats)//constructor
	{
		this.flightNumber = flightNumber;
		this. destination = destination;
		this.availableSeats = availableSeats;
	}
	abstract public void display();
	
}

class DomesticFlight extends Flight implements Reservation
{
	DomesticFlight(String flightNumber,String destination,int availableSeats)
	{
		super(flightNumber,destination,availableSeats);
	}
	public void bookTicket(int seats) throws SeatNotAvailableException 
	{
		availableSeats -= seats;
		System.out.print("\n\n\t"+seats+ "  booked successfully...");
	}
	public void cancelTicket(int seats)
	{
		availableSeats += seats;
		System.out.print("\n\n\t"+seats+ "  cancel successfully...");
	}
	public void display()
	{	
		System.out.print("\n\tFlight Number:"+flightNumber);
		System.out.print("\n\tFlight Destination:"+destination);
		System.out.print("\n\tAvailable seaths:"+availableSeats);
	}
}
class AirlineDemo
{
	public static void main(String args[])
	{
	/*try{
		/*Scanner sc=new Scanner(System.in);
		System.out.print("Emp id");
		String empid=sc.nextLine();
		System.out.print("name");
		String name=sc.nextLine();
		System.out.print("salary");
		int salary=sc.nextInt();
	
		Employee e=new Employee(empid,name);
		e.setSalary(salary);
		e.display();
	}
	catch(SeatNotAvailableException ie)
	{
		System.out.print(ie.getMessage());
	}*/
	}
}
