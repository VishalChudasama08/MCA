
import java.util.*;
//custom Exception
class InvalidSalaryException extends Exception
{
	InvalidSalaryException(String msg)
	{
		super(msg);
	}
}
class Employee
{
	String empId,name;
	double salary;
	Employee(){}
	Employee(String empId,String name)
	{
		this.empId = empId;
		this.name = name;
		
	}
	public void setSalary(double salary) throws InvalidSalaryException	
	{
		if(salary < 0)
		{
			throw new InvalidSalaryException("Salary can't be negative...");
		}
		else
		{
			this.salary = salary;
			System.out.print("\nSalary set..");
		}
	}
	public void display()
	{
		System.out.print("\nEmp Id: "+empId);
		System.out.print("\nEmp Name:" + name);
		System.out.print("\nSalary is:"+ salary);
	}
}
class EmployeeDemo
{
	public static void main(String args[]){
	
		Scanner sc = new Scanner(System.in);
		Employee e = new Employee("1","ABC");
		
		System.out.print("\n\tEnter Salary:");
		double sal = sc.nextDouble();
		
		try
		{
			e.setSalary(sal);
			e.display();
		}catch(InvalidSalaryException	ie)
		{
			System.out.print("\n\t"+ie.getMessage());
		}
		
	}
}
