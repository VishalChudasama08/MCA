class A{
    int val = 59;
    A(){
        System.out.println("This is A class Constroctor");
    }
    void show(){
        System.out.println("A");
    }
}

class B extends A{
    int valB = 80;
    int valA = super.val; // call A calss variable

    B(){
        super(); // call A class constroctor
        System.out.println("This is B class Constroctor");
    }
    void show(){
        super.show(); // call A class method
        System.out.println("B");
    }
    public static void main(String arg[]){
        B b = new B();
        b.show();
        System.out.println("A class variable: " + b.valA);
        System.out.println("B class variable: " + b.valB);
    }
}