import java.io.*;
import java.util.*;

class WriteInFile {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter file name: ");
        String fName = scan.next();

        try {
            FileWriter fw = new FileWriter(fName, true); // true then file is in append mode
            for(int i=0; i<15; i++){
                fw.write("Line: " + (i+1) + "\n");
            }
            System.out.println("Write in "+fName+" file successfully");
            fw.close();
        } catch (IOException e){
            System.out.println(e);
        }
    }
}