import java.util.*;

class InvalidAgeException extends Exception {
    InvalidAgeException(String msg){
        super(msg);
    }
}

class CustomException {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);
        try {
            System.out.print("\n\tEnter Age:");
            int age = scan.nextInt();
            if(age<=0 || age>=120){
                throw new InvalidAgeException("Age is not negative or more then 120");
            } else {
                System.out.println("\n\tAge: "+age);
            }
        } catch (InvalidAgeException e){
            System.out.println("Error: " + e.getMessage());
        }
    }
}