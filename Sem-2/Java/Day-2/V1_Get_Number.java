import java.util.Scanner;

class V1_Get_Number{
    public static void main(String arg[]){
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter First number: ");
        int a = scan.nextInt();

        System.out.println("Enter Second number: ");
        int b = scan.nextInt();

        // System.out.println("Enter operator [ex: +, -, x, /]: ");
        // String o = scan.nextLine();

        // if(o.compare("+")) {
            System.out.println(a + " + " + b + " = " + (a+b));
        // } else if(o == "-") {
            System.out.println(a + " - " + b + " = " + (a-b));
        // } else if(o == "x") {
            System.out.println(a + " x " + b + " = " + (a*b));
        // } else if(o == "/") {
            System.out.println(a + " / " + b + " = " + (a/b));
        // // } else {
        //     System.out.println("Envalid operator.");
        // }
    }
}
