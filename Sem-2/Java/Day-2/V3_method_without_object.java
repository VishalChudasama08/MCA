import java.util.Scanner;

class V3_method_without_object{
    static void sum(int n1, int n2){
        int result = n1 + n2;
        System.out.println("Result: " + result);
    }
    static void sub(int n1, int n2){
        int result = n1 - n2;
        System.out.println("Result: " + result);
    }
    static void mul(int n1, int n2){
        int result = n1 * n2;
        System.out.println("Result: " + result);
    }
    static void div(int n1, int n2){
        int result = n1 / n2;
        System.out.println("Result: " + result);
    }
    public static void main(String arg[]){
        Scanner scan = new Scanner(System.in);
        int n1 = 0;
        int n2 = 0;
        int result = 0;
        System.out.println(" 1: sum\n 2: sub\n 3: mul\n 4: div\nEnter your choice: ");
        int choice = scan.nextInt();

        System.out.println("Enter first number: ");
        n1 = scan.nextInt();
        System.out.println("Enter Second number: ");
        n2 = scan.nextInt();

        switch(choice){
            case 1: sum(n1, n2); break;
            case 2: sub(n1, n2); break;
            case 3: mul(n1, n2); break;
            case 4: div(n1, n2); break;
            default: 
                System.out.println("not valid choice ");
                break;
        }
    }
}