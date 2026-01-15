import java.util.Scanner;

class Employee extends Student{
    public void displaySalary(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Employee id: ");
        int id = sc.nextInt(); 

        System.out.println("Enter Employee name: ");
        String name = sc.next(); // nextLine(); not work

        System.out.println("Enter Employee salary: ");
        float salary = sc.nextFloat();

        System.out.println("Employee id: " + id + ", name: " + name + ", salary: " + salary);
    }
}