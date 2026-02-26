import java.util.*;

class InvalidAgeException extends Exception {
    InvalidAgeException(String msg){
        super(msg);
    }
}
class Voter{
    String name;
    int age;

    Voter(String name, int age){
        this.name = name;
        this.age = age;
    }
    public void checkEligibility() throws InvalidAgeException {
        if (age<18) {
            throw new InvalidAgeException("You are Not Eligible for vote");
        } else {
            System.out.println("\n\tEligible to vote");
        }
    }
}
class VotingDemo {
    public static void main(String [] ages){
        Scanner scan = new Scanner(System.in);
        
        System.out.print("\n\tEnter Age:");
        int age = scan.nextInt();
        System.out.print("\n\tEnter Name:");
        String name = scan.next();

        Voter v = new Voter(name, age);

        try {   
            v.checkEligibility();
        } catch (InvalidAgeException e){
            System.out.println("\n\t"+e.getMessage());
        }
    }
}