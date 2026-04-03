import java.io.*;
import java.util.*;

class CreateAndWrite {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter file name: ");
        String fileName = scan.next();

        File f = new File(fileName);
        
        try {
            if(f.createNewFile()){
                FileWriter fw = new FileWriter(fileName);

                String message;
                do {
                    System.out.print("Enter Message: ");
                    message = scan.next();
                    fw.write(message + "\n");
                } while(!message.equals("exit"));

                fw.close();
            } else if (f.exists()) {
                System.out.print("File alredy exists!");
            }else {
                System.out.println("Faild to create file");
            }
        } catch (IOException e){
            System.out.println(e);
        }
    }
}