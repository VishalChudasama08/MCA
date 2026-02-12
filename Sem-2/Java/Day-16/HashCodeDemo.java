import java.util.Scanner;

class HashCodeDemo{
    static float no;
    public float hashCodee(){
        return (((float)no+1)*4)/7f;
    }
    public static int lengthOfInt(float val){
        int d=0;
        while(val > 0){
            val = val/10;
            d++;
        }
        return d;
    }
    public static void main(String [] arg){
        
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter mobile number:");
        no = scan.nextFloat();

        HashCodeDemo h = new HashCodeDemo();
        float enctypt = h.hashCodee();
        System.out.println(enctypt);

        if(enctypt%2 == 0){
            System.out.println("enctypt number is even");
            System.out.println("Length: " + lengthOfInt(enctypt));
        } else {
            System.out.println("enctypt number is odd");
            System.out.println("Length: " + lengthOfInt(enctypt));
        }
    }
}