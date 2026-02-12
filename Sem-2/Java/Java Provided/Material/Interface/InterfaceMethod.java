interface Test {

    // 1️⃣ Abstract method (no body)
    void display();

    // 2️⃣ Default method (has body)
    default void show() {
        System.out.println("This is default method");
    }

    // 3️⃣ Static method (has body)
    static void info() {
        System.out.println("This is static method");
    }
}

class Demo implements Test {

    // Must override abstract method
    public void display() {
        System.out.println("This is abstract method implementation");
    }
}

public class InterfaceMethod {
    public static void main(String[] args) {

        Demo d = new Demo();

        // Calling abstract method
        d.display();

        // Calling default method
        d.show();

        // Calling static method
        Test.info();
    }
}
