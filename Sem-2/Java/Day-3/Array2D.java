import java.util.Scanner;

class Array2D{
    public static void display(int [][] arr){
        for(int i=0; i<r, i++){
            for(int j=0; j<c, j++){
                System.out.println("Enter value [" +i+ "][" + j + "]: ");
                arr[i][j] = sc.nextInt();
            }
        }
    }
    public static void main(String avg[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter row : ");
        int r = sc.nextInt();

        System.out.println("Enter column : ");
        int c = sc.nextInt();

        int [][] arr = new int[r][c];

        for(int i=0; i<r, i++){
            for(int j=0; j<c, j++){
                System.out.println("Enter value [" +i+ "][" + j + "]: ");
                arr[i][j] = sc.nextInt();
            }
        }
    }
}