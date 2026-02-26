import java.util.*;

class InvalidSalaryException extends Exception {
    InvalidSalaryException(String msg){
        super(msg);
    }
}

class Employee {
    int empId;
    String name;
    double salary;

    Employee(int empId, String name){
        this.empId=empId;
        this.name=name;
    }
    public void setSalary(double salary) throws InvalidSalaryException {
        if (salary<0){
            throw new InvalidSalaryException("Salary not nagative.");
        } else {
            this.salary = salary;
        }
    }
    public void display(){
        System.out.println("\t\tEmployee Details:");
        System.out.println("\t\tname:"+name);
        System.out.println("\t\tId:"+empId);
        System.out.println("\t\tsalary:"+salary);
    }
}
class EmployeeDemo {
    public static void main(String [] args) {
        Scanner scan = new Scanner(System.in);
        
        System.out.print("\n\tEmployee Age: ");
        int empId = scan.nextInt();
        System.out.print("\n\tEmployee Name: ");
        String name = scan.next();
        System.out.print("\n\tEmployee Salary: ");
        double salary = scan.nextDouble();

        Employee e = new Employee(empId, name);

        try {
            e.setSalary(salary);
            e.display();
        } 
        catch (InvalidSalaryException exce){
            System.out.println(exce.getMessage());
        }
    }
}