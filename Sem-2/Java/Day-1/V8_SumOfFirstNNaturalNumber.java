import java.util.Scanner;
import java.lang.Math.*;

class V8_SumOfFirstNNaturalNumber{
    public static void main(String arg[]){
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter number: ");
        int n = scan.nextInt();

        int sum = 0;
        while (n > 0){
            sum += n;
            n--;
        }

        System.out.println(sum);
    }
}