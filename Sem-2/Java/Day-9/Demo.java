class Demo{
    Demo(){
        this(5);
        System.out.println("Default Constructor");
    }
    Demo(int a){
        // this();
        this(a,10);
        System.out.println(a);
    }
    Demo(int a, int b){
        this(a,b,20);
        System.out.println(a+" "+b);
    }
    Demo(int a, int b, int c){
        System.out.println(a+" "+b+" "+c);
    }
    public static void main(String arg[]){
        // Demo d = new Demo(5);
        Demo d = new Demo();
    }
}