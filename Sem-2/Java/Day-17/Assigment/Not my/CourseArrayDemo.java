import java.util.*;

class Course{
    private int courseId,credits;
    private String courseName;
    private double fee;
    Course(){
        courseId=0;
        courseName="abc";
        credits=0;
        fee=0;
    }
    Course(int courseId, String courseName, int credits, double fee){
        this.courseId=courseId;
        this.courseName=courseName;
        this.credits=credits;
        this.fee=fee;
    }
    void setter_id(int courseId){
        this.courseId=courseId;
    }
    void setter_nm(String courseName){
        this.courseName=courseName;
    }
    void setter_cre(int credits){
        this.credits=credits;
    }
    void setter_fee(double fee){
        this.fee=fee;
    }
    int getter_id(){
        return courseId;
    }
    String getter_nm(){
        return courseName;
    }
    int getter_cre(){
        return credits;
    }
    double getter_fee(){
        return fee;
    }
    public String toString(){
        return "Course[ID:"+ courseId + "Name: " + courseName+ "Credits:" + credits+ "Fee: " + fee+"]";
    }
}


class CourseArrayDemo {
    public static void main(String args[]){
        int c_id,c;
        String c_nm;
        double f;
        double max;
        Scanner sc=new Scanner(System.in);
        Course o[]=new Course[3];
        for(int i=0;i<3;i++){
            System.out.print("enter courseId: ");
            c_id=sc.nextInt();
            System.out.print("enter courseName: ");
            sc.nextLine();
            c_nm=sc.nextLine();
            System.out.print("enter credits: ");
            c=sc.nextInt();
            System.out.print("enter fee: ");
            f=sc.nextDouble();
            o[i]=new Course(c_id,c_nm,c,f);
            
        }
        for(int i=0;i<3;i++){
            System.out.println(o[i]);
            
        }
    }
    
}
