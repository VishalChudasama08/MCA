import java.util.Scanner;

class V5_Patten{
    public static void main(String arg[]){
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter number: ");
        int n = scan.nextInt();

        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}