import java.util.Scanner;

class V4_method_with_object{
    
    void sum(int n1, int n2){
        int result = n1 + n2;
        System.out.println("Result: " + result);
    }
    void sub(int n1, int n2){
        int result = n1 - n2;
        System.out.println("Result: " + result);
    }
    void mul(int n1, int n2){
        int result = n1 * n2;
        System.out.println("Result: " + result);
    }
    void div(int n1, int n2){
        int result = n1 / n2;
        System.out.println("Result: " + result);
    }
    public static void main(String arg[]){
        Scanner scan = new Scanner(System.in);

        V4_method_with_object v = new V4_method_with_object();

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
            case 1: v.sum(n1, n2); break;
            case 2: v.sub(n1, n2); break;
            case 3: v.mul(n1, n2); break;
            case 4: v.div(n1, n2); break;
            default: 
                System.out.println("not valid choice ");
                break;
        }
    }
}