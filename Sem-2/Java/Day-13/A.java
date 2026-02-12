class A{
    void show(){
        System.out.println("Class A method is call");
    }
    public static void main(String [] arg){ // do "java A" for run me
        A a = new A();
        a.show();

        B b = new B();
        b.show();
    }
}

class B extends A{
    void show(){
        System.out.println("Class B method is call");
    }
    public static void main(String [] arg){ // do "java B" for run me
        A a = new A();
        a.show();

        B b = new B();
        b.show();
    }
}