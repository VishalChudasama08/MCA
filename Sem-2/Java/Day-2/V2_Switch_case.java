import java.util.Scanner;

class V2_Switch_case{
    public static void main(String arg[]){
        Scanner scan = new Scanner(System.in);
        int n1 = 0;
        int n2 = 0;
        int result = 0;
        System.out.println("1: sum\n 2: sub\n 3: mul\n 4: div\nEnter your choice: ");
        int choice = scan.nextInt();

        System.out.println("Enter first number: ");
        n1 = scan.nextInt();
        System.out.println("Enter Second number: ");
        n2 = scan.nextInt();

        switch(choice){
            case 1: 
                result = n1 + n2;
                System.out.println("Result: " + result);
                break;
            case 2: 
                result = n1 - n2;
                System.out.println("Result: " + result);
                break;
            case 3: 
                result = n1 * n2;
                System.out.println("Result: " + result);
                break;
            case 4: 
                result = n1 / n2;
                System.out.println("Result: " + result);
                break;
            default: 
                System.out.println("not valid choice ");
                break;
        }
    }
}