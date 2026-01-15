class A{
    public static void add(){
        System.out.println("void without parameter");
    }
    public int sub(int a, int b){
        System.out.println(a-b);
        return 0;
    }
    public double multiply(double a, double b){
        System.out.println(a*b);
        return 0;
    }
    public static void main(String arg[]){
        A a1 = new A();
        add();
        // a1.add(); // this also work
        a1.sub(9,2);
        a1.multiply(9,2);
    }
}