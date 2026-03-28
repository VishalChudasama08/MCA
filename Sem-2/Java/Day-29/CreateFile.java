import java.io.*;
import java.util.*;

class CreateFile {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter file name with extention: ");
        String fileName = scan.next();

        File file = new File(fileName);

        try {
            if(file.createNewFile()){
                System.out.println("File '" + fileName + "' created successfully.");
            } else {
                System.out.println("File '" + fileName + "' already exists");
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}