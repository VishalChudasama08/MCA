class School{
    public void displayStudents(){
        System.out.println("Student Details");
        class Student{
            String studentName = "Vishal";
            String studentGrade = "A+";
        }
        Student std = new Student();
        System.out.println("Student Name: " + std.studentName);
        System.out.println("Student Grade: " + std.studentGrade);
    }
    public static void main(String [] arg){
        School s = new School();
        s.displayStudents();
    }
}