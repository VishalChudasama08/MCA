import java.util.*;

class ExceptionHeadling {
    public static void commandLineArgument(String [] args){
        try {
            Float a = Float.parseFloat(args[0]); // command line firt argument
            Float b = Float.parseFloat(args[1]);
            Float c = a/b;
            System.out.println("\n\tDivision: " + c);
        } catch(ArithmeticException e){
            System.out.println("\nt\tError: / by zero not allow");
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println("\n\tError: give minimum 2 Float command line argument");
        } catch(NumberFormatException e){
            System.out.println("\n\tError: give Numeric value in command line argument");
        } catch (Exception e) {
            System.out.println("\nError: " + e);
        } finally {
            System.out.println("\n\tHey i ma commandLineArgument method finally block");
        }
    }
    public static void scannerTimeError(){
        Scanner scan = new Scanner(System.in);
        try {
            System.out.print("\n\tEnter Array size: ");
            int s = scan.nextInt();

            int arr[] = new int[s];

            for(int i=0;i<s;i++){
                System.out.print("\tEnter " + (i+1) + " value: ");
                arr[i] = scan.nextInt();
            }
            int sum=0;
            for(int i=0;i<s;i++){
                System.out.println("\tarr["+(i+1)+"]: " + arr[i]);
                sum += arr[i];
            }
            System.out.println("\n\tArray value sum: "+sum);
        } 
        catch (NegativeArraySizeException e){
            System.out.println("\n\tError: Array index not negative, give positive integer only");
        } 
        catch (InputMismatchException e){
            System.out.println("\n\tError: Array index not Float or dubble, give integer only");
        } 
        catch (Exception e){
            System.out.println("\n\tError: " + e);
        } 
        finally {
            System.out.println("\n\tHey i ma scannerTimeError method finally block");
        }
    }
    public static void main(String [] args){
        // commandLineArgument(args);
        scannerTimeError();
    }
}