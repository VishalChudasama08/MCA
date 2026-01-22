// all this key work posibility
class A{ 
    String variableA = "I am A class variable"; 
    A(){
        this("I am A class updated variable");
        System.out.println("A class constroctor default colled");
    }
    A(B obj){
        obj.show(5);
        this.show(8);
        System.out.println("A class constroctor colled with B class object argument ");
    }
    A(String variableA){
        this.variableA = variableA;
        System.out.println("A class variable value chage by A class constroctor using this keyword");
    }
    public void show(int a){
        System.out.println("A class show method colled with argument " + a);
    }
    public static void main(String arg[]){
        A a1 = new A(); // only call A class default constructor
        System.out.println("\n\n\n");
        B b1 = new B();
    }
}

class B{
    String variableB = "I am B class variable";
    B(){
        A a = new A(this);
        System.out.println("B class constroctor default colled");
    }
    public void show(int a){
        System.out.println("B class show method colled with argument " + a);
    }
}