import java.util.Scanner;
import java.lang.Math.*;

class V7_Armstrong{
    public static void main(String arg[]){
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter number: ");
        int n = scan.nextInt();

        int a = n;
        int d = 0;
        while (a > 0){
            d++;
            a /= 10;
        }
        a = n;
        int sum = 0;
        int rem=1;
        while (a > 0){
            rem = a%10;
            sum += Math.pow(rem, d);
            a /= 10;
        }
        // System.out.println(sum);
        
        if (sum == n){
            System.out.println("Armstrong number");
        } else {
            System.out.println("Not Armstrong number");
        }
    }
}