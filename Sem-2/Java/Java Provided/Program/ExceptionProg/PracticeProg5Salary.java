import java.util.*;
 class InvalidSalaryException extends Exception
{
	InvalidSalaryException( String msg)
	{
		super(msg);
	}
	
} 

 class Employee{
	int empid;
	String name;
	double salary;
	Employee(int empid,String name)
	{
		this.empid = empid;
		this.name = name;
		
	}
	public void setSalary(double salary) throws InvalidSalaryException
	{
		if(salary < 0)
		{
			throw new InvalidSalaryException("Salary can't be Negative...");
		}
		else
		{
			this.salary = salary;
			
		}
		
	}
	public void display()
	{
			System.out.print("\n\t--------------Employee Information-------------\n");
			System.out.println("empid"+empid);
			System.out.println("name"+name);
			System.out.println("salary"+salary);
	}
 }

 
class PracticeProg5Salary
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("\n\tEnter name");
		String name=sc.next();
		System.out.println("\n\tEnter empid");
		int empid=sc.nextInt();
		System.out.println("\n\tEnter Salary");
		double salary=sc.nextDouble();
		
		Employee e=new Employee(empid,name);
		try
		{
			e.setSalary(salary);
			e.display();
		}
		catch(InvalidSalaryException ie){
		System.out.println(ie.getMessage());
		
		}
		
	}
}