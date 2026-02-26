import java.util.*;

class InvalidMarksException extends Exception {
    InvalidMarksException(String msg){
        super(msg);
    }
}
interface Exam {
    public void enterMarks(int marks) throws InvalidMarksException;
    public void calculateGrade();
}
abstract class Person {
    private int id;
    protected String name;
    public final String collegeName = "ABC College";

    Person(int id, String name){
        this.id = id;
        this.name = name;
    }
    public int getId(){
        return id;
    }
    public String getName(){
        return name;
    }
    public abstract void display();
}
class Student extends Person implements Exam {
    private int marks;
    private String grade;

    Student (int id, String name) {
        super(id, name);
    }

    public void enterMarks(int marks) throws InvalidMarksException {
        if (marks < 0 || marks > 100) {
            throw new InvalidMarksException("Marks between 0 to 100 only");
        } else {
            this.marks = marks;
            System.out.print("\n\tMarks added");
        }
    }

    public void calculateGrade(){
        if (marks >= 90){
            grade = "Grade A";
        } else if (marks >= 75) {
            grade = "Grade B";
        } else if (marks >= 50) {
            grade = "Grade C";
        } else {
            grade = "Fail";
        }
        System.out.print("\n\tGrade added");
    }

    public void display(){
        System.out.print("\n\tCollege Name: " + collegeName);
        System.out.print("\n\tStudent Details:");
        System.out.print("\n\t\tId: " + getId());
        System.out.print("\n\t\tName: " + name);
        System.out.print("\n\t\tMarks: " + marks);
        System.out.print("\n\t\tGrade: " + grade);
    }
}
class CollegeDemo {
    public static void main(String [] args){
        int n;
        Scanner scan = new Scanner(System.in);
        System.out.print("\n\tEnter name: ");
        String name = scan.next();
        System.out.print("\n\tEnter Id: ");
        int id = scan.nextInt();

        Student s = new Student(id, name);

        do {
            System.out.println("\n\t1.	Enter Marks\n\t2.	Calculate Grade\n\t3.	Display Student\n\t4.	Exit");
            System.out.print("\n\tEnter your choice: ");
            n = scan.nextInt();
            switch(n){
                case 1: {
                    System.out.print("\n\tEnter Marks: ");
                    int marks = scan.nextInt();
                    try {
                        s.enterMarks(marks);
                    } catch (InvalidMarksException im) {
                        System.out.println(im.getMessage());
                    }
                    break;
                }
                case 2: s.calculateGrade(); break;
                case 3: s.display(); break;
                case 4: System.exit(0);
                default: System.out.print("\n\tInvalid!");
            }
        } while (true);
    }
}