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
  Voter(){}
  Voter(String name,int age){
     this.name=name;
	 this.age=age;
  }
  public void checkEligibility() throws InvalidAgeException
  {
	if(age <18)
	{
		throw new InvalidAgeException("Age must be greater then 18");

		}
	else
	{
		System.out.println(name + " YOu are eligible for voting...");
	}
  }
  public void display()
  {
	System.out.print("\n\t Name ::"+name);
	System.out.print("\n\t Age ::"+age);
  }
}
class VotingDemo
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
			
		try
		{
			System.out.print("\n Enter Name : ");
			String name=sc.next();
			System.out.print("\n Enter Age : ");
			int age=sc.nextInt();
			
			Voter vobj = new Voter(name,age);
			
			vobj.checkEligibility();
			
			vobj.display();
		}
		catch(InvalidAgeException ie)
		{
			System.out.print("\n"+ie.getMessage());
		}
	}
}