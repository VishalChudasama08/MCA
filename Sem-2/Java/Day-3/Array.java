import java.util.Scanner;
import java.lang.Math.*;

class Array{

    public static void printDetails(int [] arr){
        System.out.println("Array Elements: ");
        for(int i=0; i<arr.length; i++){
            System.out.println(arr[i]);
        }
    }

    // task-1: make sum of all element and avrage and print it
    public static void print(int [] arr){
        int sum = 0;
        int avg = 0;

        System.out.println("Array Elements: ");
        for(int i=0; i<arr.length; i++){
            sum += arr[i];
            System.out.println(arr[i]);
        }

        avg = sum/arr.length;
        System.out.println("Array element sum : " + sum);
        System.out.println("Array element avrage : " + avg);
    }

    // task-2: print only even index values
    public static void printEvenDetails(int [] arr){
        System.out.println("Array even Elements: ");
        for(int i=0; i<arr.length; i++){
            if(i%2 != 0){
                System.out.println(arr[i]);
            }
        }
    }

    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        
        // int studentId = new int[3]; // array with 3 length

        System.out.println("Enter How many Student here ? : ");
        int n = sc.nextInt();
        
        int[] studentId = new int[n];

        for(int i=0; i<n; i++){
            System.out.println("enter " + (i+1) + " student id: ");
            studentId[i] = sc.nextInt();
        }
        // printDetails(studentId);
        // print(studentId);
        printEvenDetails(studentId);

        // int [] studentMarks = {50,60,70,80};
        // printDetails(studentMarks);
    }
}