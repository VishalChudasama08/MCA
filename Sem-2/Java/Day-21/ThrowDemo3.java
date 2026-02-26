import java.util.*;

class ThrowDemo3 {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("\n\tEnter password: ");
        String password = scan.next();

        try {
            if(password.length() < 6){
                throw new IllegalArgumentException("Password is more then 6 character.");
            } else {
                System.out.println("\n\tYour password is good");
            }
        } catch(IllegalArgumentException e) {
            System.out.println("\n\tError: "+e.getMessage());
        } finally {
            System.out.println("\n\tend!");
        }
    }
}