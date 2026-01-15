import java.util.Scanner;
import java.lang.Math.*;

class V9_Reverse_number{
    public static void main(String arg[]){
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter number: ");
        int a = scan.nextInt();

        int n = a;

        int reverse = 0;
        int rem = 0;
        while (n > 0){
            rem = n%10;
            reverse = rem + (reverse * 10);
            n /= 10;
        }

        System.out.println("Reverse number: " + reverse);
    }
}