import java.io.*;
import java.util.*;

class CreateFolder {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);

        // System.out.print("Enter Folder name: ");  // F1
        System.out.print("Enter Folder & Sub-Folder name: "); // F2/SF1 
        String folderName = scan.next();

        File f = new File(folderName);

        if(!f.exists()){ // check file or folder exits or not
            // if(f.mkdir()){ // f.mkdir() => folder create 
            if(f.mkdirs()){ // f.mkdirs() => create folder & sub-folder
                System.out.println("Folder created successfully.");
            } else {
                System.out.println("Failed to create Folder");
            }
        } else {
            System.out.println("Folder already exists");
        }
    }
}