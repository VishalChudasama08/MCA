import java.io.*;
import java.util.*;

class CreateSubFolder {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);

        // String mainFolderName = "LJMCA";
        System.out.print("Enter Main Folder name: ");
        String mainFolderName = scan.next();


        File f = new File(mainFolderName);

        if(!f.exists()){
            if(f.mkdir()) {
                System.out.println(mainFolderName + " fodler created successully");
            } else {
                System.out.println("Fail to creater " + mainFolderName + " folder.");
            }
        } else {
            System.out.println(mainFolderName + " alredy exists!");
        }


        // String [] subFolderNames = {"Div-A", "Div-B", "Div-C", "Div-D", "Div-E"};
        System.out.print("\n\tHow many subfolder you want to create: ");
        int n = scan.nextInt();

        // StringBuffer[] subFolderNames = new StringBuffer[n];
        String[] subFolderNames = new String[n];
        for(int i=0; i<n; i++){
            System.out.print("\n\tEnter subfolder " + (i+1) + " name: ");
            subFolderNames[i] = scan.next();
            // String sf = scan.next();
            // subFolderNames.append(sf);
        }    

        for(String subFolder : subFolderNames){
        // for(StringBuffer subFolder : subFolderNames){
            File sf = new File(mainFolderName + "/" + subFolder);
            if(!sf.exists()){
                if(sf.mkdir()) {
                    System.out.println(subFolder + " fodler created successully");
                } else {
                    System.out.println("Fail to creater " + subFolder + " folder.");
                }
            } else {
                System.out.println(subFolder + " alredy exists!");
            }
        }
    }
}