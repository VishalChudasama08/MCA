class SuperClass {

    void process() {
        try {
            System.out.println("SuperClass process() started");
            performTask();   // Call to overridden method
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Handled in SuperClass: " + e);
        }
        finally {
            System.out.println("SuperClass finally block executed");
        }
    }

    void performTask() {
        System.out.println("SuperClass performTask()");
    }
}

class SubClass extends SuperClass {

    // Overriding method
    void performTask() {
        System.out.println("SubClass performTask()");
        int arr[] = {10, 20, 30};
        System.out.println(arr[5]);   // Exception (uncaught here)
    }
}

public class InheritanceExceptionDemo {

    public static void main(String[] args) {

        SuperClass obj = new SubClass();  // Dynamic Method Dispatch
        obj.process();

        System.out.println("Program Finished");
    }
}