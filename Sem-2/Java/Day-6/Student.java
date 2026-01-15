class Student{
    Student(){
        System.out.println("Student Details:");
    }
    Student(String name){
        System.out.println("Name: " + name);
    }
    Student(String name, int rollno){
        System.out.println("Name: " + name + " rollno: " + rollno);
    }
    public static void main(String arg[]){
        Student st1 = new Student();
        Student st2 = new Student("vishal");
        Student st3 = new Student("vishal", 5);
    }
}