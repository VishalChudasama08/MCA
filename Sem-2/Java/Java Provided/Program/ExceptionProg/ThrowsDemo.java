public class ThrowsDemo {

    // Method using throws
    static void divide(int a, int b) throws ArithmeticException {
        int result = a / b;   // JVM may generate ArithmeticException
        System.out.println("Result: " + result);
    }

    public static void main(String[] args) {

        try {
            divide(10, 0);   // Calling method
        } catch (ArithmeticException e) {
            System.out.println("Exception: " + e);
        }

    }
}