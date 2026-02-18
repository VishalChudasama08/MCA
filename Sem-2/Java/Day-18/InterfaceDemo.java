interface A{
    public static final int a = 18;
    public void aMethod();
}
interface B{
    public void bMethod();
}
interface C extends A, B{ // exteds A and B interface in C interface
    public void cMethod();
}
class InterDemo implements C{ // implements C interface
    public void aMethod(){ // override aMethod
        System.out.println("A interface aMethod");
    }
    public void bMethod(){ // override bMethod
        System.out.println("B interface bMethod");
    }
    public void cMethod(){ // override cMethod
        System.out.println("C interface cMethod");
    }
}

class InterfaceDemo{
    public static void main(String [] arg){
        InterDemo id = new InterDemo();

        id.aMethod();
        id.bMethod();
        id.cMethod();
        System.out.print("Interface A variable:" + A.a);
    }
}