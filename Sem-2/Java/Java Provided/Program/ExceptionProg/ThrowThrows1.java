class ThrowThrows1 {

    // Method using throws
    static void checkNumber(int num) throws ArithmeticException {

        if (num < 0) {
            // throw keyword
            throw new ArithmeticException("Number cannot be negative");
        }

        System.out.println("Valid Number: " + num);
    }

    public static void main(String[] args) {

        try {
            checkNumber(-5);
        } catch (ArithmeticException e) {
            System.out.println("Exception: " + e.getMessage());
        }

    }
}