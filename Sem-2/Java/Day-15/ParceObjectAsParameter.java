class Student{
    int id;
    String name;
    Student(int i, String n){
        id=i;
        name=n;
    }
    void display(Student s){
        System.out.println("Id: "+s.id+", Name: "+s.name);
    }

}
class ParceObjectAsParameter{
    public static void main(String [] arg){
        Student std1 = new Student(101, "Amit");
        Student std2 = new Student(102, "Amita");
        std1.display(std2);
        std2.display(std1);
    }
}