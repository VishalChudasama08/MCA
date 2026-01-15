class College {

    static String collegeName = "LJ";
    int studentId = 0;
    String studentName = "";

    College(String name, int id){
        studentId = id;
        studentName = name;
    }

    public static void displayCollegeName(){
        System.out.println("College name: " + collegeName);
    }
    public void displayStudentDetails(){
        System.out.println("Student name: " + studentName + ", ID: " + studentId);
    }

    public static void main(String arg[]){
        College c = new College("Vishal", 8);
        displayCollegeName();
        c.displayStudentDetails();
    }
}