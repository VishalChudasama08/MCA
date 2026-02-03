class A{
    int x=9;
}
class B extends A{
    int y=5;
}
class C extends B{
    void sum(){
        System.out.println("x + y = "+ (x+y));
    }
}
class D extends A {
    int z=4;
    void div(){
        System.out.println("Division: " + (z/x));
    }
}

class Hibrit {
    public static void main(String [] arg){
        C c = new C();
        c.sum();
        D d = new D();
        d.div();
    }
}