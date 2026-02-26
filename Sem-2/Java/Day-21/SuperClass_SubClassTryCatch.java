class SuperClass {
    void show() {
        try {
            SubClass obj = new SubClass();
            obj.display();     // calling subclass method
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Handled in SuperClass: " + e);
        }
        finally {
            System.out.println("SuperClass finally");
        }
    }
}

class SubClass extends SuperClass {
    void display() {
        try {
            System.out.println("Inside SubClass display()");
            
            int arr[] = {10, 20, 30};
            System.out.println(arr[5]);   // ArrayIndexOutOfBoundsException

        }
        catch (NullPointerException e) {
            // This catch does NOT match the exception
            // ArrayIndexOutOfBoundsException is NOT handled here
            // So it propagates to SuperClass
            System.out.println("Handled in SubClass");
        }
        finally {
            System.out.println("SubClass finally");
        }
    }
}

public class SuperClass_SubClassTryCatch {
    public static void main(String[] args) {
        SuperClass obj = new SuperClass();
        obj.show();
    }
}