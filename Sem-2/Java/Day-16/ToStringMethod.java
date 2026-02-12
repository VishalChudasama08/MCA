class ToStringMethod{
    String name = "Vishnu";
    int age = 21;
    @Override
    public String toString(){
        return "Student{name='"+name+"', age="+age+"}";
    }
    public static void main(String [] arg){
        ToStringMethod s = new ToStringMethod();
        System.out.println(s.toString());
    }
}