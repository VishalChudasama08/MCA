public class Student{
    
    public static void main(String[] args)
    {
        Object o = new String("GetClassMethodDemo");
        Class c = o.getClass();
        System.out.println("Class of Object o is: "+ c.getName());
    }
}