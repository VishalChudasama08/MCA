import java.util.Scanner;

class Array2D{
    public static void matrixSum(int arr1[][], int r1, int c1, int arr2[][], int r2, int c2){
        if(!(r1==r2) && !(c1==c2)){
            System.out.println("\n\n***Not valid matrix for matrix sum***\n\n");
        } else {
            int sumMatrix[][] = new int[r1][c2];
            for(int i=0; i<r1; i++){
                for(int j=0; j<c1; j++){
                    sumMatrix[i][j] = arr1[i][j] + arr2[i][j];
                }
            }
            System.out.println("\nSum of both matrix =>");
            print(sumMatrix, r1, c1);
        }
    }
    public static void matrixSub(int arr1[][], int r1, int c1, int arr2[][], int r2, int c2){
        if(!(r1==r2) && !(c1==c2)){
            System.out.println("\n\n***Not valid matrix for matrix Subtraction***\n\n");
        } else {
            int subMatrix[][] = new int[r1][c2];
            for(int i=0; i<r1; i++){
                for(int j=0; j<c1; j++){
                    subMatrix[i][j] = arr1[i][j] - arr2[i][j];
                }
            }
            System.out.println("\nSubtraction of both matrix =>");
            print(subMatrix, r1, c1);
        }
    }
    // public static void matrixMul(int arr1[][], int r1, int c1, int arr2[][], int r2, int c2){
    //     if(!(r1==c1) && !(r2==c2)){
    //         System.out.println("\n\n***Not valid matrix for matrix Multiplication***\n\n");
    //     } else {
    //         int sumMatrix[][] = new int[r1][c2];
    //         for(int i=0; i<r1; i++){
    //             for(int j=0; j<c1; j++){
    //                 sumMatrix[i][j] = arr1[i][j] - arr2[i][j];
    //             }
    //         }
    //         System.out.println("\nSubtraction of both matrix =>");
    //         print(sumMatrix, r1, c1);
    //     }
    // }
    public static void print(int arr[][], int r, int c){
        System.out.println("------------");
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter Array1 Rows: ");
        int r1 = sc.nextInt();
        System.out.println("Enter Array1 Columns: ");
        int c1 = sc.nextInt();

        System.out.println("Enter Array2 Rows: ");
        int r2 = sc.nextInt();
        System.out.println("Enter Array2 Columns: ");
        int c2 = sc.nextInt();

        int arr1[][] = new int[r1][c1];
        int arr2[][] = new int[r2][c2];

        for(int i=0; i<r1; i++){
            for(int j=0; j<c1; j++){
                System.out.println("Enter arr1["+i+"]["+j+"]:");
                arr1[i][j] = sc.nextInt();
            }
        }
        for(int i=0; i<r2; i++){
            for(int j=0; j<c2; j++){
                System.out.println("Enter arr2["+i+"]["+j+"]:");
                arr2[i][j] = sc.nextInt();
            }
        }

        print(arr1, r1, c1);
        print(arr2, r2, c2);
        matrixSum(arr1, r1, c1, arr2, r2, c2);
        matrixSub(arr1, r1, c1, arr2, r2, c2);
    }
}