import java.util.Scanner;

class D2{
    public static void main(String arg[]){
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter First number: ");
        int a = scan.nextInt();

        System.out.println("Enter Second number: ");
        int b = scan.nextInt();

        System.out.println("Enter Third number: ");
        int c = scan.nextInt();

        if(a<b){
            if(b<c){
                System.out.println("Max value is: " + c);
            } else {
                System.out.println("Max value is: " + b);
            }
        } else{
            System.out.println("Max value is: " + a);
        }
    }
}
