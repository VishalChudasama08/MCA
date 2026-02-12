// ODD: Q1. demonstrate supper keyword with variable, method, class constructor

class A{
    int varA = 8;
    A(){
        System.out.println("This is A class normal Constructor.");
    }
    A(String var1){
        System.out.println("This is A class Constructor with one perameter: "+ var1);
    }
    public void show(){
        System.out.println("This is A class show method.");
    }
}

class B extends A{
    int varB;
    B(){
        super(); // call A class Constructor
        super.show(); // call A class show method
        varB = super.varA; // call A class varA variable
        System.out.println("This is B class normal Constructor");
        System.out.println("varB: " + varB);
    }
    B(String var1, String var2){
        super(var1);
        System.out.println("This is B class Constructor with two perameter");
    }
}

class Q1_thisKeyword {
    public static void main(String[] args) {
        B b1 = new B();
        System.out.println("\n----------------------------");
        B b2 = new B("Hey", "There");
    }
}