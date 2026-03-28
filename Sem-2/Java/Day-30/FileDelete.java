import java.io.*;

class FileDelete{
    public static void main(String [] args){
        File f = new File("demo.txt");

        if(f.exists()){
            if(f.delete()) { //
                System.out.println("file delete");
            } else {
                System.out.println("Failed to delete file");
            }
        } else {
            System.out.println("File not exists");
        }
    }
}