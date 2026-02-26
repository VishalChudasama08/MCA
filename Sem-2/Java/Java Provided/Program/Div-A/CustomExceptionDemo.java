import java.util.*;
class InvalidAgeException extends  Exception
{
	InvalidAgeException(String msg)
	{
		super(msg);
	}
}
class CustomExceptionDemo
{
	public static void main(String args[])
	{
		try
		{
			Scanner sc = new Scanner(System.in);
			System.out.print("\n\n\tEnter Age::");
			int age = sc.nextInt();
			
			if(age <=0 || age>=120)
			{
				throw new InvalidAgeException("Age cant't be negative or more than 120....");
			}
			else
			{
				System.out.print("\n\tAge is::"+age);
			}
		}
		catch(InvalidAgeException ie)
		{
			System.out.print(ie.getMessage());
		}
	}
}