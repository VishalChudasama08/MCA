import java.io.*;
import java.util.*;

class RenameFile {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);

        File oldFile = new File("data.txt");
        File newFile = new File("newData.txt");

        if(oldFile.exists()){
            if(oldFile.renameTo(newFile)){
                System.out.println("File renamed successfully!");
            } else {
                System.out.println("Faild to rename");
            }
        } else {
            System.out.println("old file not exist!");
        }
    }
}