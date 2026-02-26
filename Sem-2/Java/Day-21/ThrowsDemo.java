public class ThrowsDemo {
    // Method using throws
    static void divide(int a, int b) throws ArithmeticException, NumberFormatException {
        int result = a / b;   // JVM may generate ArithmeticException
        System.out.println("Result: " + result);
    }

    public static void main(String[] args) {
        try {
            divide(10, 0);   // Calling method
            divide(10, 5);   // Calling method
        } catch (ArithmeticException e) {
            e.printStackTrace();
            System.out.println("Exception: " + e);
        } catch (NumberFormatException e) {
            System.out.println("Exception: " + e);
        } 

    }
}