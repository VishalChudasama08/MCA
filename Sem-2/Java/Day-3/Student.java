import java.util.Scanner;

class Student{
    public void displayDetails(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Student id: ");
        int id = sc.nextInt(); 

        System.out.println("Enter Student name: ");
        String name = sc.next(); // nextLine(); not work

        System.out.println("Enter Student semester: ");
        int sem = sc.nextInt();

        System.out.println("Student id: " + id + ", name: " + name + ", semester: " + sem);
    }
}