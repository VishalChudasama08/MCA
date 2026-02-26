import java.util.*;
class InvalidSalaryException extends Exception{
	InvalidSalaryException(String msg){
		super(msg);
	}
}

class Employee
{
	String empId;
	String name;
	double salary;
	
	Employee()
	{}
	
	Employee(String empId,String name)
	{
		this.empId=empId;
		this.name=name;
	}
	
	public void setSalary(double salary) throws InvalidSalaryException
	{
		if(salary<0)
		{
			throw new InvalidSalaryException("Salary Can't Be Negative.");
		}
		else
		{
			this.salary = salary;
			System.out.println("Salary Set Successfully.");
		}
	}
	
	public void display()
	{
		System.out.println("Employee Name : "+name);
		System.out.println("Employee Id   : "+ empId);
		System.out.println("Salary        : "+salary);
	}
}
class EmployeeDemo
{
	public static void main(String args[])
	{
	try{
		Scanner sc=new Scanner(System.in);
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
	catch(InvalidSalaryException ie)
	{
		System.out.print(ie.getMessage());
	}
}
}
