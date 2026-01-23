class A{
    void show(){
        System.out.println("Normal Class Method");
    }
    void display(){
        System.out.println("Normal Class display method");
    }
}

class AnonymousClass{

    public void method1(){
        System.out.println("\n\tAnonymous Class normal method1");
    }

    public static void main(String[] arg){
        System.out.println("By obj => ");
        A obj = new A() { // now this obj object have new show() method
            void show() { // show() method present in A class is mendetory, than anonymous work
                System.out.println("Anonymous Class using Normal Class");
            } // it like Method Overriding for only this (obj) object
        }; // now obj is Anonymous object

        // obj.show();
        obj.display();

        System.out.println("\nBy obj2 => ");
        A obj2 = new A();
        obj2.show(); // this class normal show() method
        obj2.display();

        System.out.println("\nBy obj3 => ");
        A obj3 = new A(){
            void details(){
                System.out.println("obj3 details method");
            }
        };
        // obj3.details(); // this not work because A class not have details method
        obj3.show();

        AnonymousClass d = new AnonymousClass(){
            public void method1(){
                System.out.println("\n\tAnonymous Class Anonymous method1");
            }
        };
        d.method1();

        AnonymousClass d2 = new AnonymousClass();
        d2.method1();
    }
}