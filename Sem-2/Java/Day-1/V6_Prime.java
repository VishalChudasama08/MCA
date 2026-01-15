import java.util.Scanner;

class V6_Prime{
    public static void main(String arg[]){
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter number: ");
        int n = scan.nextInt();

        int rem=1;
        for(int i=2; i<n/2; i++){
            rem = n%i;
            if(rem==0){
                break;
            }
        }
        if (rem == 0){
            System.out.println("Not Prime number");
        } else {
            System.out.println("Prime Number");
        }
    }
}