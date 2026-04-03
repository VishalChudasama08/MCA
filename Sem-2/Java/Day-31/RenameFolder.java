import java.io.*;
import java.util.*;

class RenameFolder {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);

        File oldFolder = new File("LJMCA");
        File newFolder = new File("LJMCA_A05");

        if(oldFolder.exists()){
            if(oldFolder.renameTo(newFolder)){
                System.out.println("Folder renamed successfully!");
            } else {
                System.out.println("Faild to rename");
            }
        } else {
            System.out.println("old Folder not exist!");
        }
    }
}