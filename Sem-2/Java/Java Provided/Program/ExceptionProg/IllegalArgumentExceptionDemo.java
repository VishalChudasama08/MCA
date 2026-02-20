/*
Use IllegalArgumentException when:

✔ Value is negative but should be positive
✔ Value is out of range
✔ String is empty when not allowed
✔ Parameter does not meet required condition
✔ Invalid input format
*/
public class IllegalArgumentExceptionDemo {

    // Method using throws
    static void checkPassword(String password) throws IllegalArgumentException {

        if (password.length() < 6) {
            // throw keyword
            throw new IllegalArgumentException("Password must be at least 6 characters long");
        }

        System.out.println("Password is valid");
    }

    public static void main(String[] args) {

        try {
            checkPassword("abc");   // Invalid password
        } catch (IllegalArgumentException e) {
            System.out.println("Exception: " + e.getMessage());
        }

    }
}