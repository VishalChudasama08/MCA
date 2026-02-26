import java.util.*;
class InvalidAgeException extends Exception{
	InvalidAgeException(String msg){
		super(msg);
	}
}
class Voter{
	String name;
	int age;
	Voter(){}
	Voter(String name,int age){
		this.name=name;
		this.age=age; 
	}
	public void checkEligibility() throws InvalidAgeException{
	if(age<18){
		throw new InvalidAgeException("age must be more than 18");
	}
	else{
		System.out.println("congratulation "+name+"you are eligible for Vote");
	}
	}
}
class VotingDemo
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter Name : ");
		String name=sc.nextLine();
		System.out.print("Enter Age : ");
		int age=sc.nextInt();
		
		try{
			Voter voter = new Voter(name,age);
			voter.checkEligibility();
		}
		catch(InvalidAgeException e){
			System.out.println(e.getMessage());
		}
		
	}
}