class V1_Constructor{
    public V1_Constructor(){
        System.out.println("This is Default Constructor. no parameters in Default Constructor");
    }
    // private V1_Constructor(){
    //     System.out.println("This is Default Constructor. access presifyer private. this constructer not call wan object create from another class (not same class)");
    // }
    public V1_Constructor(int a){
        System.out.println("This is parameter Constructor.");
    }
    public V1_Constructor(int a, int b){
        a = 2;
        b = 3;
        int c = a+b;
        System.out.println(c);
        a = 6;
        b = 7;
        c = a+b;
        System.out.println(c);
    }

    public void normalMethod(){
        System.out.println("This is normal method");
    }
    public void V1_Constructor(){
        System.out.println("This method. not constructor. method name same as class name with return type");
    }
    public static void main(String avg[]){
        // constructor not have return type

        V1_Constructor obj = new V1_Constructor(); // constructor call automatic wan object create  
        obj.normalMethod();
        obj.V1_Constructor(); // method that have same name, this is not constructor

        V1_Constructor obj2 = new V1_Constructor(1); // call parameter Constructor
        V1_Constructor obj3 = new V1_Constructor(4, 5);
    }
    
    
    // object value not copy directly, for copy object value need & in copy constructor
}