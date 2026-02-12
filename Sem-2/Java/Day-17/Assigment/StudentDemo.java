
/*
 * 1. write a java program to demonstrate ther use of ther toString() method and encapsulation perform the followinf tasks:
 */

class Student{
    private int rollNo;
    private String name;
    private double marks;
    Student(){

    }
    Student(int rollNo, String name, double marks){
        this.rollNo = rollNo;
        this.name = name;
        this.marks = marks;
    }

    void setRollNo(int rollNo){
        this.rollNo = rollNo;
    }
    void setName(String name){
        this.name = name;
    }
    void setMarks(Double marks){
        this.marks = marks;
    }

    @Override
    public String toString(){
        return "Student[Roll No: "+rollNo+", Name: "+name+", Marks: "+marks+"]";
    }
}
public class StudentDemo {
    public static void main(String[] args) {
        Student s1 = new Student(101, "Vishal", 95.5);
        System.out.println(s1.toString());

        Student s2 = new Student();
        s2.setRollNo(102);
        s2.setName("navin");
        s2.setMarks(85.5);
        System.out.println(s2.toString());
    }
}
