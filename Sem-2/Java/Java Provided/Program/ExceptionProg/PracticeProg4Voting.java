import java.util.*;
class InvalidAgeException extends Exception
{
	InvalidAgeException(String msg)
	{
		super(msg);
	}
} 
class Voter
{
	String name;
	int age;
	
	Voter(String name, int age)
	{
		this.name=name;
		this.age=age;
	}
	public void checkEligibility() throws InvalidAgeException
	{
		if(age < 18)
		{
			throw  new InvalidAgeException("Eligibility for Voting is 18 years");
		}
		else
		{
			System.out.println(" "+name+" you are Eligible for vot;ing");
		}
		
		
	}
}



class PracticeProg4Voting
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter name");
		String name = sc.next();
		
		System.out.print("Enter Age");
		int age = sc.nextInt();
		
		Voter v = new Voter(name,age);
		
		try
		{
			v.checkEligibility();
		}
		catch(InvalidAgeException e)
		{
			System.out.print(e.getMessage());
		}
		sc.close();
	}
}