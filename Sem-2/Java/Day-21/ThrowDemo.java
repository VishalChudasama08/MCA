public class ThrowDemo {
    public static void main(String[] args) {
        int a = 10;
        int b = 0;
        try {
            if (b == 0) {
                throw new ArithmeticException("Cannot divide by zero");
            }

            int result = a / b;
            System.out.println("Result: " + result);

        } catch (ArithmeticException e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}