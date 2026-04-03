import java.io.*;
import java.util.*;

class ReadFromFile {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter file name: ");
        String fName = scan.next();

        try {
            FileReader fr = new FileReader(fName);

            int i;
            while((i = fr.read()) != -1) {
                System.out.print((char)i);
            }
            fr.close();
        } catch (IOException e){
            System.out.println(e);
        }
    }
}